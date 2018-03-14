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
			
		Compostion is about expressing a number in terms of lower deniminations.
		Means expressing 4 as combinations of 1, 2, 3.
	
		Let us take the example 3.
		3 = 2 + 1.
		"Number of ways expressing 3" = "Number of ways expressing 2" + "Number of ways expressing 1"
		This can be solved using recursion.

	    
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
		
	Applying composition techinque to find number of combinations.
		Number of comibinations is equal to number of subtractions so count the number of subtractions.

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

			//apply subtraction-technique. 
			//If N = 4, subtract 1, 2, 3 from 4.
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

