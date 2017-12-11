#pragma once
#include <iostream>
#include "BuildLL.h"

using namespace std;
using namespace BuildLLNM;
namespace PalidroneUsingRecursionNM //@RED20170725040
{
	
	/*
		Check if LL is palidrone_RED20170725040
			Palidrone check invlves comparing first and last element; then comparing 2nd and max-1 element.
			This can be done using recursion. Do the comparison in post-recursion code.
			Assume that cursor has made the U turn.
			The very First comparison will try to match TAIL against the root-node.
			Return TRUE to outer-layer, if there is a match; otherwise it returns FALSE to outer-layer.
			Outer layer should check the return value of recursion, if it is FALSE, it should not do any 
			more comparison because word is no more palidrone. It should simply propgate the FALSE return code to next top layer.
			
			Post-recursion code compared against Head-node so Head node should be passed as recursion param.
			After the U-turn, as stack-unwinds, the Head-node cursor starts moving towards Tail. 
			For this to happen, after every comparison, post-recursion code should advance the root-node ptr.
			Root node should be pointer-to-pointer.
			
			Coming to implementation, iterate the LL using recursion. 
			Rec Params are cursor and pointer to Head-node. Cursor moves from L-R and Head-node pointer stays the same till U-turn.
			After the U-turn, Head node makes starts moving towards tail.
			
	
	*/
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