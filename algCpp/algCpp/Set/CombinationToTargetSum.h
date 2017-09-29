#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>

using namespace std;



/*
			Combintaion problems
				-Generate combinations who's sum is X; 	
					This can be coded using either 'bit-generation code' or 'plain-recursion-code'. 
		
			Finding combinations that adds to TargetSum X_20170729009
				This is based on plain combination problem. Try to generate all the possible combinations.
				Print only those combinations that add up to target sum, and once the TargetSum is reached, 
				stop working on that particular subset as if it reached FULL bitwidth. 
				Similarly if the sum goes over the Target sum, then do not print the combination and 
				stop working on that particular subset as if it reached FULL bitwidth. 
				There could be some subsets who's some does not reach the Targetsum even after reaching 
				FULL bitwidth.
				
				This recursion function will accept sum and targetSum as input parameter, and at each 
				the beginning of every round we check whether the Sum is EQUAL to targetSum.

				This is also known as SubSetSum problem, and coin change problem.				
				
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
namespace CombinationToTargetSumNM //@RED20170729009
{
	class CombinationToTargetSum
	{
		public:
			void useCombination()
			{
				
				int TargetSum4 = 4;
				int srcLen4 = 3;
				int src4[3] = { 1, 2, 3 };
				int output4[4] = { 0 };
				int outIndex4 = 0;
				int Sum4 = 0;
				CoinMaking(src4, srcLen4, output4, outIndex4, TargetSum4, Sum4);


				cout << "Combinations that add up to Sum X \r\n \r\n";
			
				int TargetSum = 15;
				int srcLen = 5;
				int srcIndex = 0;
				int src[5] = { 5, 5, 10, 2, 3 };
				int output[5] = { 0 };
				int outIndex = 0;
				int Sum = 0;
				CombinationToTargetSumBitGen(src, srcLen, srcIndex, output, outIndex, TargetSum, Sum);

				int TargetSum1 = 15;
				int srcLen1 = 5;
				int srcIndex1 = 0;
				int src1[5] = { 5, 5, 10, 2, 3 };
				int output1[5] = { 0 };
				int outIndex1 = 0;
				int Sum1 = 0;
				CombinationToTargetSumRecursion(src1, srcLen1, srcIndex1, output1, outIndex1, TargetSum1, Sum1);
			}

			
			void CoinMaking(int* src, int srcLen,int* output, int outIndex, int TargetSum, int Sum )
			{
				//Print the existing combination, and break the recursion. Do not build this combination any more
				if (Sum == TargetSum)
				{
					cout << "following adds to " << TargetSum << endl;
					for (int i = 0; i < outIndex; i++)
					{
						cout << output[i] << " ";
					}
					cout << endl;
					cout << endl;
					return;
				}

				//break the recursion.Do not build this combination any more
				if (Sum > TargetSum)
					return;

				//Sum is UNDER TargetSUM so try to add one more SLOT to combination, and see if the SUM becomes equal to TargetSum.
				for (int i = 0; i < srcLen; i++) //'count - count' is same as index so use "<="
				{
					//Fill the current-slot or column
					output[outIndex] = src[i];
					cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;

					//RECURSE for filling the slot that is RIGHT of current-slot. 
					//ADD the value of current-slot to SUM.
					//SUM should reflect the summ of whatever is already in output[]
					//NEXT slot will be filled by the element that is "RIGHT of i" so pass "i+1" to next elevel.
					CoinMaking(src, srcLen,  output, outIndex + 1, TargetSum, Sum + src[i]);
				}
			}

			void CombinationToTargetSumRecursion(int* src, int srcLen, int srcIndex, int* output, int outIndex, int TargetSum, int Sum)
			{
				//Print the existing combination, and break the recursion. Do not build this combination any more
				if (Sum == TargetSum)
				{
					cout << "following adds to " << TargetSum << endl;
					for (int i = 0; i < outIndex; i++)
					{	
						cout << output[i] << " ";
					}
					cout << endl;
					cout << endl;
					return;
				}

				//break the recursion.Do not build this combination any more
				if (Sum > TargetSum)
					return;
				
				//Sum is UNDER TargetSUM so try to add one more SLOT to combination, and see if the SUM becomes equal to TargetSum.
				for (int i = srcIndex; i <	srcLen; i++) //'count - count' is same as index so use "<="
				{
					//Fill the current-slot or column
					output[outIndex] = src[i];
					cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;

					//RECURSE for filling the slot that is RIGHT of current-slot. 
					//ADD the value of current-slot to SUM.
					//SUM should reflect the summ of whatever is already in output[]
					//NEXT slot will be filled by the element that is "RIGHT of i" so pass "i+1" to next elevel.
					CombinationToTargetSumRecursion(src, srcLen, i+1, output, outIndex+1, TargetSum, Sum + src[i]);
				}
			}

			//remaining:- number of slots vacant OR "yet to be filled" combination
			void CombinationToTargetSumBitGen(int* src, int srcLen, int srcIndex, int* output, int outIndex, int TargetSum, int Sum)
			{
				

				if (Sum == TargetSum)
				{
					cout << "following adds to" << TargetSum << endl;
					for (int i = 0; i < outIndex; i++)
					{
						if (output[i] == 1)
						{
							cout << src[i] << " ";
						}
					}
					cout << endl;
					cout << endl;
					return;
				}
				if ( (outIndex == srcLen) || (Sum > TargetSum))
				{
					return;
				}
				
				
				//Add current element to SUM, and appropriately ENABLE the BIT also.
				output[outIndex] = 1;
				CombinationToTargetSumBitGen(src, srcLen, srcIndex + 1, output, outIndex + 1, TargetSum, Sum + src[srcIndex]);
					
				//Do NOT NOT add current element to SUM, and appropriately DISABLE the BIT also.
				output[outIndex] = 0;
				CombinationToTargetSumBitGen(src, srcLen, srcIndex + 1, output, outIndex + 1, TargetSum, Sum);
				
			}
		
	};
};

