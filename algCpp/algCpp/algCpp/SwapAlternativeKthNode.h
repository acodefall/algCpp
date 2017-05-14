#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>

using namespace std;
namespace SwapAlternativeKthNodeNM
{
	template<typename T>
	class SwapKthNode
	{
		template<typename T>
		class Node78
		{
		public:
			T d;
			Node78* next;

			Node78(T x)
			{
				d = x;
				next = 0;
			}
		};

		void printLL(Node78<T>* rt)
		{
			Node78<T>* cur = rt;
			while (cur)
			{
				cout << cur->d << " ";
				cur = cur->next;
			}
		}

		public:
			void callSwapKthNode()
			{
				Node78<int> root(1);
				Node78<int> x2(2);
				Node78<int> x3(3);
				Node78<int> x4(4);
				Node78<int> x5(5);
				Node78<int> x6(6);
				Node78<int> x7(7);
				Node78<int> x8(8);
				Node78<int> x9(9);

				root.next = &x2;
				x2.next = &x3;
				x3.next = &x4;
				x4.next = &x5;
				x5.next = &x6;
				x6.next = &x7;
				x7.next = &x8;
				x8.next = &x9;

				printLL(&root);
				Node78<T>* rev = reverseKthNode(&root, 3);
				printLL(rev);

			}

			//1 2 3 4 5 6 7 8 9 
			//k = 3
			//3 2 1 6 5 4 9 8 7         
			Node78<T>* reverseKthNode(Node78<T>* rt, int K)
			{
				Node78<T>* cur = rt;
				Node78<T>* prev = rt;
				int Ki = K;
				if (rt)
				{
					//skip K
					while ((Ki > 1) && (cur))
					{
						prev = cur;
						cur = cur->next;
						Ki--;
					}

					//Reverse
					prev->next = rt;
					Node78<T>* nextK = cur->next;
					cur->next = rt->next;

					rt->next = reverseKthNode(nextK, K);
				
					return cur; //head
				}
				return 0;
			}

	
	};

};