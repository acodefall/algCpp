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
			We will be given a word, who's letter are supposed to be alphabetical order and also they should be in either upper case or lower. The First letter of the word decides the upper-case and lower-case for whole word. Assume that 1st letter is in lower case then, rest of the letters must be in lower case, otherwise they will be breaking the rule.
			Our job is to find the index where rules get broken.  
			Ex: "ART", all the letters are in ORDER
					"BART", letters are not in ORDER.

			Logic:
				Iterate the src-array from [1] to SrcLen
				-compare [i-1]  & [i] //1st of the rule is verified
				-Check if the character is less than 'z' or 'Z'. //2nd of the rule is verified

				If any one of this condition is not met, then break the loop. We have found the answer.


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