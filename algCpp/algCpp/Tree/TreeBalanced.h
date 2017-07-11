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
namespace TreeBalancedNM
{
	/*
				Print All The Full Nodes in a Binary Tree
                                                                            (Unbalanced) 						
																                 100
				       100										               /     \
				      /    \									              /       \
				     /      \									             80       120
				    80       120								            /   \      / \
				   /  \      / \								          70    90   110  300
				 50    90   110  300							          /\    /\
				 /\    /\										         /  \  /  \
				/  \  /  \										        10 30  85 95
			   10 60  85 95										       /
																      /
																     5


			A tree is said to be balanced at a particular node, if the height difference between Right child and Left child hive is either 0 or 1(or les than 2) 
            Over all Tree is said to be balanced if Root-Node Node is balanced. If any one inner node is out of balance, then whole tree will not be considered as balanced.
		

   */
	class TreeBalanced
	{
		public:
			void callTreeBalanced()
			{
				//Balanced tree
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
			
				
				int x = Balanced(objTrrr.root);
				cout << "Node Height is " << x;;


				//unbalanced tree
				BuildTree objTrrr2;
				objTrrr2.AddValuesUnbalanced();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr2.printTreeInOrder(objTrrr2.root);
				cout << "\r\n";


				int x2 = Balanced(objTrrr2.root);
				cout << "Node Height is " << x2;;
			}

		private:
			//
			int Balanced(NodeTree* root)
			{
				int balanced = 0;
				if (root)
				{
					//Assume the current node is UN Balanced we have not checked the children YET
					balanced = -1;

					int x1 = Balanced(root->L);	//Check if Lc is balanced. If it is balanced then only Try to check Rc.
												//If Lc is unbalanced then there is no need to check Rc 
												//simply return -1.
					if (x1 != -1)
					{
						int x2 = Balanced(root->R);

						if (x2 != -1)
						{	//Both Lc and Rc hives are balanced  when TAKEN ALONE.
							//We have to check if they are balanced when hives are TAKEN TOGATHER
							if (abs(x1 - x2) < 2)
							{	//Yes, Lc and Rc hives are balanced when taken TOGATHER
								//Take the MAX among them and Add 1 to it and return caller.
								balanced = max(x1, x2) + 1; //1 accounts for current node's height
							}
						}
					}
					return balanced;
				}
				else
				{	//If it is NULL, then no tree hight so balanced = 0
					balanced = 0;
				}
				return balanced;
			}
	};
};