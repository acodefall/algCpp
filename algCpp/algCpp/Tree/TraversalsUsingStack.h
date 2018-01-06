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
namespace TreeTraversalsUsingStackNM
{
	class TreeTraversalsUsingStack
	{
	public:
		void callTreeTraversalsUsingStack()
		{
			BuildTree objTrrr;
			objTrrr.AddValues1();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			//Order refers to the position of Parent node
			StackInorder(objTrrr.root);  //L P R
			StackPreorder(objTrrr.root);  //P L R

			/*
				Stack based In order traversal
				  10   50   60   80   85   90   95  100  110  120  300
				Stack based Pre order traversal
				 100   80   50   10   60   90   85   95  120  110  300
			*/

			/*

							1
						2		3
					4     5   6   7


					Stack based In order traversal
					4    2    5    1    6    3    7
					Stack based Pre order traversal
					1    2    4    5    3    6    7
			*/
		}

	private:
		void StackInorder(NodeTree* rt)
		{
			cout << endl  << "Stack based In order traversal" << endl;
			stack<NodeTree*> st;
			NodeTree* cur = rt;

			while (true) //IMPORTANT we do not want to exit if is NULL because LEAF are going to be NULL
			{
				//go to left most node and all along push the item in to stack
				while (cur != NULL)
				{
					st.push(cur);
					cur = cur->L;
				}

				if (st.size() == 0)
					break;

				NodeTree* rChildNode = st.top()->R;

				//print current node
				cout << setw(4) << st.top()->d << " ";
				st.pop(); //pop the current node because it got printed already
				
				//explore the right child
				cur = rChildNode;
			}
		}

		void StackPreorder(NodeTree* rt)
		{
			cout << endl << "Stack based Pre order traversal" << endl;
			stack<NodeTree*> st;
			NodeTree* cur = rt;

			while (true) //IMPORTANT we do not want to exit if is NULL because LEAF are going to be NULL
			{
				//go to left most node and all along push the item in to stack
				while (cur != NULL)
				{
					cout << setw(4) << cur->d << " ";  /////CHANGED PART
					st.push(cur);
					cur = cur->L;
				}

				if (st.size() == 0)
					break;

				NodeTree* rChildNode = st.top()->R;
				st.pop(); //pop the current node because it got printed already

 			    //explore the right child
				cur = rChildNode;
			}
		}

	};
};