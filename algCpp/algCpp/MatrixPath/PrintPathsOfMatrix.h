#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
#include <string>
namespace PrintPathsOfMatrixNM
{
    /*
		Printing paths of a Matrix using recursion
			Starting from root, navigate to bottom-right cell, and record the cells as you visit every cell.
			Path recording is done as part pre-recursion code. We will have the whole path when recursion breaks.
			Recursion breaks when we reach the bottom-right cell.
			From every cell we can go down by taking any of the 3 paths, through left-cell, right-cell and diagonal cell.
			And we have to explore all the three of them so from every cell we launche 3 recursions. 
			Recursion function record the cell as part of Pre recursion. 
			There is Post-recursion code.
			When recursion breaks we will have the result, we can print it and be done with it. 
		
		
	*/
	
	/* //@GN60 Matrix_018_Print All paths from Top-left corner to bottom-right corner of a Matrix Recursion_GN60
     * //@GN60 Matrix_020_Step Print All paths from Top-left corner to bottom-right corner of a Matrix Recursion_GN60
     * //@GN60 Matrix_022_Print All paths from Top-left corner to bottom-right corner of a Matrix Recursion  Diagonal_GN60
     Print All paths from Top-left corner to bottom-right corner of a Matrix Recursion_GN60
             Allows for only RIGHT and BOTTOM turns
             (Recursion)
             EX; For path is L-shaped path.
             From each cell, cursor could go either to Right or Bottom.
             Say cursor goes to Right-cell, from there, it can turn to Right or Bottom.So we need two recursion calls. 
                     Recursion will have RowIndex, ColIndex and a Path variable to record CELL-value.
             Cursor stops turning to Right(means recursion breaks), once ColIndex reaches MAXCOL. 
             Similarly, Cursor stops trurning to Bottom, once RowIndex reaches MAXROW. 
             For Bottom-turn recursion=call pass RowIndex+1, and unchanged ColIndex.
             For Right-turn recursion-call, pass unchanged RowIndex, and incremented ColIndex.
             Break the recursion when either (RowIndex = MAXROW - 1) or  (ColIndex = MAXCOL - 1).
             When recursion breaks print, if it is MAXROW(Bottom Row), we need to go to MAXCOL(Right-Most Column), 
                      and record the cell-values along the way, so start a For-Loop to record Nodes from ColIndex to MAXCOL, in Path
                     Variable.Then print the Path variable. 
                     Similarly, handle the MAXCOL case.

     Step Print All paths from Top-left corner to bottom-right corner of a Matrix Recursion_GN60
             Allows for only RIGHT and BOTTOM turns
             -Have recursion function with SrcMatrix, RowIndex, ColIndex and a Path variable as parameter.
             -Inside (RowIndex == MAXROW - 1), start another for-loop to go from ColIndex to MAXCOL. And record the cell-value in Path variable.
              Then print the PATH variable and RETURN. Now recursion ends for that path.
             - (ColIndex == MAXCOL - 1), start another for-loop to go from RowIndex to MAXROW. And record the cell-value path in Path variable.
              Then print the PATH variable and RETURN. Now recursion ends for that path.
             -If we did not reach MAX indexes, set "Path = SrcMatrix[ RowIndex, ColIndex]"
             -Then call Bottom-recursion with RowIndex+1, and unchanged ColIndex.
             -Then call Right-recursion also.
 */
	const int MAXRow = 3;
	const int MAXCol = 3;
    class PrintPathsOfMatrix
    {

        int printAllPathsRecursion(int src[MAXRow][MAXCol], int r, int c, int rowCount, int colCount, string& path)
        {
            if ((r == (rowCount - 1)) && (c == (colCount - 1)))
            {
                cout << endl << path.c_str() << endl; 
                return 0;
            }
          


            path += " ";
            path += to_string(src[r][c]);

            
			if(c == (colCount - 1))
			{	//cursor is in Last column,  and cursor can only go along Row-wise.
				//Keep the row constant
				printAllPathsRecursion(src, r + 1, c,  rowCount, colCount, path);
			}
			else if (r == (rowCount - 1))
			{
				//cursor is in bottom row, and cursor can only go along Column-wise
				//Keep the Row constant
				printAllPathsRecursion(src, r, c+1,   rowCount, colCount, path);
			}
			else
			{
				//These are needed if we travel ONLY   BOTTOM and RIGHT
				printAllPathsRecursion(src, r + 1, c,   rowCount, colCount, path);
				printAllPathsRecursion(src, r,  c + 1,   rowCount, colCount, path);

				//Include this if you need DIAGONAL also
				printAllPathsRecursion(src, r + 1, c + 1,  rowCount, colCount, path);
			}
				
          

            return 0;
        }

		public:
			void callCountPathsinMatrx()
			{
				int Src[MAXRow][MAXCol] = 
				{
					{1,2,3},
					{4,5,6},
					{7,8,9}
				};

				string Path;
          
				cout << endl << "Print matrix paths using Recursion" << endl;
				printAllPathsRecursion(Src, 0, 0, MAXRow, MAXCol, Path);

				/*   When travelling RIGHT & BOTTOM
						 1 4 7 8 9
						 1 4 5 8 9
						 1 4 5 6 9
						 1 2 5 8 9
						 1 2 5 6 9
						 1 2 3 6 9
             
				 * 
				 *  When travelling RIGHT & BOTTOM & DIAGONAL
						 1 4 7 8 9
						 1 4 5 8 9
						 1 4 5 6 9
						 1 2 5 8 9
						 1 2 5 6 9
						 1 2 3 6 9

						 1 4 5 9
						 1 4 8 9
						 1 2 5 9

						 1 2 6 9
						 1 5 8 9
						 1 5 6 9
						 1 5 9
				 * 
				 */
			}
       
	};
};
