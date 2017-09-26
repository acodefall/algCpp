#pragma once
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;
namespace KnapsackUsingDPNM
{
	/*
	
	Knapsack problem_201706080002
		We are given a different items like (say Pencils and Candles) and a Knapsack to carry them.
		Price[] will have the price for these items; and Weight[] will have weight of each item.
		Array index indicates the item-type. Example: [0] may correspond to Pen and [1] may correspond to Pencil.
		Refer to these arrays to know price and wieght of the article.
		Knapsack has a weight limit of certain Kg; we should come up with the combination of items that 
		will fit the Knapsack and also yeild highest profit.
		We can not take two copies of same item and that is why this is called as 0-1 Knapsack problem. 
		
		This can be solved using DP and also bruteforce. 
			
		
		
 
 
	 0-1 Knapsack problem using Brute force_20170608003
		Brute force method will generate all possible combinations(probably using bit generator), and chooses
		the one that translates to maximum profit. Bit width is equal to Item-count. Bit generator does allow
		duplocates and that suites 01 Knapsack problem style. 
		Ex: It the available items are  Pen, Pencil.
		We can have 3 combs. {Pen}, {Pencil}, {Pen, Pencil}

 
	 0-1 Knapsack problem using DP_20170609001
		DP constructs a Solution matrix.
		Structure of solution matrix is
		-Each Row corresponds to an item and Column Column stands for weight.
		 Say 1st row is for Pencil and 2nd row is for Pen. 
     	 Similarly 1st column is for 1kg knapsack, and 2nd column is for 2Kg knapsack. 
		-Cell value is the Price of items kept inside the bag. 
		
		DP introduces one item at a time in to pool. 
		In the beginning, only one item will be available for selection; so solution matrix will have only one row.
		We compute the values for cells of 1st row.
		
		In the next round, DP introduces 2nd item in to pool, adds an another row in to solution matrix.
		Say second item is Pencil. We ccompute the values for 2nd row, thinking that we have two choices(pen and pencil).
		
	Rules used when filling solution matrix.
		Follow these 3 rules when filling Solution matrix.
		-When filling the sol[], get Price and Weight for the current row from Price[] and Weight[].
		 Price gets written cell, Weight is used for comparing against Column value.
		 
		-We can pour 2ltr milk in to 1ltr can. Before filling the cell check if that column can accomadate the that weight.
		 If it is not either write 0 or import the value from upper row.
		 Say we are filling 2nd row of Solution matrix, and this row corresponds to 'screw driver', and its weight is 4kg and price is 200.
		 Then you can write until we reach the 4th cell.
         So our code should compare the Item's weight and Column's capacity

		-If the choice is between Gold and iron, fill it with Gold because Gold will maximize the profit.
		 So before writing the price to cell, compare it against the value stored in upper cell. If the upper cell
		 has higher value; then simply import it. If current row belongs to 'iron' and top row belongs 'gold'
		 then import the price of the Gold from upper row, for every cell of current row.
		
		-If bag capacity is more than the weight of the item's weight, then add one more item in to bag.
         in addition to current item. Additonal item's price will be in upper row, and its index is the 
		 difference between column capacity and current item's weight.
		 Say we are filling 2nd row of Solution matrix where current item's weight is 10 and column's capacity is 15;
		 the excess weight is 5. Price of 10K from cost[] 
		 We add the "price for current item" to "price taken from 5th index of top row", and write the sum to Sol[].
		 
		 
		 Once the Solution matrix is filled, bottom row will give the maximum price for any weight. 
		 Ex:	3rd column will give max price when bag capacity is 3kg.
				6th column will give max price when bag capacity is 6kg.

		
	
	Steps for 0-1 Knapsack problem_20170609006
		1) Function's input is ItemWieght[], ItemPrice[], ItemTypeCount, Knapsackweight
		2) Allocate a SolutionMatrix of dimension ItemTypeCount+1, and KnapSackWieght+1
		3) Then Initialize the whole solution matrix with 0
		4) Then try to compute cell values for solution matrix, going by one row at a time.
			Wight and Value for every row is given by ItemWieght[], ItemPrice[]. And column goes as long as Knapsackweight

		   To iterate the solution mAtrix, start an outer ForLoop and an inner ForLoop. Start index for both will be 1.
      
		5)  Every loop tries to fill Solution[row][columnWeight]
			  In every loop, compare if currentItemWieght < ColumnWieght.
			  Here 'currentItemWieght' is the weight of ItemType like Pencil and Gold, and this comes from ItemWeight[]
			  'ColumnWeight' is 0kg, 1kg,... scale

			  If columnWeight is higher, then column can accomadate the item. 
			  Then find out the difference between currentItemWieght & ColumnWieght (Call this as TraceItemWeight)
			  Use TraceItemWeight as Index in to upper-row, and extract the value for TraceItem (say TraceItemValue).
			  Then add both currentItemValue and TraceItemValue
			   Here 'currentItemValue' is the VALUE of ItemType like Pencil and Gold, and this comes from ItemValue[]
			   Compare the sum with the Uppercell’s value (that is Solution[row-1][columnWeight - 1])
			   Whichever value is higher should be written to Solution[row][columnWeight]

			   If the columnWeight is lower than ColumnWieght, then column can not accomadate the currentItem so we assign 
			   Upper cell's value to Solution[row][columnWeight]. By doing this we will not be adding the current item in to bag.
			   This ends one loop. In the next loop we will be filling the value for next cell.   


//Finding the items that are in Knapsack
	0-1 Knapsack problem Interpreting the Solution Matrix_20170609005
		Bottom-right cell of Solution matrix gives the maximum value that can be carried by knapsack but to find the subset of items that makes up the bag, we have to walk back the matrix. 

		Start by Walking UP from Bottom-right cell. At every step, compare the current-cell with the cell right above it, located in upper row. If the values are same, then current-row’s value has been imported from upper-cell. In otherwords, item-type for current-row did not make it to bag, so we do not include the item in SUBSET, and instead go up by one more row, by decrementing row-index.

		If current cell-value were to be higher than upper cell’s value, then the item-type represented by current row (that is lower-row) has been added to bag, so we include it in Subset.  Then we go to UPPER row and make a LEFT turn. Turn quantity is “column-weight - itemTypeWeight”. Left Turn will land us in some cell. From that point, we continue to compare the current cell with upper-cell. We do this untill we reach 0th row.  

		Note length of subset should be less than equal to row count(number of item types) 


	Steps for finding items that are in Kanpsack_20170609007
		a) Iterate the Matrix from Bottom-Right corner.
			Note that same variables are used to access both SolutionMatrix and ItemArrays.
			They are initialized to itemTypeCount, and KnapsackWeight.
			So variables are Index to SolutionMatrix(means do not use -1), and count to ItemArrays(means use -1)
	
			rIdex = itemTypeCount; 
			cIdx = KnapsackWeight; 
	
		b) Start a while() to from MaxRow to until ( > 0) 
		c)  In every loop always decreease RIdx, and decrease cIndex only when we record the cell.
		d)  Inside the loop compare current-cell with the upper-cell of the same column
			If the cell values are same then do not do anything, just decrement the ROWIndex, and go to next round.
				(Solution[rIdx][cIdx] == Solution[rIdx -1][cIdx])
		
			If the Cell values are different then current Item is in Bag so add it to subset
			 Add ItemWeight[rIndex -1] to string object
		
			Then we need to make a LEFT turn by the amount "cIdx - ItemWeight[rIdx - 1]", so adjust the cIndex by "cIdx - ItemWeight[rIdx - 1]"

			Note that we used the ItemWeight for upper row.
			Then go to next round.
		d) In the end string object will have the content of bag


		
		

	*/
	class KnapsackUsingDP
	{
		public:
				void CallKnapsackUsingDP()
				{
					int TargetWeight = 10;
					
					//'WeightAndPrice' Stores the item and its price
					//Ex: 
					//              wt      wt
					//	pen			10      67
					//	pencil      4       30
					//////////////////////////////

					int	WeightAndPrice[2][4] = { { 5, 4, 6, 3 } , { 10, 40, 30, 50 } }; //itemTypeCount = 4
					KnapsackUsingDP2((int*)(WeightAndPrice[0]), (int*)(WeightAndPrice[1]), 4, 10);
					/*
						 --0   1   2   3   4   5   6   7   8   9   a--
						   0   0   0   0   0   0   0   0   0   0   0
						   0   0   0   0   0  10  10  10  10  10  10
						   0   0   0   0  40  40  40  40  40  50  50
						   0   0   0   0  40  40  40  40  40  50  70
						   0   0   0  50  50  50  50  90  90  90  90
						   Subset(wt): 4, 3


						   0   0   0   0   0  10  10  10  10  10  10
						   0   0   0   0  40  40  40  40  40  50  50
						   0   0   0   0  40  40  30  30  30  30  70
						   0   0   0  50  50  50  50  90  90  80  80
					*/

					int TargetWeight2 = 5;
					int	WeightAndPrice2[2][4] = { { 2, 3, 4, 5 } ,{ 3, 4, 5, 6 } }; //itemTypeCount = 4
					KnapsackUsingDP2((int*)(WeightAndPrice2[0]), (int*)(WeightAndPrice2[1]), 4, 5);
					/*
					      -0   1   2   3   4   5-
						   0   0   0   0   0   0
						   0   0   3   3   3   3
						   0   0   3   4   4   7x    
						   0   0   3   4   5   7
						
						 Subset(wt): 2, 3 

						   //7x => "Value[2] + TraceValue" 
						            "4 + sol[cw - wi]"
									 4 + sol[5-3]
									 4 + 3
									1, 2,
					*/
				}
				void KnapsackUsingDP2(int* ItemWeight, int* ItemPrice, int itemTypeCount, int NumberOfWeights)
				{
					//Allocate a SolutionMatrix of dimension ItemTypeCount+1, and KnapSackWieght+1
					int Solution[256][256];

					
					//Then Init the all of the solution matrix with 0
					for (int row = 0; row < 256; row++)
					{
						for (int column = 0; column < 256; column++)
						{
							Solution[row][column] = 0;
						}
					}

					//Then try to compute cell values for solution matrix
					for (int row = 0; row < itemTypeCount; row++)
					{
						for (int col = 1; col < NumberOfWeights+1; col++)
						{
							//If the col is lower than currentItemWieght, then column can not accomadate the currentItem so we assign Upper cell's value to Solution[row][col].
							//This ends one loop. In the next loop we will filling the value for next cell.
							if (row == 0)
							{	

								if (ItemWeight[row] <= col)
								{
									Solution[row][col] = ItemPrice[row];
								}
								else
								{
									//This is top row, assign the price the current item 'as it is' to solution matrix.
									Solution[row][col] = 0;
								}
							}
							else
							{	//This is not a top row so follow rules while computing value for sol
								if (ItemWeight[row] <= col)
								{
									int excessCapacity = col - ItemWeight[row];

									//go to previous row and get the price for this 'excessCapacity', and add that to current item's weight
									int sumTemp = ItemPrice[row] + Solution[row - 1][excessCapacity];
									             //currentItem's price + price for the item used for filling excess-capacity
									if (sumTemp > Solution[row - 1][col])
									{	//If the sumTemp is LOWER then we IMPORT the value from upper
										Solution[row][col] = sumTemp;
									}
									else
										Solution[row][col] = Solution[row - 1][col];
								
								}
								else
								{
									//column can not accomadate the wieght of currentItem, so import the price from upper row
									Solution[row][col] =  Solution[row - 1][col];
								}
							}
						}
					}

					cout << "printing solution matrix \r\n";
					//PrintMatrix
					for (int row = 0; row < itemTypeCount; row++)
					{
						for (int c = 0; c < NumberOfWeights+1; c++)
						{
							cout << setw(4) << Solution[row][c];
						}
						cout << "\r\n";
					}

					
					//Print the items that are in Knapsack
					string subset;
				
					int cIdx = NumberOfWeights;
					int rIdx = itemTypeCount;
			
					while (rIdx > 0)
					{
						if (Solution[rIdx][cIdx] == Solution[rIdx -1][cIdx]) //compare with the cell right above the current cell
						{
							//Do not record item because this item has not made it in to bag
						}
						else
						{	//This item has made it in to bag, so add it to subset
							stringstream ss;
							ss << ItemWeight[rIdx - 1] << " "; //This does iToa conversion
							subset = subset.append(ss.str()); //ItemPrice index is one lower than solution index.
							
							cIdx = cIdx - ItemWeight[rIdx - 1];	//Also make a LEFT turn. (Note: we use the wight of upper-cell)
						}
						rIdx--; //Always Go UP. 
					}
					cout << "subset that is Knapsack is " << subset.c_str();
				}

			
	};
};