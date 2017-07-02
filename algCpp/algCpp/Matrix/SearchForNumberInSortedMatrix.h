
#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
namespace SearchForNumberInSortedMatrixNM
{
    /*
        Searching inside sorted Matrix_20170629035
		Searching inside sorted Matrix_GN214 
	        Sorted Matrix looks like sorted multi-column table. Coming down and going right will increase the value.
            To find the number, start iterating from Bottom-Left corner. Compare the Target value and Current cell's value.
	        If Target value is HIGHER than current-cell’s value, then go-UP because lower values will be above the current cell.
	        If Target value is LOWER than current-cell’s value, then go-RIGHT because higher values will be to the right of current cell.

	       
            Step for Searching inside sorted Matrix_GN214
                a) Function's parameter are int[] and the Value to be searched.
                b) Declare col and row variables, and initialize row for MaxRow - 1, and col for 0.
                c) Start a While loop to iterate the Matrix from Bottom-left corner. Condition is TRUE
                d) Check if the src[row,col] is the VALUE, if so BREAK the loop.
                e) if ( Value < src[row,col]), we need still LOWER value, so go UP by doing "ROW--" 
                f) else if ( Value > src[row,col]), we need still HIGHER value, so go to RIGHT by doing "COL++" 
                g) Since we going towards Top-Right corner, check 
                    if (Row == 0) AND (Col == Max - 1)
                   If both the conditions are TRUE, then break while-loop.
                   We could not locate the VALUE being sought.
     */
	 
	const int MAXRow = 5;
	const int MAXCol = 4;
    class SearchForNumberInSortedMatrix
    {
		public:
		void callSearchForNumberInSortedMatrix()
        {
			int src[MAXRow][MAXCol] =
			{
				{ 1, 2, 3, 4},
				{ 6, 7, 8, 9},
				{ 13, 14, 15, 16},
				{17, 18, 19, 20 },
				{ 22, 23, 24, 26 }
			};
		
		    searchInMatrix(src, 8, MAXRow,MAXCol);
        }

        int searchInMatrix(int Src[MAXRow][MAXCol], int value, int MaxRows, int MaxCols)
        {
            int ret = -1;

            //Start scanning from Bottom-left corner
            int row = MaxRows - 1;
            int col = 0 ;

            int row1 = 0;
            int col1 = 0;

            //Mtrix is arranged like 
            while(true)
            {
                //found the value;
                if(Src[row][col] == value)
                {
                    ret = 0;
                    break;
                }
                else if(value < Src[row][col]) //To get the lower value go UP (imagine Matrix as Ascending-Table)
                {
                    row--;
                }
                else  //To reach higher value go right.
                {
                    col++;
                }

                if((col == MaxCols -1) && (row == 0))
                {
                    ret = -1;
                    break;
                }
            }
            return ret;
        }
	};
};
