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

namespace  GeneratePrimeNumbersNM
{
	/*
	Finding prime numbers_20170722012
		Prime number are divisible only by 1 or iteself.This mean multiples of 2(like 4, 6, 8) are not prime; similarly multiple of 3 (like like 6, 9, 12) are not prime.We do not bother to find the multiples for 4 because it is already divisible by 2.
		Using this method, we scratch out the all multiples because they are divisible(say 6 is divisble by 2), so 6 is not a prime.Since 6 is divisible by 2, we do not even to find multiples for 6.
		In the end, few numbers will not get scratched at all, and they are the primes.
		We will probe only until product reaches the SQUARE of max - prime.
		Ex: When finding 7 prime numbers, we will not go any further if the product is above 49. When trying the multiples of 5, we will stop before 5 * 10.


	0   1   2   3   4   5   6   7   8   9   10   11   12   13   14   15   16   17   18   19   20

	sqrt(20) => 4.4
	Set FALSE as follows for 2,3,4
	2       4       6       8       10        12        14        16        18        20
	3                       9                            15

	*/

	/*
	To generate an array 20-prime numbers.
	-Create an array to hold 20 prime numbers.
	-In a For-Loop, fill the whole array with 1.
	-Next For-Loop, goes from j = 2 to j < (SQRT of 20).
	Loop starts from 2 that is 4.
	This is because 0,1,2,3 are prime numbers so no need to evaluate them.
	Evaluation for prime-number starts from 4, that is square-root of 2
	-Inside For-Loop, if d[j] is 1, then start an another For-Loop, where K starts at (J ^ 2) and increments by J.
	This goes until 20.
	Set d[k] as 0.

	-Now print the Prime numbers. Prime numbers will be at the index where value is 0.
	*/
	const int SIZEX = 7;
	class GeneratePrimeNumbers
	{
	public:
		void callGeneratePrimeNumbers()
		{
			int len = SIZEX;
			int lensqrt = (int)pow(len, 2);
			int prmArry[SIZEX];

			for (int i = 0; i < SIZEX; i++)
			{
				prmArry[i] = 1;
				cout << "prmArry[" << i << "]   " << prmArry[i] << endl;
			}

			//Loop starts from 2 that is 4.
			//This is because 0,1,2,3 are prime numbers so no need to evaluate them.
			//Evaluation for prime-number starts from 4, that is square-root of 2
			for (int i = 2; i < lensqrt; i++)
			{
				cout << "	prmArry[" << i << "]   " << prmArry[i] << endl;
				if (prmArry[i])
				{
					/*
					i=2

					j=4
					a[4] = false

					j = 4 + 2
					a[6] = false

					j = 4 + 4
					a[8] = false
					*/
					for (int j = (int)pow((double)i, (double)2); j < len; j = j + i)
					{
						prmArry[j] = 0;
						cout << "		prmArry[" << j << "]" << " " << prmArry[j] << endl;
					}
				}
				
			}

			cout << "Prime numbers are :" << endl;
			for (int i = 2; i < len; i++)
			{
				if (prmArry[i])
					cout << "prmArry[" << i << "]" << " " << prmArry[i]  << endl;
			}
		}




  

    };
};
