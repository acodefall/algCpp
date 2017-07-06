#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;

namespace BalancedBSTCheckUsingInOrderTrvNM
{
	/*
	We can check if the Tree is Balanced using 3 methods
			   -Check for MIN and MAX 
					This is superior and work even when the Tree has duplicates.
			   -Do inorder traversal and check if the output is increasing, is so Tree is balanced.               
			This can be implemented using Recursion and non-recursion methods.
	
	*/
	class BalancedBSTCheckUsingInOrderTrv
	{
		public:
				void callBalancedBSTCheckUsingInOrderTrv()
				{
					BuildTree objTrrr;
					objTrrr.AddValues();

					cout << "\r\n";
					cout << "Tree content\r\n";
					objTrrr.printTreeInOrder(objTrrr.root);
					cout << "\r\n";

					bool x = BalancedBSTUsingInorderTrv(objTrrr.root);

				}

				//iterate the Tree using Inorder traversal, if the data is in increasing order then BST is Balanced
				bool BalancedBSTUsingInorderTrv(NodeTree* rt)
				{
					bool Balanced = true;
					stack<NodeTree*> st;
					int prevValue = INT32_MIN;
					NodeTree* cur = rt;
					while (cur)
					{
						//Navigate till the deepest left-node.
						//Add the nodes found till then to STACK 
						while (cur)
						{
							st.push(cur);
							cur = cur->L;
						}

						if (st.size() > 0)
						{
							NodeTree* n = st.top();
							st.pop();
							if (n->d > prevValue)
								prevValue = n->d;
							else
							{
								Balanced = false;
								break;
							}

							cur = n->R;
						}

					}

					return Balanced;
				}
	};
};
