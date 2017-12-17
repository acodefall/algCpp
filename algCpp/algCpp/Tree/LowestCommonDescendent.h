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
namespace LowestCommonDescendentNM //@RED20170725066
{
		/*
			Find Lowest Common Ancestor (LCA)
				LCA is a node that is ancestor to two target nodes. Value of LCA will be between the values of two target nodes, 
				and also closest to it.
				It is possible that LCA could be one of the Target node itself.
				Since the LCA is a ancestor start drilling down from root. At every step compare the current against the values of both Target nodes.
					if('Target values' < current)
						Make Left Turn
					else if('Target values' > current)
						Make right turn
					else
						(current == T1) || (current == T2) || (current is between T1,T2)
							Meet the LC
						Exit

				LCA between for two nodes is a common ancestor that meets two condition
					-Value of the ancestor should fall in between that of two nodes.
					-Value should be lowest among common ancestors.
				So to find the LCA, start from Root of the BST, and drill down until the node values are within the range set by target nodes.
				All along the way record the nodes traversed. And LCA is the last recorded node.

						(BALANCED)
			               100
                          /    \
                         /      \
                        80       120
                       /  \      / \
                     50    90   110  300
                     /\    /\
                    /  \  /  \
                   10 60  85 95

				   		  (LCA)
			                20
                          /     \
                         /       \
                        8       22
                       /  \      
                      4   12     
                          /\
                         /  \
                        10  14
			

			
		
		*/
	class LowestCommonDescendent
	{
	public:
		void callLowestCommonDescendent()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			//Order refers to the position of Parent node
			LowestCommonDescendentX(objTrrr.root,90, 95); //90
			LowestCommonDescendentX(objTrrr.root, 60, 110); //90



			BuildTree objTrrr2;
			objTrrr2.AddValuesLCA();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr2.printTreeInOrder(objTrrr2.root);
			cout << "\r\n";

			//Order refers to the position of Parent node
			LowestCommonDescendentX(objTrrr2.root, 14, 8); //8
			LowestCommonDescendentX(objTrrr2.root, 10, 22); //20
		}

	private:
		void LowestCommonDescendentX(NodeTree* rt, int v1, int v2)
		{
			NodeTree* cur = rt;
			cout << endl << "find LCA for " << v1 << " " << v2 << endl;
			while (cur != NULL)
			{
				if ((v1 < cur->d) && (v2 < cur->d))
				{	// values being sought are less than currData so get in to left-hive

					cout << endl << v1 << "-" << v2 << " < " << setw(4) << cur->d << " (go LEFT)" << endl;
					cur = cur->L;
				}
				else if ((v1 > cur->d) && (v2 > cur->d))
				{	// values being sought are less than currData so get in to left-hive
					cout << endl << v1 << "-" << v2 << " > " << setw(4) << cur->d << " (go Right)" << endl;
					cur = cur->R;
				}
				else
				{
					cout << endl << "LCA for " << v1 << " " << v2 << " is " << cur->d << endl;
					break;
				}
			}
		}

	};
};