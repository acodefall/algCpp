#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;

namespace AddTwoLLNM //@RED20170820010
{
	/*	TBD
		TBD
		
			Add the digits stored in two LL_@RED20170820010
			
			When we are iterating LL cursor goes from Left-Right. but addition shoud happen from right-left.
			We have to come with a logic so that we add the numbers when the cursor is moving from Tail to Heas.
			We can do this using LL.
			
			Logic is as follows. Recursion has two phases pre and post.
			In pre-recusion Cursor goes from Head->Tail (that is 1 -> 3).
			In post-recusion Cursor goes from Tail->Head (that is 3 -> 1)
			We have to add the numbers in post-recursion code, and create a node and store the sum in that node.
			Additon operation will generate CARRY OVER and this should be passed to outer-layer.
			When the stack-unwinds, the outer caller should get the carryOver; 
			Pass the carryOver as POINTER-recursion-parameter.
			We can also send the carryOver through return-value. But there can be only one retrurn code
			so it is better to pass as part of recursion parameter.

			Coming to implementation. same Recursion function should iterate both the LL, at the same time.
			Since both LL are of same length, recursion will break at the same point.
			
			
			(Note: The pre-recursion code can pass a value to next-level of recursion, 
			  using by-value parameter. 
					
			   Where as post-recursion code has to use by-reference parameter for passing 
			   a value to the next level. Means pass the value to the outer layer.
			   When the stack-unwinds, control goes to outer layer, the outer-caller should get the value. 
			   In order to achieve this, pass the parameter using BY-REFERENCE.
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

			/*
			
			
			
			void AddUsingRecurion(NodeSLL* llSrc1, NodeSLL* llSrc2, NodeSLL** NewLLTail, int* carryOver)
			{
				int sum = 0;
				*carryOver  =0;
				if((llSrc1 == NULL) || (llSrc2 == NULL))
				{
					break;
				}
				
				AddUsingRecurion(llSrc1, llSrc2, NewLLTail, carryOver);
				
				//Add the numbers taken from LL
				sum = llSrc1->d + llSrc2->d;
				
				//Add carry-over to sum
				sum += carryOver;
				
				NodeSLL* newNode = new NodeSLL(sum);
				newNode->next = *NewLLTail;
				newNode->d = sum % 10;
				carryOver = sum / 10;
			}
			*/
			
	};

}