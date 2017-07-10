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
namespace DFSSearchNM
{
	class DFSSearch
	{
		public:
			void callDFSSearch()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";

				DFSSearchX(objTrrr.root, 50);
			}

		private:
			void DFSSearchX(NodeTree* root, int Value)
			{
				stack<NodeTree*> st;
				st.push(root); //push the root

				while (st.size() > 0)
				{
					//pop one item
					NodeTree* n = st.top();
					st.pop(); 

					//check if the value exists
					if (n->d == Value)
					{
						cout << endl << "found the value " << Value << endl;
						break;
					}

					//if the value is not present, then push the children in to stack.
					//Container is stack, and when we are popping out the elements we want 
					//L-child pop-oout first so we insert the L-child last
					if (n->R)
						st.push(n->R);
					if (n->L)
						st.push(n->L);
				}
			}
	};
};