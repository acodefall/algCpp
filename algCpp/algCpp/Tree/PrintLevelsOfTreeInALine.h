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
			IN BFS navigation, 1st level adds the elements of 2nd-level in to Q.
			Similarly 2nd level adds the elements of 3rd-level in to Q.
			We modify this code for printing nodes in a seperate line.
			1st-level will print the Q content , along with CRLF, and empties the Q, and then 
			adds the children in to Q. Now Q will have only the elements of level-2. 
			
			When the control goes to next loop, level-2 will print and empty the Q.
			Then adds its children to Q. Now Q will have only the elements of level-3. 
			
			Coming to implementation.
			-Start with BFS code
			-Then enter the while loop. Say we are at level-2.
			-We know all the elements of Q belong to level-1 and want to print them.
			-Read the q-count, and start an inner while loop to extract the X elements from Q and print them.
			 Add the children of Deques nodes in to Q. These elements will be added to bottom of the Q,
			 While loop will not deque the newly added nodes.
			 While loop will print all the elements of 1-st level. 
			 And also Enquis the elements of 2-nd level.
			 
			 Once out of the inner-while loop, print crlf.
			 
			 

			
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



