#pragma once
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
namespace FindSuccessorNodeNM //20170709003
{
	/*
		Successor node a node who's value is just above the value of current node.
		Successor node is a node who's value is higher than current node. Given a node we have to find the node with immidiate higher value.
		Given a node, left-most child of right-child's will have immidiate higher value; so we first check the value of left-most child of right-child.
		If it is present, return that value to caller. This can be implemented using while-loop.
		If that value is not present, then look at the Next candidate; that will be right-child itself. 
		If teh right-child has a value return it to caller. This can be implemented using while-loop.
		
		If the right-child has no value; then we have to look for the successor node above the current node. 
		To do this we navigate the tree, from the root. Our goal is to go past the hostNode(host node is the node who's successor we want to find). 
		When navigating if (currentNode is < soughtValue), make left turn, otherwise makde right turn.
		All along way, record the node-value if the value is higher than the soughtValue (this is because we are interested in the node value that is higher than host node). 
		At some point cursor will hit host node, then break rhe navigation and return the 'recorded node value' to caller.
		
		-Start while-Loop.
		-if(currData > TargData)
			succNode = CurrNode //Record the node for tracking purpose.

		-if(TargData < currData ) 
			cur = cur->L
			//If targetNode is lower than currNode, then Target node has to be in left hive so make left turn

		-if(TargData > currData ) 
			cur = cur->R
			//If targetNode is higher than currNode, then Target node has to be in right hive so make right turn

	*/
	class FindSuccessorNode
	{
	public:
		void callFindSuccessorNode()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";
			int deapestLevel = INT_MIN;
			NodeTree trgNode(50);


			NodeTree* successorNode = FindSuccessorNodeX(objTrrr.root, &trgNode);

		}

	private:
		NodeTree* FindSuccessorNodeX(NodeTree* rt, NodeTree* targetNode)
		{
			NodeTree* successorNode = 0;
			if (rt != NULL)
			{
				if (targetNode != NULL)
				{
					//If X has valid R-child, then successor for X is either the RIGHT-child itself; OR the Left-most-child for X
					if (targetNode->R != NULL)
					{
						NodeTree* tmp = targetNode->R;
						while (tmp != NULL)
						{
							tmp = tmp->L;
						}

						return tmp;
					}

					NodeTree* cur = rt;
					while (cur != NULL)
					{
						//Successor of targetNode, has to be higher than targetNode.
						//So if you find any node that is higher than targetNode, record it.
						if (targetNode->d < cur->d) //Trg is in left check-out left-hive
						{
							successorNode = cur; //If you are going on left-side, successor will be the node that is immidiately higher in value compared to Target Node
						}

						//Navigate by taking left turn or right turn.
						//If targetNode is lower than currNode, then Target node has to be in left hive so make left turn
						if (targetNode->d < cur->d) //Trg is in left check-out left-hive
						{
							cur = cur->L;
						}
						else if (targetNode->d > cur->d) //If targetNode is higher than currNode, then Target node has to be in right hive so make right turn
						{
							cur = cur->R;
						}
						else
							return successorNode;
					}
				}
			}

		}

	};
};