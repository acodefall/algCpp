#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;

namespace RevLLNM
{
	

	class RevLL
	{
		public:
			void callRevLL()
			{
				BuildLL objLL78;
				objLL78.AddValues();

				cout << "before \r\n";
				objLL78.printLL(objLL78.root);
				cout << "\r\n";
				NodeSLL* rev = reversetLL(objLL78.root);
				cout << "After Reversal\r\n";
				objLL78.printLL(rev);
				cout << "\r\n";

			}
			NodeSLL* reversetLL(NodeSLL* rt)
			{
				NodeSLL* cur = rt;
				NodeSLL* prev = 0;
				while (cur != nullptr)
				{
					NodeSLL* tmp = cur->next;
					cur->next = prev;
					prev = cur;
					cur = tmp;
				}
				return prev;
			}
	};
};