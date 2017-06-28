#pragma once
#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
using namespace std;

namespace PermutationsNM
{
	class Permutation
	{
		public:

			/*
				Output
					Permutation (without Dupe)
					//No duplicates means a set not having "AA". 
					//Unordered means sets "AB" and "BA" are considered as valid. So Unordred is applied across the sets.  
						A B C
						A B D
						A C B
						A C D
						A D B
						A D C
						B A C
						B A D
						B C A
						B C D
						B D A
						B D C
						C A B
						C A D
						C B A
						C B D
						C D A
						C D B
						D A B
						D A C
						D B A
						D B C
						D C A
						D C B

					Permutation (WithDupe)
						A A A
						A A B
						A A C
						A A D
						A B A
						A B B
						A B C
						A B D
						A C A
						A C B
						A C C
						A C D
						A D A
						A D B
						A D C
						A D D
						B A A
						B A B
						B A C
						B A D
						B B A
						B B B
						B B C
						B B D
						B C A
						B C B
						B C C
						B C D
						B D A
						B D B
						B D C
						B D D
						C A A
						C A B
						C A C
						C A D
						C B A
						C B B
						C B C
						C B D
						C C A
						C C B
						C C C
						C C D
						C D A
						C D B
						C D C
						C D D
						D A A
						D A B
						D A C
						D A D
						D B A
						D B B
						D B C
						D B D
						D C A
						D C B
						D C C
						D C D
						D D A
						D D B
						D D C
						D D D

			*/
			void usePermutation()
			{
				char src[4] = { 'A', 'B', 'C', 'D' };
			

				cout << "Permutation With Duplicates \r\n \r\n";
				char out1[3] = { 0 };
				PermutationWithDupesKofN(src, 4, out1, 0, 3);

				cout << "PermutationWithoutDupes() \r\n \r\n";
				char out2[4] = { 0 };
				PermutationWithoutDupes(src, 4, 0, out2, 0, 4);	

			
				
			}



		

				
			void PermutationWithDupesKofN(char src[], int srcLen, char out[], int outIndex, int K)
			{
				//This controls the length of combinations string
				if (outIndex == K)
				{
					for (int a = 0; a < outIndex; a++)
					{
						cout << out[a] << " ";
					}
					cout << "\r\n";
					return;
				}
				//This inner loop does not control the length of the combination, instead it ONLY controls how many different values can go in to  a specific position in out-array.
				//Length of the combination is controlled by width of out-array. Ex; We can have output array of width 10, and number of characters to fill is only 2. In that case, 
				//there will be many duplicates.
				for (int i = 0; i < srcLen; i++)
				{
					out[outIndex] = src[i];
					PermutationWithDupesKofN(src, srcLen, out, outIndex + 1, K);
				}
			}

			

			//Every round of dupes starts at same position
			void PermutationWithoutDupes(char src[], int srcLen, int srcIndex, char out[], int outIndex, int K)
			{
				if (outIndex == K)
				{
					for (int a = 0; a < outIndex; a++)
					{
						cout << src[out[a]] << " ";
					}
					cout << "\r\n";
					return;
				}
				for (int i = 0; i < srcLen; i++)
				{
					bool usedAlready = false;
					for (int j = 0; j < outIndex; j++)
					{
						if (out[j] == i)
						{
							usedAlready = true;
							break;
						}
					}
					if (usedAlready == false)
					{
						out[outIndex] = i;
						PermutationWithoutDupes(src, srcLen, i, out, outIndex + 1, K);
					}
				}
			}

			
			
	};




};

