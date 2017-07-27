#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
#include "Graphbuild.h"
using namespace std;

//http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
namespace CombinationsBitGenNM //@RED20170725046
{
	class CombinationUsingBitGen
	{
		public:
			void useCombination()
			{
			
				cout << "CombinationUsingBitGen \r\n \r\n";
				int TotalbitLen = 4;
				int OneBits = 0;
				int Bits[4] = { 0 };
				int EnabledBits = 4;
				char src2[4] = { 'A', 'B', 'C', 'D' };
				CombinationUsingBitGenX(src2, 4, Bits, 0, TotalbitLen, 4, OneBits);


				TotalbitLen = 4;
				OneBits = 0;
				Bits[4] = { 0 };
				EnabledBits = 2;
				char src3[4] = { '1', '2', '3', '4' };
				CombinationUsingBitGenX(src3, 4, Bits, 0, TotalbitLen, EnabledBits, OneBits);

				/*
					Combination for '1', '2', '3', '4' of width 2 are
									"1,2" "1,3", "1,4", "2,3", "2,4", "3,4"
					
					Combinations match with Bits as follows
						1 1 1 1
						1 1 1 0
						1 1 0 1
						1 1 0 0        1 2
						1 0 1 1
						1 0 1 0        1 3
						1 0 0 1        1 4
						1 0 0 0
						0 1 1 1
						0 1 1 0        2 3
						0 1 0 1        2 4
						0 1 0 0
						0 0 1 1        3 4
						0 0 1 0
						0 0 0 1
						0 0 0 0
				
				*/

			}


			void CombinationUsingBitGenX(char src[], int srcLen, int Bits[], int bitIndex, int TotalbitLen, int K, int OneBits)
			{
				if (TotalbitLen == bitIndex)
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
				CombinationUsingBitGenX(src, srcLen, Bits, bitIndex + 1, TotalbitLen, K, OneBits + 1);

				Bits[bitIndex] = 0;
				CombinationUsingBitGenX(src, srcLen, Bits, bitIndex + 1, TotalbitLen, K, OneBits);
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

