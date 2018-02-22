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
namespace LongestUniqueSubSequenceNM
{
	/*
	*
		FindLongestUniqueSubArray_RED20180129001
			Find the substring (that is contious sequence) that has unique characters in it, and sequence has to be longest.
			Use "index based occurence count' strategy. Go on sliding a window across the string.  As window moves to right, it keeps on aqcuiring a new letter.
			If the new letter is already present inside the window, then shrink the window and exclude the existing letter.

			- - - - - D - - - - D(new letter)

			Say letter D already exists at 5th position and we want to exclude it from the window, and we do that by moving the start index of the window to 6th position.
			We get the index of D from "index based occurence count".

			As we iterate the string, store the index of current letter in index-Array and use it for checking whether the current item is duplicate.
			if so shrink the window size.
	*/
	class LongestUniqueSubSequenceX
	{
		public:
			void callLongestUniqueSubSequence()
			{
				//string src = "ABDEFGABEF";
				string src = "GEEKSFORGEEKS";
				FindLongestUniqueSubSequence(src); //len = 6, winstart = 3
			}
			//1 3 4 7 7 3
			void FindLongestUniqueSubSequence(string s)
			{
				int occur[UCHAR_MAX];
				int stIdx = 0;
				int maxWinLen = 0;
				int maxWinStartindex = 0;
				int winLen = 0;
				char* sa = (char*)s.c_str();

				//fill with -1
				for (int i = 0; i < UCHAR_MAX; i++)
					occur[i] = -1;

				for (int i = 0; i < s.length(); i++)
				{
					//Current character is appearing for 1st time
					if (occur[sa[i]] == -1) 
					{
						//Current character is NOT repeating
						winLen++;
					}
					else
					{
						//Current character is already appeared. Check whether it appeared within 'currently Active window' or not
						int prevIdx = occur[sa[i]];
						if (stIdx <= prevIdx)
						{
							int newStart = prevIdx + 1;  //Move the start index to new position 
							//Current character is already present within the 'currently Active window'
							//So we need to shrink the window by right-shifting stIdx to the 'right-of-prevIdx'
							if (maxWinLen < winLen)
							{
								maxWinLen = winLen;
								maxWinStartindex = newStart;
							}
							winLen = winLen - (newStart - stIdx); //reduce winLen
							stIdx = newStart;
						}
						else
						{	//Current character is repeated but does not fall within the 'currently Active window'
							//So no need to shrink the window by adjusting stIdx
							winLen++;
						}
					}
					//update occur-array
					occur[sa[i]] = i; 
				}
			}
	};
};
