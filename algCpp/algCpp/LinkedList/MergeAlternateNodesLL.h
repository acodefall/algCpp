#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;
namespace MergeAlternateNodesLLNM //@RED20170731003
{
	
	/*
		TBD-READ
		Merge Alternative Nodes of LL_20170731003

	*/
	class MergeAlternateNodesLL
	{
		public:
			void callMergeAlternateNodesLL()
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

				

				cout << "Alternatively Merged LL is " << endl;
				NodeSLL* mergedLL = MergeAlternateNodesLLX(objLL78.root, objLL79.root);
				BuildLL::printLL(mergedLL);
				
			
					/*
						LL to be merged
							20 25 30 35 40 45 50 55 60 65 70 75 80 85 90  95  100 105
							30 35 40 45 50 55 60 65 70 75 80 85 90 95 100 105 110 115
					Alternatively Merged LL is
							20 35 30 45 40 55 50 65 60 75 70 85 80 95 90 105 100 115
					
					*/
			}

			NodeSLL* MergeAlternateNodesLLX(NodeSLL* l1, NodeSLL* l2)
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
					int id = 1;
					while ((currL1 != NULL) && (currL2 != NULL))
					{
						//allocate new Node
						NodeSLL* newNode = new NodeSLL();

						//Set the value to NewNode. Use LL1 as source
						if(id == 1)
						{
							newNode->d = currL1->d; //Assign the value to New node
							
							id = 2;
						}
						else
						{
							newNode->d = currL2->d;
							id = 1;
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

						//advance both the nodes.
						currL2 = currL2->next;
						currL1 = currL1->next; //Advance the LL who's value we use
					}

					
					return mergedHead;
				}
			}

			
	};
};