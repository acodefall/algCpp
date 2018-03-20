#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace FindSmallestWindowOfSubstringNM
{
	/*
		Find smallest substring/Pattern_20170617005
			hxxp://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
			Problem:
			Given Pattern and Src array, find the smallest range (inside Src array) within which all of the characters of the Pattern appear. 
			
			 	ptr: "yc"
				src: "xyycefgh"
						 ^  
			 Expand window across src[] until every charcter of the pattern is found.
			 Once that is achieved, try to eliminate the characters on left-end. 
			 Criterion for removal is 
				-Character should be not be pattern (say left-most character is X and it is not present in Pattern, then remove it).
				-Character appears more number of times (say left-most character is Y and it appers twice in TEXT but appers only once in PATTERN, then mremove it).
				 Apply this to rule to left most character. if it meet the rules then remove it
					-shorten the window by 1
					-reduce the occurence count by 1, because that character is NO more in the window.
					Then appy the same rule to newest left-most character.
					Do this in a loop, and remove as many characters as possible from left-end.

				Now go back to processing next character in src[], by advancing currIndex.
				When we advance the currIdex, we stretch the window by 1 character.
				And this changes the occurence count for one of the character.
				Try to strip down the the window on left-end as we did before. 
				Repeat this process until the curIndex reaches the END.

			(matchingCharsCount == PatLen) 
				This means every character found in PATTRN has been encountered in TEXT also.
				Window-reduction should be attempt only after this condition is met

		Steps for Finding smallest substring/Pattern_20170617006
			Build this code using the code used for finding pattern using occurrence count. Parameters are src and patter arrays
			Declare unordered_map for srcOccuranceCount and patOccuranceCount to store occurence count for src and pattern.
			KEY is character and VALUE is count.

			Start ForLoop to compute the occurence count for Pattern and fill out patOccuranceCount.
			Declare gblPatternStartIndx, gblMinWindowLen, TempStartIndex. Set gblMinWindowLen = INT_MAX.
			Start ForLoop to compute the occurence count for Src and fill out srcOccuranceCount.
			Inside 2nd ForLoop, for every element of Src-array, check if that KEY exists in patOccuranceCount and its count is EQUAL or MORE than what is in patOccuranceCount. If so increment 'matchingCharCount'.

			Then check matchingCharCount == patLen, now onwards try to shrink the pattern-window by eliminating the unecessary elements by advancing TempStartIndex. Advance the TempStartIndex past unnecessary elements using WHILE loop. Loop continues If 
							a) (srcOccuranceCount[src[TempStartIndex]] > patOccuranceCount[src[TempStartIndex]])

								OR
							b) (patOccuranceCount[src[TempStartIndex]] == 0)
			Inside while loop advance the HEAD of pattern-Window by incrementing TempStartIndex, and also reduce the count for that character in srcOccuranceCount[].

			Once outside the while loop, we have 2nd pattern-window, and we compute its width by doing CurrentIndex – StartIndex. If 2nd pattern-window is samller than 1st pattern-window, we overwrite both gblPatternStartIndx and gblMinWindowLen.

				
	*/
	class FindSmallestWindowOfSubstring
	{
	public:
		void CallFindSmallestWindowOfSubstring()
		{
			char* src = { "this is a test string" };
			char* pat = {"tist"};
			FindSmallestWindowOfSubstringX2(src, pat);

			//gblPatternStartIndx = 13 and gblMinWindowLen = 6
			//"t stri"
		}

		

		void FindSmallestWindowOfSubstringX2(char* src, char* pat)
		{
			int lenS = strlen(src);
			int lenP = strlen(pat);
			map<char, int> srcOccuranceCount;
			map<char, int> patOccuranceCount;
			for (int p = 0; p < lenP; p++)
			{
				if (patOccuranceCount.find(pat[p]) == patOccuranceCount.end())
					patOccuranceCount.insert({ pat[p],1 });
				else
					patOccuranceCount[pat[p]]++;
			}

			int matchingChars = 0;
			int TempStartIndex = 0; //Start index of most recent pattern-window. Gets updated every time. This may not be the smallest
			int gblPatternStartIndx = -1; //Start index of SMALLEST pattern-window. Update this only when we find 'still smaller pattern-window'
			int gblMinPatternWindowLen = INT_MAX;
		
			for (int s = 0; s < lenS; s++)
			{
				if (srcOccuranceCount.find(src[s]) == srcOccuranceCount.end())
					srcOccuranceCount.insert({ src[s],1 });
				else
					srcOccuranceCount[src[s]]++;

				if ((patOccuranceCount[src[s]] != 0) &&
					srcOccuranceCount[src[s]] <= patOccuranceCount[src[s]])
				{
					matchingChars++;
				}
				if (matchingChars == lenP) 
				{
					//We have a 1st pattern-window, try to reduce the pattern-window
					
					//
					//Src[currentItem] is same src[start] so go past that by advancing start by 1 
					//Subsequent characters(/src[start +1, +2]) may belong to either one of these
					//a) Character may not be pattern at all, so 'go past the characters that are not in pattern' 
					//AND 
					//b) Character may be in pattern but the count is too higher than what is required by patterCount, so 'go past the characters that are in excess of pattern count' (ex: "this is a test string" second I is excess and we want to remove it.)
					//In either case reduce the count in srcOccuranceCount (ex: "this is a test string" second I is excess and we want to remove it.)
					while ( (patOccuranceCount[src[TempStartIndex]] == 0)
							||
							(srcOccuranceCount[src[TempStartIndex]] > patOccuranceCount[src[TempStartIndex]]))
					{
						srcOccuranceCount[src[TempStartIndex]]--;
						TempStartIndex++;
					}
					
					//we have 2nd pattern-window, and we compute its width by doing CurrentIndex – StartIndex.If 2nd pattern-window is samller than 1st pattern - window, we overwrite both gblPatternStartIndx and gblMinWindowLen.
					int WindowLenTemp = s - TempStartIndex + 1;
					if (WindowLenTemp < gblMinPatternWindowLen)
					{
						gblMinPatternWindowLen = WindowLenTemp;
						gblPatternStartIndx = TempStartIndex;
					}
				}
			}
		}
	};
};