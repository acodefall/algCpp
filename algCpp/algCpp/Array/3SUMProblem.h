#pragma once
/*
	 Problem:
	 Find all unique triplets in a set which gives the sum of zero.
		For example, given set S = {-1 0 1 2 -1 -4},
		One possible solution set is:
		(-1, 0, 1)
		(-1, 2, -1)

	Solution 1
	3SUM problem
	We are given N number, and asked to list all the combination of width 3, who's sum becomes equal to X.
	3SUM method solves this in (N ^ 2) time.
	https://en.wikipedia.org/wiki/3SUM#Quadratic_algorithm


	Solution2
	Knapsack problem can be tweaked to solove this also.

	http://www.techiedelight.com/find-triplet-given-with-given-sum/
	https://www.cpp.edu/~ftang/courses/CS240/lectures/recursion.htm
	https://www.cs.rochester.edu/u/hliao6/projects/combinatorial_optimization/final_project.pdf
*/


#pragma once
#include <iostream>
using namespace std;

namespace ThreeSumProblemNM  //@RED20170616002
{
	/*
		http://blog.gainlo.co/index.php/2016/07/19/3sum/
		3SUM problem overview_20170616001
			Given an array we have to find the 3 elements who's sum is 0 or K. There is also a problem called 2SUMProblem, and this adds two elements only. 3SumProblem can be solved using either Bruteforce or 3indexes.

		
		3SUM problem using 3indexes_20170616002
			This uses three indexes(currItemIndex, startIndex, endIndex). 
			currItemIndex points to the stable member of the trio, startIndex, endIndex refers to the elements that we try out (by adding in to currItemIndex). Ex: currItemIndex is stable at 3, we vary startIndex, endIndex from [3+1] to [Last Index], and compute the sum and check if the sum is 3. currItemIndex is like an iterator to scanning the src array goes from 0 to N-2.
			Where is initialized to [currItemIndex+1], and endIndex is initialized to Max.			

			Program will have Outer ForLoop that scans the src array, uses currItemIndex as index(0 to Max). Then it starts a inner while loop to vary startIndex and endIndex. Before starting the inner While loop startIndex is set to 1, and endIndex is set to Max. Then an inner whileloop starts, and it compares the 'sum of the trio' against K, and appropriately manipulates either startIndex or endIndex, but not the both at same time. To understand the manipulation logic, keep in mind that Data is sorted, and startIndex can only INCREASE and endIndex can only DECREASE because they are already at the extreams.
			If (trio-sum > K)
				reduce endIndex; //that is because we want to reduce the sum, and we can not move startIndex backwards.
			If (trio-sum < K)
				increase startIndex; //that is because we want to increase the sum. And we can do that by increasing startIndex. We can not move the endIndex backward because it could be at Max point.
			 
			 If the (trio-sum == K)
				We found a sequence that is 0. Record the sequence.
				decrease endIndex; 
				Continue to find next match.

				for(iterates src[I])
						{
							while( st < end)
							{
								if(i + end + start == 0)
								{
									//we found a combination that is 0
									end--;
								}
								else if(i + end + start > 0)
									//Sum is high and needs reducing, so reduce endIndex
									end--;
								else 
									//Sum is Low and needs increasing, so increase startIndex
									start--;
							}
						}
			Inner while loop goes as long as (startIndex < endIndex). All along, currItemIndex stays constant.
			Once the inner loop ends, currItemIndex moves to the 1st element, and whileLoop starts again, looking for the match that makes the sum K.
			
				Steps for 3SUM problem using 3indexes_20170616003
			a) Start a ForLoop to iterate src[], and use currItemIndex as index
			b) Inside ForLoop, 
				set startIndex = currItemIndex + 1
				endIndex = Max
			c) Start a While Loop to go until
				while( startIndex < endIndex)
			d) Sum up the trio.
				If the (trio-sum > K)
					reduce endIndex; //that is because we want to reduce the sum.
				If the (trio-sum < K)
					increase startIndex; //that is because we want to increase the sum. And we can do that by increasing startIndex. We can not move the endIndex backward because it could be at Max point.
			 
				If the (trio-sum == K)
					We found a sequence that is 0. Record the sequence.
					decrease endIndex; 
					Continue to find next match.

			Note that whileLoop manipulates either startIndex or endIndex, not both at the same time.
			Once the WhileLoop ends, move the currItemIndex to 1. Do this until, currItemIndex hits the end.


	Steps for 3SUM problem using BruteForce_ 20170616004
		a) Start three nested ForLoops
			1st one goes from (0 to Len -2)
			2nd one goes from (i+1 to Len -1)
			3rd one goes from (j+1 to Len)
		b) Inside 3rd Loop, check if the Trio sum is 0, if so print it

	*/
	class ThreeSumProblem
	{
		public:
				void Call3SumProblem()
				{
					int src[] = { -25, -10, -7, -3, 2, 4, 8, 10 };
					cout << "\r\n";
					cout << "calling Do3SUM()";
					cout << "\r\n";
					Do3Sum(src, 8);

					cout << "\r\n";
					cout << "calling Do3SumBruteForce()";
					cout << "\r\n";
					Do3SumBruteForce(src, 8);
				}

				void Do3SumBruteForce(int src[], int srcLen)
				{
					for (int i = 0; i < srcLen - 2; i++)
					{
						for (int j = i+1; j < srcLen - 1; j++)
						{
							for (int k = j; k < srcLen; k++)
							{
								if (src[i] + src[j] + src[k] == 0)
								{
									cout << "\r\n";
									cout << "Found the 3SUM numbers";
									cout << " " << src[i] << " " << src[j] << " " << src[k];
								}
							}
						}
					}
				}

				void Do3Sum(int src[], int srcLen)
				{
					
					for (int i = 0; i < srcLen - 3; i++)
					{
						int a = src[i];
						int stIndex = i + 1;
						int edIndex = srcLen - 1;
						
						//
						while (stIndex < edIndex)
						{
							int b = src[stIndex];
							int c = src[edIndex];
							if ( a + b + c == 0)
							{
								cout << "\r\n";
								cout << "Found the 3SUM numbers";
								cout << "a: " << a << "b: " << b << "c: " << c;
								edIndex--;
							}
							else if (a + b + c > 0)
							{
								edIndex--;
							}
							else
							{
								stIndex++;
							}
						}
					
					}
				}
	};
};