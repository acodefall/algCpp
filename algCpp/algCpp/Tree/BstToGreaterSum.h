#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace BstToGreaterSumNM
{
	/*
		Greater Sum of Tree
		Greater sum of tree replces the current node's value with cumulative sum of all of the higher-valued nodes.
		Imagine In-order-traversal output who's length is 10. Greater Sum of Tree logic will do following
		   [10] =  0 //Replace 10th node with 0.
		   [09] =  value of [10]
		   [08] =  value of [9] + value of [10]
		Implementation uses Reverese-Inorder-Traversal code for iterating the TREE from right-most node.
		During iteration, Code maintains the cumulative sum of node values in a global variable. 
		At every round, replace the current node's value with whatever value is present in global cumulative sum variable. 
		Then add current node's value to cumulative sum, so the next node will get a incremented value.
		Since the Cumulative sum is initialized to 0 value, the right-most node will get initialized to 0.

		Tree content
		In:	10 50 60 80 85 90 95 100 110 120 300

		  0 + 300 =  300

		300 + 120 =  420

		420 + 110 =  530

		530 + 100 =  630

		630 +  95 =  725

		725 +  90 =  815

		815 +  85 =  900

		900 +  80 =  980

		980 +  60 = 1040

		1040 +  50 = 1090

		1090 +  10 = 1100

		Greater Sum Tree:
			1090 1040 980 900 815 725 630 530 420 300 0
	*/
	class BstToGreaterSum
	{
	public:
		void callBstToGreaterSum()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			BstToGreaterSumX(objTrrr.root);

			cout << endl << "Tree content of Greater Sum Tree\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << endl;
		}

	private:
		int Sum = 0;
		void BstToGreaterSumX(NodeTree* rt)
		{
			if (rt != NULL)
			{
				//This is reverse-in-order traversal. 
				BstToGreaterSumX(rt->R);

				//We exit from above function, we are coming out of nodes that are HIGHER in value.
				//We would have added up values of each of those nodes in "Sum".
				//We are supposed REPLACE current_node.Data with the "Sum", so we assign "Sum" to current_node.Data.
				//We also need need to add current_node.Data to "Sum". So we would have stored current_node.Data in a TEMP variable
				cout << endl << setw(3) << Sum << " + " << setw(3) << rt->d << " = " << setw(4) << Sum + rt->d << endl;
				int temp = rt->d;
				rt->d = Sum;
				Sum += temp;
				
				BstToGreaterSumX(rt->L);
			}
		}
	};
};