#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
namespace ColoringHomeUsingCombinationNM
{
	/*
						R (1)       R (4)         R (6)			Sum = 11
						R (1)       R (4)         G (4)			Sum = 9
						R (1)       R (4)         B (2)			Sum = 7
						R (1)       G (100)       R (6)			Sum = 107
						R (1)       G (100)       G (4)			Sum = 105
						R (1)       G (100)       B (2)			Sum = 103
						R (1)       B (100)       R (6)			Sum = 107
						R (1)       B (100)       G (4)			Sum = 105
						R (1)       B (100)       B (2)			Sum = 103
						G (3)       R (4)         R (6)			Sum = 13
						G (3)       R (4)         G (4)			Sum = 11
						G (3)       R (4)         B (2)			Sum = 9
						G (3)       G (100)       R (6)			Sum = 109
						G (3)       G (100)       G (4)			Sum = 107
						G (3)       G (100)       B (2)			Sum = 105
						G (3)       B (100)       R (6)			Sum = 109
						G (3)       B (100)       G (4)			Sum = 107
						G (3)       B (100)       B (2)			Sum = 105
						B (2)       R (4)         R (6)			Sum = 12
						B (2)       R (4)         G (4)			Sum = 10
						B (2)       R (4)         B (2)			Sum = 8
						B (2)       G (100)       R (6)			Sum = 108
						B (2)       G (100)       G (4)			Sum = 106
						B (2)       G (100)       B (2)			Sum = 104
						B (2)       B (100)       R (6)			Sum = 108
						B (2)       B (100)       G (4)			Sum = 106
						B (2)       B (100)       B (2)			Sum = 104

	*/
	class ColoringHomeUsingCombination
	{
		public:
			int cost;

				void callColoringHomeUsingCombination()
				{

					cost = 0;
					const int MaxColors = 3;
					const int MaxHomes = 3;

					int costOfRed[MaxHomes] = { 1,4,6 };	//cost of painting in R for 1st,2nd and 3rd home
					int costOfBlue[MaxHomes] = { 2,100,2 }; //cost of painting in B for 1st,2nd and 3rd home
					int costOfGreen[MaxHomes] = { 3,100,4 }; //cost of painting in G for 1st,2nd and 3rd home

					//Number of permutaions = "number of times a color can be attempted" = "number of homes"
					//We have 2 colors(R, B) and 3 homes then we need combinations like this  
					//R R R => values will come from  costOfRed[0] costOfRed[1] costOfRed[2]
					//B B B => values will come from  costOfBlue[0] costOfBlue[1] costOfBlue[2]
					//.......
					//So the width of permutationArray should be equal to 'Number of homes'
					int availableColors[MaxColors] = {'R', 'G', 'B'};
					int permArray[MaxHomes] = {0};
					colorHome(availableColors, MaxColors, permArray, MaxHomes, 0, costOfRed, costOfBlue, costOfGreen);
					//int colorCodes[MaxHomes] =   

				}

				//data has colorCodes
				void colorHome(int* Colors, int colrCount, int* permutationArray,  int combLen,int Idx, int* clrR, int* clrB, int* clrG)
				{
					//This controls the width of combination
					if (Idx == combLen)
					{
						{
							int tempcost = 0;
							stringstream ss;
							for (int i = 0; i < combLen; i++)
							{
								char code = (char)(permutationArray[i]);
								ss << (char)(permutationArray[i]);
								ss << " ";

								if (code == 'R')
								{
									ss << "(";
									ss << clrR[i];
									ss << ")";
									tempcost += clrR[i];
								}
								else if (code == 'B')
								{
									ss << "(";
									ss << clrB[i];
									ss << ")";
									tempcost += clrB[i];
								}
								else if (code == 'G')
								{
									ss << "(";
									ss << clrG[i];
									ss << ")";
									tempcost += clrG[i];
								}
								ss << " ";
							}
							ss << " Sum = ";
							ss << tempcost;
							ss << "\r\n";
							cout << ss.str();
						}
						return;
					}
					
					//Generate the permutataions of "R, G, B" with duplicates
					////R R R 			
					//This inner loop does not control the length of the combination, instead it ONLY controls how many different values can go in to  a specific position in out-array.
					//Length of the combination is controlled by width of out-array. Ex; We can have output array of width 10, and number of characters to fill is only 2. In that case, 
					//there will be many duplicates.
					//This inner loop is only responsible for filling ANY to 'permutationArray[Idx]'. 
					/*
						permutationArray[Idx]  = R
						permutationArray[Idx]  = G
						permutationArray[Idx]  = B
					*/
					for (int k = 0; k < colrCount; k++)
					{
						permutationArray[Idx] = Colors[k];
						colorHome(Colors, colrCount, permutationArray, combLen, Idx + 1, clrR, clrB, clrG);
					}
					
				}
	};
};

