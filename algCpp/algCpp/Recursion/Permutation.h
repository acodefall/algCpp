#pragma once
#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
using namespace std;

/* Write permutation code using recursion
	for(i... Len)
		for(j... Len)
			for(k... Len)
				subset = src[i] src[j] src[k]

	Becomes
		Rec(int srcdx, int outIndex)
		{
			for(i = srcdx; ... Len)
				out[outIndex] = src[i];
				Rec(i,outIndex+1);
		}
		
namespace PermutationsNM //@RED20170729011
{
	class Permutation
	{
		public:

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




};*/

