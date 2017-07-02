#pragma once
#include<iostream>
#include "BuildDbLL.h"
using namespace BuildDbLLNM;

namespace ReverseDoublyLinkedListNM
{
	class ReverseDoublyLinkedListX
	{
		public:
			void callRevDLL()
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
				H -> 1n  ->  2n  ->  3n -> 4n -> NULL
				N <- 1p   <- 2p  <-  3p <- 4p <- T

   
				Reverse
				
				0 <- 1n  <-  2n  <-  3n <- 4n <- H
				T -> 1p  -> 2p   ->  3p -> 4p -> N
			
			*/
			void revreseDoublyLL(NodeDbLL* rt)
			{
				NodeDbLL* cur = rt;
				NodeDbLL* tailTmp = rt; //This is Post-Rev-Tail
				NodeDbLL* headTmp = 0; //This is Post-Rev-Head
				while (cur)
				{
					NodeDbLL*	Tmp = cur->next;
					cur->next = cur->prev;
					cur->prev = Tmp;
					cur = Tmp;
					if (cur != 0)
						headTmp = cur; //THis could be last Node, so store it as Post-Rev-Head
				}
			}
	};
};