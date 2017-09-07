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
			Solve this using BFS navigation of Tree. 
			BFS navigation uses Q and a while loop. In BFS navigation, 1st level will introduce 2nd-level in to Q.
			Similarly 2nd level will introduce 3rd-level in to Q. This is achieved by applying following 3 rules:
			a) When the while loop begins, all the nodes stored in Q must belong to same level in tree;
			b) While loop will deque ONLY the nodes of current level; and will also Enque the children of current-lveel (which are at next level) in to Q. So by the time current round of While loop ends, nodes of current level will be out of Q, and only the only the nodes of next level will be in Q. So while loop enters next round, we can be sure that Q content belongs to just one level.

			c) While loop is able to Deque ONLY the nodes of current level because it caches the Q count at the very beginning of While loop, before Enquing any children in to Q. Since this is a Q, all the Enqued the items (belong to next level) will go to bottom of Q. Note that this logic would not work if we use STACK. 

			For printing the nodes in seperate line, use the above code; and print CRLF at the end of every while loop. 

			
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



