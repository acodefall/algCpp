#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace SumTreeNM
{
	/*
				Create Sum Tree out of BST_ 20170711005

				       BST                               SumTree
				       100							       100					
				      /    \						      /    \
				     /      \						     /      \
				    80       120					    80       410
				   /  \      / \					   /  \      / \
				 50    90   110  300				 70   180   110  300
				 /\    /\							 /\    /\
				/  \  /  \							/  \  /  \
			   10 60  85 95						   0   0  0   0
			
				In Sum-tree current node's values will be replaced with the sum of left hive and right hive. Do not add current node's value to sum.
				Parent Node makes recursion calls to left and right children, and recursions return sum of their respective hives. 
				Then replace parent's node value with the sum of value returned by left and right hives
				. 
					-To create sumTree we neeed the sum from right hive and left hive, then only we can create Sum Tree.
					 So we use Post-Order-Traversal code. Once the Recursion comes back with the sum of child node values, add them and make it the value of current Node.
					-Call Left-Recursion and get the sum. Call Right-recursion and get the sum.
					-Add children's sum to current_node's Value, and return to caller.
					Just before returning, update the current_node's value with the sum of right and left children values
   */
	class SumTree	
	{
		public:
			void callSumTree()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				BuildTree::printTreeInOrder(objTrrr.root);
				cout << "\r\n";
			
				
				int x = createSumTree(objTrrr.root);
				cout << "Tree content of sum of tree \r\n";
				BuildTree::printTreeInOrder(objTrrr.root);
			}

		private:
			int createSumTree(NodeTree* root)
			{
				if (root)
				{
					int lSum = createSumTree(root->L);
				
					int rSum = createSumTree(root->R);

					cout << lSum << " + " << rSum << " = " << (lSum + rSum) << endl;
					int tmpCurr = root->d;
					
					//replace current node's value with the sum of children
					root->d = lSum + rSum; 
				
					return tmpCurr + lSum + rSum; //when returning add up all the tree nodes
				}
				else
				{
					return 0;
				}
			}
	};
};