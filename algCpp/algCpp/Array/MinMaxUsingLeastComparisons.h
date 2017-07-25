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

namespace MinMaxUsingLeastComparisonsNM //@RED20170722006
{
	/*	
	Find Min,Max using least Comparisons
	There are two methods.
	Method1: Maintain Global variables GblMax and GblMin
		Iterate the src-arry, by incrementing one element at a time, and comapre every element against GblMax and GblMin.
		And update them appropriately.

	Method2:
		Find Min,Max using least Comparisons_20170722006
			Compare first two adjacent elements, and note down the max and min among them.
			Now we know the min and max for first two elemens, and these TWO items can be taken out of equation.
			Advance the cursor by two elements. 
			Next compare 3rd and 4th element against each other, and pick min and max among those two, and compare these 
			against the already known Min and Max.
			Now we know Min and Max for first 4 items so remove them from equation, by moving the cursor to 5th position
			This reduces the number of comparisons, takes 1/3 less number of comparisons



		If the src is ODD is length, ForLoop would have left the last element of the src-array unattended.
		After exiting the for-loop, compare the left over src-element against GblMax and GblMin

		
	*/

	const int SIZEX = 14;
	class MinMaxUsingLeastComparisons
	{
	public:

		void callMinMaxUsingLeastComparisons()
		{
			int src[SIZEX] = { 1000, 11, 445, 1, 330, 3000, 67, 6,34, 61, 9, 3, 61,8 };

			singleComps(src); //16 comps
			//pairedComps(src); //13 comps
			pairedCompsX(src); //13 comps
		}

		void singleComps(int src[SIZEX])
		{
			int gblMax = INT_MIN;
			int gblMin = INT_MAX;
			int i = 0;
			int comps = 0;
			for (i = 0; i < SIZEX; i++)
			{
				//When the currItem is higher than gblMax, load currItem in to gblMax
				//When the currItem is lower than gblMin, load currItem in to gblMin
				if (src[i] >= gblMax)
					gblMax = src[i];
				else if (src[i] < gblMin)
				{
					comps++;
					gblMin = src[i];
				}
				comps++;
			}
			cout << endl << "Simple compare method takes '" << comps << "' compares. Min: '" << gblMin << "' Max: '" << gblMax << "'" << endl;
		}

		/*void pairedComps(int src[SIZEX])
		{
			int gblMax = INT_MIN;
			int gblMin = INT_MAX;
			int i = 0;
			int comps = 0;

			
			{4} test for EVEN
			<3(Len-1)
			0,1
			2,3
			4 ---> does not go through

			{5} test for ODD
			<4(Len-1)
			0,1
			2,3
			4 ---> does not go through
			*//*
			//Compare two adjacent elements, and note down the max and min.
			//Now we know the min and max for first two elemens, and these TWO items can be taken out of equation.
			//So move the cursor by two position.
			//Next compare 3rd and 4th element against each other, and then compare the result of that compare against the already known Min and Max.
			//Now we know Min and Max for 4 items, and we remove them from equation, and move the cursor by 2 more positions.
			for (i = 0; i < SIZEX - 1; i = i + 2)
			{
				if (src[i] >= src[i + 1]) //compare the two neighbours. 
				{
					comps++;
					if (src[i] > gblMax)
					{
						comps++;
						gblMax = src[i];
					}
					if (src[i + 1] < gblMin)
					{
						comps++;
						gblMin = src[i + 1];
					}
				}
				else if (src[i] < src[i + 1]) //compare the two neighbours
				{
					comps = comps + 2;
					if (src[i + 1] > gblMax)
					{
						comps++;
						gblMax = src[i + 1];
					}
					if (src[i] < gblMin)
					{
						comps++;
						gblMin = src[i];
					}
				}
			}

			if (SIZEX % 2 > 0)
			{
				if (src[SIZEX - 1] > gblMax)
				{
					gblMax = src[SIZEX - 1];
					comps++;
				}
				if (src[SIZEX - 1] < gblMin)
				{
					gblMin = src[SIZEX - 1];
					comps++;
				}
			}

			cout << endl << "Double compare method takes '" << comps << "' compares. Min: '" << gblMin << "' Max: '" << gblMax << "'" << endl;
		}*/

		void pairedCompsX(int src[SIZEX])
		{
			int gblMax = INT_MIN;
			int gblMin = INT_MAX;
			int i = 0;
			int comps = 0;

			//Compare two adjacent elements, and note down the max and min.
			//Now we know the min and max for first two elemens, and these TWO items can be taken out of equation.
			//So move the cursor by two positions.
			//Next compare 3rd and 4th element against each other, and pick min and max among those two.
			//then compare them against the already known Min and Max.
			//Now we know Min and Max for 4 items, and we remove them from equation, and move the cursor by 2 more positions.
			//this reduces the number of comparisons
			for (i = 0; i < SIZEX - 1; i = i + 2)
			{
				int mx = 0;
				int mn = 0;
				if (src[i] >= src[i + 1]) //compare the two neighbours. 
				{
					comps++;
					mx = src[i];
					mn = src[i + 1];
				}
				else if (src[i] < src[i + 1]) //compare the two neighbours
				{
					comps += 2;
					mx = src[i + 1];
					mn = src[i];
				}

				if (gblMax < mx)
				{
					comps++;
					gblMax = mx;
				}

				if (gblMin > mn)
				{
					comps++;
					gblMin = mn;
				}
			}
			
			//Previous For Loop uses "(i < SIZEX - 1)". If the array-length is ODD, then For Loop
			//would have left one item unattended and we have to process that.
			if (i < SIZEX) //There is one more item 
			{
				if (src[SIZEX - 1] > gblMax)
				{
					gblMax = src[SIZEX - 1];
					comps++;
				}
				if (src[SIZEX - 1] < gblMin)
				{
					gblMin = src[SIZEX - 1];
					comps++;
				}
			}

			cout << endl << "Double compare method takes '" << comps << "' compares. Min: '" << gblMin << "' Max: '" << gblMax << "'" << endl;
		}
	};
};
