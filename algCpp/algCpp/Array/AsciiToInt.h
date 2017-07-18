#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>

using namespace std;

namespace AsciiToIntNM
{
	class AsciiToInt
	{
	public:
		void callAsciiToInt()
		{
			string src("459");

			cout << "Convert string(" << src.c_str() << ") in to INT" << endl;

			const char* src1 = src.c_str();
			int i = src.length() - 1;
			int position = 0;
			int result = 0;
			while (i >= 0)
			{
				int tmp =  src1[i] - '0';
				cout << "src1[" << i << "] = " << src1[i] << " in INT is " << tmp << endl; 
				result += (tmp * pow(10, position));
				cout << "result is " << result << endl;
				i--;
				position++;
			}
		}

	};
};
