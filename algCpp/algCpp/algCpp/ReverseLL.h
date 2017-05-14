#pragma once
#include <iostream>
#include <memory>
using namespace std;

namespace RevLLNM
{
	template<typename T>
	class Node78
	{
		public:
			T d;
			Node78<T>* next;

			Node78(T x)
			{
				d = x;
				next = 0;
			}
	};

	void printLL(Node78<int>* rt)
	{
		Node78<int>* cur = rt;
		while (cur)
		{
			cout << cur->d << " ";
			cur = cur->next;
		}
	}


	class RevLL
	{
		public:
			void callRevLL()
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

				cout << "before \r\n";
				printLL(&root);
				cout << "\r\n";
				Node78<int>* rev = reversetLL(&root);
				cout << "After \r\n";
				printLL(rev);

			}
			Node78<int>* reversetLL(Node78<int>* rt)
			{
				Node78<int>* cur = rt;
				Node78<int>* prev = 0;
				while (cur != nullptr)
				{
					Node78<int>* tmp = cur->next;
					cur->next = prev;
					prev = cur;
					cur = tmp;
				}
				return prev;
			}
			

		

	};
};