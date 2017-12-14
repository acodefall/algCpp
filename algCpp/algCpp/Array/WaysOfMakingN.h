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
		
		Compostion is about expressing a number in terms od lower deniminations.
		Means expressing 4 as combinations of 1, 2, 3.
		
		To know the compositions of a number, go on subtracting 1,2,3 from original number.
		This creates various combinations of 2 part each. Then go in to each combination.
		Combination will have 2 parts, and divide one of the part in to still smaller pieces
		using same subtraction-technique. This will reduce the partition in to still smaller size.
		Keep subdividing the parts as long as the partition size is more than 1.
		Aply this logic to 4. Apply the subtraction-technique by subtracting 1, 2, 3; and 
		this will create following partitions. 
			“1 + 3”,		   =  1 + 3	
					1 + (1, 3-1) 
						(1, 2) =  1 + 1 + 2  
					1 +	(2, 3-2) 
						(2, 1) =  1 + 2 + 1
			“2 + 2”, 
			“3 + 1”, 
		Take the combination "1 & 3" and subdivide "3" by subtracting 1 & 2 from 3.
		Go on doing this as long as partition width is > 1.
		We can say, number of ways of making 4 = "ways of making 3" + "ways of making 2" + "ways of making 1"
		Number of compositions is 2 ^ (n-1). For N = 4, the compositions are 2 ^ 3, that is 8.  
	
		Coming to the implementation, use a recursion function that accepts number N (say N = 4) as input.
		Functions starts a for that goes fron 1-3 and that for applying substraction-technique.
		Subtraction creates parts, if the part size is more than 1, then make a recursion call.
		
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

