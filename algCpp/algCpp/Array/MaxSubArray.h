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
namespace MaxSubArrayNM //@RED20170714012
{
	/*
        Max SubArray Problem Kadan's method_20170714012
			Given an array having +ve and -ve numbers, we have to find the continuous sequence of numbers who's cumulative sum is highest.
			Say first 4 numbers are +ve numbers; next 2 numbers are -ve numbers; 
			and next 6 numbers are also positive. Now we have two sequeces of +ve numbers, and we have to find the one that gives 
			highest cumulative sum. 
			This can be solved using Iteration and also using Dynamic programming
			
			Solution is as follows. 
				Traverse the array, and as you are traversing maintain the CumulativeSum and MaxOfCumulativeSum.
				CurrentItem will be added to existing CumulativeSum, only if the resulting sum is going to be HIGHER than 'CurrentItem alone'.
				Ex: CumulativeSum = -10 and CurrentItem = 2. Then we do not add 2 to -10, instead we 2(CurrentItem) will be come Cumulative sum.
				Otherwise, CurrentItem will ignore the existing content of CumulativeSum, and simply assigns itself to CumulativeSum, instead of ADDING itself to CumulativeSum.
				This is joinging the party or going alone. When currentItem goes ALONE, it marks the begginning of new 'Sequence Of Sums'.

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
			/*
				Solution Array will give the MAXIMUM Sum until that index.
				Ex: Sol[5] gives MAXIMUM Subaary sum for first 5 elements.
				SOl[6] could be constructed in two ways. 
						Sol[6] = Sol[5] + [currItem] if sum > [currItem]
						Else Sol[6] = [currItem]
			*/
			int MaxSubArrayDyn(int src[SIZEX])
			{
				int MaxSubArrayValue = 0;
				int Sol[SIZEX] = { 0 };
				Sol[0] = src[0];
				for (int i = 1; i < SIZEX; i++)
				{
					//Use the prev-solution only if that is going to enhance the SUM, otherwise ignore the prev-solution. 
					//Assign CurrItem directly to Solu[]
					if (Sol[i - 1] + src[i] > src[i]) //Use the prev-solution only if that is going to enhance the SUM, otherwise ignore the prev-solution. 
						Sol[i] = Sol[i - 1] + src[i];
					else  //Assign CurrItem directly to Solu[]
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