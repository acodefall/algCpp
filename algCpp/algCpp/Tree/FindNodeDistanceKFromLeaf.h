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
namespace FindNodeDistanceKFromLeafNM
{
	/*
		Find the nodes that are at distance K from Leaf
		   This is about printing the Nodes that are at a distance K from LEAF, not from root. Since there are many Leaf, there will be many paths also, running between root to leaf.  In these paths, we have to print the node that is at a distace K from Leaf. 
			For building the path, use Pre-order-traversal code. As we are traversing, store the nodes in a list object that is passed as recursion parameter. By the time we reach the LEAF node (leaf is the node who's children are NULL), list object would have recorded every node found along path from Root to leaf.
			The node stored at the index (Size Of List - K) will give the Node node that is at the distance K from Leaf.
			Since there are many paths, there we will be many paths.


			Example
				           100
                          /    \
                         /      \
                        80       120
                       /  \      / \
                     50    90   110  300
                     /\    /\
                    /  \  /  \
                   10 60  85 95

				Paths are     [K]
						100 80 50 10
						100 80 50 60
						100 80 90 85
						100 80 90 95
						  100 120 110
						  100 120 300


				

	*/
	class FindNodeDistanceKFromLeaf
	{
		public:
			void callFindNodeDistanceKFromLeaf()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
				vector<NodeTree*> Nodelist;
				int K = 2;
				Nodelist.reserve(50); // reserve some random number of size
				//cout << "Find Node distance for " << Value << "\r\n";
				FindNodeDistanceKFromLeafX(objTrrr.root, Nodelist, K);

				/*	Nodes at a distance 2 from Leaf
					Node at K distance is 50
					Node at K distance is 90
					Node at K distance is 120
				*/
			}

		private:
			void FindNodeDistanceKFromLeafX(NodeTree* root, vector<NodeTree*> Nodelist, int K)
			{
				if (root)
				{
					
					Nodelist.push_back(root);
					if ((root->L == NULL) && (root->R == NULL))
					{
						//Tree will have many Leaf, and one or the other Node will be at distance from each of the LEAF.
						//So we will be printing each on them 
						//So we will come here several times
						if (Nodelist.size() >= K)	
						{	//Node at K distance is Nodelist[K]
							cout << "Node at K distance is " << Nodelist[Nodelist.size() - K]->d << endl;
							
							cout << "Path is " << endl;
							for (auto itr = Nodelist.begin(); itr != Nodelist.end(); itr++)
							{
								cout << (*itr)->d << " ";
							}
							cout << endl << endl;
							return;
						}
					}
					FindNodeDistanceKFromLeafX(root->L, Nodelist, K);
					FindNodeDistanceKFromLeafX(root->R, Nodelist, K);
				}
				else
				{
					return; 
				}
			}
	};
};