#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
using namespace std;



/*
		Coin Change Problem Create Sum using Minnimum coins DP
			We have to create sum using least number of coins(this means use higher denomination coins).
			For example: 4 = 2+2 and 4 = 1+1+1+1. 
			Problem should return the length of 2+2 that is 2.
			
			Solution matrix is bulit using array. 
			Every Cell value gives the  Number of coins for creating that particular SUM; make sure this CELL value is SMALL.
			For example: Say if we use current-row's coin we need 4 coins, and upper-row's coin needs just 2 coins, then 
			import the value from upper row.


			Rules are as follows
			Compare the coin-value against cell-value, based on the out come of comparison fill the cell value..
			1)  If the COIN is BIGGER than COLUMN-VALUE(column value. Ex: coin is 5 cent and column is 2), 
				We can not use current-coin, simply import the value from UPPER row.
				(if we are implementing the Solution matrix using array, do not change the existing value,
				 leave the existing value as it is)
			
			2) If the COIN and COLUMN-VALUE are same, we want to use current coin, so write 1 to cell. Since the count being written is 1, it is already smallest, so we do not compare against upper row.
			
			3) If the coin-value is SMALLER than the column-capacity, we can fill the cell using either current-row's coin 
			or upper-row's coin. We use the coin which that requires FEW numbers. 
		    Compute the number of coins using current coin. Take one instance of current-coin. Since the 
			column capacity is higher, there will be still some space. To fill the excess capacity, 
			use the history-value stored in same row. Add these two numbers. Now we have the coin-count using current
			coin. Compare it against the value stored in upper row and select which ever is lower, and write to CELL.

			In the end Matrix will give lower-number of coins for any taregt-sum.
			   
			When filling for TOP row, we have to be care full, because that is the 1st coin to be used, there is no previous coin.
			So do no try to compare against previous row, instead use the current row's coin.
			
				Coming to implementation:
					We do not use Matrix, instead we use just array. This is because DP code needs just one historic row.
					We use array and initially array will have values for 1st-row.
					When constructing the 2nd row, we either keep the array-value as it is;
					OR add new value to it. This same as IMPORTING and ADDING respectively.
					ex: To get the cumulative combs, to know the combs for 2-cent, we add the value to exitsing array-value.

					Array length has to be 1 byte extra. And INIT the [0] with 1.
			*/
namespace CoinChangeMakingMinimumWaysNM //@RED20170818001
{
	const int LEN = 4;
	const int TRGSUM = 11;

	class CoinChangeMakingMinimumWays
	{
		public:
			void useCoinChangeMaking()
			{
				//This is based on permutations
				int src4[LEN] = { 1, 5, 6, 9 };
				
				CoinChangeMakingMinimumWaysDP(src4);
				/*
					coins = {9, 6, 5, 1}, Sum = 11


							0 1 2 3 4 5 6 7 8 9 10  11  ------> Target Value
					1c  	  1 2 3 4 5 6 7 8 9 10  11  
					5         1 2 3 4 1 2 3 4 5 2   3   ------> Cell value shows number of COINS(not combs).
					6         1 2 3 4 1 1 2 3 4 2   2
					9         1 2 3 4 1 1 2 3 1 2   2
					Sol[] {1, 1, 2, 3, 4, 1, 1, 2, 3, 1, 2, 2}
					    
				*/
			}

		
			
			//
			
			void CoinChangeMakingMinimumWaysDP(int coin[LEN])
			{
				int sol[TRGSUM +1] = { 0 };
				for (int r = 0; r < LEN; r++)
				{
					cout << coin[r] << endl;
				}
				sol[0] = 1;
				
				//introduce one coin at a time
				for (int r = 0; r < LEN; r++)
				{
					for (int c = 1; c <= TRGSUM; c++)
					{	
						//Always import combinations that can be created using lower coin, and this will be in top row, import it.
						//if the COIN is BIGGER than SOUGHT-VALUE(column value), 
						//then we can not use current-coin. Import the number of combs from lower coin stored in top row.
						if (coin[r] == c) //COIN fits the COLUMN, so use 1stance of current-coin. We are using one instance of current coin. 
							sol[c] = 1;   //Count-1 is already SMALLEST, so there is point in comparing against previous coin store in upper row. 
						else if (coin[r] > c) //COIN is too BIG to fit, try to use previous coin. (means import the value from upper row.) 
							sol[c] = sol[c]; //simulate as if importing from top row
						else if (c >= coin[r])
						{
							if (r == 0)
							{	//This is 1st row, there is only one coin, so no need to check upper-row.
								sol[c] = 1 + sol[c - coin[r]];
							}
							else
							{
								//COIN is SMALLER
								//Say coin is 5 and column is 7
								//current coin will provide '5', and there is still '2' remaining. 
								//To fill the '2', take the value from sol[2]
								//Cell = 1 + sol[2]
								sol[c] = min(sol[c], 1 + sol[c - coin[r]]);
							}
						}
					}
				}
			}
	};
};

