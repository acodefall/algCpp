#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
//#include <stringstream>
using namespace std;



/*
		
		Change making problem
			Given a set of coins, arrange them in such a way that sum becomes equal to X, and also find the combination that uses least number of coins. 
			We are allowed to add same coin any number of times. Ex: 1 + 1 + 1 + 1 = 2, and 2 + 2 = 4
			As you see making 4 using "1 1 1 1" is a Permutation problem.
			So the code will generate the permutation by making recursion calls from within a ForLoop.
			Where Each level of recursion iterates the src[] from 0 and until MAX, but the Outindex increases by 1.
			Pass the CurrentSum as recursion param, and before making recursion call add the src[cur] to it CurrentSum.
			At the beginning of recursion check if the CurrentSum is equal to TargetSum. Make further recursion calls
			only if the  CurrentSum < TargetSum. If the CurrentSum == TargetSum, print the values stored in Out[] and break the recursion.
			
			sum = 4
			coins = { 1, 2, 3 };
				"1 1 1 1", "1 1 2", "2 2", "1, 3"

			This is a non-0-1-Knapsack problem.
*/
namespace CoinChangeMakingNM //@RED20170729009
{
	class CoinChangeMaking
	{
		public:
			void useCoinChangeMaking()
			{
				
				int TargetSum4 = 4;
				int srcLen4 = 3;
				int src4[3] = { 1, 2, 3 };
				int output4[4] = { 0 };
				int outIndex4 = 0;
				int Sum4 = 0;
				AddCoinsToReachTargetSumX(src4, srcLen4, output4, outIndex4, TargetSum4, Sum4);
			}

			
			
			void AddCoinsToReachTargetSum(int* src, int srcLen,int* output, int outIndex, int TargetSum, int Sum )
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


					AddCoinsToReachTargetSum(src, srcLen,  output, outIndex + 1, TargetSum, Sum + src[i]);
				}
			}


			void AddCoinsToReachTargetSumX(int* src, int srcLen, int* output, int outIndex, int TargetSum, int Sum)
			{
				//Print the existing combination, and break the recursion. Do not build this combination any more
				//if (Sum >= TargetSum)
				if(outIndex == 4)
				{
					//cout << "following adds to " << TargetSum << endl;
					for (int i = 0; i < outIndex; i++)
					{
						cout << output[i] << " ";
					}
					//cout << endl;
					cout << endl;
					return;
				}

				//break the recursion.Do not build this combination any more
				//if (Sum > TargetSum)
					//return;

				//Sum is UNDER TargetSUM so try to add one more SLOT to combination, and see if the SUM becomes equal to TargetSum.
				for (int i = 0; i < srcLen; i++) //'count - count' is same as index so use "<="
				{
					/*stringstream ss;
					ss << src[i];
					string combTemp = comb;
					combTemp += " ";
					combTemp += ss.str();*/
					//Fill the current-slot or column
					output[outIndex] = src[i];
					//cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;
					//cout << "output[" << outIndex << "] = '" << output[outIndex] << "'" << endl;
					//RECURSE for filling the slot that is RIGHT of current-slot. 
					//ADD the value of current-slot to SUM.
					//SUM should reflect the summ of whatever is already in output[]
					//NEXT slot will be filled by the element that is "RIGHT of i" so pass "i+1" to next elevel.


					AddCoinsToReachTargetSumX(src, srcLen, output, outIndex + 1, TargetSum, Sum + src[i]);
				}
			}
	};
};

