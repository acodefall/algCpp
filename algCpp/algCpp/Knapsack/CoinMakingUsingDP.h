#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
namespace CuttingRodNM
{
	/*

	CuttingRod Problem_20170609008
		ProgrammingYou are given some denominations of coins in an array (int denom[])and infinite supply of all of them. Given an amount (int amount), find the minimum number of coins required to get the exact amount. 

		//hxxps://medium.com/@pratikone/dynamic-programming-for-the-confused-rod-cutting-problem-588892796840
		Probem: A rod needs to be cut in to pieces so that total profit is maximum. Price varies from length to length. We should compute the subset of pieces that generates maximum profit and also the Max profit itself. Assume the length of pieces is a number series like 1,2,3…. So Input data for 10feet rod is Price[] and Length[] of length 10.
	
			This problem can be solved using 3 methods
			a) PERMUTATIONS method
			b) Recursion method
			c) DP method


	Cutting Rod Solution using DP_20170609010
		A Rod of length 4ft can be cut in to 4 different sizes(1ft, 2ft, 3ft and 4ft), and DP tries to find the combination that generates max revenue. Problem input is Price[] of length 4, where index is the length of the piece.
		DP constructs a solution array of length 5, and expects the max revenue to be at the 5th index.
		DP introduces introduce 1ft rod in to pool. Price for 1ft will be in Price[0]. DP computes max-revenue for it and stores the solution in Sol[1].
		Then DP introduces 1ft and 2ft pieces in to pool. Price for 1ft will be in Price[0], Price[1]. Then DP computes max-revenue for this using Price[0], Price[1] and their corresponding solution namely Solution[0]and Solution[1]. Max revenue for pool of “1ft and 2ft” pieces will be stored in Solution[2].

		Complexity is O(n ^ 2).  16 for 4 feet rod.

		Cutting Rod Solution using DP Details_ 20170609011
		DP starts with pool with 0 rods and solution for it is stored in Solution[0].
 
		Then DP introduces 1ft piece in to pool, and also assumes that total length of rod is 1ft. Since there is only one rod in pool, the best revenue is in src[0], and it will be stored in Solution [1].
 
				int price1[1] = { 1};
				int lengths1[1] = { 1};
				Solution[0] = 0.
				Solution[1] = 1;

		Then DP introduce 2ft rod in to pool, and assumes total rod length to be 2ft. src[0], src[1] provides the price for 1ft and 2ft rods. 2ft rod can be sold as "one 2ft rod" OR "two 1ft rods". DP computes the price for these as follows.
		Price of "one 2ft rod" comes from "src[1]"
		Price of "two 1ft rods" is computed by adding the "price of 1ft rod stored in src[0]" + solution[1];
		Then store the Best price in Solution[2]. Now Solution[2] contains the best price when pool has one 1ft rod and 2ft rod.
				int price1[2] = { 1, 5};
				int lengths1[2] = { 1, 2};
				Solution[2] = 5;
				Solution[1] = 1;
				Solution[0] = 0.
							
		Then DP Introduce the 3ft rod in to pool, and assumes total length is 3. Then src[0], src[1] and src[2] provides the price for 1ft, 2ft and 3ft rods. 3ft rod can be sold as "one 3ft rod" OR "three 1ft rods" OR “one 1ft and one 2ft rod” OR “two 1ft and one 2ft rod”. DP computes the price for these as follows. Note that we do not have “three 1ft rods”; I think that is because Cutting rod is a 1-0 Knapsack Problem where we can not have more items of same type.


		Then compute the maximum price for each of the combination as follows.
		Now src[] will have 3 elements: price-for-1ft, price-for-2ft and price-for-3ft
		-Add src[0](the price of 1ft rod) to Sol[2](the price of 2ft rod), and this gives the price for "1ft + 2ft" combo
		src[0] + sol[2] = "1ft + 2ft" 
		-Add src[1](the price of 2ft rod) to Sol[1](the price of 1ft rod), and this gives the price for "2ft + 1ft" combo
		-src[2] has the price for 3ft rod and use it as it is. 
		Compare the three values and chose the highest value, and store it in Solution[3].
				int price1[3] = { 1, 5, 8};
				int lengths1[3] = { 1, 2, 3};
                        
				Solution[3] = 8; //Max ("src[1] + sol[2]", "src[1] + sol[1] + sol[1]", src[3]); 
		
				//These we already KNOW
		Solution[2] = 5; //Max ("src[1] + sol[1]", "src[2]"); 
				Solution[1] = 1; //Max ("src[0]", "src[2]"); 
				Solution[0] = 0.
				
		Repeat the above steps 10 times, if the rod length is 10.
		Finally, maximum value will be stored in last element of Solution[last-element].

		Steps for Cutting Rod using DP
			1) Parameters are price-array and its length
			2) Initialize the Solution[0] to 0.
			3) Then start a Forloop that iterates src-array from 0 to srcLen,  and this loop introduces one-piece at time in to Pool.
			4) Then start an inner ForLoop for computing the price each of the combinations for the Pool set up by outer ForLoop.
			When outer loop’s index is 1, then innerLoop computes price for one combinations and stores the output in Sol[1]
			When outer loop’s index is 3, then innerLoop computes price for 4 combinations, using 4 loops, and picks the combination with highest revenue as winner and stores it in Sol[3]

			5) Innerloop has most interesting implementation. It uses to mirror-indexes for iterating Solution[] and Src[]. It iterates src-Forward index iterates Src[] from 0 to IndexOfOuterLoop, and ReverseIndex iterates Solution[] from IndexOfOuterLoop to 0. Reason is we want to add mirroring elements.
			For example: If the pool has 1ft, 2ft, 3ft rods.
			Price for “one 1ft and one 2ft combo” can be generated by adding Src[0] and Sol[2]
			Price for “2ft and one 1ft combo” can be generated by adding Src[1] and Sol[1] 
			Price for “one 3ft combo” can be generated by adding Src[2] and Sol[0] 
			Loop maintains the Max Revenue in gblMax, and loads it in to Solution[] after exiting from forLoop. 

			5) Once out of both the loops, Solution[srcLen] gives the best price.

			Complexity is O(n ^ 2).  16 for 4 feet rod.
	*/
	class CuttingRod
	{

		public:
				void CallCuttingRod()
				{
					                
					int price1[4] = { 1, 5, 8, 9};
					int lengths1[4] = { 1, 2, 3 ,4};
					int max = 0;
					

					cuttingRodUsingDPX(price1, lengths1, 4); //10
					int mx = CuttingRodUsingRecursion(price1,4);
					profitDP(price1, 4);
					
					int price2[8] = { 1, 5, 8, 9, 10, 17, 17, 20};
					int lengths2[8] = { 1, 2, 3 ,4, 5, 6, 7, 8};
					cuttingRodUsingDPX(price2, lengths2, 8); //22
					int mx1 = CuttingRodUsingRecursion(price2, 8);
					profitDP(price2, 8);

					int price3[5] = { 2, 3, 7, 8, 9 };
					int len = 5;
					
					profitDP(price3,5);
				
				}

				/*
					Cutting Rod using Recursion, how combinations are generated?_20170610001
						For 3ft Rod we generate combinations using mirroring technique. Run a counter that goes from 0 to 2, and at every step substract the counter from 3. The Counter and Result of substaction gives the combination.
							a) 3-1 = 2. We can make 3 by adding 1 and 2
							b) 3-2 = 1. We can make 3 by adding 2 and 1
							c) 3-3 = 0. We can make 3 by adding 3 and 0
						CuttingRod recursion genertes above combinations using ForLoop. This types of combinations also expresses the 3ft in what we already readily know. That is, since we know the price for 1ft, 2ft and 3ft, make 3ft out of "1ft + 2ft", and “2ft+ 1ft”, but not out of "1ft + 1ft + 1ft".
			
						Coming to the recursion function itself, a ForLoop splits the 3ft rod in to 1ft, 2ft and 3ft rods.
						When i = 1ft, we readily know the the price for 1ft(this is stored in Price[]) but we also want to know the price for other 2ft, so that sum becomes 3ft. To know the price for 2ft, we call the recursion function with 2ft as size. Once that recursion returns we know the price for 3ft in terms of "1ft and 2ft".

						When i = 2, we fetch the readily available price for 2ft rod from Price[2]. Then make a recursion call to know the price for 
						other 1ft. When the recursion returns, we know the price for making 3ft using "2ft and 1ft"

						When i = 3, we fetch the readily available price for 3ft rod from Price[3]. We know the price of 0ft, make a recursion call for 0ft, and it comes back with 0.

						Now the ForLoop was able to construct 3ft using price-of-1ft, price-of-2ft and price-of-3ft, and ForLoop also tracks the maximum price among these 3. So when ForLoop ends we know the price of best combination for making 3ft.

						When we call Recursion function with 2ft rob. Recursion call will inturn divide the 2ft rod in to combination of “one 2ft rod” and “two 1ft Rods”. Then returns us the best price among the combination for 2ft. This alogorithm is inefficient because Recursion(2ft) gets called for, 3ft rod, 4ft rod and 5ft rod. So we process the same data again and again.

						Steps for CuttingRod using Recursion_20170610002
							a) Input parameters are RodLen and Price[]
							RodLen is the length of the Rod to be cut in to pieces. If RdLen is 3ft, we cut it in to 1ft, 2ft, 3ft using For Loop.
							ForLoop goes from (0 to < RdLen)

							c)	ForLoop generates combinations like “2ft and 1ft” and “1ft and 2ft”. Given a combination,  view the elements of combinations as 1stPart and 2ndPart(say in “2ft and 1ft” combination, 2ft is 1stpart and 1ft is 2nd part. Price for 1st part comes from Price[], and price for 2nd part comes from Recusion call. Once the recursion ends, we sum the both and compare against gblMax to check whether the sum is Maximum of ALL the combinations of making 3ft.
							d)	 
							PriceForFirstPart = srcPrice[i]; //This is pulled from the readily available Price[]
							PriceForSecondPart = CuttingRodUsingRecursion(RodLen - (i + 1), srcPrice); 

							Recursion parameter is remaining length of Rod(that is after removing 1stPart from TotalLen). 
							Recursion expects RodLen as COUNT but ForLoop uses index, so we add 1 to i

							e)		PriceForFirstPart is recorded in PreRecursion phase. PriceForSecondPart comes from PostRecursion phase.			
							int TotalPrice = PriceForFirstPart + PriceForSecondPart;

									if (gblMax < TotalPrice)
										gblMax = TotalPrice;
							f)	Once out of forLoop, return gblMax to caller. This is the best price among all combos.
							g)	If the RodLen is <= 0, then retun 0.
							h)	Note: Here Recursion is adding Post part and Pre part data, and records highest one.


				*/
				int CuttingRodUsingRecursion(int* srcPrice, int RodLen)
				{
					if (RodLen <= 0)
						return 0;
					else
					{
						int gblMax = INT_MIN;
						//Cut the 3ft rod in to
						//  0
						for (int i = 0; i < RodLen; i++)
						{
							//Len = i + restLen
							//    = Price for Length I + Price for RodLen -I
							//    = Price[i] + CuttingRodUsingRecursion(RodLen -I)
							
							int PriceForFirstPart = srcPrice[i]; //This is pulled from the readily available Price[]
							int PriceForSecondPart = CuttingRodUsingRecursion(srcPrice, RodLen - (i + 1)); //This is computed by calling Recursion
						

							int TotalPrice = PriceForFirstPart + PriceForSecondPart;

							if (gblMax < TotalPrice)
								gblMax = TotalPrice;
						}

						return gblMax;
					}
				}
			



				int cuttingRodUsingDPX(int* srcPrice, int* srcLens, int srcLen)
				{
					int solution[50] = { 0 };

					//DP requires that solution-array have one element even at the beginning
					solution[0] = 0; 

					
					
					//this Loop introduces the new elements in src-array. 
					//when i = 0, src-array has one element, and we compute solution[1]
					//when i = 1, src-array has two elements, and we compute solution[1]
					//solutionIndex = i + 1
					for (int i = 0; i < srcLen; i++)
					{
						//starting from 
						int maxSum = INT32_MIN;
						
						//This loop
						int solIndex = i;
						for(int srcIndex = 0; srcIndex <= i; srcIndex++)
						{
							maxSum = max(maxSum, solution[solIndex] + srcPrice[srcIndex]);
							solIndex--;
						}
						
						solution[i+1] = maxSum;
					}

					cout << "\r\n";
					cout << "Final value solution[" << srcLen << "]\r\n";
					return solution[srcLen];
				}


				int profitDP(int* value, int length) 
				{
					int* solution = new int[length + 1];
					solution[0] = 0;

					for (int i = 1; i <= length; i++) 
					{
						int max1 = -1;
						for (int j = 0; j < i; j++) 
						{
							max1 = max(max1, value[j] + solution[i - (j + 1)]);
							solution[i] = max1;
						}
					}
					return solution[length];
				}

				

	};
};