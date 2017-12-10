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

namespace  GeneratePrimeNumbersNM //@RED20170722012
{
	/*
	Finding prime numbers_20170722012
		Prime number list is created by using -ve logic; that is by "scratching out" the numbers that are NOT prime.
		-Prime number is divisible only by 1 or iteself. That means multiple of any number can not be a prime, so scratch them out.
		 Using this logic, scratch out all multiple of 2, multiple of 3, etc....
		 Scratching will happen until the required number of prime numbers. If the user has asked for 5 prme number.
		 we scratch out 2*2 to 2*5; out 3*2 to 3*5.
		 Base for multiplication goes until square of N.
		 

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
					cout << i << endl;
			}
		}




  

    };
};
