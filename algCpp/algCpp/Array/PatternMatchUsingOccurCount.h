#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
namespace PatternMatchUsingOccurCountNM //20170617003
{
	/*
		Pattern matching using ocurence count.
		Src is said to contain the pattern if src has all the characters of pattern and also their count is EQUAL or MORE.
		Say pattern has "a" and "b" in quantities 2 and 3. Then src should also have "a" and "b" in EQUAL or MORE quantity.
		First compute the occurence-count for Pattern. Then compute the occurence count for Src[].
		
		As we are computing the occurence count for src[], in the same loop check if that character exists 
		in occurence-map of pattern, and then check the count also. If the character is in present both the maps,
		and its count is EQUAL or HIGHER in src-occurence-map, then increment a counter
		called matchingCharCount. Inside the same loop, check if the matchingCharCount is same as patternLength;
		if so we can conclude that pettern is present in src-array. Then stop computing occurence count for whole src array,
		exit the program. Note we do not waste time by computing the occurence count for whole src-array.
		

		ter, while computing the occurence count for Src, 
		check if that character happens to exist in Pattern-array and also thier quantity is higher, if that is true increment 
		the variable called matchingCharCount. When matchingCharCount == PatLen, we can declare that Pattern exists in Src array.

		Steps:
			
				Parameters are src and patter arrays
				Declare unordered_map for srcOccuranceCount and patOccuranceCount to store occurence count for src and pattern.
				KEY is character and VALUE is count.
				Start ForLoop to compute the occurence count for Pattern and fill out patOccuranceCount.
				Start ForLoop to compute the occurence count for Src and fill out srcOccuranceCount.
				For every element of Src-array check if that KEY exists in patOccuranceCount and its count is EQUAL or MORE
				than what is in patOccuranceCount. If so increment 'matchingCharCount'.

				Then check matchingCharCount == patLen, if so declare that the pattern exists in Src-array.

	*/
	class PatternMatchUsingOccurCount
	{
		public:
			void callPatternMatchUsingOccurCount()
			{
				char* src = { "Hi, is this a test string" };
				char* pat = { "tist" };

				cout << "\r\n";
				cout << "PatternMatchUsingOccurCount \r\n";
				cout << "src: " << src << "pattern: " << pat << "\r\n";
				//1-14 
				//"Hi, is this a test string"
				//"i, is this a t"

				PatternMatchUsingOccurCountX(src, pat);

			}
			/*
				Parameters are src and patter arrays
				Declare unordered_map for srcOccuranceCount and patOccuranceCount to store occurence count for src and pattern.
				KEY is character and VALUE is count.
				Start ForLoop to compute the occurence count for Pattern and fill out patOccuranceCount.
				Start ForLoop to compute the occurence count for Src and fill out srcOccuranceCount.
				For every element of Src-array check if that KEY exists in patOccuranceCount and its count is EQUAL or MORE
				than what is in patOccuranceCount. If so increment 'matchingCharCount'.

				Then check matchingCharCount == patLen, if so declare that the pattern exists in Src-array.
			*/
			void PatternMatchUsingOccurCountX(char* src, char* pat)
			{
				int lenS = strlen(src);
				int lenP = strlen(pat);
				unordered_map<char, int> srcOccuranceCount;
				unordered_map<char, int> patOccuranceCount;

				//compute occur count for Pattern 
				for (int p = 0; p < lenP; p++)
				{
					if (patOccuranceCount.find(pat[p]) == patOccuranceCount.end())
						patOccuranceCount.insert({ pat[p],1 });
					else
						patOccuranceCount[pat[p]]++;
				}

				//compute occur count for src-array, and as we are computing the occurence count,
				//in the same loop check if the src-character exists in occurence-map of pattern.
				//The character is in present both the maps and their count also same, then increment counter
				//called matchCount. If the matchCount is same as patternLength then we can conclude that.
				//pettern is present in src-array, and stop computing occurence count for whole src array. 
				int matchingCharCount = 0;
				int start = 0;
				int startIndx = -1;
				for (int s = 0; s < lenS; s++)
				{
					if (srcOccuranceCount.find(src[s]) == srcOccuranceCount.end())
						srcOccuranceCount.insert({ src[s],1 });
					else
						srcOccuranceCount[src[s]]++;

					if ((patOccuranceCount[src[s]] != 0) &&
						srcOccuranceCount[src[s]] <= patOccuranceCount[src[s]])
					{
						if (startIndx == -1)
						{
							startIndx = s;
						}
						matchingCharCount++;
					}
					if (matchingCharCount == lenP)
					{
						cout << "\r\n";
						cout << "Found the pattern. start: " << startIndx << " end: " << s << "\r\n";
						break;
					}
				}
			}
	};

};