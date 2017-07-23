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

namespace IntToAsciiNM
{
	class IntToAscii
	{
	public:
		void callIntToAscii()
		{
			int src = 4592;
			char map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
			int base = 10;
			char out[5] = { ' ', ' ', ' ', ' ','\0' };
			int outIdx = 0;

			cout << "Convert INT(" << src << ") in to STRING" << endl;

		
			while (src > base)
			{
				out[outIdx] = map[src % base];
				src = src / base;
				outIdx++;
			}
			out[outIdx] = map[src];
		}

	};
};