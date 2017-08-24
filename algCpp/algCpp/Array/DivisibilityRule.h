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

namespace DivisibilityRuleNM  //@RED20170726003
{

	/*
		Detect whether number is divisible by 3
		This can be solved using 
		Divisibility 
	*/
	class DivisibilityRule
	{
	public:
		void callDivisibilityRule()
		{
			DivisionBy2(368);
			DivisionBy2(361);
			DivisionBy3(39);
			DivisionBy3(392);

				/*
					Last digit of '368' is '8' and is Divisible by 2
					Last digit of '361' is '1' and is NOT Divisible by 2
					
					39
						Divisibility3 for '39' sumAll is '12'
						3 is Divisible by 3

					392
						Divisibility3 for '392' sumAll is '14'
						3 is Not Divisible by 3
				*/


		}


		void DivisionBy2(int n)
		{
			int x = n;
			int base = 10;

			//extract the last digit of the number 
			if (n >= 10)
			{
				n %= 10;
			}
			

			// sumAll holds the sum of all the numbers, check whether the sumAll is divible by 3
			if (n % 2 == 0)
				cout << "Last digit of '"<< x <<"' is '"<< n << "' and is Divisible by 2" << endl;
			else
				cout << "Last digit of '" << x << "' is '" << n << "' and is NOT Divisible by 2" << endl;
		}

		//Add every digits of the number. If Sum of all the digits is divible by 3 then whole number is divible 3
		void DivisionBy3(int n)
		{
			int x = n;
			int sumAll = 0;
			int base = 10;

			//seperate the digits from number and add them.
			//sum gets stored in sumAll
			while (n >= 10)
			{
				int y = x;
				int mod = n % 10;
				n /= 10;
				sumAll += mod;
			}

			//Add the remaining digit to also 
			sumAll += n;
			cout << "Divisibility3 for '" << x << "' sumAll is '" << sumAll << "'" << endl;

			//sumAll holds the sum of all the numbers, check whether the sumAll is divible by 3
			if(sumAll % 3 == 0)
				cout << n << " is Divisible by 3" << endl;
			else
				cout << n << " is Not Divisible by 3" << endl;
		
		}
	};
};


//DivisibilityRule