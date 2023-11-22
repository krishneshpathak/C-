#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <deque>
#include <list>

/* This is the classical singleton pattern.
 * The first getInstance() call initializes the singleton,
 * getInstance() will always return an instance of the T class,
 * If the class Base is declared as
 * class Base : public Singleton<Base> getInstance() method
 * of the derived class will create and provide access to
 * the instance of class Base.
 */

template <class T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T_instance instance;
        return instance;
    }
    ~Singleton() = default;

protected:
    // default constuctor and destructor defined so this class can be inherited
    Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton& operator = (const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator = (const Singleton&&) = delete;

private:
    /* If the T has a protected constructor, using the bare class T
     * in Singleton<T>::getInstance() as a "static T instance"
     * leads to compilation error due to inability to access
     * the protected constructor of class T.
     *
     * To allow getInstance() to use the protected constructor of
     * class T we need to implement wrapper struct T_instance as
     * nested class of the Singleton. T_instance provides access
     * to the protected constructor of the class T that allows to
     * call the protected T() via "static T_instance instance".
     */
    struct T_instance : public T
    {
        using T::T;
    };
};

class Packet: public Singleton<Packet> {
public:
    bool initiaize()
    {
        iomem_ptr = std::make_unique<uint8_t>(10); 
        smem_ptr = std::make_unique<uint8_t>(20);
        iomem_cap = 128;
        smem_cap = 256;

        return true;
    }

    std::pair<uint64_t, uint64_t> getcapacity() const 
    {
        return { iomem_cap, 
                 smem_cap };
    }
#if 0
    std::pair<uint8_t*, uint8_t*> getstartaddress() const 
    {
        return {iomem_ptr, 
                smem_ptr };
    }
#endif
    Packet(const Packet &) = delete;
    Packet& operator = (const Packet&) = delete;
    Packet(const Packet&&) = delete;
    Packet& operator = (const Packet&&) = delete;

protected:
    Packet() = default; //protected constructor

private:
    std::unique_ptr<uint8_t> iomem_ptr{nullptr};
    std::unique_ptr<uint8_t> smem_ptr{nullptr};
    uint64_t iomem_cap{0};
    uint64_t smem_cap{0};
};

int main()
{
    uint8_t *iomemstart{nullptr};
    uint8_t *smemstart{nullptr};
    uint64_t iosizecap{0};
    uint64_t smemsizecap{0};

    //std::tie(iomemstart, smemstart) = packet::getInstance().getstartaddress();
    if (not Packet::getInstance().initiaize())
    {
        std::cout << "False" << std::endl;
        return false;
    }
    std::tie(iosizecap, smemsizecap) = Packet::getInstance().getcapacity();
    std::cout << "IoSize " << iosizecap <<" " << "SmemSize "<< " "<< smemsizecap <<std::endl;
    return 0;
}

