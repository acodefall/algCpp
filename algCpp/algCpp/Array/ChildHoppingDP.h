#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace ChildHoppingDPNM //@RED20170722008
{
	/*
		Child hopping stairs_@RED20170722008
			Child could climb the staircase by hopping 1-step OR 2-steps OR 3-steps at a time. 
			Question can be "to compute total number of paths" OR "total number of hops"
			Total number of hops means: "Hops required when a hop covers 1 step" +  "Hops required when a hop covers 2 steps" +  “Hops required when a hop covers 3 steps"
			
			Logic is as follows. 
			Say staircase has 4 steps. 
			We could begin by taking a single hop of 1step; and that leaves 3 more steps travel.
			OR We could also begin by taking single hop of 2steps; and that leaves 2 more steps travel.
			OR We could also begin by taking single hop of 3steps; and that leaves 1 more steps travel.

			Now we have 3 sets of steps to to be travelled. Try to travel the left over steps using hopof1step, hopof2steps and hopof3steps.  Do this until we have no 0 steps to travel. 

			Implement using recursion. Function recives stepsToTravel as input; make 3 recursion calls by subtracting 1, 2, and 3 for stepsToTravel. Sum up the return values of each recursion call and return to caller.. Recursion will break when left over steps is 0. All the logic is POST-recursion code.

			Logic is slightly different for “counting hops” or “counting paths”. 
			When counting paths, we should count 1 when the path ends, so when recursion ends (stepsLeftOver = 0) return 1. At every level of recursion, caller should sum up the return values and returned it to caller.

			When counting hops, we should count when ever the function gets called. At every level of recursion, add the return values, and then add 1 to it (to account for current rec call), and return the total sum to caller.
			Recursion should break when stepsLeftOver = 0, and returns 0.
			

			This can be implemented using DP. We will be memorizing the Steps in array that is passed as input.

			
			
			
			Traversing Staircase-4steps	using hops of 1step, 2steps and 3steps
			(4)		Total number of steps
				h1(3)									hopOf1Step was taken, 3steps are leftover
							h1(2)
										h1(1)
													h1(0)
										h2(0)

							h2(1)		
										h1(0)
							h3(0)
										
					
				h2(2)										hopOf2Steps was taken, 2steps are leftover
							h1(1)
										h1(0)
							h2(0)
				h3(1)			
							h1(0)							hopOf1Step was taken, 0steps leftover
						

			h1 = hopOf1Step, h2 = hopOf2Steps, h3 = hopOf3Steps

			Now we generated Take out 1step, them remaining is 3steps slice one 1step from total-count
			
			Solution is similar to Fib problem. In Fib recursion, building block is 0 and 1; and every other number is built out of 0 and 1. So the base condition for 
			recursion are 0 and 1.
			Similarly for this problem, building block is 1. So the base condition for recursions are 1, 2 and 3. 
			Also treat Number of Stairs as number as Fib length. To get total number of Hops we to add all of the Fib lengths.

			StairsLen '2' Total Hopcount '2'
			StairsLen '3' Total Hopcount '4'
			StairsLen '4' Total Hopcount '8'
			StairsLen '5' Total Hopcount '15'
			StairsLen '6' Total Hopcount '28'

			StairsLen '2' Total Paths '2'
			StairsLen '3' Total Paths '4'
			StairsLen '4' Total Paths '7'
			StairsLen '5' Total Paths '13'
			StairsLen '6' Total Paths '24'


	*/
	const int SIZEX = 50;
	class ChildHoppingDP
	{
	public:





		
		void callChildHoppingDP()
		{

			int StairsLen = 0;
			int hopsCount = 0;
			int pathssCount = 0;
			int histicalHopCount[SIZEX] = { -1 };
			int histicalPathCount[SIZEX] = { -1 };

			StairsLen = 2;
			hopsCount = NumberOFHopsDP(StairsLen, histicalHopCount);
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;


			StairsLen = 3;
			hopsCount = NumberOFHopsDP(StairsLen, histicalHopCount);
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;

			StairsLen = 4;
			hopsCount = NumberOFHopsDP(StairsLen, histicalHopCount);
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;

			StairsLen = 5;
			hopsCount = NumberOFHopsDP(StairsLen, histicalHopCount);
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;


			StairsLen = 6;
			hopsCount = NumberOFHopsDP(StairsLen, histicalHopCount);
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;


			StairsLen = 2;
			pathssCount = NumberOFPathsDP(StairsLen, histicalPathCount);
			cout << "StairsLen '" << StairsLen << "' Total Paths '" << pathssCount << "'" << endl << endl;


			StairsLen = 3;
			pathssCount = NumberOFPathsDP(StairsLen, histicalPathCount);
			cout << "StairsLen '" << StairsLen << "' Total Paths '" << pathssCount << "'" << endl << endl;

			StairsLen = 4;
			pathssCount = NumberOFPathsDP(StairsLen, histicalPathCount);
			cout << "StairsLen '" << StairsLen << "' Total Paths '" << pathssCount << "'" << endl << endl;

			StairsLen = 5;
			pathssCount = NumberOFPathsDP(StairsLen, histicalPathCount);
			cout << "StairsLen '" << StairsLen << "' Total Paths '" << pathssCount << "'" << endl << endl;


			StairsLen = 6;
			pathssCount = NumberOFPathsDP(StairsLen, histicalPathCount);
			cout << "StairsLen '" << StairsLen << "' Total Paths '" << pathssCount << "'" << endl << endl;

		}



		int NumberOFHopsDP(int stepsToGo, int histicalHopCount[SIZEX])
		{

			if (stepsToGo < 1) //No more steps to travel, do not make recursion call
				return 0;

			//If data is in HISTRORY[] return, no need to make recursion call
			if (histicalHopCount[stepsToGo] > 0)
				return histicalHopCount[stepsToGo];

			//If the data is not in HISTRORY[], then compute it by making recursion call
			//remaining steps can be completed in terms of either 1 or 2 or 3 steps.
			//so we make three recursion functions
			int x = NumberOFHopsDP(stepsToGo - 1, histicalHopCount);
			int y = NumberOFHopsDP(stepsToGo - 2, histicalHopCount);
			int z = NumberOFHopsDP(stepsToGo - 3, histicalHopCount);

			//Sumup return values
			//+1 is to account for current HOP
			//Store the result in a HISTORY[] for future use
			histicalHopCount[stepsToGo] = 1 + x + y + z;

			return histicalHopCount[stepsToGo];
		}

		int NumberOFPathsDP(int stepsToGo, int histicalHopCount[SIZEX])
		{
			if (stepsToGo < 0) //No more steps to travel, do not make recursion call
				return 0;

			if (stepsToGo == 0) //Path has come to end, return 1 because we are counting paths.
				return 1;

			//If data is in HISTRORY[] return, no need to make recursion call
			if (histicalHopCount[stepsToGo] > 0)
				return histicalHopCount[stepsToGo];

			//If the data is not in HISTRORY[], then compute it by making recursion call
			//remaining steps can be completed in terms of either 1 or 2 or 3 steps.
			//so we have three recursion functions
			int x = NumberOFPathsDP(stepsToGo - 1, histicalHopCount);
			int y = NumberOFPathsDP(stepsToGo - 2, histicalHopCount);
			int z = NumberOFPathsDP(stepsToGo - 3, histicalHopCount);

			//Sumup return values
			//Store the result in a HISTORY[] for future use
			histicalHopCount[stepsToGo] = x + y + z;
			return histicalHopCount[stepsToGo];
		}
	};
};