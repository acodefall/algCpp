#pragma once
#include <map>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

/*
	Printing of Matrix in Circles
	-----------------------------

a) This will have two functions Main() and Print(); Main() invokes Print(), once for printing every concentric circle. 
   Main() will pass parameters to Print() and they include the origin and row-width and column-height. 
   For printing outer-most path, origin will be (0,0); and 
   row-width and column-height will be the soure-matrix-width and soure-matrix-height.
   Print() will start printing at (0,0) and stops right below the origin at (1,0). 
   Finally Print() retuns to Main(), after the printing one circle.
   
   
   Then Main() calls the Print() again, for printing 2nd-most circle, this time origin will be (1,1), and row-width and column-height will be reduced by 2.
   So origin will go down diagonally. 
   
   Main will keep track of the number of cells printed, once it reaches ("soure-matrix-width ** soure-matrix-height"), Main() will stop calling Print().
   Print() will be passed outPut[] and outPutIndex; and  outPutIndex should be < "soure-matrix-width ** soure-matrix-height".
   
   
b) Inside print(), there will be a For-Loop that goes for 4 rounds. ForLoop contains four IF-conditions and each will have a while-loop, for printing each side.
   While-loop goes until either rowCount or columnCount. 
  
   1st round will be handled by first-IF-condition, and it will print all of the columns of the Top-most row. 
   While loop goes until ('ccount'). After coming out of While-loop, IF-condition will do (R + 1) so the cursor turns to downward path.
   
   2nd round will be handled by second-IF-condition, and it will print everything in the Right-side-column except the top-row; this is because 1st 
   round would have printed it. This is why the while loop goes until ('rcount - 1').
   After coming out of While-loop, IF-condition will do (C - 1) so the cursor makes left-turn.

   Similarly, 3rd round will print the bottom row.  While loop goes until ('ccount - 1').
   
   4th round will print the Left-side-column; This side prints everything that is in between the bottom and bottom rows. 
   This is why the while loop goes until ('rcount - 2').
   
   Print() exits after printing the 4th side.

*/
namespace MatrixRotateNm
{
	const int MAXRow = 4;
	const int MAXCol = 4;
	class MatrixInCircle
	{
		public:
				void callMatrixInCircle()
				{
					int c = 0;
					int r = 0;
					
						int src[MAXRow][MAXCol] = {
							{ 1, 7, 9, 2 },
							{ 8, 6, 3, 2 },
							{ 1, 6, 7, 8 },
							{ 2, 9, 8, 2 }
						};
					

					//Print the Matrix content
					for (int m = 0; m < MAXRow; m++)
					{
						for (int n = 0; n < MAXCol; n++)
						{
							cout << src[m][n] << " ";
						}

						cout << "\r\n";
					}
					cout << "\r\n";
					cout << "\r\n";

					int rc = MAXRow;
					int cc = MAXCol;
					int sides = 0;
					int TotalOutput = MAXRow*MAXCol;
					int* out = new int[TotalOutput];
					int  outIndex = 0;



					while (outIndex < TotalOutput)
					{
						PrintOneRound(src, r, c, rc, cc, out, outIndex);

						//Before every new cycle begins, Move the origin diagonally by 1.
						r++;
						c++;

						//For every round Reduce the cell-count by 2
						if (rc > 1)
							rc = rc - 2;
						else if (rc > 0)
							rc = rc - 1;
						else
							break;

						if (cc > 1)
							cc = cc - 2;
						else if (cc > 0)
							cc = cc - 1;
						else
							break;
					}

					cout << "printing values \r\n";
					for (int m = 0; m < TotalOutput; m++)
					{
						cout << out[m] << " ";
					}

					if (src)
					{
						for (int m = 0; m < MAXRow; m++)
						{
							if (src[m])
							{
								delete[] src[m];
							}
						}
						delete[] src;
					}
				}

				void PrintOneRound(int src[MAXRow][MAXCol], int r, int c, int rcount, int ccount, int* out, int& outidx)
				{
					cout << "\r\n";
					for (int sides = 0; sides < 4; sides++)
					{
						int k = 1;
						if (sides == 0) //Top-Most row. Prints ALL Columns of Top-Row
						{
							while (k <= ccount)
							{
								out[outidx++] = src[r][c++];
								k++;
							}
							r = r + 1;
							c = c - 1;
						}
						else if (sides == 1) //Left column. Prints everything in Left column except the top-row, so 'rcount - 1'
						{
							while (k <= rcount - 1)
							{
								out[outidx++] = src[r++][c];
								k++;
							}
							r = r - 1;
							c = c - 1;
						}
						else if (sides == 2) //Bottom-row. Prints everything in bottom-row except the left-column, so 'ccount - 1'
						{
							while (k <= ccount - 1)
							{
								out[outidx++] = src[r][c--];
								k++;
							}
							r = r - 1;
							c = c + 1;
						}
						else if (sides == 3) //Right-column. Prints right-column in between top-row and bottom-row, so 'ccount - 2'
						{
							while (k <= rcount - 2)
							{
								out[outidx++] = src[r--][c];
								k++;
							}
						}
					}
				}

				
	};
};