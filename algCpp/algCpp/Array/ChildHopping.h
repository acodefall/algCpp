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

namespace ChildHoppingNM //@RED20170722008
{
	/*
		Child hopping stairs.
			Child could climb the staircase by hopping 1-step OR 2-steps OR 3-steps at a time. 
			Our task is to count-> "Hops required when climbing 1 step at a time" +  "Hops required when climbing 2 steps at a time" + 
			Logic is as follows. Say stair case has 4 steps. Out of 4 steps, remove 1step, 2step and 3steps, as if you are 
			taking 1,2,3 steps. This leaves 3steps, 2steps and 1steps. 
			
			4= 
				h1(3) 
						h1(2)
								h1(1)
								h2(0)


						h2(1)	
								h1(0)


						h3(0)
								
					
				h2(2) 
						h1(1)
								h1(0)


						h2(0)

					
				h3(1)		
						h1(0)
						


			Now we generated Take out 1step, them remaining is 3steps slice one 1step from total-count
			
			Solution is similar to Fib problem. In Fib recursion, building block is 0 and 1; and every other number is built out of 0 and 1. So the base condition for 
			recursion are 0 and 1.
			Similarly for this problem, building block is 1. So the base condition for recursions are 1, 2 and 3. 
			Also treat Number of Stairs as number as Fib length. To get total number of Hops we to add all of the Fib lengths.

			StairsLen '2
				Hops for '2' steps is '1'
				Hops for '1' steps is '1'
				StairsLen '2' Total Hopcount '2'

			StairsLen '3
				Hops for '3' steps is '2'
				Hops for '2' steps is '1'
				Hops for '1' steps is '1'
				StairsLen '3' Total Hopcount '4'

			StairsLen '6
				Hops for '6' steps is '13'
				Hops for '5' steps is '7'
				Hops for '4' steps is '4'
				Hops for '3' steps is '2'
				Hops for '2' steps is '1'
				Hops for '1' steps is '1'
				StairsLen '6' Total Hopcount '28'

			StairsLen '4
				Hops for '4' steps is '4'
				Hops for '3' steps is '2'
				Hops for '2' steps is '1'
				Hops for '1' steps is '1'
				StairsLen '4' Total Hopcount '8'

	*/
	class ChildHopping
	{
	public:
		/*
		StepsInStaircase / Hops
		6 = 28
		4 = 8
		3 = 4
		2 = 2
		*/
		
		void callChildHopping()
		{
			int StairsLen = 2;
			int hopsCount = 0;
			
		
			StairsLen = 2;
			hopsCount = 0;
			cout << " StairsLen '" << StairsLen << endl;
			
			//for (int i = StairsLen; i > 0; i--)
			{
				int ret = ChildHoppingX(StairsLen);
				hopsCount += ret;
				cout << " Hops for '" << StairsLen << "' steps is '" << ret << "'" << endl;
			}
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;


			StairsLen = 3;
			hopsCount = 0;
			cout << " StairsLen '" << StairsLen << endl;
			//for (int i = StairsLen; i > 0; i--)
			{
				int ret = ChildHoppingX(StairsLen);
				hopsCount += ret;
				cout << " Hops for '" << StairsLen << "' steps is '" << ret << "'" << endl;
			}
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;

			StairsLen = 6;
			hopsCount = 0;
			cout << " StairsLen '" << StairsLen << endl;
			//for (int i = StairsLen; i > 0; i--)
			{
				int ret = ChildHoppingX(StairsLen);
				hopsCount += ret;
				cout << " Hops for '" << StairsLen << "' steps is '" << ret << "'" << endl;
			}
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;

			StairsLen = 4;
			hopsCount = 0;
			cout << " StairsLen '" << StairsLen << endl;
			//for (int i = StairsLen; i > 0; i--)
			{
				int ret = ChildHoppingX(StairsLen);
				hopsCount += ret;
				cout << " Hops for '" << StairsLen << "' steps is '" << ret << "'" << endl;
			}
			cout << "StairsLen '" << StairsLen << "' Total Hopcount '" << hopsCount << "'" << endl << endl;

		
		}

		//
		int ChildHoppingX(int stairsCount)
		{
			//cout << "Stairs remaining: " << stairsCount << endl;
		
			if (stairsCount < 1)
				return 0;
			//If the input value is higher than 1, then we we make two more recursion calls and add their return values and send it to caller.
			int hopCount1 = ChildHoppingX(stairsCount - 1);
			//cout << "hopCount1 :" << hopCount1 << endl;

			int hopCount2 = ChildHoppingX(stairsCount - 2);
			//cout << "hopCount2 :" << hopCount2 << endl;

			int hopCount3 = ChildHoppingX(stairsCount - 3);
			//cout << "hopCount3 :" << hopCount3 << endl;

			return  hopCount1 + hopCount2 + hopCount3 + 1;
		}


		//
		int ChildHoppingX2(int stairsCountRemaining)
		{
			//base condition returns 1 for all these because 
			if (stairsCountRemaining == 1)
				return 1;	//when 1 steps is remaining, it can be covered using single hop so return 1-hop
			if (stairsCountRemaining == 2)
				return 1;	//when 2 steps are remaining, it can be covered using single hop so return 1-hop
			if (stairsCountRemaining == 3)
				return 1;	//when 3 steps are remaining, it can be covered using single hop so return 1-hop

			//when you have more than 3 steps remaining
			return  ChildHoppingX2(stairsCountRemaining - 1) +	//compute how many hops of one-step require to cover remaining
					ChildHoppingX2(stairsCountRemaining - 2) +	//compute how many hops of two-steps require to cover remaining
					ChildHoppingX2(stairsCountRemaining - 3)    //compute how many hops of three-steps require to cover remaining
					+ 1;			//Add one for current hop
			
		}
	};
};