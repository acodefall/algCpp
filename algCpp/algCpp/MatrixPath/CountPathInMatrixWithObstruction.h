#pragma once
#include <iostream>
#include <sstream>
using namespace std;
namespace CountPathInMatrixWithObstructionNM
{
	/*
		Count the paths in Matrix using DP(Matrix has obstructions_20170701009
			Logic same as counting paths for a matrix without obstructions, only one change is that we building the solution Matrix, refer to SolutionMat to check whether cell has an Obstruction; if there is obstruction, corresponding Solution[] cell should have 0 value. 
			Implementation will have two changes
			-	Function should accept SrcMat[] as parameter so that it can check for obstruction.
			ForLoop responsible for filling solMatrix should check for onstruction, if it is ‘-1’ then set the solMatr[] to 0.
			Once Matrix construction is done total path count will be at
							Sol[rows - 1][cols - 1];
			Complexity is time taken to build solution matrix O(M * N)

	*/		

	const int MAXRow = 5;
	const int MAXCol = 5;
	class CountPathInMatrixWithObstruction
	{
	public:

		int CountPathInMatrixWithObstructionRecursion(int  src[MAXRow][MAXCol], int r, int c, int MaxRows, int MaxCols, int out[MAXRow][MAXCol])
		{
			int left = 0;
			int right = 0;
			if ((r == MaxRows - 1) && (c == MaxCols - 1))
			{
				out[r][c] = 1;
				return 1;
			}
		
			if (src[r][c] == -1)
				return 0;
			
			if (r == MaxRows - 1) //Bottom Row, we can go only in horizontal direction
			{
				//if (src[r][c + 1] != -1) //'recursion exit condition' will make sure c is not over shooting column count
					left = CountPathInMatrixWithObstructionRecursion(src, r, c + 1, MaxRows, MaxCols, out);
				
			}
			else if (c == MaxCols - 1) //Right most column, we can go only go vertically down
			{
				//Path exploration ends if the cell is -1
				// 'recursion exit condition' will make sure r does not overshoot the row count
				//if(src[r+1][c] != -1)
					left = CountPathInMatrixWithObstructionRecursion(src, r + 1, c, MaxRows, MaxCols, out);
			}
			else
			{
				//if (src[r + 1][c] != -1) //Check bottom cell is not -1
					left = CountPathInMatrixWithObstructionRecursion(src, r + 1, c, MaxRows, MaxCols, out);
				//if (src[r][c + 1] != -1) //Check right cell is not -1
					right = CountPathInMatrixWithObstructionRecursion(src, r, c + 1, MaxRows, MaxCols, out);
			}
			
			out[r][c] = right + left;
			return right + left;
		}

		
		int countPathsRecursionDynamic(int src[MAXRow][MAXCol], int rows, int cols)
		{
			int totalPathCount = 1;
			
			int Sol[MAXRow][MAXCol] = {}; //This will initialize the solutionMatrix to 0.

			
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

			//Do no start from root, we all ready know the path count for it
			for (int p = 0; p < rows; p++)
			{
				for (int q = 0; q < cols; q++)
				{
					if (src[p] [q] == -1)
					{
						Sol[p][q] = 0;
					}
					else
					{
						if ((p == 0) && (q == 0))
						{
							//Root has only one path so set it to 1.
							//(DP assumes that in the beginning there is only one cell, and path to thar is 1.)
							Sol[0][0] = 1;
						}
						else if ((p == 0)) //Cursor is going along TopRow. Cells of top row can be approached via the left cell only. So the cells in top row have a path-count of 1
						{
							Sol[p][q] = Sol[p][q - 1];
						}
						else if ((q == 0)) //Cursor is going along LeftCol. 
						{
							Sol[p][q] = Sol[p - 1][q];
						}
						else
						{	//These are internal cells and can be approached from 3-ways
							Sol[p][q] = Sol[p - 1][q] + //coming from TopCell
								Sol[p][q - 1];  // coming from LeftCell
							
						}
					}
				}
			}

			//print the matrix
			//stringstream ss;
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

			int src[MAXRow][MAXCol] =
			{
				{ 0,0,-1,0,0},
				{ 0,0,0,0,0},
				{ 0,-1,0,0,-1},
				{-1,0,0,0,0 },
				{ 0,0,0,0,0 }
			};
		
			int out1[MAXRow][MAXCol] = {};


			int countR = CountPathInMatrixWithObstructionRecursion(src, 0, 0, MAXRow, MAXCol, out1);
			cout << endl << "total number of path using Recursion " << countR << endl;
			//print the matrix
			stringstream ss;
			for (int p = 0; p < MAXRow; p++)
			{
				for (int q = 0; q < MAXCol; q++)
				{
					ss << out1[p][q] << " ";
				}
				ss << endl;
			}

			cout << ss.str();
			
			int count = countPathsRecursionDynamic(src, MAXRow, MAXCol);
			cout << endl << "total number of path using DP " << count << endl;
			
			/* Solution matrix from DP
				1 1 0 0 0
				1 2 2 2 2
				1 0 2 4 0
				0 0 2 6 6
				0 0 2 8 14


				14 7 0 0 0
				7 7 7 2 0
				0 0 5 2 0
				0 0 3 2 1
				0 0 1 1 1
			*/
		}

	
	};
};
