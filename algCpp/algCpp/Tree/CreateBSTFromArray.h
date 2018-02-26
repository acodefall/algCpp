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
namespace CreateBSTFromArrayNM //@RED20170825001
{
	/*

		Construct BST from array.
			We go to middle of the array and build root node.
			Next we go to middle of left-side and build left-child for root node
			Next we go to middle of right-side and build right-child for root node
			Order node construction is Parent, Lc and Rc. This is Pre-order fashion. 
			So we use pre-order code for construction. At the top of the function,
			compute M-index using L & H, and construct a parent-node using M-index-data.
			Then adjust L & H to point to left half, and make L-rec call for building left-child.
			Then adjust L & H to point to right half, and make R-rec call for building right-child.
			Attach child nodes to parent-node and return it to caller.
			Not that we do not advance INDEX in to src-array, instead use M-index.
			M-index gets computed again and again.
			Additionally recursion breaks if L is not < H

		if(L <= H)
					L   H     m         [L] [H]   [M]
			{  0  10  5 } = {  10  300   90 }  built node   90				           100						
			{  0   4  2 } = {  10   85   60 }  built node   60				          /    \
			{  0   1  0 } = {  10   50   10 }  built node   10				         /      \
			{  1   1  1 } = {  50   50   50 }  built node   50				        80       120
			{  3   4  3 } = {  80   85   80 }  built node   80				       /  \      / \
			{  4   4  4 } = {  85   85   85 }  built node   85				     50    90   110  300
			{  6  10  8 } = {  95  300  110 }  built node  110				     /\    /\
			{  6   7  6 } = {  95  100   95 }  built node   95				    /  \  /  \
			{  7   7  7 } = { 100  100  100 }  built node  100				   10 60  85 95
			{  9  10  9 } = { 120  300  120 }  built node  120
			{ 10  10 10 } = { 300  300  300 }  built node  300
			

			Tree built
				10 50 60 80 85 90 95 100 110 120 300
	
		if(L < H)
			{ 0  10  5 } = {   10  300   90 } built node   90
			{ 0   4  2 } = {   10   85   60 } built node   60
			{ 0   1  0 } = {   10   50   10 } built node   10
			{ 3   4  3 } = {   80   85   80 } built node   80
			{ 6  10  8 } = {   95  300  110 } built node  110
			{ 6   7  6 } = {   95  100   95 } built node   95
			{ 9  10  9 } = {  120  300  120 } built node  120
			
			Tree built
				10 60 80 90 95 110 120


	*/
	const int Len = 11;
	class CreateBSTFromArray
	{
	public:
		void callCreateBSTFromArray()
		{
			int src[Len] = { 10, 50, 60, 80, 85, 90, 95, 100, 110, 120, 300  };
		
			
			NodeTree* parentBuilt = 0;
			NodeTree* m = CreateBSTFromArrayX(src, 0, Len - 1, &parentBuilt);

			cout << "\r\n";
			cout << "Tree built\r\n";
			BuildTree::printTreeInOrder(parentBuilt);
			cout << "\r\n";
		}

	private:
		//L & H are indexes, zero based
		//parentBuilt will be the Root of the Tree built
		NodeTree* CreateBSTFromArrayX(int src[Len], int L, int H, NodeTree** parentBuilt)
		{
			NodeTree* p = 0;
			if (L <= H)  //Having <= is necessary 
			{
				//For the range L & H, the root-node will be src[mid].
				//Use src[mid] to build parent-Node
				int mid = L + (H - L) / 2;
				cout << "{ " << setw(3) << L << " " << setw(3) << H << " " << setw(3) << mid << " } = { " << setw(3) << src[L] << " " << setw(3) << src[H] << " " << setw(3) << src[mid] << " } ";
				
				//Build Root for L-H range (parent-Node)
				
				p = new NodeTree(src[mid]);
				cout << "built the node " << setw(3) << src[mid] << endl;
				if (*parentBuilt == 0) //When we build the Node, if it is the first node, then it is the ROOT, preserve it. 
				{
					*parentBuilt = p;
				}
				p->L = CreateBSTFromArrayX(src, L, mid - 1, parentBuilt);
				p->R = CreateBSTFromArrayX(src, mid+1, H, parentBuilt);
			}
			return p;
		}
	};
};