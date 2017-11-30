#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace MedianOfTwoSortedArraysNM
{
	/*
			  1    2   3   6 (2)             4   6   8   10 (7)
					2  3  6(3)               4   6  8(6)
					   3  6                  4  6
						            5


									
			1    12   15   26   38(15)             2   13   17   30   45 (17)
					  15   26   38(26)             2   13   17(13)
					  15   26                          13   17
									    16

									
	
	Median for two sorted arrays_20170627011
		Median can be found out by applying DAC. 
		In case of BinSearch, the mid-index is used as Partition, but here Median-value is used as partition bounday.
		
		Since the input arrays are sorted, they can be joined also. Before joining find thier median seperately, and this creates 4 segments.
		There are two medians. Place the two arrays right next to each other. Array with  smaller median should be placed first, and then should come the second array.
		Logic behind this is that arrays with smaller median should have lower values, so this array comes first.

		After placing the arrays next to each oher, pick one segment from each, and the choosen segments should form a "continous sequence". Discard the other two segments. 
		Thd choosen segments will not be joined. They are choosen segments.
		This helped reduce the problem size by half. You can see we are applying DAC logic.

		Go repeating is cycle until the total element count reduces to 2. Once that happens, average them and that is the median.

		
		Ex:(S1 median < S2 median) 
			So the order is <---S1 S2-->
			So select the 2nd-half-of-S1, 1st-half-of-S2, and discard the rest.
		   
		   (S2 median < S1 median) 
			So the order is <---S2 S1-->
			So select the 2nd-half-of-S2, 1st-half-of-S1, and discard the rest.
		
		Recursion parameters
		After selecting the subparts, make recursion calls and pass the partitions. 
		Partitions should include the medians that we were used as partition boundary. 
		Note that we did 2-way partition, not 3-way partition.
		Median element will be contributing to the MEDIAN in next round so it should be sent.
		

	Steps for finding median of two sorted arrays_20170627012
		1) parameters for recursion are src1[] and src2[] and len
		Len gives the length of arrays. both arrays will have same size
		2)Inside the function, first handle the condition when rray has shrunk to 0, 1, 2
		These are exit condition for recursion. So return
		if(len <= 0)
			Return
		if(len == 1)
			Arrays have shrunk to minimum size, compute the median and RETURN it
		if(len == 2)
			Arrays have shrunk to minimum size, compute the median and RETURN it
			Take (MaxOf[0] and MinOf[1])/2
			Return the median

		3) Otherwise array size is still high and needs to undergo DAC
		4) Compute the Median for src1 and src2
		5) if(M1 == M2)
			We found the median EXIT
		6) 	We need to make recursion call to subdivide half of current.
		There are 4 different ways to make recursion call, depending whether (M1 > M2) and (M2 > M1)
		Under each one of them taken in to account whether len is even or odd.
		These factor affect
		-beginOffSet of sub array
		-length of sub array
		If(EVEN)
			two elements were used for median computation so
			OFFSET = "(len/2) - 1"
			LEN =  "(len - len/2) + 1"
		If(ODD)
			one element was used for median computation so
			OFFSET = "(len/2)"
			LEN =  "(len - len/2)"


		if(M1 > M2)
			select the 1st-half-of-1st-array, 2nd-half-of-2nd-array, and discard the rest.

		if(M2 > M1)
			Select the 2nd-half-of-1st-array, 1st-half-of-2nd-array, and discard the rest.
		7)  Then make the recursion call and return their values


		
	*/
	class MedianOfTwoSortedArrays
	{
		public:
				void CallMedianOfTwoSortedArrays()
				{
					//int src1[] = { 1, 2, 3, 6 };
					//int src2[] = { 4,6,8,10};  //5
					//int med = findMedianForToArray(src1, src2, 4); //5
					//cout << "median " << med << endl;
					int src1[] = { 1, 12, 15, 26, 38 };
					int src2[] = { 2, 13, 17, 30, 45 }; //16

					int med = findMedianForToArray(src1, src2, 5);
					cout << "median " << med << endl; 
				}


				int findMedianForToArray(int* src1, int* src2, int len)
				{
					int median = 0;

					if (len <= 0)
						return -1;
					
					//array content
					cout << endl << "Array content" << endl << " size: " << len << endl;
					for (int i = 0; i < len; i++)
					{
						cout << src1[i] << " ";
					}
					cout << endl;
					for (int i = 0; i < len; i++)
					{
						cout << src2[i] << " ";
					}

					cout << endl;

					//Depending on whether array size is EVEN or ODD, the DAC will shrink the array length to either 1 or 2 elements.
					//when the two arrays of same size
					if (len == 1)
					{
						median = (src1[0] + src2[0]) / 2;
						return median;
					}
					if (len == 2)
					{	//Reason for for MIN and MAX is; say 1st array has {1, 10} and 2nd array has {5, 20}, we need to cover the range “5 and 10”; so we use MAX of 1st element and MIN of 2nd element.
						median = (max(src1[0], src2[0]) + min(src1[1], src2[1])) / 2;
						return median;
					}
					

					int med1 = findMedianOneArray(src1, len);
					int med2 = findMedianOneArray(src2, len);

					//To understand this imagine the two arrays are forming a circle
					if (med1 == med2)
					{
						return med1;
					}
					else if (med1 > med2)
					{	// use (Len - Len/2), not just Len/2. The difference matters for ODD length. 
						if (len % 2 == 0)
							return findMedianForToArray(src1, (&src2[0] + (len / 2 - 1)), (len - len / 2) + 1);
						return findMedianForToArray( src1, (&src2[0] + (len / 2)), (len - len / 2));
					}
					else
					{	// use (Len - Len/2), not just Len/2. The difference matters for ODD length. 
						if (len % 2 == 0)
							return findMedianForToArray((&src1[0] + (len/2 - 1)), src2, (len - len/2) + 1);
						return findMedianForToArray((&src1[0] + (len / 2)), src2, (len - len/2));
					}
					return median;
				}

				int findMedianOneArray(int src[], int len)
				{
					
					//int med1 =
					//compute the median 
					int median = 0;
					if (len > 0)
					{
						//1 2 3 4 = 2
						if (len % 2 == 0)
						{
							median = (src[len / 2] + src[(len - 1) / 2]) / 2;
						}
						else if ((len % 2) != 0)
						{
							median = src[len / 2];
						}
					}
					else
					{
						median = src[0];
					}

					
					cout << endl << "Median : " << median << endl;
					return median;
				}
				
	};
};