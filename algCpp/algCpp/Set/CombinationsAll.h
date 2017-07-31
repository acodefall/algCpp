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
		Print all the combinations
			Output is very similar to POWERSET output.
			See CombinationToWidth @RED20170729007
		
		When using recursion code for generating combinations of all the sizes, we have to call the recursion function once for every combLlen. 
		If the srcLen 4. To generate combs of size 1, 2,3, and 4; call the rec-function with 1,2,3,4 as combLen.
		for (int i = 1; i <= srcLen; i++)
		{
			CombinationsAllBitGen(src, i, srcIndex, output, outIndex);
		}
		
		We do not have to do this if we are using BITGen code for generating all combs of all the size.

			

*/
namespace CombinationsAllNM 
{
	class CombinationsAll
	{
		public:
			void useCombination()
			{
				int srcLen = 3;
				int srcIndex = 0;
				int src[3] = { 2, 3, 5};
				int output[3] = { 0 };
				int outIndex = 0;
				CombinationsAllRecursionX(src, srcLen, srcIndex, output, outIndex);
				/*
					2
					2 3
					2
					3
					2 3 5
					2 3
					2 5
					2
					3 5
					3
					5
				*/

				int srcLen1 = 3;
				int srcIndex1 = 0;
				int src1[3] = { 2, 3, 5 };
				int output1[3] = { 0 };
				int outIndex1 = 0;
				CombinationsAllBitGen(src1, srcLen1, srcIndex1, output1, outIndex1);
				/*
					5 3 2
					5 3 2
					5 3
					5 2
					5
					3 2
					3
					2
				*/
			}

			void CombinationsAllRecursionX(int* src, int srcLen, int srcIndex, int* output, int outIndex)
			{
				for (int i = 1; i <= srcLen; i++)
				{
					CombinationsAllBitGen(src, i, srcIndex, output, outIndex);
				}
			}
			/*
				Finding combination that add up to TargetSum is like a Powerset problem. 
				We generate combinations of width 1, 2, 3... and check if their sum adds to Targetsum.
				If Sum = Targetsum, then Print the existing combination, and break the recursion.
				No need to add any more slots to this particular combination because this already reached TargetSum.
				Similarly if the Target sum goes over TargetSum, break the recursion. 
				
				Recursion has to keep track of SUM of already built combination in a REC-param.
				In the beginning SUM will be 0. When ever we place a number in the SLOT, add that to SUM also.
				Say if you place '4' in 1st slot, then add 4 to SUM.
				Say if you place '5' in 2nd slot, then add 5 to SUM. So TotalSum will be 9.
				
				TargetSum = 15
				S={5, 5, 10, 2, 3}
				
				combination = corresponding-sum									
				{0}=5												//Caller
				{5}=5												//1st level  REC	
						{5  5}=10									//2nd level  REC	
									{5  5  10}=20					//3rd level  REC "Sum > TargetSum" so break the REC, abandon the combination {5,5,10}
									
									{5  5  2}=12					//3rd level  REC 
													{5  5  2  3}=15	//4th level  REC "Sum == TargetSum" so break the REC, Log the combination {5,5,2,3}
																	
						 <-											//Recursion returns to 2nd level

									{5  5  3}=13					//3rd level  REC "Len=SrcLen", break the recursion
						 <-


			*/
			void CombinationsAllRecursion(int* src, int srcLen, int srcIndex, int* output, int outIndex)
			{
				//Print the existing combination, and break the recursion
				if (outIndex == srcLen)
				{
					for (int i = 0; i < outIndex; i++)
					{	
						cout << output[i] << " ";
					}
					cout << endl;
					return;
				}

				
				//Recursion can go until the llast element of src-set
				for (int i = srcIndex; i <	srcLen; i++)
				{
					//Fill the current-slot or column with value
					output[outIndex] = src[i];
					
					//cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;

					//RECURSE for filling the slot that is RIGHT of current-slot. 
					//NEXT slot will be filled by the element that is "RIGHT of i" so pass "i+1" to next elevel.
					CombinationsAllRecursion(src, srcLen, i+1, output, outIndex+1);
				}
			}

			
			void CombinationsAllBitGen(int* src, int srcLen, int srcIndex, int* output, int outIndex)
			{
				if ( outIndex == srcLen)
				{
					for (int i = 0; i < outIndex; i++)
					{
						if (output[i] == 1)
						{
							cout << src[i] << " ";
						}
					}
					cout << endl;
					return;
				}
				
				
				//ENABLE the BIT.
				output[outIndex] = 1;
				CombinationsAllBitGen(src, srcLen, srcIndex + 1, output, outIndex + 1);
					
				//dis-ENABLE the BIT.
				output[outIndex] = 0;
				CombinationsAllBitGen(src, srcLen, srcIndex + 1, output, outIndex + 1);
				
			}
		
	};
};

