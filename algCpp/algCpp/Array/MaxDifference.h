#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
namespace MaxDifferenceNM //@RED20170725050
{
	/*
	
		 Price variation of a stock is given in a array, and we should tell selling on which day gives maximum yield.
        [0], [1], [2] have 1st day, 2nd day and 3rd day price. We can not buy and sell on same day.
        For example: Diff "3rd day price with 2nd day", then "3rd day price with 1st day", then select the difference that is higher.
        Solution is: take src[i] and diff it against the elements that are on right-side. Then track the max difference, and use that as final result.
	
	*/
	const int SIZEX = 5;
	class MaxDifference
	{

		public:
				void callMaxDifference()
				{
					int src[SIZEX] = { 10,  11,   7,   10,  6 };
					MaxDifferenceX(src);
					MaxDifferenceLoop(src);
				}
				void MaxDifferenceX(int src[SIZEX])
				{
					int MinValue = src[0];
					int MaxDiff = 0;

					//first compute the "MaxDiff" and then select "MinValue"
					for (int i = 1; i < SIZEX; i++)
					{
						MaxDiff = max(MaxDiff, src[i] - MinValue);
						MinValue = min(MinValue, src[i]);
					}
					cout << "MaxDiff is " << MaxDiff << endl;
				}

				void MaxDifferenceLoop(int src[SIZEX])
				{
					int MaxDiff = INT_MIN;
					for (int i = 0; i < SIZEX; i++)
					{
						for (int j = i+1; j < SIZEX; j++)
						{
							cout << MaxDiff << endl;
							cout << "[" << i << "]" << " - " << "[" << j << "] = " << src[i] << " - " << src[j] << " = " << src[i] - src[j] << endl;
							if ((src[i] - src[j]) > MaxDiff)
							{
								MaxDiff = src[i] - src[j];
							}
							cout << MaxDiff << endl << endl;
						}
					}
					cout << "MaxDiff is "<< MaxDiff << endl;
				}
	};

};
