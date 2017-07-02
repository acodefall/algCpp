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
namespace SwapAlternativeKthNodeNM
{
	
	class SwapKthNode
	{
		public:
			void callSwapKthNode()
			{
				BuildLL sLL;
				sLL.AddValues();
				
				cout << "\r\n";
				cout << "print SLL \r\n";
				sLL.printLL(sLL.root);
				cout << "\r\n";

				NodeSLL* rev = reverseKthNode(sLL.root, 3);
				cout << "\r\n";
				cout << "print SLL after reversal\r\n";
				sLL.printLL(rev);
				cout << "\r\n";

			}

			//1 2 3 4 5 6 7 8 9 
			//k = 3
			//3 2 1 6 5 4 9 8 7         
			NodeSLL* reverseKthNode(NodeSLL* rt, int K)
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

					rt->next = reverseKthNode(nextK, K);
				
					return cur; //head
				}
				return 0;
			}

	
	};

};