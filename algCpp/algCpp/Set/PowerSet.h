#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace PowerSetNM
{
	class PowerSet
	{
		public:
			void printPowerSetUsingBitGen(int src[], int srcLen, int bits[], int bitIndex)
			{
				if (bitIndex == srcLen)
				{

					//Print the bits also just for the sake of understanding
					for (int i = 0; i < bitIndex; i++)
					{
						if (bits[i])
						{
							cout << " 1 ";
						}
						else
							cout << " 0 ";

					}


					cout << "  ";

					//Print the powerset
					for (int i = 0; i < bitIndex; i++)
					{
						if (bits[i])
						{
							cout << src[i] << " ";
						}
						
					}

				

					

					cout << "\r\n";
					return;
				}

				bits[bitIndex] = 1;
				printPowerSetUsingBitGen(src, srcLen, bits, bitIndex + 1);

				bits[bitIndex] = 0;
				printPowerSetUsingBitGen(src, srcLen, bits, bitIndex + 1);
			}
	};

	class CallPowerSet
	{
		public:
				void callPowerSetX()
				{
					int src[4] = { 2, 4, 6, 8 };
					int bits[4] = { 0,0,0,0 };

					PowerSet o1PwerSet;
					o1PwerSet.printPowerSetUsingBitGen(src, 4, bits, 0);
				}
	};



};