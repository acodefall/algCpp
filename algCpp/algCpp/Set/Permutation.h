#pragma once
#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
using namespace std;

namespace PermutationsNM //@RED20170729011
{
	class Permutation
	{
		public:

			/*
				Permutations of width X
					Permutation by definition "honors ORDER, not just DATA" and also allows dupes.
					So "coffee, Tea", "Tea, coffee", "coffee, coffee"; all these are valid.
					Permutaion can be generated using Recursion code and it is same as combination code.
					One difference is, in case of PERM, the ForLoop at every level of recursion starts from beginning.
					Because of this we are able generate duplicates like AA. Since ForLoop starts from beginning, 
					there is no need to pass srcIndex as rec-param.

					char src[4] = { 'A', 'L', 'G', 'O'};
					AA AL AG AO LA LL LG LO GA GL GG GO OA OL OG OO
					//You can see AA, AL and LA

					Read "Generate combinations using Recursion_20170729007"

				Output
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
				char src[4] = { 'A', 'L', 'G', 'O'};
				int srcLen = 4;
				int permLen = 2;

				cout << "Permutation With Duplicates \r\n \r\n";
				char out1[3] = { 0 };
				PermutationWithDupesKofN(src, srcLen, out1, 0, permLen);
				//AA LA GA OA AL LL GL OL AG LG GG OG AO LO GO OO
				//AA AL AG AO LA LL LG LO GA GL GG GO OA OL OG OO
				//This is a PERM because it "honors ORDER, not just DATA" EX: we have both LG and GL
				//It also has duplicates AA

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

