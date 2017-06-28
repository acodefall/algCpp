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
		We are given a different types of items (say Pencils and Candles) and a Knapsack to carry them. Their price and weight is different. So price-weight combo is unique. We should compute the subset of items that can be carried in knapsack and also has value. For example: if choice is between Gold and Paper, then choose the Gold.
 

		There are few variations of Knapsack problem: “0/1 Knapsack problem” and ‘Regular Knapsack problem”. In 0/1 Knapsack problem, we are limited to take one item per Item Type. Like one candle per bag. 

		Knapsack Problem can be solved using BruteForce, DP and Graph(shortest path). BruteForce takes “2 ^ Type Of Item Count”. DP takes O(Type Of Item Count * Capacity of Knapsack).
 
	Knapsack and subset
		Knapsack problem can be viewed as subset problem also because the combination with maximum profit is a SUBSET of original SET. Going further, SUBSET can in turn be viewed as Suffix-STRING.
 
 
	 0-1 Knapsack problem using Brute force_20170608003
		Brute force approach generates all the possible combinations of 'Item Type', and then computes the cost for each of the combination, and selects the priciest among them.  Number of combinations is (2 ^ Item Type count'). We can use Bit generator code, and Bitwidth will be 'Item Type count'. For 2 Item items(Pencil and Candles), combination count is 4. 
 
	 0-1 Knapsack problem using DP_20170609001
		DP constructs a Solution matrix. There will be one row per Item-Type (1st row could be Pencil and 2nd could be Candles). 
		Column carries weight-scale, going from 0 to the capacity of the Knapsack. 
 
		DP tries to solve the problem in small steps. For example: Knapsack’s capacity is 5Kg and there are 4 types of items to choose from. DP does not directly compute the best price for 5kg with 4item types. Instead, DP assumes that weight is 1Kg and there is only one Type of item, and computes the maximum profit for 1kg bag/one-item-type, and stores the max-profit in cell (1, 1). Then DP introduces 2ng Kg and 2nd ItemType. This goes on until we reach 5kg. Solution Matrix is structured in such a way that complexity increases in small steps. When the cursor is at Top-left corner, there will be one item and 1kg bag, and as cursor moves towards bottom-right corner, the Weight and Item type increases. 

		Cell (1, 3) gives the Max profit for 1Kg knapsack with only Pencil being the choice.
		Cell (2, 5) gives the MAX profit for knapsack of capacity 5Kg, when the item types are Pencil and Candles.
		Matrix construction takes O(itemType-count * Capacity of Knapsack).

	0-1 Knapsack problem DP Efficiency_20170609002
		0th row and 0th column is initialized using zeros, and this stands for 0kg and 0 item-types. 
		1st row represents 1st ItemType (say Pen 6/6), 2nd row represents 2nd ItemType (say Pencil 4/4), and 3rd row represents  3rd ItemType (say Gold 2/80). In NORMAL world, 1st row can select only Pen, and 2nd row can select either Pen or Pencil, and 3rd can select Pencil, Pen or Gold. If 3rd row tries to look at 1st and 2nd rows, then that will be inefficient, and DP wants to avoid that by making 2nd row represent the best of 0th 1st 2nd row itself (in fact 2nd row will import 1st row’s value if it finds out that 1st row is higher). Because of this consolidation (done by 2nd row) the 3rd row can focus on only 2nd row, and ignore previous rows. This is how DP achieves its efficiency. 

	0-1 Knapsack problem Filling solution Matrix_20170609003
		The cells of 1st row can select nothing but Pen. Pen’s weight is 6 and it can not fit in to 
		1st 2nd 3rd 4th 5th columns because ColumnWeight can not accomadate ItemWeight of 6, so write 0 for 1st 2nd 3rd 4th 5th columns. From 6th column onwards the values will be VALUE of Pen. Even the 10th column will have 6 because we can not have multiple copies of same item. (This is equilavent to carrying 1pen in a bag of capacity 10Kg)

		Coming to 2nd row of Pencil(weight is 4), cells can stick to Pencil or go for Pen represented by UPPER row. Note that 2nd row can not use 3rd row of Gold because it has not be introduced. Pencil’s weight is 4 and it can not fit in to 1st 2nd 3rd column so we import the VALUE from UPPER row. Beginning from 4th column, we can use Pencil’s value as Cell value but before doing that we have to make that the Pencil’s value is higher than Upper-cell value. So we compare the Pencil’s value against Upper row and use which ever is higher. Upper row has 0 for first first rows because Pen’s Wieght is 6. Value of Pencil is high compared to 0, so we write “value of Pencil 4” to 4th and 5th cells. For the 6th cell, Upper row has Pen of value 6 and current row has Pencil of value 4, we select Pen from Upper row instead of Pencil. From onwards all the subsequent cells will import Pen from upper row. This implies that if the bag capacity is 6 and higher, then go with Pen, 

		Coming to 3nd row of Gold item(weight is 2), import the values from upper row until 2nd. For 2nd column compare upper cell’s value againt Gold’s value of 80. Value of Gold is high so write 80 to 2nd cell. This implies that bag capacity is 2Kg then we will ignore Pencil, Pen and take just one Gold.
		When cursor goes to 3rd column, we find that ColumnWight is 3Kg and ItemWieght is 2Kg, so even after adding one gold we will still be left with space for 1Kg. So try to fill 1Kg extra space with suitable item(call it TraceItem), and that TraceItem will be in 1st column of upper row. In this case TraceItem is 0. We add the TraceItem’s Value and Gold’s Value and sum comes to 80. Before putting these two items in to Bag we have to check if there is higher valued item, so we check the Upper cell’s value. 80 is still the higher so we write 80 to cell. Until the 8th column we write 80 as cell value. On the 8th cell, difference between ColumnWight and ItemWeight becomes 6. 6 is equal to weight of Pen. For 8th cell we add the value of Gold and value stored at 6th column of upper cell. This is 86. 86 is higher than upper cell value and we write it to cell. This implies that if bag capacity is 8Kg, then we go with one gold and 1 pen.

	
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

				/*
					Function's input is ItemWieght[], ItemPrice[], ItemTypeCount, Knapsackweight
				*/
				void KnapsackUsingDP2(int* ItemWeight, int* ItemPrice, int itemTypeCount, int KnapsackWeight)
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
					//Start an outer ForLoop to iterate rows and an inner ForLoop to iterate columns
					//Start index for both will be 1.

					//We initialize the index to 1 so it is suitable for Solution Matrix, but accessing ItemPrice[] and ItemValue[] array do -1.
					for (int row = 1; row < (itemTypeCount + 1); row++)
					{
						for (int columnWeight = 1; columnWeight < (KnapsackWeight + 1); columnWeight++)
						{
							//Every loop tries fill Solution[row][columnWeight]
							//In every loop compare if currentItemWieght < ColumnWieght.
							//Here 'currentItemWieght' is the weight of ItemType like Pencil and Gold, and this comes from ItemWeight[]
							//     'ColumnWeight' is 0kg, 1kg,... scale

							//If columnWeight is higher, find out the difference between currentItemWieght & ColumnWieght (Call this as TraceItemWeight)
							//Use TraceItemWeight as Index in to upper-row, and extract the value for TraceItem (say TraceItemValue).
							//Then add currentItemValue and TraceItemValue
							//Here 'currentItemValue' is the VALUE of ItemType like Pencil and Gold, and this comes from ItemValue[]
							//Compare the sum with the Uppercell value that is Solution[row-1][columnWeight - 1]
							//Whichever value is higher should be written to Solution[row][columnWeight]
							

							//If the columnWeight is lower than currentItemWieght, then column can not accomadate the currentItem so we assign Upper cell's value to Solution[row][columnWeight].
							//This ends one loop. In the next loop we will filling the value for next cell.
							if (ItemWeight[row - 1] <= columnWeight)
							{
								//compare the weight of column and weight of the item represented by that item-type.
								//column-weight could be too low compared to weight of the item.
								//In that case use the item-type, that is latest in bag.
								
								
								int traceWeightValue = 0;
								int traceWeight = columnWeight - ItemWeight[row - 1];
								traceWeightValue = Solution[row - 1][traceWeight];
								
								//compute the Value of NewItem by adding Item'sValue and TraceWeight'sValue
								int NewItemValue = ItemPrice[row - 1] + traceWeightValue;
								
								//compare the existingValue with potentialValueOfNewItem
								//SameColumn of 'UpperRow is CurrentVAlue that is already in the Bag'
								if (NewItemValue > Solution[row - 1][columnWeight])
									Solution[row][columnWeight] = NewItemValue;
								else
									Solution[row][columnWeight] = Solution[row - 1][columnWeight];
							}
							else
							{	//Item's weight is higher, column-weight can not accomadate it 
		
								Solution[row][columnWeight] = Solution[row - 1][columnWeight];
							}
						}
					}

					cout << "printing solution matrix \r\n";
					//PrintMatrix
					for (int row = 0; row < (itemTypeCount + 1); row++)
					{
						for (int c = 0; c < (KnapsackWeight + 1); c++)
						{
							cout << setw(4) << Solution[row][c];
						}
						cout << "\r\n";
					}

					
					//Print the items that are in Knapsack
					string subset;
				
					int cIdx = KnapsackWeight; 
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