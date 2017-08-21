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

namespace IsBSTNM //@RED20170731006
{
	/*
	We can check if the Tree is Balanced using 3 methods
			   -Check for MIN and MAX 
					This is superior and work even when the Tree has duplicates.
			   -Do inorder traversal and check if the output is increasing, is so Tree is balanced.               
			This can be implemented using Recursion and non-recursion methods.
	
	*/
	class IsBST
	{
		public:
				void callIsBST()
				{
					BuildTree objTrrr;
					objTrrr.AddValuesNonBST();
					//objTrrr.AddValues();

					cout << "\r\n";
					cout << "Tree content\r\n";
					objTrrr.printTreeInOrder(objTrrr.root);
					cout << "\r\n";


					bool x = IsTreeBST(objTrrr.root);

				}

				
				bool IsTreeBST(NodeTree* rt)
				{
					bool bst = false;
					NodeTree* cur = rt;
					if (rt != NULL)
					{	
						bool lc = IsTreeBST(rt->L);
						bool rc = IsTreeBST(rt->R);
						if (lc && rc) //Child hives are BST
						{
							//now check the current node
							if ((rt->L <= rt->d) && (rt->R >= rt->d))
							{
								return true;
							}
						}

					}
					else
					{	//A NULL node is assumed to satisfy the rule of BST because P, lc & rc are all NULL
						//If the Node is NULL, there are no child either.
						//we can NOT compare value of P, Lc and Rc
						//so simply return TRUE

						return true;
					}
				
					return Balanced;
				}
	};
};
