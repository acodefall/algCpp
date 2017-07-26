#pragma once
#include <iostream>
#include "BuildLL.h"

using namespace std;
using namespace BuildLLNM;
namespace PalidroneUsingRecursionNM //@RED20170725040
{
	class PalidroneUsingRecursion
	{
		public:
			void CallPalidroneUsingRecursion()
			{		
					BuildLL objLL78;
					objLL78.AddValuesPalidrone();
					cout << "before palidrone check\r\n";
					objLL78.printLLPalidrone(objLL78.root);
					cout << "\r\n";

					NodeSLL* tmp = objLL78.root;
					bool x = palicheck(&tmp, tmp);
					if(x == true)
						cout << "Palidrone found \r\n";
					else
						cout << "not a Palidrone \r\n";

			}

			bool palicheck(NodeSLL** root, NodeSLL* next)
			{
				bool retvalue = true;
				if (next == 0)
				{
					return retvalue;
				}

				retvalue = palicheck(root, next->next);

				if (retvalue == false)
					return retvalue;

				if ((*root)->d == next->d)
				{
					char c = next->d;
					*root = (*root)->next;
					cout << c << "\r\n";
				}
				else
					retvalue = false;

				return retvalue;
			}
	};
};