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

namespace BreakLongWordToSubwordsNM
{
	//http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
	//
	/*
		"ilike" can be split in 5 ways as shown below 
				a) i + like
						 l i k e ke ik e ike li k e ke lik e like
					i l i k e ke ik e ike li k e ke lik e like
		
				b) il + ike
						 i k e ke ik e ike
					i l i k e ke ik e ike li k e ke lik e like il i k e ke ik e ike
		
				c)	ili + ke
						  k e ke
					i l i k e ke ik e ike li k e ke lik e like il i k e ke ik e ike ili k e ke

				d)	ilik + e
							e
					i l i k e ke ik e ike li k e ke lik e like il i k e ke ik e ike ili k e ke ilike

				e) ilike + ""


	*/
	class BreakLongWordToSubwords
	{
	public:
		void callBreakLongWordToSubwords()
		{
			string src("ilike");
			list<string> dictionary;
			dictionary.push_back("new");
			dictionary.push_back("spa");
			dictionary.push_back("paper");
			dictionary.push_back("per");
			dictionary.push_back("ape");
			dictionary.push_back("news");

			string parts = WordBreakUsingRecursion(src, true);

			
			
			for (auto itr = dictionary.begin(); itr != dictionary.end(); itr++)
			{
				if (parts.find((*itr).c_str()) != -1)
				{
					cout << (*itr).c_str() << " Y" << endl;
				}
				else
				{
					cout << (*itr).c_str() << " N" << endl;
				}
			}

			cout << endl;

		}

		//
		string WordBreakUsingRecursion(string remaining, bool top)
		{
			string allParts;
			string src = remaining;
			int len = src.length();
			//src = iLike
			//firstPart will be {"i", "iL", "iLi", "iLik", "iLike"}
			for (int i = 0; i < len; i++)
			{
				//divide the src  as 1st and 2nd part. 2nd part will be passed to recursion.
				//"iLike" ==> firstPart "iL"
				string firstPart = src.substr(0, i + 1);
					
				//src='iLike', firstPart='iLi' then remaining='ke'
				remaining = src.substr(i + 1, len - (i + 1));
				
				
				string subwords;
				if (remaining.length())
				{
					subwords = WordBreakUsingRecursion(remaining, false); //reduce the length by 'i'
				}

				//string allCombs = firstPart;
				allParts += " ";
				allParts += firstPart;
				allParts += subwords;
				
				if (top)
				{
					cout << (src).c_str() << endl;
					cout << (firstPart).c_str() << endl;
					cout << (remaining).c_str() << endl;
					cout << (subwords).c_str() << endl;
					cout << (allParts).c_str() << endl;
				}
			}
			return allParts;
		}

		
	};
};
