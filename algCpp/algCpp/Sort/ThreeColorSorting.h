#pragma once
#include <iostream>
#include "PartitionArray.h"
using namespace std;
namespace ThreewaysortingNM
{
	/*
		ThreeWaySortng_20170528001
			Threeway sorting sorts the array that has nothing but several 1s, 2s and 3s.
					{ 1, 3, 1, 1, 3, 2, 1, 2, 3, 1, 2, 3 };
			Main algorithm used here is the selection-method that is used in Quick sort for grouping data on either side of anchor value. Selection-method is called twice, with anchor as 1 and 2. When the anchor is 1, selection-method brings all the 1s to left. 
					//output: 1 1 1 1 1 2 3 2 3 3 2 3
			When the anchor is 2, selection-method brings all the 2s to the RIGHT of 1s.  First call returns the index of right most 1, and we use that to adjust the index and lenght for 2nd call.
					//output: 1 1 1 1 1 2 2 2 3 3 3 3
			This also known as Dutch Flag Problem.

Steps for ThreeWaySortng_20170528002
			Outer method calls SelectionSort() twice. Params are as follows
			SelectionSort(src-data, startIndex, len, anchor);//	Anchor is 1.
			SelectionSort(src-data, startIndex + retCodeOf1stCall, len - retCodeOf1stCall, anchor); //Anchor is 2.
			Implementation of Selection-Method.
			Function scans the array from opposite directions, so initialize fIndex and rIndex to min and max index of src-array
			Goal is to bring all anchor-values(that values equal to anchor value) to left side of the array.
			So the while-loop scanning from left-end, skips the element that anchor-value and breaks the loop when it encounters non-anchor-value. Conversly an another while-loop coming from Right-end, skips if the value is non-anchor-value, but breaks the loop if it encounters anchor-value on right side. 
		Once both the loops break, if (fIndex < rIndex), we have found values that are on WRONG side, and we exchange them, and increment fIndex and decrement rIndex.
		After finding one misfit, we look for 2nd mis-fit element. This exploration continues as long as (fIndex < rIndex).

		We achieve this we have one outer loop, and this wraps two while-loops, and a IF() condition for executing SWAP.
		1st inner-while loop goes from L-R, and increments fIndex, and breaks on non-anchor-value.
		2nd inner-while loop goes from R-L, and decrements rIndex, and breaks on anchor-value. 

	
	*/
	//@20170528001
	class ThreewaySorting
	{
		public:
			void CallThreewaySorting()
			{
				int data[12] = { 1, 3, 1, 1, 3, 2, 1, 2, 3, 1, 2, 3 };
				int anchor = 0;
				int len = 12;
				
				//place "2 and above" on the right-side
				anchor = 2;
				PartitionArrayNM::PartitionArray objPartitionArray;
				int ret = objPartitionArray.PartitionInTo2Parts(data,0,len-1,2);
				//output: 1 1 1 1 1 2 3 2 3 3 2 3 ret = 5

				//place "3 and above" on the right-side
				anchor = 3;
				objPartitionArray.PartitionInTo2Parts(data+ret, 0, len-ret-1, anchor);
				//output: 1 1 1 1 1 2 2 2 3 3 3 3
			}

			/*int SelectionSort(int* data, int start, int len, int anchor)
			{
				int r = len - 1;
				int f = start;


				while ((f < r) && (f < len) && (r >= start))
				{
					while ((data[f] == anchor))
					{
						f++;
					}

					while ((data[r] != anchor))
					{
						r--;
					}

					if (f < r)
					{
						int tmp = data[f];
						data[f] = data[r];
						data[r] = tmp;
						f++;
						r--;
					}

				}

				std::cout << "\r\n";
				for (int i = 0; i < len; i++)
				{
					std::cout << data[i] << " ";
				}
				std::cout << "\r\n";
				return f;
			}*/
	};
};

