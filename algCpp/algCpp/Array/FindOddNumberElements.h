#pragma once
#include <iostream>
using namespace std;

namespace FindOddNumberElementsNM //@RED20170909015
{
	/*  RED20170909015
		Find a Number occurring odd number of times
			Use XOR for finding out the odd element. XORing a number with itself results in zero. So if a number repeats 
			even number of times, then XORing all of them will give zero output. If the number appears ODD number of times,
			then we will be left with number itself.

			So the solution is, XOR "[i] with [i+1]", do this whole array. Final output will be the element that repeats ODD number of times.

			This strategy will not work if multiple number repeat ODD number of times.

            Array will have {1,1,2,2,2}. Here 2 appear 3 times, and we have to find out 2.
	            x = "1 ^ 1" = 0 
	            x = "x ^ 2" = "0 ^ 2" = 2
	            x = "x ^ 2" = "2 ^ 2" = 0
                        x = "x ^ 2" = "0 ^ 2" = 2  ---> return code
	
	            Steps:
		            Declare variable called Result = Src[0]
		            Start a forLoop from i=1 to i < Src.Len
		            Do 
			            Result = Result ^ Src[i];
	*/
	const int SIZEX = 9;
	class FindOddNumberElements
	{
		public:

				void callFindOddNumberElements()
				{
					int Src[SIZEX] = { 1, 1, 2, 2, 4, 4, 4, 5, 5 };
					int Result = Src[0];


					for (int i = 1; i < SIZEX; i++)
					{
						Result = Result ^ Src[i];
					}
					
					cout << Result << " repeats ODD number of times"; //4
				}

	};
};