#pragma once
//MergeUnsortedWordList

#pragma once
#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

namespace PatternReplaceNM //@RED20170730006
{
	/*
		Find and replace a pattern_20170730006 
		

		output:
			source : ramabxabc2abcabcy7
			pattern : abc
			replace : ##

			source : ramabx##2##y7


	

	*/
	class PatternReplace
	{
	public:
		void callPatternReplace()
		{
			
			string src("ramabxabc2abcabcy7");
			string pattern("abc");
			string replace("##");
			replaceX(src,pattern,replace);
		}

		void replaceX(string srcIn, string patterntIn, string replaceIn)
		{
			char* src = (char*)srcIn.c_str();
			char* ptn = (char*)patterntIn.c_str();
			char* rpc = (char*)replaceIn.c_str();
			int i = 0;
			
			
			int Skip = 0;
			cout << endl << "source : " << src << endl;
			cout << "pattern : " << ptn << endl;
			cout << "replace : " << rpc << endl;
			
			while (i < srcIn.length())
			{
				//check for whole pattern
				int patternCount = 0;
				int j = i;
				while ((j + patterntIn.length() - 1) < srcIn.length())
				{
					int k = 0;
					for (; k < patterntIn.length(); k++, j++)
					{
						if (src[j] != patterntIn[k])
						{
							break;
						}
					}
					if (k == patterntIn.length())
					{	//found a pattern, check further...
						patternCount++;
					}
					else
					{	//pattern broke, EXit
						break;
					}
				}

				if (patternCount > 0)
				{
					//copy the replacement
					int t = i;
					for (int k = 0; k < replaceIn.length(); k++, t++)
					{
						src[t - Skip] = replaceIn[k];
					}
					//Park i beyond pattern
					i = i + (patternCount * patterntIn.length());

					//update the skip count
					Skip = Skip + (patternCount * patterntIn.length()) - replaceIn.length();
				}
				else
				{
					src[i - Skip] = src[i];
					i++;
				}
			}

			//Resize the src
			if (Skip > 0)
				srcIn.resize(srcIn.length() - Skip);

			cout << endl << "source : " << src << endl;
			
			
		}
	};
};
