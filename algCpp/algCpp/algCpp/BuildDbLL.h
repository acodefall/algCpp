#pragma once

#pragma once
#include <iostream>
using namespace std;

namespace BuildDbLLNM
{
	class NodeDbLL
	{
		public:
			int d;
			NodeDbLL* next;
			NodeDbLL* prev;
			NodeDbLL()
			{
				next = 0;
				prev = 0;
			}

			NodeDbLL(int x)
			{
				d = x;
				next = 0;
				prev = 0;
			}
	};

	class BuildDbLL
	{
		public:

			NodeDbLL* root;
			NodeDbLL* head;
			NodeDbLL* tail;

			BuildDbLL()
			{
				root = 0;
				tail = 0;
				head = 0;
			}
			void printLL(NodeDbLL* rt)
			{
				NodeDbLL* cur = rt;
				while (cur)
				{
					char c = cur->d;
					cout << c << " ";
					cur = cur->next;
				}
			}

			void printLLHeadToTail(NodeDbLL* rt)
			{
				NodeDbLL* cur = rt;
				while (cur)
				{
					std::cout << cur->d << " ";
					cur = cur->next;
				}
			}

			void printLLTailToHead(NodeDbLL* rt)
			{
				NodeDbLL* cur = rt;
				while (cur)
				{
					std::cout << cur->d << " ";
					cur = cur->prev;
				}
			}

			/*
				10 <-> 15  <->  20  <-> 25  <-> 30  <-> 35  <-> 40  <-> 45  <-> 50  <-> 55  <-> 60  <-> 65  <-> 70  <-> 75  <-> 80  <-> 90  <-> 95
			*/
			void AddValues()
			{
				NodeDbLL* x10 = root = head = new NodeDbLL(10);
				NodeDbLL* x15 = new NodeDbLL(15);
				NodeDbLL* x20 = new NodeDbLL(20);
				NodeDbLL* x25 = new NodeDbLL(25);
				NodeDbLL* x30 = new NodeDbLL(30);
				NodeDbLL* x35 = new NodeDbLL(35);
				NodeDbLL* x40 = new NodeDbLL(40);
				NodeDbLL* x45 = new NodeDbLL(45);

				NodeDbLL* x50 = new NodeDbLL(50);
				NodeDbLL* x55 = new NodeDbLL(55);
				NodeDbLL* x60 = new NodeDbLL(60);
				NodeDbLL* x65 = new NodeDbLL(65);
				NodeDbLL* x70 = new NodeDbLL(70);
				NodeDbLL* x75 = new NodeDbLL(75);

				NodeDbLL* x80 = new NodeDbLL(80);
				NodeDbLL* x85 = new NodeDbLL(85);
				NodeDbLL* x90 = new NodeDbLL(90);
				NodeDbLL* x95 = new NodeDbLL(95);
				tail = x95;


				x10->next =	x15;
				x10->prev = 0;

				x15->next = x20;
				x15->prev = x10;


				x20->next = x25;
				x20->prev = x15;

				x25->next = x30;
				x25->prev = x20;


				x30->next = x35;
				x30->prev = x25;

				x35->next = x40;
				x35->prev = x30;


				x40->next = x45;
				x40->prev = x35;

				x45->next = x50;
				x45->prev = x40;


				x50->next = x55;
				x50->prev = x45;

				x55->next = x60;
				x55->prev = x50;


				x60->next = x65;
				x60->prev = x55;

				x65->next = x70;
				x65->prev = x60;


				x70->next = x75;
				x70->prev = x65;

				x75->next = x80;
				x75->prev = x70;


				x80->next = x85;
				x80->prev = x75;

				x85->next = x90;
				x85->prev = x80;

				x90->next = x95;
				x90->prev = x85;


				x95->next = 0;
				x95->prev = x90;

			}

			~BuildDbLL()
			{
				cout << "\r\n";
				cout << "Deleting DbLL \r\n";
				DelLL(root, root);
				cout << "Deleted DbLL \r\n";
				root = 0;
			}


			// 4 -> 5 -> 8 -> NULL
			//8 should be deleted by 5 when recursion is returning
			//5 should be deleted by 5 when recursion is returning
			//4 should be when "rt == head" when recursion is returning
			void DelLL(NodeDbLL* rt, NodeDbLL* head)
			{
				if (rt->next)
				{
					DelLL(rt->next, head);
					if (rt == head)
						delete rt;
					else if (rt->next)
						delete rt->next;
				}
			}

	};
};
