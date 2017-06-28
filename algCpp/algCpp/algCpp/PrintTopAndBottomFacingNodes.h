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
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;

/*
	Printing Top view of Tree_20170528019
		Top-view means print ing only the nodes found along the inverted-V, ignore the inner nodes that are inside the V.


 
		Top facing nodes are 70,80,100,120,300 (ignore 90, and 110)
		Top-view means the nodes that sit along the inverted-V of Tree. This ignorse the inner nodes that are inside the V.
		To solve this do the following.
		Draw imaginary vertical lines. There will be Line a passing through the root, and there will be lines on either sides of root.
		Assign these lines a number. Line passing through root will have a value of 0 and other lines' value will be 1, -1, 2, -2, 3 and -3.
		Makes these numbers the KEY in a hashTable, and value will be the list of nodes living along these lines.
		Once you have this hashTable, Top-view comes from 0th element of list stored as value in HashTable.
		Bottom-view comes from last element of the list stored as value in HashTable.

	Steps for Printing Top view of Tree_20170528020
		Write pre-order recursion code. Recursion parameters are 'hDistance', and node. For the root node, hDistance will 0.
		When making L-Recursion call, do "hDistance - 1"
		When making R-Recursion call, do "hDistance + 1"
		Inside the function, use hDistance (passed-in as paramete) as KEY in to HashTable, and store the Node as VALUE.
		Once the iteration is over, print Top and Bottom view, by using HashTable.


*/
class PrintTopAndBottomFacingNodes
{

	public:
			unordered_map<int, list<int> > vert;
			void callPrintTopAndBottomFacingNodes()
			{
				BuildTree trr;
				trr.AddValues();
			
				cout << "\r\n";
				cout << "Print Tree In-Order\r\n";
				trr.printTreeInOrder(trr.root);
				cout << "\r\n";

				treeNav(trr.root, 0);
				
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
				cout << "Print Tree along vertical lines(Top -> Bottom) \r\n";
				cout << top << endl;

				cout << "\r\n";
				cout << "Print Tree along vertical lines(Bottom -> Top) \r\n";
				cout << bottom << endl;
				cout << "\r\n";
			}

			void treeNav(NodeTree* rt, int hdist)
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
					treeNav(rt->L, hdist - 1);
					treeNav(rt->R, hdist + 1);
				}
			}


};