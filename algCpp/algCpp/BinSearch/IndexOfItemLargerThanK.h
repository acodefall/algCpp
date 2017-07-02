#pragma once
#include <iostream>
#include "BinSearchBase.h"
using namespace std;

namespace IndexOfItemLargerThanKNM
{
	class IndexOfItemLargerThanK
	{
		public:
				void CallIndexOfItemLargerThanK()
				{
					BinSearchBaseNM::BinSearchBase binsearch;
					int src[14] = {4, 6, 8,  45,52, 67,  298 ,  408, 518, 760, 894, 913,  963, 1093};
					binsearch.BinSearch(src, 14, 45);

					binsearch.BinSearch(src, 14, 4);

					binsearch.BinSearch(src, 14, 894);
				}


				

	};
};