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

		Find Kth Largest item in max Heap is larger than X_20170725064
			Max heap will have MAX item at root, and Kth largest item will be K steps below the root. 
			Question is to check whether this Kth node’s value is LARGER than some value, say 100.
			Solution is, start drilling from root, K steps down. At each step compare currNode and Value.
			If the currNode stays higher than Value, until the Kth step,  then return TRUE.
				If(Value(K) > 100)
					Return TRUE;
				Else
					Return FALSE;
			If NodeValue drops below Value(100), before we even reach Kth node, then there is no need to drill down until Kth node. 
			Return with FALSE.

			Heap is also a TREE, so write pre-order traversal code and track the LEVEL by passing level as rec-param; 
			also make left and right turn at every node. 
			In everey round compare the sought-value against Node value, and take appropriate action.



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
			
		
			//Heap is also a TREE, so write pre - order traversal code and track the LEVEL by passing level as rec - param
			//In everey round compare the sought-value against Node value, and take appropriate action.
			//Check if the ValueX is lower than the value that is at "Kth distance from node" 
			//If the currNode stays higher than ValueX, until the Kth step,  then return TRUE.
			//If NodeValue drops below Value(100), before we even reach Kth node, then there is no need to drill down until Kth node. 
			//Return with FALSE.
			
			bool checkForKItem(Node* node, int ValueX, int K, int* level)
			{
				while (node != 0)
				{
					if (*level <= K)
					{
						if (node->value <= ValueX)
						{
							return false; //NO, ValueX is higher than Kth value
						}
					}
					else
						return true; //Yes ValueX is lower than Kth value
									 //End traversal, no need to go beyond Kth item.

					level++;
					checkForKItem(node->left, ValueX, K, level);
					checkForKItem(node->Right, ValueX, K, level);
				}

			}
	};
};