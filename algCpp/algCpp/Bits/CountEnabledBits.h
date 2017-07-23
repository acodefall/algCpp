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

namespace  CountEnabledBitsNM
{
	class CountEnabledBits
	{
	public:
		void callCountEnabledBits()
		{
			int src = 0x45; //  0100 0101 
			int cnt = 0;
			while (src > 0)
			{
				int forlog = src & (src - 1);
				cout << hex << "src = '" << src <<"' (src - 1) = '" << src - 1 << "'     src & (src - 1) = " << forlog << endl;
				src = src & (src - 1);
				cnt++;
			}

			cout << "Bits in " << hex << src << " " << cnt << endl;
		}

	};
};