#pragma once
#include<iostream>
#include "BuildDLL.h"
using namespace BuildDbLLNM;

namespace ReverseDoublyLinkedListNM //@RED2017072505
{
	class ReverseDoublyLinkedListX
	{
		public:

			void callRevDLL()
			{
				callRevDLLRecursion();
				callRevDLLWhile();
			}

			void callRevDLLRecursion()
			{
				BuildDbLL dbLL;
				dbLL.AddValues();

				std::cout << "before Head to Tail \r\n";
				dbLL.printLLHeadToTail(dbLL.head);

				std::cout << "\r\n before Tail to Head \r\n";
				dbLL.printLLTailToHead(dbLL.tail);

				NodeDbLL* hd = reverseRecursion(dbLL.head);

				std::cout << "After Head to Tail \r\n";
				dbLL.printLLHeadToTail(hd);

				//std::cout << "\r\n After Tail to Head \r\n";
				//dbLL.printLLTailToHead(hd);
			}

			void callRevDLLWhile()
			{
				BuildDbLL dbLL;
				dbLL.AddValues();

				std::cout << "before Head to Tail \r\n";
				dbLL.printLLHeadToTail(dbLL.head);

				std::cout << "\r\n before Tail to Head \r\n";
				dbLL.printLLTailToHead(dbLL.tail);
				
				revreseDoublyLL(dbLL.head);

				std::cout << "After Head to Tail \r\n";
				dbLL.printLLHeadToTail(dbLL.tail);

				std::cout << "\r\n After Tail to Head \r\n";
				dbLL.printLLTailToHead(dbLL.head);
			}

			/*
						1n  ->  2n  ->  3n -> 4n -> NULL
				NULL <- 1p   <- 2p  <-  3p <- 4p <- T

   
				Reverse
				
				0 <- 1n  <-  2n  <-  3n <- 4n <- H
				T -> 1p  -> 2p   ->  3p -> 4p -> N
			
			*/
			void revreseDoublyLL(NodeDbLL* rt)
			{
				NodeDbLL* cur = rt;
				NodeDbLL* headTmp = 0; //This is Post-Rev-Head
				
				while (cur)
				{
					//backup the CONTENT of curr before altering its content (that is curr->next)
					NodeDbLL*	Tmp = cur->next;

					//Modify the cur node 
					cur->next = cur->prev;
					cur->prev = Tmp;
					
					//set the cursor for NEXT node for iteration
					cur = Tmp;

					if (cur != 0)
						headTmp = cur; //THis could be last Node, so store it as Post-Rev-Head
				}
			}

			//
			//Last node to be processed is the post-reversal-HEAD, so we should pass this all way to the top most layer.
			//Last node should return its cur-node, and every one above the chain should simply return it unchanged.
			//Note that Last node will call Tail-Node, and Tail-Node will return NULL to Last Node. 
			//Last-node should not return NULL, instead it should return its own NODE.
			//So in post-recursion code, check if recursion has returned non-NULL, if so return whatever was returned.
			//If the recursion is has returned NULL, then ignore the return code and pass the node that YOU modified. 
			//Tail-Node which comes after Last-Node will return NULL, we need to ignore that.
			NodeDbLL* reverseRecursion(NodeDbLL* rt)
			{
				NodeDbLL* cur = rt;
				NodeDbLL* headTmp = 0; //This is Post-Rev-Head
				NodeDbLL* retNode = 0;
				if (rt != NULL)
				{
					//backup the CONTENT of curr before altering its content (that is curr->next)
					NodeDbLL*	Tmp = cur->next;

					//Modify the cur node 
					cur->next = cur->prev;
					cur->prev = Tmp;

					//set the cursor for NEXT node for iteration
					cur = Tmp;

					//Last node to be processed is the post-reversal-HEAD, so we should pass this all way to the top most layer.
					//Last node should return its cur-node, and every one above the chain should simply return it unchanged.
					//Note that Last node will call Tail-Node, and Tail-Node will return NULL to Last Node. 
					//Last-node should not return NULL, instead it should return its own NODE.
					//In post-recursion code, check if recursion has returned non-NULL, if so return whatever was returned.
					retNode = reverseRecursion(cur);
					if (retNode == NULL) //Tail - Node which comes after LastNode will return NULL, we need to ignore that.
						retNode = cur;
					return retNode;
				}
				else
					return rt;
			}
	};
};