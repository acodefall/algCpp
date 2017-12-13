
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
			
			Peak Element is an element who’s left and right neighbours are lower than middle element. Eg “4 10 6”
			Peak element has left-crest and right-crest.
			We can find Peak element using binary search code. As usual start by computing the mid value.
			
			If src[m] is higher than both [m-1] and [m+1], then both left-crest and right-crest are present,
			and we have found the peak value, return.
			
			If [m-1] is less [m],  we have found only left-crest, and should look for right-crest, explore the right-half.
			If [m+1] is less [m],  we have found only right-crest, and should look for left-crest, explore the left-half.
			
			Check for boundary condition all the time. If (m = 0) check for only right-crest
			If (m = MAX) check for only left-crest
			
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
			else if ((m > 0) && (src[m-1] < src[m])) //Left-crest is good(means peak), check the right side peak is present or not
			{
				return FindPeakElementX(src, L, m-1);
			}
			else if ((m + 1 < SIZE) && (src[m+1] < src[m])) //Right-crest is good(means peak), check the left side for oother creast.
			{
				return FindPeakElementX(src, m + 1, H);
			}
			else //This does not have proper right-crest OR left-crest OR both
				return -1;
		}
	};
};