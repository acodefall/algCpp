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
			
			Sum Of tree replaces current node's value with the sum of the values held by left and right children.
			Implementation will use post-order-traversal code; and goes on replacing current node's value with sum of left-child and right-child;
			but returns the sum of current node, left-child and right-child to caller.  Note that values of Leaf-nodes will get replaced by 0.
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