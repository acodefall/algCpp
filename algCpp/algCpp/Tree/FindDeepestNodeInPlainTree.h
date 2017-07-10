#pragma once
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
namespace FindDeepestNodeInPlainTreeNM
{
	//Code for finding deepest Left-Node and deepest Node are almost same. Core logic is same. In case of former code specifically looks for LEft node only. 
	//Caller has to set a flag to TRUE, when he is making left-recursion call. In latter case this is not needed.
	class FindDeepestNodeInPlainTree
	{
	public:
		void callFindDeepestNodeInPlainTree()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";
			int deapestLevel = INT_MIN;
			NodeTree* deepestLeftNode = 0;
			FindDeepestNodeInPlainTreeX(objTrrr.root, 0, &deapestLevel, &deepestLeftNode); //4th level, Node is 10
		}

	private:
		void FindDeepestNodeInPlainTreeX(NodeTree* rt, int level, int* deepestLevel, NodeTree** deepestLeftNode)
		{
			if (rt != NULL)
			{
				++level;
				FindDeepestNodeInPlainTreeX(rt->L, level, deepestLevel, deepestLeftNode);
				if (level > (*deepestLevel))
				{
					*deepestLeftNode = rt;
					*deepestLevel = level;
				}

				FindDeepestNodeInPlainTreeX(rt->R, level, deepestLevel, deepestLeftNode);
			}

		}

	};
};