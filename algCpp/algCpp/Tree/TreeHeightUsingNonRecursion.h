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
		Use same code as PrintEveryLevelOfTreeInALine


		


*/
namespace TreeHeightUsingNonRecursionNM //@RED20170711001 20170711002
{
	class TreeHeightUsingNonRecursion
	{
	public:
		void callTreeHeightUsingNonRecursion()
		{
			/*BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			TreeHeightUsingNonRecursionX(objTrrr.root);*/
		}

	private:
		/*void TreeHeightUsingNonRecursionX(NodeTree* root)
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
		}*/
	};
};



