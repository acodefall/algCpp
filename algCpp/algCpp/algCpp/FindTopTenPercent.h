#pragma once
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
using namespace std;

//NotRead
namespace FindTopTenPercentNM
{
	class FindTopTenPercentX;
	

	class wordData
	{
		public:
				string word;
				int ocurence;
				wordData(string s, int cnt)
				{
					word = s;
					ocurence = cnt;
				}

			
	};


	class compareWordData
	{
		public:
			bool operator()(wordData* p1, wordData* p2)
			{
				bool ret = false;
				if (p1->ocurence < p2->ocurence)
					ret = true;
				else
					ret = false;
				return ret;
			}
	};
	class FindTopTenPercentX
	{
		public:
			void DoFindTopTenPercentX(const char* fName)
			{
				list<string> wordList;
				//assume we read from file and get some words and store them in list<string>
				int len = strlen(fName);
				int k = 0;
				int sp = 0;
				while (k < len)
				{
				
					if(
						(fName[k] == ' ') && (wordList.size() == 0) && (sp == 0)
							||
						((fName[k] == ' ') && (sp > 0)))
					{
						(sp == 0) ? sp : sp++;
						wordList.push_back(string(&fName[sp],k-sp));
						sp = k;
					}
					k++;
				}

			
				unordered_map<string, int> wordAndOccurenceMap;
				priority_queue<wordData*, vector<wordData*>, compareWordData> pq;
					
				for (list<string>::iterator itr = wordList.begin(); itr != wordList.end(); itr++)
				{
					//Add words to wordAndOccurenceMap;
					auto wordInMap = wordAndOccurenceMap.find(*itr);
					if (wordInMap == wordAndOccurenceMap.end())
						//Add word
						wordAndOccurenceMap.insert(make_pair(*itr, 1));
					else
						//increment words counter
						wordAndOccurenceMap[*itr]++;
				}
				
				
				for (auto itr2 = wordAndOccurenceMap.begin(); itr2 != wordAndOccurenceMap.end(); itr2++)
				{
					//Add words to wordAndOccurenceMap;
					wordData* w = new wordData((*itr2).first, (*itr2).second);
					pq.push(w);
				}
				
				//find top 90%
				int needed = wordList.size() * (0.90);
				stringstream  ss;
				ss << "words in order \r\n";
				while (pq.size() >  needed)
				{
					
					wordData* w = pq.top();
					if (w != 0)
					{
						ss << w->word << " " << w->ocurence << "\r\n";
					}
					pq.pop();
				}
				cout << ss.str();
				//

			}
	};

	class callFindTopTenPercentX
	{
		public:
			void callFindTopTenPercent()
			{
				FindTopTenPercentX objFindTopTenPercentX;
				const char* src = "makes sure only one other makes till thread makes will do makes till the makes initialization only do and till makes then other makes threads will makes wait";
				objFindTopTenPercentX.DoFindTopTenPercentX(src);
			}
	};
};