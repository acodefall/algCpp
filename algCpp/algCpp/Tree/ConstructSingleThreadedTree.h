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
		Single Threaded Tree_20170707004
			 
			 In Threaded-Tree, R-child of every node will  point to next HIGHER-VALUED node.
			 This helps in "in-order-traversal" without using STACK. In case of TREE, navigating downwards to
			 left-most corner node can be done without STACK; but navigating UP requires STACK.
			 Single threaded eliminates the need for STACK during UP ward navigation.

			 Node in STT will have a special flag called 'right threaded' and if it is true, then r-child property points
			 to higher node. Navigation code will If the flag is not set then Node behaves like traditional BST node.

			 SIT traversal code will first drive down to left-most corner(note that STACK is not for making left).
			 From there cursor start moving towards right-most node.
			 Navigation code should handle both SIT and non-SIT nodes; so it checks whether the node has RThreaded flag set.
			 If the flag is set, then stack-traversal will happen; if the flag is OFF, then traditional
			 inorder traversal using STACK will start. 
			 

			 INSERTING a number in to Threaded-Tree_20170707006 20170707009
				User calls the insert function() once for inserting every number in the tree.
				New node should be made R-child of CURRENT Node, taking in to account whether Rc have any value and whether currNode is already singled-threaded.
				If the current node is already singled-threaded, then new node should be sandwitched/INSERTed between
				existing-Rc and Parent node(current node).
				If the current node is NOT singled-threaded, simply assign the NewNode to Rc, provided the Rc is NULL. 
				If Rc has some value do not overwrite it.
				
				It is also possible that new-node has lowest value, then new node should be made the 1st element.
				This code will go under ( V < c.D).
				
				Coming to impl, make left trun as usual but never make right right at all. When (V > c.d) create the node node and break
				
				
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

		Navigating Threaded Tree 20170707008
				Code Navigating the SingleThreadedTree does not use STACK. This is because Rc is supposed to have next higher value,
				so cursor should jump from Rc to Rc. 
				But Some of the nodes may not be right-threaded and we have to account for it also. 
				If CURR-Node has RightTreaded  == TRUE, then successor is stored in CURR->Right, so to go that node.
				If CURR-Node has RightTreaded  == FALSE, then successor is the Deepest-Left-node of CURR->Right. Use while-loop for reaching to Deepest-Left-node. So cursor should be set to Curr-.Right itself OR Deepest-Left-node of Curr-.Right.
				Navigation should start from beginning so first drill down to lef-most node.
				Then start a while loop to navigate.
				
				
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
				NodeTreeThreaded* parent = root;
				cout << endl << "Insert " << ValueToInsert << endl;
				while (cur != NULL)
				{
					parent = cur;
					
					//Value is lower so make left-turn
					if (ValueToInsert < cur->d) 
					{ 
						if (cur->L == NULL) 
						{	//Left child is NULL so we can not go any further so insert the new node here
							cout << ValueToInsert << " insert at MIN" << endl;
							
							//create a new node to place ValueToInsert. 
							NodeTreeThreaded* newTemp = new NodeTreeThreaded(ValueToInsert);
							cur->L = newTemp;  //new node should be left child of parent
							newTemp->RightTreaded = true; //New node is RIght threaded and it points to parent
							newTemp->R = cur; //New node is RIght threaded and it points to parent
							break;  //Break because we wanted to insert just one value
						}
						cur = cur->L; 
					}
					else //if (ValueToInsert <= cur->d)
					{	
						//Value being added is high
						if (cur->RightTreaded == false)
						{	//This block will insert the VALUE, only if it is MAX-value.
							if (cur->R == NULL) //This also checks if value is MAX
							{
								NodeTreeThreaded* newTemp = new NodeTreeThreaded(ValueToInsert);
								cur->R = newTemp; //This is MAX value so no need to make it to ppint to any higher value
								break;    //Break because we wanted to insert just one value
							}
						}
						else
						{   //This block will insert the VALUE,  if it is between MIN and MAX.
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
					
						
					}
				}
			}
			
			/*
				converts existing Bst in to Right-threaded tree
				convertTreeToThreadedTree(N, NPrev)
				{
					if(N)
					{
						//reverse inorder
						
						convertTreeToThreadedTree(N.rc, N);
						if(N.rc == NULL && Nprev != NULL)
						{
							N.rc = Nprev;
							N.rightThreded = true;
						}
						convertTreeToThreadedTree(N.lc, N);
						
					}
				
				}
			
			
			
			*/
	};
};