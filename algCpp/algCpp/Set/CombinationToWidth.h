#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
#include "Graphbuild.h"
using namespace std;




/*
			Combination_20170729003
				First rule is that combination cares about DATA but not their ORDER.
				So we can not create a brand new combination by just re arranging the elements of an alareday existing combination.
				This means "coffee, Tea" and "Tea, coffee" mean just one combination. 
				So if SrcLen is 5 and combLen is 5, then we can have only combination. 
				But if we reduce the combLen to 3, then we can have few more combinations.

				Second rule is that combinations does not allow duplicates. This mean "cofee, cofee" is not allowed. 
				Examples
					All Combination for {1 2 3} 
					All cobinations(this is same as powerset):	
							{}, {1}, {2}, {3}, {1,2}, {1,3}, {1,4}, {2,3}, {1,2,3}
				
					Combination for of length 2 for {1 2 3 4} 
							{1,2} {1,3} {1,4} {2,3} {2,4} {3,4}


			Types Combintaion problems_20170729005
				Combination problems come in 3 flavours: 
				-Generatw all the possible combinations of length-0 to length of source-set. 
					Ex: SrcLen is 3, then generate combination of 0-length, 1-length, 2-length, and 3-length.
						This is nothing but POWER SET. Power set follows other rules of Combinations.
						It honors DATA and ignores ORDER and does not allow duplicates 
						This can be coded using generator code.
						When using recursion code for generating combinations of all the sizes, we have to call the recursion function once for every combLlen. 
							If the srcLen 4. To generate combs of size 1, 2,3, and 4; call the rec-function with 1,2,3,4 as combLen.
							for (int i = 1; i <= srcLen; i++)
							{
								CombinationsAllBitGen(src, i, srcIndex, output, outIndex);
							}



				-Generate combinations of width X; 
					Ex: SrcLen is 5, then generate combination of 3.
					This can be coded using either 'bit-generation code' or 'plain-recursion-code'. 
					This is also known as SubSetSum problem.				

				-Generate combinations who's sum is X; 	
				This can be coded using either 'bit-generation code' or 'plain-recursion-code'. 


			Generate combinations using Recursion_20170729007
			


			Code:
					Func(0,0,combLen);

					void Func(srcIndex, outIndex, remaining )
					{
						if (remaining == 0)
						{
							PRINT comb and exit
							return;
						}
				
			    		for (int i = srcIndex; i <= srcLen - remaining; i++) 
						{
							output[outIndex] = src[i];
							CombinationUsingForLoop(src, srcLen, i + 1, output, outIndex + 1, combLen, Sum + src[i]);
						}
					}

=*/
namespace CombinationsOfWidthXNM //@RED20170729007
{
	class CombinationsOfWidthX
	{
		public:
			void useCombination()
			{
				cout << "CombinationUsingBitGen \r\n \r\n";
				int outputLen = 3;
				int output[3] = { 0 };
				char src2[4] = { 'A', 'B', 'C', 'D' };
				CombinationUsingBitGenX(src2, 0, 4, output, 0, outputLen);


				outputLen = 3;
				output[3] = { 0 };
				char src3[5] = { '1', '2', '3', '4', '5' };
				CombinationUsingBitGenX(src3, 0, 5, output, 0, outputLen);
				/*
					1 2 3
					1 2 4
					1 2 5
					1 3 4
					1 3 5
					1 4 5
					2 3 4
					2 3 5
					2 4 5
					3 4 5
				*/
				int combLen1 = 3;
				int srcLen1 = 5;
				int srcIndex1 = 0;
				int src1[5] = { 1, 2, 3, 4, 5 };
				int output1[3] = { '0' };
				int outIndex1 = 0;
				//int remaining1 = combLen1;
				CombinationUsingForLoop(src1, srcLen1, srcIndex1, output1, outIndex1, combLen1);
				/*
					1 2 3
					1 2 4
					1 2 5
					1 3 4
					1 3 5
					1 4 5
					2 3 4
					2 3 5
					2 4 5
					3 4 5
				*/

			}

			//remaining:- number of slots vacant OR "yet to be filled" combination
			void CombinationUsingForLoop(int* src, int srcLen, int srcIndex, int* output, int outIndex, int combLen)
			{
				if (outIndex == combLen)
				{
					//cout << "all '" << combLen << "' filled"<< endl;
					for (int i = 0; i < combLen; i++)
						cout << output[i] << " ";
					cout << endl;
					return;
				}
				
				//cout << "Fill slot '" << outIndex << "'" << endl;

				//(srcLen - remaining) means, if there are 2 more slots to be filled then we should stay within last two elements from the end. 
				//if srcLen = 5, combLen = 3; then we remaining is 3. 
				//for (int i = srcIndex; i <=	srcLen - remaining; i++) //'count - count' is same as index so use "<="
				for (int i = srcIndex; i < srcLen; i++) //'count - count' is same as index so use "<="
				{
					//Fill the current-slot or column
					output[outIndex] = src[i];
					//cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;

					//RECURSE for filling the slot that is RIGHT of current-slot. That is why we increment the srcIndex (that is i+1)
					//remaining is the slots to be filled, this keeps on coming down.
					//CombinationUsingForLoop(src, srcLen, i+1, output, outIndex+1, combLen, remaining-1);
					CombinationUsingForLoop(src, srcLen, i + 1, output, outIndex + 1, combLen);
				}
			}

			

			void CombinationUsingBitGenX(char src[], int srcindex, int srcLen, int output[], int outIndex, int outputLen)
			{
				if (outputLen == outIndex)
				{
					//Maps the bits to src[], provided the enabled bits are equal to K
					cout << "       ";
					for (int a = 0; a < outIndex; a++)
					{
						cout << output[a] << " ";
					}
				
					cout << "\r\n";
					return;
				}

				if (srcindex >= srcLen)
					return;

				output[outIndex] = src[srcindex] - '0';
				CombinationUsingBitGenX(src, srcindex+1, srcLen, output, outIndex + 1, outputLen);

				//Note that we do not increment the outIndex 
				CombinationUsingBitGenX(src, srcindex+1, srcLen, output, outIndex, outputLen);
			}

		
	};
};

