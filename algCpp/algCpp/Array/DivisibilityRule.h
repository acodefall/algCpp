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

namespace DivisibilityRuleNM  //@RED20170825013 @RED20170825014
{


	/*
		Divisibily rule_RED20170825013 
			Divisibily rule will help to detect whether a number is divisible by 2 or 3 or 4 or 5 
			without actually dividing the whole number. 
			For example: Number is divisible by 2 if the last digit is divisible by 2.
			Number is divisible by 3 if sum of all digits is divisible by 3.
			Number is divisible by 4 if last two digits are divisible by 4.
			Number is divisible by 5 if last digit is either 5 o 0.
			These techiques help us determine whether stream of number is divisible by some number.
			For example: To know whther a stream of numbers is divisible by 3,
			maintain a sum of all of the numbers. If the sum is divisible by 3, then 
			the whole stream is divisible by 3. Use DIV and MOD for extracting digits from a number.
			For divisibility-2 checking, we need only last digit so apply MOD on whole number, nothing more is needed.
			For divisibility-3 checking, we need every digit, so apply MOD & DIV in a loop; MOD will pluck the last digit and DIV will shrink the number and brings “last-but-1-number” to last position so it can be plucked by applying MOD.


		MOD for extracting last digit of a number
		MOD will extract the last digit of a number. 198 % 10  will give 8. 
		MOD can ONLY eject the last digit. If we want to pluck the digit that is at the middle of the number,
		bring that digit to last position by dividing the number with 10.
		
		If we want to pluck every digit of a number, apply MOD and DIV until the result of DIV drops below 10(or base)
		This MOD and DIV loop is used to detect whether a number is divisible 3. In this case we have to extract
		every digit and add them togather,
		
		int src;
		while (src > 10)
		{
			int lastDigit = src % 10; //MOD to extract lastDigit

			src = src/10; //bring the 'last but-one digit' to end so that we can pluck that by doing MOD
		}


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
			int base = 10;
			int lastDigit = n;
			//extract the last digit of the number 
			if (n >= 10)
			{
				lastDigit = n % 10;
			}
			

			// sumAll holds the sum of all the numbers, check whether the sumAll is divible by 3
			if (n % 2 == 0)
				cout << "Last digit of '"<< n <<"' is '"<< lastDigit << "' and is Divisible by 2" << endl;
			else
				cout << "Last digit of '" << n << "' is '" << lastDigit << "' and is NOT Divisible by 2" << endl;
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
				int lastDigit = n % 10; //plucks the last digit
				n /= 10; //shrinks the number, and brings the last-but-1 digit to last position so that it can be plicked by applying MOD.
				sumAll += lastDigit;
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