#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace IsomorphicNM
{
    /*
		@RED20180127001
			If the two strings are isomorphic then PATTERN should of occurence should be same.Order of occurence count should be same.
			Eg: EGG & ADD
			For example : If 2nd and 3rd letters are duplicates in S1, and then S2 should also have duplicates at 2nd and 3rd position.

			Solution involves computing occurence count in different hash map.Assume the length of string is same and start iterating.
			Say if the 3rd - letter is missing in 1st hash table, then it should also be missing in 2nd hash table.
			Say if the 3rd - letter is missing in both the hash tables, then current count should be SAME.
	*/
	class IsomorphicX
	{
		public:
			void callIsomorphic()
			{
				unordered_map<char,int> sh1;
				unordered_map<char,int> sh2;

				string s1("egg");
				string s2("add");

				const char* itr1 = s1.c_str();
				const char* itr2 = s2.c_str();
				
				if (s1.length() == s2.length())
				{
					int i = 0;
					bool isomorphic = true;
					while (i < s1.length())
					{
						if (sh1[(char)(*(itr1 + i))] != sh2[(char)(*(itr2 + i))])
						{
							//not isomorphic
							isomorphic = false;
						}
						i++;
					}
				}
			}
	};
};