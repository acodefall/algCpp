#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace InsertionSortNM
{
	//InsertioneSort_20170623011
	class InsertionSort
	{
	public:
			void CallInsertionSort()
			{
				insertionSort();
			}
			void insertionSort()
			{
				cout << "\r\n InsertionSort \r\n";
				int src[] = { 25, 10, 7, 3, 2, 4, 8, 10 };
				int srcLen = 8;
				for (int i = 0; i < srcLen; i++)
				{
					cout << src[i] << " ";
				}

				//take one element from src[], and compare with the elements that are on the LEFT of it. 
				//We go from Right-to-Left, and stop as soon as come across anything is Less than that swap
				for (int i = 1; i < srcLen; i++)
				{
					int ItemToInsert = src[i];

					int j = i;
					while ((j > 0) && ItemToInsert < src[j - 1])
					{
						src[j] = src[j - 1];
						j--;
					}

					if (j != i)
					{
						src[j] = ItemToInsert;

						/*cout << "\r\n";
						for (int k = 0; k < srcLen; k++)
						{
						cout << src[k] << " ";
						}
						cout << "\r\n";*/
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
