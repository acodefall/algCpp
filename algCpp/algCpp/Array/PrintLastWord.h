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
namespace PrintLastWordNM
{
	/*
		Extract last word from sentence. 
			Scan the sentense letter by letter. Note down the letter in string variable by appending.
			We have to reset the letter whenever the control goes from "space-to-letter" boundary.
			Coming to impl
			Iterate the array using for loop. Track the SPACE, and if so set a flag. If the letter is not SPACE, append
			it to outString. If the SPACE_FLAG is TRUE, then reset the outString because we are on "space-to-letter" boundary.


	*/
	class PrintLastWordX
	{
		public:
			void callPrintLastWord()
			{
				string s(" aaaa b123 ");
				char* sa = (char*)s.c_str();
				bool newword = false;
				string lastword;
				for (int i = 0; i < s.length(); i++)
				{
					if (sa[i] == ' ')
					{
						newword = true;
					}
					else
					{
						if (newword)
						{
							lastword = "";
							newword = false;
						}
						lastword += sa[i];
					}
				}
				cout << lastword;
			}
	};

};