#pragma once
#include <iostream>
#include <string>
#include <random>
#include "KthOrderStatsBase.h"
using namespace std;

namespace KthItemUnsortedArrayNM //@RED20170627004
{
	using namespace KthOrderStatsBaseNM;
	class KthItemUnsortedArray
	{
		public:
				void callKthItemUnsortedArray()
				{
				
					//Find 8th smallest (smallest means 8th item when data is in ascending order)
					int src[] = { 2, 36, 5, 21, 8, 13, 11, 20, 5, 4, 1 }; //13
					int K = 8;
					int srcLen = 11;
					KthOrderStatsBase objKthOrderStatsBase;
					int ret = objKthOrderStatsBase.CallKthOrderStatsBase(src, srcLen, K);
					cout << "\r\n";
					cout << K << "th Smallest element " << ret << "\r\n";

					//Find 8th Largest (Largest means 8th item when data is in Descending order.
					//If the Data is ascending it will be "srcLen - 8"
					//ret = objKthOrderStatsBase.CallKthOrderStatsBase(src, srcLen, srcLen - K);
					cout << K << "th Largest element " << ret << "\r\n";
				}
	};
};
