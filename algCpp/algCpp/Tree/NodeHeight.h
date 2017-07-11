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
namespace NodeHeightNM
{
	/*
				Print All The Full Nodes in a Binary Tree


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
	class NodeHeight
	{
		public:
			void callNodeHeight()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
			
				
				int x = NodeHeightX(objTrrr.root);
				cout << "Node Height is " << x;;
			}

		private:
			int NodeHeightX(NodeTree* root)
			{
				int height = 0;
				if (root)
				{
					int x1 = NodeHeightX(root->L);
				
					int x2 = NodeHeightX(root->R);


					height = max(x1, x2);
					height += 1;

					return height;
				}
				else
				{
					return height;
				}
			}
	};
};