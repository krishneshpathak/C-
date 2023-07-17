#include <iostream>

class Packet {
protected:
    Packet(){
        std::cout <<"Packet: constructor" <<"\n";
    };

     ~Packet() {
        std::cout <<"Pakcet: detructor" <<"\n";
    };

};
class TxPacket : public Packet {

private:
    //Packet t;
public:
    TxPacket(){
       std::cout <<"TxPacket: constructor" <<"\n"; 
    };
    ~TxPacket(){
       std::cout <<"TxPacket: destructor" <<"\n"; 
    };
    //Packet t;

};

int main()
{
    TxPacket *tx_obj = new TxPacket;
    delete tx_obj;

    TxPacket tx;

    //Packet *pack = new Packet;//programmer responsibility to delete 
    //delete pack;

    //Packet t;// error: 'Packet::~Packet()' is protected

   Packet *obj = new TxPacket;
   //delete obj;//error: 'Packet::~Packet()' is protected
   
    return 0;
}
