#pragma once
#include <random>
#include <iostream>
#include <sstream>
using namespace std;
namespace QuickSortNM
{
	/*

		QuickSort over view_20170624035
			Find a random element in the src-array, and place it at its sorted-position, by doing 3-way partition technique.
			This partitioning will help us sort just one element, and but creates two partitions that appear BEFORE and AFTER the sorted partition-value.
			Now we want to apply the above techniwue on these two partitions, so we make 2 recursion calls(one for left and right partition).
			The recursion call will pick a random-value, just sorts that one random-value, and as a by product create 
			2 partitions. 
			This process continues until each partition has just element. By this time whole array would have been sorted.

			Implementation
				QuickSort(src-whole-array, staart, end)
				{
					if(start < end)
					{
						//Find a random element in the src-array, and place it at its sorted-position, by using 3-way partition technique.
						//This partitioning will help us sort just one element, and but creates two partitions that appear BEFORE and AFTER the sorted partition-value.
						partndex = Partition();

						//Now try to apply the same technique on Left and Right partitions.
						QuickSort(src, startIndex, partndex-1)
						QuickSort(src, partndex+1, endIndex)
				}
			
			Quicksort is a DAC alogorithm and makes LongN partitions, so there are LogN levels. 
			But we process every branch at every level because we want to SORT each and every element, 
			so work done by every level is CN. So taotal work is NLogN.

			Quick was efficient because partition operation created two partitions and also successfully sorted the partition-value.
			In fact partition-value will be placed at it its FINAL index. That partition-value will not be sorted again. 
			Compared to this Merge Sort will go on partitioning the array until the size is 1, and then starts sorting the each partition.
			So Mergesort make more than 1-pass.

			QucikSort does 3-partition and Mergesort does 2-way partition. 3-way partition creates partition value which can be 
			sorted but Mergesort does not even hace partition-value.
 

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
      
	
	3-way partitioning technique_20170919001
	//Eventually all lower values should go to left side. We can achieve this maintaining running count of element
	//lower values(than Anchor value). As we are iterating the array,
	//if (COUNT < currIndex) then it means we have gone past few higher-values, and the
	//places held by these higher values can be given to a lower value; this will help us bring all the lower values to left side.
	//Ex: currIndex = 6 and COUNT = 4. This means 5th element is higher value. If "curValue" is a lower value,
	//we will swap it with 5th element(basically swap 5th and 6th). Then increment both COUNT and currIndex.

	//Final logic is
	//Iterate the array usin a ForLoop
	//	if(curValue < AnchorValue)
	//		if(COUNT < currIndex)
	//			Swap(src[Count], src[curIndex]) //we have a highVaue on wrongside
	//		COUNT++;


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
							//Find a random element in the src-array, and place it at its sorted-position, by using 3-way partition technique.
							//This partitioning will help us sort just one element, and but creates two partitions that appear BEFORE and AFTER the sorted partition-value.
							//Now we want to apply the above techniwue on these two partitions, so we make 2 recursion calls(one for left and right partition).
							//The recursion call will pick a random-value, just sorts that one random-value, and as a by product create 
							//2 partitions. 
							//This process continues until each partition has just element. By this time whole array would have been sorted.

							int partIndex = Partition(src, startIndex, endIndex);

							/*stringstream ss;
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

							cout << ss.str();*/

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
					
					//3-way partitioning technique.
					//Eventually all lower values should go to left side. We can achieve this maintaining running count of element 
					//lower values(than Anchor value). As we are iterating the array, 
					//if (COUNT < currIndex) then it means we have gone past few higher-values, and the 
					//places held by these higher values can be given to a lower value; this will help us bring all the lower values to left side.
					//Ex: currIndex = 6 and COUNT = 4. This means 5th element is higher value. If "curValue" is a lower value,
					//we will swap it with 5th element(basically swap 5th and 6th). Then increment both COUNT and currIndex. 
					
					//Final logic is
					//Iterate the array usin a ForLoop
					//	if(curValue < AnchorValue)
					//		if(COUNT < currIndex)
					//			Swap(src[Count], src[curIndex]) //we have a highVaue on wrongside  
					//		COUNT++;

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
