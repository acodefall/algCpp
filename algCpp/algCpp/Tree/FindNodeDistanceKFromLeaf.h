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
		Find the nodes that are at distance K from Leaf 20170709001
		   Tree has many paths running running from Root to LEAf. Assume all these paths are stored in a seperate list. Number of lists will be equal to number of paths.
		   There will be many node that will be at distance X from LEAF.  These are Xth element from LEAF.
		   To solve this problem, we have to navigate until the LEAF, and add the nodes fond along the path in to a list. 
		   Once at the LEAF, print the Kelement in the List.
		   Many paths will reach LEAF, and they will all be printing Kth element.
		   
			Start with pre-order recursion code. Pass list objct as rec param.
			Inside the recursion function, right at the top, add the current node to List object.
			After that check if the current node's children are NULL, if so we have reached the LEAF.
			Print the Kth element from bottom of the List that was passed as rec param.
			Then break the recursion.
			
			If we have not reached the LEAF level, make tecursion call to left and right.
			

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