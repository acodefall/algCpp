#pragma once
#include <iostream>
#include <unordered_map>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;
namespace RemoveDuplicateNodesLLNM
{
	
	/*
		

	*/
	class RemoveDuplicateNodesLL
	{
		public:
			void callRemoveDuplicateNodesLL()
			{
				BuildLL objLL78;
				objLL78.AddValuesDuplicates(0);

				
			

				//Print LL 
				cout << "LL to remove duplicates " <<endl;
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";
			

				
				cout << "LL to remove duplicates using Loop" << endl;
				RemoveDuplicatesUsingLoop(objLL78.root);
				BuildLL::printLL(objLL78.root);

				BuildLL objLL79;
				objLL79.AddValuesDuplicates(0);
				cout << endl << "LL to remove duplicates using Hash table" << endl;
				RemoveDuplicatesUsingHashTable(objLL79.root);
				BuildLL::printLL(objLL79.root);

				/*
					LL to remove duplicates
						10 10 15 25 15 35 40 45 50 55 40 35 70 75 80 65 90 95
							LL to remove duplicates using Loop
								10 15 25 35 40 45 50 55 70 75 80 65 90 95
							LL to remove duplicates using Hash table
								10 15 25 35 40 45 50 55 70 75 80 65 90 95
				*/
				
			}

			void RemoveDuplicatesUsingLoop(NodeSLL* llSrc)
			{
				/*
					When comparing two nodes,  cursor can stay at A, and compare with B. OR cursor can stay at B and compare against A.
					Here first copy the value of A to X.
					Then keep the cursor at A, and compare B's value against X; then move cursor to B, and compare C's value against X.
					If the value is same then link B and D nodes, and set the cursor to D.
					
					We copy the value of A to temp-variable, so that we do not have to carry along A all the time.

					This takes O(N2) time
				*/
				NodeSLL* cur = llSrc;
				while (cur != NULL)
				{
					int X = cur->d; 
					NodeSLL* cur2 = cur; //cur2 range is "cur -> END"
					while ((cur2 != NULL) && (cur2->next != NULL))
					{
						if (cur2->next->d == X)		//Say value has nodeA's X, and cur2 is at D. We compare E's value against X  
						{								//If they are same linkup both D and F, and set the cursor to F
							cur2->next = cur2->next->next; 
							cur2 = cur2->next->next;
						}
						else
							cur2 = cur2->next;
					}
					cur = cur->next;
				}
			}

			

			void RemoveDuplicatesUsingHashTable(NodeSLL* llSrc)
			{
				unordered_set<int> hashset;

				/*
					Insert node[0] in to hash_set, 
					set prevCursor = node[0]
					set curCursor = node[1]
					Then start a while loop to go from node[1] to END.
					In every loop adjust both prevCursor & curCursor
					
					This takes O(N) time
				*/
				NodeSLL* cur = llSrc;
				NodeSLL* prev = NULL;
				hashset.insert(cur->d); //Before going inside loop, insert the 1st node of LL in to hash_set, so that you can check against subsequent node 
				prev = cur;
				cur = cur->next;
				while (cur != NULL)
				{
					if (hashset.find(cur->d) == hashset.end())
					{
						hashset.insert(cur->d);
						prev = cur;
						cur = cur->next;
					}
					else
					{	//value is present, link D and F(prev=D, cur=E, cur->next=F)
						prev->next = cur->next;

						//Let F be cursor
						cur = cur->next;
					}
				}
			}
	};
};