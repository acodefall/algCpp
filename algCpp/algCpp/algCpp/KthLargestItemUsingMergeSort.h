#pragma once
#include <iostream>
#include <iomanip>>
using namespace std;
#include<iostream>

namespace KthLargestItemUsingMergeSortNM
{
	/*			     
		Find Kth Item in unsorted data using MergeSort_20170621003
			Do the merge sort as usual.
			Once the array is sorted return the item located at kth index.
			We have to sort the whole array to know Kth position. This is because of following reason. Merge function will be first called to sort individual smaller parts; then a larger part will be created by stitching some of the smaller parts. Merge sort will be called to sort these composite parts. This 2nd time sorting will rearrange all of the elements. So to know what VALUE comes at 5th position, we have to sort whole array.


													(s=0 e= 8)
													3, 2, 16, 11, 27, 4, 15, 9, 8  
													m = 4

									s=0,e=4                         s=5 e=8
									3, 2, 16, 11,27                 4, 15, 9, 8  
									m=2                             m=1      
                     
						s=0,e=2             s=3,e=4           
						3, 2, 16            11,27
						m=1                 m=1
                 
				s=0,e=1      s=3 e=3
				3,2          16
				m=0

		s=0,e=0      s=1,e=1 
		3            2


Merge() called for sorting in this order
    "3 2" 
    "2 3 16"
    "11 27"
    "2 3 16 11 27"
    "4 15"
    "9 8"
    "4 15 8 9"
    "2 3 11 16 27 4 8 9 15"
    "2 3 4 8 9 11 15 16 27"
	
	*/
	class KthLargestItemUsingMergeSort
	{
		public:
			void CallKthLargestItemUsingMergeSort()
			{
				int src[9] = { 3, 2, 16, 11, 27, 4, 15, 9, 8 };
				int srcLen = 9;
				int K = 4;
				MergeSort(src, 0, srcLen - 1, K);
				////Try to extract the Kth element
				int ret = src[K - 1];
				
				//////////
				cout << "\r\n Kth value is " << ret << "\r\n";
			}


			int MergeSort(int* src, int start, int end, int K)
			{
				int mid = 0;
				int ret = -1;
			
				//If "start=end" then we have just one element so nothing to partition, so do not enter the loop at all.
				if (start < end)
				{
					mid = start + (end - start) / 2;
					cout << "Start: " << start << " end: " << end << " mid: " << mid << "\r\n";
					MergeSort(src, start, mid, K); //includes the 
					MergeSort(src, mid + 1, end, K);
					ret = merge(src, start, mid, end, K);

				
				}
				return ret;
			}
		
			//sort the array that is in between "start - end"
			int  merge(int* src, int startIdx, int midIdx, int endIdx, int K)
			{
				int st = startIdx;
				int ed = midIdx;
				int st2 = midIdx + 1;
				int ed2 = endIdx;
				int dataLen = endIdx - startIdx + 1;
				int sortedIndex = 0; 
				int* sortedData = new int[dataLen];
				int retValue = -1;
				for (int i = 0; i < dataLen; i++)
				{
					sortedData[i] = 0;
				}

				cout << "\r\n merge start: " << startIdx << " mid: " << midIdx << " end: " << endIdx << "\r\n";
				cout << "\r\n array(before) " << "\r\n";
			
				//print the array that is in between "start - end"
				for (int i = startIdx; i < (endIdx + 1); i++)
				{
					cout << src[i] << " ";
				}

				//sort the data. Output will go to sortedData
				while ((st <= ed) && (st2 <= ed2))
				{
					if (src[st] < src[st2])
					{
						sortedData[sortedIndex] = src[st];
						sortedIndex++;
						st++;

					}
					else
					{
						sortedData[sortedIndex] = src[st2];
						sortedIndex++;
						st2++;
					}
				}

				while (st <= ed)
				{
					sortedData[sortedIndex] = src[st];
					st++;
					sortedIndex++;
				}

				while (st2 <= ed2)
				{
					sortedData[sortedIndex] = src[st2];
					st2++;
					sortedIndex++;
				}
				//////Sorting Done////


				////Print sorted data //////
				cout << "\r\n array(after) " << "\r\n";
				for (int i = 0; i < sortedIndex; i++)
				{
					cout << sortedData[i] << " ";
				}
				////////


				///Copy the sorted data to original Array 
				//copy the sorted data that is in SortedOutPut[] to Src[]
				//Merge function will sorting some section of src[], given in start and end indexes.
				//Start/End could point to 4-8 or 16-19. Sorted data will be held in a array that begins at 0.
				//At the end of the function, sorted data should be transferred to src[] and it should overwrite the '
				//start-end indexed only
				for (int i = startIdx, j = 0; j < sortedIndex; i++, j++)
				{
					src[i] = sortedData[j];
				}
				//////////////////////////


				
				return retValue;
			}


	};
};