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
namespace FindDeepestLeftNodeNM
{
	class FindDeepestLeftNode
	{
		public:
			void callFindDeepestLeftNode()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
				int deapestLevel = INT_MIN;
				NodeTree* deepestLeftNode = 0;
				FindDeepestLeftNodeX(objTrrr.root, 0, false, &deapestLevel, &deepestLeftNode); //4th level, Node is 10
			}

		private:
			void FindDeepestLeftNodeX(NodeTree* rt, int level, bool LeftChild, int* deepestLevel, NodeTree** deepestLeftNode)
			{
				if (rt != NULL)
				{
					++level;
					FindDeepestLeftNodeX(rt->L, level, true, deepestLevel, deepestLeftNode);
					if ((level > (*deepestLevel)) && (LeftChild == true))
					{
						*deepestLeftNode = rt;
						*deepestLevel = level;
					}

					FindDeepestLeftNodeX(rt->R, level, false, deepestLevel, deepestLeftNode);
				}

			}
			
	};
};