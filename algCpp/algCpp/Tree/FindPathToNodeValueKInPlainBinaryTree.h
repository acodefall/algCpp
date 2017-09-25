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
				In Plain Binary Tree, new VALUE takes which ever place is available at that time, without giving any consideration to the value. Where as BST places the new VALUE at appropriate slot based on the VALUE. Eg: If the new VALUE is 10, then it will be placed in between 5 and 15.

				So when searching for a VALUE in BST, we can comapare currNode's value against the Value being searched, and appropriately make either LEFT OR RIGHT turn. But we can not do that in case of Plain Tree. We have to iterate from Root to LEAF, using IN-ORDER traversal, and check for the VALUE along the way.


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