#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <sstream>
#include <stack>
using namespace std;

namespace DecodeBracketsNM
{
	/*
			in:  "af2[v3[gr]t]nmsd"; 
                        out: "afvgrgrgrtvgrgrgrtnmsd"
			

	*/
	class DecodeBracketsX
	{
		public:
			void callDecodeBrackets()
			{
				//af2[v]dh2h[kr2[ow]q]tg
				//0123456780abcdef
				string src;
				src = "af2[v3[gr]t]nmsd"; //"afvgrgrgrtvgrgrgrtnmsd"
				DecodeBrackets1((char*)src.c_str());
			}

			void DecodeBrackets1(char* s)
			{
				int len = strlen(s);
				stack<int> st;
				string pre;
				string start;
				string end;
				bool processed = false;
				for (int i = 0; i < len; i++)
				{
					if ((s[i] >= '0') && (s[i] <= '9'))
					{
						st.push(i);
						processed = true;
					}
					else
					{
						if (s[i] == ']')
						{
							int sti = st.top();
							int cnt = s[sti] - '0';
							st.pop();
							sti += 2; // go past the number say "2["
							string tmp;
							for (int k1 = sti; k1 < i; k1++)
							{
								if ((s[k1] == '[') || ((s[k1] >= '0') && (s[k1] <= '9')))
								{

									tmp += pre;
									while ((s[k1] != ']') && (k1 < i))
										k1++;
								}
								else
								{
									tmp += s[k1];
								}
							}
							string tmp1;
							while (cnt > 0)
							{
								tmp1 += tmp;
								cnt--;
							}
							pre = tmp1;
						}
					}
					if (st.size() == 0)
					{
						if (s[i] != ']')
						{
							if (processed == false)
								start += s[i];
							else
								end += s[i];
						}
					}
				}
				pre = start + pre + end;
			}
	};

};