
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
namespace FindPeakElementNM
{
	/*
		Find the Peak elemnt in Sorted Array using DAC_20170714006 
			Arrat will be in sorted order except around the peak element.
			Peak Element is an element who’s left and right neighbours are lower than middle element. Eg “4 10 6”
			Code looks like binary search code. Compute the mid value.
			If src[m] is higher than [m-1] and [m+1], then we have found the peak value, return.
			Other possibilities are [m-1] is NOT less than [m]; [m+1] is NOT less than [m].

			If [m-1] is not less [m], then probbaly [m] is too high to be peak value, so we need to 
			explore the side where still lower values are further lower, so we explore left-half.

			If [m+1] is not less [m], then explore right-half.

			If conditions should be aware of boundary conditiom.
			If cursor is at [0], then there is no scope for [m-1], in that case just compare [m] and [m+1]
			If cursor is at [MAX], then there is no scope for [m+1], in that case just compare [m] and [m-1]
	*/
	const int SIZEX = 7;
	class FindPeakElement
	{

	public:
		void callFindPeakElement()
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