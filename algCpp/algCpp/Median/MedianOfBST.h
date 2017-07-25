#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include "BuildTree.h"
using namespace std;

//Median of Balanced BST_20170621009
namespace MedianOfBSTNM //@RED20170621009
{
	using namespace BuildTreeNM;
	class MedianOfBST
	{
			public:
				void CallMedianOfBST()
				{
					BuildTreeNM::BuildTree objBuildTree;
					objBuildTree.AddValues();

					vector<int>			nodeValues; 
					stack<NodeTree*>	st;
					NodeTree*			rt = objBuildTree.root;
					nodeValues.reserve(UCHAR_MAX);
		
					//iterate the BST and store the content in nodeValues
					//Balanced BST's content will give sorted data when traversed in 'in-order' fashion
					while (true)
					{
						while (rt)
						{
							st.push(rt);
							rt = rt->L;
						}

						if (st.size() == 0)
						{
							cout << endl << "stack is empty" << endl;
							break;
						}
						NodeTree* temp = st.top();
						st.pop();
						nodeValues.push_back(temp->d);

						rt = temp->R;
					}
					
					//compute the median 
					int median = 0;
					if (nodeValues.size() > 0)
					{
						int size = nodeValues.size();
						//1 2 3 4 = 2
						if (nodeValues.size() % 2 == 0)
						{
							median = (nodeValues[size / 2] + nodeValues[(size - 1) / 2]) / 2;
						}
						else if (nodeValues.size() % 2 != 0)
						{
							median = nodeValues[size / 2];
						}
					}

					//BST content
					cout << endl << "BST content" << endl << " size: " << nodeValues.size() << endl;
					for (int i = 0; i < nodeValues.size(); i++)
					{
						cout << nodeValues[i] << " ";
					}

					cout << endl << "Median : " << median << endl;
				}
	};
};
