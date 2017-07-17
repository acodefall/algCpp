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
namespace NodeCountNM
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
	class NodeCount
	{
		public:
			void callNodeCount()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
			
				
				int x = NodeCountX(objTrrr.root);
				cout << "NodeCount is " << x;;
			}

		private:
			int NodeCountX(NodeTree* root)
			{
				int count = 0;
				if (root)
				{
					count += NodeCountX(root->L);
				
					count += NodeCountX(root->R);

					count += 1;

					return count;
				}
				else
				{
					return count;
				}
			}
	};
};