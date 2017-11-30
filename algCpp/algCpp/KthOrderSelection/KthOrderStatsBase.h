#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

/*
	Selection algorithms_20170627001
		In general, KthOrderStatistics algorithm is used to know the value that would sit at Kth index if we were to sort the UNSORTED array. KthOrderStatistics algorithm will produce the result without sorting whole array. KthOrderStatistics Algorithm randomly picks a value from unsorted array, and uses the random value as boundary-value for createing 3-way partition. Partitioning process will place the boundary-value at proper position; inother words sorts just one element. If the index happens to be K then we discovered what value sits at Kth position, and return it to caller. If the index is not equal to K, then apply the KthOrderStatistics algorithm more time. Choose an another random value and sort iy by means of partitioning process. Repeat this process until one of the partition-value lands at Kth index.Once that happens exit. 

		KthOrderStatistics can be used for computing MIN, MAX and Median values. MIN means value stored at K = 0, MAX means value stored at K = N, and Median means value stored at K = N/2.
		MedianOfMedian algorithm can be used for selecting random element.

		Instead of KthOrderStatistics,  merge sort can be used. But  Merge sort will sort the whole array and then returns the Value located at Kth index. This technique is inefficient because it sorts whole array, and even the best sorting algorithm takes O(nLogn) time. Where as KthOrderStatistics took O(N) time.

		Example: Caller provide the index(K) and wants to know the VALUE stored at that position. When K = 8, we will be finding 8th item, when K =0 we will be finding MIN item. When K = N we will be fining MAX item. When K = N/2 we will be finding MEDIAN. To find the Kth item we can either fully sort the array using MergeSort or partially sort the array

		Kth order problem can be generalized as follows.
		If K=0, then return [0] element;
		If K=N/2, then return mid element;
		If K=N, then return [MAX-1] element;

	
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

		KthOrderStats with DAC
			3-way partitioning sorts one element and gives the index for that one element. 
			If this index matches the K-index, program can return the value to caller and exit.
			If the index is not same as K-index, KthOrderStats should be run once more.
			index helps apply DAC. 
			If the index is < than the K-index then KthOrderStats will explore only the right-partition
			If the index is > than the K-index then KthOrderStats will explore only the left-partition
			This is how  KthOrderStats applies DAC.



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