#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace BubbleSortNM
{
	//BubbleSort_20171227001
	//TBD-READ
	/* 	Bubble sort
			In case of bubble sort, higher values bubble up(means higher value move up). Place the highest value at [Max], and place the next highest element at [Max-1].

			How do you find the highest element?
			Compare [0] & [1]; if [0] is higher then swap. Next compare [1] & [2]; if [1] is higher then swap. Repeat this until the end of the array is reached. This will bubble up highest value to [Max].
			In the 2nd iteration, do the same set comparisons. This will bubble up 2nd highest value to [Max-1].
			
		Bubble sort and Selection sort
			1)
				Bubble sort compares the adjacent elements, if the LEFT > RIGHT. and they get swapped. Number of swaps = number of elements.

				Selection sort compares the  adjacent elements, if the LEFT > RIGHT. and index of higher value will be NOTED(no swapping at this point). 
				Swapping will happen only when cursor reaches the end of the array.

			 2)
				 Bubble sort bubbles higher number to higher index
				 Selection sort pushes lower number to lower index
	*/
		
	class BubbleSort
	{
	public:
		void CallBubbleSort()
		{
			BubbleSortx();
		}
		void BubbleSortx()
		{
			cout << "\r\n BubbleSort \r\n";
			int src[] = { 25, 10, 7, 3, 2, 4, 8, 10 };
			int srcLen = 8;
			for (int i = 0; i < srcLen; i++)
			{
				cout << src[i] << " ";
			}

			for (int i = 0; i < srcLen; i++)
			{
				for (int j = 1; j < srcLen; j++)
				{
					if (src[j-1] > src[j])
					{
						//swap
						int tmp = src[j - 1];
						src[j - 1] = src[j];
						src[j] = tmp;
					}
				}
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
