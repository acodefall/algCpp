#pragma once
/*
	Subset sum problem
	https://en.wikipedia.org/wiki/Subset_sum_problem
	Subset problem is standard algorithm. Given a set of numbers, we have to find a every subset(combination) who's sume becomes equal to X.
	This can be solved by using bit-generator, and Knapsack problem. bit-generator is inefficient compared Knapsack.

	This is how bit-generator works. Say src has 5 elements and we have to find 3 elements that add up to 100.
	Solution involves generating bit sequences of width 5. Then select only those sequences that has 3 bits enabled. Then replace 1 with the 
	value taken from src-array. If the sum becomes equal to X, then select that combination.
*/