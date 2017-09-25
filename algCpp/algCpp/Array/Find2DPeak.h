
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
namespace Find2DPeakNM //@RED20170909017
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
	const int SIZEX = 4;
	class Find2DPeak
	{

	public:
		void callFindPeakElement()
		{
			int src[SIZEX][SIZEX] =
			{
				{ 10, 8, 10, 10 },
				{ 14, 13, 12, 11 },
				{ 15, 9, 21, 11 },
				{ 16, 17, 19, 20 }
			};
			FindPeakElementX(src); //5 17 9
		}

		// In findpeak peak. check have we found lower-crest 
		void FindPeakElementX(int src[SIZEX][SIZEX])
		{
			
			for (int r = 0; r < SIZEX; r++)
			{
				//Left and Right neighbors of X constitute Peak Element
				int x = FindPeakElementInArray(src[r],0, SIZEX-1);

				if (x != -1)
				{
					//check if Top and Bottom neighbors of X also constitute Peak Element
					if ((r > 0) && (r + 1 < SIZEX) && (src[r][x] > src[r + 1][x])
						&&
						(src[r][x] > src[r - 1][x]))
					{
						cout << "peak cordinates are " << r << " " << x << endl;
						break;
					}
				}

			}
		}

		//This returns the INDEX, not value
		int FindPeakElementInArray(int* src, int L, int H)
		{
			int m = L + (H - L) / 2;
			//check for success fully finding "PEAK ITEM"
			if (((m == 0) || (src[m] > src[m - 1]))
				&&
				((m == SIZEX - 1) || (src[m] > src[m + 1]))
				)
			{
				cout << "found peak value { src[" << m - 1 << "] src[" << m << "] src [" << m + 1 << "]} = " << src[m - 1] << " " << src[m] << " " << src[m + 1] << endl;
				return m;
			}
			else if ((m > 0) && (src[m] < src[m - 1])) //check for broken Left-Crest 
			{
				return FindPeakElementInArray(src, L, m - 1); // look for proper Left-crest in left half
			}
			else if ((m + 1 < SIZEX) && (src[m] < src[m + 1])) //check for broken Right-Crest 
			{
				return FindPeakElementInArray(src, m + 1, H); // look for proper Right-crest in Right half
			}
			else
				return -1;
		}
	};
};