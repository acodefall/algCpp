#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;
namespace ReverseEveryKNodesNM //@RED2017072507
{
	
	/*
		
		ip:	10 15 20	25 30 35	40 45 50	55 60 65	70 75 80		85 90 95
		op:	20 15 10	35 30 25	50 45 40	65 60 55	80 75 70		95 90 85
	
	*/
	class ReverseEveryKNodes
	{
		public:
			void callReverseEveryKNodes()
			{
				int K = 3;
				BuildLL sLL;
				sLL.AddValues();
				
				cout << "\r\n";
				cout << "SLL \r\n";
				BuildLL::printLL(sLL.root);
				cout << "\r\n";

				NodeSLL* rev = ReverseEveryKNodesX(sLL.root, K);
				cout << "\r\n";
				cout << "SLL after reversing every " << K << " nodes \r\n";
				BuildLL::printLL(rev);
				cout << "\r\n";

			}

			//1 2 3    4 5 6     7 8 9 
			//k = 3
			//3 2 1    6 5 4     9 8 7         
			NodeSLL* ReverseEveryKNodesX(NodeSLL* rt, int K)
			{
				NodeSLL* cur = rt;
				NodeSLL* prev = rt;
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
					NodeSLL* nextK = cur->next;
					cur->next = rt->next;

					rt->next = ReverseEveryKNodesX(nextK, K);
				
					return cur; //head
				}
				return 0;
			}

	
	};

};