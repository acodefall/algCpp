#pragma once
#include <random>
#include <iostream>
#include <sstream>
using namespace std;
namespace QuickSortNM_@RED20170725015
{
	/*

		QuickSort over view_20170624035
			Quicksort is a DAC alogorithm and makes LongN partitions. Each partition has a Partition Value. Quicksort positions the partition-values to its correct position once for all, at the time of creating partition. There won't be any more effort to sort partition-values at any future time. Sorting partition will have the indirect effect of sorting non-partition values(LEAF).
			Number of non-partition values/LEAFS is less than number of partition values. Also number of partition-values and leafs will add up to srcLen. Now we can see why sorting partition-values sorts the whole array. There is no step saying SORT as we see in MergeSort. All we have is a function to create partitions.

			SrcLen(8) = "Partition Values=5" + "Number of leaf = 3"

 

		Why QuickSort is efficient_20170624036
			-Process of creating partiton will in fact sorts the element, and does this in-place, no extra memory is used like MergeSort   
			-Does not need extra function for SORTING, like the way it is in Merge sort
			-Partition function could pick the partition value from fixed index (say 0th element); OR generate the random-index using Random function or it could use MedianOfMedian Technique for generating random index.

			When partition index is fixed, QuickSort could end up taking N2 time if the array is already sorted. In this case Insertion Sort gives better perfromance than QT.
			When partition index is Random, average speed will be nLogN.
	 
		Steps for QuickSort_20170624038
			a) There will be two functions quicksort() and partitioTo3Parts(). Quicksort() calls partitioTo3Parts() for partitioning the array in to 3-parts. 

			().Partition method will modify the original array in such a way that, random element get sorted and sits at sortedIndex; and the values that are less than random element, will sit below sortedIndex, and similarly higher values sit above sortedIndex.  
			   1st-part goes from src[0] to src[sorted-Index -1]
			   2nd-part will have just one src[sortedIndex] 
			   3rd-part will have src[sortedIndex + 1] to src[srcLen-1] 

			1st and 3rd part will not be in sorted order; Mid-part will have only one value that is the PartitionValue and it will be in sorted position. In order to sort 1st and 3rd part, QuickSort() will make two recursive calls to itself: once for 1st-part and other for 3rd part. QuickSort() will break the recursion if src-array has just one element, that is when "startIndex in not less than endIndex".	

			b) Parameters for both functions is same, that (src[], startIndex, endIndex)
	
			Note that QuickSort() works on both 1st and 3rd partition, because it is SORTING the whole array. In contrast a SEARCH Algorithm like KthOrder statistics would have processed only one of the section. 

			Function checks (startIndex < endIndex). If that is true, then only calls partitioTo3Parts() with startIndex and endIndex.
			partitioTo3Parts() returns the PartitionIndex, and that will point to 2nd-part or Midpart which is already sorted..
	   
			Then QuickSort() makes two recursion calls 
						   QuickSort(src, startIndex, P-1) 
						   QuickSort(src, P+1, endIndex)
			Partitions sent to Recursion call will not include partition value.	   


		Quicksort Flow

                               {4 6 9 5 8 7 11 3}
              
              {4 6 5 3 7}               8             {11 9}
        
        {4 3}      5      {6 7}                   {9}  11
    
    {3}  4            {7}  6                       *
     *                 *   


                              {3 4 5 6 7 8 9 11}
      
	
	*/
	class QuickSort
	{
			public:
					void CallQuickSort()
					{
						int src[] = { 4, 6, 9, 5, 8, 7, 11, 3 }; 
						int srcLen = 8;

						cout << endl;
						cout << "Quicksort" << endl;
						
						cout << endl;
						for (int i = 0; i < srcLen; i++)
							cout << src[i] << " ";
						cout << endl;

						quicksortX(src, 0, srcLen - 1);

						cout << endl;
						for (int i = 0; i < srcLen; i++)
							cout << src[i] << " ";
						cout << endl;
					}

					void quicksortX(int src[], int startIndex, int endIndex)
					{
						//Only partition when 'startIndex < endIndex' there will be more than one element in array. 
						if (startIndex < endIndex)
						{
							int partIndex = Partition(src, startIndex, endIndex);

							stringstream ss;
							ss << endl << "Start " << startIndex << " End " << endIndex << " Anchor " << src[partIndex] << endl;
							ss << "{ ";
							for (int i = startIndex; i <= (partIndex - 1); i++)
								ss << src[i] << " ";
							ss << "} ";

							ss << "{ " << src[partIndex] << " } ";
							ss << "{ ";
							for (int i = partIndex + 1; i <= endIndex; i++)
								ss << src[i] << " ";
							ss << "} ";
							ss << endl;

							cout << ss.str();

							//When we make recursion call to partition the L-half abd R-Half, we exclude the 
							//partition-value from both.
							quicksortX(src, startIndex, partIndex - 1);
							quicksortX(src, partIndex + 1, endIndex);
						}
						else
						{
							cout << endl << "Start " << startIndex << " End " << endIndex << " Skip" << endl;
						}
					}
					int Partition(int src[], int start, int end)
					{
						default_random_engine rndPartition; //do not provide seed.
						uniform_int_distribution<int> dist(start, end);
						int RandomPartitionIndex = dist(rndPartition);
						swap(src[end], src[RandomPartitionIndex]); //push the partition-value out of action-zone to [end]
						int anchor = src[end];

						int prevHighIndex = 0; //Used for finding high-value and once found it stays there until we swap with lower-value(found by currIndex) OR we hit the end of array.
											   //Do not incr if (value > Anchor). This stays at high-value.
											   //If the (value <= Anchor), look back if prevHighIndex has a valid index; if so swap(currItem, prevHighIndex);

						/*cout << endl << "before partition " << endl;
						for (int i = 0; i <= end; i++)
							cout << src[i] << " ";
						cout << endl;


						cout << endl << "Start " << start << "End " << end << "Anchor " << anchor << endl;
						//cout << endl << "before partition " << endl;
						for (int i = 0; i <= end; i++)
							cout << src[i] << " ";
						cout << endl;*/

						for (int curr = 0; curr <= (end - 1); curr++)
						{
							//If the src[curr] is less than anchor then increase prevHighIndex and curr.
							//In otherword, prevHighIndex stops growing until it encounters a Value > Anchor.
							//So we can assume prevHighIndex is waiting at an index that has highValue and that needs to be swapped with low-value
							//So for every currItem, if the curr-value is 'lower' think about swapping it with [prevHighIndex]
							//prevHighIndex + 1
							if (src[curr] <= anchor)
							{
								if (prevHighIndex < curr)
									swap(src[prevHighIndex], src[curr]);
								prevHighIndex++;
							}
							/*cout << endl;
							for (int i = 0; i <= end; i++)
								cout << src[i] << " ";
							cout << endl;*/
						}
						//prevHighIndex would be pointing to 1st value in high-value-section, and swap it with partition-value waiting at [end]
						swap(src[prevHighIndex], src[end]);
						
						/*cout << endl;
						cout << endl << "After partition " << "Partition Value " << anchor << " Partition Index "<< prevHighIndex << endl;
						for (int i = 0; i <= end; i++)
							cout << src[i] << " ";
						cout << endl;*/

						return prevHighIndex;
					}
	};
};
