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

namespace CheckTreeIsBSTUsingInOrderTrvNM //@RED20170731007
{
	/*
		Check if the Tree is a Binary Search Tree(BST) 
			Note this is not about checking whether the tree is Balanced BST.
			BST and Plain Tree are different.
			BST has rules that controls the values of P, Lc and Rc; where as the Plain Tree does not
			lie down any rules about the node value.
			In BST, Parent node's value should be higher than Lc and Lower than Rc
			   20
			   / \
			 10   30
	 
			In Plain Binary Tree, node value can be anything.
				20
			   / \
			 100  3
	 
			Checking for BST can be done in 2 ways
			-Using inorder traversal
				We know BST data will be in increasing order. So write a code for inoder traversal and in each round
				confirm that current value is higher than previous value. If the whole tree satisfies this rule, then
				the whole tree in BST. 
	
			-Using Min and MaX method
			   Value of every node in BSTree has to fall in between some MIn and MAx value. 
			   These Min and Max values are set by immiditae parent and also some other ancestor node.
			   For root node, there is no parent or ancestor so the Min and Max are Int_Min and Int_Max.
			   For internal node, that is also a Lc, value should be LESS than immidiate parent and higher than some ancestor node.
			   For internal node, that is also a Rc, value should be HIGHER than  immidiate parent and lower than some ancestor node.
			   If every node meets this requrement then we can say that whole tree is Binary Search Tree)(not Balanced BST).
	   
	*/
	class CheckTreeIsBSTUsingInOrderTrv
	{
		public:
				void callCheckTreeIsBSTUsingInOrderTrv()
				{
					BuildTree objTrrr;
					objTrrr.AddValues();

					cout << "\r\n";
					cout << "Tree content\r\n";
					objTrrr.printTreeInOrder(objTrrr.root);
					cout << "\r\n";

					bool x = CheckTreeIsBSTUsingInOrderTrvX(objTrrr.root);

				}

				//iterate the Tree using Inorder traversal, if the data is in increasing order then BST is Balanced
				bool CheckTreeIsBSTUsingInOrderTrvX(NodeTree* rt)
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
