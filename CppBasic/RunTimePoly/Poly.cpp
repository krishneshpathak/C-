#include<iostream>

class Packet {
public:
    virtual void CreatePacket() const = 0;
};

class TcpPacket: public Packet {
public:
    void CreatePacket() const override {
        std::cout << "Class TcpPacket : CreatePacket() "<<"\n";
    }
    void print() {
        std::cout << "Class TcpPacket : print() "<<"\n";
    }
};

class AbstractIf {
public:
    virtual Packet * ImplementPacket() const = 0;
};

class concreteTcp : public AbstractIf {
public:
    Packet * ImplementPacket() const override {
        return new TcpPacket();
    }
};

void app(AbstractIf& abstact)
{
    Packet * pckobj = abstact.ImplementPacket();
    pckobj->CreatePacket();
}

int main()
{
    Packet *obj;
    obj = new TcpPacket();

    obj->CreatePacket();
    //obj->print(); //error: 'class Packet' has no member named 'print'

    AbstractIf* absif= new concreteTcp;
    app(*absif);

    concreteTcp* conTcp= new concreteTcp;
    app(*conTcp);

    return 0;
}
