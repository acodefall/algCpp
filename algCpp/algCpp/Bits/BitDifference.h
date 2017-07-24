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

namespace BitDifferenceNM
{
	//@mfg20170723015
	/*
		Method2 (count number of enabled bit)
					  a:'0010010111'
					a-1:'0010010110'
			a & (a - 1):'0010010110'

					  a:'0010010110'
					a-1:'0010010101'
			a & (a - 1):'0010010100'

					  a:'0010010100'
					a-1:'0010010011'
			a & (a - 1):'0010010000'

					  a:'0010010000'
					a-1:'0010001111'
			a & (a - 1):'0010000000'

					  a:'0010000000'
					a-1:'0001111111'
			a & (a - 1):'0000000000'

			differing bits 5
	
	*/
    class BitDifference
    {
        ////@BT02
		public:
		void callBitDifference()
        {
            int x1 = 0x07;
            int x2 = 0x90;
			int a = x1 ^ x2;
			int diff = 0; //5
            cout << " X1 :'" << bitset<32>(x1) << "'  X2 : '" << bitset<32>(x2) << "'" << endl;
			cout << " X2 :'" << bitset<32>(x2) << "'" << endl;
			cout << " X1 ^ X2:'" << bitset<32>(a) << "'" << endl;
            

            //Method1
			//XOR the two numbers. Take the result and count the enabled bits using left-bit-shifting technique.
			//Left-shift the number by 1 position in a while loop, do this until the number becomes zero.
			//When looping, monitor ONLY the last bit, and if it is 1 then increment the enabled bit counter.
			//Increment the counter only when the bit is 1.
            while (a > 0)
            {
				if ((a & 0x1) > 0) //check if last bit is 1, if only increment the counter
					diff++;
                a = a >> 1;
            }
			cout << "differing bits using 'left-bit-shifting' method " << diff << endl; //5
            

            //Method2 
			cout << " Method2 " << endl;
			diff = 0; //5
            a = x1 ^ x2;
            while (a > 0)
            {
				cout << "           a:'" << bitset<10>(a) << "'" << endl;
				cout << "         a-1:'" << bitset<10>(a-1) << "'" << endl;
				cout << " a & (a - 1):'" << bitset<10>(a & (a-1)) << "'" << endl << endl; 
                a = a & (a - 1);

				diff++;
			}
			cout << "differing bits " << diff << endl; //5
        }
	};
};
