#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace BubbleSortNM
{
	//BubbleSort_20171227001
	//TBD-READ
	/* 	Bubble sort
			In case of bubble sort, higher values bubble up(means higher value move up). 
			1st iteration places the highest value at [Max], and next iteration places the 2nd highest element at [Max-1].
			Every iteration starts by comparing [0] & [1], and swaps if [0] is higher. Then compare [1] & [2], and swap if [1] is higher. 
			So every adjacent element gets compared against each other. But the length of comparison keeps on coming down.
			1st iteration goes from 0 to [MAX]; 2nd iteration goes until 0 to [Max-1];
			3rd iteration goes until 0 to [Max-2]
			
			
			
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
				//
				for (int j = 1; j < srcLen - i; j++)
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
