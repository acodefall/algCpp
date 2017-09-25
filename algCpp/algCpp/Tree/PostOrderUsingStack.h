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
namespace PostOrderUsingStackNM
{
		/*
			Post order traversal 20170710005
				Post order traversal is can be acieved by modifiying DFS 
				Write the DFS code. When you pop the item from the stack, instead of printing it, push in to second stack.
				Once the DFS is done, print the content of second stack.
				During DFS, Push the left child first and then right child
		
		*/
	class PostOrderUsingStack
	{
	public:
		void callTreeTraversalsUsingStack()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			//Order refers to the position of Parent node
			StackPostorder(objTrrr.root); //L R P
		}

	private:
		//Post order traversal is can be acieved by modifiying DFS 
		//Write the DFS code. When you pop the item from the stack, instead of printing it, push in to second stack.
		//Once the DFS is done, print the content of second stack.
		void StackPostorder(NodeTree* rt)
		{
			cout << endl << "Stack based Post order traversal" << endl;
			stack<NodeTree*> st;
			stack<NodeTree*> st2;
			NodeTree* cur = rt;

			st.push(cur);
			while (st.size() > 0) 
			{
				NodeTree* tmp = st.top();
				st.pop();

				st2.push(tmp);
				
				if (tmp->L != NULL) //Push the left child first and then right child
				{
					st.push(tmp->L);
				}

				if (tmp->R != NULL)
				{
					st.push(tmp->R);
				}
				
			}
			
			cout << endl;
			while (st2.size() > 0)
			{
				cout << setw(4) << st2.top()->d << " ";
				st2.pop();
			}
			cout << endl;

		}

	};
};