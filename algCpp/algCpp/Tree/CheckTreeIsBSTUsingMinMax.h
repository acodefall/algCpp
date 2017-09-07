#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;

namespace CheckTreeIsBSTUsingMinMaxNM //@RED20170731006
{
	/*
		Check if the Tree is a Binary Search Tree(BST)_RED20170731007
			Note this is not about checking whether the tree is Balanced BST.
			BST and Plain Tree are different.
			BST has rules that controls the values of P, Lc and Rc; where as the Plain Tree does not lie down any rules about the node value.
			In BST, Parent node's value should be higher than Lc and Lower than Rc
	   
				   20
				   / \
				 10   30
	 
			In Plain Binary Tree, node value can be anything.
				    20
				   / \
				 100  3
	 
			Checking for BST can be done in 2 ways
				-Using inorder traversal_RED20170731007
				We know BST data will be in increasing order when tree is travesrded using InOrderTraversal. So write a code for inoder traversal, and in each loop confirm that current node’s value is higher than previous node’s value. If the whole tree satisfies this rule, then the whole tree in BST. 
	
		-Using Min and MaX method_RED20170731006
			Value of every node in BSTree has to fall in between some MIn and MAx value. 
			These Min and Max values are set by immiditae parent and also some other ancestor node.
			For root node, there is no parent or ancestor so the Min and Max are Int_Min and Int_Max.
			For internal node, that is also a Lc, value should be LESS than immidiate parent and higher than some ancestor node.
			For internal node, that is also a Rc, value should be HIGHER than immidiate parent and lower than some ancestor node. Code has to confirm that every node meets this requirement. If every meets this rule then we can say that whole tree is Binary Search Tree)(not Balanced BST).
			Every node has to do following
			-MIX and MAX will be passed as recursion parameter.
			-Every node should check whether current node's value falls between MIN and MAX
			-If that is true, then it has to make sure both left and right child hives also meet this requirement; so it makes two recursion calls and they also return BOOL.
			-Finally caller will AND all the three BOOLs and return to caller.
			-If every node returns TRUE, then we can conclude that TREE is BST

	   
		Check for Tree is BST using MIN and MAX method  

		 (Non BST)  Plain Tree                          BSTMinMax(rt, Min, Max)
					100                                 {
				  /     \                                   if (rt)
				 /       \                                  {   //Non-Leaf has VALUE, Lc, Rc. All 3 has to be BST
				80       120                                    if ((rt->d > Min) && (rt->d < Max))
			   /   \      / \                                   {
			 70    90   110  300                                    bool left = BSTMinMax(rt->L,..);
			 /\    /\                                               bool right = BSTMinMax(rt->R,..);
			/  \  /  \                                              return left & right;
		   10 30  85 95                                         }
																else 
																	return FALSE;
															}
															else //LEAF has no VALUE; return TRUE
																return TRUE;
														}
		   
		LEAF Node                               Non-LEAF Node 
			BSTMinMax(10)                           BSTMinMax(80)
			{                                       {
				if (rt)                                 if (80)
				{                                       {   
															//1) [80] between 70 & 90; 
				}                                           //2)      TRUE == BSTMinMax(70) 
				else //Control comes here                   //3)      TRUE == BSTMinMax(90) 
					return TRUE;                        return TRUE
			}                                           }   
													}
			

	
	*/
	class CheckTreeIsBSTUsingMinMax
	{
		public:
				void callCheckTreeIsBSTUsingMinMaxNM()
				{
					BuildTree objTrrr;
					objTrrr.AddValuesNonBST();
					//objTrrr.AddValues();

					cout << "\r\n";
					cout << "Tree content\r\n";
					objTrrr.printTreeInOrder(objTrrr.root);
					cout << "\r\n";

					//Min and Max values are set by immiditae parent and also some other ancestor node.
					//For root node, there is no parent or ancestor so the Min and Max are Int_Min and Int_Max.
					bool x = CheckTreeIsBSTUsingMinMaxX(objTrrr.root, INT32_MIN, INT32_MAX);
				}

				bool CheckTreeIsBSTUsingMinMaxX(NodeTree* rt, int Min, int Max)
				{
					bool BinarySearchTree = true;
					NodeTree* cur = rt;
					
					if (rt != NULL)
					{	
						//This is Non-Leaf Node, this has VALUE and Lc & Rc. 
						//For this node to be BST
						//X- Node VALUE should fall between MIN and MAX
						//Y- Both Lc & Rc should pass BST check
						//If any one of this 3 condition fails, then return FALSE, node is not BST
						
						//X
						if ((rt->d > Min) && (rt->d < Max))
						{
							//Y
							//any Left child should be LESS than PARENT. So rt->d is MAX
							bool left = CheckTreeIsBSTUsingMinMaxX(rt->L, Min, rt->d);

							//any Right child should be HIGHER than PARENT. So rt->d is MIN
							bool right = CheckTreeIsBSTUsingMinMaxX(rt->R, rt->d, Max);
							
							
							// X && Y
							BinarySearchTree = left & right;
							return BinarySearchTree;
						}
						else
						{
							BinarySearchTree = false;
							return BinarySearchTree;
						}
					}
					else
					{	//This is LEAF node and it has no value so we can not compare against MIN and MAX value
						//So assume the node is meeting the BST requirement
						//Return TRUE
						BinarySearchTree = true;
					}
					return BinarySearchTree;
				}
	};
};
