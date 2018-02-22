#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace ShortestSubArrayThatAddsToXNM
{
	/*
	ShortestSubArrayThatAddsToX_@RED20180128008
	We are interested in SubArray or consecutive sequence that adds to X.
	Imagine a window that starts from 0 and goes until the SUM becomes X.
	Similaraly imagine another window that starts from 1 and goes until the SUM becomes X.
	There will be several windows likes this. We have to select the window that is shortest in length.

	Coming to implementation, initialize startIndex of window to  = 0, and increase the end index until sum
	becomes equal to X. If sum goes above > X, then substract value held by startIndex, and shrink wth windowLength by 1.
	If the sum becomes equal to X, then we have found ONE-window that adds to X. We have look for NEXT-window. 
		-Second windows starts RIGHT next the startIndex of 1st-window, 
			reset both startIndex & cursor(i) to "startIndex+1"
		-Reset resent WinLien.
	
	In the next round of while loop we will find the window that adds up to X.
	

	*/
	const int MX = 7;
	class ShortestSubArrayThatAddsToX
	{
		public:
			void callShortestSubArrayThatAddsToX()
			{
				int src[MX] = { 2, 3, 1, 2, 4, 3, 7 };
				ShortestSubArrayThatAddsToX1(src, 6);
			}

			void ShortestSubArrayThatAddsToX1(int src[MX], int sumX)
			{
				int st = 0;
				int ed = 0;
				int winLen = INT_MAX;
				int curSum = 0;
				int i = 0;
				while (true)
				{
					//delete any excess value from sum
					while (curSum > sumX)
					{
						curSum -= src[st];
						st++;
					}

					//if sum has reached the target value, we found ONE-window.
					//We have look for NEXT-window. Reset the "st" 
					if (curSum == sumX)
					{
						/*
						If the sum becomes equal to X, then we have found ONE - window that adds to X.We have look for NEXT - window.
							- Second windows starts RIGHT next the startIndex of 1st - window,
							reset both startIndex & cursor(i) to "startIndex+1"
							- Reset resent WinLien.*/

						winLen = min(i - st, winLen);
						if (i >= MX)
						{
							break;
						}

						st = st + 1; //reset
						i = st; //reset
						curSum = 0; //reset
					}
					else if (curSum < sumX)
					{
						if (i < MX)
						{
							curSum += src[i];
						}

						if (i >= MX)
						{
							break;
						}
						i++;
					}
				}
			}
	};
};