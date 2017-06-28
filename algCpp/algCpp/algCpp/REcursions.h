
#pragma once


/*

How to understand this?
	Recursion is self substitution. Termination for this chain reaction is not obvious so recursion function appears like a complex problem.
	To unravel the recursion, invoke the function with one value more than BASE condition, that will expose the pattern.

	Here call this function will 3 as input.
	factorial(2);
	2 * factorial(1);
	2 * 1;

	factorial(4);
	4 factorial(3);
	3 factorial(2);
	2 factorial(1); //replace with 2 1
	

	4 3 2 1
	
	
	

	Using above result we can write factorial(5) as "5 * 4 * 3 * 2 * 1"

static int factorial (int n) 
{
	if (n < 2) 
		return 1;                     // base case
	else 
		return n * factorial(n-1);    // recursive case

}

The above recursion is called a linear recursion since it makes one recursive call at a time. The loop equivalent:

public static int factorial(int n) {
int result = 1;
for (int i = 2; i <= n; i++)
result *= i;
return result;
}

*/
