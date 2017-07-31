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

namespace FindNonDuplicateNumberNM //@RED20170719004
{
    /*
		 Find the non repeating number_@RED20170719004
	            This is to find the number that does not repeat.
				Strategy is that when we XOR same number number with itself, result will be 0.
				If you do this on whole array, repeating numbers will cancel out and in the end we will be left with the element that does not repeat.
				Note that array does not have to be sorted for this to work.
		
				Output:
						0  ^ 3 = 3
						3  ^ 5 = 6
						6  ^ 4 = 2
						2  ^ 5 = 7
						7  ^ 3 = 4
						4  ^ 4 = 0
						0  ^ 9 = 9
	
	*/
    class FindNonDuplicateNumber
    {
        public:

			void callFindNonDuplicateNumber()
			{
				const int SIZEX = 7;
				int src[SIZEX] = { 3, 5, 4, 5, 3, 4, 9 }; //Return 9
													 //int[] src = { 3, 5, 4, 5, 3, 4, 9, 3 }; //Returns 10. In correct because 3 repeats ODD number of times
				int res = 0;
				for(int i = 0; i < SIZEX; i++)
				{
					cout << res << "  ^ " << src[i] << " = " << (res ^ src[i]) << endl;
					res ^= src[i];
				}
			}

		
    };
};