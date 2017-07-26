#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
#include "BuildTree.h"
using namespace std;
using namespace BuildLLNM;
using namespace BuildTreeNM;
namespace LinkedListToBSTConvertionNM //@RED20170725056
{
	
	/*
		Input:
			10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95
		Output: 
				80

	*/
	class LinkedListToBSTConvertion
	{
		public:
			NodeSLL* gblLLCurr;
			NodeTree* gblNewTreeRoot;

			LinkedListToBSTConvertion()
			{
				gblLLCurr = 0;
				gblNewTreeRoot = 0;
			}
			void callLinkedListToBSTConvertion()
			{
				BuildLL objLL78;
				objLL78.AddValues();

				
				//Print LL 
				cout << "LL: " <<endl;
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";

				

				gblLLCurr = objLL78.root;
				int len = 18;
				NodeTree* nn = LinkedListToBSTConvertionX( 0, len - 1);
			
				cout << "Tree is contructed " << endl;
				BuildTree forPrinting;
				forPrinting.printTreeInOrder(nn);
			}

			NodeTree* LinkedListToBSTConvertionX(int L, int H)
			{
				int mid = 0;
				if (L < H)
				{
					
					mid = L + (H - L) / 2;
					cout << " [" << L << "]  [" << mid << "]  [" << H << "] LL is at " << gblLLCurr->d << endl;

					NodeTree* treeL = LinkedListToBSTConvertionX(L, mid - 1);
					

					NodeTree* treeP = new NodeTree(gblLLCurr->d);
					
					if (gblNewTreeRoot == NULL)
						gblNewTreeRoot = treeP;
					treeP->L = treeL;

					print1(treeP);
					

					gblLLCurr = gblLLCurr->next;
					treeP->R = LinkedListToBSTConvertionX(mid + 1, H);

					
					print2(treeP);
					return treeP;
				}
				else
				{
					cout << " [" << L << "]  [" << mid << "]  [" << H << "] LL is at " << gblLLCurr->d << endl;
					return NULL;
				}
			}

			void print1(NodeTree* p)
			{
				cout << "P-tree ";
				if(p)
					cout << p->d;

				cout << " L-tree ";

				if (p && p->L)
					cout << p->L->d;
				cout << endl;
			}

			void print2(NodeTree* p)
			{
				cout << "P-tree ";
				if (p)
					cout << p->d ;

				cout << " L-tree ";

				if (p && p->L)
					cout << p->L->d;
				
				cout << " R-tree ";

				if (p && p->R)
					cout << p->R->d;

				cout << endl;
			}
	};
};