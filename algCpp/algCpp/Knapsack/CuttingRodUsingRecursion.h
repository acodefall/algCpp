#pragma once
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
namespace CuttingRodUsingRecursionNM
{
	/*

	//hxxps://medium.com/@pratikone/dynamic-programming-for-the-confused-rod-cutting-problem-588892796840
	Probem: We are given a long rod, and told to cut it in to pieces and sell it.
	Rod of different length has different price. We should comeup with subset of pieces that generates maximum profit.
	Input data is array of prices and array of lengths.
	Rod of length 4 can be cut in to various combinations. There will be (2 ^ (4-1)) = 8 VALID combinations.
	This problem can be solved using 3 methods
	a) Generating PERMUTATIONS
	b) Recursion
	c) DP

	Generating PERMUTATIONS
	BruteForce has to generate PERMUTATIONS (not combinations). We can not use BitGenerator because we need duplicates.
	We should get some like "Algo" -> "AAAA". Among those permutations use only those that add up to 4.
	---|---------
	Len| 1 2 3 4  //a b c d
	---|---------
	Prc| 1 5 8 9
	---|---------

	CuttingRod using Recursion
	For the sake of understanding, imagine that Rod has been cut in to 4 distinct pieces of length 1, 2, 3, 4.
	Price[] and Length[] of length 4 will give us the price and length.

	4

	Each has a different price tag.


	CuttingRod using DP

	ength i 1 2 3 4 5 6 7 8 9 10
	pricep
	i
	1 5 8 9 10 17 17 20 24 30
	*/
	class CuttingRodUsingRecursion
	{

	public:
		void CallCuttingRodUsingRecursion()
		{

			int price1[4] = { 1, 5, 8, 9 };
			int lengths1[4] = { 1, 2, 3 ,4 };
			int max = 0;
			//cuttingUsingRecursion(price, 4);
			//cutRod(price1, 4);
			//max = cuttingUsingRecursion(price1, 4);
			//cuttingRod(price, lengths, 4);
		}

		
		/*
	
		At startIndex = 0
		cuttingUsingRecursion() return sum from 0 to 0.
		*/
		int cuttingUsingRecursion(int* srcPrice, int remains)
		{
			int sum = 0;

			{
				for (int x = 0; x < remains; x++)
				{
					cout << "\r\n";
					cout << srcPrice[x] << "\r\n";
					int y = cuttingUsingRecursion(srcPrice, remains - x - 1);
					int totalSum = y + srcPrice[x];
					if (totalSum > sum)
					{
						sum = totalSum;
					}
				}
			}
			return sum;
		}
	

	};
};