#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

namespace  BrickPointsNM
{
	//
	const int SIZEX = 8;
    class BrickPoints
    {

		public:
			void callBrickPoints()
			{
				int src[SIZEX] = { 5, -2, 4, 'Z', 'X', 9, '+', '+' }; 
				int sum = func(src);
				cout << "sum : " << sum << endl;
			}

    
        int func(int* src)
        {
            stack<int> totalScore;
            stack<int> currentScore;

            //I am adding these so that I do not have to check whether Stack.Empty();
            totalScore.push(0);
            currentScore.push(0);

            //Always compute 'Current score', and then compute 'Total Score'
            //because latter depends on former
            //foreach (int x in src)
			for(int i = 0; i < SIZEX; i++)
            {
                if (src[i] == 'Z')
                {
                    //ignore 'last TotalScore' and also 'last Current score'
                    //So POP one value from both the Stacks
                    totalScore.pop();
                    currentScore.pop();
                }
                else if (src[i] == 'X')
                {
                    //compute 'Current score', and PUSH in to currentScore
                    // 'Current score' = 'last Current score' * 2
                    currentScore.push(currentScore.top() * 2);

                    //compute 'Total score', and PUSH in to totalScore
                    // 'Total score' = 'last Current score' + 'last Total score' 
                    totalScore.push(totalScore.top() + currentScore.top());
                }
                else if (src[i] == '+')
                {
                    // 'Current score' = 'last Current score' + 'last Current score' 
                    int clastInt = currentScore.top();
                    int clastlastInt = currentScore.top();
                  
					int currScore = clastInt + clastlastInt;

                    //push them back again in the reverse order
                    currentScore.push(clastlastInt);
                    currentScore.push(clastInt);
                    currentScore.push(currScore);

                    //totalScore
                    totalScore.push(totalScore.top() + currentScore.top());
                }
                else
                {
                    currentScore.push(src[i]);
                    totalScore.push(totalScore.top() + currentScore.top());
                }

            }
            return totalScore.top();
        }

	};
};
