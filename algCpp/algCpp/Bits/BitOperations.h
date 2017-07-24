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
#include <bitset>
using namespace std;

namespace  BitOperationsNM
{
	////
	/*

	*/


	class BitOperations
	{
		public:
				void callBitOperations()
				{
					//fastest way to make all bit 1 is inverse 0

					int v = 0;
					cout << " v      :'" << bitset<10>(v) << "'" << endl;
					cout << " v(inv) :'" << bitset<10>(~v) << "'" << endl;
				}
	};
};

