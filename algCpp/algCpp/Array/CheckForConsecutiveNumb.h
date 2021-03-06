#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_set>
using namespace std;
namespace CheckForConsecutiveNumbNM
{
	/*
		Confirm that array has consecutive integers_20170714010
			By observation we can say that the consecutive numbers are generated by adding 1. Eg: "2, 3, 4".
			So if we know MIN and MAX then there should be math formula that we can apply.
			To validate the consecutive numbers do this
			-Find the MAX and MIN. Do this because numbers may not be in sorted order.
			-Apply the math formula. If this formula fails, then Array is not consecutive.
				(src.Length == (Max - Min + 1))
			-Lastly make sure there are duplicate
			-If both length condition and duplicate conditions match then we can say that the src[] is consecutive
	*/
	const int SIZEX = 6;
	class CheckForConsecutiveNumb
	{
		public:
				void callCheckForConsecutiveNumber()
				{
					int src[SIZEX] = { 22, 24, 21, 26, 23, 25 };
					CheckForConsecutiveNumbX(src);
				}
				void CheckForConsecutiveNumbX(int src[SIZEX])
				{
					int mn = INT_MAX;
					int mx = INT_MIN;
					//find out the min and max
					for (int i = 0; i < SIZEX; i++)
					{
						mn = min(mn, src[i]);
						mx = max(mx, src[i]);
					}

					//check LEN against Mx-Min. If this fails quit
					if (SIZEX != mx - mn + 1)
					{
						cout << "Numbers are not consecutive. Length condition failed" << endl;
						return;
					}

					//make sure there are no DUPLICATES
					unordered_set<int> shset;
					for (int i = 0; i < SIZEX; i++)
					{
						if (shset.find(src[i]) == shset.end())
						{	//fresh item. Insert in to SET
							shset.insert({src[i]});
						}
						else
						{
							cout << "Numbers are not consecutive. Duplicate condition failed" << endl;
							break;
						}
					}
					
					cout << "Numbers are consecutive. Both Duplicate condition and Length condition passed" << endl;
				}
	};
};