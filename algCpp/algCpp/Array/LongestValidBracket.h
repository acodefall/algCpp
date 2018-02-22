#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
namespace LongestValidBracketNM
{
	/*
		LongestValidBracketLength_@RED20180128005
		When the cursor is at Open-bracket, PUSH the close bracket followed by its index of Open-bracket.
		So we can assume that, when POPING out we will first get the INDEX and then the bracket located at that index.

		When the cursor is at Close-bracket, POP two items from stack, 1st will be the index and 2nd will be the Open-bracket.
		Use the to know the width of the bracket, subtract "currIndex - poppedIndex".
		If the 2nd item is not a Open-bracket then there is a mismatch, ignore it.

		"( c d { 1 2 3 ( r a m )   p c i  }    9 8   {  k e y  } b o a r d )"
		0     3       7       11         15         18       22           28
	*/

	class LongestValidBracketX
	{
		public:
			void callLongestValidBracket()
			{
				//string src = "(cd{123(ram)pci}98{key}board)";
				string src = "cd{123(ram)pci}98{key}board"; //12
				LongestBracket(src);
			}

			void LongestBracket(string s)
			{
				stack<int> st;
				char* sc = (char*)s.c_str();
				int longestBr = 0;
				bool invalidBracket = false;
				for (int i = 0; i < s.length(); i++)
				{
					if ((sc[i] == '{') || (sc[i] == '('))
					{
						st.push(i); //push the index
						st.push((int)sc[i]); //push the bracket also
					}
					else if ((sc[i] == '}') || (sc[i] == ')'))
					{
						while ((st.size() > 0))
						{
							if ((sc[i] == '}') && (st.top() == '{'))
							{	//valid bracket
								st.pop();//pop bracket
								longestBr = max(longestBr, i - st.top());
								st.pop();//pop index also
								break;
							}
							else if ((sc[i] == '}') && (st.top() == '('))
							{   //invalid bracket
								invalidBracket = true;
								break;
							}

							if ((sc[i] == ')') && (st.top() == '('))
							{
								st.pop();//pop bracket
								longestBr = max(longestBr, i - st.top());
								st.pop();//pop index also
								break;
							}
							else if ((sc[i] == '}') && (st.top() == '('))
							{   //invalid bracket
								invalidBracket = true;
								break;
							}

							//Non-bracket, pop it also
							st.pop();
						}

						if (invalidBracket)
							break;
					}
				}

			}
	};
};