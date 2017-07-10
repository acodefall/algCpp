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
namespace ConstructSingleThreadedTreeNM
{
	/*
		Single Threaded Tree
			 In BST tree, node will be pointing to R-Child and L-Child. 
			 Whereas in Threaded-Tree, R-child will always points to a HIGHER-VALUED node, as it appear in "in-order-traversal".
			 Threaded-Tree is made for "in-order-traversal".
			 Say L-child is 5, Parent is 10 and R-child is 15.
			 In case of Threaded Treem, L-child's r-child should point to parent because it is greater in value, and 
			 also the rightThreaded flag should be set to 1.
			 Parent-node will already be pointing to R-child(who's value is higher than Parent-node), we do not modify Parent node.
			 R-child should be modified to point to next higher-node; which could be Left-child of some other parent.

			 So in ordr to convert the BST in to Threaded-Tree, we have to focus on Left-childs and right-childs. 
 
			 Inserting a number in to Threaded-Tree.
			 For inerting a VALUE in to Threaded Tree, iterrate the whole tree and find a suitable slot, and then insert the VALUE as it is 
			 Linked list. If the VALUE is MIN, then VALUE will become left-child for deepest-left-node.
			 We have to also modify the new-node so that its r-child points to parent node.
			 and also the rightThreaded flag should be set to 1.
 
			 If the VALUE is MAX, then VALUE will become right-child of deepest-right-node. Since this is the highest valued node, 
			 this will not pointing to any higher node, nor we will set rightThreaded flag.

			 If the VALUE is in-between MIN and MAX, find the node that is just under the VALUE, and make VALUE the R-child.
			 Say VALUE is 10. There happens to be a node with value 5, and its r-child's value is 15. Then VALUE should come in between 5 and 15.
			 Value 10 will take the place of 15, and then 10 should be made to point to 15, and also the set rightThreaded flag.

			 Insert 50
				50 < 100 make left turn
				50 insert at MIN

			Insert 25
				25 < 100 make left turn
				25 < 50 make left turn
				25 insert at MIN

			Insert 7
				7 < 100 make left turn
				7 < 50 make left turn
				7 < 25 make left turn
				7 insert at MIN

			Insert 20
				20 < 100 make left turn
				20 < 50 make left turn
				20 < 25 make left turn
				20 > 7 make right turn
				20 insert 

			Insert 75
				75 < 100 make left turn
				75 > 50 make right turn
				75 insert in between 50 and 000000000035D330

			Insert 99
				99 < 100 make left turn
				99 > 50 make right turn
				99 insert in between 50 and 000000000035D390

			print SingleThreadedTree
				7
				20
				25
				50
				99
				75
				100

		Navigating Threaded Tree
				Navigation should start from lowest of the values so drill down to deepest-left-node. Then start printing using while loop.
				Note that Threaded tree is setup for 'in order traversal' so take the help of RightTreaded flag for navigation.

				If CURR-Node has RightTreaded  == TRUE, then successor is stored in CURR->Right, so to go that node.
				If CURR-Node has RightTreaded  == FALSE, then successor is the Deepest-Left-node of CURR->Right. Use while-loop for reaching to Deepest-Left-node. So cursor should be set to Curr-.Right itself OR Deepest-Left-node of Curr-.Right.

 
	*/
	class NodeTreeThreaded
	{
		public:
			int d;
			NodeTreeThreaded*	L;
			NodeTreeThreaded*	R;
			bool				RightTreaded; //When this is TRUE, R points to HIGHER node.
			NodeTreeThreaded()
			{
				L = 0;
				R = 0;
				d = 0;
				RightTreaded = false;
			}

			NodeTreeThreaded(int x)
			{
				d = x;
				R = 0;
				L = 0;
				RightTreaded = false;
			}
	};
	class ConstructSingleThreadedTree
	{
		public:
			void callConstructSingleThreadedTree()
			{
				NodeTreeThreaded* rt = new NodeTreeThreaded(100);
				InsertToSingleThreadedTreeX(rt, 50);
				InsertToSingleThreadedTreeX(rt, 25);
				InsertToSingleThreadedTreeX(rt, 7);
				InsertToSingleThreadedTreeX(rt, 20);
				InsertToSingleThreadedTreeX(rt, 75);
				InsertToSingleThreadedTreeX(rt, 99);

				printSingleThreadedTree(rt);
			}

		private:
			//Threaded tree is setup for 'in order traversal' but we still have to check RightTreaded flag for every node.
			//We want to print from MIN to MAX, so first drill down to deepest-left-node, and then start printing.
			//Then start printing. 
			//If the RightTreaded is TRUE, Node is THreaded so use R-Child to go to next node. 
			//Otherwise go to the R-child, and then drill down to it deepest-left-node using while loop.
			//Summarize, next can be reached by using R-Child(if node is Threaded);
            //           otherwise next node is rightChild's deepest-left-child.
			void printSingleThreadedTree(NodeTreeThreaded* r)
			{
				NodeTreeThreaded* cur = r;
				cout << endl << "print SingleThreadedTree" << endl;
				//go to left most
				while ((cur != NULL) && (cur->L != NULL))
					cur = cur->L;

				while (cur != NULL)
				{
					//print current node
					cout << cur->d << endl;

					//figure out successor node and make that as the CURSOR
					if (cur->RightTreaded)
					{	//successor is cur->R itself
						cur = cur->R;
					}
					else
					{
						//successor is deepest-left-child of cur->R
						NodeTreeThreaded* d = cur->R;
						while ((d != NULL) && (d->L != NULL))
							d = d->L;
						cur = d;
					}
				}
			}
			//This will insert one value and exits
			void InsertToSingleThreadedTreeX(NodeTreeThreaded* root, int ValueToInsert)
			{
				NodeTreeThreaded* cur = root;
				cout << endl << "Insert " << ValueToInsert << endl;
				while (cur != NULL)
				{
					//Value is lower so make left-turn
					if (ValueToInsert < cur->d) 
					{ //This block will insert the VALUE, only if it is MIN-value.
					  //makes the VAlue left-child of deepest-left-node
						cout << endl << ValueToInsert << " < " << cur->d << " make left turn" << endl;
						if (cur->L == NULL) //This check is made to see whether we are at the deepest-left-node
						{					//This also cjhecks if value is MIN
							cout << ValueToInsert << " insert at MIN" << endl;
							//This is deepest-left-node, create a new node to place ValueToInsert. 
							//Make the new node 'right-threaded', by making it point to Parent, who's value is higher than newnode
							NodeTreeThreaded* newTemp = new NodeTreeThreaded(ValueToInsert);
							cur->L = newTemp;  //new node should be left child of parent
							newTemp->RightTreaded = true; //New node is RIght threaded and it points to parent
							newTemp->R = cur; //New node is RIght threaded and it points to parent

							break;  //Break because we wanted to insert just one value
						}
						cur = cur->L; //if we 
					}
					else //if (ValueToInsert <= cur->d)
					{	
						cout << endl << ValueToInsert << " > " << cur->d << " make right turn" << endl;

						//Value being added is high
						if (cur->RightTreaded == false)
						{	//This block will insert the VALUE, only if it is MAX-value.
							if (cur->R == NULL) //This also checks if value is MAX
							{
								cout << endl << ValueToInsert << " is MAX insert after " << cur->R << endl;
								NodeTreeThreaded* newTemp = new NodeTreeThreaded(ValueToInsert);
								cur->R = newTemp; //This is MAX value so no need to make it to ppint to any higher value
								break;    //Break because we wanted to insert just one value
							}
						}
						else
						{  //This block will insert the VALUE,  if it is between MIN and MAX.
							//VALUE is is taking the place of existing R-child, so backup the current R-child in to a tempVar.
							//Make the VALUE the new r-child, and then make new-r-child point to previous-r-child (because its value was higher)
							//This is inserting 10 in between 5(parent) and 15(r-child)
							NodeTreeThreaded* tmp = cur->R; //backup the current right child
							NodeTreeThreaded* newTemp = new NodeTreeThreaded(ValueToInsert); //create a new node
							newTemp->RightTreaded = true;
							newTemp->R = tmp;
							cur->R =  newTemp;
							
							
							cout << endl << ValueToInsert << " insert in between " << cur->d << " and " << cur->R<< endl;
							break;
						}
						
						cur = cur->R;
						
					}
				}
			}
	};
};