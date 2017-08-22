#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
using namespace std;



/*
		Change making problem using permutations
			Create a sum by adding set of coins. We can add same coin repeatedly.
			Ex: 2 + 2 = 4; and 1 + 3 = 4.
			As you see, the combination "2 2" has duplcate elements so this is a Permutation problem.
			This is different from cutting-rod problem, that was 0-1 Knapsack problem, and we could use an item only once, no duplicates were allowed. But coin change problem we can have duplicates elements.

			Generate the permutations by making recursion calls from within a ForLoop.
			ForLoop at Each level of recursion iterates the src[] from 0 and until SrcLen.
			Recursion deapth goes down until the Target Sum is reached. So complexity at the worst is (Sum/deapth * SrcLen)
			Width of permutation depends on Recursion depth, and Width of permutation could be anything,  
							"1 1 1 1" = 4 //has width of 4
							"2 + 2" = 4 //has width of 2
			
			Recursion code
							Rec(out, o, sum)
							{
								if(sum >= 4)
									return
								for(i = 0; i < srcLen; i++)
									Rec(out, o+1, sum + src[i]);
							}

			Logic of addition is as follows:
				sum = 4
				coins = { 1, 2, 3 };

			Add just 1cent coins till the sum reaches the TargetSum. Then Eject one 1cent coin and replace it with 2cent and 3cent. Now we created SUM in 3 ways.
			1 1 1 1  //using 'all 1cents',
			1 1 1 2  //'multiple 1cents + one 2cent', Reject the combo
			1 1 1 3  //'multiple 1cents + one 3cent'  Reject the combo

			1 1 1 2 //Make sum using multiple 1cent + one 2cent. Reject the combo
			1 1 1 3 //Make sum using multiple 1cent + one 3cent.  Reject the combo  
				
           	//In the next step, eject 2 of 1cents	
			1 1 2 1 
			1 1 2 2
			1 1 2 3
			1 1 3 1
			1 1 3 2
			1 1 3 3

			Complexity in worst case is O(AverageWidth * SRcLen) = O(Sum * SRcLen)

*/
namespace CoinChangeMakingUsingPermNM //@RED20170818001
{
	class CoinChangeMakingUsingPerm
	{
		public:
			void useCoinChangeMaking()
			{
				//This is based on permutations
				int TargetSum4 = 4;
				int srcLen4 = 3;
				int src4[3] = { 1, 2, 3 };
				int output4[4] = { 0 };
				int outIndex4 = 0;
				int Sum4 = 0;
				AddCoinsToReachTargetSum(src4, srcLen4, output4, outIndex4, TargetSum4, Sum4);
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
					AddCoinsToReachTargetSum(src, srcLen,  output, outIndex + 1, TargetSum, Sum + src[i]);
				}
			}
	};
};
