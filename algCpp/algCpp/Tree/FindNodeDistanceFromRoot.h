#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace FindNodeDistanceFromRootNM // 20170709002 
{
	/*
		Find the distance of a Node from Root_20170709002
			Start with pre-order recursion code and make few modifictons.
			Pass the level as one of the recursion parameter, and incremenet it for every recursion call.
			Inside the function, before making any recursion calls, check if currData is equal to the Value
			being sought, if the values are equal, do not make any further recursion calls, and
			retrun the Level and exit from function.
			Similarly if the Left-recursion retuns TRUE, it means sought value has been found in left-hive,
			so do not make right-rec call. We do not do similar check after r-rec call because that is the last the
			thing in the function.


			Pre-recusion-code is generates the return code because that compares sought-value against cell-value.
			Post-recusion-code simply bubbles the return code got from recursion calls.

			Example
				           100
                          /    \
                         /      \
                        80       120
                       /  \      / \
                     50    90   110  300
                     /\    /\
                    /  \  /  \
                   10 60  85 95
				Say control is 80.
				Value = 50
					We go until 50, and 50 returns a +ve number to 80, so 80 does not make any more recursion call( to explore 90, 10, 60).
					Then 80 returns +ve number to 100, and 100 does not make any recursion call to explore 120 because it recieved +ve value from Left-recursion call.

				Value = 90
					Since the value is not in left-hive, we go until 10, and every node returns 0. So 80 recieves 0 from Left recursion.
					Then 80 calls 90, and 90 returns +ve value to 80. 90 does not make any more recursion call to 85, 95.
					Then 80 returns +ve number to 100, and 100 does not make any recursion call to explore 120 because it recieved +ve value from Left-recursion call.



	*/
	class FindNodeDistanceFromRoot
	{
		public:
			void callFindNodeDistanceFromRoot()
			{
				BuildTree objTrrr;
				objTrrr.AddValues();

				cout << "\r\n";
				cout << "Tree content\r\n";
				objTrrr.printTreeInOrder(objTrrr.root);
				cout << "\r\n";
				int Value = 50;

				//cout << "Find Node distance for " << Value << "\r\n";
				Value = 50;
				int distance = FindNodeDistanceFromRootEfficient(objTrrr.root, Value, 0);
				cout << "Node " << Value << " is at distance " << distance << "\r\n"; //2
			
				Value = 80;
				//cout << "Find Node distance for " << Value << "\r\n";
				distance = FindNodeDistanceFromRootEfficient(objTrrr.root, Value, 0);
				cout << "Node " << Value << " is at distance " << distance << "\r\n";  //1

				Value = 90;
				//cout << "Find Node distance for " << Value << "\r\n";
				distance = FindNodeDistanceFromRootEfficient(objTrrr.root, Value, 0);
				cout << "Node " << Value << " is at distance " << distance << "\r\n"; //2


				//cout << "Find Node distance for " << Value << "\r\n";
				Value = 50;
				distance = FindNodeDistanceFromRootX(objTrrr.root, Value, 0);
				cout << "Node " << Value << " is at distance " << distance << "\r\n"; //2

				Value = 80;
				//cout << "Find Node distance for " << Value << "\r\n";
				distance = FindNodeDistanceFromRootX(objTrrr.root, Value, 0);
				cout << "Node " << Value << " is at distance " << distance << "\r\n";  //1

				Value = 90;
				//cout << "Find Node distance for " << Value << "\r\n";
				distance = FindNodeDistanceFromRootX(objTrrr.root, Value, 0);
				cout << "Node " << Value << " is at distance " << distance << "\r\n"; //2

				
			}

		private:

			/*
			
			         


			
			*/
			int FindNodeDistanceFromRootEfficient(NodeTree* root, int Value, int distance)
			{
				if (root)
				{
					//cout << root->d << " " << distance << endl;
					if (root->d == Value) //we found the VALUE,  return +ve number.  Here return code originates. 
					{
						//cout << "Found the Value " << Value << " No recursion required" << endl;
						return distance;
					}

					
					int dist = FindNodeDistanceFromRootEfficient(root->L, Value, distance + 1);
					if (dist != 0) //Value was found in Left-hive so do not make right recursion call. Return the + value to caller.
					{			   //Even if we make R-Rec call, that will return 0, and we end up returning 0 can our-caller.			
									//By returning here itself, we avoid that
						//cout << "Left-Rec(): use the return code " << dist << " from " << root->L->d << endl;
						return dist;
					}
					
					//Value was NOT found in Left-hive so make right recursion call. Return the + value to caller.
					dist = FindNodeDistanceFromRootEfficient(root->R, Value, distance + 1);
					return dist; //This just bubbles up the return code.
				}
				else
				{
					return 0; //return 0. Here return code originates. 
				}
			}

			int FindNodeDistanceFromRootX(NodeTree* root, int Value, int distance)
			{
				if (root)
				{
					//cout << root->d << " " << distance << endl;
					if (root->d == Value) //we found the VALUE,  return +ve number.  Here return code originates. 
					{
						//cout << "Found the Value " << Value << " No recursion required" << endl;
						return distance;
					}

					int distL = FindNodeDistanceFromRootX(root->L, Value, distance + 1);
					int distR = FindNodeDistanceFromRootX(root->R, Value, distance + 1);
					
					//If value was found in L-hive, then distL would be +ve value and distR would be 0.
					//If value was found in R-hive, then distR would be +ve value and distL would be 0.
					//Return to caller whatever is +ve 
					return max(distR, distL);
				}
				else
				{
					return 0; //return 0. Here return code originates. 
				}
			}
	};
};