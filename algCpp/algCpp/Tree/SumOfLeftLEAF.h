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
namespace SumOfLeftLEAFNM
{
	
	/*
						 (BST)
			               100
                          /    \
                         /      \
                        80       120
                       /  \      / \
                     50    90   110  300
                     /\    /\
                    /  \  /  \
                   10 60  85 95
	
				add 10 to 'Sum of Left Leaf' 10
				add 85 to 'Sum of Left Leaf' 95
				add 110 to 'Sum of Left Leaf' 205
	*/
	class SumOfLeftLEAF
	{
		public:
			void callSumOfLeftLEAF()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
				int SumLeftLeaf = 0;
				SumOfLeftLEAFX(objTrrr.root, false, &SumLeftLeaf); 

			}

		private:
			void SumOfLeftLEAFX(NodeTree* rt, bool LeftChild, int* SumLeftLeaf)
			{
				if (rt != NULL)
				{
					SumOfLeftLEAFX(rt->L, true, SumLeftLeaf);
					if ((rt->R == NULL) && (rt->L == NULL) && (LeftChild == true))
					{
						*SumLeftLeaf += rt->d;
						cout << "add " << rt->d << " to 'Sum of Left Leaf' " << *SumLeftLeaf << endl;
						
						return;
					}

					SumOfLeftLEAFX(rt->R, false, SumLeftLeaf);
				}
			}
			
	};
};