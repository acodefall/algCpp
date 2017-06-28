#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace CountingSortNM
{
	
	//CountingeSort_20170623012
	class CountingSort
	{
	public:
		void CallCountingSort()
		{
			CountingSortX();
		}
		void CountingSortX()
		{
			cout << "\r\n CountingSort \r\n";
			int src[] = { 25, 10, 7, 3, 2, 4, 8, 10 };
			int srcLen = 8;
			//take one element from src[], and compare with the elements that are on the LEFT of it. 
			//We go from Right-to-Left, and stop as soon as come across anything is Less than that swap
			int occurenceArray[UCHAR_MAX] = { 0 };
			int sortedOuputArray[UCHAR_MAX] = { 0 };

			int occurLen = 0;
			for (int i = 0; i < srcLen; i++)
			{
				occurenceArray[src[i]]++;
				occurLen = max(occurLen, src[i]);
			}

			int sortIndex = 0;
			for (int i = 0; i <= occurLen; i++)
			{
				int count = occurenceArray[i];
				while (count > 0)
				{
					sortedOuputArray[sortIndex] = i;

					count--;
					sortIndex++;
				}
			}
			cout << "\r\n \r\n";
			for (int i = 0; i < sortIndex; i++)
			{
				cout << sortedOuputArray[i] << " ";
			}

			cout << "\r\n \r\n";
		}
	};
};

