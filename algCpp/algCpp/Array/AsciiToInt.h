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
	/*
		Input {"234"}
		Output
			Sum += 4 * (10 ^ 0);
			Sum += 3 * (10 ^ 1);
			Sum += 2 * (10 ^ 2);
	*/
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
			
			//Assume the BASE is 10 because output number is in DECIMAL
			while (i >= 0)
			{
				int tmp =  src1[i] - '0'; //Difference between two CHARs is INT, that is how we convert '4' to 4; 
										  //'4' - '0' = 4
				cout << "src1[" << i << "] = " << src1[i] << " in INT is " << tmp << endl; 
				result += (tmp * pow(10, position));
				cout << "result is " << result << endl;
				i--;
				position++;
			}
		}

	};
};
