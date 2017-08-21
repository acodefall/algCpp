#pragma once
#include <iostream>
#include "BuildLL.h"
#include <memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;

namespace ValueOfMidNodeNM //@RED20170820008
{
	/*
		Find the Mid node in LL_@RED20170820008
		   Using one-hop and two-hop technique iterate the LL.
		   When 2hop cursor reaches TAIL, 1hop cursor should be at mid node of LL
	*/
	class ValueOfMidNode
	{
		public:
			void CallValueOfMidNode()
			{
				BuildLL objLL78;
				objLL78.AddValues(10);


				//Print LL 
				cout << "LL to be partitioned " << endl;
				BuildLL::printLL(objLL78.root);
				cout << "\r\n";

				int x = FindMidValue(objLL78.root);
				cout << "Mid value '" << x << "'" << endl;
			}

			//Using one-hop and two-hop technique iterate the LL.
			//When 2hop cursor reaches TAIL, 1hop cursor should be at mid point
			int FindMidValue(NodeSLL* llSrc)
			{
				NodeSLL* cur = llSrc;
				NodeSLL* cur2Step = llSrc;

				//iterate using 1-hop and 2-hop technique
				//cur2Step will reach the TAIL when cur is still at MID-node
				while ((cur2Step != NULL) && (cur != NULL))
				{
					cur = cur->next;
					cur2Step = cur2Step->next->next;
				}

				///cur2Step will be at TAIL
				//Now read the value held by cur
				if (cur != NULL)
				{
					return cur->d;
				}
				else
					return -1;
			}
	};

}