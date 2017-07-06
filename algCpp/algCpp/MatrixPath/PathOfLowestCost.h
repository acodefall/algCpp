#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
namespace PathOfLowestCostNM
{
	/*
	Identify the path of lowest cost in a Matrix_20170701010
			We have a 2D - matrix where each cell has a cost to travel.
			Find a path from Top - left to Bottom - right corner, who's sum is lowest.
			You can move only right or down.
			Recursion approach takes O(2 ^ n) and Dynamic version takes O(N ^ 2)

	Compute lowest cost to traverse Matrix using DP method_20170701011
			Core logic is as follows.
			Cost for reaching a particular cell from Root, can be derived by adding cost of the one of the neighbouring cell and the cost of current cell itself.Cost of the neighbor comes from Solution matrix and cost for current cell comes from SrcMAtrix.
			Since we are interested in the lowest cost, we have to select the neighbor who has lowest cost, and add the current cell’s value to it.This logic is used for computing SolMatrix and it will hold the lowest cost for every cell.
			Cost for current cell = Cost for one of the neighbour stored in SolMat[] + cost of current cell stored in SrcMatr[]

			DP will fill out this Solution matrix as follows.
			DP starts by assuming that there is only one cell in matrix, and cost for the cell is srcMatrix[0, 0].
			//Root cell
			sol[0][0] = SRC[0][0]

			Then DP introduces more cells in to matrix, and computes lowest - cost for them, based on the lowest - cost of the neighboring cells who’s value is already present in solution matrix.

			If the new cell is in Top - Row, then that cell has only one neighbor, and we have to use it whether its cost is high or low.This neighvoring is the left - cell.Lowest cost for new cell is sum Lowest cost of ‘immidiate left - neighbour’ + the the price of current cell stored in SrcMatrix[].
			//Top row
			sol[r][c] = sol[r][c - 1] + SRC[r][c];

		If the current cell is in Left - Column, then there is only one choice, and that is ‘immidiate top - neighbour’.
			//Left column
			sol[r][c] = sol[r - 1][c] + SRC[r][c];

		If the new cell is an internal cell, then that cell has two neighbors(top and Left).We pick the neighbor that has lowest value, and add the value of  new cell that is stored in SrcMatric[].Result gets stored in Solution matrix.
			sol[r][c] = min(sol[r - 1][c], sol[r][c - 1]) + SRC[r][c]);
			In this fashion, DP goes on expanding the Sol Matrix till it reaches the dimension of Source Matrix.
				Runtime is O(M*N) that is equal to the time spent constructing Solution Matrix.

				Takes O(M * N) time

	Steps to compute lowest cost to traverse Matrix using DP_20170701012
				a) Parameters are SrcMatrix[], RowCount, ColCount
				b) Allocate and also initialize the Solution Matrix who's size is same as SrcMatrix   
				c) Start two nested ForLoops to fill Solution Matrix.Indexes are P and Q.
				d) ForLoop will have IF conditions to check where the CELL is located and appropriately computes solution.
				if ((p == 0) && (q == 0)) //Cursor is at root, there is no past cell to refer, so select the value from SrcMatr[0,0]
					set sol[p, q] = src[p][q];;
				else if (p == 0)
				{
					//Cursor is going along TopRow. History has only LEFT-cell, and we must select it. 
					//DP computes Solution cell value based only on the value stored in is Left - Cell.
					Sol[p][q] = Sol[p][q - 1] + src[p][q];
				}
				else if (q == 0)  //Cursor is going along LeftCol. 
				{
					//Cursor is going along LeftMostColumn. History has only TOP-cell, and we must select it. 
					//DP computes the Solution cell value based only on the value stored in  TOP cell.
					Sol[p][q] = Sol[p - 1][q] + src[p][q];
				}
				else
				{//Cursor is at internal cell. History has Top-cell and Left-cell. Select the minimum among the Left & Top
					Sol[p][q] = min(Sol[p - 1][q], Sol[p][q - 1]) + src[p][q];
				}
			e) Once the Solution Matrix is constructed, lowest cost will be at
			Sol[rows - 1][cols - 1];

			f) Complexity is time taken to build solution matrix O(M * N)

	Compute the actual path of lowest cost_20170701013
			Solution Matrix has the cost but not actual cell values, and cell values are stored in SrcMatrix[].
			To compute the actual path of lowest cost, we need to link both the matrices.
			Navigate the Solution Matrix from Bottom - Right corner.Cursor starts from corner cell, record the SrcMatrix - value that corresponds to corner cell.
			Then we can go to Left - cell or Top - cell, go to cell with lower value; Record the SrcMatrix - value that corresponds to that cell.In the next round either go UP or LEFT.Repeat these steps until you reach Root.

			Steps for Computing the actual path with lowest cost _20170701014
			a) Input parameter is Solution Matrix and SrcMatrix.
			Now we need to navigate the Solutiin matrix from bottom - right conrner to root, so initialize the indexs.

			b) Initialize R & C to MaxRow and MaxCol
			c) Start a while loop for navigating SoluMatrix, it goes as long as
			while ((r > 0) && (c > 0))
				d) Inside While()
				Record the current cell of SrcMatrix using std::to_string()

				Next we have to decide whether to go UP or LEFT.
				If(sol[r - 1] <= sol[c - 1]) //TOP CELL < LEFT cell
				Go to TOP
				Decrement ROWindex;
		Else
			Go to LEFT
			Decrement CoumnIndex;

		e) By the time while - loop ends, we will have actual path of lowest cost

	Compute lowest cost to traverse Matrix using Recursion method_20170701015
			As we navigate from Root to Bottom corner, we only tread the cells that have lowest value.When cursor is at FORK, and is offered to select either RIGHT cell or BOTTOM cell, it will select the cell that has lowest value, and makes a recursion call to it.Callee knows that caller entered our cell because our cell has lower value, so fuction records the current cell’s value in variables called as lowestCost and lowestPath.These variables are carried along as recursion parameter, and they keep track of lowest valued cells.When the recursion reaches the CORNER cell, LowestValue and LowestPath variables will have the lowest cost and also Lowest path.Function will return the Lowest Cost to the caller, and prints the lowestPath.Caller at higher will receive the return value, and passes it to next higher level.

			This recursion is different from Counting Path problem in two ways :
			-Counting path entered every road at the FORK, so it called all the 3 neighbours(Right / Bottom / Diagonal).So every path hits the Bottom - corner - cell.In case of Lowest cost problem, we call either Right - cell or Bottom - cell, so in the end only one thread reaches the Bottom - Corner - cell.Basically function makes only one recursion call, irrespective of number of avialable options.

	Steps to compute lowest cost to traverse Matrix using Recursion_20170701016
			Here we want to compute lowest cost and also the path.
			Note that we do not have any Solution matrix here.

			a) Parameters are SrcMatr, RIndex, CIndex, LowestCost, Path
			In the beginning of the function
			- Append current cell to Path variable
			- Add current cell to Lowest cost variable.
			Do this even when cursor is at Bottom - right corner also.
			- Lastly check the cursor location, and based on that make a recursion call to either RIGHT - cell or Bottom cell.
			Unlike counting number of paths, we make ONLY one recursion call, that is to either Right - cell or Bottom - Cell, but not to both.
			Because of this only one path reach the CORNER cell.
			- There is no PostRecursion code, so recursion - call can directly RETURN to caller.

			As soon as you enter the function,
			-Append current cell to Path variable
			- Add current cell to Lowest cost variable.

			b) Check if current cell is right - bottom corner cell, if so return 1
			if ((r == MaxRows - 1) && (c == MaxCols - 1))
				Print the Actual Path.
				Return the LowestCost
				Note that only Path will be printed because only the LOWEST path will reach this corner.Rest of the path gets in earlier round.

				Check if current cell is at bottom - row, then make only one recursion call that is to Right - neighbour
				if (r == MaxRows - 1)
				{
					return  LowestCostToTravelRecursion(src, r, c + 1, MaxRows, MaxCols, lowestCost, Path);
				}
		Check if current cell is at right - column, then make only one recursion call that is to Bottom - neighbour
			if (c == MaxCols - 1)
			{
				//we can only go down 
				return  LowestCostToTravelRecursion(src, r + 1, c, MaxRows, MaxCols, lowestCost, Path);
			}
		Check if the current cell is an internal cell, we can go RIGHT or BOTTOM, enter the cell that is LOWER in value
			if (src[r][c + 1] < src[r + 1][c])
			{
				return LowestCostToTravelRecursion(src, r, c + 1, MaxRows, MaxCols, lowestCost, Path);
			}
			else
			{	//BottomCell is cheaper so go to Bottom cell
				return LowestCostToTravelRecursion(src, r + 1, c, MaxRows, MaxCols, lowestCost, Path);
			}

		e) Once recursion is complete, caller will get the LowestCost.We come to know about Lowest cost when control reaches the Bottom - Right corner.We return  LowestCost, and that gets returned all way to the main().There is post - recursion code, so every level returns the LowestCost as it is.
		f) Complexity is O(2 ^ N)
	*/
	const int MAXRow = 4;
	const int MAXCol = 4;
	class PathOfLowestCost
	{
		public:
		
		void callPathOfMinimumCost()
		{
			int src[MAXRow][MAXCol] = {
				{ 1, 7, 9, 2 },
				{ 8, 6, 3, 2 },
				{ 1, 6, 7, 8 },
				{ 2, 9, 8, 2 }
			};

		

			int LowestCostToTravel = LowestCostToTravelDP(src, MAXRow, MAXCol);

			/*
			*    Solution matrix:
					1 8 17 19
					9 14 17 19
					10 16 23 27
					12 21 29 29
			*/
			string path;
			int LowestCostToTravel1 = LowestCostToTravelRecursion(src, 0,0, MAXRow, MAXCol, 0, path);
		}

		int LowestCostToTravelRecursion(int src[MAXRow][MAXCol], int r, int c, int MaxRows, int MaxCols, int lowestCost, string Path)
		{
			
			//caller would have selected this current cell because it is cheaper than other option.
			//Record the path and also cost. 
			lowestCost += src[r][c];
			Path += " ";
			Path += to_string(src[r][c]);

			//right-bottom corner cell so exit with 1
			if ((r == MaxRows - 1) && (c == MaxCols - 1))
			{
				
				cout << endl << "Cost: " << lowestCost << " Path: " << Path << " " << endl;
				return lowestCost;
			}

			

			//Take care of bottom-row and right-column
			if (r == MaxRows - 1)
			{
				//we can only go in right direction
				return LowestCostToTravelRecursion(src, r, c + 1, MaxRows, MaxCols, lowestCost, Path);
			}
			else if (c == MaxCols - 1)
			{
				//we can only go down 
				return LowestCostToTravelRecursion(src,r + 1, c, MaxRows, MaxCols, lowestCost, Path);
			}
			else
			{	//from each cell we can go in 2 direction, select the one with lowest cost
				//RightCell is cheaper than BottomCell to go to bottom cell.
				if (src[r][c+1] < src[r+1][c])
				{
					return LowestCostToTravelRecursion(src, r, c + 1, MaxRows, MaxCols, lowestCost, Path);
				}
				else 
				{	//BottomCell is cheaper so go to Bottom cell
					return LowestCostToTravelRecursion(src, r+1, c, MaxRows, MaxCols, lowestCost, Path);
				}
			}
		}


		int LowestCostToTravelDP(int src[MAXRow][MAXCol], int rows, int cols)
		{
			int LowestCostToTravel = 1;
			int Sol[MAXRow][MAXCol] = {}; //Init whole array to 0s


			  /*We know that DP computes the current cell value(of Solution matrix) based on the values stored in
				previous cells that is Left - Cell and Top cell.

				In this problem we want the path of minimum cost, so DP will select which ever is low
				among TOP and LEFT cell.Then adds the current - scr - cell value to it.
				sol[r][c] = min(sol[r - 1][c], sol[r][c - 1]) + SRC[r][c]);*/
			for (int p = 0; p < rows; p++)
			{
				for (int q = 0; q < cols; q++)
				{
					if ((p == 0) && (q == 0))
					{
						//(DP assumes that in the beginning there is only one cell, and there are no previous cells so select the value from Src[0][0])
						Sol[0][0] = src[p][q];
					}
					else if (p == 0) 
					{
						//Cursor is going along TopRow. History has only LEFT-cell, and we must select it. 
						//DP computes the current cell value(of Solution matrix) based on only the values stored in  adjacent cells that is Left - Cell.
						Sol[p][q] = Sol[p][q - 1] + src[p][q];
					}
					else if ((q == 0) && (p > 0)) //Cursor is going along LeftCol. 
					{
						//Cursor is going along LeftMostColumn. History has only TOP-cell, and we must select it. 
						//DP computes the current cell value(of Solution matrix) based on only the values stored in  TOP cell.
						Sol[p][q] = Sol[p - 1][q] + src[p][q];
					}
					else
					{	//These are internal cells. These cells have TWO history cells. Top-cell and Left-cell
						Sol[p][q] = min(Sol[p - 1][q], Sol[p][q - 1]) + src[p][q];
					}
				}
			}

			//print the matrix
			stringstream ss;
			for (int p = 0; p < rows; p++)
			{
				for (int q = 0; q < cols; q++)
				{
					ss << Sol[p][q] << " ";
				}
				ss << endl;
			}
			//solution matrix
			cout << ss.str();

			LowestCostToTravel = Sol[rows - 1][cols - 1];


			ComputeMinimumLowestPath(Sol, src);
			return LowestCostToTravel;
		}


		string ComputeMinimumLowestPath(int src[MAXRow][MAXCol], int sol[MAXRow][MAXCol])
		{
			string lowestCostElements;
			int r = MAXRow - 1;
			int c = MAXCol - 1;
			while ((r > 0) && (c > 0))
			{
				lowestCostElements += to_string(src[r][c]);
				
				
				if (sol[r - 1] <= sol[c - 1])
				{
					r--;
				}
				else
					c--;
			}

			return lowestCostElements;
		}
		

	};
};
