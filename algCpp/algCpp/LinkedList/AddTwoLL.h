#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;

namespace AddTwoLLNM //@RED20170820010
{
	/*
		Add the digits stored in two LL_@RED20170820010
			Say LL1 will have “2 & 2” and LL2 will have “5 & 8”. We have to add them as if we are adding 22 + 58; only difference is addition goes from L->R, so the carry over too. Ideally addition should travel R->L, that is start from TAIL. 
			In this case, 22+58 will result in “701”; and result should be stored in brand new LL.
			
			Coming to inplementation, Iterate both LL in the same loop; and continue as long as at least one of the cursor is non-null
			Both the LL may not be of same length. In that case, for the shorter LL, assume the value as 0, and execute the same addition logic, as if the value is non-null.

				If (sum >= 10) //Do special logic. //if sum = 25; "carryOver=2" "sum=5"
					carryOver = sum/10;
					sum = sum%10;
			Once sum is ready, store it in a brand new Node 
			Once whole addition is complete, function should return the Head of resultLL.

			Note: sum = v1 + v2 + carryOver(from previous round)

						2->6->7		//LL1
						5->0->5->8  //LL2
						7->6->2->9	//(sum)

	*/
	class AddTwoLL
	{
		public:
			void CallAddTwoLL()
			{
				BuildLL objLL1;
				objLL1.AddValuesSmallNumber267();

				BuildLL objLL2;
				objLL2.AddValuesSmallNumber5058();

				//Print LL 
				cout << "LL to be added " << endl;
				BuildLL::printLL(objLL1.root);
				cout << "\r\n";
				BuildLL::printLL(objLL2.root);

				NodeSLL* resultLL = AddLL(objLL1.root, objLL2.root);
				if (resultLL != NULL)
				{
					cout << "Print the SUM-LL" << endl;
					BuildLL::printLL(resultLL);
				}
				/*
					LL to be added
					2 6 7  //LL1
					5 0 5 8  //LL2
					7 6 2 9 (sum)
				*/
			}

			NodeSLL* AddLL(NodeSLL* llSrc1, NodeSLL* llSrc2)
			{
				NodeSLL* cur1 = llSrc1;
				NodeSLL* cur2 = llSrc2;
				NodeSLL* resultHead = NULL;
				NodeSLL* resultTail = NULL;
				int carryOver = 0;
				
				//iterate both LL. Loop should continue as long as one of the NODE is valid.
				//Both the LL may not be of same length. In that case one of LL is going to reach TAIL before the other.
				//In that case assume the value to be 0.
				while ((cur1 != NULL) || (cur2 != NULL))
				{
					
					int v1 = 0; //val
					int v2 = 0;

					//Read values from LL. If any of the LL has already reached the TAIL, then assume the vaue to be 0.
					if (cur1 != NULL)
						v1 = cur1->d;

					if (cur2 != NULL)
						v2 = cur2->d;

					//Add the values of TWO nodes, and also carryOver.
					int sum = v1 + v2 + carryOver;

					//reset the carryOver
					carryOver = 0;
				
					//If sum is more than 10, we have to carryOver the 'sum/10'
					if (sum >= 10)
					{
						carryOver = sum / 10;//if sum = 25; "carryOver=2" "sum=5" 
						sum = sum % 10;
					}
				
					
					//assign the SUM to NEWly created node
					NodeSLL* newNode = new NodeSLL(sum);
					if (resultHead == NULL)
					{	//First node of result so assign the new node to both HEAD and TAIL. Both point to the ONLY node present.
						resultHead = newNode;
						resultTail = newNode;
					}
					else
					{	//LL is already present. attach the newNode to TAIL. Then modify the TAIL to point to NewNode
						resultTail->next = newNode;

						//make resultTail point to newNode
						resultTail = newNode;
					}
					
					//advance the cursors
					if(cur1 != NULL)
						cur1 = cur1->next;

					if (cur2 != NULL)
						cur2 = cur2->next;
				}
				

				
				return resultHead;
			}
	};

}