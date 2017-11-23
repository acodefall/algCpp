#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace InplaceMergingOfSortedArrayNM
{
    /*
		Inplace Merging of sorted array_20170722010
			We take two sorted arrays and rearrange their contents, so that one array will have just higher numbers, and other will have just lower numbers.
			When the arrays are placed right next to each other, numbers will be in ascending order. Array size will stay the same.
			Logic is... designate one of the array as high-arry and move all the high numbers to it. 
			Say both the arrays are 5 elements long. 
			Compare 5th element of high-array with 5th element of low-array.
			Then compare 4th element of high-array with 5th element of low-array.
			Then compare 3rd element of high-array with 5th element of low-array.
			Do this in a loop until we reach the eand of high-array.
			After each comparison 
				-If the hight-array's value is smaller, then swap values, so larger value goes to high-array. 
				 This swapping could have spooiled sorting order in low-array, so do an insewrting sort.
	 
				-If the high-array's value is large, then do not do anything because larger value is in high-array. 
	
			We compare the values at max end because Large numbers sit at the max-end of the array 
			During comparison we always compare against the max-end of low-array because we want to MOVE 
			the max value in low-arry to high-array. And max-value sits at max-index because array is sorted.

			if(high[max] < low[max])
					SWAP(high[max], low[max])
						SORT(low[]);
			If high[maxindex] is indeed higher than low[maxIndex], leave that alone and try comparing high[maxindex-1] with low[maxIndex]
				if(high[max] > low[max])
					if(high[max-1] > low[max])
						if(high[max-2] > low[max])
							LEAVE LEAVE
								.........
			Note: We want to make sure every element of high[] is larger than the low[Max] so we move the cursor on High[] but keep the low[] cursor pointing at low[Max], all the time. low[max] is used because that is where the max-value in low[] sit, and we want to check whether they can be moved to high array.
		  
			Swapping elements between high[] and low[] will not spoil the sorting of high-array because we replace the larger element with more-larger element. But swapping could have spoiled the sorting order of low[]. The element that we put in to low-array could be too small to sit at max-index, so this element needs to be moved to LEFT. We use Insertion sort to place that element at right index. Note that we do not want to sort the whole array, instead we just want to place that one element.

 

		Merge two SORTED arrays so that Larger and Smaller values end up in different arrays 

		low[]:     3  16 150       //Lost slot in low[] is always supposed to have the highest element within low[], and  
				   0   1   2	  //this is a potential candidate for swapping with high[maxIndex], high[maxIndex - 1], high[maxIndex - 2]
									   //So check whether this element can be SWAPPED with high[]
           

		high[]:    1  31  39        //We designate that THIS array will hold Larger elements (we could selected low[] but we did not)
				   0   1   2         //First step in program is to designate one of the array as a resident for larger elements.
           
		FLOW

		   {3 16 150}  {1  31 39}                       //Compare [maxIndex] from both array
				  (low[2] > high[2])    (150 > 39) 
				  swap low[2](39) and high[2](150)  
			 post-swapping:	{3 16 39}  {1  31 150} 
				  Sort the low[] but it won't do anything because '39' is at appropriate slot    

		   {3 16 39}  {1  31 150}                     //one cursor moves to high[maxIndex -1] but other stays at low[maxIndex] 
															   //this is because low[maxIndex] is supposed to have highest  element within low[]
								   //This is a potential candidate for swapping with high[maxIndex - 1]
				  (low[1] > high[2])    (16 > 150) 
				  swap low[1](16) and high[2](150)
				  post-swapping:	{3 16 31}  {1  39 150} 
				  Sort the low[]...

		   {3 16 31}  {1  39 150}                   //now   high[maxIndex -2] v/s low[maxIndex]
				 (low[0] > high[2])    (3 > 150)
				 swap low[0](3) and high[2](150)
				 post-swapping:	{3 16 1}  {31 39 150} 
				 This time SORTING required
				 Post sorting             {1  3 16}  {31 39 150} 
 

		Output
		   low[]:    {1,  3, 16}   
		   high[]:   {31, 39, 150} 
	
	       
	
      
     */
	const int SIZEX = 3;
    class InplaceMergingOfSortedArray
    {
     
	 
		public:
				void callInplaceMergingOfSortedArray()
				{
					int low[SIZEX] = { 3, 16, 150 };
					int high[SIZEX] = { 1, 31, 39 };

					cout << "low[]" << endl;
					stringstream ss;
					for (int i = 0; i < SIZEX; i++)
					{
						cout << setw(4) << low[i];
						ss << setw(4) << i;
					}
					cout << endl;
					cout << ss.str() << endl << endl;

					cout << "high[]" << endl;
					stringstream ss1;
					for (int i = 0; i < SIZEX; i++)
					{
						cout << setw(4) << high[i];
						ss1 << setw(4) << i;
					}
					cout << endl;
					cout << ss1.str() << endl;
				   
					for (int i = SIZEX - 1; i >= 0; i--)
					{
						
						if (low[SIZEX - 1] > high[i])
						{
							cout << "(low[" << i << "] > high[" << SIZEX - 1 << "])    (" << low[i] << " > " << high[SIZEX - 1]<< ")" << endl;
							swap(high[i], low[SIZEX - 1]);
							cout << "swap low[" << i << "](" << low[i] << ") and high[" << SIZEX - 1 << "](" << high[SIZEX - 1] << ")" << endl;
							
							//print the content of low[] after swapping(could be unsorted state)
							cout << "low[post swapping] :";
							for(int k = 0 ; k < SIZEX; k++)
							{
								cout << low[k] << " ";
							}
							cout << endl;
							
							//Sort the low[] using insertion sort
							//Do insertion sort on S1[] and ValueToBeInserted in Si[Max]
							int swappedValue = low[SIZEX - 1];
							int k = SIZEX - 1;
							while ( (k > 0) && (swappedValue < low[k-1]))
							{
								low[k] = low[k-1]; //Copy to RIGHT
								k--;
							}
							if (k < SIZEX - 1)
								low[k] = swappedValue;
						
							//print the content of low[] after swapping, sorting
							cout << "low[post sorting] :";
							for(int k = 0 ; k < SIZEX; k++)
							{
								cout << low[k] << " ";
							}
							cout << endl;
						}
						else
						{
							cout << "(low[" << i << "] < high[" << SIZEX - 1 << "])   (" << low[i] << " < " << high[SIZEX - 1]<< ")" << endl;
							cout << "do not do anything..compare next item" << endl;
						}
					}
				}
    };
};