#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

namespace FindMissingNumberNM
{
	//@RED20170724008

	/*
		Find the first repeated element in an array by its Lower-index(or First Index)_GN72
	        Say array is {1, 12, 5, 12}, and 12 repeats.  
	        Question is should we scan from Beginning or from the End.
	        If we scan the array from beginning, we will see '12' at index-2 and also at index-4.
        By the time we reach index-4, we would have forgotten the first location if 12. So we have to remember the 1st occurrence in a variable so it is not efficient. So it is better to scan from the End.

	        If the question is to find the Higher-Index, then Scan from Beginning
	        If the question is to find the Lower-Index, then Scan from End

		Steps Find the first repeated element in an array by its Lower-index(or First Index)_GN72
            	-Declare a HashSet<>. (Note that HashSet keeps only one element, even if we insert the same element twice, 
                 so HashSet<> is made for checking 'if-item-exists', but not will not tell you how many times the item repeats)
     
	            -Scan the arry using ForLoop. Check Src[i] is in HashSet, if it is not present, add it.
     
	            -If the Src[i] is already in the HashSet, we found the duplicate INDEX. Exit the loop

	*/
	const int SIZEX = 6;
	class FindMissingNumber
	{
	public:

		void callFindMissingNumber()
		{
			int Src[SIZEX] = { 1, 2, 3, 4, 6, 7 };
			int ActualCumulativeSum = Src[0];
			int Max = Src[0];

			for (int i = 1; i < SIZEX; i++)
			{
				ActualCumulativeSum += Src[i];
				Max = max(Max, Src[i]);
			}

			int CumulativeSum = (Max * (Max + 1)) / 2;

			int MissingNumber = abs(CumulativeSum - ActualCumulativeSum);


			cout << "Actual Cumulative Sum " << ActualCumulativeSum << " Max Value " << Max << " CumulativeSum(using formula) " << CumulativeSum << " Missing Number  " << MissingNumber << endl;


			
		}

	};
};