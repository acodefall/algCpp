#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace CheckTreeIsIdenticalNM //@RED20170725060
{
	/*
		Mirror Trees
			Mirror Trees can be visualized as follows.
			If original tree has 3 nodes (parent, and 2 children); then the mirror image of that tree will also have
			same Parent node but the children will be swapped.
			
			(Original)     (Mirror image)
			    20              20
 
			10     30       30      10

		Implementation
			Two nodes are said to be mirror if the left-child of 1st node has same value as right-child of 2nd node.
			And viceversa. But the Parent's value should be same.
 
			A tree is said to be mirror, if every node of the tree exhibits MIRROR behaviour.
			Verifying whether the Tree is mirror will Iterate the tree using pre-order recursion and checks one node from T1 against a node from T2.
			Function will be iterating two trees at the same time, so the function will recieve two cursors as input parameter.
			Pre-recursion coder will check
			-if both cursors are NULL, if so breaks the recursion and returns TRUE.
			-if both cursors have same value, then proceed further to check whether their children are mirror, by making TWO rec call.
			If both the recs return TRUE, then the both the child hives are mirror.
			For 1st recursion call pass left-child of 1st node and right-child of 2nd node as parameter.
			For 2nd recursion call pass right-child of 1st node and left-child of 2nd node as parameter.
			Post recursion code will collect the ret code of recursion calls and both should return TRUE.
			Function ANDa the return of recursion calls and returns to caler.
 
			Pre-recursion code will generate genuine return value, where it checks whether cursors are NULL, and whether node-values have same value.
			Post-recursion code will simply pass the AND of the return values returned by two recursion funcs.
			Whole TREE is said to be Mirror if control reaches the point where both the nodes, passed as input are NULL


			Tree T1:
					10 50 60 80 85 90 95 100 110 120 300
			Tree T2:
					300 120 110 100 95 90 85 80 60 50 10
			
			Compare
				n1: 100 n2: 100
				n1: 80 n2: 80
				n1: 50 n2: 50
				n1: 10 n2: 10
					Null
					Null
				n1: 60 n2: 60
					Null
					Null
				n1: 90 n2: 90
				n1: 95 n2: 95
					Null
					Null
				n1: 85 n2: 85
					Null
					Null
				n1: 120 n2: 120
				n1: 300 n2: 300
					Null
					Null
				n1: 110 n2: 110
					Null
					Null
				Mirror is 1
	*/
	class CheckTreeIsIdentical
	{
	public:
		void callCheckTreeIsIdentical()
		{
			BuildTree T1;
			BuildTree T2;
			
			
			cout << endl << "Tree T1: " << endl;
			T1.AddValues();
			BuildTree::printTreeInOrder(T1.root);

			cout << endl << "Tree T2: " << endl;
			T2.AddValues();
			BuildTree::printTreeInOrder(T2.root);
			
			bool bIdentical = CheckTreeIsIdenticalX(T1.root, T2.root);

			cout << endl << "Trees are Identical " << bIdentical << endl;
		}

	private:
		void bUildMirrorTrees(NodeTree** n1, NodeTree** n2)
		{
				/*
			               100										              100
                          /    \									            /     \
                         /      \									           /       \
                        80       120								          120       80
                       /  \      / \								         /  \      /  \
                     50    90   110  300							      300   110   90   50
                     /\    /\														  /\    /\
                    /  \  /  \										                 /  \  /  \
                   10 60  85 95										                95  85 60  10
			*/

				(*n1) = new NodeTree(100);
				(*n1)->L = new NodeTree(80);
				(*n1)->R = new NodeTree(120);

				(*n1)->L->L = new NodeTree(50);
				(*n1)->L->R = new NodeTree(90);

				(*n1)->L->L->L = new NodeTree(10);
				(*n1)->L->L->R = new NodeTree(60);

				(*n1)->L->R->L = new NodeTree(85);
				(*n1)->L->R->R = new NodeTree(95);


				(*n1)->R->L = new NodeTree(110);
				(*n1)->R->R = new NodeTree(300);
			

				(*n2) = new NodeTree(100);
				(*n2)->R = new NodeTree(80);
				(*n2)->L = new NodeTree(120);
				

				(*n2)->R->R = new NodeTree(50);
				(*n2)->R->L = new NodeTree(90);
				
				(*n2)->R->R->R = new NodeTree(10);
				(*n2)->R->R->L = new NodeTree(60);
				
				(*n2)->R->L->R = new NodeTree(85);
				(*n2)->R->L->L = new NodeTree(95);
				

				(*n2)->L->L = new NodeTree(300);
				(*n2)->L->R = new NodeTree(110);
		}

		bool CheckTreeIsIdenticalX(NodeTree *n1, NodeTree *n2)
		{
			bool NodesAreIdentical = false;

			if ((n1 == NULL) && (n2 == NULL))
			{
				cout << endl << "Null" << endl;
				NodesAreIdentical = true;
			}
			else
			{
				if (n1->d == n2->d)
				{
					cout << endl << "n1: " << n1->d << " n2: " << n2->d << endl;
					bool left = CheckTreeIsIdenticalX(n1->L, n2->L);
					if (left)
					{
						bool right = CheckTreeIsIdenticalX(n2->R, n1->R);
						if (right)
							NodesAreIdentical = true;
					}
					else
					{
						cout << endl << "n1: " << n1->d << " n2: " << n2->d << endl;
					}
				}
				else
				{
					cout << endl << "n1: " << n1->d << " n2: " << n2->d << endl;
				}
			}
			return NodesAreIdentical;
		}
	};
};