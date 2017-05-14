#pragma once
#include<iostream>

namespace ReverseDoublyLinkedListNM
{
	template<typename T>
	class Node78Dbl
	{
		public:
			T d;
			Node78Dbl<T>* next;
			Node78Dbl<T>* prev;

			Node78Dbl(T x)
			{
				d = x;
				next = 0;
				prev = 0;
			}
	};

	void printLLHeadToTail(Node78Dbl<int>* rt)
	{
		Node78Dbl<int>* cur = rt;
		while (cur)
		{
			std::cout << cur->d << " ";
			cur = cur->next;
		}
	}
	
	void printLLTailToHead(Node78Dbl<int>* rt)
	{
		Node78Dbl<int>* cur = rt;
		while (cur)
		{
			std::cout << cur->d << " ";
			cur = cur->prev;
		}
	}


	class ReverseDoublyLinkedListX
	{
		public:
			void callRevDLL()
			{
				Node78Dbl<int> root(1);
				Node78Dbl<int> x2(2);
				Node78Dbl<int> x3(3);
				Node78Dbl<int> x4(4);
				Node78Dbl<int> x5(5);
				Node78Dbl<int> x6(6);
				Node78Dbl<int> x7(7);
				Node78Dbl<int> x8(8);
				Node78Dbl<int> x9(9);

				root.next = &x2;
				x2.next = &x3;
				x2.prev = &root;

				x3.next = &x4;
				x3.prev = &x2;

				x4.next = &x5;
				x4.prev = &x3;

				x5.next = &x6;
				x5.prev = &x4;

				x6.next = &x7;
				x6.prev = &x5;

				x7.next = &x8;
				x7.prev = &x6;

				x8.next = &x9;
				x8.prev = &x7;

				x9.next =  0;
				x9.prev = &x8;

				head = &root;
				tail = &x9;

				std::cout << "before Head to Tail \r\n";
				printLLHeadToTail(head);

				std::cout << "\r\n before Tail to Head \r\n";
				printLLTailToHead(tail);
				
				revreseDoublyLL(head);

				std::cout << "After Head to Tail \r\n";
				printLLHeadToTail(tail);

				std::cout << "\r\n After Tail to Head \r\n";
				printLLTailToHead(head);
			}

			/*
				H -> 1n  ->  2n  ->  3n -> 4n -> NULL
				N <- 1p   <- 2p  <-  3p <- 4p <- T

   
				Reverse
				
				0 <- 1n  <-  2n  <-  3n <- 4n <- H
				T -> 1p  -> 2p   ->  3p -> 4p -> N
			
			*/
			Node78Dbl<int>* head ;
			Node78Dbl<int>* tail;
			void revreseDoublyLL(Node78Dbl<int>* rt)
			{
				Node78Dbl<int>* cur = rt;
				Node78Dbl<int>* tailTmp = rt; //This is Post-Rev-Tail
				Node78Dbl<int>* headTmp = 0; //This is Post-Rev-Head
				while (cur)
				{
					Node78Dbl<int>*	Tmp = cur->next;
					cur->next = cur->prev;
					cur->prev = Tmp;
					cur = Tmp;
					if (cur != 0)
						headTmp = cur; //THis could be last Node, so store it as Post-Rev-Head
				}
			}
	};
};