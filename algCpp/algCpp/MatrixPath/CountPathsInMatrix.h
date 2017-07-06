#pragma once
#include <iostream>
#include <sstream>
using namespace std;
namespace CountPathsFromTopCornerToBottomMatrixNM
{
	/*
		Count the Number of paths in Matrix using DP_20170701005
			A cell in a matrix can be reached from Top-cell, Left-cell and Diagonal cell. So for any given cell, Number of Path to reach current cell is sum of path-count for Top-cell, Left-cell and Diagonal cell. This means for computing path count for current cell, we need path count for 3 other neighboring cells. Solution matrix constructed by DP stores path count for every cell.

			When building the solution matrix, DP starts with the assumption that there is only one cell, and computes that path count for it, and that is 1.
			sol[0][0] = 1;

			Then DP introduces more cells in to pool and computes path count for the new cells based on the existing path counts that are already present in solution matrix.

			If the current cell is in Top-Row, then there is only one path to reach that cell, and that path is through the left-neighbor, so path count for curr-cell and ‘immidiate left-neighbour’ same. In fact path count for all the cells of Toprow is same, and that count is 1.
			On the same lines, path count for Left-columns is also 1.

			If the current cell is an internal cell, then there are 3 roads to reach current cell, so number of paths to current cell is sum of path count for Left, Top and Diagonal neighbours.
					sol[r][c] = sol[r-1][c] + sol[r][c-1] + sol[r-1][c-1];
			In this fashion, DP goes on expanding the Sol Matrix till it reaches the dimension of Source Matrix. 
			Runtime is O(M*N) that is equal to the time spent constructing Solution Matrix.

			Takes O(M * N) time


			Solution Matrix for 3 x 3 matrix:
				1 1 1    //but cells of toprow can be approached via the left cell only. So the cells in top row have a value of 1. 
				1 3 5    //3 = 1 + 1 + 1
				1 5 13   //13 = 5 + 5 + 3


		Steps for counting the paths in a matrix using DP_20170701006
			This functions is supposed to compute the solution matrix that holds the path count for every cell of Source matrix. Dimension of soluMatrix is same as that of SrcMtriax
			a) Parameters are RowCount, ColCount. These are dimensions of srcMatrix.
				 To count number of paths all we need is Matrix dimension so do not pass SrcMatrix 
	
			b) Allocate and also initialize the Solution Matrix who's size is same as SrcMatrix
			c) Begin computing path-count by starting two nested ForLoops, they will fill the Solution Matrix with path counts. 
			Index are P and Q.
			d) ForLoop will have IF conditions to check where the CELL is located and appropriately computes Path Count by applying following rules.
			-Root Cell's path count is hard coded to 1; 
			-Top-row’s path count is same as left neighbour 
			-Left-Column’s path count is same as Top neighbour. This is because approach road to current cell is same as that of neighbor.
					   -Internal cell path count is sum of path count of all the 3 neighbors.

				if ((p == 0) && (q == 0)) //It is root, then path count is 1
					set sol[p,q] = 1; 
				else if ((p == 0)) //Cursor is going along TopRow, value is same as "left neigbour"
					Sol[p][q] = Sol[p][q - 1];
				else if ((q == 0)) //Cursor is going along LeftCol, value is same as "top neigbour"
					Sol[p][q] = Sol[p - 1][q];
				else
				{	//These are internal cells and can be approached from 3-ways
					Sol[p][q] = Sol[p - 1][q] + //coming from TopCell
					Sol[p][q - 1];  // coming from LeftCell
				}
			e) Once the Solution Matrix is constructed, total path count will be at
				Sol[rows - 1][cols - 1];
			f) Complexity is time taken to build solution matrix O(M * N)


		Counting paths in Matrix using Recursion_20170701007
			As we navigate from Root to Bottom corner, cursor comes to the FORK that has 3 roads; that pass through RIGHT, BOTTOM and DIAG cell. Since we are counting the paths, we enter each one of the FORK, by making recursion call. All these recursions eventually come to Bottom-corner and recursion breaks there by returning 1. 

			Return value of 1 is saying that “the path that just ended is to be counted as 1”. Caller receives such return values from Left, Right and Diagonal recursions;and caller adds all the return values, and returns it to its caller. Addition code is part of Post-Recursion code. Eventually Top most caller gets the total number of paths. Important points are Recursion call is made to every neighbor. Every path will reach Corner-cell and comes back to the caller with value of 1. Post recursion code is responsible for summing up the return values.

		Steps for Counting paths in Matrix using Recursion_20170701008
			This functions is supposed to compute path count for solution matrix.
			a) Parameters are RowCount, ColCount. These are dimensions of srcMatrix.
			b) Check if current cell is right-bottom corner cell, if so return 1
				if ((r == MaxRows - 1) && (c == MaxCols - 1))
					return 1;
			
			Check if current cell is at bottom-row, then make only one recursion call that is to Right-neighbour
				if (r == MaxRows - 1)
				{
					return countPathsRecursion(r, c + 1, MaxRows, MaxCols);
				}
			Check if current cell is at right-column, then make only one recursion call that is to Bottom-neighbour
				   if (c == MaxCols - 1)
				{
							//we can only go down 
					return countPathsRecursion(r + 1, c, MaxRows, MaxCols);
				}
			Check if the current cell is an internal cell, then make 3 recrsuion calls. Here there is post-recursion processing, Add the return values of all the 3 recursions and return to caller.
				{	//from each cell we can go in 3 direction
					//from each cell we can go in 3 direction
					int bottom = countPathsRecursion(r + 1, c, MaxRows, MaxCols);  //accounts for BOTTOM
					int right = countPathsRecursion(r, c + 1, MaxRows, MaxCols); //accounts for RIGHT
					int diagonal = countPathsRecursion(r + 1, c + 1, MaxRows, MaxCols); //accounts for diagonal 

					return bottom + right + diagonal;
				}
			e) Once recursion is complete, total path count will be returned to caller
			f) Complexity is time taken to build solution matrix O(2 ^ N)


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
				//from each cell we can go in 3 direction
				int bottom = countPathsRecursion(r + 1, c, MaxRows, MaxCols);  //accounts for BOTTOM
				int right = countPathsRecursion(r, c + 1, MaxRows, MaxCols); //accounts for RIGHT
				int diagonal = countPathsRecursion(r + 1, c + 1, MaxRows, MaxCols); //accounts for diagonal 

				return bottom + right + diagonal;
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