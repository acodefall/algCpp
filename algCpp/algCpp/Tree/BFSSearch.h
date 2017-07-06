#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace BFSSearchNM
{
	class BFSSearch
	{
		public:
			void callBFSSearch()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";

				BFSSearchX(objTrrr.root, 50);
			}

		private:
			void BFSSearchX(NodeTree* root, int Value)
			{
				queue<NodeTree*> q;
				q.push(root); //push the root

				while (q.size() > 0)
				{
					//pop one item
					NodeTree* n = q.front();
					q.pop(); 

					//check if the value exists
					if (n->d == Value)
					{
						cout << endl << "found the value " << Value << endl;
						break;
					}

					//if the value is not present, then push the children
					if (n->R)
						q.push(n->R);
					if (n->L)
						q.push(n->L);

				}
			}
	};
};