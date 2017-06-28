#pragma once
#include <iostream>
#include <math.h>
#include "BinSearchBase.h"
using namespace std;
using namespace BinSearchBaseNM;
namespace BinarySearchSizeUnknownNM
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
			In traditional binary search, when the array size is known, we divide the array in to two parts and go in to either left-half or right-half. Key point is partition-count grows by "power of TWO". That is something like: 1, 2, 4, 8, 16		

			When array size is unknown, we first try to detect the array boundary, by reading the values at partition indexes like 1, 2, 4, 8, 16. We do not read in between the partitions. We expect the runtime to throw an exception when partition-index is outside array boundary. The array boundary being tested grows by "power of 2".
			We first access src[2^0], if there is no exception then access src[2^1], then try src[2^2].
			Say we are at partition-index-16.
			When we try to read src[16], we can expect three outcomes.
			a) Index-16 may have the Value that we are looking, then retrun the current-patrtition-index; no adventure is needed.
			b) Value at Index-16 could be higher, in that case launch a traditional Binary, to search as if we know the size.
			   Search window is between Index-8 and Index-16, so srcLen is 8, and search starts at 'address of src[8]'.
			   When the search function returns, return "Index-8 + retvalue" to caller.
			   
			c) Accessing Index-16 may throw an exception. It means array size boundary is some where in between 16 and 8.
			   Then initiate a traditional binary search but the function should handle exception. Pass 'addrsss of src[16]' and 'length as 32-16'
			Function may recieve exception when it accesses src[mid]. In response, it should next go in to left-half by setting 
						   "end = mid-1".
			Once the search function returns, return "Index-8 + retvalue" to caller.
		
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