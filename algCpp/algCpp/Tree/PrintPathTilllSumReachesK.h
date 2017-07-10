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
namespace PrintPathTilllSumReachesKNM
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

				Paths are   that reached 190 are
						Sum reached 190  "100  80  50"
						Sum reached 190  "100  80  90"
						Sum reached 190  "100 120"

	*/
	class PrintPathTilllSumReachesK
	{
		public:
			void callPrintPathTilllSumReachesK()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
				vector<NodeTree*> Nodelist;
				Nodelist.reserve(50); // reserve some random number of size
				
				PrintPathTilllSumReachesKX(objTrrr.root, Nodelist, 0, 190 );
				/*
						Sum reached 190  "100  80  50"
						Sum reached 190  "100  80  90"
						Sum reached 190  "100 120"
				*/

			}

		private:
			//SumTillNow tracks the sum of nodes found along this path
			void PrintPathTilllSumReachesKX(NodeTree* root, vector<NodeTree*> Nodelist, int SumTillNow, int K )
			{
				if (root)
				{
					
					SumTillNow += root->d; //Add current node's value to SUM
					Nodelist.push_back(root); //Add current node's value to Node List
					if (SumTillNow > K)
					{	//Sum reached K so no need to explore child nodes so RETURN, but the print the Path before returning
						cout << "Sum reached " << K << " ";
						for (auto itr = Nodelist.begin(); itr != Nodelist.end(); itr++)
						{
							cout << setw(4) << (*itr)->d;
						}
						cout << endl << endl;
						return;
					}
					PrintPathTilllSumReachesKX(root->L, Nodelist, SumTillNow, K);
					PrintPathTilllSumReachesKX(root->R, Nodelist, SumTillNow, K);
				}
				else
				{
					return; 
				}
			}
	};
};