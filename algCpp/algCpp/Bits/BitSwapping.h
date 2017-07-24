#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

namespace  BitSwappingNM
{
    ////
		/*
			evenBitMask : '0001010101
			oddBitMask : '0010101010
			Value : '1010111001
			After swapping bit
			Value : '0101110110'
		*/


	class BitSwapping
    {
		public: 
		void callBitSwapping()
        {
            int evenBitMask = 0x55; //even (0101)
            int oddBitMask = 0xaa; //odd  (1010)

            int  ValueToSwap = 872121;
			cout << endl;
			cout << " evenBitMask :'" << bitset<10>(evenBitMask) << "'" << endl;
			cout << "  oddBitMask :'" << bitset<10>(oddBitMask) << "'" << endl;
			cout << "       Value :'" << bitset<10>(ValueToSwap) << "'" << endl;

			ValueToSwap = ((ValueToSwap & 0x55555555) << 1) //mask the even bits
									| 
							((ValueToSwap & 0xaaaaaaaa) >> 1);

		
			cout << "After swapping bit " << endl;
			cout << " Value :'" << bitset<10>(ValueToSwap) << "'" << endl;
			

        }
	};
};

