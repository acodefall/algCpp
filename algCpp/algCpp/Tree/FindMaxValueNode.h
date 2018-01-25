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

/*
	FindMaxValueInTreeRED20180114001 //Tree_064_Find MAX element_TR60
		This can be solved using two methods.
		1) This method is similar to computing node code. 
		   Each recursion call should compare the values of currNode, LeftChildNode and RightChildNode.
		   And return the one that is highest among the three.
		   In this fashion, higher value gets passed up and up. Final value returned by recursion will be the highest value. 
		   Coming to coding, use post-traversal code. And compare the return values of recursion call
		   with current node, and then return the highest value among them.

		2) Do inorder traversal and go on maintaining highest value in a global variable.
		   Finally global variable will have highest value.
	   
	
	
*/
namespace FindMaxValueNodeNM
{
	class FindMaxValueNode
	{
		public:
			void callFindMaxValueNode()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";

				int m = FindMaxValueNodeX(objTrrr.root);
				cout << "MAx value is " << m;
			}

		private:
			int FindMaxValueNodeX(NodeTree* root)
			{
				int MaxValue = 0;
				if (root)
				{
					//cout << root->d << endl;
					
					int L = FindMaxValueNodeX(root->L);
					int R = FindMaxValueNodeX(root->R);
					
					MaxValue = max(max(L, R), root->d);
					//MaxValue = max(downMax, MaxValue);
					cout << setw(4) << root->d << " " << setw(4) << L << " " << setw(4) << R << " " << setw(4) << MaxValue << endl;
				}
				return MaxValue;
			}
	};
};