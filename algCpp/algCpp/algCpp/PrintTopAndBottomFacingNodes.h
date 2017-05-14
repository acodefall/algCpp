#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>
#include<unordered_map>
using namespace std;


class PrintTopAndBottomFacingNodes
{

	class Node
	{
		public:
			int d;
			Node* left;
			Node* right;
			Node(int x)
			{
				d = x;
				left = 0;
				right = 0;
			}
	};


	public:
			unordered_map<int, list<int> > vert;
			void callPrintTopAndBottomFacingNodes()
			{
				Node x1(500);
				Node x2(250);
				Node x3(750);
				Node x4(125);
				Node x5(350);
				Node x6(650);
				Node x7(900);


				x1.left = &x2;
				x1.right = &x3;
				x2.left = &x4;
				x2.right = &x5;
				x3.left = &x6;
				x3.right = &x7;

				trav(&x1);
				treeNav(&x1, 0);
				
				string top;
				string bottom;
				for (auto x = vert.begin(); x != vert.end(); x++)
				{
					auto y = (*x).second;
					int cn = 1;
					
					for (auto z = y.begin(); z != y.end(); z++)
					{
						if (cn == 1)
						{
							top = top.append(to_string((*z)));
							top = top.append(" ");
						}
						else if (cn == y.size() - 1)
						{
							bottom = bottom.append(to_string((*z)));
							bottom = bottom.append(" ");
						}
						cn++;
					}
					
				}
				cout << top << endl;
				cout << bottom << endl;
			}

			void treeNav(Node* rt, int hdist)
			{
				if (rt)
				{
					//add
					auto x = vert.find(hdist);
					if (x == vert.end())
					{
						list<int> ls1;
						ls1.push_back(rt->d);
						vert.insert(make_pair(hdist, ls1));
					}
					else
					{
						vert[hdist].push_back(rt->d);
					}
					treeNav(rt->left, hdist - 1);
					treeNav(rt->right, hdist + 1);
				}
			}


			void trav(Node* rt)
			{
				if (rt)
				{
					trav(rt->left);
					cout << rt->d << " ";
					trav(rt->right);
				}
			}
};