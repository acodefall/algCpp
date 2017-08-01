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

namespace BalancedBSTCheckUsingMinMaxNM //@RED20170731006
{
	/*
	We can check if the Tree is Balanced using 3 methods
			   -Check for MIN and MAX 
					This is superior and work even when the Tree has duplicates.
			   -Do inorder traversal and check if the output is increasing, is so Tree is balanced.               
			This can be implemented using Recursion and non-recursion methods.
	
	*/
	class BalancedBSTCheckUsingMinMax
	{
		public:
				void callBalancedBSTCheckUsingMinMaxNM()
				{
					BuildTree objTrrr;
					objTrrr.AddValuesNonBST();
					//objTrrr.AddValues();

					cout << "\r\n";
					cout << "Tree content\r\n";
					objTrrr.printTreeInOrder(objTrrr.root);
					cout << "\r\n";


					bool x = BalancedBSTCheckUsingMinMaxX(objTrrr.root, INT32_MIN, INT32_MAX);

				}

				/*bool BalancedBSTCheckUsingMinMaxX(NodeTree* rt, int Min, int Max)
				{
					bool Balanced = true;
					NodeTree* cur = rt;
					if ( rt != NULL)
					{	//If the Node is not NULL, make sure that they are between the MIN and MAX limits.
						//If the fail the MIN and MAX test, then return False.
						if ((rt->d > Max) || (rt->d < Min))
						{
							Balanced = false;
							return Balanced;
						}
						//any Left child should be LESS than PARENT. So rt->d is MAX
						bool left = BalancedBSTCheckUsingMinMaxX(rt->L, Min, rt->d);

						//any Right child should be HIGHER than PARENT. So rt->d is MIN
						bool right = BalancedBSTCheckUsingMinMaxX(rt->R, rt->d, Max);


						Balanced = left & right;
					}
					else  //return TRUE if the node is NULL
						Balanced = true;

					return Balanced;
				}*/

				bool BalancedBSTCheckUsingMinMaxX(NodeTree* rt, int Min, int Max)
				{
					bool Balanced = true;
					NodeTree* cur = rt;
					if (rt != NULL)
					{	//If the Node is not NULL, make sure that they are between the MIN and MAX limits.
						//If the fail the MIN and MAX test, then return False.
						if ((rt->d > Min) && (rt->d < Max))
						{
							//any Left child should be LESS than PARENT. So rt->d is MAX
							bool left = BalancedBSTCheckUsingMinMaxX(rt->L, Min, rt->d);

							//any Right child should be HIGHER than PARENT. So rt->d is MIN
							bool right = BalancedBSTCheckUsingMinMaxX(rt->R, rt->d, Max);
							Balanced = left & right;
							return Balanced;
						}
						else
						{
							Balanced = false;
							return Balanced;
						}
					}
					else  //return TRUE if the node is NULL
						Balanced = true;

					return Balanced;
				}
	};
};
