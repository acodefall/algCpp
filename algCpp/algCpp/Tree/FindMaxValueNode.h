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