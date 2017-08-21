//

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
namespace FindKthItemInBSTNM //@RED20170820004
{
	/*
		Find the Kth item in BST_RED20170820004
			We know In order traversal of BST will result in data that is in ascending order.
			Solution is do inorder traversal until k rounds, then print the node value and then stop iterating.
	*/
	class FindKthItemInBST
	{
	public:
		void callFindKthItemInBST()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();
			int K = 4;
			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			//Order refers to the position of Parent node
			cout << endl;
			
			int x = StackInorder(objTrrr.root, K);  //L P R
			cout << endl << "Kth(" << K << ")item is " << x << endl;
		}

	private:
		int StackInorder(NodeTree* rt, int K)
		{
			cout << endl << "Stack based In order traversal K '" << K << "'" << endl;
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
				K--;
				cout << setw(4) << st.top()->d << " ";
				if (K == 0)
					return st.top()->d;
				st.pop(); //pop the current node because it got printed already

						  //explore the right child
				cur = rChildNode;
			}
		}

	

	};
};