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
	
		FindLongestUniqueSubArray_RED20180129001
		LongestUniqueSubSequence
		We have to find the Sequence that does not have any duplicates character.
		An array may have several sequences that are unique.
		Among these we have to chose the window that is longest.
		We can tell whether window has duplicates by checking occurence count. 
		No duplicates means ocr-count must be 1. So instead of storing the real occurence count, we store the 
		'index of last occurence of that character'. 
		Say if 'a' has not occured at all, then value will be -1.
		If 'a' appears at 5th index, then value will be 5.
		If 'a' appears again at 7th index, then value will be changed to 7.

		Whenever the unique-window gets broken, record the length of unique window that got broken.
		Then begin exploring the 2nd-unique-window. This 2nd-unique-window's start index will right after 
		where the duplicate character occured. 

		Say first 4 characters are unique, so windowlength to 4, and startindex is 0. Cursor is at [5] and is pointing to 'a'.
		Say 'a' occurs at [2] also, so relocate the startindex to 3.
		New uniquewindow starts at 3, and it goes from 3 to 5. 

		Also break current-unique-window only if the character appears within currently ongoing  window.
		Example: current window starts at [2]. And we found that a charcter appears at [1].
		This is OK. This does not break the window because character appears outside current-window.
			
			
		EXAMPLE:
				WidestWindow = 0 //widest window where every character is UNIQUE
				wlen = 1 		 //width of currently on going window
				st = 0; 		 //start window index
				i = 0; 			 //cursor
				ocp[];           //occurence array that holds index, not the count
				input:
						"a b c b d f g a x"
						 0 1 2 3 4 5 6 7 8

				Runtime:
						i,  st, wlen, WidestWindow
						0   0	1      1
						1   0	2      2 
						2   0	3      3
						3   2	1      3
						4   2   2      3
						5   2   3      3
						6   2   4      4
						7   2   5      5
						8   2   6      6

				ocp(stores INDEX, not the count)
				'a' = 0, 7
				'b' = 1
				'c' = 2
				'd' = 4
				'f' = 5
				'g' = 6
				'x' = 8
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
