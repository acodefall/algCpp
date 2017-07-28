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

				int combLen1 = 2;
				int srcLen1 = 4;
				int srcIndex1 = 0;
				int src1[4] = { 1, 2, 3, 4 };
				int output1[3] = { '0' };
				int outIndex1 = 0;
				int remaining1 = combLen1;
				CombinationUsingForLoop(src1, srcLen1, srcIndex1, output1, outIndex1, combLen1, remaining1);
				//CombinationUsingForLoop(char* src, int srcLen, int srcIndex, int* output, int outIndex, int combLen, int remaining)
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
				
				       1 2 3 4 5 
					   0 1 2
					   

					   RemainingBts = 3 - (startIndex + 1);
					                =  3     - )
								    <=  3 //0,1

									(startIndex + 1 + ReminBits) < srcLen;

                       st = 2
					     Rmn = 3 - (3);
					   
					   RemainingSrcBts 
					   SrcLen - RequiredBits
					   SrcLen - (totalBitLen - coverBitLen)

					       (5 - (start + 1)) 
						    5 - (0 + 1) = 4
							  < 4 = 0, 1 , 2

							  
							  3
							     2
								    1

								     
									 remain < end - start
									 
									 
						CombLen = 3
src: 1  2  3  4 
	 	2  3  4 
		   3  4 
              4		   
		   
		
		1

	1  2  3  4 

	
	2
	3



Fill slot '0'
output[0] = '1'
Fill slot '1'
output[1] = '2'
Fill slot '2'
output[2] = '3'
all '3' filled
				1 2 3
output[2] = '4'
all '3' filled
				1 2 4
output[1] = '3'
Fill slot '2'
output[2] = '4'
all '3' filled
				1 3 4
output[0] = '2'
Fill slot '1'
output[1] = '3'
Fill slot '2'
output[2] = '4'
all '3' filled
				2 3 4
				
				
				
				
				
Fill slot '0'
output[0] = '1'
Fill slot '1'
output[1] = '2'
all '2' filled
				1 2
output[1] = '3'
all '2' filled
				1 3
output[1] = '4'
all '2' filled
				1 4
output[0] = '2'
Fill slot '1'
output[1] = '3'
all '2' filled
				2 3
output[1] = '4'
all '2' filled
				2 4
output[0] = '3'
Fill slot '1'
output[1] = '4'
all '2' filled
				3 4
				
					       
				*/

			}

			//remaining:- number of slots vacant OR "yet to be filled" combination
			void CombinationUsingForLoop(int* src, int srcLen, int srcIndex, int* output, int outIndex, int combLen, int remaining)
			{
				if (remaining == 0)
				{
					cout << "all '" << combLen << "' filled"<< endl;
					for (int i = 0; i < combLen; i++)
						cout << output[i] << " ";
					cout << endl;
					return;
				}
				
				cout << "Fill slot '" << outIndex << "'" << endl;
				for (int i = srcIndex; i <=	srcLen - remaining; i++) //'count - count' is same as index so use "<="
				{
					
					output[outIndex] = src[i];
					cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;
					CombinationUsingForLoop(src, srcLen, i+1, output, outIndex+1, combLen, remaining-1);
				}
			}

			//remaining:- number of slots vacant OR "yet to be filled" combination
			void CombinationUsingForLoop(int* src, int srcLen, int srcIndex, int* output, int outIndex, int combLen, int Sum)
			{
				if (remaining == 0)
				{
					cout << "all '" << combLen << "' filled" << endl;
					for (int i = 0; i < combLen; i++)
						cout << output[i] << " ";
					cout << endl;
					return;
				}
				
				//No need to go further
				if (Sum > 0)
					return;

				cout << "Fill slot '" << outIndex << "'" << endl;
				for (int i = srcIndex; i <= srcLen - remaining; i++) //'count - count' is same as index so use "<="
				{

					output[outIndex] = src[i];
					cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;
					CombinationUsingForLoop(src, srcLen, i + 1, output, outIndex + 1, combLen, Sum + src[i]);
				}
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

