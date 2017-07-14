
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
namespace IntersectionOfSortedArrayNM
{
	/*
	
	
	*/
	const int SIZEX1 = 7;
	const int SIZEX2 = 6;
	class IntersectionOfSortedArray
	{

	public:
		void callIntersectionOfSortedArray()
		{

			int src1[SIZEX1] = { 10, 22, 33, 50, 41, 60, 80 };
			int src2[SIZEX2] = { 5, 12, 15, 33, 62, 80 };

			cout << "src1[]" << endl;
			for (int i = 0; i < SIZEX1; i++)
				cout << src1[i] << " ";

			cout <<  endl;

			cout << "src2[]" << endl;
			for (int i = 0; i < SIZEX2; i++)
				cout << src2[i] << " ";

			cout << endl;

			FindIndexOfIntersection(src1, src2);
		}


		void FindIndexOfIntersection(int src1[SIZEX1], int src2[SIZEX2])
		{
			
			int i1 = 0;
			int i2 = 0;

			while ((i1 < SIZEX1) && (i2 < SIZEX2))
			{
				if (src1[i1] < src2[i2])
				{
					i1++;
				}
				else if (src2[i2] < src1[i1])
				{
					i2++;
				}
				else
				{
					cout << "Two array intersect at src1[" << i1 << "] and src2[" << i2 << "] " << src1[i1] << " " << src2[i2] << endl;
					break;
				}
			}
		}
	};
};