#pragma once
#include <queue>
#include <iostream>
#include <stack>
namespace CheckNumberIsHigherThanKthNM //@RED20170725064
{
	using namespace std;

	/*
		Problem
			201) There is an array based binary heap containing n numbers (the root stores the greatest number so it is a max-heap). 
			You are a given an integer x and have to determine whether the kth largest element of the heap is greater than x or not. Your algorithm must take O(k) time.

		Find Kth Largest item in max Heap is larger than X
		Node at a distance K from Root
			Say X is 10, and K is 5.
			Check 5th item's value is higher than 10.
			In max heap, as we go down the values reduce.
			When going down check whether the 5th item's value( from TOP)  is > 10.

			Iterate the heap like any Tree by going to left and right child.
			Each level compare the level and also value.
			Go ONLY until 5th level, not beyond that. If the value drops below 10
			before you reach 5th level, exit there itself. Even if did not meet that
			condition, do not go beyond 5th level.


	*/
	struct Node
	{
		Node* left;
		Node* Right;
		int   value;
	};
	class CheckNumberIsHigherThanKth
	{

		public: 
			
			
			//Check if the ValueX is lower than the value that is at "Kth distance from node" 
			//Do the DFS search only until distance K, and all the node values should be more than ValueX.
			//If we come across any node who value is less than ValueX, then return immedietely, no need to go until Kth item
			//TRUE: ValueX is less than the value that is at "Kth distance from node" 
			bool checkForKItem(Node* node, int ValueX, int K, int* distance)
			{
				while (node != 0)
				{
					if (*distance <= K)
					{
						if (node->value <= ValueX)
						{
							return false; //NO, ValueX is higher than Kth value
						}
					}
					else
						return true; //Yes ValueX is lower than Kth value
									 //End traversal, no need to go beyond Kth item.

					distance++;
					checkForKItem(node->left, ValueX, K, distance);
					checkForKItem(node->Right, ValueX, K, distance);
				}

			}
	};
};