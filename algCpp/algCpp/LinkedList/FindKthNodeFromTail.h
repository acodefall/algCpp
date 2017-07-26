#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;

namespace FindKthNodeFromTailNM //@RED20170725043
{
	
	/*
		Input:
			10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95
		Output: 
				80

	*/
	class FindKthNodeFromTail 
	{
		public:
			void callFindKthNodeFromTail()
			{
				BuildLL objLL78;
				objLL78.AddValues();

				int K = 4;
				
				//Print LL 
				cout << "Find Kth Node From Tail K " << K <<endl;
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";

				

				
				int value = FindKthNodeFromTailX(objLL78.root, 4); //80
			
				cout << K <<"th value is " << value << endl;

			}
			int FindKthNodeFromTailX(NodeSLL* rt, int K)
			{
				NodeSLL* cur = rt;
				NodeSLL* curK = rt;
				int Kn = K;

				//Move curK to Kth position
				while ((Kn > 0) && (curK != NULL))
				{
					curK = curK->next;
					Kn--;
				}

				//iterate curK to END.
				while (curK != NULL)
				{
					curK = curK->next;
					cur = cur->next;
				}

				return cur->d;
			}
	};
};