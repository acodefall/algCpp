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
	//Prime number is devisible by 1 amd itself.
	//So to generate P-N until 20. First write 2-20. Then scratch out the numbers that multiple of 2. Then scratch out the 
	//numbers that are multiples of 3. Keep on doing this until we reach 20. Whatever left are PRIME numbers.

	/*
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
	const int SIZEX = 20;
	class BinSearchWhileLoop
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
			}

			//Loop starts from 2 that is 4.
			//This is because 0,1,2,3 are prime numbers so no need to evaluate them.
			//Evaluation for prime-number starts from 4, that is square-root of 2
			for (int i = 2; i < lensqrt; i++)
			{
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
					}
				}
			}

			cout << "Prime numbers are :" << endl;
			for (int i = 2; i < len; i++)
			{
				if (prmArry[i])
					cout << i << endl;
			}
		}




  

    };
};
