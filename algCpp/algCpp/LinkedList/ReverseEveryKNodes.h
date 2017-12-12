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
namespace ReverseEveryKNodesNM
{
	
	/*
		Reverse Every K Nodes  abd Reverse K altarnative Nodes
		Reverse K Nodes means: If K =5. Revese first 5items within themself.
								Revese next 5items within themself.
								Divide the LL as small-LL of size 5, and reverse each LL
								within itself, as if each LL is seperate. 
		
								In case of reversing altarnative K elements,
								we do the same thing but we reverse altarnative segments.
								
		Reverse K altarnative Nodes means: Here also we divide the LL in to chunks of
								5 but reverse only the alternative chunks, 
								
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

			//1 2 3 9    4 5 6 3     7 8 9 1
			//k = 4
			//9 3 2 1    3 6 5 4     1 9 8 7         
			NodeSLL* ReverseEveryKNodesX(NodeSLL* rt, int K)
			{
				NodeSLL* cur = rt;
				NodeSLL* prev = rt;
				int Ki = K;
				if (rt)
				{
					//k
					//a  b  c 	1 2 3 	x y z
					//process/reverse K nodes
					while ((Ki > 0) && (cur))
					{
						//Reverse logic modifies only the current node.
						//Backup the elements that are going to get modified. Like Curr.Next
						NodeSLL* tmp = cur->next;
						prev = cur;
						cur = tmp;
						Ki--;
					}

				
					//Reverse next K elements
					rt->next = ReverseEveryKNodesX(cur, K);
				
					return prev; //post-reverse Head
				}
				return 0;
			}

	
	};

};