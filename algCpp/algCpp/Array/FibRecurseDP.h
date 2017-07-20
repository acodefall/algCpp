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

namespace FibRecurseDPNM
{
    /*
		Fib Recurse
		In Fib series, values for first two positions are hard coded as 0, 1, and values for subsequent positions are generated by adding two previous fib values. For example: Value for 3rd position is sum of values for 1st and 2nd position. So value for 3rd position can be genetated by making two recursion calls (fib(0) and fib(1)), and then adding their return values. We already know that fib(0) and Fib(1) will return hard coded value of 0, 1. Base condition for recursion is returning 0 and 1 when input is 0 and 1. If the input value is higher than 1, then we we make two more recursion calls and add their return values and send it to caller. So important work is being at POST-recursion stage, that is where we sum up the return values of recursion calls, and return it to caller.
			fib(d=2)  //Generate Fib value for  3rd position
				if(d=1 or 0)	//base condition. Only two genuine returns values (0 & 1);
					return d;
				x = fib(1);  //fib for 2nd pos
				y = fib(0)   //fib for 1st pos
		
				return x+y; //add fib for 1st and 2nd pos and use it as fib for 3rd pos (POST-Recursion stage work)

		Fib(2) = Fib(0) + Fib(1)
		Similarly fib-value for every any position can be generated recursively.
		Example: Fib(4) = Fib(3) + fib(2).

		Fib call for any position will trigger a tree of recursion calls until 1st and 2nd position. For example: both Fib(4) and F(10) will execute Fib(2). So we can use DP for memorizing Fib value for every position and reuse it. 
		

		For generating fib value for position-5
			fib(5)=5  ==>
			{
				fib(4)=3
					fib(3)=2 
						fib(2)=1
							fib(1)= 1
							fib(0)= 0
						fib(1)=1
					fib(2)=1
						fib(1)=1
						fib(0)=0
				fib(3)=2
					fib(2)=1
						fib(1)=1
						fib(0)=0
					fib(1)=1	
			
			}
			i=5 will trigger two recursions i=4, i=3.
			i=4 will trigger two recursions i=3, i=2
			i=3 will trigger two recursions i=2, i=1
			i=2 will trigger two recursions i=1, i=0
				i=1 and i=0 will not triggers any more recursions.
			

	
	*/
    class FibRecurseDP
    {
        public:

			void callFibRecursee()
			{
				int fibLen = 7;
				int FibvalueMemory[7] = { 0 };

				for (int i = 0; i < fibLen; i++)
				{
					FibvalueMemory[i] = -1;
				}
				//i=4 computes the fib number for only pos-4
				//i=5 computes the fib number for only pos-5
				for (int i = 0; i < fibLen; i++ )
				{
					int ret = FibRecurseXDP(i, FibvalueMemory);
					cout << " Fib counter for position '" << i << "' ret = '" << ret << "'" << endl;
				}
				/*
					 i = '0' ret = '0'
					 i = '1' ret = '1'
					 i = '2' ret = '1'
					 i = '3' ret = '2'
					 i = '4' ret = '3'
					 i = '5' ret = '5'
					 i = '6' ret = '8'
					Final Fb of length 7 has = {0,1,1,2,3,5,8}	
												
				*/
			}

		//pos - is the position in the FibSeries to which we want to generate the value 
        int FibRecurseXDP(int pos, int* FibvalueMemory)
        {
		   if ((pos == 0) || (pos == 1)) //base condition. Only two genuine returns values (0 & 1);
			{
				//cout << "end" << endl;
                return pos;
			}
			if (pos < 0)
				return 0;
			int value = 0;
			if (FibvalueMemory[pos] == -1)
			{
				//If the input value is higher than 1, then we we make two more recursion calls and add their return values and send it to caller.
				int x = FibRecurseXDP(pos - 1, FibvalueMemory);
				//cout << "x :" << x << " ";

				int y = FibRecurseXDP(pos - 2, FibvalueMemory);
				//cout << "y :" << y << " ";
				value = x + y;
				FibvalueMemory[pos] = value;
			}
			else
			{
				value = FibvalueMemory[pos];
			}
            return  value;
        }
    };
};