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
namespace PrintAllPathsOfTreeNM
{
	/*
		

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

				Paths are     
						 100  80  50  10
						 100  80  50  60
						 100  80  90  85
						 100  80  90  95
						 100 120 110
						 100 120 300
	*/
	class PrintAllPathsOfTree
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
				vector<NodeTree*> Nodelist;
				Nodelist.reserve(50); // reserve some random number of size
				
				PrintAllPathsOfTreeX(objTrrr.root, Nodelist);

			}

		private:
			void PrintAllPathsOfTreeX(NodeTree* root, vector<NodeTree*> Nodelist)
			{
				if (root)
				{
					
					Nodelist.push_back(root);
					if ((root->L == NULL) && (root->R == NULL))
					{
						//Tree will have many Leaf, and each has distinct path to Root.
						//So we will be printing each on them 
						//So we will come here several times
						cout << "Path is " << endl;
						for (auto itr = Nodelist.begin(); itr != Nodelist.end(); itr++)
						{
							cout << setw(4) << (*itr)->d;
						}
						cout << endl << endl;
						return;
						
					}
					PrintAllPathsOfTreeX(root->L, Nodelist);
					PrintAllPathsOfTreeX(root->R, Nodelist);
				}
				else
				{
					return; 
				}
			}
	};
};