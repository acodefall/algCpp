#pragma once
#include <iostream>
using namespace std;
namespace BuildTreeNM
{
	class NodeTree
	{
		public:
			int d;
			NodeTree* L;
			NodeTree* R;
			NodeTree()
			{
				L = 0;
				R = 0;
				d = 0;
			}

			NodeTree(int x)
			{
				d = x;
				R = 0;
				L = 0;
			}
	};

	class BuildTree
	{
		public:

			NodeTree* root;

			BuildTree()
			{
				root = 0;
			}
			static void printTreeInOrder(NodeTree* rt)
			{
				NodeTree* cur = rt;
				if (cur)
				{
					printTreeInOrder(rt->L);
					cout << rt->d << " ";
					printTreeInOrder(rt->R);
				}
			}

			/*		     (BST)
			               100
                          /    \
                         /      \
                        80       120
                       /  \      / \
                     50    90   110  300
                     /\    /\
                    /  \  /  \
                   10 60  85 95
			*/

			void AddValues()
			{
				root = new NodeTree(100);
				root->L = new NodeTree(80);
				root->R = new NodeTree(120);

				root->L->L = new NodeTree(50);
				root->L->R = new NodeTree(90);

				root->L->L->L = new NodeTree(10);
				root->L->L->R = new NodeTree(60);

				root->L->R->L = new NodeTree(85);
				root->L->R->R = new NodeTree(95);


				root->R->L = new NodeTree(110);
				root->R->R = new NodeTree(300);
			}

			/*        (Non BST)  Plain Tree
			                100
                          /     \
                         /       \
                        80       120
                       /   \      / \
                     70    90   110  300
                     /\    /\
                    /  \  /  \
                   10 30  85 95
			*/
			void AddValuesNonBST()
			{
				root = new NodeTree(100);
				root->L = new NodeTree(80);
				root->R = new NodeTree(120);

				root->L->L = new NodeTree(70);
				root->L->R = new NodeTree(90);

				root->L->L->L = new NodeTree(10);
				root->L->L->R = new NodeTree(30);

				root->L->R->L = new NodeTree(85);
				root->L->R->R = new NodeTree(95);


				root->R->L = new NodeTree(110);
				root->R->R = new NodeTree(300);
			}


				/*        (LCA)
			                20
                          /     \
                         /       \
                        8       22
                       /  \      
                      4   12     
                          /\
                         /  \
                        10  14
			*/
			void AddValuesLCA()
			{
				root = new NodeTree(20);
				root->L = new NodeTree(8);
				root->R = new NodeTree(22);

				root->L->L = new NodeTree(4);
				root->L->R = new NodeTree(12);

				root->L->R->L = new NodeTree(10);
				root->L->R->R = new NodeTree(14);
			}

			
			/*        (Unbalanced) 
			                100
                          /     \
                         /       \
                        80       120
                       /   \      / \
                     70    90   110  300
                     /\    /\
                    /  \  /  \
                   10 30  85 95
				   /
                  /
				  5
				 
			*/
			void AddValuesUnbalanced()
			{
				root = new NodeTree(100);
				root->L = new NodeTree(80);
				root->R = new NodeTree(120);

				root->L->L = new NodeTree(70);
				root->L->R = new NodeTree(90);

				root->L->L->L = new NodeTree(10);
				root->L->L->R = new NodeTree(30);

				root->L->R->L = new NodeTree(85);
				root->L->R->R = new NodeTree(95);


				root->R->L = new NodeTree(110);
				root->R->R = new NodeTree(300);

				root->L->L->L->L = new NodeTree(5);
			}
			~BuildTree()
			{
				cout << "\r\n";
				cout << "Deleting Tree\r\n";
				DeleteTree(root);
				cout << "Deleted Tree\r\n";
			}


			
			void DeleteTree(NodeTree* rt)
			{
				NodeTree* cur = rt;
				if (cur)
				{
					DeleteTree(rt->R);


					DeleteTree(rt->L);
					if (rt)
					{
						delete rt;
					}
				}
			}
	};
};