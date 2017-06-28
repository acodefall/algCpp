#pragma once
#include <iostream>
#include <iomanip>>
using namespace std;

namespace MergeSortingNM
{
	/*
		MergeSort_20170623010
		This is how mergesort divides the array in parts				
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


		These are the sections of array passed to Merge(), for sorting in this order
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
	class MergeSort
	{
		public:
				void CallMergeSort()
				{
					int src[9] = { 3, 2, 16, 11, 27, 4, 15, 9, 8 };
					int srcLen = 9;
					int K = 4;
					
					cout << endl << "Before sorting" << endl;
					for (int i = 0; i < srcLen; i++)
					{
						cout << src[i] << " ";
					}
					cout << endl;
					//////////

					MergeSortX(src, 0, srcLen - 1);

					cout << endl;
					cout << endl << "After sorting" << endl;
					for (int i = 0; i < srcLen; i++)
					{
						cout << src[i] << " ";
					}
					cout << endl;
					//////////

				}


				void MergeSortX(int* src, int start, int end)
				{
					int mid = 0;
					
					//If "start=end" then we have just one element so nothing to partition, so do not enter the loop at all.
					if (start < end)
					{
						mid = start + (end - start) / 2;
						cout << "Start: " << start << " end: " << end << " mid: " << mid << "\r\n";
						MergeSortX(src, start, mid); //includes the 
						MergeSortX(src, mid + 1, end);
						merge(src, start, mid, end);
					}
					
				}

				//sort the array that is in between "start - end"
				void  merge(int* src, int startIdx, int midIdx, int endIdx)
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
				}

	};
};
