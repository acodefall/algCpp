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
		DLL should be built from L to R in Ascending order.
		BST will produce asceding data in in-order traversal.
		So iterate the BST using in-order-traversal and construct the LL-nodes.
		Every loop creates a New LL-Node. This needs to be connected to pre-LL_node,
		so pass previous-LL-node as rec param.

		Cominng to impl. Write In-order traversal code. 
		Create the LL-node right at the top, assign current-BST node's value to new-LL-node.
		Do this when the controld is in between the two recursion calls.
		And also connect the new-LL-node to pre-LL-node(passed as rec param)

		Then When making right-rec call pass new-LL-node as parameter. 

		  Since we are modifying the prev-LL-Node, pass ** prev-LL-Node.

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