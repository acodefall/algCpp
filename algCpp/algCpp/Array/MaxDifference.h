#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
namespace MaxDifferenceNM
{
	/*
	
		 Price variation of a stock is given in a array, and we should tell selling on which day gives maximum yield.
        [0], [1], [2] have 1st day, 2nd day and 3rd day price. We can not buy and sell on same day.
        For example: Diff "3rd day price with 2nd day", then "3rd day price with 1st day", then select the difference that is higher.
        Solution is: take src[i] and diff it against the elements that are on right-side. Then track the max difference, and use that as final result.
 
		
	                                Ex:  Day:-    0   1    2   3   4
		                                 Price:-  10  11   7   10  6
		                               
												  [0] [1]  [-4]
									We have to compute difference between following items	  
											
											[0] - [1] = 10 - 11 = -1  //-2147483648 -> -1
											[0] - [2] = 10 - 7 = 3	//-1 -> 3
											[0] - [3] = 10 - 10 = 0	//3 -> 3
											[0] - [4] = 10 - 6 = 4 //3 -> 4
										
															[1] - [2] = 11 - 7 = 4 //4 -> 4
															[1] - [3] = 11 - 10 = 1 //4 -> 4
															[1] - [4] = 11 - 6 = 5 //4 -> 5
											
																	[2] - [3] = 7 - 10 = -3 //5 -> 5
																	[2] - [4] = 7 - 6 = 1  //5 -> 5
																				[3] - [4] = 10 - 6 = 4  //5 -> 5
											

											MaxDiff is 5
	
	*/
	const int SIZEX = 5;
	class MaxDifference
	{

		public:
				void callMaxDifference()
				{
					int src[SIZEX] = { 10,  11,   7,   10,  6 };
					MaxDifferenceX(src);
				}
				void MaxDifferenceX(int src[SIZEX])
				{
					int MaxDiff = INT_MIN;
					for (int i = 0; i < SIZEX; i++)
					{
						for (int j = i+1; j < SIZEX; j++)
						{
							cout << MaxDiff << endl;
							cout << "[" << i << "]" << " - " << "[" << j << "] = " << src[i] << " - " << src[j] << " = " << src[i] - src[j] << endl;
							if ((src[i] - src[j]) > MaxDiff)
							{
								MaxDiff = src[i] - src[j];
							}
							cout << MaxDiff << endl << endl;
						}
					}
					cout << "MaxDiff is "<< MaxDiff << endl;
				}
	};

};
