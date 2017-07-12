#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace FindNumberHigherThanKSortedNM
{
	/*
		Find number that is higher than K in Sorted array. You can get this by using Binary search

	*/
	const int SIZEX = 9;
	class FindNumberHigherThanKSorted
	{
	public:
		void callFindNumberHigherThanK()
		{
			int src[SIZEX] = { 2, 5, 7, 9, 23, 56, 789, 6666, 590003 };
			int out = FindNumberHigherThanKX(src,789);
			
		}

	private:
		int FindNumberHigherThanKX(int src[SIZEX], int V)
		{
			int l = 0;
			int h = SIZEX - 1;

			while (l <= h)
			{
				int mid = l + (h - l) / 2;

				if (src[mid] > V)// v  []
				{
					return mid;
				}
				else  // [] v
				{
					l = mid + 1;
				}
			}
		}
	};
};