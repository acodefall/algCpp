#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include <sstream>

using namespace std;

namespace FindOutOfOrderCharNM //@RED20170820001
{
	/*
		Find the first letter that is out of order_RED20170820001
			We will be given a word. All the letters should be either in upper case or lower case; and also their order shoud be increasing.
			We should Identify the first letter that breaks any one of these rules.
			Ex: In "PAZ" //'A' breaks the rule because A is out of order
				In "PaZ" //'a' breaks the rule because 'a' is in lower case.

			Iterate the src-array from [1] to SrcLen, and in each loop, compare "[i-1] and [i]" and also check if the character is WITHIN (lower-case-Z OR upper-case-Z).
			If any one of this condition is not met, then break the loop. We have found the answer.
			The Z-Limit for comparison could be upper-case-Z or lower-case-Z. 
			If the first letter of the WORD is in lower case, then assume lower-case-z as END-value; otherwise assume upper-case-Z as END-value.

   */

	class FindOutOfOrderChar
	{
		public:
			void callFindOutOfOrderChar()
			{
				//string src1("ACIPGQVZ"); //print G
				string src1("ACIPaQVZ"); //print a
				const char* src = src1.c_str();
				
				int start = (int)src[0];
				int end = 0;
				
				//get the END point
				if (src[0] >= 'a' && src[0] <= 'z')
					end = 'z';
				else
					end = 'Z';

				cout << endl << "Src '" << src1.c_str() << "'" << endl;

				//compare [i-1] with [i]. Start from [1]
				//Two conditions should be met.
				//[i-1] < [i] 
				// AND
				//[i]  < end
				for (int i = 1; i < src1.length()-1; i++)
				{
					if ((src[i - 1] < src[i]) && (src[i] <= end))
					{
						;
					}
					else
					{
						cout << "out of order character " << src[i] << endl;
						break;
					}
				}
			}
	};
};