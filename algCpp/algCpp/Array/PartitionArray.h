#pragma once
#include <iostream>
#include <random>
using namespace std;
namespace PartitionArrayNM
{
	class PartitionArray
	{
		/*
			#pragma region DebugX  
			#pragma endregion DebugX 
	
			2-way Partition and 3-way partition_20170627006
				Roughtly speaking there are two types of partitioning. Partition in to 2-parts and in to 3-parts.
				In 3-way partitioning, partitionValue sits on the border of low-section and high-section. This is used in Quicksort, KthOrderStatistics problems.
					 {4, 6, 9, 5, 8, 7, 11, 3 }; //partitionValue = 8
					 {4, 6, 5, 3, 7, 8, 11, 9 };
				In 2-way partitioning, there is no border-value; all we have is low-section and high-section. This is used when we want to separate single-number from rest, as we do in two-color and 3-color sorting problems.
				  { 1, 3, 1, 1, 3, 2, 1, 2, 3, 1, 2, 3 } 
				  { 1, 1, 1, 1, 1, 2, 3, 2, 3, 3, 2, 3 } //separate 1s from rest
				  { 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3 } //separate 2s from rest
				Core of Partitioning alogorithms is identifying the elements that are eligible to sit in left-half; and if found then swap them for a high-value that is waiting for a donor in left-half. Partition logic assumes anything that is “less than” Anchor Element is eligible for sitting in left-side. So Anchor element should be a number just outside of left-half; in case of 3-way partitioning Anchor element is PartitionValue. In case of 2-way partitioning Anchor element is the lowest value in high-section. 
				//3-way partitioning
				Input: { 4, 6, 9, 5, 8, 7, 11, 3 }; 
				Output: {4, 6, 5, 3, 7, 8, 11, 9 };// Output  when anchor is 8

				//2-way partition
				Input: { 1, 3, 1, 1, 3, 2, 1, 2, 3, 1, 2, 3 }; //2-way partition, anchor is 2
				Output: { 1, 1, 1, 1, 1, 2, 3, 2, 3, 3, 2, 3 } // Output  when anchor is 2
				Output: { 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3 } // Output  when anchor is 3

				//Common to both 2-way and 3-way partitioning
				if (src[curr] < anchor)  
				{
					if (prevHighIndex < curr)
						swap(src[prevHighIndex], src[curr]);
					prevHighIndex++;
				}

			Partition Logic _ 20170627009
				Assume partition value is 5. partitioning should place the lower-value first, followed by higher values. 
				Basically iterate the array, and swap the low-value (sitting on right-side) with the higher-value (sitting on left-side).
				For this logic to work program should maintain an index to the left-most high-value.
				As a result of swapping, high-value will get replaced by low-value, and appropriately we have to increment the index that was pointing to high value;
				because that location is taken up by low-value.

				Coming to implementation: At the beginning initialize the high-Index to 0. Then scan the array from L-R, and compare curr-value with part-value (that is 5). 
				If the curr-value is lower than part-value (that is 5), and high-Index is less than curr-index, then swap the two values and increment the high-index. 
				Ex: Array has "10 2" and partition-value is 5; Say the cursor is at 2 and 2 is lower than 5. We know there is higher-value(10) sitting on the left-side.
				We exchange 10 and 2. so array becomes "2 10"  

				Above logic applies to both 2-way and 3-way partitions.
				3-way partitioning needs one more change. Before iterating the array, take out the partition value out of of equation,
				by swapping partition-value with the value stored at max-index. Then partition logic should only span until (SrcLen -1).
				After partitioning, place the partition-value abefore the start of right-side. 
				This can be done by swapping 1st element of high-segment with src{max]
	
					for (int curr = 0; curr <= (end - 1); curr++)
					{
						//If the src[curr] is less than anchor then increase prevHighIndex and curr.
						//In otherword, prevHighIndex stops growing until it encounters a Value > Anchor.
						//So assume prevHighIndex is waiting at an index that has highValue, to be swapped with low-value
						 //So for every currItem, if the curr-value is 'lower' think about swapping it with [prevHighIndex]
						//prevHighIndex + 1
						if (src[curr] <= anchor)
						{
								if(prevHighIndex < curr)
									swap(src[prevHighIndex], src[curr]);
								prevHighIndex++;
						}
					}
					Swap(src[prevHighIndex], src[endIndex]);

			Steps for 3-way partition logic_ 20170627010
					a) parameters are startIndex and endIndex
					b) compute the random index using default_random_engine and uniform_int_distribution<int>
					c) Use swap() to swap src[randomIndex] with src[endIndex] 
					d) Set src[end] to anchor
					e) Declare prevHighIndex. this stops growing if the currValue > AnchorValue
					f) start a ForLoop to go from startIndex to as long as (endIndex-1)
					g) Inside ForLoop
							if (src[curr] <= anchor)
							{
								if(prevHighIndex < curr)
									swap(src[prevHighIndex], src[curr]);
									prevHighIndex++;
							}
					h) Once outside the ForLoop
						swap(src[prevHighIndex], src[end]);
					i) Return prevHighIndex to caller



		 Partition Logic Flow
			 int src[] = { 4, 6, 9, 5, 8, 7, 11, 3 };   //partitionValue = 8. Move 8 to end, and rearrange only 4-11
						 { 4, 6, 9, 5, 3, 7, 11, 8 }; // ">  = curr" and "^  = prevHigh"

			 curr      prevHigh
			 -------   ---------
			 0(4)       0(4)            (4 < 8)  'Incr both'                   {4, 6, 9, 5, 3, 7, 11, 8}; 
																				>
																				^
																				   >
																				   ^
                                                                           
			 1(6)       1(6)            (6 < 8)  'Incr both'                   {4, 6, 9, 5, 3, 7, 11, 8}; 
																				   >
																				   ^
																					  >
																					  ^
			 2(9)       2(9)           !(9 < 8)  'Incr only curr'               {4, 6, 9, 5, 3, 7, 11, 8}; 
																					   >    
																					   ^   
																					   ^  >

			 3(5)       2(9)            (5 < 8)  'Swap 9 and 5. Incr both'      {4, 6, 9, 5, 3, 7, 11, 8}; 
																					   ^  >
																				{4, 6, 5, 9, 3, 7, 11, 8}; 
																						  ^               
																							 >

			 4(3)       3(9)            (3 < 8)  'Swap 9 and 3. Incr both'      {4, 6, 5, 9, 3, 7, 11, 8}; 
																						  ^  >
																				{4, 6, 5, 3, 9, 7, 11, 8}; 
																							 ^  >

			 5(7)       4(9)            (7 < 8)  'Swap 9 and 7. Incr both'      {4, 6, 5, 3, 9, 7, 11, 8}; 
																							 ^  >
																				{4, 6, 5, 3, 7, 9, 11, 8};
																								^  >
    
			 6(11)      5(9)           !(11 < 8)  'stop'                        {4, 6, 5, 3, 7, 9, 11, 8};
																								^  >
			curr(6) = [end-1](6) so stop iteration. 
			Swap  [end] with [prevHighIndex]                                    {4, 6, 5, 3, 7, 8, 11, 9};
		*/
		public:
			void CallPartitionArray()
			{
				int src[] = { 4, 6, 9, 5, 8, 7, 11, 3 }; //4 6 5 3 7 8 11 9
				int srcLen = 8;

				//Partition in to 3-parts ".....lowMIDhight..."
				//After partitioing the PartitionValue should sit at the border of two segments.
				PartitionInTo3PartsAssumeRandom(src,0, srcLen-1);
			
				int src2[] = { 1, 3, 1, 1, 3, 1, 3, 1 };
				int anchor = 3; //anchor
				int srcLen2 = 8;

				
				//Partition in to 2-parts ".....lowhight..."
				//After partitioing the PartitionValue can be anywhere in higher segment. 
				int idxx = PartitionInTo2Parts(src2, 0, srcLen2 - 1, anchor);
				////output: 1 1 1 1 1 2 3 2 3 3 2 3 ret = 5
			}

			/*
				a) parameters are startIndex and endIndex
				b) compute the random index using default_random_engine and uniform_int_distribution<int>
				c) Use swap() to swap src[randomIndex] with src[endIndex] 
				d) Set src[end] to anchor
				e) Declare prevHighIndex. this stops growing if the currValue > AnchorValue
				f) start a ForLoop to go from startIndex to as long as (endIndex-1)
				g) Inside ForLoop
							if (src[curr] <= anchor)
							{
								if(prevHighIndex < curr)
									swap(src[prevHighIndex], src[curr]);
								prevHighIndex++;
							}
				h) Once outside the ForLoop
					swap(src[prevHighIndex], src[end]);
				i) Return prevHighIndex to caller
			*/
			//in case of 3 - way partitioning Anchor element is PartitionValue.
			int PartitionInTo3PartsAssumeRandom(int src[], int start, int end)
			{
				default_random_engine rndPartition; //do not provide seed.
				uniform_int_distribution<int> dist(start, end);
				int RandomPartitionIndex = dist(rndPartition);
				swap(src[end], src[RandomPartitionIndex]); //push the partition-value out of action-zone to [end]
				int anchor = src[end];

				int prevHighIndex = 0; //Used for finding high-value and once found it stays there until we swap with lower-value(found by currIndex) OR we hit the end of array.
									   //Do not incr if (value > Anchor). This stays at high-value.
									   //If the (value <= Anchor), look back if prevHighIndex has a valid index; if so swap(currItem, prevHighIndex);

#pragma region DebugX  
				cout << endl << "before partition " << endl;
				for (int i = 0; i <= end; i++)
					cout << src[i] << " ";
				cout << endl;


				cout << endl << "Anchor " << anchor << endl;
				cout << endl << "before partition " << endl;
				for (int i = 0; i <= end; i++)
					cout << src[i] << " ";
				cout << endl;
#pragma endregion DebugX 
				for (int curr = 0; curr <= (end - 1); curr++)
				{
					//If the src[curr] is less than anchor then increase prevHighIndex and curr.
					//In otherword, prevHighIndex stops growing until it encounters a Value > Anchor.
					//So we can assume prevHighIndex is waiting at an index that has highValue and that needs to be swapped with low-value
					//So for every currItem, if the curr-value is 'lower' think about swapping it with [prevHighIndex]
					//prevHighIndex + 1
					if (src[curr] < anchor)
					{
						if(prevHighIndex < curr)
							swap(src[prevHighIndex], src[curr]);
						prevHighIndex++;
					}
#pragma region DebugX  
					cout << endl;
					for (int i = 0; i <= end; i++)
						cout << src[i] << " ";
					cout << endl;
#pragma endregion DebugX 
				}
				//prevHighIndex would be pointing to 1st value in high-value-section, and swap it with partition-value waiting at [end]
				swap(src[prevHighIndex], src[end]);
#pragma region DebugX  
				cout << endl << "after partition " << "partition value: " << anchor << "partitionIndex: " << prevHighIndex  << endl;
				for (int i = 0; i <= end; i++)
					cout << src[i] << " ";
				cout << endl;
#pragma endregion DebugX 
				return prevHighIndex;
			}

			
			//In case of 2 - way partitioning Anchor element is the lowest value in high - section.
			int PartitionInTo2Parts(int src[], int start, int end, int PartitionValue)
			{
				int anchor = PartitionValue;

				int prevHighIndex = 0; //Used for finding high-value and once found it stays there until we swap with lower-value(found by currIndex) OR we hit the end of array.
									   //Do not incr if (value > Anchor). This stays at high-value.
									   //If the (value <= Anchor), look back if prevHighIndex has a valid index; if so swap(currItem, prevHighIndex);
#pragma region DebugX  
				cout << endl << "before partition " << endl;
				for (int i = 0; i <= end; i++)
					cout << src[i] << " ";
				cout << endl;


				cout << endl << "Anchor " << anchor << endl;
#pragma endregion DebugX 	
				for (int curr = 0; curr <= end; curr++)
				{
					//If the src[curr] is less than anchor then increase prevHighIndex and curr.
					//In otherword, prevHighIndex stops growing until it encounters a Value > Anchor.
					//So we can assume prevHighIndex is waiting at an index that has highValue and that needs to be swapped with low-value
					//So for every currItem, if the curr-value is 'lower' think about swapping it with [prevHighIndex]
					//prevHighIndex + 1
					if (src[curr] < anchor) 
					{
						if (prevHighIndex < curr)
							swap(src[prevHighIndex], src[curr]);
						prevHighIndex++;
					}
#pragma region DebugX 
					cout << endl;
					for (int i = 0; i <= end; i++)
						cout << src[i] << " ";
					cout << curr << " ";
					cout << endl;
#pragma endregion DebugX 
				}
				//prevHighIndex would be pointing to 1st value in high-value-section, and swap it with partition-value waiting at [end]
#pragma region DebugX  			
				cout << endl << "after partition " << "partition value: " << anchor << "partitionIndex: " << prevHighIndex << endl;
				for (int i = 0; i <= end; i++)
					cout << src[i] << " ";
				cout << endl;
#pragma endregion DebugX 
				return prevHighIndex;
			}

			
	};

};