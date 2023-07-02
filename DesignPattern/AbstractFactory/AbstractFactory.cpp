#include <iostream>
#include <string>

#define LINUX 1

//-----------------feature impelementation---------------------
class Os {

public:
    virtual void display() = 0; 
};

//----------------LINUX OS--------------------------------------
class LinuxApp: public Os {

public:
     void display() {
	     std::cout << " This is LinuxApp class " << "\n";
     }
};

class LinuxPlat: public Os {

public:
      void display() {
	      std::cout << " This is LinuxPlat class " << "\n";
      }
};

//----------------WINDOWS OS-----------------------------------
class WindowsApp: public Os {

public:
      void display() {
	      std::cout << " This is WindowsApp class " << "\n";
      }
};

class WindowsPlat: public Os {

public:
      void display() {
	      std::cout << " This is WindowsPlat class " << "\n";
      }
};

//----------Absstract Factory Design---------------------------
class OsFactory {

public:
     virtual Os* Create_App()=0;
     virtual Os* create_Plat()=0;
};


class LinuxFactory: public OsFactory {

public:

     Os* Create_App() {
	 return new LinuxApp; 
     }

     Os* create_Plat() {
	 return new LinuxPlat;
     }
};

class WindowsFactory: public OsFactory {

public: 

     Os* Create_App() {
         return new WindowsApp; 
     }

     Os* create_Plat() {
         return new WindowsPlat;
     }
};

//-------------------Use of Abstract Factory Method------------

int main()
{
    OsFactory *osfac;  //creat a object for OsFactor class
#ifdef LINUX  //for "WINDOWS" use #ifndef LINUX
    osfac = new LinuxFactory;
#else
   osfac = new WindowsFactory;
#endif
    Os *osapp = osfac->Create_App();
    Os *ospla = osfac->create_Plat();
    osapp->display();
    ospla->display();

    return 0;
}

