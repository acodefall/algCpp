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
Inplace Merging of sorted array_GN808
	In-place merging will take two sorted arrays, and rearranges the contensts, so that all higher values 
	goes to one array and lower values goes to another array. After merging we still have two arrays, just like before.
	Even the size will remain same. 
	Only difference is that higher and lower values are different arrays. Ex: 1-5 goes to 1st array and 6-10 geoes to second array.

	Merging logic will first designate one of the array as max-array
	Logic wants to make sure that content of max[] is higher.
	Since both the arrays are sorted we can assume that max values at higher-incex of the array.
	Logic compares the highest-element from max-array against the against the max element of low-array.
	If the low array's value is higher, then we swap the two. Now max-arry has largest item at its highest index.
		 if(high[max] > low[max])
			if(high[max-1] > low[max])
				if(high[max-2] > low[max])
					.........
					.........
		 if(high[max] < low[max])
			swap(high[max], low[max])
			sort(low[]);
			Swapping did not spoil the sorting of high-array because we replaced the larger 
			element with more-larger element.
			But swapping could have spoiled the sorting order of low-array. 
			The element that we put in to low-array could be too small to sit at max-index, so this element needs to be moved to LEFT. We use Insertion sort to place that element at right index. Note that we do not want to sort the whole array, instead we just want to place that one element.
			
			if(high[max-1] < low[max])
				In the subsequent rounds, compare high-array[max - 1] with low-array[max], and take appropriate action. Then compare high-array[max - 2] with lower[max]. Note: In every round, we compare against the low-array[max], and reduce the index of ONLY the high-array.
				We always compare against the max-index of low-array because that is where the max-value in low[] sits,
				and we want to check whether that is eligible to moved to high array.
	
	
		 
				 
			
			
			When we swap values between high-array and low-arry, we will disrupt the 
			sorted order in lower array so we have to resort using insertion sort. 
			
			
 
	
	       
	
	        Steps for Inplace Merging of sorted array_GN808
		        a) Start a ForLoop to scan higher-array S2.
			         for (int i = high.Len ; i >= 0; i--)
		        b) Compare  low[Len] and  high[i]
				        if (low[low.Length - 1] > high[i])
					        Swap low[Len] and  high[i].
					
				        Do insertion sort on S1, to place swappedValue at right position
						        int swappedValue = low[low.Len];
						        int k = low.Length - 1;
						        while ( (k > 0) && (swappedValue < low[k-1]))
						        {
							        low[k] = low[k-1]; //Copy to RIGHT
							        k--;
						        }
						        if (k < low.Length - 1)
							        low[k] = swappedValue;
				
				        If low[Len] is NOT larger than  high[i], then no need to swap.
				        Go to the next round of ForLoop

				
       oooo
      
     */
	const int SIZEX = 3;
    class InplaceMergingOfSortedArray
    {
     
	 
		public:
				void callInplaceMergingOfSortedArray()
				{
					int low[SIZEX] = { 3, 6, 150 };
					int high[SIZEX] = { 6, 31, 39 };

				   
					for (int i = SIZEX - 1; i >= 0; i--)
					{
						
						if (low[SIZEX - 1] > high[i])
						{
							cout << "(low[" << i << "] > high[" << SIZEX - 1 << "])  (" << low[i] << " > " << high[SIZEX - 1]<< ")" << endl;
							
							int tmp = low[SIZEX - 1];
							low[SIZEX - 1] = high[i];
							high[i] = tmp;

							cout << "swap " << low[i] << " and " << high[SIZEX - 1] << endl;
							
							//print the content of low[] after swapping(could be unsorted state)
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
