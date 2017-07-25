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
namespace PrintPathsOfMatrixNM //@RED20170701018
{
    /*
		Steps for Printing all the paths of Matrix_20170701018
			Refer to the problem of computing number of paths. Then modify the following
			-	Recursion function carries a Path Variable, and function should record the current cell’s value in Path Variable.
			When recursion breaks, Path variable will have the complete path starting from Root. 
			When cursor is at the FORK, we make recursion call to every possible option(right/bottom/diagonal); because of this every path will end up reaching Bottom-Right corner cell, and there we will print the value held in Path .

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
