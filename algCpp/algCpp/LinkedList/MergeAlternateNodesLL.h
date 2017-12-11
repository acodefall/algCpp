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
	
		Merge Alternative Nodes of LL_20170731003
		//Merge the alterante nodes from two LL. 
		//Merge the ODD elements from LL1 with the EVEN elements of LL2.
		//LL1[1], LL2[2], LL1[3], LL2[4]
		//Use two cursors, and hop by two nodes at a time. And in every loop take one element from each LL1 and one element from LL2. 
		//Join the two nodes and attach it to Merged-LL.
		//Then advance the cursor by two positions.
		//Key thing is, before beginning the iteration, cursors should be placed one place apart.
		//Means 1st cursor = 1st position of LL1
		//      2nd cursor = 2nd position of LL2
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
					
					
					
					LL to be merged
							20 25 30 35 40 45 50 55 60 65 70 75 80 85
							aa bb cc dd ee ff gg hh ii jj kk ll mm nn 
					Alternatively Merged LL is
							20 bb 30 dd 40 ff 50 hh 60 jj 70 ll 80 nn
							
					*/
			}

			
			
			NodeSLL* MergeAlternateNodesLLX(NodeSLL* l1, NodeSLL* l2)
			{
			
				{
					NodeSLL* mergedHead = NULL; //This will be returned to caller 
					NodeSLL* mergedTail = NULL;//TAIL is needed because new nodes are attached to TAIL.

					//IMPORTANT: Cursors should start by POSITION APART
					NodeSLL* currL1 = l1;
					NodeSLL* currL2 = l2->next;

					while ((currL1 != NULL) && (currL2 != NULL))
					{
						//allocate TWO new Nodes
						//allocate ONE Node
						NodeSLL* newNode1 = new NodeSLL();
						newNode1->d = currL1->d; //Assign the value to New node
						
						//allocate SECOND Node
						NodeSLL* newNode2 = new NodeSLL();
						newNode2->d = currL2->d;
							
						//attach both the NEW nodes
						newNode1->next = newNode2;

						//If 'newNode' is the First one to be built, then set as HEAD and also TAIL.
						//In subsequent rounds, 'newNode' will be attached to TAIL only.
						if (mergedHead == NULL)
						{
							mergedHead = newNode1;
							mergedTail = newNode2;
						}
						else
						{
							mergedTail->next = newNode1;
							mergedTail = newNode2;
						}

						//advance both the cursors by TWO positions
						currL1 = currL1->next->next;
						currL2 = currL2->next->next;
					}

					
					return mergedHead;
				}
			}

			
	};
};