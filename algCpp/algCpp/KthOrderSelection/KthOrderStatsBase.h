#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

/*
	Selection algorithms_20170627001
		In general Selection algorithm is used for Knowing the position of an element in an UNSORTED array, without actually sorting it. Caller provide the index(K) and wants to know the VALUE stored at that position. When K = 8, we will be finding 8th item, when K =0 we will be finding MIN item. When K = N we will be fining MAX item. When K = N/2 we will be finding MEDIAN. To find the Kth item we can either fully sort the array using MergeSort or partially sort the array.

		Sorting the whole array and then returning Kth item from sorted array is inefficient because it sorts whole array to know the position of just one element. Alternatively we can use Partial Sorting. Partial Sorting sorts one random element and compares its index against K. If  SortedIndex == K, then we know what value sits are Kth index, problem solved. If SortedIndex != K, then try sorting another random element and check its SortedIndex against K. Partial sorting is called as KthOrderStatistics. PartialSorting takes O(N) time, and this is lesser than NlogN taken by Mergesort.

		KthOrderStatistics sorts a random element. This random element is based on a randomIndex. RandomIndex can be generated using some random algorithm or using a suffisticated algorithm called as MedianOfMedian.


	Find Kth Item in unsorted data using KthOrderStats_20170621002
		KthOrderStats is used to find Kth element in unsorted array, without sorting whole array.  Logic will not sort the whole array, instead Logic randomly picks an element from the unsorted array, and sorts only that random element by calling PartitionInTo3wayMethod().Partition method will modify the original array in such a way that, random element get sorted and sits at sortedIndex; and the values that are less than random element, will sit below sortedIndex, and similarly higher values sit above sortedIndex.
		1st-part goes from src[0] to src[sorted-Index -1]
		2nd-part will have just one src[sortedIndex]
		3rd-part will have src[sortedIndex + 1] to src[srcLen-1]
		Now we know one value and its position.
		sortedIndex gives Position and src[sortedIndex] gives value
		Say src[5] has value 25;  compare sortedIndex(5) with K and decide whether we should explore 1st-part or 3rd-part.
		For example: SortedIndex = 5, and K = 8. This means 8th element comes after 5th element, so explore 3rd-partition.
		SortedIndex = 10, and K = 8. This means 8th element comes before 10th element, so explore 1st-partition.
		SortedIndex = 8, and K = 8. This means we have solved the problem, return the value stored in 2nd-partition/mid-part to caller, and exit the program. That is src[sortedIndex]

		Exploring 1st-part or 3rd-part involves making Recursion call to KthOrderFunction().  In the subsequenct round, KthOrderFunction() will again pick a random element and calls PartitionInTo3wayMethod() to sort that ONE random element. Once PartitionInTo3wayMethod() returns, we compare sortedIndex with K. We may exit or continue making Recursion will. This Recursion will go on until SortedIndex returned by PartitionInTo3wayMethod() is equal to K.

		This logic uses DAC. At everystep we explore only one part, not both the parts, this is because we are searching. When sorting we will explore both the parts.


		KthOrder(src, K, srcLen)
		-Src, K = 8
		-RandomIndex = 5 //Before sorting
		-SortedIndex = PartitionInTo3wayMethod(S, RandomIndex)
		If(K == SortedIndex)   //SOLVED
			Return S[SortedIndex];
		If(K < SortedIndex)
			Return PartitionInTo3wayMethod(1stPart, K, Length of 1stPartOnly);
		If(K > SortedIndex)
			Return PartitionInTo3wayMethod(3rd, K – (len of 1st and 2ndpart), SrcLen - (len of 1st and 2ndpart));


		Steps for finding Kth Item in unsorted data using KthOrderStats _20170627004
			Input to the recursion function is src[], srcLen, K.
			We have to return the value held by Kth index of Src[]

			a) Generate a random number between 0 & srcLen using
			default_random_engine
			uniform_int_distributition
			b) Get the value held by
			randomValue = src[randomIndex]
			c) Call PartitionInTo3Parts() and pass randomValue, start and endIndex of src array.
			PartitionInTo3Parts() sort only the random value and return its index, say sortedIndex.
			PartitionInTo3Parts() would have created 3 partitions inside src[].
			1st-part goes from src[0] to src[sorted-Index -1]
			2nd-part will have just one src[sortedIndex]
			3rd-part will have src[sortedIndex + 1] to src[srcLen-1]
			Now we know one value and its position.
			sortedIndex gives Position and src[sortedIndex] gives value
			d) compare K and sortedIndex.
			If(K == SortedIndex)   //SOLVED
			Return S[SortedIndex];
			If(K < SortedIndex)
			Return PartitionInTo3wayMethod(1stPart, K, Length of 1stPartOnly);
			If(K > SortedIndex)
			Return PartitionInTo3wayMethod(3rd, K – (len of 1st and 2ndpart), SrcLen - (len of 1st and 2ndpart));

	
*/
namespace KthOrderStatsBaseNM //@RED20170627004
{
	class KthOrderStatsBase
	{
		public:
				//Find the value stored at index K
				int CallKthOrderStatsBase(int* src, int srcLen, int K)
				{
					cout << "\r\n" << "CallKthOrderStatsBase() " << " K is " << K << "\r\n";
					for (int i = 0; i < srcLen; i++)
					{
						cout << src[i] << " ";
					}
					int ret = KthOrderStatsUsingQuickSelect(src, srcLen, K);
					cout << "\r\n" << "CallKthOrderStatsBase(). src[K]: "<< ret << "\r\n";
					return ret;
				}
				
				//assume there is no duplicates in data
				int KthOrderStatsUsingQuickSelect(int* src, int srcLen, int K)
				{
					//generate random number
					default_random_engine rndPartition; //do not provide seed.
					uniform_int_distribution<int> dist(0, srcLen -1);
					int RandomPartitionIndex = dist(rndPartition);
				
					int PartValuePosition = PartitionInTo3Parts(src, 0, srcLen-1, RandomPartitionIndex);
					PartValuePosition++;  //PartValuePosition is index so ADD 1
					cout << "Partition Value : "<< src[RandomPartitionIndex] << "index of Partition value(before quickselect): " << RandomPartitionIndex << "\r\n";
					cout << "Index Of Partition Value(in sorted state after QuickSelect) : " << PartValuePosition << "\r\n";
					
					//Assume QuickSelect that quick select has created 3 arrays:"< K" "=K" and ">K"
					//check the partition value and go in to appropriate half
					if( K == PartValuePosition)
					{
						//When using PartValuePosition on src[] subtract 1, because PartValuePosition is not INDEX
						return src[PartValuePosition-1];
					}
					else if( K <= (PartValuePosition - 1)) //subtract 1 for the partition
					{
						//Adjust the srcLen so we search in first "PartValuePosition" items
						return KthOrderStatsUsingQuickSelect(src, PartValuePosition, K);
					}
					else if( K > PartValuePosition)
					{
					    //Adjust the src and srcLen we search AFTER first "PartValuePosition" items
						//Assuming there are 3 parts, adjust the K as "K = K-org - (1stPartLen + 2ndPartLen)"
						return KthOrderStatsUsingQuickSelect(&src[PartValuePosition], srcLen - PartValuePosition, K - (PartValuePosition));
					}
					return -1;
				}

				//this is same as PartitionInTo3PartsAssumeRandom()
				int PartitionInTo3Parts(int src[], int start, int end, int index)
				{
				
					swap(src[end], src[index]); //push the partition-value out of action-zone to [end]
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