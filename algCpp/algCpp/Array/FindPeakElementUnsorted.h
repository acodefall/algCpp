
#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
namespace FindPeakElementUnsortedNM
{
	/*
		Find the Peak elemnt in Unsorted Array using DAC. 
			Peak Element is made up Left-crest and Right-crest, that is [i-1], [i], [i+1].
			DAC code returns success if both Left-crest and Right-crest are present;
			DAC makes left-turn if the condition for Left-crest fails. This is because left-crest should be in left half.
			DAC nakes right-turn if the condition for Right-crest fails. This is because right-crest should be in right half. 
			If none of above conditions are met, then DAC return -1.

		Steps to find Peak element using DAC
			a) F
	*/
	const int SIZEX = 7;
	class FindPeakElementUnsorted
	{

	public:
		void callFindPeakElementUnsorted()
		{

			int src[SIZEX] = { 1,      5,      17,       9,       13,          56,       67 };

			int pk = FindPeakElementX(src,0, SIZEX -1); //5 17 9
		}

		// In findpeak peak. check have we found lower-crest 
		int FindPeakElementX(int src[SIZEX], int L, int H)
		{
			
			int m = L + (H - L) / 2;

			//Got the peak-value (This has both left-crest and right-crest)
			if (
				((m == 0) || ((m > 0) && (src[m] > src[m - 1]))) //check for lower-crest OR left-end
					&&
				((m == SIZEX - 1) || ((m + 1 < SIZE)  && (src[m] > src[m + 1]))) //check for upper-crest OR high-end
				)
			{ 
				cout << "found peak value { src[" << m-1 << "] src[" << m << "] src [" << m+1 << "]} = " << src[m - 1] << " " << src[m] << " " << src[m + 1] << endl;
				return m;
			}
			else if ((m > 0) && (src[m] < src[m - 1])) //Left-crest is broken, and look for good left-crest on left-half of array
			{
				return FindPeakElementX(src, L, m-1);
			}
			else if ((m + 1 < SIZE) && (src[m] < src[m + 1])) //Right-crest is broken, and look for good Right-crest on right-half  of array
			{
				return FindPeakElementX(src, m + 1, H);
			}
			else //This does not have proper right-crest OR left-crest OR both
				return -1;
		}
	};
};