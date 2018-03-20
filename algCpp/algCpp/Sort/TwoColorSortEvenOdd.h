#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace TwoColorSortEvenOddNM
{
	/*
		
		TwoColorSortWithEvenOdd¬_20170528006
                        { 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0 };
							1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0
				Problem is, we are given an array containing 0, 1, and we have to adjust the array so that 0 comes at Odd-index and 1 comes at Even-index. This means we have to modify the array only if there is a "0 at even-index", and "1 at odd-index".

				This problem seems similar to 'TwoColorSort' problem but it is not. TwoColor problem is interested in just sorting 0s and 1s, irrespective of index polarity. Note that we can not use SELECTION method here.
 
				We want to solve this problem by modifying the src-array inplace. Inplace modification logic hinges on swapping "0 of even-index" with complimentary "1 of odd-index". But we may not succeed in getting complimentary misfit; in that case we will end up the partially SOLVED result.
				If [i] is a mis-fit, and then we look for 'complimentaory misfit' in the range of "[i+1] to MAX", using a while loop. If complimentory misfit is found we swap the misfits 
		
Steps for TwoColorSortWithEvenOdd_20170528008 
	a) start a ForLoop to go from 0 to end
	b) Inside the forloop check if 
	"1 is at even-index" and "0 is at odd-index", if so every thing is good, CONTINUE to next element. 
	If not, start an inner WhileLoop, go from [i+1] to end.
	Inside the inner while loop, first identify if the element is a misfit, and check if it compliments with the misfittess shown by outer-value and outer-index. If misfitness compliments, set a flag called FOUND, and break the while-loop;
	Otherwise continue to look for suitable complimentary misfit further deeper in src-array, till the MAX index.

	Once out of inner While loop exits, if the FOUND is TRUE, swap the misfits located at index "i" and 'j"

	*/
	class TwoColorSortEvenOdd
	{
		public:
			//Place 1 in EVEN 
			// 0 in ODD
			void callTwoColorSortEvenOdd()
			{
				int data[12] = { 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0 };
				int len = 12;


				std::cout << "Before swap" << "\r\n";
				for (int i = 0; i < len; i++)
				{
					std::cout << data[i] << " ";
				}
				//TwoColorSortEvenOddX(data, len);

				TwoColorSortEvenOddX1(data, len);
				std::cout << "\r\nAfter swap" << "\r\n";
				for (int i = 0; i < len; i++)
				{
					std::cout << data[i] << " ";
				}

				//1 0 1 0 1 0 1 0 1 0 0 0
			}

			void TwoColorSortEvenOddX(int* data, int Len)
			{
				
				for (int i = 0; i < Len; i++)
				{
					if ((i % 2 == 0 && data[i] == 1) || (i % 2 == 1 && data[i] == 0) && (i < Len))
					{
						continue;
					}
					int j = i + 1;
					bool found = false;
					while (j < Len)
					{
						if (i % 2 == 0 && data[i] == 0) //0 at even position, look for 1 in odd position to replace 0
						{
							if (j % 2 == 1 && data[j] == 1)
							{
								found = true;
								break;
							}
						}
						else
						{
							if (i % 2 == 1 && data[i] == 1) //1 at ODD position, look for 0 in EVEN position to replace 1
							{
								if (j % 2 == 0 && data[j] == 0)
								{
									found = true;
									break;
								}
							}
						}
						j++;
					}

					if (found)
					{
						int t = data[i];
						data[i] = data[j];
						data[j] = t;
					}
				}
			}
			
			void TwoColorSortEvenOddX1(int* data, int Len)
			{

				int prevEven = -1; //index of "EVEN number located at Odd-Index" avialable for swap
				int prevOdd = -1; //index of "ODD number located at Even-Index" avialable for swap

				for (int i = 0; i < Len; i++)
				{
					if (i % 2 == 0)
					{
						if (data[i] % 2 == 0) //Value is Even, look for Even value for exchange
						{
							if ((prevEven != -1) && (prevEven < i))
							{
								swap((data[i]), (data[prevEven]));
								prevEven = -1;
							}
						}
						else
						{	//Odd-Value at Even-Index. This is candidate for Exchange at future time, so preserve the index in prevEven
							if (prevEven == -1)
								prevEven = i;
						}
					}
					else
					{
						if (data[i] % 2 > 0)
						{
							if ((prevOdd != -1) && (prevOdd < i))
							{
								swap(data[i], data[prevOdd]);
								prevOdd = -1;
							}
						}
						else
						{	//Even-Value at Odd-Index. This is candidate for Exchange at future time, so preserve the index in prevOdd
							if (prevOdd == -1)
								prevOdd = i;
						}
					}
				}
			}
	};
};