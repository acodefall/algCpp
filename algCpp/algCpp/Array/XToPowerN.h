#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace XToPowerNNM
{
	/*
       Compute power of P using DAC_20170711007
		We can compute 2 ^ 8 using DAC. There will be LogN levels, and at each level we make only recursion call.
		But double the return value of recursion-call before sending it to caller, as if we made two recursion calls.
		For example: For computing “2 ^ 8”, we can say “2^4” * 2

		At every level of DAC, power gets divided by 2 but base stays the same. Ex: 8->4->2->1
		At some point power reduces to either 0 or 1, then Recursion breaks.
		If power is 0, return the 1(because base^0 = 1)
		If power is 1, return the base(because base^1 = base)
		If power is ODD that needs special handling. Multiply the result of recursion with base.
			Return = ReturnOfRecursion * ReturnOfRecursion * BaseValue
		Say base = 5, power = 3, and we send 3/2 for recursion call.
		Recursion returns value for 5 ^ 1, and doubling of return value gives 5 * 5, but we need 5 * 5 * 5; so we multiply with base

			
						 b=3 p=6  //return 27 * 27 
							/
					       / 
					     3,3       //return (3 * 3) * 3 = 27
						  \
						   \
						   3,1     //return 3
			
	
        Steps for computing X ^ p GN151
	        a) Rec func takes X and P as input.
	        b) if (P = 0) return 1;
	           else if (P = 1) return X;
	           else if (P % 2 = 0)  //P is EVEN
			        Make rc-func call with X, P/2 as parameter, and capture the output in res.
			        return Res * Res;
	           else 
	                Make rc-func call with X, P/2 as parameter, and capture the output in res.
			        return Res * Res *  X;

     */
	class XToPowerN	
	{
		public:
			void callXToPowerN()
			{
				int base = 3;
				int power = 6;
				int out = XToPowerNx(base,power);
				cout << base << " ^ " << power << " = " << out;
				
			}

		private:
			int XToPowerNx(int base, int power)
			{
				if(power == 0)
				{
					cout << "return 1" << endl; 
					return 1;
				}
				else if (power == 1)
				{
					cout << "return " << base << endl;
					return base;
				}
				else
				{
					
					/*	
						  b=3 p=6  //return 27 * 27 
							/
					       / 
					     3,3       //return (3 * 3) * 3 = 27
						  \
						   \
						   3,1     //return 3
						 
					*/
					//make only one recursion call, and double that before RETURNING
					if(power % 2 == 0)
					{
						int half = XToPowerNx(base, power/2);
						cout << "return (" << half << " * " << half << ") = " << (half * half) << endl;
						return half * half;
					}
					else
					{
						int half = XToPowerNx(base, power/2);
						cout << "return (" << half << " * " << half << ") * " << base << " = " << (half * half * base) << endl;
						return half * half * base;
					}
				}
			}
	};
};