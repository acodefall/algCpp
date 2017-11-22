#pragma once
#include <iostream>
#include <sstream>
using namespace std;
namespace FindContiguousSubArrayWithSumXNM
{
	/*
		Find continous Subarray of Sum X using NestedLoop_20170714001
			In a array detect the continuous elements that will result in specific sum.
			Say { 1,2,4} and target-sum is 6. Continuous elements 2 and 4 will result in sum of 6.

			Iterate the src array from 0th index, and go adding the elements for creating cumulative sum.
			At some point, cumulative sum will go above Target sum or become exactly equal to Target sum.
			If cumulative sum goes above TargetSumm then we have to substract from Cumulative sum, so that it comes closer to Target sum. 
			We can only substact the numbers that has been added in to CumulativeSum; that means the number being subtracted
			should come from 0th index. So read the values from 0th index, and subtract them from cumulative sum.

			At some point cumulative Sum may drop below the TargetSum; at that time we have to stop subtracting, and start adding in to cumulative sum.
			The Number being added should come from the index where we had stopped earlier. It possible that we may have to 
			subtract the numbers from cumulative sum once more. The number being subtracted should come from the index where we had stopped earlier.
			Basically we have to maintain two indexes called 'AddIndex' and 'SubtractIndex'; both start at 0 and goes on increasing.
			We use a While loop for iterating src-array.

			At the top of the while loop, have an nested while loop for subtracting from CumulativeSum.
			After coming out of nested while loop check if the CumulativeSum is eqiual to TargetSum. 
				If CumulativeSum == TargetSum)
					break;
				else
					Add to CumulativeSum.

			Important point is while-loop first subtracts and then adds.Takes O(N) time

		src
		  25  12  14  22  19  15  10  23
		   0   1   2   3   4   5   6   7

		runningSum '0' targetSum '55'
		   addIndex '0' subtractIndex '0'
		   runningSum '0' targetSum '55'
		   ADD: runningSum + src[0] = 0 + 25 = 25

		runningSum '25' targetSum '55'
		   addIndex '1' subtractIndex '0'
		   runningSum '25' targetSum '55'
		   ADD: runningSum + src[1] = 25 + 12 = 37

		runningSum '37' targetSum '55'
		   addIndex '2' subtractIndex '0'
		   runningSum '37' targetSum '55'
		   ADD: runningSum + src[2] = 37 + 14 = 51

		runningSum '51' targetSum '55'
		   addIndex '3' subtractIndex '0'
		   runningSum '51' targetSum '55'
		   ADD: runningSum + src[3] = 51 + 22 = 73

		runningSum '73' targetSum '55'
		   addIndex '4' subtractIndex '0'
		   DELETE : runningSum + src[0] = 48 + 25 = 48
		   runningSum '48' targetSum '55'
		   ADD: runningSum + src[4] = 48 + 19 = 67

		runningSum '67' targetSum '55'
		   addIndex '5' subtractIndex '1'
		   DELETE : runningSum + src[1] = 55 + 12 = 55
		   runningSum '55' targetSum '55'
		   runningSum == targetSum 55 55
	*/
	const int SIZEX = 8;
	class FindContiguousSubArrayWithSumX
	{
		public:
			void callFindContiguousSubArrayWithSumX()
			{
				int src[SIZEX] = { 25, 12, 14, 22, 19, 15, 10, 23 };

				stringstream ss;
				cout << "src " << endl;
				for (int i = 0; i < SIZEX; i++)
				{
					cout << setw(4) << src[i];
					ss << setw(4) << i;
				}
				cout << endl;
				cout << ss.str() << endl;
				
				FindContiguousSubArrayWithSum(src, 55);
			}

			void FindContiguousSubArrayWithSum(int src[SIZEX], int targetSum)
			{
				int runningSum = 0;
				int subtractIndex = 0;
				int addIndex = 0;
				while (true)
				{
					cout << endl << "runningSum '" << runningSum << "' targetSum '" << targetSum << "'" << endl;
					cout << "   addIndex '" << addIndex << "' subtractIndex '" << subtractIndex << "'" << endl;
					//If the runningSum is more than targetSum, substract previously-added items from runningSum
					while (runningSum > targetSum)
					{
						runningSum -= src[subtractIndex];
						cout << "   DELETE : runningSum + src[" << subtractIndex << "] = " << runningSum << " + " << src[subtractIndex] << " = " << runningSum << endl;
						subtractIndex++;
					}

					cout << "   runningSum '" << runningSum << "' targetSum '" << targetSum << "'" << endl;

					//now targetSum could be <= targetSum.
					//if it is EQAUL quit
					//else we need to add 
					if ((runningSum == targetSum))
					{
						cout << "   runningSum == targetSum " << targetSum << " " << runningSum;
						break;
					}
					cout << "   ADD: runningSum + src[" << addIndex << "] = " << runningSum << " + " << src[addIndex] << " = " << runningSum + src[addIndex] << endl;
					runningSum += src[addIndex];
					
					addIndex++;
				}
			}
	};
};