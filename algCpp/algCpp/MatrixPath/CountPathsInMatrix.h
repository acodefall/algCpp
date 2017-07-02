#pragma once
#include <iostream>
#include <sstream>
using namespace std;
namespace CountPathsFromTopCornerToBottomMatrixNM
{
	/*
		Count the paths in Matrix using DP_20170629031
			Core logic is as follows. Say A, B and C are connected, in such a way that C can be reached ONLY through either A or B,
			In that case we can say “Number of Paths To C" = " Number of  Paths To A" + " Number of Paths To B"
			To compute Number of path to a cell in matrix apply same theory.

			Number of Path to a cell = Number of Path to reach topCell + Number of Path to reach left-Cell + Number of Path to reach DiagonalCell
			For this equation to be true, top/left/diagonal cells should hold total number of paths to reach them.
			Basically we have to build a solution matrix where every cell holds total number of paths to reach it.
			When building the solution matrix, start with the assumption that there is only one cell, and its path count will be 1. Then add 3-more cells, 
			to form a square; and compute the paths-count for each of the newly added cell, based on the path-count held by lone-cell that existed previously. 
			Go on expanding the Matrix in this fashion till it reaches the dimension of Source Matrix. For every cell compute the path-count by adding the count of
			top/left/diagonal cells, except the Cells of top-row.
			Cells of top-row can not be approached from TOP or DIAGONAL; they can be approached via the left-cell. So the Path count for cells of top row is 1. Same applies to the cell left-most-column.

			Here are some of the special observations that our code should handle.:
			- Path count for root cell is 1, 	so set [0,0] =1.
			-Internal cells can be reached from 3 other cells: top/left/diagonal
			-Program does not need whole matrix as input; all it needs is row and column count
	
			Runtime is O(M*N) that is equal to the time spent constructing Solution Matrix.
	*/

	const int MAXRow = 3;
	const int MAXCol = 3;
	class CountPathsFromTopCornerToBottomMatrix
	{
	public:
	
		int countPathsRecursion(int r, int c, int MaxRows, int MaxCols)
		{
			//right-bottom corner cell so exit with 1
			if ((r == MaxRows - 1) && (c == MaxCols - 1))
				return 1;
			

			//Take care of bottom-row and right-column
			if (r == MaxRows - 1)
			{
				//we can only in left direction
				return countPathsRecursion(r, c + 1, MaxRows, MaxCols);
			}
			else if (c == MaxCols - 1)
			{
				//we can only go down 
				return countPathsRecursion(r + 1, c, MaxRows, MaxCols);
			}
			else
			{	//from each cell we can go in 3 direction
				return (countPathsRecursion(r + 1, c, MaxRows, MaxCols) +  //accounts for BOTTOM
					countPathsRecursion(r, c + 1, MaxRows, MaxCols) +  //accounts for RIGHT
					countPathsRecursion(r + 1, c + 1, MaxRows, MaxCols)); //accounts for diagonal 
			}
		}

		
		int countPathsRecursionDynamic(int rows, int cols)
		{
			int totalPathCount = 1;
			int Sol[MAXRow][MAXCol] = {}; //Init whole array to 0s
			

			//Do no start from root, we all ready know the path count for it
			for (int p = 0; p < rows; p++)
			{
				for (int q = 0; q < cols; q++)
				{
					if ((p == 0) && (q ==0))
					{
						//Root has only one path so set it to 1.
						//(DP assumes that in the beginning there is only one cell, and path to thar is 1.)
						Sol[0][0] = 1;
					}
					else if ((p == 0) && (q > 0)) //Cursor is going along TopRow. Cells of top row can be approached via the left cell only. So the cells in top row have a path-count of 1
					{
						Sol[p][q] = Sol[0][ q - 1];
					}
					else if ((q == 0) && (p > 0)) //Cursor is going along LeftCol. 
					{
						Sol[p][ q] = Sol[p-1][ 0];
					}
					else
					{	//These are internal cells and can be approached from 3-ways
						Sol[p][ q] = Sol[p - 1][ q] + //coming from TopCell
							Sol[p][ q - 1] +    //coming from LeftCell
							Sol[p - 1][ q - 1]; //coming from Diagonal cell
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

			totalPathCount = Sol[rows - 1][cols - 1];
			return totalPathCount;
		}


		void CallCountPathsFromTopCornerToBottomMatrix()
		{

			int count = countPathsRecursion(0,0, MAXRow, MAXCol); //13
			cout << endl << "total number of path using Recursion " << count << endl;
			count = countPathsRecursionDynamic(MAXRow,MAXCol); //13
			cout << endl << "total number of path using DP " << count << endl;
				/* Solution matrix
				1 1 1
				1 3 5
				1 5 13
			*/
			
		}
	};
};