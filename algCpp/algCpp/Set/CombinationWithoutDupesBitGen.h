#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
#include "Graphbuild.h"
using namespace std;

namespace CombinationsBitGenNM
{
	class CombinationUsingBitGen
	{
		public:
			void useCombination()
			{
			
				cout << "CombinationWithoutDuplicateUsingBitGen \r\n \r\n";
				int bitLen = 4;
				int OneBits = 0;
				int Bits[4] = { 0 };
				char src2[4] = { 'A', 'B', 'C', 'D' };
				CombinationWithoutDuplicateUsingBitGen(src2, 4, Bits, 0, bitLen, 4, OneBits);

			}


			void CombinationWithoutDuplicateUsingBitGen(char src[], int srcLen, int Bits[], int bitIndex, int bitsLen, int K, int OneBits)
			{
				if (bitsLen == bitIndex)
				{
					//Prints the Bits for the sake of info
					for (int a = 0; a < bitIndex; a++)
					{
						cout << Bits[a] << " ";
					}


					//Maps the bits to src[], provided the enabled bits are equal to K
					if (OneBits == K)
					{
						cout << "       ";
						for (int a = 0; a < bitIndex; a++)
						{
							if (Bits[a] == 1)
								cout << src[a] << " ";
						}
					}
					cout << "\r\n";
					return;
				}

				Bits[bitIndex] = 1;
				CombinationWithoutDuplicateUsingBitGen(src, srcLen, Bits, bitIndex + 1, bitsLen, K, OneBits + 1);

				Bits[bitIndex] = 0;
				CombinationWithoutDuplicateUsingBitGen(src, srcLen, Bits, bitIndex + 1, bitsLen, K, OneBits);
			}

		/*
		

		CombinationWithoutDuplicates
		A A A A
		A A A B
		A A A C
		A A A D
		A A B B
		A A B C
		A A B D
		A A C C
		A A C D
		A A D D
		A B B B
		A B B C
		A B B D
		A B C C
		A B C D
		A B D D
		A C C C
		A C C D
		A C D D
		A D D D
		B B B B
		B B B C
		B B B D
		B B C C
		B B C D
		B B D D
		B C C C
		B C C D
		B C D D
		B D D D
		C C C C
		C C C D
		C C D D
		C D D D
		D D D D




		*/
	};
};

