#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
   std::vector<int> vec = {5, 4, 7, 3, 2, 9, 1,8, 6};
 
   int hi=0;

   for(auto i : vec)
   {
     std::cout << i << std::endl;
   }
#if 0
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
#endif
   auto refLambda = [&](const int vecin) 
   {
	if ( hi < vecin)
	{
	   hi = vecin;
	}
   };
   std::for_each(vec.cbegin(), vec.cend(), refLambda); //Named Lambda Function

   std::cout <<"highest = " <<  hi <<std::endl;
   return 0;
}
