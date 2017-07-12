#pragma once
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
namespace PrintFullNodesNM //20170711003
{
	/*
	Print All The Full Nodes in a Binary Tree_20170711003
		Full node is a node that has non-null R-child and L-Child.
		To print them, iterate the Tree using Inorder traversal, Print the current node ONLY if R & L children are non-null.
		List of full nodes will not have LEAF


	
				       100					
				      /    \
				     /      \
				    80       120
				   /  \      / \
				 50    90   110  300
				 /\    /\
				/  \  /  \
			   10 60  85 95
				
				
				Full Nodes(node this list does not have LEAF)
					50
					80
					90
					100
					120

   */
	class PrintFullNodes
	{
		public:
			void callPrintAllPathsOfTree()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
			
				
				PrintFullNodesX(objTrrr.root);

			}

		private:
			void PrintFullNodesX(NodeTree* root)
			{
				if (root)
				{
					PrintFullNodesX(root->L);
					//Full node is the one that has both non-null children 
					if ((root->L != NULL) && (root->R != NULL))
					{
						cout << root->d << " " << endl;
					}
					PrintFullNodesX(root->R);
				}
				else
				{
					return; 
				}
			}
	};
};