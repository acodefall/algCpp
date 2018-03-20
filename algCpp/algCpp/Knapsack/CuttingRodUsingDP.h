#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
namespace CuttingRodNM
{
	/*

	CuttingRod Problem_20170609008
		Probem: A rod needs to be cut in to pieces so that total profit is maximum. 
		Price varies from length to length. We should compute the subset of pieces that generates maximum profit and 
		also the Max profit itself. Price[] will give the price, where the index stands for length of the rod
		
		This is a 0-1 Knapsack problem that does not allow duplicates.
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

	Cutting Rod Solution using DP_20170609010
		A Rod of length 4ft can be cut in to 4 different sizes(1ft, 2ft, 3ft and 4ft), and DP tries to find the combination that generates max revenue. 
		Problem input is Price[] of length 4, where index is the length of the piece.
		DP constructs a solution array of length 5, and expects the max revenue to be at the 5th index.
		DP introduces introduce 1ft rod in to pool. Price for 1ft will be in Price[0]. 
		DP computes max-revenue for it and stores the solution in Sol[1].
		Then DP introduces 1ft and 2ft pieces in to pool. Price for 1ft will be in Price[0], Price[1]. 
		Then DP computes max-revenue for this using Price[0], Price[1] and their corresponding solution namely Solution[0]and Solution[1]. 
		Max revenue for pool of “1ft and 2ft” pieces will be stored in Solution[2].

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
			DP starts with just price for 1ft rod.
			And DP computes the Max price for 1ft of rod and stores in Sol[0].
			Then DP inceases the length to 2ft, and now we have price for 1feet rod and 2feet rod.
			DP has to decide will selling which yeilds more profit: "selling 2ft as it is" or "selling two 1ft rods (1ft + 1ft)".
			Price for selling "selling 2ft as it is" comes from src[1];
			Price for selling "selling two 1ft rods (1ft + 1ft)"; we already know the best price for 1ft rod and that is in solu[];
			Price for other 1ft comes from src[1].
				"selling two 1ft rods (1ft + 1ft)" = src[0] + solu[0];
			

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

			Cutting rod problem using Combinations method.
			Say we want to know the combination that adds to 4ft and also has max price tag.
			Generate the combinations of all kinds. Only ENABLED bit add to the length of the rod,
			so combinations will be equal to 4ft, and some will be more than 4ft and some will be less.
			Only select the combinations that add extactly 4ft. Say there are 8 such combinations,
			take the that yeilds max price.
			Coming to implementation. Recursion should continue until the bit width is reahed,
			and on reaching the bit width, go through the ENABLED bits, and compute the length and also price,
			if the length is 4ft, then only compute the price. If the length is not 4ft, then ignore the 
			combination.


	*/
	class CuttingRod
	{

		public:
				void CallCuttingRod()
				{
					                
					int price1[4] = { 1, 5, 8, 9};
					int max = 0;
					

					cuttingRodUsingDPX(price1, 4); //10
					int mx = CuttingRodUsingRecursion(price1,4);
					profitDP(price1, 4);
					
					int price2[8] = { 1, 5, 8, 9, 10, 17, 17, 20};
					mx = cuttingRodUsingDPX(price2, 8); //22
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
			

				/*
					Initialize the solut[0] to 0 so when adding sol[] and prc[], we can use same index variable.
					For example when computing price for for 4ft rod. 
					Price of 4th full length rod is one of the combo. To compute price for it, we will be adding 
					"price for 4ft full length rod" to solu[0].

					Ex: Compute best price for 4ft rod
								  prc[]		sol[]
						     		3			0   //4ft full + 0     
									2           1   //3ft ful  + 1ft
									1           2   //2ft ful  + 2ft
									0			3	//1ft ful  + 3ft			
				*/
				int cuttingRodUsingDPX(int* srcPrice, int srcLen)
				{
					int solution[50] = { 0 };

					solution[0] = 0; 
					
					//this Loop introduces the new elements in src-array. 
					//when i = 0, src-array has one element, and we compute solution[1]
					//when i = 1, src-array has two elements, and we compute solution[2]
					//solutionIndex = i + 1
					for (int i = 0; i < srcLen; i++)
					{
						//starting from 
						int maxSum = INT32_MIN;
						
						//Iterate the sol[]
						for(int srcIndex = 0; srcIndex <= i; srcIndex++)
						{
							cout << srcIndex << " + " << i - srcIndex << endl;
							maxSum = max(maxSum, solution[srcIndex] + srcPrice[i-srcIndex]);
							
						}
						cout << " i ....." << i << endl << endl;
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