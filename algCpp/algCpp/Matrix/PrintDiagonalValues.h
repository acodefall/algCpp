#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;




namespace PrintDiagonalValuesNM
{

	/* 
		Print matrix diagonally
			To visualize the diagonal print out of Matrix, imagine arrows 
			-starting from cells of Left-column and going up to top row.
			 Imagine a L made up of Left-column and Top-row
			 Cells along these diagonal line should be printed on a single LINE.
			 Ex: Root cell will appear in its own line
			 What is explained is Upper row
	 
			-starts from Bottom-row and goes up to Right-most-column.
			 Cells along these diagonal line should be printed on a single LINE.
			 What is explained is Upper row

			Note: Two traingles share common line and it runs through origin(where X & Y axes) meet. Print this line only once
			
	
	//@GN68 Matrix_010_Print diagonal lines_GN68
	//@GN68 Matrix_012_Steps Print diagonal lines_GN68


	Print diagonal lines_GN68
	Divide the matrix in to upper and lower triangles.

	To print upper triangle, from the top row, drop to, say 2ndrow, and then travel UP and RIGHT till the 0th row. This will take us along a diagonal line. Then drop to 3rd row,and then go UP and RIGHT. Do this until we cover all the rows.

	To print the lower triangle, go to 1st-col, and from there travel UP and RIGHT, till MAX-Column. This will take us along a diagonal line. Then go to 2nd-col, and then go UP and RIGHT. Do this until for each column.

	Steps Print diagonal lines_GN68
	To print the upper-triangle, start a WHILE( currRow = 0; currRow == MAXRow)
	-Declare TempRow and assign (TempRow = currRow )
	-Start inner WHILE( TempRow; TempRow < 0).
	-Inside the while loop Increment Col and decrement TempRow
	-Print the cell values

	To print lower-triangle, start a WHILE(currCol = 0; currCol == MAXCol)
	-Declare TempCol and assign (TempCol = currCol )
	Start inner WHILE(TempCol = Col; TempCol < MAXCol).
	-In the inner while loop Increment the column and decrement the row
	-Print the cell values
	*/

	const int MAXRow = 4;
	const int MAXCol = 4;
	class PrintDiagonalValues
	{
	

		public:
		void callPrintDiagonals()
		{
			int Src[MAXRow][MAXCol] = 
			{
				{ 1,2,3,4 },
				{ 5,6,7,8 },
				{ 9,10,11,12 },
				{ 13,14,15,16 }
			};



		
			
			PrintDiagonalsX(Src);

			/*
			
			input:
					 1  2  3  4
					 5  6  7  8
					 9 10 11 12
					13 14 15 16


			Diagonal output:
								  1
								  5  2
								  9  6  3
								 13 10  7  4

								   13   10    7    4
								   14   11    8
								   15   12
								   16
				
			
			
			*/
		}

		void PrintDiagonalsX(int src[MAXRow][MAXCol])
		{
			stringstream ss;
			cout << endl << "src : " << endl;
			for (int p = 0; p < MAXRow; p++)
			{
				for (int q = 0; q < MAXCol; q++)
				{
					ss << setw(2) << src[p][q] << " ";
				}
				ss << endl;
			}
			cout << ss.str();
			ss << endl;

			//Print UPPER traingle
			int rowIndex = 0;
			while (rowIndex < MAXRow)
			{
				int colTemp = 0;
				int rowTemp = rowIndex; //Since this is intialized to INDEX
				while (rowTemp >= 0) //condition is (>=)
				{
					cout <<" " << setw(2) << src[rowTemp--][colTemp++];
				}
				cout << endl;
				rowIndex++;
			}

			cout << endl;
			//PrintLOWER triangle.
			int colIndex = 0;
			while (colIndex < MAXCol)
			{
				int colTemp = colIndex;
				int rowTemp = MAXRow - 1;
				while (colTemp < MAXCol)
				{
					cout <<" " << setw(4) << src[rowTemp--][colTemp++];
				}
				colIndex++;
				cout << endl;
			}


		}
	};
};
