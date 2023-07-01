#include <iostream>

namespace Crtp_DesignPattern {

template <class Packet> 
class Protocol {
public:
     Protocol() {
	std::cout << "Protocol Constructor" <<"\n";
     }
     virtual ~Protocol() {
	std::cout << "Protocol Destructor" <<"\n";
     }

     void packet() {
	std::cout << "Packet from Protocol Class " <<"\n";
	static_cast<Packet *>(this)->derivedPacket();
     }
};


class TcpPacket : public Protocol<TcpPacket> {
public:
    TcpPacket() {
	std::cout << "	TcpPacket Constructor" <<"\n";	   
    }
    ~TcpPacket() {
        std::cout << "	TcpPacket Destructor" <<"\n";
    }
    void derivedPacket() {
        std::cout << "	Derived Packet implementation in TcpPacket Class" <<"\n";
    }
};

class UdpPacket : public Protocol<UdpPacket> {
public: 
    UdpPacket() {
        std::cout << "	UdpPacket Constructor" <<"\n";
    }
    ~UdpPacket() {
        std::cout << "	UdpPacket Destructor" <<"\n";
    }
    void derivedPacket() {
        std::cout << "	Derived Packet implementation in UdpPacket Class " <<"\n";
    }
};
    //Static Polymorphism using CRTP
    void run() {
	TcpPacket tp;
	UdpPacket up;
	//Protocol<TcpPacket> *tcp = new TcpPacket();
        
	//Compiler knows in compile time what is the functiom to be called
	//because we are passing in advance to the base(Packet) class 
	//what is the implementation of the function in the "future"
	tp.packet();
	up.packet();
	//tcp->packet();
    }

}//namespace Crtp_DesignPattern
int main()
{
   //CRTP is faster then Virtual interface implementation because it does not have the overhead
   // of runtime checking which function to call
   Crtp_DesignPattern::run();
   return 0;
}
