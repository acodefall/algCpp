#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include <sstream>
using namespace std;

/*
	General_1212_Binary search inside rotated sorted Array_RED20170907005
		Rotated will have min and max elements at the middle of the array.
		This does not suite the BIN searh logic, because trad bin-search expect lowest and highest values to be at src[0] and src[max].
		We can view Rototated array as having two segments.
		As usual Bin search will use real physical index as max index, and computes the Midindex,
		creates left and right parts. 
		Now there are 3 possibilities.
		Left part may match width of left-rorated array; and right part may match width of right-rorated array.
		Other possibility is one of the part is within one of the rotated array; go in to that part.
		If left-part is within left-rorated array, then go inside that.
		If src[L] < src[M] then, left-part is within left-rorated array.
		Once inside left segment.
		If src[m] == V, we found teh value exit.
		If V  is between L & M, make a rec call to L & M-1
		Else make a rec call to M+1 & H.
			If src[L] < src[M]. then left-side is continuous so go to left-half
			If src[H]  > src[H]. then Right-side is continuous so go to right-half.
						
		
	     Steps for Binary search inside rotated sorted Array_GN814
		        1) Recursion parameters are Src[] and V
		        2) Declare L and H.
		        3) Start a While-loop to go as long as ( L <= H)
		        4) Compute M
		        5) if(Src[M] == V)
				        Break. We found the value
		        6) Else
			        Check which segment is complete
			        if(src[L] < src[M])
				        Left-segment is complete. Now compare the V and adjust H & L.
				        if(V is within src[L] & src[M])
					        H = M - 1;
				        else 
					        L = M + 1;
			        else
				        Right-segment is within right-sorted array. 
				        if(V is within src[M] & src[H]) //NOTE: we check whether the value is in between M & H, instead of checking it is greate than M. We go in to the side that is continuous and check if the 
																value is in between two contunuous points.
					        L = M + 1;
				        else 
					        H = M - 1;

*/
namespace BinarySearchInRotatedArrayNM //@RED20170907005
{
	const int SIZEX = 7;
	class BinarySearchInRotatedArray
	{
	public:
		void callBinarySearchInRotatedArray()
		{
			int src[SIZEX] = { 4,5,6,7,0,1,2 }; // {4 5 6 7} {0 1 2}
			stringstream ss;
			cout << "src " << endl;
			for (int i = 0; i < SIZEX; i++)
			{
				cout << setw(4) << src[i];
				ss << setw(4) << i;
			}
			cout << endl;
			cout << ss.str() << endl;


			int x = BinarySearchInRotatedArrayX(src, 1);
		}

		int BinarySearchInRotatedArrayX(int src[SIZEX], int Value)
		{
			int L = 0;
			int H = SIZEX - 1;
			int M = 0;
			while (L <= H)
			{
				M = L + (H - L) / 2;
				cout << endl << "src[" << L << "] src[" << M << "] src[" << H << "]  = " << src[L] << "  " << src[M] << "  " << src[H] << endl;
				

				//Rotated array consists of two SORTED array but they are not sequential any more.
				//Ex: {4, 5, 6} is broken in to{ 5,6 } and {4}
				//FIRST decide whether to go in to left part or right part;
				
				if (src[L] <= src[M])
				{//1st array will have both Low - Index and mid - Index If src[L] < src[M].then go to left part.
					//{5	6 8} {1 2 3 4}
					//L = 0, M = 1, H = 6 //Go to left part. 
					//SECOND compare the Src[M] and VALUE, and appropriately adjust L & H. 
					
					cout << "    Go 1st Array src[" << L << "] < src[" << M << "] =  " << src[L] << " < " << src[M] << endl;
					if (src[M] == Value)
					{
						cout << "    Found the value " << Value  << " at " << M << endl;
						return M;
					}
					else if ((Value >= src[L]) && (Value <= src[M]))
					{
						cout << "    Go Left L = " << L << " H = " << M - 1 << endl;
						H = M - 1;
					}
					else
					{
						cout << "    Go Right L = " << M + 1 << " H = " << H << endl;
						L = M + 1;
					}

				}
				else if (src[M] < src[H])
				{ //2nd array will have both mid-Index and high-Index If src[M]  < src[H]. then go to 2nd array.

					cout << "    Go 2nd Array src[" << M << "] < src[" << H << "] =  " << src[M] << " < " << src[H] << endl;
					if (src[M] == Value)
					{
						cout << "    Found the value " << Value << " at " << M << endl;
						return M;
					}
					else if ((Value >= src[M]) && (Value <= src[H]))
					{
						cout << "    Go Right L = " << M + 1 << " H = " << H << endl;
						L = M + 1;
					}
					else
					{
						cout << "    Go Left L = " << L << " H = " << M - 1 << endl;
						H = M - 1;
					}
				}
		
			}
		}

	};
};
