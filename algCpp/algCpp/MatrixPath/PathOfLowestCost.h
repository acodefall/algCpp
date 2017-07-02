#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
namespace PathOfLowestCostNM
{
	//Go fr http://algorithms.tutorialhorizon.com/dynamic-programming-minimum-cost-path-problem/
	/*
	* //@GN58 Matrix_014_Minimum Cost Path Problem using Dynamic Programming_GN57
	* //@GN57 Matrix_016_Steps Minimum Cost Path Problem using Dynamic Programming_GN57

	Minimum Cost Path Problem using Dynamic Programming_GN57
	-We have a 2D-matrix where each cell has a cost to travel.
	Find a path from Top-left to Bottom-right corner, who's sum is lowest.
	You can move only right or down.
	Recursion approach takes O(2^n) and Dynamic version takes O(N ^ 2)

	Compute path of lowest cost using DP method 
		We know that DP computes the current cell value(of Solution matrix) based on the values stored in
		previous cells that is Left-Cell and Top cell.
		In this problem we want the path of minimum cost, so DP will select which ever is low
		among TOP and LEFT cell. Then adds the current-scr-cell value to it.
		sol[r][c] = min(sol[r-1][c], sol[r][c-1]) + SRC[r][c]);

		Top-row and Left-most column are special cases.
		DP computes the current cell value(of Solution matrix) based on only the values stored in
		adjacent cells that is Left-Cell.
		//Top row
		sol[r][c] = sol[r][c-1] + SRC[r][c];

		//Left-most column
		sol[r][c] = sol[r-1][c] + SRC[r][c];
		For the Root cell of solution matrix has no previous cell so it selects the
		//Root cell
		sol[0][0] = SRC[0][0]
		Takes O(M * N) time

	Compute the path of lowest cost using Recursion method 
		In case of recursion, the logic has to select the lowest valued cell among the cells that are ahead of it. That is select lowest among Right and Bottom cell.
		Then make a recursion call to it. If you compare DP and Recursion logics, DP selects lowest among past cells(already traversed), Recursion selects lowest among future cells(yet to traverse). 
		One of the recursion parameter will be Lowestcost and Path. In every round update them with current cell value.
		By the time cursor reaches the bottom-right cell we will have the lowest value.
		No activity happens in post recursion stage.
		Takes O(N ^2) time

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

			//int y = costX(A, 0, 0, 0, x);

			//int LowestCostToTravel = LowestCostToTravelDP(src, MAXRow, MAXCol);

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
			
			//right-bottom corner cell so exit with 1
			if ((r == MaxRows - 1) && (c == MaxCols - 1))
			{
				
				lowestCost += src[r][c];
				cout << endl << "Cost: " << lowestCost << " Path: " << Path << " " << endl;
				return lowestCost;
			}

			//caller would have selected this current cell because it is cheaper than other option.
			//Record the path and also cost. 
			lowestCost += src[r][c];
			Path += " ";
			Path += to_string(src[r][c]);

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
