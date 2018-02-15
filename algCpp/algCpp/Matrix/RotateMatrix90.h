#pragma once
#include <iostream>

using namespace std;

/*
	Rotate the Matrix by 90degree_RED20180209001
		After 90degree rotation top-row should become Right-column.
		Solution is Apply Transpose and then swap the columns on left-side with the columns on right-side.
		Ex: left-most column will become right-most column.

		Transpose means, folding the matrix along the diagonals.
		That is exchanging values between mirroring cells. (x,y) ===> (y,x)

		Iterate the array using two far-loops, and exchange the the number between mirror cells,
		ONLY when the cursor is ABOVE the diagonal line (means (i > j).
		In the end number of exchanges will be equal to number of cells.

		For exchanging columns, Iterate the array using two far-loops, and exchange values only when cursor 
		is at left-half. Exchange 0th column with MaxColumn; 1st column with 'Max-1' column.
		[i,j] gives left-side cell and [MxCol-j] gives right-side cell.
		Exchange values only when (colIndex < maxCol/2)
*/

namespace RotateMatrix90NM
{
	const int RM = 5;
	const int CM = 5;
	class RotateMatrix
	{
			public:

				void rotate()
				{
					int mat[RM][CM];

					//create matrix
					int start = 10;
					for (int i = 0; i < RM; i++)
					{
						for (int j = 0; j < CM; j++)
						{
							mat[i][j] = start++;
						}
					}

					//print 
					print(mat, RM, CM);

					/*
						Original						
							10   11   12   13   14
							15   16   17   18   19
							20   21   22   23   24
							25   26   27   28   29
							30   31   32   33   34

						Transpose
							10   15   20   25   30
							11   16   21   26   31
							12   17   22   27   32
							13   18   23   28   33
							14   19   24   29   34

						Transpose Reversed
							30   25   20   15   10
							31   26   21   16   11
							32   27   22   17   12
							33   28   23   18   13
							34   29   24   19   14
					*/


					transpose(mat, CM, RM);
					print(mat, CM, RM);

					reverseColumn(mat, CM, RM);
					print(mat, CM, RM);


				}

				void print(int mat[RM][CM], int r, int c)
				{
					cout << "matrix" << endl;
					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							cout << mat[i][j] << "   ";
						}
						cout << endl;
					}
				}


				/*
					Transpose means, folding the matrix along the diagonals.
					That is exchanging values between mirroring cells. (x,y) ===> (y,x)

					Iterate the array using two far-loops, and exchange the the number between mirror cells,
					ONLY when the cursor is ABOVE the diagonal line (means (i > j).
					In the end number of exchanges will be equal to number of cells.
				*/
				void transpose(int  mat[RM][CM], int r, int c)
				{
					for (int i = 0; i < r; i++)
					{
						for(int j = 0; j < c; j++)
						{
							//Cursor is ABOVE the diagonal line, try to exchange cell value
							//between MIRROR cells
							if (i > j)
							{ 
								int tmp = mat[i][j];
								mat[i][j] = mat[j][i];
								mat[j][i] = tmp;
							}
						}
					}
				}

				//Reverse the columns
				void reverseColumn(int  mat[RM][CM], int r, int c)
				{

					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							//(colIndex < maxCol/2)
							if (j < c/2)
							{
								int tmp = mat[i][j];
								mat[i][j] = mat[i][(c - 1) -j];
								mat[i][(c - 1) - j] = tmp;
							}
						}
						cout << endl;
					}


				}

	};
};