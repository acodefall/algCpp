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
		When searching for Successor of Target node, first look for the left-most child of right-child of TargetNode. If that is missing, then look at the rightChild of TargetNode.
		If both are absent, look among the ancestors of Target node. 
		Starting from root, drill down to Target node, and along the way record any node who's value is more than that of TargetNode.
		This is because Successor of targetNode, has to be higher than targetNode.
		Stop the iteration when you reach Target node. Last recorded node is the successor node.
		
		-Start while-Loop.
		-if(currData > TargData)
			succNode = CurrNode //Record the node for tracking purpose.

		-if(TargData < currData ) 
			cur = cur->L
			//If targetNode is lower than currNode, then Target node has to be in left hive so make left turn

		-if(TargData > currData ) 
			cur = cur->R
			//If targetNode is higher than currNode, then Target node has to be in right hive so make right turn

		For this drill down from 
		InOrderSuccessor Node is a node with higher value. In general higher valued node will be 
				-Leftmost child of Right-Child of X
				-Right-Child of X
				-Ancestor node of X
			Explore in above given order only.

			If the Right-Child has any left node, use the deepest left node as successor node.
			If the Right-child does not have any left node, then use the deepest left node as successor node
			If the Right-child it self missingg, start navigating from root. MAke left of right turn so that you approach Target node.
			Along the way keep track the node that is above Target node.

   
            -If TargetNode has no R-Child, then start a while loop to iterate from root.
                            Declare Curs, PrevNode, and start while loop.
                            Inside the while loop:
                                                    if (trg.Data < Curs.Data),
                                                                                    PrevNode = Curs; Curs = Curs.Left;
                                                    under Else If (trg.Data > Curs.Data),
                                                                                    Curs = Curs.Right;
                                                    under Else (where trg == Curs)
                                                            return PrevNode.
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