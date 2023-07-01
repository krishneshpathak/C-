//std::Unique_ptr
//krishnesh pathak

#include <iostream>
#include <memory>

class Linux {
public:

   Linux(const Linux &) = delete; //no copy pf object
   Linux( Linux && ) = delete;  //no move of object

   Linux(const std::string &linux_name, int data) : pstr(linux_name),val(data) {
   	std::cout <<"Linux constructor- "<< val<<"\n";
   }

   ~Linux() {
	std::cout <<" Linux Destructor\n";
   }

   //public interface 
   
   const std::string & getName () const {
	return pstr;
   }

private:
   std::string pstr{nullptr};
   int val{};

};

namespace Linux_unique {
    
    std::unique_ptr<Linux> linux_process(std::unique_ptr<Linux> lipr ) {
        std::cout <<" Linux Process on " << lipr->getName()<< "\n";
         return lipr; //(Move on return by copy), is implicit- This is the preferred optiom :)
    }

    void linux_thread(const std::unique_ptr<Linux> &lipr) {
	    std::cout << " Linux Thread on  " << lipr->getName() << "\n";
    }

    std::unique_ptr<Linux> linux_object(std::unique_ptr<Linux> lipr ) {
        std::cout <<" Linux object on  " << lipr->getName()<< "\n";
         return std::move(lipr);//(Move on return by copy), is explicit has no effect- same as "return lipr"
    }

    void  linux_core(std::unique_ptr<Linux> lipr ) {
        std::cout <<" Linux core on " << lipr->getName()<< "\n";
        linux_thread(lipr);
	lipr = linux_object(std::move(lipr));
	std::cout <<" still Linux core on " << lipr->getName()<< "\n";

    }

    void check() {
	std::unique_ptr<Linux> obj{nullptr};
        obj 	= std::make_unique<Linux> ("linux_rt", 10);
	obj 	= linux_process(std::move(obj));
	(obj) ? std::cout << "Linux still alive\n " : std::cout << "Linux killed\n";//turnary operator
        linux_core(std::move(obj));
	(obj) ? std::cout << "Linux still alive\n " : std::cout << "Linux killed\n";//turnary operator

    }

}// namespace Linux_unique

/* check the uniquness of unique_ptr */
int main()
{
    Linux_unique::check();

    return 0;
}
