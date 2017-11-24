#pragma once
#include <iostream>
#include <math.h>
#include "BinSearchBase.h"
using namespace std;
using namespace BinSearchBaseNM;
namespace BinarySearchSizeUnknownNM //@RED20170618001
{
	/*
		Binary search in a sorted array when size is unknown Binary Search Theory_20170618001
			Searching in general is like selecting one item among N choices. Binary search algorithm reduces the pool-size(being searched) by a factor of TWO, in every iteration. There will be Log2N iterations.
						If Log2N = X, then Log2N = (2 ^ x) 
			
			Iterations are also known as levels in the Binary Search TREE. Number of partitions will double for each level, so the number of items carried by each partition will reduce, so the item-pool that we are searching-in will also reduce.
			Root of the tree will have all N items in one single pool/partition. 1st level will have two pools/partitions of size N/2
			2nd level will have 4 pools/partitions of size N/4. At every level, if you add up the items stored in every partition, the total number of items will remain same. Total items remains same but partition count keeps on growing, until each partition has just one item; and this is where TREE ends.

			Key point is partition-count grows by "power of TWO". That is something like: 1, 2, 4, 8, 16			
			
		Binary Search When size is not known details_20170618002
			When the size of the array is known, BS will create new Partition boundaries at indexes corresponding to POWER-OF-2. 
			Ex: If the array size is 16, 1st boundary comes at 8. Next boundary comes at 4;
			next one comes at 2. 
			
			When the array size is unknown, partition index goes from low-high. That is 2, 4, 8....
			Look for the VALUE(being searched) only by reading the values stored at partition indexes like 2,4,8,16. 
			There could be 4 possibilities
			-value is matches
			-value is low-high
			-value is hight
			-we overshot the array.
			
			If the value stored at partition index MATCHES the value being searched, then end the search.
			
			If  the value is MORE THAN the value being searched, then do a traditional binary search in the previous partition. 
			Ex: Current partition index is 16.
			Then do a traditional binary search in 8-16 range.

			If  the value is LESS THAN the value being searched, then poke the next partition-index. 
			Ex: Current partition index is 16, then check 32. Array may not be not 32 elements long so be ready to handl exception.

			
			Last possibility is ....
			If there is an exception, array shorter than what we think it is.  If exception comes at index=16, it means array ends somewhere in between 8-16.
			So do a raditional binary search just within 8-16. Code should handle exception and incase exception, always make left-turn.
			Ex: Say M = 14, and this gives exception, in the next round explore the Left-side of "14".
			
			Coming to implementation
			-Have two function, one for checking ONLY the partition indexes, and other for doing 'traditional binary-search-function'.
			Partition-check-function checks the value stored ONLY at partition indexes. It increases the partition-indexes  by 'power of 2' that is 2, 4, 8
			This function MUST handle EXCEPTION, and launches the 'traditional binary-search-function'.
			
			'traditional binary-search-function' computes M-index and makes left and right turns. This should handle EXCEPTION, and in case of 
			exception, it should make left turn.
			
		
		Steps for Binary search in a sorted array when size is unknown_20170618003
			a) Parameters are int* and Value
			b) Declare powerOfTwo, currIndex, prevIndex.
				powerOfTwo goes from 0,1,2,3...
				currIndex will have the partition-index being tested (2,4,8,16... ) - 1
				prevIndex will have previous partition-index.
				currIndex is generated using "pow(2,powerOfTwo) - 1".
			In every round we increment powerOfTwo by one
			
			c) start a while(TRUE)
			d) Have a Try{} Catch{} block inside WhileLoop
				prevIndex = currIndex;
				
				//compute next partition-index
				currIndex = pow(2, powerOfTwo) - 1;

			e) 
				if (src[currIndex] == Value)
					return currIndex and exit
			d)  
				if (Value < src[currIndex])
				Launch a Traditional Binary search within current previous-partition-index and current-part-index.
				Pass src[prevIndex] and 'currIndex - prevIndex'
				When the function returns, return "prevIndex + retValue" to caller.
				
				if (Value > src[currIndex])
					Increment the powerOfTwo, so that we can generate next priotion-index
					
			e)  if there is exception, our partition index is too high, launch a traditional binary search between previous-part-index and current-part-index.
			Pass src[prevIndex] and 'currIndex - prevIndex'
			Function may recieve exception when it accesses src[mid]. In response, it should do the next go in to left-half by setting 
							"end = mid-1".
				When the function returns, return "prevIndex + retValue" to caller.

	*/
	class BinarySearchSizeUnknown
	{
		public:
				void callBinarySearchSizeUnknown()
				{
					cout << "\r\n" << " Calling BinSearchUnbounded()" << "\r\n";
					int src[14] = { 4, 6, 8,  45,52, 67,  298 ,  408, 518, 760, 894, 913,  963, 1093 };
					int ret = BinSearchUnbounded(src, 67); ///5
					cout << "\r\n" << " Called BinSearchUnbounded() " << ret <<"\r\n";
				
					ret = BinSearchUnbounded(src, 963); ///12
					cout << "\r\n" << " Called BinSearchUnbounded() " << ret << "\r\n";
				
				}

			/*Binary Search tree has LogN levels.
				LongN = x = (2 ^ x).
				So we also*/

				//Go searching in forward direction only, but jump at the same rate as BinarySearch.
				//Binary search jumps 50% of total length. Ex: If the size is 10, hops are 5, 2, 1
				//Here we start from 0 and go as 1, 2, 4, 8, 16. ((2^0), (2^1), (2^2)....) Increment the "power of 2"
				int BinSearchUnbounded(int* src, int Value)
				{
					
					int powerOfTwo = 0; //give (2^0) = 1
					int currIndex = 0; //This goes as follows(subtract 1) 0, 1, 2, 4, 8, 16, 32, 64. It does NOT look at the intermediary indexes. This is soley done to find out the boundary.
									   //Once we know the range, then we come to know the length of that window. Then do the traditional Binary search.
					int prevIndex = 0;

					while (true)
					{
						try
						{
							prevIndex = currIndex;
							
							//increement the (2^0), (2^1), (2^2)
							currIndex = pow(2, powerOfTwo) - 1;
							
							////SPECAIL////
							//Run time will not throw exception when we READ/WRITE outside arrayboundary,
							//so throw the exception artificially by checking array boundary ourself
							if (currIndex > 14)
							{
								exception e;
								throw e;
							}
							////SPECAIL ENDS////
							if (src[currIndex] == Value)
							{
								cout << "\r\n" << "BinSearchUnbounded() found (" << Value << ") the value at currIndex: " << currIndex  << " powerOfTwo: " << powerOfTwo << " \r\n";
								return currIndex;
							}
							else if (Value < src[currIndex])
							{
								//Value is less, and it must be in previous window say 32 - 64.
								//Now go inside that window and do traditional binarySearch
								
								BinSearchBase objBinSearchBase;
								int srcLen = currIndex - prevIndex;
								cout << "\r\n" << "BinSearchUnbounded() Value (" << Value << ") the value at currIndex: " << currIndex << " prevIndex: " << prevIndex << " powerOfTwo: " << powerOfTwo << " srcLen: " << srcLen << " \r\n";
								int retvalue = objBinSearchBase.BinSearchPtr(&src[prevIndex], srcLen, Value);
								cout << "\r\n" << "BinSearchUnbounded() returned Value " << retvalue << "\r\n";
								return retvalue + prevIndex;
							}
							else if (Value > src[currIndex])
							{	//Increment the partition-index
								powerOfTwo++;
							}
						}
						catch (...)
						{
							
							//We are outside the array size, go back from (currentIndex - 1) to PreviousIndex
							BinSearchBase objBinSearchBase;
							int srcLen = currIndex - prevIndex;
							cout << "\r\n" << "BinSearchUnbounded() Exception Value (" << Value << ") the value at currIndex: " << currIndex << " prevIndex: " << prevIndex << " powerOfTwo: " << powerOfTwo << " srcLen: " << srcLen << " \r\n";
							int retvalue = objBinSearchBase.BinSearchException(&src[prevIndex], srcLen, Value);
							cout << "\r\n" << "BinSearchUnbounded() Exception returned Value " << retvalue << "\r\n";
							return retvalue + prevIndex;
						}

					}


				}



	};
};