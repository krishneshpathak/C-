#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <optional>

class Packet {
public:
   Packet() = default;
   ~Packet() = default;

   Packet(const Packet&) 		= delete;
   Packet& operator = (const Packet&)   = delete;
   Packet(const Packet&&)		= delete;
   Packet& operator = (const Packet&&)  = delete;

   int CalHi(const std::vector<int>& count);
};

int Packet::CalHi(const std::vector<int>& count)
{
    int hi{0};

    for (auto &i : count)
    {
       std::cout << i << std::endl;
    }
    
    std::for_each(count.cbegin(), count.cend(), [&](int vecin) 
		    {
		   	if ( hi < vecin)
		            hi = vecin;	
		    });

    return hi;
}

#if 0
std::optional<Packet> getInstance()
{
   std::unique_ptr<Packet> packet{nullptr};

   packet = std::make_unique<Packet>();

   //std::optional<Packet> pac(std::move(packet));
   if ( packet != nullptr)
	return packet;//error: could not convert ‘packet’ from 
                            //‘std::unique_ptr<Packet>’ to ‘std::optional<Packet>

   return std::nullopt;
}

#endif
int main()
{
   std::vector<int> vec = {5, 4, 7, 3, 2, 9, 1,8, 6};
   int high{0};
   //auto packet = getInstance();
   std::unique_ptr<Packet> packet{nullptr};
   packet = std::make_unique<Packet>();
   if ( packet)
   {  
	high = packet->CalHi(vec);
   }
   std::cout << "highest = " << high << std::endl;
#if 0
   int hi=0;

   for(auto i : vec)
   {
     std::cout << i << std::endl;
   }

   for (auto it = vec.cbegin(); it < vec.cend(); it++) 
   {
	std::cout << *it << std::endl;
   }

   std::for_each(vec.cbegin(), vec.cend(), [&](const int vecin) { //Lambda function
    	if (hi < vecin)
	{
	   hi = vecin;
	}
   });

   auto refLambda = [&](const int vecin) 
   {
	if ( hi < vecin)
	{
	   hi = vecin;
	}
   };
   std::for_each(vec.cbegin(), vec.cend(), refLambda); //Named Lambda Function

   std::cout <<"highest = " <<  hi <<std::endl;
#endif
   return 0;
}

