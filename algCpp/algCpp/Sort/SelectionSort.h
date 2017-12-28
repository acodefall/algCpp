#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace SelectionNM
{
	/*
		Selection sort
			Go from L -> R looking for lowest number. 
			Initially 4 could be the lowest number so make it the lowest number( as of now).
			Then proceed to right-side, and compare every element against 4. Assume you find 2.
			Since the 2 is less than 4, make 2 as the lowest number.
			Then proceed to right-side, and compare every element against 2. 
			Assume you reached the end of the array. 
			Now you have found the LOWEST number in array, store it at [0] by swapping.

			Our next effort should be to find the 2nd lowest number and place it is at [1].
			Assume the number that is currently at [1] as lowest number.

			So second round begins from [1] and goes on finding the lowest number.
			Once the lowest number is found, place it at [1]. 
			Then proceed to right-side, and go on comparing.

			Repeat this for all the elements of array.

			Summary: 
				Scan from [0] to [Max] looking for 1st lowest number; once found place is it at [0].
				Scan from [1] to [Max] looking for 2nd lowest number; once found place is it at [1].
				Scan from [2] to [Max] looking for 3rd lowest number; once found place is it at [3].
	*/
	//SelectionSort_20171227002
	//TBD-READ
	class SelectionSort
	{
	public:
		void CallSelectionSort()
		{
			SelectionSortx();
		}
		void SelectionSortx()
		{
			cout << "\r\n SelectionSort \r\n";
			int src[] = { 25, 10, 7, 3, 2, 4, 8, 10 };
			int srcLen = 8;
			for (int i = 0; i < srcLen; i++)
			{
				cout << src[i] << " ";
			}

			for (int i = 0; i < srcLen; i++)
			{
				//this loop finds the LOWEST value
				int minIndex = i;
				for (int j = i + 1; j < srcLen; j++)
				{
					if (src[j] < src[minIndex])
					{
						minIndex = j;
					}
				}

				//Now minIndex will have the index where LOWEST value is stored.
				//swap
				int tmp = src[minIndex];
				src[minIndex] = src[i];
				src[i] = tmp;
			}


			cout << "\r\n \r\n";
			for (int i = 0; i < srcLen; i++)
			{
				cout << src[i] << " ";
			}

			cout << "\r\n \r\n";
		}


	};
};
#pragma once
