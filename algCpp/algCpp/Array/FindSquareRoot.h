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

namespace FindSquareRootNM
{
    /*
		
         Fib Recurse_20170719001
			In Fib series, first two values are hard coded as 0, 1, and subsequent values are generated by adding two previous values. For example: Value for 3rd position is sum of values for 1st and 2nd position. So value for 3rd position can be genetated by making two recursion calls (fib(0) and fib(1)), and adding their return values. We already know that fib(0) and Fib(1) will return hard coded value of 0, 1. We can use same recursion logic to compute the Fib value for other higher number. That To compute the recursion for position-5, make recursion call to fib(4) and fib(3), and add their return value and use it. Fib(4) will in turn call fib(3) and Fib(2), 
			Fib(3) will in turn call fib(2) and Fib(1).
			Fib(1) will not make any further recursion call and returns 1 to caller.
			At each layer of recursion, post-recursion code of caller, will add the return-values and returns higher layer. So to construct Fibvalue for position-4, recursion comes all the way to 1, 0; and on the way back, it adds up the number. So Fib call for any position will trigger a tree of recursion calls until 1st and 2nd position. We can use DP and eliminate redundancy. For example: both Fib(4) and F(10) will execute Fib(2). So we can use DP for memorizing Fib value for every position and reuse it. 

		Important things about Turn-logic is that
		a) Assume Src[Mid] happens to SQRT and verify that using  "Src[Mid] * Src[Mid] == Number"
			But SQRT may not be a round figure like 8 is for 64. 
		   So code should exit even if Src[Mid] * Src[Mid] is VERY close to "Number" within a buffer.
				   if (abs(M*M - src) <= precision)
					Found the SQRT.

		b) When making Turns, do not use "M-1" and "M+1", instead use M as it is(assign M directly to L or H). This assumes that there is boundary element.
			if (src < (M*M)) 
				H = M; //Left Turn.  Note that we do not do M+1
			else
				L = M; //Right Turn
					
			


		Find SQRT for '36' precision: '0.2
			L = '0' M = '18' H = '36'
			   {M*M '18*18 = '324'}  src = '36'
			   (36 < 342)
					Go Left {H = 18}
	   
			L = '0' M = '9' H = '18'
			   {M*M '9*9 = '81'}  src = '36'
			   (36 < 81)
					Go Left {H = 9}
			
			L = '0' M = '4.5' H = '9'
			   {M*M '4.5*4.5 = '20.25'}  src = '36'
   			   (36 > 20.25)
					Go Right {L = 4.5}

	   
			L = '4.5' M = '6.75' H = '9'
			   {M*M '6.75*6.75 = '45.5625'}  src = '36'
			   (36 < 45)
					Go Left {H = 6.75}
			
			L = '4.5' M = '5.625' H = '6.75'
			   {M*M '5.625*5.625 = '31.6406'}  src = '36'
			   (36 > 31)
					Go Right {L = 5.6}
			
			L = '5.625' M = '6.1875' H = '6.75'
			   {M*M '6.1875*6.1875 = '38.2852'}  src = '36'
			   (36 < 38)
					Go Left {H = 6.18}
			
			L = '5.625' M = '5.90625' H = '6.1875'
			   {M*M '5.90625*5.90625 = '34.8838'}  src = '36'
			   (36 < 34.8)
					Go Right {H = 5.9}
			
			L = '5.90625' M = '6.04688' H = '6.1875'
			   {M*M '6.04688*6.04688 = '36.5647'}  src = '36'
			   (36 < 36.56)
					Go Left {H = 6.04}
	   
			L = '5.90625' M = '5.97656' H = '6.04688'
			   {M*M '5.97656*5.97656 = '35.7193'}  src = '36'
			   (36 > 35.7)
					Go Right {L = 5.9}
			
			L = '5.97656' M = '6.01172' H = '6.04688'
			   {M*M '6.01172*6.01172 = '36.1408'}  src = '36'
			   (36 == 36.14) // Difference is within the precision buffer
			
			found the value 36.1408
			

	
	*/
    class FindSquareRoot
    {
        public:

			void callFindSquareRoot()
			{
				float src = 36;
				float precision = 0.2;
				cout << endl << "Find SQRT for '" << (float) src << "' precision: '" << (float)precision << endl;
				FindSquareRootX(36,00.2);
			}

		//pos - is the position in the FibSeries to which we want to generate the value 
        void FindSquareRootX(float src, float precision)
        {
			float L = 0;
			float H = src;


			while (L <= H)
			{

				float M = L + (H - L) / 2;
				cout << "L = '" << (float)L << "' M = '" << (float)M << "' H = '" << (float)H << "'" << endl;
				//M*M = 12*12 = 144    
				cout << "   {M*M '" << (float)M <<"*" << (float)M << " = '" << (float)M*M <<  "'}  src = '" << (float)src <<"'"  << endl;
				cout << "   abs(M*M - src)" << (float)abs(M*M - src) << "  precision: '" << (float)precision << "' " << endl;
				if (abs(M*M - src) <= precision)
				{
					cout << "found the value " << (float)M*M << endl;
					break;
				}
				else
				{
					//Note that DAC code will not do 'M+1' or 'M-1'
					if (src < (M*M))
					{
						H = M; //Note that we do not do M+1
						//cout << "   go left. L = '" << (float)L << "' H = '" << (float)H << "'" << endl;
					}
					else
					{
						L = M; 
						//cout << "   go right. L = '" << (float)L << "' H = '" << (float)H << "'" << endl;
						
					}
				}

			}
        }
    };
};