#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

namespace CompactStringRemovingSpacesNM //@RED20170724010
{
	/*   
		Compact String by Removing Spaces 

				Src:   g       h           j   
					   0   1   2   3   4   5   

				src[0] = 'g' is Non-Token. SHIFT & COPY char. 
				   src[i - shiftCount] = src[i] that is src[0 - 0] = src[0]
				   Reset 'tokenCount' 0 because sequence of spaces ended(because encountered non-space character).
				   Do not increment shiftCount since we RETAINED char
  

				src[1] = ' ' is token. RETAIN this, as this is First Token in the seq of Tokens.
						 (we should replace multiple-spaces with single space)
					Copy src[i - shiftCount] = src[i],  that is src[1-0] = src[1]
					Incr 'tokenCount': 1
					'shiftCount' stays same at '0' since we did not SKIP the char
 

				src[2] = 'h' is Non-Token. 
					Left-shift 'h' by shiftCount & copy  
					copy src[i - shiftCount] = src[i] that is src[2-0] = src[2]
					Reset 'tokenCount' 0 because sequence of spaces ended(because encountered non-space character).
				   'shiftCount' stays same at '0' since we did not SKIP the char
  

				src[3] = ' ' is token. RETAIN this, as this is First Token in the seq of Tokens.
					Repeat src[1]

				src[4] = ' ' is token. Skip this because this is 2nd in the seq of tokens(tokenCount : '1')
				   We do not copy anything
				   Incr tokenCount: 2
				   shiftCount++ 

				src[5] = j is Non-Token. Left-shift 'j' by shiftCount(1) & copy  
					Left-shift by '1' copy src[5 - 1] to src[5]
					Reset tokenCount 0
					shiftCount stays same at '1' since we RETAINED the char
     
				   0   1   2   3   4   5   
				   g       h           j  //Input
				   g       h       j      //Output
	
	*/
	class CompactStringRemovingSpaces
	{
	public:
		void callCompactStringRemovingSpaces()
		{
			string src("g hj  jj  kf");
			//"dfg hjj jjjj kfff yyy mmmmm 7777" compacted version
			   
			cout << " Src: " << endl;

			stringstream ss;
			for (int i = 0; i < src.length(); i++)
			{
				cout << setw(4) << src[i];
				ss << setw(4) << i;
			}
			cout << endl;
			cout << ss.str() << endl;

			CompactStringRemovingSpacesX(src);

		}

		void  CompactStringRemovingSpacesX(string srcIn)
		{
			char* src = (char*) srcIn.c_str();
			int shiftCount = 0;
			int tokenCount = 0;
			int i = 0;
			while (i < srcIn.length())
			{
				cout << endl;
				//cout << " src[" << i "] = " << src[i] << endl;
				if (src[i] == ' ')
				{
					tokenCount++;
					cout << "src[" << i << "] = " << src[i] << "is token. Skip if it is 1st in sequence. tokenCount : '" << tokenCount << "'" << endl;
					if (tokenCount <= 1)
					{
						cout << "First Token, RETAIN char" << endl; 
						cout << "src[" << i << "] = src[" << i << " - " << shiftCount << "]  " << endl;
						src[i - shiftCount] = src[i];
						cout << "Incr tokenCount: " << tokenCount << endl;
						cout << "shiftCount stays same at '" << shiftCount << "' since we RETAINED char" << endl;
					}
					else
					{
						cout << "non-First Token, SKIP char" << endl;
						shiftCount++;
						cout << "Incr tokenCount: " << tokenCount << endl;
						cout << "Incr shiftCount: " << shiftCount << endl;
					}
				}
				else
				{
					cout << "src[" << i << "] = " << src[i] << " is Non-Token. SHIFT & COPY char" << endl;
					cout << "Left-shift by '" << shiftCount << "' copy src[" << i << "] to src[" << i << " - " << shiftCount << "]" << endl;
					
					src[i - shiftCount] = src[i];
					
					tokenCount = 0;
					cout << "Reset tokenCount " << tokenCount << endl;
					cout << "shiftCount stays same at '" << shiftCount << "' since we RETAINED char" << endl;
				}
				cout << "   Out array " << src << endl;
				i++;
			}

			//This takes care of last one
			if (tokenCount > 1)
			{
				shiftCount += tokenCount - 1;
				src[i - shiftCount] = src[i];
			}

			//
			cout << "Compacted array " << srcIn.substr(0, i - shiftCount) << endl;
		}

	};
};
