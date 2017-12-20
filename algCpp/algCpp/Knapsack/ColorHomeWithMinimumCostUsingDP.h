#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
namespace ColorHomeWithMinimumCostUsingDPNM //@RED20170527001
{
	/*
		hxxp://stackoverflow.com/questions/15630743/is-house-coloring-with-three-colors-np
		
		Lowest Cost for painting 3 homes_20170527001
			hxxp://stackoverflow.com/questions/15630743/is-house-coloring-with-three-colors-np
			Problem: Compute the cheapest price for painting 3 homes with 3 colors.	Cost of each paint is different, and also for a 
			given paint, price changes depending how many times it is being used. (R could cost 100 for 1st home and 200 for 2nd home). Since the price of paint depends on home-count, each color will have price-array, where 1st 1st element is the price 1st home and 2nd element is the cost for 2nd home.

			One more conditsion, we are not allowed use same paint for two adjacent homes. Ex: when total home count is 2, we can not use red for both the homes.


			Ex: 
			INPUT: Cost of colors  
			Attempt#	   1st   2nd	3rd
			R	      =   {1,	4,	6}  //Cost of R is "1" for 1st home, "4" for 2nd time use, and "6" for 3rd time use.
			B	      =  {2,	100,	2}  //.....
			G	      =  {3,	100,	4}

			Solutions:
			There are two solutions: One is combination-method and other is DP-method. 
					
		Lowest Cost for painting 3 homes Using Combination Method_20170527002	
			In combination-method, generate all the possible combinations like “R B R” and “R G B”, and compute the cost for each one of the combination, and pick the cheapest combination as solution. 
			Width of the each combination is equal to number of homes. To generalize this solution for different number of homes, say we have just 2homes, then each combination will have 2 elements (like “R B”, “B G”, etc..), and the color price comes from 2nd element o of cost-array. 

			Similarly when there are 3 homes, combination will have 3 elements (like “R B G”, “B G R”, “R B R” etc..). For combination “R B R”, cost for 1st R comes from costArray[1], and cost for 2nd R comes from costArray[2].


			Number of combinations or the Complexity is ("numberOfHomes" ^ "numberOfHomes"). If home-count is 3, then we will have 27 combinations. 
 

		Lowest Cost for painting 3 homes Using DP-method_20170527003
			In general, DP first computes the cost for painting 0 homes; and uses it to compute the cost for painting a ‘pool of one-home’; and uses it to compute the cost for paniting a ‘pool of two-homes’, and this goes on.  At every level DP takes the solution from previou-level and adds one to it. This is why DP method is efficient.

			For example: cost for painting a ‘pool of two-home’ =  Cost from ‘pool of one-home’ + Cost of using the paint for second time time.

			Similarly we compute the cost for ‘pool of three-homes’. As you see, at every level we are adding just doing one extra addition.

			Complexity of DP method is O(homes * colors);
 
			Lowest Cost for painting 3 homes (How costs are computed)_20170527004
			Assume we have 3 colors and 3 homes. To solve this problem, we need a 3x4 solution matrix where row corresponds to color(1st row is RED, 2nd is BLUE …), and Column-number indicates the "number of houses in that pool" (0th column has no homes, 1st column has 1 home, and 2nd column has 2 homes,…). 
			Coming to the Cell value, it indicates the total cost of painting. 
			For 0th column, values cost is 0.
			For 1st column, since there is only one home, RED-row get costOfRed[0], and BLUE-row gets costOfBlue[0].
			For the 2nd column, we have to select two colors because there are two homes, and both colors can not be same.  We already know the cost for one home, and that VALUE is in the 1st column. 2nd color’s value comes from costArray[2]; note the index is 2 because it is 2nd color for that specific home. 

			Problem mandates that we should not use same color for two consecutive homes. So when reusing the value from 1st column, pick the cheapest among two other colors. Since 1st row is RED, select chepest among Blue and Green from Row[1].

			Finally, (r2) that is 1st-row of 2nd-column = costOfRed[2] + chepest among Blue and Green from Row[1]. 
																	  6   =   4                  + 2    (blue is cheap)
			Similarly compute the value for 2nd-row and 2nd-column. Since 2nd row is BLUE, select the chepest among Red and Green from Row[1].
			Finally, (b2) that is 2nd-row of 2nd-column = costOfBlue[2] + chepest among Red and Green from Row[1]. 
																	  101  =   100                 + 1 (red is cheap)    

			Similarly compute the value for 3nd-row and 2nd-column.
			Finally, (g2) that is 2nd-row of 2nd-column = costOfGreen[2] + chepest among Red and Blue from Row[1]. 
																	  101         =   100                 + 1 (red is cheap)    

			We have computed the cost when there are two homes. For a second assume problem definition said just two homes, and try to compute the cost for cheapest-paint option.
			Each row of 2nd-column covers a combination of painting.
			Red-row gives the cost if we used red as 2nd color, and chose cheapest among B and G as 1st color. 
			Blue-row gives the cost if we used blue as 2nd color, and chose cheapest among R and G as 1st color. 
			Gree-row gives the cost if we used Green as 2nd color, and chose cheapest among R and B as 1st color. 
			So the cheapest option is given by the row with lowest value in 2nd column.  That value is 6.

			Final solution matrix (cheapest cost is 8 in last column)
						0  1  6    107
						0  2  101  8
	            		0  3  101  10




		 Building of solution Matrix
					Input
						INPUT: Cost of colors  
						Attempt#	   1st   	2nd		3rd
							R		=  {1,		4,		6}  //Cost of R is "1" for 1st home, "4" for 2nd time use, and "6" for 3rd time use.
							B		=  {2,		100,	2}  //.....
							G		=  {3,		100,	4}
			
			Solution Matrix steps
					1
						0  1  0  0
						0  2  0  0
						0  3  0  0


					2
						0  1  6    0   //6 = Cost of colors[
						0  2  101  0
						0  3  101  0


					3
						0  1  6    107
						0  2  101  8
						0  3  101  10


		Final Solution matrix (Cheapest cost of painting is in "lowest row in 3 column")
						0  1  6    107
						0  2  101  8
						0  3  101  10
	

	Steps for Lowest Cost for painting 3 homes using DP-method_20170527005
		Declare color-array and solution-array, one for each color (R,G,B).
		Initialize each of the cost-array with respective color price.
		Initialize the solution-array with 0.

		Note that for storing/memorizing the DP solution, we are storing each row of matrix as a seperate row.
		MAtrix turns the code in to a complex bundle of indexes; we avoid that by using separate array for
		each row. Arrays are named as R, G, B; and their length is "numberOfHomes + 1"

		Start bulding the solution-array column by column.
		Set Index = 1 and, start a while to  go until "index < maxHomes + 1".
		First round of while loop computes the cost when pool has one home.
		2nd round of while loop computes the cost when pool has two homes.
		Loop ends after 3rd round.
		Inside while-loop
		solution-Red[index] = costOfRed[index-1]
		+
		min(solution-Blue[index-1], solution-Green[index-1]);

		Do this for solution-Blue[index] and also solution-Green[index]

		Once we are out of the while loop, cheapest cost is lowest value stored in last-index in all of the solution-arrays.
		Means lowest among
		solution-Red[index], solution-Blue[index] and solution-Green[index]

	*/


	const int MaxColors = 3;
	const int MaxHomes = 3;

	const int PaintUsageCount = 3;
	const int MaxRowsOfHomes = 3;
	const int HomesPerRow = 3;
	class ColorHomeWithMinimumCostUsingDP
	{

		public:
				void callColorHomeWithMinimumCostUsingDP()
				{
					

				    //We have 3 colors (R,g,b) paints; and 9 homes to paint(3 homes in 3 rows).
					//We need to find a cheapest combination of colors for painting.
					//Problem has two conditions:
					//First condition is that we can not use same color for the homes that are in a same row.
					//Second condition is that Price of the color changes depending on whether it is being used for 1st time or 2nd time or 3rd time. 
					//Example: Cost of Red paint could be 5$ when used for the 1st time in 1st row;
					//If we use it again in the 2nd row the cost could 14$. 
					//This is why, problem input has price array for each color. There are three colors and  possibility for 3 attempts;
					//and that gives rise to 3 prices. So taotally we have 9 prices. This can be represented as Matrix.
					//Where row is number of attempt and column is type of color.
					//Ex: Under Red column, 1st-row gives price for 1st time usage of Red; and 2nd-row gives the price for 2nd time usage 
					//of Red color. 
					
					//Solve this using DP. 
					//Start with just one row of homes; compute the price for painting them. Store that result in 1st row of solution matrix.
					//Then add one more row of homes to the problem; and compute the price and update 2nd row of solution matrix.
					//Similarly add the 3rd row of homes to the problem and compute the price and update the 3rd row of solution matrix. 
					//Cheapest cost of painting is the lowest value in the last row of solution matrix.

					//Solution matrix should show the consolidated price. 
					//In the sense, cost stored in 2nd row is the price when we have to paint both two rows of homes; not jut 2nd row alone.
					//Similarly the price in 3rd row reflects the price when we have to paint al the 3 rows of homes.
					//This is how we compute the value stored in solution matrix.
					//Price in 1st Row = Price for 1st row //This comes from srcPrice[1st attempt] 
					//Price in 2nd Row = Price for 1st row  + Price for 2nd row 
					//					 (comes from 1st row of solu[]) + (comes from srcPrice[2nd attempt])

					//Price in 3rd Row = Price for 2nd row  + Price for 3rd row 
					//					 (comes from 2nd row of solu[]) + (comes from srcPrice[3rd attempt])
					//Note when filling the sol[] for 2nd row; if we selected RED for a 2nd row, then we must select the cheapest among GREEN or BLUE 1st row.
					//This means when picking value from 1st row of solu[], pick the cheapest value among BLUE and GREEN.
					//This is how we are able to deduce the cheapest cost; so this step is very important.
					//Ex:
					//Price in 2nd Row(RED) =   Price for 1st row  + Price for 2nd row 
					//							Min(sol[1, BLUE], sol[1, GREEN]) + srcPrice[2nd attempt for RED]
					

					//Price in 3rd Row(Blue) =  Price for 2nd row  + Price for 3rdd row 
					//							Min(sol[2, RED], sol[2, GREEN]) + srcPrice[3rd attempt for BLUE]
					
					//Row is 'Usage-count' Column is 'Colors' (RGB0
					//Cell value is Price.
					//6 is price for using RED for the 3rd time
					int paintCostUsageCountByColor[PaintUsageCount][MaxColors] = 
					{
						{1, 3, 2 },										
						{ 4, 100, 100 },
						{ 6, 4, 2 }
					};
					
					//Build a solution matrix of same dimention as source-cost-matrix
					int Solu[MaxRowsOfHomes][HomesPerRow] =
					{
						{ 0, 0, 0 },
						{ 0, 0, 0 },
						{ 0, 0, 0 }
					};


					

					cout << "Cost of Matrix Solution Matrix \r\n";
					cout << "\r\n";

					cout << "Solution Matrix \r\n";
					cout << "\r\n";
					
					cout << "\r\n building solution Matrix \r\n";
					
					//This computes the values for solution matrix. Values stored in solution matrix is cosolidated values.
					//This loop will introduce one row of homes at a time.
					//r=0 there is only 1st row of homes
					//r=1 there is only 1st row of homes
					for (int r = 0; r < MaxRowsOfHomes; r++)
					{
						//There is only one row of homes. pick the cost for 1st time use of colors
						if (r == 0)
						{
							Solu[0][0] = paintCostUsageCountByColor[0][0]; //fills with RED for 1st attempt
							Solu[0][1] = paintCostUsageCountByColor[0][1]; //fills GREEN
							Solu[0][2] = paintCostUsageCountByColor[0][2]; //fills BLUE
						}
						else
						{
							Solu[r][0] = paintCostUsageCountByColor[r][0] + min(Solu[r-1][1], Solu[r - 1][2]); //fills with RED for 1st attempt
							Solu[r][1] = paintCostUsageCountByColor[r][1] + min(Solu[r - 1][0], Solu[r - 1][2]); //fills GREEN
							Solu[r][2] = paintCostUsageCountByColor[r][2] + min(Solu[r - 1][0], Solu[r - 1][1]); //fills BLUE
						}
					}

					//Print the Solution Matrix content
					for (int m = 0; m < MaxRowsOfHomes; m++)
					{
						for (int n = 0; n < HomesPerRow; n++)
						{
							cout << Solu[m][n] << " ";
						}

						cout << "\r\n";
					}

					/*
						building solution Matrix
						1	3	2
						6	101 101
						107 10	8

						Lowest cost is 8.
						
					*/
				}

				
				void print(int* data, int len)
				{
					for (int i = 0; i < len; i++)
					{
						cout << data[i] << "  ";
					}
					cout <<"\r\n";
				}
			
	};
};