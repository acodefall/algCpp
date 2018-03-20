#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
namespace FindMinValueInRotatedArrayNM
{
	/*
		Find MIN element in Rotated array_RED20180129009
			int src[10] = { 4, 3, 2, 1, 10, 9, 8, 7,6,5 };
			Rotated array will have two downward slopes
			One starts at left-most end and other slope starts at the middle and goes until the end of array.
			There will be a upward slope at the point where both these slopes meet. MIN value will be in this slope. 
			So when searching for MIN value, look for upward slope.
			So there are 3 possibilities
	  			a) if([m] < [m+1]) //Update slope
					break;
				b) Left slope(L > M), go R beacuse upward slope will be on R
				c) Right slope(M > H), go L beacuse upward slope will be on R


	*/
	const int MX = 7;
	class FindMinValueInRotatedArrayX
	{
		public:
			void callFindMinValueInRotatedArray()
			{
				//int src[7] = { 4, 5, 6, 7, 1,2,3 };
				int src[10] = { 4, 3, 2, 1, 10, 9, 8, 7,6,5 };
				int c = find(src,0,9); //1
			}


			int find(int s[MX], int L, int H)
			{

				while (L <= H)
				{
					int M = (H - L + L) / 2;

					if (s[M] < s[M + 1])
					{
						return M + 1;
					}
					else if (s[L] > s[M] ) //we are in left-slope, go to right  
					{
						L = M + 1;
					}
					else if (s[M] > s[H]) //we are in right-slope, go to left
					{
						H = M - 1;
					}
				}
			}
	};

};