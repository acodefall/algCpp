
#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <unordered_set>
using namespace std;
namespace KthItemInSortedAryUsingIntersectionNM //@RED20170919005 @RED20170919007
{
	/*
		Find Kth item among 2 Sorted arrays_RED20170919005
			Since the arrays are already sorted we can find Kth item among those two arrays using INTERSECTION method. INTERSECTION method iterates the arrays ONLY until K items are crossed.
			If K = 4, stop after merging 4 items.
			This takes O(K) time.  Thiis can also be solved by using MERGING sorted arrays as we do in MERGE sort but that needs extra array.

		Intersection Method Understanding_RED20170919007
			Intersection method will have two SORTED arrays but only one cursor. This cursor has to jump back and forth between so that the values are ASCENDING(or the path being traced is ascending). At every stage cursor has two paths or two "next-values": one from 1st array and other 2ns array.  Cursor should pickup the value that is LOWER AMONG them, and then INCREMENT the index of the THAT array only. Other arrays index same where ever it was. In the next loop, we again compare two next values as we did before. So in a loop, we increment the index of the array who's curr-value is LOWER.
			If the curr-values of both arrays is same then increment the index of both the arrays.

			//WHen src arrays are ASCENDING
			if(s1 < s2)
				s1++;
			else if(s2 < s1)
				s2++;
			else
				s1++ s2++;

			If the src-arrays are in DESCENDING order, the pickup the HIGHER among the two values, 
			because path being traced should be HIGH to LOW

			Coming to implementation, intersection method iterates both arrays in same while loop, using distinct indexes.
			Every loop will increment the index of the array who's value is LOWER.
			If Index of Src1 is lower then increment the index of only Src1.
			If the values both Src1 and Src2 are equal, then increment both the indexes.
			Index pointing to low value is incremented because array is assumed to in ascending order.

					void FindKthItemUsingIntersection(int src1, int src2, int K)
					{
						while ((i1 < SIZEX1) && (i2 < SIZEX2))
						{
							if (src1[i1] < src2[i2])
							{
								Value = src1[i1];
								i1++;
							}
							else if (src2[i2] < src1[i1])
							{
								Value = src2[i2];
								i2++;
							}
							else
							{
								Value = src2[i2];
								i2++;
								i1++;
							}
							K--;
							if (K == 0)
							{
								break;
							}
						}
					}


	*/
	const int SIZEX1 = 7;
	const int SIZEX2 = 6;
	class KthItemInSortedAryUsingIntersection
	{
		public:
			void callKthItemInSortedAryUsingIntersection()
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
				int K = 4;
			
				FindKthItemUsingIntersection(src1, src2, K);

				/*
					src1[] : 10 22 33 50 41 60 80
					src2[] : 5 12 15 33 62 80
					Sorted data [5 10 12 15 ]
					Kth (0) item is '15'
			
				*/
			}


			void FindKthItemUsingIntersection(int src1[SIZEX1], int src2[SIZEX2], int K)
			{
				stringstream sortedData;
				int i1 = 0;
				int i2 = 0;
				int Value = 0;

				while ((i1 < SIZEX1) && (i2 < SIZEX2))
				{
					if (src1[i1] < src2[i2])
					{
						Value = src1[i1];
						i1++;
						K--;
					}
					else if (src2[i2] < src1[i1])
					{
						Value = src2[i2];
						i2++;
						K--;
					}
					else
					{
						Value = src2[i2];
						i2++;
						i1++;
						K--;
					}
					sortedData << Value << " ";
					if (K == 0)
					{
						cout << endl << "Sorted data [" << sortedData.str() << "] " << endl;
						cout << "Kth (" << K << ") item is '" << Value << "'" << endl;
						break;
					}
				}
			}
	};
};