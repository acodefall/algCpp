#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace BubbleSortNM
{
	//BubbleSort_20171227001
	//TBD-READ
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
