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
		We know that Right-child hive and ancestor nodes may have high-valued node, so we should explore that region.
		We are not interested in any higher value, but the the value that is just above the current node so we should 
		explore in following order.

		-Left-most child under right-child will have immidiately higher-value. So first search there.
		-Then move on to Right-child itself. 
		-Then move on to ancestor of current node
		
		Use a while loop for probing the left-most child of Right-hive. 
		If the value is not there, then search under ancestor using Binary search, starting from Root.
		Bbinary search will in fact search for the TargetNode itself who's value we already know. 
		We expect to see the successor node somewhere between Root and current node.
		Binary search will be making L and R turn by comparing currNode with TargetNode's value.
		And Stops the binary at TargetNode.
		All along the way record the value of currNode if it's value is more than that of TargetNode.
		By the time the cursor reaches the Target node, we should have successor node.

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