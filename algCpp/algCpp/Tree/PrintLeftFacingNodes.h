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
namespace PrintLeftFacingNodesNM //20170711004
{
	/*
				Print All The Left Facing Nodes in a Binary Tree_20170711004
					Left facing nodes sit on the Left-side of the triangle, and we have to print node value when cursor is at those nodes. 
					When cursor is going along the left-traingle, the LEVEL goes from LOW to HIGH, and that is how we can detect that cursor is 
					on left-side triangle.

					Start with In-order-Traversal code.
					As we navigate track MaxLevel( just like tracking the max Node value), and also current level.
					Maximum level is the level that we have seen since the navigation began.
					Update the MaxLevel only when currLevel goes above MaxLevel, and at time PRINT the node
					CurrLevel will be higher than MaxLevel only when cursor is on left-triangle.
					Recursion parameter should have Node, currLevel and pointer to MaxLevel.
					

					For printing the Right facing nodes follow similar strategy. This time do Reverse Pre-order Traversal code.
				       100					
				      /    \
				     /      \
				    80       120
				   /  \      / \
				 50    90   110  300
				 /\    /\
				/  \  /  \
			   10 60  85 95
				
				
				Left-facing Nodes
							100
					{ 1 0 } 80
					{ 2 1 } 50
					{ 3 2 } 10

   */
	class PrintLeftFacingNodes
	{
		public:
			void callPrintLeftFacingNodes()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
			
				int maxLevel = INT32_MIN;
				PrintLeftFacingNodesX(objTrrr.root, 0, &maxLevel); //100, 80, 50, 10

				cout << "\r\n";
				maxLevel = INT32_MIN;
				PrintRightFacingNodesX(objTrrr.root, 0, &maxLevel); //300, 95
			}

		private:
			//maxLevel tracks maximum level that we have seen since the navigation began. This is like tracking the max Node value.
			//Update maxLevel only if it is lower than currLevel
			void PrintLeftFacingNodesX(NodeTree* root, int curlevel, int *maxLevel)
			{
				if (root)
				{
					if (curlevel > *maxLevel)
					{   
						cout << "{ " << curlevel << " " << *maxLevel << " }" << setw(3) << root->d << endl;
						*maxLevel = curlevel;
					}
					PrintLeftFacingNodesX(root->L, curlevel +1, maxLevel);
					PrintLeftFacingNodesX(root->R, curlevel +1, maxLevel);
				}
				else
				{
					return; 
				}
			}


			void PrintRightFacingNodesX(NodeTree* root, int curlevel, int *maxLevel)
			{
				if (root)
				{
					PrintRightFacingNodesX(root->R, curlevel + 1, maxLevel);
					PrintRightFacingNodesX(root->L, curlevel + 1, maxLevel);

					if (curlevel > *maxLevel)
					{
						cout << "{ " << curlevel << " " << *maxLevel << " }" << setw(3) << root->d << endl;
						*maxLevel = curlevel;
					}
					
				}
				else
				{
					return;
				}
			}
	};
};