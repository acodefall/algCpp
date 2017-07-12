#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace MaxSubArrayNM
{
	/*
        Kadan's method 
			Given an array having +ve and -ve numbers, we have to find the continuous sequence of numbers who's cumulative sum is highest.
			Say first 3 numbers are +ve numbers; next 4 numbers are -ve numbers; 
			and next 6 numbers are also positive. Now we have two sequeces of +ve numbers, and we have to find the one that gives 
			highest cumulative sum. 
			This can be solved using Iteration and also using Dynamic programming
			
			Solution is as follows. 
				Traverse the array, and as you are traversing maintain the CumulativeSum and MaxOfCumulativeSum.
				CumulativeSum is constructed by adding currentItem to CumulativeSum, based on some logic, and the logic is as follows.
				CurrentItem will add itself to existing CumulativeSum, only the resulting sum is going to be HIGHER than 'CurrentItem alone'
				Otherwise, CurrentItem will ignore the existing content of CumulativeSum, and simply assigns itself to CumulativeSum, instead of ADDING itself to CumulativeSum.
				This is joinging the party or going alone. When currentItem goes ALONE, it marks the begginning of new 'Sequence Of Sums'.

				Say When cursor comes to 5, Cumulative sum will be holding the cumulative sum of first 4 elements.
				Now the 5th element can either ADD its value to CumulativeSum OR assign its value to CumulativeSum.
				By ADDING to CumulativeSum, element will be adding to PAST value; By assigning to CumulativeSum, 
				element to erasing the PAST value, and starts a new sequence of Cumulative sums.
				This ADDING and ASSIGINING decision is made based on following logic
					if('currentItem value' + CumulativeSum) >  'currentItem value')
						CumulativeSum = 'currentItem value' + CumulativeSum
					else
						CumulativeSum = 'currentItem value' //Ignore the Past history of Culumalative Sum
     */
	const int SIZEX = 8;
	class MaxSubArray
	{
		public:
			void callMaxSubArray()
			{
				int src[SIZEX] = { -2, -3, 4, -1, -2,1,5, -3 }; //{ 1, 2, -3, -4, 2, 7, -2, 3 };
				
				cout << "Kadane's method" << endl;
				
				for (int i = 0; i < SIZEX; i++)
					cout << src[i] << " ";
				cout << endl;
				
				int x = MaxSubArrayX(src);
				cout << "Sum " << x; //7

				int y = MaxSubArrayDyn(src);
				cout << "Sum " << y; //7
			}

		private:
			int MaxSubArrayX(int src[SIZEX])
			{
				
				int CumulativeSum = src[0];
				int MaxOfCumulativeSum = src[0]; //tracks maximum cumulative sum

				for (int i = 1; i < SIZEX; i++)
				{
					//cout << "CumulativeSum + src[" << i << "] " << CumulativeSum << " + " << src[i] << " = " << src[i] + CumulativeSum << endl;
					//cout << "compare " << src[i] << " & " << CumulativeSum << endl;
 					
					
					//CurrentItem will add itself to existing CumulativeSum, only the resulting sum is going to be HIGHER than 'CurrentItem alone'
					//Otherwise, CurrentItem will ignore the existing content of CumulativeSum, and simply assigns itself to CumulativeSum, 
					//instead of ADDING itself to CumulativeSum.
					if ((CumulativeSum + src[i]) > src[i])
					{
						CumulativeSum = CumulativeSum + src[i];
					}
					else
					{
						CumulativeSum = src[i];
					}
					//cout << "CumulativeSum  = " << CumulativeSum << endl;

					//cout << "MaxOfCumulativeSum & CumulativeSum " << MaxOfCumulativeSum << " " << CumulativeSum << endl;
					if (MaxOfCumulativeSum < CumulativeSum)
					{
						MaxOfCumulativeSum = CumulativeSum;
					}
					//cout << "MaxOfCumulativeSum " << MaxOfCumulativeSum << endl << endl << endl;

					
				}

				return MaxOfCumulativeSum;
			}

			int MaxSubArrayDyn(int src[SIZEX])
			{
				int MaxSubArrayValue = 0;
				int Sol[SIZEX] = { 0 };
				Sol[0] = src[0];
				for (int i = 1; i < SIZEX; i++)
				{
					if (Sol[i - 1] + src[i] > src[i])
						Sol[i] = Sol[i - 1] + src[i];
					else
						Sol[i] = src[i];
				}

				//to know the max sum we have to iterate the sol-array
				MaxSubArrayValue = Sol[0];
				for (int i = 1; i < SIZEX; i++)
				{
					if (Sol[i] > MaxSubArrayValue)
						MaxSubArrayValue = Sol[i];
				}
				
				return MaxSubArrayValue;
			}


	};
};