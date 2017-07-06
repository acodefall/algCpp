#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;
namespace MergeSortedLLNM
{
	
	/*
		

	*/
	class MergeSortedLL
	{
		public:
			void callMergeSortedLL()
			{
				BuildLL objLL78;
				objLL78.AddValues(10);

				
				BuildLL objLL79;
				objLL79.AddValues(20);


				//Print LL 
				cout << "LL to be merged " <<endl;
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";
				BuildLL::printLL(objLL79.root);
				cout << "\r\n";

				

				cout << "Merged LL is " << endl;
				NodeSLL* mergedLL = MergeLL(objLL78.root, objLL79.root);
				BuildLL::printLL(mergedLL);
				
			
			}

			NodeSLL* MergeLL(NodeSLL* l1, NodeSLL* l2)
			{
			
				{
					NodeSLL* mergedHead = NULL; //This will be returned to caller 
					NodeSLL* mergedTail = NULL;//TAIL is needed because new nodes are attached to TAIL.

					NodeSLL* currL1 = l1;
					NodeSLL* currL2 = l2;

					//We do not use the existing Node object provided by L1 and L2.
					//Instead we create a Brand new Node and barrow only the value from L1 and L2.
					//For brand new Node
					//	-We have to assign value
					//  -Connect it to prev-Node (we do this with the help of TAIL node. TAIL node gives us the PREV node.	
					//							 whenever we create a brand new node, we attach the new node to Tail->Next
					//							 This will make sure that the LINKS are good
					while ((currL1 != NULL) && (currL2 != NULL))
					{
						//allocate new Node
						NodeSLL* newNode = new NodeSLL();

						//Set the value to NewNode. Value should be Lower among L1 and L2
						if (currL1->d < currL2->d)
						{
							newNode->d = currL1->d; //Assign the value to New node
							currL1 = currL1->next; //Advance the LL who's value we use
						}
						else
						{
							newNode->d = currL2->d;
							currL2 = currL2->next;
						}

						//If 'newNode' is the First one to be built, then set as HEAD and also TAIL.
						//In subsequent rounds, 'newNode' will be attached to TAIL only.
						if (mergedHead == NULL)
						{
							mergedHead = newNode;
							mergedTail = newNode;
						}
						else
						{
							mergedTail->next = newNode;
							mergedTail = newNode;
						}

					}

					while (currL1 != NULL)
					{
						NodeSLL* newNode = new NodeSLL();
						newNode->d = currL1->d;
						mergedTail->next = newNode;
						mergedTail = mergedTail->next;

						currL1 = currL1->next;
					}

					while (currL2 != NULL)
					{
						NodeSLL* newNode = new NodeSLL();
						newNode->d = currL2->d;
						mergedTail->next = newNode;
						mergedTail = mergedTail->next;
						currL2 = currL2->next;
					}
					return mergedHead;
				}
			}

			
	};
};