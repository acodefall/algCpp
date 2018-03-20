
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
			There are three conidtions:
			-M could be at peak, or left-slope or right-slope
			-left-slope means m-1 < M, in that case go right
			-right-slope means m-1 > M, in that case go left
		

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

			int pk = FindPeakElementX(src,0, SIZEX -1); //5 17 9  //array : 2 , 4, 2, 1, 5
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
			else if ((m > 0) && (src[m-1] < src[m]))  //left-slope so go right
			{
				
				return FindPeakElementX(src, m, H);
			}
			else if ((m + 1 < SIZE) && (src[m-1] > src[m]))  //right-slope so go left
			{
				return FindPeakElementX(src, L, m);
			}
			else //This does not have proper right-crest OR left-crest OR both
				return -1;
		}
	};
};