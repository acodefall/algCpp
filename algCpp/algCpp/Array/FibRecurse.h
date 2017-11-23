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

namespace FibRecurseNM
{
    /*
		Fib Recurse
		In Fib series, first two elements are hard coded
		3rd element gets computed by adding 1st and 2nd elements.
		4th element gets computed by adding 3rd and 2nd elements.
		So if we want to generate 4th element, go to the beginning of the array and add the 1st and 2nd element and generate
		3rd element, once the 3rd element is ready; add 2nd and 3rd element and generate 4th element.
		Similarly for generating the 4th element, we again start adding from 1st element.
		This logic can be implemented using recursion. at every level recursion we need two previous
		elements, so create them, we make two recursion call and add their return value.
		Recursion goes all the way down; and makes U-turn when sought-index is either 1 or 0.
		Those recursion calls return what ever is element-1 or element-0.
		This is the only time that recursion returns a genuine value to caller. At every other level,
		post-recursion code adds the return values of recursion calls and returns the sum to caller.
		Basically Pre-recursion has no code; post-recursion simply sums the return values of recursion calls;
		post-recursion at base-case level returns genuine return values.

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
    class FibRecurse
    {
        public:

			void callFibRecursee()
			{
				int fibLen = 7;
				//i=4 computes the fib number for only pos-4
				//i=5 computes the fib number for only pos-5
				for (int i = 0; i < fibLen; i++ )
				{
					int ret = FibRecurseX(i);
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
        int FibRecurseX(int pos)
        {
		   if ((pos == 0) || (pos == 1)) //base condition. Only two genuine returns values (0 & 1);
			{
				//cout << "end" << endl;
                return pos;
			}
			if (pos < 0)
				return 0;
			//If the input value is higher than 1, then we we make two more recursion calls and add their return values and send it to caller.
			int x = FibRecurseX(pos - 1);
			//cout << "x :" << x << " ";
			
			int y = FibRecurseX(pos - 2);
			//cout << "y :" << y << " ";
            return  x + y;
        }
    };
};
