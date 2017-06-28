#pragma once
#include <iostream>
using namespace std;

namespace BuildLLNM
{
	class NodeSLL
	{
		public:
			int d;
			NodeSLL* next;
			NodeSLL()
			{
				next = 0;
			}

			NodeSLL(int x)
			{
				d = x;
				next = 0;
			}
	};

	class BuildLL
	{
		public:

			NodeSLL* root;

			BuildLL()
			{
				root = 0;
			}
			void printLLPalidrone(NodeSLL* rt)
			{
				NodeSLL* cur = rt;
				while (cur)
				{
					char c = cur->d;
					cout << c << " ";
					cur = cur->next;
				}
			}

			void printLL(NodeSLL* rt)
			{
				NodeSLL* cur = rt;
				while (cur)
				{
					cout << cur->d << " ";
					cur = cur->next;
				}
			}

			void AddValues()
			{

				NodeSLL* x10 = root = new NodeSLL(10);
				NodeSLL* x15 = new NodeSLL(15);
				NodeSLL* x20 = new NodeSLL(20);
				NodeSLL* x25 = new NodeSLL(25);
				NodeSLL* x30 = new NodeSLL(30);
				NodeSLL* x35 = new NodeSLL(35);
				NodeSLL* x40 = new NodeSLL(40);
				NodeSLL* x45 = new NodeSLL(45);

				NodeSLL* x50 = new NodeSLL(50);
				NodeSLL* x55 = new NodeSLL(55);
				NodeSLL* x60 = new NodeSLL(60);
				NodeSLL* x65 = new NodeSLL(65);
				NodeSLL* x70 = new NodeSLL(70);
				NodeSLL* x75 = new NodeSLL(75);

				NodeSLL* x80 = new NodeSLL(80);
				NodeSLL* x85 = new NodeSLL(85);
				NodeSLL* x90 = new NodeSLL(90);
				NodeSLL* x95 = new NodeSLL(95);



				x10->next = x15;
			
				x15->next = x20;
			

				x20->next = x25;
			
				x25->next = x30;
			

				x30->next = x35;
			
				x35->next = x40;
			

				x40->next = x45;
			
				x45->next = x50;
			

				x50->next = x55;
			
				x55->next = x60;
			

				x60->next = x65;
			
				x65->next = x70;
			

				x70->next = x75;
			
				x75->next = x80;
			

				x80->next = x85;
			
				x85->next = x90;
			
				x90->next = x95;
			

				x95->next = 0;
			}

			void AddValuesPalidrone()
			{
				root = new NodeSLL('l');
				NodeSLL* x2 = new NodeSLL('i');
				NodeSLL* x3 = new NodeSLL('v');
				NodeSLL* x4 = new NodeSLL('e');
				NodeSLL* x5 = new NodeSLL('e');
				NodeSLL* x6 = new NodeSLL('v');
				NodeSLL* x7 = new NodeSLL('i');
				NodeSLL* x8 = new NodeSLL('l');


				root->next = x2;
				x2->next = x3;
				x3->next = x4;
				x4->next = x5;
				x5->next = x6;
				x6->next = x7;
				x7->next = x8;
			}

			~BuildLL()
			{
				cout << "\r\n";
				cout << "Deleting SLL \r\n";
				DelLL(root, root);
				cout << "Deleted SLL \r\n";
				root = 0;
			}


			// 4 -> 5 -> 8 -> NULL
			//8 should be deleted by 5 when recursion is returning
			//5 should be deleted by 5 when recursion is returning
			//4 should be when "rt == head" when recursion is returning
			void DelLL(NodeSLL* rt, NodeSLL* head)
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