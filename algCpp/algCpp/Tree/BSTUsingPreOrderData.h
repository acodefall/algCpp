#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace BSTUsingPreOrderDataNM
{
	class BSTUsingPreOrderData
	{
	public:
		void callBSTUsingPreOrderData()
		{
			int preOrder[11] = { 20, 10, 5, 1, 7, 15, 30, 25, 35, 32, 40 };
			int len = 11;
			pIndex = 0;
			NodeTree* x2 = BSTUsingPreOrderDataRecursion(preOrder, len, INT32_MIN, INT32_MAX);


			//BuildTree objTrrr;
			//objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			printTreeInOrderS(x2);
			cout << "\r\n";
			//Output: 1 5 7 10 15 20 25 30 32 35 40
		
		}

	private:
		int pIndex;
		NodeTree* BSTUsingPreOrderDataRecursion(int preOrder[11], int length,int Min, int Max)
		{
			if (pIndex < length)
			{
				if ((preOrder[pIndex] > Min) && (preOrder[pIndex] < Max))
				{
					NodeTree* n = new NodeTree(preOrder[pIndex]);
					pIndex++;

					//any Left child should be LESS than PARENT. So rt->d is MAX
					n->L = BSTUsingPreOrderDataRecursion(preOrder, length,  Min, n->d);

					//any Right child should be HIGHER than PARENT. So rt->d is MIN
					n->R = BSTUsingPreOrderDataRecursion(preOrder, length, n->d, Max);
					return n;
				}
				return NULL;
			}
			return NULL;

		}

		void printTreeInOrderS(NodeTree* rt)
		{
			NodeTree* cur = rt;
			if (cur)
			{
				printTreeInOrderS(rt->L);
				cout << rt->d << " ";
				printTreeInOrderS(rt->R);
			}
		}
	};
};