#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
namespace CuttingRodNM
{
	/*

	General_0951_CuttingRod Problem_20170609008
		Probem: A rod needs to be cut in to pieces so that total profit is maximum. 
		Ex: 4ft rod can be sold as 2 + 2 or 3 + 1. We should compute which combo yields most money.
		
		This problem can be solved using 3 methods
			a) PERMUTATIONS method
			b) Recursion method
			c) DP method

	Cutting Rod using Recursion_20170610001
			Recursion method constructs various combinations using  Combinator technique, and computes the price for each one of them
			and picks up the one with MAX profit.
			Combinator technique generates combination for 4 using 1,2,3.
			Even in case of cutting rod problem, we want to do the same if the rod length 4.
			In addition to generating the combinations, we also want know their cost and pick the one
			with max profit.

			To understand this, let us creat 4ft by adding 1ft and 3ft.
			In this case caller will himself know the Price for 1ft; and makes the rec call for
			discovering the price for 3ft.
			Post recursion code will add 'price for 3ft' and 'price for 1ft'.
			Now we know the price for one combination.
			Similaraly price for 2 + 2 combo will be generated.
			And Max among them will be the max combo price.
			This method is inefficient because it recomputes the MAX price for same combination again and again.

			4 =          1            +          3
			'provided by caller'  + 'provided by recursion'

	General_0953_Cutting Rod Solution using DP_20170609010
		DP introduces one feet at a time, computes the best price for that length and stores the price in solution array. 
		For example: 
			DP introduces 1st feet. There is NO combo for 1ft so the price comes from Price[0] directly.
			sol[1] will have the best price for 1ft rod. 
			
			DP introduces 2nd feet. 2ft can be generated using either '1ft + 1ft' OR using '2ft' directly. Among the two prices, DP picks up the best value and stores it in sol[1].
			sol[2] has best price for 2ft rod. 2ft can be generated using 1ft + 1ft and also using directly 2ft. 
			
			DP introduces 2nd feet. 2ft can be generated using either '1ft + 1ft' OR using '2ft' directly. Among the two prices, DP picks up the best value and stores it in sol[1].
			sol[3] = BestOf('3' '2+1'  '1+2')
			sol[4] = BestOf('4'  '3+1'  '2+2' '1+3')
			
		
		DP computes prices for various combo using both Price[] and Solution[] as follows.
			For example when Rod length 4ft, compute the price for various combos of 4ft combo by taking the 'full-length price for 4ft', 'full-length price for 3ft' from Price[].
			Remaining price comes from Solu[]. 
			
				Take the price for 4ft full length rod from price[].
				Take the price for 3ft full length rod from price[] and price for 1ft from sol[] //we are adding best price for 1ft taken from history
				Take the price for 2ft full length rod from price[] and price for 2ft from sol[] 
		This can be coded using a single for-Loop with two indexes: SolIndex(0-3) and PriceIndex(3-0).
			Start the ForLoop that starts from Rod length and goes down to 0. 
			-this loop will add [0] & [3]  --combo1
								[1] & [2]  --combo2
								[2] & [1]  --combo3
								[3] & [0]  --combo4
								
			-sol[4] = Best of ( combo1 combo2 combo3 combo4)
							
		int bestPrice = MAX;
		for(srcIdx=3, solIndex=0; srcIdx >= 0; srcIdx++, solIndex++)
		{
			bestPrice = MAX(bestPrice, price[srcIdx] + sol[solIndex];
		}
		sol[4] = bestPrice;
		
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
					Cutting Rod using Recursion_20170610001
						Recursion method constructs various combinations using  Combinator technique, and computes the price for each one of them
						and picks up the one with MAX profit. 
						Combinator technique generates combination for 4 using 1,2,3.
						Even in case of cutting rod problem, we want to do the same if the rod length 4.
						In addition to generating the combinations, we also want know their cost and pick the one 
						with max profit.
						
						To understand this, let us creat 4ft by adding 1ft and 3ft. 
						In this case caller will himself know the Price for 1ft; and makes the rec call for 
						discovering the price for 3ft. 
						Post recursion code will add 'price for 3ft' and 'price for 1ft'. 
						Now we know the price for one combination.
						Similaraly price for 2 + 2 combo will be generated.
						And Max among them will be the max combo price.
						This method is inefficient because it recomputes the MAX price for same combination again and again.

						4 =          1            +          3
						    'provided by caller'  + 'provided by recursion'
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
						int bestPrice = INT32_MIN;
						
						//This loop
						/*int solIndex = i;
						for(int srcIndex = 0; srcIndex <= i; srcIndex++)
						{
							bestPrice = max(bestPrice, solution[solIndex] + srcPrice[srcIndex]);
							solIndex--;
						}*/
						
						int solIndex = 0;
						for(int srcIndex = i, solIndex = 0; srcIndex >= 0; srcIndex--, solIndex++)
						{
							bestPrice = max(bestPrice, solution[solIndex] + srcPrice[srcIndex]);
						}
						
						solution[i+1] = bestPrice;
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