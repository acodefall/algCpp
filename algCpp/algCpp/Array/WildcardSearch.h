#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace WildCardSearchNM
{
	/*
	Wildcard Comparison_RED20180128001
	When there is no * compare letter by letter, and every letter should match.
	"abc" "abc"
	When there is "*", skip comparison completely. So comparison logic toggles between "letter-by-letter compare mode" and "skip compare mode".
	When there is a letter after "*", skip until that letter comes. Once that letter comes, search should switch back to "letter-by-letter compare mode".
	When there is no letter after "*", abort comparison and return TRUE.

	Here is a walk through: Compare the 1st letter of TEXT and PATTERN, if there is no match, then return FALSE and exit.
	Otherwise go to next loop, and compare 2nd letter against 2nd letter, and go to next loop. If the letter is *, no comparison is needed.
	But we need to handle two sub cases.
	-If "*" is the last letter, then exit the function altogather.
	"asvvv" "as*" //Here no need to compare vvv

	-If there is a latter (say X) after "*". Then simply loop through TEXT until X is found, without doing any comparison.
	Once X is found, in the subsequent rounds do letter by letter comparison.

	"a123bcdfff" "a*bcd*"
	-compare "a & a" using "letter-by-letter compare mode"
	-skip 123 until "b" is found. ("skip compare mode").
	-compare "c d"  using "letter-by-letter compare mode"
	-abandon comparison because "*" is the last letter

	aa a = False
	aa aa = True
	aaa aa = False
	aa * = True
	aa a* = True
	ab ?* = True
	aab c*a*b = False
	aabbbcc *b* = True

	*/
	class WildCardSearchX
	{
		public:
			void callWildCardSearch()
			{
				list<string> s = {  "aabbbcc", "aa", "aaa", "aa", "aa", "ab", "aab" };
				list<string> q = {  "*b*",      "a", "aa",  "aa", "*",  "a*", "?*" };
				for (int h = 0; h <  s.size(); h++)
				{
					bool x = wildSearch(*(std::next(s.begin(), h)), *(std::next(q.begin(), h)));
					cout << *(std::next(s.begin(), h)) << " " <<  *(std::next(q.begin(), h)) << " " << x << endl;
				}
			}

			bool wildSearch(string s, string q)
			{
				bool retval = false;
				const char* qc = q.c_str();
				const char* sc = s.c_str();
				int qi = 0;
				int si = 0;

				//loop of the query will drive the logic
				while (qi < q.length())
				{
					//check length
					//Make sure length of src satisfies the length criterion.
					//Ex: If query is "*fc", we should first make sure that there are 3 letters in src;
					//then proceed to check whether those letters happens to be "fc"
					if (si < s.length())
					{
						;
					}
					else
					{
						retval = false;
						break;
					}

					//check letter 
					if (qc[qi] == '*')
					{
						//If the Q ends with "*". Then end the search with TRUE
						//If the Q has a character AFTER "*" 
						//then position both Q-index to point to that letter, and then advance S-index until we get that character.
						//If the character is not found, then 
						//Ex: "yu*k"

						//Q ends with *, so no need to check. Simply exit
						if (q.length() == qi+1)
						{
							retval = true;
							break;
						}
						
						//Test whether there is a character after "*". I so record the letter.
						while (qi < q.length() && qc[qi] == '*')
						{
							qi++;
						}
						//Now q[qi] points character after "*"
						//Now advance the s[si] until it matches q[qi]
						//If we fail to find, then whole seach is failure.
						
						while (si < s.length() && s[si] != qc[qi])
						{
							si++;
						}
						
						//Q ends with *, so no need to check. Simply exit
						if ((s[si] != qc[qi]) || si < s.length())
						{
							retval = false;
							break;
						}
					}
					else if (qc[qi] == '?')
					{
						//skip checking only current character
						si++;
						qi++;
						retval = true;
					}
					else
					{
						if (sc[si] == qc[qi])
						{
							si++;
							qi++;
							retval = true;
						}
						else
						{
							retval = false;
							break;
						}
					}
				}

				return retval;
			}

	};
};
