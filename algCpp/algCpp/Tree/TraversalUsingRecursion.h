#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<stack>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace TraversalUsingRecursionNM
{
	class TraversalUsingRecursion
	{
	public:
		void callTraversalUsingRecursion()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			//Order refers to the position of Parent node
			cout << endl;
			cout << endl << "In" << endl;
			RecursionInorder(objTrrr.root);  //L P R
			cout << endl << "Pre" << endl;
			RecursionPreorder(objTrrr.root);  //P L R
			cout << endl << "Post"<< endl;
			RecursionPostorder(objTrrr.root); //L R P
		}

	private:
		void RecursionInorder(NodeTree* rt)
		{
			if (rt != NULL)
			{
				RecursionInorder(rt->L);
				cout << setw(4) << rt->d << " ";
				RecursionInorder(rt->R);
			}
		}

		void RecursionPreorder(NodeTree* rt)
		{
			if (rt != NULL)
			{
				cout << setw(4) << rt->d << " ";
				RecursionPreorder(rt->L);
				RecursionPreorder(rt->R);
			}
		}

		void RecursionPostorder(NodeTree* rt)
		{
			if (rt != NULL)
			{
				RecursionPostorder(rt->L);
				RecursionPostorder(rt->R);
				cout << setw(4) << rt->d << " ";
			}
		}

	};
};