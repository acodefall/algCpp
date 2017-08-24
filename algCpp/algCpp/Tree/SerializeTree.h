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
		Serialize a Tree_20170731001
		
		Compute the height of Tree_20170731009
			Traverse the tree using in-order traversal and store it in a List.
			Then traverse the List and rebuild the Tree.
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



