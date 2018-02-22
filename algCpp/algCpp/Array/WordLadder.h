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

namespace WordLadderNM
{
	class WordLadderX
	{
		public:
			void callWordLadder()
			{
				list<string> dictWord({ "hot", "dot", "dog", "lot", "log", "cog" });

				worslad((string)"hit", "cog",dictWord );

					//COG is 5 steps way from source.
					//distanceMap[COG] = 5

					/* Path  "Cog Dog Dot Hot Hit"
					hit     "" ^
					hot     hit ^
					dot     hot ^
					dog     dot ^
					lot     hot
					log     lot
					cog     dog ^
					*/

				
			}

			

			string stringCopy(char* s)
			{
				int len = strlen(s);
				string s1;
				for (int i = 0; i < len; i++)
				{
					s1 += s[i];
				}
				return s1;
			}
			void worslad(string sW, string eW, list<string> dict)
			{
				queue<string> q;
				int dist = 1;
				map<string, int> wrdDisrance;
				q.push(sW);
				
				if (wrdDisrance.find(sW) == wrdDisrance.end())
					wrdDisrance.insert({ sW, dist });
				else
					wrdDisrance[sW] = dist;
				while (q.size() > 0)
				{
					string wrd = q.front();
					q.pop();

					if (wrd == eW)
					{
						cout << "end word found" << endl;
						break;
					}
					dist++;
					//replace the letters
					
					for (int i = 0; i < wrd.length(); i++)
					{
						string cpy = wrd;
						char* cword = (char*)cpy.c_str();
						char cache = cword[i];
						for (char c = 'a'; c <= 'z'; c++)
						{
							//if the letter is same, no point in replacing , so skip it.
							if (c == cache)
								continue;
							//overwrite the new letter
							cword[i] = c;
							string newWord(stringCopy((char*)cword));

							//check if the newWord is in in dictionary, if it is present then that is a Hop-word, add it to Q
							if (std::find(dict.begin(), dict.end(), newWord) != dict.end())
							{
								//Remove new word from dictionary
								dict.remove(newWord);

								//Found the newWord in dictionary add to Q
								q.push(newWord);

								wrdDisrance[newWord] = wrdDisrance[wrd] + 1;
							}
						}
					}
				}
			}
	};
};