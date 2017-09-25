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
		Using NULL as marker when computing Height using Iteration_20170711001
		Also check @RED20170731009
			Start with BFS code. EnQ every node that sits on a line in to Q, and end the line by inserting a place-holder (say NULL). 
			If you look at the Q,  newest item (NULL) will be at the top, and oldest item will be at the bottom of Q.
				NULL //End of line marker for root node
				N
	
			Dq operation will always read from bottom most slot only. After every Dequing, the top item(NULL) will fall by one level.
			After every Dequing, we will Enq the children of the Dqued item on to Q. These children will sit on the top of NULL.
			NULL will hit the bottom slot once all the items belonging to a LINE have been read. By this time we would Enqued every the children of every node belonging to current level. 

			Now Dq the NULL, and in response Enq a NULL. And the Enqued NULL will sit on the top, and acts as END of the LINE marker for NEXT line. This is how we can use NULL to marker. When ever the Dequed Item is NULL, increment the HEIGHT counter by 1
	
				NL
				NR
				NULL	//End of line marker for root node has come to Bottom
	
				NULL //End of line marker for 2nd LEVEL
				NL
				NR

		
		Q buildup
		----------
			NULL													100
			100 (pop 100 push 80/120)							  /    \
				80												 /      \
				120												80       120
				NULL (pop NULL push NULL)					   /  \      / \
						NULL								 50    90   110  300
						80									 /\    /\
						120 (pop 120 push 110/300)    		/  \  /  \
							  110						   10 60  85 95
							  300
							  NULL
							  80  (pop 80 push 50/90)
									50
									90
									110
									300
									NULL  (pop NULL push NULL)
											NULL
											50
											90
											110
											300 (pop 300 )
													NULL
													50
													90
													110	(pop 110 )
															NULL
															50
															90


*/
namespace TreeHeightUsingNonRecursionNM //@RED20170711001 20170711002
{
	class TreeHeightUsingNonRecursion
	{
	public:
		void callTreeHeightUsingNonRecursion()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			TreeHeightUsingNonRecursionX(objTrrr.root);
		}

	private:
		void TreeHeightUsingNonRecursionX(NodeTree* root)
		{
			int height = 0;
			queue<NodeTree*> q;
			queue<NodeTree*> qLog;
			q.push(root); //push the root
			q.push(NULL); 
			//q = printAllQ(q);
			while (q.size() > 0)
			{
				//pop one item
				NodeTree* n = q.front();
				q.pop();

				if (n == NULL)
				{
					cout << "pop " << "NULL";
					height++;
					if (q.size() > 0)
						q.push(NULL);
				}
				else
				{
					cout << "pop " << n->d;
					if (n->R)
						q.push(n->R);

					if (n->L)
						q.push(n->L);
				}
				//q = printAllQ(q);
			}

		}

		//only way to itearete Q is POP.
		//So as you POP create an another Q and send it to caller
		//Shows how user-UNFRIENDLY is STL is?
		queue<NodeTree*> printAllQ(queue<NodeTree*> q)
		{
			queue<NodeTree*> unFriendlySTL;
			cout << endl;
			cout << endl;
			if (q.size() > 0)
			{
				while (q.size() > 0)
				{
					NodeTree* t = q.front();
					q.pop();
					unFriendlySTL.push(t);
					if (t == NULL)
					{
						cout << NULL << endl;
					}
					else
					{
						cout << setw(4) << t->d << endl;
					}
				}
				cout << endl;
			}
			else
				unFriendlySTL = q;
			return unFriendlySTL;
		}
	};
};



