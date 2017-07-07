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
namespace CheckTreeIsIdenticalNM
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
			To judge whether two Tress are mirror We have one node from each other.
			Compare rightChild of T1 against leftChild of T2. If one is NULL then other has to be NULL too.
			If every nodes satisfies this condition then we can say that Tress are Mirror.
			To implement this do Inorder traversal of both the tree at the same time, so inoder traversal code will have two Node pointers.
			If the nodes are mirror, value should be same irrespective of whether it is NULL or non-NULL.
			In case the values are same, we have to make children are also Mirror, so make recursion call.
			Nodes passed to recursion should come from different trees and they should be of different type. 
			Say rightChild from T1 and leftChild from T2 gets paired.
			Similaraly rightChild from T2 and leftChild from T1 gets paired.
			AND the return values of the recursion call and pass it to caller.
			If one recursion returns FALSE, then theer is no reason to make 2nd recursion.


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