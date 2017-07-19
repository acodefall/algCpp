#pragma once
#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <unordered_map>
using namespace std;

namespace BracketMatchNM
{
	//If the open and close brackets are matching, then their count should also match.
	//If you maintain a one single counter for both; and increment once for every open-bracket and decrement the counter once for every close-bracket; in the end
	//counter should reach 0, provided that brackets match.
	//Code will use same strategy. Iterate the array, increment the counter for every open-bracket; and then decrement the SAME counter once for every close-bracket.
	//Finally if the counter becomes 0, then brackets matchin sync.
	class BracketMatch
	{
	public:
		void callBracketMatch()
		{
			string expr("(()()((()())))");
			//expr = "))((";

			const char* exprCh = expr.c_str();
			int counter = 0;
			for (int i = 0; i < expr.length(); i++)
			{
				if (exprCh[i] == '(')
					counter++;
				else if (exprCh[i] == ')')
				{
					counter--;
					if (counter < 0)
					{   //As soon as counter hits NEGATIVE exit. This will catch "))(("
						break;
					}
				}
			}

			if (counter == 0)
				cout << "Brackets matched" << endl;
			else
				cout << "Brackets did not match" << endl;
		}
	};
};
