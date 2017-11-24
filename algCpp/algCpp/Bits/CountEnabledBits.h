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

namespace  CountEnabledBitsNM //@RED20170725058
{
	/*
			There are two ways to do this.
				-In a loop, AND X with (X-1), assign the result to X itself. 
				-Loop should continue as long as X is NOT Zero.
				-Keep track of loop count, that gives the number of enabled bits.
				
			Second method is.
				-In a loop, right-shift the X by 1 position. 
				-Loop should continue as long as X is NOT Zero.
				 Right-shift will force the bits to leave from RIGHT-end. 
				 So by monitoring the MSB we can count how many 1s are there.
				-Inside the while loop check is right-most bit is 1, if so then increament the counter.
				
	*/
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