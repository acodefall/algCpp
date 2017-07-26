#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildDLL.h"
using namespace std;
using namespace BuildLLNM;
using namespace BuildDbLLNM;
namespace RevLLNM //@RED20170725035
{
	

	class RevLL
	{
		public:

			void callRevLL()
			{
				callRevLLWhile();
			}

			void callRevLLWhile()
			{
				BuildLL objLL78;
				objLL78.AddValues();

				cout << "before \r\n";
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";
				NodeSLL* rev = reversetSLL(objLL78.root);
				cout << "After Reversal\r\n";
				BuildLL::printLL(rev);
				cout << "\r\n";

			}

			void callRevLLRecursion()
			{
				BuildLL objLL78;
				objLL78.AddValues();

				cout << "before \r\n";
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";
				NodeSLL* rev = reversetSLL(objLL78.root);
				cout << "After Reversal\r\n";
				BuildLL::printLL(rev);
				cout << "\r\n";

			}

			NodeSLL* reversetSLL(NodeSLL* rt)
			{
				NodeSLL* cur = rt;
				NodeSLL* prev = 0;
				while (cur != nullptr)
				{
					//backup the CONTENT of curr before altering its content (that is curr->next)
					NodeSLL* tmp = cur->next; 
					
					//Now modify the content of cur by making it point BACKWARDS
					cur->next = prev;
					
					//Backup the cur itself
					prev = cur;

					//adjust the cur to point to NEXT node
					cur = tmp;
				}
				return prev;
			}

			NodeSLL* reversetSLLRecursion(NodeSLL* rt, NodeSLL* prev)
			{
				NodeSLL* cur = rt;
			
				if (cur != nullptr)
				{
					//backup the CONTENT of curr before altering its content (that is curr->next)
					NodeSLL* tmp = cur->next;

					//Now modify the content of cur by making it point BACKWARDS
					cur->next = prev;

					//Backup the cur itself
					prev = cur;

					//adjust the cur to point to NEXT node
					cur = tmp;

					reversetSLLRecursion(tmp, cur);
				}
				else
					return rt;
			}
	};
};