#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace ReverseWithoutTempNM  //@RED20170725062
{
	/*
		Reverse words of sentence but not the sentence itself 
			Write one routine for reversing WORD, and call that for every word of the sentence.
			Before this isolate each word of the sentence. 

			For isolating word based on TOKEN space follow this logic. We want to handle 
			case of consecutive spaces
			
				When the character is SPACE note down the index, but do not call REVERSE,
				wait until ALL of the consecutive SPACES pass away and next word starts.
				When the next word starts(that means character is non-space) then call REVERSE()
				on previous word.
				Token will have the index of where the prev-word ended.
				Start will have the index of where the prev-word Started.
				After the REV() returns reset TOKEN to 0. and Start = curIndex
				This logic will help us avoid "multiple spaces"

			
	*/
	class ReverseWithoutTemp
	{
		public:
			void callReverseWithoutTemp()
			{
				string s("reverse");
				callReverseWithoutTemp(s,0, s.length() - 1);

				string s1("reverse only words");
				callReverseWithoutOnlyWords(s1);
			}

			//We to reverse only the words but not sentence
			void callReverseWithoutOnlyWords(string& srcIn)
			{
				int st = 0;
				int tk = 0;
				int cur = 0;
				char* src = (char*)srcIn.c_str();
				
				cout << "whole word: " << srcIn.c_str() << endl;

				//seperate words by looking for ' '
				//When we get SPACE note down the index, but do not call REVERSE,
				//wait until ALL of the consecutive SPACES pass away and next word starts.
				//When the next word starts call REVERSE on previous word.
				//Token will have the index of where the last word ended.
				//After the REV() returns reset TOKEN.
				//This logic will help us avoid "multiple spaces"
				
				while(cur < srcIn.length())
				{
					if (src[cur] == ' ')
					{
						//Note down the index of 1st of SPACE, but do not call REVERSE,
						//wait until ALL of the consecutive SPACES pass away and next word starts.
						//Then call REV()
						if (tk == 0)
						{
							tk = cur;
						}
					}
					else
					{
						if (tk > 0)
						{
							//Now all of the consecutive SPACES have passed away and next word has started,
							//Start will have the index of where the prev - word Started.
							//Call REV() on the prev-word who's end-index is kept in TK
							//TK will be pointing to 1st-SPACE, so do 'tk-1' 
							callReverseWithoutTemp(srcIn, st, tk-1);
							tk = 0;
							st = cur;
							
							//After the REV() returns reset TOKEN to 0. and Start = curIndex
						}
					}
					cur++;
				}
				if (st > 0)
				{
					callReverseWithoutTemp(srcIn, st, srcIn.length() - 1);
				}
				cout << "whole word: " << srcIn.c_str() << endl;
			}
			//start and end are INDEXS
			void callReverseWithoutTemp(string& srcIn, int start, int end)
			{
				char* src = (char*) srcIn.c_str();
				//"end - start" will not include the '[start]' so add 1
				cout << "IN: " << srcIn.substr(0, end - start + 1) << endl;
				
				int f = start;
				int r = end;
			
				//cout << src << endl;
				while (f < r)
				{
			
					src[f] = src[f] ^ src[r]; //store both values(src[f] & src[r]) at one place. 
											  //src[f] = "src[f] + src[r]"

					src[r] = src[f] ^ src[r]; //Expel "src[r]" from "src[f] + src[r]"

					src[f] = src[f] ^ src[r]; //Expel "src[f]" from "src[f] + src[r]"
					f++;
					r--;
				}
				//cout << src << endl;
				cout << "Out: " << srcIn.substr(0, end - start + 1) << endl;
			}

	
	};
};