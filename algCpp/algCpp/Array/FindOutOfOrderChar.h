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
			Sentence may have both upper-case and lower-case letters.
				If the current letter is a lower-case letter, then compare it against previously seen lower-case letter.
				If the current letter is a higher-case letter, then compare it against previously seen higher-case letter.
				For this to work, we have to be tracking lower-case and upper-case letters.
				And then compare current letter against one of them.
				If they fail to meet the condition then return FALSE.


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
				
				int a = 0; //previous lower case letter
				int A = 0; //previous upper case letter

				cout << endl << "Src '" << src1.c_str() << "'" << endl;

				//compare [i-1] with [i]. Start from [1]
				//Two conditions should be met.
				//[i-1] < [i] 
				// AND
				//[i]  < end
				for (int i = 1; i < src1.length()-1; i++)
				{
					if ( (src[i] >= 'a') && (src[i] <= 'z'))
					{
						if (a == 0)
							a = src[i];
						else
						{
							if (a > (int)src[i])
							{
								cout << "out of order character " << src[i] << endl;
								break;
							}
							else
								a = (int)src[i];
						}
					}
					else if ((src[i] >= 'A') && (src[i] <= 'Z'))
					{
						if (A == 0)
							A = src[i];
						else
						{
							if (A > (int)src[i])
							{
								cout << "out of order character " << src[i] << endl;
								break;
							}
							else
								A = (int)src[i];
						}
					}
				}
			}
	};
};