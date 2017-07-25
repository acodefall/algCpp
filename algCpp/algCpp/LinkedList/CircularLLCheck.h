#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;

namespace CircularLLCheckNM //@RED2017072509
{
	
	/*
		Input:
			10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95
		Meet at:
			10   10
			LL is circular. Meet at 10
			Look for loop length. Start.Data 10
			Look for loop length. Start.Data 10end data 95


	*/
	class CircularLLCheck
	{
		public:
			void callCircularLLCheck()
			{
				BuildLL objLL78;
				objLL78.AddValues();

				//Print before setting up circular loop
				cout << "before \r\n";
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";

				//Create a loop
				//this will setup the LOOP
				if(objLL78.tail)
					objLL78.tail->next = objLL78.root;
				///

				

				//Find the loop
				CircularLLCheckX(objLL78.root);
			
				cout << "\r\n";

			}
			bool CircularLLCheckX(NodeSLL* rt)
			{
				bool circular = false;
				int LoopLen = 0;
				NodeSLL* oneHop = rt;
				NodeSLL* twoHop = rt;
				while (oneHop != nullptr)
				{
					cout << endl << setw(3) << oneHop->d << "  " << setw(3) << twoHop->d << endl;

					if (oneHop == twoHop)
					{
						circular = true;
						cout << "LL is circular. Meet at " << oneHop->d << endl;

						//find the loop length
						//In order to find the loop length we have to traverse the loop, starting from the point where they meet.
						//So first we have to find the point of intersection and from there we have to take one step at a time.
						//If we want to terminate the loop also we have to first come to the point and then set the NEXT pointer to NULL.
						//Means last node's Next pointer should be set to NULL
						
						NodeSLL* Start = oneHop;
						cout << "Look for loop length. Start.Data " << Start->d << endl;
						while (Start != oneHop->next)
						{
							oneHop = oneHop->next;
							LoopLen++;
						}
						cout << "Look for loop length. Start.Data " << Start->d << "end data "<< oneHop->d << endl;
						
						//Break the loop by setting Next pointer to NULL
						oneHop->next = NULL;
						break;
					}
					oneHop = oneHop->next;
					twoHop = oneHop->next->next;
				}
				return circular;

				/*NodeLLS N1 = rt;
				NodeLLS N2 = rt.next.next;
				int LoopLen = 0;
				while (N1 != null)
				{
					if (N1 == N2)
					{   //found the point of inter-section

						//Find the Loop-length. We initialize the Length to 1 because we are comparing
						//N1.next against N2. And N1 is already advanced 
						LoopLen = 1;
						while (N1.next != N2)
						{
							LoopLen++;
							N1 = N1.next;
						}

						//Break the loop by setting to NULL
						N1.next = null;
						break;
					}
					else
					{
						N1 = N1.next;
						N2 = N2.next.next;
					}
				}*/
			}
	};
};