#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>

using namespace std;

namespace WordBreakNM
{
	//http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
	class WordBreak
	{
	public:
		void callWordBreak()
		{
			string src("459");

			cout << "Convert string(" << src.c_str() << ") in to INT" << endl;

			const char* src1 = src.c_str();
			int i = src.length() - 1;
			int position = 0;
			int result = 0;
			while (i >= 0)
			{
				int tmp = src1[i] - '0';
				cout << "src1[" << i << "] = " << src1[i] << " in INT is " << tmp << endl;
				result += (tmp * pow(10, position));
				cout << "result is " << result << endl;
				i--;
				position++;
			}
		}

		//
		string WordBreakUsingRecursion(string remaining, list<string>& dictionary)
		{
			string firstPart = "";
			string src = remaining;
			int len = src.length();
			//src = iLike
			//firstPart will be {"i", "iL", "iLi", "iLik", "iLike"}
			for (int i = 0; i < len; i++)
			{
				//divide the src  as 1st and 2nd part. 2nd part will be passed to recursion.
				//"iLike" ==> firstPart "iL"
				firstPart = src.substr(0, i + 1);
				
				//src='iLike', firstPart='iLi' then remaining='ke'
				remaining = remaining.substr(i + 1, len - (i + 1));
				
				//1st part is in dictionary
				find(dictionary.begin(), dictionary.end(), remaining);
				
				string combs;
				if (remaining.length())
				{
					combs = WordBreakUsingRecursion(remaining); //reduce the length by 'i'
				}

				//string allCombs = firstPart;
				if (combs.length() > 0)
				{
					find(dictionary.begin(), dictionary.end(),combs);
					//allCombs += " ";
				}
				allCombs += combs;
				return allCombs;
			}
		}

	};
};
