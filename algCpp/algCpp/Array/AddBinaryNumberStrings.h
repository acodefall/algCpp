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
namespace AddBinaryNumberStringsNM
{
	class AddBinaryNumberStringsX
	{
		public:
			void callAddBinaryNumberStrings()
			{
				int carryOver = 0;
				cout << "add 11 + 01" << endl;
				AddBinaryNumberStrings((char*)"11", (char*)"01", &carryOver, 0, 2);
				cout << carryOver << endl; //100 == 001
			}
			
			void AddBinaryNumberStrings(char* s1, char* s2, int* carryover, int idx, int len)
			{
				//base condition
				if (idx == len)
				{
					return;
				}
				AddBinaryNumberStrings(s1, s2, carryover, idx+1, len);

				//Add the numbers
				int sum = ((s1[idx] - '0') + (s2[idx] - '0') + (*carryover));
				cout << (sum % 2);
				*carryover = sum / 2;
			}
	};
};