#include<iostream>

//---------------------abstract product-------------------
class TxPacket {
public:
    virtual void CreateTxPacket() const = 0;
};

class TcpTxPacket: public TxPacket {
public:
    void CreateTxPacket() const override {
        std::cout << "Class TcpTxPacket : CreateTxPacket() "<<"\n";
    }
};

class UdpTxPacket: public TxPacket {
public:
    void CreateTxPacket() const override {
        std::cout << "Class UdpTxPacket : CreateTxPacket() "<<"\n";
    }
};

class IpTxPacket: public TxPacket {
public:
    void CreateTxPacket() const override {
        std::cout << "Class IpTxPacket : CreateTxPacket() "<<"\n";
    }
};

//---------------------abstract product-------------------
class RxPacket {
public:
    virtual void CreateRxPacket() const = 0;
};

class TcpRxPacket: public RxPacket {
public:
    void CreateRxPacket() const override {
        std::cout << "Class TcpRxPacket : CreateRxPacket() "<<"\n";
    }
};

class UdpRxPacket: public RxPacket {
public:
    void CreateRxPacket() const override {
        std::cout << "Class UdpRxPacket : CreateRxPacket() "<<"\n";
    }
};

class IpRxPacket: public RxPacket {
public:
    void CreateRxPacket() const override {
        std::cout << "Class IpRxPacket : CreateRxPacket() "<<"\n";
    }
};

//------------------Abstract Factory Design Pattern---------
class AbstractIf {
public:
    virtual TxPacket * ImplementTxPacket() const = 0;
    virtual RxPacket * ImplementRxPacket() const = 0;
};

class concreteTcp : public AbstractIf {
public:
    TxPacket * ImplementTxPacket() const override {
        return new TcpTxPacket();
    }

    RxPacket * ImplementRxPacket() const override {
        return new TcpRxPacket();
    }
};

class concreteUdp : public AbstractIf {
public:
    TxPacket * ImplementTxPacket() const override {
        return new UdpTxPacket();
    }

    RxPacket * ImplementRxPacket() const override {
        return new UdpRxPacket();
    }
};

class concreteIp : public AbstractIf {
public:
    TxPacket * ImplementTxPacket() const override {
        return new IpTxPacket();
    }

    RxPacket * ImplementRxPacket() const override {
        return new IpRxPacket();
    }
};

//--------------application -------------------------
void app(AbstractIf& abs)
{
    TxPacket * txpck = abs.ImplementTxPacket();
    RxPacket * rxpck = abs.ImplementRxPacket();

    txpck->CreateTxPacket();
    rxpck->CreateRxPacket();

    delete txpck;
    delete rxpck;
}

//----------test the application -------------------------
int main()
{
    AbstractIf *tcpabs = new concreteTcp();
    app(*tcpabs);
    delete tcpabs;

    AbstractIf *udpabs = new concreteUdp();
    app(*udpabs);
    delete udpabs;

    AbstractIf *ipabs = new concreteIp();
    app(*ipabs);
    delete ipabs;

    return 0;
}
