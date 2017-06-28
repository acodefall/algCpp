#pragma once



#include <iostream>
#include <string>
#include <random>
#include "KthOrderStatsBase.h"
using namespace std;

namespace MedianUnsortedUsingKthOrderNM
{
	using namespace KthOrderStatsBaseNM;
	class MedianUnsortedUsingKthOrder
	{
		public:
			void callKthItemUnsortedArray()
			{
				//Take odd numbered array size = 11.
				//median is 5, that is 6. Median is 11
				int src[] = { 2, 36, 12, 21, 8, 13, 11, 20, 5, 4, 1 }; //
				           // 1, 2, 4, 5 8, 11 12 13 20 21 36 
				int K = 6;
				int srcLen = 11;
				KthOrderStatsBase objKthOrderStatsBase;
				int ret = objKthOrderStatsBase.CallKthOrderStatsBase(src, srcLen, K);
				cout << "\r\n";
				cout << K << " median element " << ret << "\r\n"; //median is 11.

			}
	};
};