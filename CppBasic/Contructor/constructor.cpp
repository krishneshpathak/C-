#include <iostream>

class Packet {

public:

    int* data{nullptr};

    Packet() {}

    Packet(const Packet& other) {
        data = other.data;
    } //copy constructor

    Packet& operator=(const Packet& other)=delete;//copy assignment operator

    Packet(Packet&& other){ data = other.data; other.data = nullptr;}//move constructor
   
    Packet& operator=(Packet&& other) = delete; // {return* this;}//move assignmet operator

};


int main()
{

   Packet obj;

   obj.data = new int(10);

   std::cout << "obj.data = " << *obj.data <<"\n";

   Packet cobj{obj}; //copy contructor called 

   //Packet cobj;
   //cobj = obj; // error:if "copy assignment operator" is "delete"
   
   std::cout << "cobj.data = " << *cobj.data <<"\n";


   Packet mobj{std::move(obj)}; //move contructor called

   //Packet mobj;
   //mobj = std::move(mobj); //<--- work onlywhen move assignment operator is not delete.

   std::cout << "mobj.data = " <<  *mobj.data <<"\n";

   return 0;
}
