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
				d = 0;
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
			NodeSLL* tail;
			BuildLL()
			{
				root = NULL;
				tail = NULL;
			}
			static void printLLPalidrone(NodeSLL* rt)
			{
				NodeSLL* cur = rt;
				while (cur)
				{
					char c = cur->d;
					cout << c << " ";
					cur = cur->next;
				}
			}

			static void printLL(NodeSLL* rt)
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
				AddValues(0);
			}

			void AddValuesDuplicates(int startValue = 0)
			{
				
				NodeSLL* x10 = root = new NodeSLL(10 + startValue);
				NodeSLL* x15 = new NodeSLL(10 + startValue);
				NodeSLL* x20 = new NodeSLL(15 + startValue);
				NodeSLL* x25 = new NodeSLL(25 + startValue);
				NodeSLL* x30 = new NodeSLL(15 + startValue);
				NodeSLL* x35 = new NodeSLL(35 + startValue);
				NodeSLL* x40 = new NodeSLL(40 + startValue);
				NodeSLL* x45 = new NodeSLL(45 + startValue);

				NodeSLL* x50 = new NodeSLL(50 + startValue);
				NodeSLL* x55 = new NodeSLL(55 + startValue);
				NodeSLL* x60 = new NodeSLL(40 + startValue);
				NodeSLL* x65 = new NodeSLL(35 + startValue);
				NodeSLL* x70 = new NodeSLL(70 + startValue);
				NodeSLL* x75 = new NodeSLL(75 + startValue);

				NodeSLL* x80 = new NodeSLL(80 + startValue);
				NodeSLL* x85 = new NodeSLL(65 + startValue);
				NodeSLL* x90 = new NodeSLL(90 + startValue);
				NodeSLL* x95 = new NodeSLL(95 + startValue);



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


				x95->next = NULL;
				tail = x95;
				
			}

			void AddValues(int startValue)
			{
				NodeSLL* x10 = root = new NodeSLL(10 + startValue);
				NodeSLL* x15 = new NodeSLL(15 + startValue );
				NodeSLL* x20 = new NodeSLL(20 + startValue );
				NodeSLL* x25 = new NodeSLL(25 + startValue );
				NodeSLL* x30 = new NodeSLL(30 + startValue );
				NodeSLL* x35 = new NodeSLL(35 + startValue );
				NodeSLL* x40 = new NodeSLL(40 + startValue );
				NodeSLL* x45 = new NodeSLL(45 + startValue );

				NodeSLL* x50 = new NodeSLL(50 + startValue );
				NodeSLL* x55 = new NodeSLL(55 + startValue );
				NodeSLL* x60 = new NodeSLL(60 + startValue );
				NodeSLL* x65 = new NodeSLL(65 + startValue );
				NodeSLL* x70 = new NodeSLL(70 + startValue );
				NodeSLL* x75 = new NodeSLL(75 + startValue );

				NodeSLL* x80 = new NodeSLL(80 + startValue );
				NodeSLL* x85 = new NodeSLL(85 + startValue );
				NodeSLL* x90 = new NodeSLL(90 + startValue );
				NodeSLL* x95 = new NodeSLL(95 + startValue );



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
			

				x95->next = NULL;
				tail = x95;
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