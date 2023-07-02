#include <iostream>
#include <cstdlib>
#include <memory>
//-------------------------------------------------------
template <typename PacketCreator>
class IpPacketCreator
{
public:
    IpPacketCreator(uint8_t queueContext, uint16_t frameId, uint8_t slotIdFrame);

    uint16_t createPackets();

private:
    uint8_t queueContext;
    uint8_t slotIdFrame;
    uint16_t frameId;
};

template<typename PacketCreator>
IpPacketCreator<PacketCreator>::IpPacketCreator(uint8_t queueContext, 
						  uint16_t frameId, 
						  uint8_t slotIdFrame)
    :queueContext(queueContext), 
     frameId(frameId),
     slotIdFrame(slotIdFrame)
{
   std::cout << "IpPacketCreator contructor" <<"\n";
}


template<typename PacketCreator>
uint16_t IpPacketCreator<PacketCreator>::createPackets()
{
     std::cout << "IpPacketCreator createPackets" <<"\n";
     return frameId;
}

//-----------------------------------------------------------------------
class TcpIpPacketCreator : public IpPacketCreator<TcpIpPacketCreator>
{
public:
    TcpIpPacketCreator(uint8_t queueContext, uint16_t frameId, uint8_t slotIdFrame);

private:
    void packetize(uint8_t queueContext, uint16_t frameId, uint8_t slotIdFrame);

    friend class IpPacketCreator<TcpIpPacketCreator>;
};


TcpIpPacketCreator::TcpIpPacketCreator(uint8_t queueContext, 
				       uint16_t frameId, 
				       uint8_t slotIdFrame)
    :IpPacketCreator(queueContext, frameId, slotIdFrame)
{
    std::cout << "	TcpIpPacketCreator constructor"<<"\n";
    uint16_t FrameId = createPackets();
    std::cout <<"	FrameId in TcpIpPacketCreator = "<< FrameId <<"\n";
}

inline void TcpIpPacketCreator::packetize(uint8_t queueContext, 
					  uint16_t frameId, 
					  uint8_t slotIdFrame)
{
   std::cout << "	TcpIpPacketCreator packetize"<<"\n";
   //std::cout << queueContext<< <<"\n";
}

//------------------------------------------------------------------------
class UdpIpPacketCreator : public IpPacketCreator<UdpIpPacketCreator>
{
public:
    UdpIpPacketCreator(uint8_t queueContext, uint16_t frameId, uint8_t slotIdFrame);

private:
    void packetize(uint8_t queueContext, uint16_t frameId, uint8_t slotIdFrame);

    friend class IpPacketCreator<UdpIpPacketCreator>;
};


UdpIpPacketCreator::UdpIpPacketCreator(uint8_t queueContext,
                                       uint16_t frameId,
                                       uint8_t slotIdFrame)
    :IpPacketCreator(queueContext, frameId, slotIdFrame)
{
    std::cout << "	UdpIpPacketCreator constructor"<<"\n";
    uint16_t FrameId = createPackets();
    std::cout <<"	FrameId in UdpIpPacketCreator = "<< FrameId <<"\n";
}

inline void UdpIpPacketCreator::packetize(uint8_t queueContext,
                                          uint16_t frameId,
                                          uint8_t slotIdFrame)
{
   std::cout << "	UdpIpPacketCreator packetize"<<"\n";
   //std::cout << queueContext<< <<"\n";
}
//--------------------------------------------------------------------------
int main()
{
    //uint8_t *queueid = new uint8_t;
    IpPacketCreator<int>     ipObj(17, 64, 1);
    TcpIpPacketCreator  tcpObj(121, 64, 1); 
    UdpIpPacketCreator  udpObj(119,32,2);
    return 0;
}//end of Template class functionality





