
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
namespace KthItemInSortedAryUsingIntersectionNM //@RED20170919005
{
	/*
		Find Kth item among 2 arrays_RED20170919005
					Since the arrays are already sorted we can find Kth item among those two arrays using INTERSECTION method. INTERSECTION method iterates the arrays ONLY until K items are crossed.
					If K = 4, stop after merging 4 items.
					This takes O(K) time.  Thiis can also be solved by using MERGING sorted arrays as we do in MERGE sort but that needs extra array.

					To understand intersection method, imagine a SINGLE cursor that rides both Arrays selectively. Cursor hops on to the array who’s value is lower and advances the index on that array; where as the index of other array stays at the current index. Say Src1 has low value, then increment the index of Src1; index of Src2 remains unchanged. If both values are equal, then increment the index of both src1 and src2. 

					Cursor rides the array with lower value because arrays are expected to be ACENDING order. If the array were in DESCENDING order, cursor would have been hopping on to the array who's value is HIGHER.

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