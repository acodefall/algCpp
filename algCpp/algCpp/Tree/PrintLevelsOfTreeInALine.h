#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;


/*
		Print every level of Tree in a seperate line_20170731001
		Compute the height of Tree_20170731009
			In BFS navigation, 1st level will introduce 2nd-level in to Q.
			Similarly 2nd level will introduce 3rd-level in to Q. 
			Before 1st-level introduces the 2nd-level in to Q, Q will have nothing but the nodes of 1st-level.
			So, before introducing the 2nd level in Q, if we can print whatever is already present in the Q, 
			then we will be printing the content of 1st-level in a straight line.
			That is exactly what we want to do.
			
			1st-level will eject the nodes from the Q; and prints them; and then injects thier children in to bottom of the Q. 
			This is a self-feeding loop.
			As older nodes get ejected, the newly added child nodes (of belonging to next-level) will rise in Q; and they will eventually occupy 100% of Q.
			Ejecting code knows the number of old nodes that existed before the injection operation; so it ejects only those mumber of nodes.
			Ejecting code will not eject any newly added child nodes.

			At the end of this ejection operation logic, Q will have just the content of 2nd-level. 
			And 2nd-level will applay the same logic. It prints the q-content and also introduces 3rd-level in to Q. 
			
			This code can be used for counting the levels also. 

			
						100							
					  /    \			(Only 2nd level in Q)	(Eject/print/addchild of 80)	
					 /      \			  80                        80
					80       120		  120						120						
				   /  \      / \		  						    50						
				 50    90   110  300	  						    90						
				 /\    /\				  						                        
				/  \  /  \				                            
			   10 60  85 95

										(Eject/print/addchild	(Only 3rd level in Q)
											 of 120)				
										  120					  50
										  50					  90
										  90					  110
										 110					  300
										 300 					   





*/
namespace PrintEveryLevelOfTreeInALineNM //@RED20170731001 @RED20170731009
{
	class PrintEveryLevelOfTreeInALine
	{
	public:
		void callPrintEveryLevelOfTreeInALine()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			PrintEveryLevelOfTreeInALineX(objTrrr.root);
		}

	private:
		//This can be used to know tree height also
		void PrintEveryLevelOfTreeInALineX(NodeTree* root)
		{
			int height = 0;
			queue<NodeTree*> q;
			q.push(root); //push the root
			
			while (q.size() > 0)
			{
				int cnt = q.size(); //Pop only the old nodes, and print them, and inject their children
				while (cnt > 0)
				{
					//pop one item
					NodeTree* n = q.front();
					q.pop();
					cout << n->d << " ";
					
					if (n->L)
						q.push(n->L);
				
					if (n->R)
						q.push(n->R);

					cnt--;
					
				}
				//we printed nodes of a LEVEL, print CRLF
				height++;
				cout << endl;
			}
			cout << "all rows printed " << endl;
			cout << "height " << height << endl;
		}

		
	};
};



