#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

/*
	Selection algorithms_20170627001
	Given an unsorted array, Kth order statistics is used to know the value located at Kth index without actually sorting the array.
	Ex: If K = 5, we have to tell what value will at 5th index, without sorting the src[].
	Kth order problem can be generalized as follows.
	If K=0, then return [0] element;
	If K=N/2, then return mid element;
	If K=N, then return [MAX-1] element;

	We can know the Value located at Kth index by sorting the wholw array using Merge sort. This is inefficient because it sorts whole array where as our 
	requirement is to sort only one element. This takes O(NlogN) tine

	Kth order statistics technique will discover the Kth value by just sorting few random element. This take Log(K) time.
	Randomly pick an element from unsorted src-array, and sort that one element, and get its index(say sortedIndex). 
	If the sortedIndex is equal K, then we have solved the problem. Otherwise, randomly select an anoher element and sort that one element,
	abd check what index it gets. And check that index against K. Repeat these steps until sortedIndex becomes equal to K.
	Kth order statistics 

	Random number can be generated usng Median Of Median techinque also.
	First round uses the whole array for picking the random index. Ex: If array len is 10, we pick an random index between 0-9.
	In the second round uses only the part of the array for selecting random number. In the 3rd round array length reduces further down.
	Sorted index returned by 1st round will tell the 2nd round whether to explore right-partition or left-partition. 
	Ex: User has given K = 7 and array length is 10.
	1st round will select 5 as random index, and sorts that one value; and it takes index-4. We are looking for K=7 and it comes in 
	right-partition so we 2nd round picks the random number inside 2nd half.


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