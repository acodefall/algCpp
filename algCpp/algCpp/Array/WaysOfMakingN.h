#pragma once
#include <iostream>
#include <iomanip>>
using namespace std;
namespace WaysOfMakingNNM
{
	/*
	https://en.wikipedia.org/wiki/Composition_%28combinatorics%29
	
	Composition of an Integer_20170616005
		hxxps://en.wikipedia.org/wiki/Composition_%28combinatorics%29
 
		Composition of an Integer is expressing N as SUM of positive integeres that are less than N.
		Ex: Composition for 4 is “4”, “3 + 1”, “2 + 2”, “1 + 3”, “1 + 1 + 1 +1” etc... Number of compositions is 2 ^ (n-1). For N = 4, the compositions are 2 ^ 3, that is 8.  Compisition uses only +ve integers so we can ignore “7-3 = 4”.

		Logic for computing Compositions_20170616006	
		Total number of combin of constructing N is sum of Combination for n-1, n-2, n-3.. goes on until 1. Take the example of 4.  
		Starting from the top, and express 4 as "3+1", "2+2", "1+3", we got 3 combinations.
		Then go one step deeper and express 3 and 2 as its childrens. 3 can be expressed as 1+2, 2+1. This adds 2 combs. Then express the 2 as 1 + 1. This adds another 2 combs. Do this recursively until we reach 1. One can not be expressed as in any other way, so recursion breaks.
		So the total number of ways of making 4 is number of making 4, plus number of ways of making 3, plus number of ways of making 2.  We can use a recursion function for computing combinations count.
	
		Number of combinators are "2 ^ (N – 1)". Four For 4 we will have 2 ^ 3
	
Generate Compositions for 4
	a)
	Express 4 using its children 1, 2, 3. This results in combinations "3+1", "2+2", "1+3"
	Then express above children (1,2,3) as their children. 
	1 can not be represented in its children form, but 2 can be expressed as 1 + 1, and 3 can be expressed as "1+2" and '2+1". Above 2's can be further expressed as 1 + 1. So totally there will be 7 ways of representing 4.
	Note that we express only the 2nd operand as its children. 
	Ex: in "2 + 2", we express the only the 2nd-2 as "1+1" 
			4
			"3+1", 	       "2+2", 		"1+3"
			"2+1+1"        "2+1+1"       1+1+2"
						   1+1+1+1

Computing Compositions count detailed_20170616007
	Have a recursion function that takes int N as input and computes direct (1st level) combinations for N, and increments the counter for each combinatio. If any of the top-level combination is higher than 1, then it makes a recursion call wth child value as parameter(If N is 4, the recursion call will carry 3, 2 as parameter). Recursion call returns the count of 2nd-level combinations (that is for 3, 2), and callee adds these return values to the count maintained by it. In fact recursion call to 3, would have placed a recursion call to 2. 
	Note: If the combination generated are 2+1 and 1+2, make the recursion call for only second combination where the 2 is 2nd parameter. This logic gets applied when N = 3 

	For generating 2st-level of combinations, use a forLoop that goes from i = 1 to i < N.
	N-i gives the child value, if it is higher than 1, then make recursion call, to discover the children of N-i.
	Once the recursion function comes back, take its return value and add it to cominator count  maintained by callee.
 
	Steps for computing Compositions count_ 20170616008
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

