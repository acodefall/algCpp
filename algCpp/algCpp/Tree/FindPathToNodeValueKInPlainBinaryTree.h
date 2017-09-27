#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<stack>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace FindPathToNodeValueKInPlainBinaryTreeNM //20170710003
{
		/*
			Find Path To Value K in Plain Binaray Tree 
				Note that we are searching inside Binaray Tree, not Binary Search Tree.
				In Binary Tree, nodes will not follow any order, nodes will be allocated on first-come-first serve basis.
				Where as the insertion code in BST, searches for the appropriates place and then creates the node there.
				In BST, Value on left should be lower and value on right should be higher. 
				So when searching in BST, comapare currNode's value against VsoughtValue and appropriately make either LEFT OR RIGHT turn. 
				
				In case of Plain Tree, there is not order. So we have to iterate the whole tree from Root to LEAF, 
				using IN-ORDER traversal, and check for the VALUE along the way. Potentially we may have to touch every
				node in the tree. So searching in Plain Tree is not efficient.


				           100
                          /    \
                         /      \
                        80       120
                       /  \      / \
                     50    90   110  300
                     /\    /\
                    /  \  /  \
                   10 60  85 95

				   Path for 85 in Plain Binary Tree
										100 80 90 85
		*/
	class FindPathToNodeValueKInPlainBinaryTree
	{
		public:
				void callFindPathToNodeValueKInPlainBinaryTree()
				{
					BuildTree objTrrr;
					objTrrr.AddValues();

					cout << "\r\n";
					cout << "Tree content\r\n";
					objTrrr.printTreeInOrder(objTrrr.root);
					cout << "\r\n";

					//Order refers to the position of Parent node
					int K = 85;
					vector<NodeTree*> Nodelist;
					Nodelist.reserve(50); // reserve some random number of size
					cout << endl << "Print path for " << K << " in Plain Binary Tree" << endl;
					FindPathToNodeValueKInPlainBinaryTreeX(objTrrr.root, Nodelist, K);
				}

		private:
				void FindPathToNodeValueKInPlainBinaryTreeX(NodeTree* root, vector<NodeTree*> Nodelist, int K)
				{
					if (root)
					{
						Nodelist.push_back(root); //Add current node's value to Node List
						if (root->d == K)
						{	//Found the value that we were looking, so no need to explore child nodes. RETURN, but print the Path before returning
							cout << "Node " << K << " found ";
							for (auto itr = Nodelist.begin(); itr != Nodelist.end(); itr++)
							{
								cout << setw(4) << (*itr)->d;
							}
							cout << endl << endl;
							return;
						}
						FindPathToNodeValueKInPlainBinaryTreeX(root->L, Nodelist, K);
						FindPathToNodeValueKInPlainBinaryTreeX(root->R, Nodelist, K);
					}
					else
					{
						return;
					}
				}

	};
};