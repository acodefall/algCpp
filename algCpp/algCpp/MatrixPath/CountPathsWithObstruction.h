using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CountPathsWithObstructionNM
{
    /*
     //@GN69  Matrix_032_Count the Matrix Paths with Obstruction_GN69
     //@GN69  Matrix_034_Step Count the Matrix Paths with Obstruction_GN69
     
     Count the Matrix Paths with Obstruction_GN69
        Count the Paths is a matrix that do not have obstruction (Obstructions means cell with value -1)
        Solution is very close to Counting the paths in a matrix. 
        Main difference is, we should stop making recursion calls if the next-cell-value has -1.(this is the cell who's cordinate is passed through recursion)
        If the next-cell-value is -1, then exit and return the sum of the return values of Recursion functions.
 
        If the next-cell-value is not -1,  let the recursion go until cursor gooes to MAX-ROW and MAX-COL Then only break the 
         recursion, and return 1 to caller. ONE signifies as one path.
        
        In the example of 'counting path', we use OR condition, to check whether the cursor reached either bottom-row OR Right-most col. That is because we assume that if the cursor reaches the bottom-row, it will eventually travel to bottom-right corner. But in this case, we can not make such assumption because the bottom row could have -1, and that will prevent from cursor going to bottom-right corner.
       
     Step Count the Matrix Paths with Obstruction_GN69
        -Have a recursion function with Src[], row and col as parameters. Returns 1
        -Inside the function, check for both RowMAX and ColMAX using AND, and return 1.
        -If RowMax and ColMax is not reached, make recursion calls.
		        -
        -Before making Bottom-recursion call, we have to check whether check [row+1, col] is not -1, then only make recursion call. Since we are reading the NEXT cell, we also have to check array-boundary. If we are doing row+1, then check for Row-boundary.
        Then collect the return value.
		
	        IF( row != (Src.GetLength(0)  -1) && Src[row+1, col]!=-1)
             	        left = count(Src, row+1, col);
         Similarly make Right-recursion call.
       
         -Finally return the sum of the values returned by both the recursions.

     */
    class CountPathsWithObstruction
    {
        public:
				int pathWithObtruction( int** src, int row, int col, int MaxRow, int MaxCol)
				{
					if ((row == MaxRow -1 ) && (col == MaxCol))
						return 1;

					int left = 0;
					int right = 0;
					if ((row != MaxRow - 1) && (src[row + 1][col] != -1))
						left = pathWithObtruction(src, row + 1, col, MaxRow, MaxCol);

					if ((col != src.GetLength(1) - 1) && (src[row][ col + 1] != -1))
						right = pathWithObtruction(src, row, col + 1, MaxRow, MaxCol);

					return right + left;
				}

				public void callCountPathsWithObstruction()
				{
					int[,] arrA = new int[3, 3] { { 1, 1, 1 }, { 1, -1, 1 }, { 1, -1, 1 } };
					int y = pathWithObtruction(arrA, 0, 0);
				}
    }
}
