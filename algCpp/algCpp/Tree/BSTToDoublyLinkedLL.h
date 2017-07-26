#pragma once
#include <iostream>
#include "BuildDLL.h"
#include "BuildTree.h"
/*             
			  100
	         /    \   
			/      \
		  80   	   120		   
		/   \		/ \		
	  70	 90	  110  300	      
	  Takes O(N) time because we make only one pass.
	  Construct Doubly LL out of BST (sorted)_20170528031
		  We have to construct the LL from left to right, in ascending order, so we have to traverse the Tree in in-order fashion.
		  In order to build a Doubly linked list, current node should have prev node, for hooking up. So when doing In-order traversal, pass the prev-LL-Node as one of the recursion parameter.
		  In every round, function should create brand new current-LL-Node, connect it to the prev-LL-Node(coming-in as in put parameter). Before returning, current-LL-Node should be made Prev-Node by assigning it toprev-LL-Node.

		  Say nodes to be created are 10, 20, 30.
		  In the first round prev-LL-Node will be NULL, so function creates the current-LL-Node and it will become the Root Node of LL(this is 10 node). Then assign current-LL-node to prev-LL-Node. In the next round, prev-LL-Node will have value of 10. function will create a node for 20, and hook up 10 & 20, and assignes 20-node as prev-LL-Node.

		  Since we are modifying the prev-LL-Node, pass ** prev-LL-Node.

	  Steps for Construct Doubly LL out of BST (sorted)¬_20170528032

		  1) Start by writing In-order-traversal code
		  2) Recursion parameters be TreeNode, **PrevLLNode, *HeadLL, * TailLL
		  *HeadLL, * TailLL are out parameter and they contain HeadNode and TailNode.
		  *PrevLLNode in IN/OUT parameter.

		  3) in the body create currentLLNode using TreeNode's data
		  4) check if (PrevLLNode == NULL), if so assign 'currentLLNode' to 'PrevLLNode'
		  currentLLNode is root of LL, so assign it to HeadLL.
		  if (PrevLLNode != NULL), connect 'currentLLNode' to 'PrevLLNode', to establish double link.
		  Then assign 'currentLLNode' to 'PrevLLNode'
		  5) Assign every 'currentLLNode' to TailLL. We keep on overwriting the existing value.
		  In the end, value of the last node will remain, and that is the tailNode.

	   


*/
using namespace std;
using namespace BuildTreeNM;
using namespace BuildDbLLNM;
namespace BSTToDoublyLinkedLLNM //@RED20170528031
{
	
	class BSTToDoublyLinkedLL
	{
		public:
			void callBSTToDoublyLinkedLL()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";

				BuildDbLL objDbLL;
				NodeDbLL* tailLL = 0;
				NodeDbLL* headLL = 0;
				ConstructDbListFromLL(objTrrr.root, &objDbLL.root, &headLL, &tailLL);
				objDbLL.root = headLL;
				objDbLL.head = headLL; //Set the head pointer to root
				objDbLL.tail = tailLL; //Set the head pointer to root


				cout << "\r\n";
				cout << "Double LL content(Head to Tail)\r\n";
				objDbLL.printLLHeadToTail(objDbLL.root);
				cout << "\r\n";
				cout << "Double LL content(Tail to Head)\r\n";
				objDbLL.printLLTailToHead(objDbLL.tail);
				cout << "\r\n";

			}

			void ConstructDbListFromLL(NodeTree* rt, NodeDbLL** prevNodeLL, NodeDbLL** headLL, NodeDbLL** tailLL)
			{
				if (rt)
				{
					NodeDbLL* currNodeLL = new NodeDbLL(rt->d);
					ConstructDbListFromLL(rt->L, prevNodeLL, headLL, tailLL);
					if (*prevNodeLL)
					{	//Some Middle node in LL 
						//attach the 'currNodeLL' to 'prevNodeLL'
						(*prevNodeLL)->next = currNodeLL;
						currNodeLL->prev = *prevNodeLL;
					}
					else
					{	//Root Node(head Node of LL)
						*prevNodeLL = currNodeLL;
						*headLL = currNodeLL;
					}
					//Make the currentNode as PreNode.
					//So when control goes from 10 - > 20, the 20 will see 10 as prev-node
					*prevNodeLL = currNodeLL;

					//Every time write the current node to TAIL, in the what ever value is present will be the TAIL.
					*tailLL = currNodeLL;
					ConstructDbListFromLL(rt->R, prevNodeLL, headLL, tailLL);
				}
			}
	};
}