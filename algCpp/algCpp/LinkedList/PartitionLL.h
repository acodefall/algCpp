#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;
namespace PartitionLLNM
{
	
	/*
		

	*/
	class PartitionLL
	{
		public:
			void callPartitionLL()
			{
				BuildLL objLL78;
				objLL78.AddValues(10);

				
			

				//Print LL 
				cout << "LL to be partitioned " <<endl;
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";
			

				

				PartitionLLX(objLL78.root, 41);
			}


			void PartitionLLX(NodeSLL* llSrc, int partValue)
			{
				NodeSLL* cur = llSrc;

				NodeSLL* head1 = NULL;
				NodeSLL* head2 = NULL;
				NodeSLL* tail1 = NULL;//TAIL is needed because new nodes are attached to TAIL.
				NodeSLL* tail2 = NULL;
				
				//Nodes of llSrc will be put to LL1 or LL2 based on Partition value
				//Create a brand new node object(newNode), and load the value that is in llSrc in to newNode, 
				//and then attach either newNode to either LL1 or LL2, based on Part value

				while (cur != NULL)
				{
					NodeSLL* newNode = new NodeSLL();
					newNode->d = cur->d; //assign value to New node
					if (cur->d <= partValue)
					{
						if (head1 == NULL) //first node of LL, so set it to both LL1 and LL2
						{
							head1 = newNode;
							tail1 = newNode;
						}
						else
						{
							tail1->next = newNode; //current-Tail's next should point to newNode
							tail1 = newNode; //Then change the Tail to new node
						}
					}
					else if (cur->d > partValue)
					{
						if (head2 == NULL) //first node of LL, so set it to both LL1 and LL2
						{
							head2 = newNode;
							tail2 = newNode;
						}
						else
						{
							tail2->next = newNode; //current-Tail's next should point to newNode
							tail2 = newNode; //Then change the Tail to new node
						}
					}
					cur = cur->next;
				}

				cout << "Print the partitioned LL. Partition value " << partValue << endl;
				//print the two LL
				BuildLL::printLL(head1);
				cout << endl;
				BuildLL::printLL(head2);
				cout << endl;
			}

			
	};
};