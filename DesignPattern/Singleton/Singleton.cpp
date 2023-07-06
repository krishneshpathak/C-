#include <iostream>
#include <cstdlib>
class NonCopyable {

public:
   //1:public static creation method for getting the singleton instance.
   //The static method of the class will still be able to call the constructor, but not the other objects.
   static NonCopyable* getInstance(uint16_t val) {
	if (obj == nullptr) {
		obj = new NonCopyable(val);
        }
        return obj;
   }

protected:
   //2: Default constructor & desctuctor defined so this class can be inherited.
   NonCopyable() = default;

   NonCopyable(uint16_t c_v): val{c_v} {
   	std::cout << "NonCopyable constructor= "<<val <<"\n";
   }

   NonCopyable(NonCopyable&&) = delete;
   NonCopyable& operator=(NonCopyable&&) = delete;

   NonCopyable(const NonCopyable&) = delete;
   NonCopyable& operator=(const NonCopyable&) = delete;

   ~NonCopyable()= default;

private:
   //3:private static field to the class for storing the singleton instance.
   static NonCopyable* obj;

   uint16_t val;
};

//initialize the static member outside of class
NonCopyable* NonCopyable::obj{nullptr};

//derived class inherit singleton class
class Packet: public NonCopyable {
public:
    Packet() {}

    void method1() {
        //4: call static creation method of Singleton class
	NonCopyable* pobj = NonCopyable::getInstance(10);
    }

    void method2() {
        NonCopyable* pobj = NonCopyable::getInstance(20);
    }
};

int main ()
{
   Packet pckt;

   pckt.method1();
   pckt.method2();// this call will not call contructor again :)

   return 0;
}
