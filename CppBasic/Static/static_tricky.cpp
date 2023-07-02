#include <iostream>

//---------------------Static ---------------------------------
class StaticClass {

private:
    static const int i{10}; // const static will init. at decleration

    static int s; // must be init. at outside of class

public:
    static int a; //Global static

    static int fun() { return s; } //static member function

    static const int constfun()  { return s;} //static const member function
};

int StaticClass::a{1000}; 

int StaticClass::s{100}; // OK

int main ()
{
    static StaticClass obj{}; // Till program terminate

    std::cout << "static variable a in main " << obj.a <<'\n'; //using obj

    std::cout << "static variable a in main " << StaticClass::a <<'\n';

    std::cout << "static s in main " << obj.fun() <<'\n';//using obj

    std::cout << "static s in main " << StaticClass::fun() <<'\n';

    std::cout << "static const i in main " << StaticClass::constfun() <<'\n';

    return 0;
}
