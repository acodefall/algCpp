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
	Binary search inside rotated sorted Array_20170717001
		Rotated array is created by breaking one big sorted array in to two pieces, so that max-value and Min-Value come to the center of the array. 
		Traditional BST logic assume higher-index will give higher number and lower index will give lower number,
         and this will not be true after rotation. To compensate for this BST logic needs to alted, as follows.
		-Compute MID index as usual, and this gives two partitions
		-Go in to the partition that has continuous numbers. Continuous numbers means 'numbers in that partition should be all be INCREASING or DECREASING'; 
		 It should not "REDUCE and then INCREASE" means {5, 6, 7, 1, 2}
			Left-partition  {"4 5 6"}    //Continuous so go here
			Right-partition {"8, 10, 1, 2, 3"}  //Not Continuous,  so do not go here
			
			If src[L] < src[M]. then left-side is continuous so go to left-half
			If src[M]  < src[H]. then Right-side is continuous so go to right-half.
						
		-Once inside the correct section, apply the DAC logic. Check whether SoughtVALUE = MidVALUE is equal, if so exit.
		 If the SoughtVALUE is LOW, then make Left Turn or make Right Turn.
		
		

 
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
				        if(V is within src[M] & src[H])
					        L = M + 1;
				        else 
					        H = M - 1;

*/
namespace BinarySearchInRotatedArrayNM //@RED20170717001
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
