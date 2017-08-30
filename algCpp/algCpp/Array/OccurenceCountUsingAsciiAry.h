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

namespace OccurenceCountUsingAsciiAryNM  //@RED20170030003
{
   
    /*
         Test if  a string is ENTAIRELY made up of the characters taken from other two source strings_RED20170030003
			There will be two src strings and one superset string; we have to check whether the superset string is entairely made up of chars taken from two source strings.
			Strategy is, compute the occurence count for both source strings and store them inside same 'occurence count Array'.
			Then go through the superset array, and decrement the occurence count in 'occurence count Array'.
			If the superset-ary is entairely made up of source arrays, then 'occurence count Array' should be full of 0s; if not superset string is not entairely made up of src arrays.
			So verify this condition by going through the 'occurence count Array'. 
			.

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
			//Basically srcHash[] should be full of 0s.
			i = 0;
			int notMade = 0;
			while (i < CHAR_MAX)
			{
				//If any slot has non-zero, then combString is NOT constructed using src1 and src2, 
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
