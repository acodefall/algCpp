#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
// selects the median of medians in an array





class MedianOfMedian
{

public:
	
	int call()
	{
		int Src1[] = { 1, 2, 3, 6 };
		int Src2[] = { 4, 6, 8, 10 };
		int n1 = sizeof(Src1) / sizeof(Src1[0]);
		int n2 = sizeof(Src2) / sizeof(Src2[0]);
		if (n1 == n2)
			printf("Median is %d", medianSortedArrays(Src1, Src2, n1));
		else
			printf("Doesn't work for arrays of unequal size");
		return 0;
	}

	int computeMedian(int src[], int len)
	{
		if (len % 2 == 0)
			return (src[len / 2] + src[len / 2 - 1]) / 2;
		else
			return src[len / 2];
	}

		int medianSortedArrays(int Src1[], int Src2[], int len)
		
		{
			/* return -1  for invalid input */
			if (len <= 0)
				return -1;
			if (len == 1)
				return (Src1[0] + Src2[0]) / 2;
			if (len == 2)
				return (max(Src1[0], Src2[0]) + min(Src1[1], Src2[1])) / 2;

			int m1 = computeMedian(Src1, len); /* get the median of the first array */
			int m2 = computeMedian(Src2, len); /* get the median of the second array */

			/* If medians are equal then return either m1 or m2 */
			if (m1 == m2)
				return m1;

			/* if m1 < m2 then median must exist in Src1[m1....] and
			Src2[....m2] */
			if (m1 < m2)
			{
				if (len % 2 == 0)
					return medianSortedArrays(Src1 + len / 2 - 1, Src2, len - len / 2 + 1);
				return medianSortedArrays(Src1 + len / 2, Src2, len - len / 2);
			}

			/* if m1 > m2 then median must exist in Src1[....m1] and
			Src2[m2...] */
			if (len % 2 == 0)
				return medianSortedArrays(Src2 + len / 2 - 1, Src1, len - len / 2 + 1);
			return medianSortedArrays(Src2 + len / 2, Src1, len - len / 2);
		}


};