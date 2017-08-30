#pragma once
//AsciiHashing

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

namespace OccurenceCountUsingAsciiAryNM  //@RED20170726003
{
   
    /*
         
    */
    class OccurenceCountUsingAsciiAry
    {
        public:
		void callOccurenceCountAscii()
        {
			string src1("aabcc");
			string src2("dbbca");
			string combString("aadbbcbcac");
            int x = OccurenceCountAsciiX(src1,src2,combString);

           
        }

		
        int OccurenceCountAsciiX(string src1, string src2, string combString)
        {
            int res = 0;
			int srcHash[CHAR_MAX] = { 0 }; //Two of the source strings(src1 & src2) will store their HASH here 
			const char* src1const = src1.c_str();
			const char* src2const = src2.c_str();
			const char* combStringconst = combString.c_str();
			int i = 0;
			
		

		
			//compute occurence count src1 by incrementing count.
			while (i < src1.length() )
			{
				
				srcHash[(int)src1const[i]]++;
				cout << (char)src1const[i] <<
				i++;
			}

			//compute occurence count for src2 by incrementing count.
			i = 0;
			while (i < src2.length())
			{
				
				srcHash[(int)src2const[i]]++;
				i++;
			}


			//Decrement occurence count for characters of combString.
			i = 0;
			while (i < combString.length())
			{
				
				srcHash[(int)combStringconst[i]]--;
				i++;
			}

			//If the combString is constructed using src1 and src2, then occurence count of every character should become 0
			//Basically there won't be any letter who's occurence count is > 0.
			i = 0;
			int notMade = 0;
			while (i < CHAR_MAX)
			{
				//We initialized the array to 0, so the remaining value in ary[] should be either '0'
				//Any other value will indicate that combstring is NOT entairely made up of src1 ad src2
				if (srcHash[i] != 0)
				{
					notMade = 1;
					break;
				}
				i++;
			}

			if(notMade == 0)
				cout << endl << "combString('" << combString.c_str() << "') is entairely made up of src1 ('" << src1.c_str() << "') and src2 ('" << src2.c_str() << "')";
			else
				cout << endl << "combString('" << combString.c_str() << "') is not entairely made up of src1 ('" << src1.c_str() << "') and src2 ('" << src2.c_str() << "')";

            return res;
        }
    };
};
