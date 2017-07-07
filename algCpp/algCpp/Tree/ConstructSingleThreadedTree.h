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
			}

		private:
			//This will insert one value and exits
			void InsertToSingleThreadedTreeX(NodeTreeThreaded* root, int ValueToInsert)
			{
				NodeTreeThreaded* cur = root;
				while (cur != NULL)
				{
					NodeTreeThreaded* newTemp = new NodeTreeThreaded(ValueToInsert);
					
					
					//Value is lower so make left-turn
					if (ValueToInsert < cur->d) 
					{ //This block will insert the VALUE, only if it is MIN-value.
					  //makes the VAlue left-child of deepest-left-node

						if (cur->L == NULL) //This check is made to see whether we are at the deepest-left-node
						{					//This also cjhecks if value is MIN
							//This is deepest-left-node, create a new node to place ValueToInsert. 
							//Make the new node 'right-threaded', by making it point to Parent, who's value is higher than newnode
							cur->L = newTemp;
							cur->RightTreaded = true;
							cur->R = cur;
							break;  //Break because we wanted to insert just one value
						}
						cur = cur->L; //if we 
					}
					else if (ValueToInsert < cur->R->d)
					{	//Value being added is high
						if (cur->RightTreaded == false)
						{	//This block will insert the VALUE, only if it is MAX-value.
							if (cur->R == NULL) //This also checks if value is MAX
							{
								cur->R = newTemp; //This is MAX value so no need to make it to ppint to any higher value
								break;    //Break because we wanted to insert just one value
							}
						}
						else
						{  //This block will insert the VALUE,  if it is between MIN and MAX.
							//VALUE is is taking the place of existing R-child, so backup the current R-child in to a tempVar.
							//Make the VALUE the new r-child, and then make new-r-child point to previous-r-child (because its value was higher)
							//This is inserting 10 in between 5(parent) and 15(r-child)
							NodeTreeThreaded* tmp = cur->R;
							cur->R = newTemp;
							newTemp->R = tmp;
							newTemp->RightTreaded = true;
							break;
						}
						cur = cur->R;
					}
				}
			}
	};
};