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

namespace DivisionNM  //@RED20170726003
{
   
    /*
         Division_GN88
             Division can be done by subtracting DEN from MUM, un till the result is less than DEN. Also take care of boundary conditions.
				
             Step:
             Function takes N and D as parameter
             If D is 1 return N as it is
             If D is 0 return -1
             Else start a while loop.
             Inside the while, subtract N with D and result to N.
             Increment the divisor-counter. Do this before IF condition.
                     If N < D, then break the loop. 
             And return divisor-counter to caller
    */
    class Division
    {
        public:
		void callDivision()
        {
            int x = DivisionX(3,1);

            x = DivisionX(13, 2);

            x = DivisionX(12, 2);

            x = DivisionX(12, 3);
        }

        int DivisionX(int n, int d)
        {
            int res = 0;

            if (d == 1)
                res = n;
            else if (d == 0)
                res = -1;
            else
            {
                while (true)
                {
                    n = n - d;
                    res++;
                    if (n < d)
                    {
                        break;
                    }
                }
            }

            return res;
        }
    };
};
