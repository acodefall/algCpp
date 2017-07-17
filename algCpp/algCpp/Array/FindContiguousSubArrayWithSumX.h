#pragma once
#include <iostream>
#include <sstream>
using namespace std;
namespace FindContiguousSubArrayWithSumXNM
{
	/*
		Find continous Subarray of Sum X using NestedLoop__20170714001
			In a array detect the continuous elements that will result in specific sum.
			Say { 1,2,4} and target-sum is 6. Continuous elements 2 and 4 will result in sum of 6.
			Solution is maintain two indexes: addIndex and subtractIndex. Both will start from 0. 
			But addIndex will be ahead of subtractIndex. addIndex points to element that we want to add to CumulativeSum.
			subtractIndex points to element that we want to subtract from the CumulativeSum, if the CumulativeSum is > TargetSum.
			Say AddIndex is 5 and subtractIndex is 2. We add src[5] to CumulativeSum, if the CumulativeSum goes above TargetSum,
			then we delete src[2] from CumulativeSum. Subtrcat until CumulativeSum is NOT above TargetSum.

			Takes O(N) time.
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