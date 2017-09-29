#pragma once
#include <iostream>
#include <iomanip>>
using namespace std;
namespace WaysOfMakingNNM //@RED20170616005
{
	/*
	https://en.wikipedia.org/wiki/Composition_%28combinatorics%29
	
	Composition of an Integer_20170616005
		hxxps://en.wikipedia.org/wiki/Composition_%28combinatorics%29
		
		Composition means expressing a number N as SUM of numbers that are less than N.
		Means 
		

		Ex: If N = 4, then express 4 using the numbers that are less than 4, that is {1, 2, 3}
		The combinations will be 
			“1 + 3”,
			“2 + 2”, 
			“3 + 1”, 
		In the same fashion, express 3 using 1, 2; and express 2 using 1.

		Number of ways of making 4 = "ways of making 3" + "ways of making 2" + "ways of making 1"
		We need compute the number of ways we can express N.
		This can be coded using recursion. Rec function will recieve 4 as parameter, and starts a ForLoop that makes 3 rounds; 
		Each round of forLoop makes a recursion call by passing 1, 2, 3 as parameter.
		Rec call should be made only if the currIndex is more than 1. This is because we can divide 1 in to any more subparts.

		We have been asked to count the number of Compositions; this count is equal nothing but the sum of 
		iterations of forLoop at every level of recursion. Recursion maintains the iteration at current level and 
		also recieves the iteration count from Rec function. Post recursion code adds 
		'compositionCounter at current level' + 'compositionCounter returned by rec call', and returns the total sum
		to caller. So eventually the top most caller gets the total Composition count for integer N.

		
		Pre recursion code increments the 'compositionCounter at current level';
		and Post recursion code adds 'compositionCounter at current level' + 'compositionCounter returned by rec call'
		
		
		Rec(N)
		{
			int compositionCounter = 0;
			for(i = 1 to N-1)
			{
				compositionCounter++;
				if(>1)
					compositionCounterRec =  Rec(i)
				compositionCounter += compositionCounterRec;
			}
			return compositionCounter;
		}
		
		Number of compositions is 2 ^ (n-1). For N = 4, the compositions are 2 ^ 3, that is 8.  
		Compisition uses only +ve integers so we can ignore “7-3 = 4”.


		N = 4
	Ex: in "2 + 2", we express the only the 2nd-2 as "1+1" 
			4
			"3+1", 	       "2+2", 		"1+3"
			"2+1+1"        "2+1+1"       1+1+2"
						   1+1+1+1
	*/
	class WaysOfMakingN
	{
	public:
		void callWaysOfMakingN()
		{
			int N = 4;
			int Loops = 0;
			cout << " \r\n";
			cout << " WaysOfMakingN() \r\n"; //7
			int Ways = WaysOfMakingNx(N);

			/*
				WaysOfMakingN()
					Divide (4)    1 + 3
					Divide (4)    2 + 2
					Divide (4)    3 + 1
					Divide (3)    1 + 2
					Divide (3)    2 + 1
					Divide (2)    1 + 1
					Divide (2)    1 + 1
			*/
			cout << " Ways: " << Ways << " \r\n";
			cout << " \r\n";
		}
		/*
			a) N is input paeameter
			b) declare ways = 0//this counts the number of compositions
			c) Start a For loop 
		*/
		int WaysOfMakingNx(int N)
		{
			int Ways = 0;

			for (int i = 1; i < N; i++)
			{
				cout << "Divide (" << N << ")    " << i << " + " << N - i << "\r\n";
				Ways++;
				int x = 0;
				if (N - i > 1)
					x = WaysOfMakingNx(N - i);
				Ways += x;

			}
			return Ways;
		}
	};
};

