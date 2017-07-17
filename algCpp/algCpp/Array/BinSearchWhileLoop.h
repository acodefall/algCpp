#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

namespace BinSearchWhileLoopNM
{	
	/*
		src
			   4  20  29  37  43  45  75 100 250 356
			   0   1   2   3   4   5   6   7   8   9
				value to search 75

				src[0] src[4] src[9]  = 4  43  356
					Go Right L = 5 H = 9

				src[5] src[7] src[9]  = 45  100  356
					Go Left L = 5 H = 6

				src[5] src[5] src[6]  = 45  45  75
					Go Right L = 6 H = 6

				src[6] src[6] src[6]  = 75  75  75
					Value found src[6] = 75
	
	*/
	const int SIZEX = 10;
	class BinSearchWhileLoop
	{
		public:
				void callBinSearchWhileLoop()
				{
					//Data has to Sorted for us to apply Binary search
					int src[SIZEX] = { 4, 20, 29, 37, 43, 45, 75, 100, 250, 356 };

					stringstream ss;
					cout << "src " << endl;
					for (int i = 0; i < SIZEX; i++)
					{
						cout << setw(4) << src[i];
						ss << setw(4) << i;
					}
					cout << endl;
					cout << ss.str() << endl;

					BinSearchWhileLoopX(src, 75);
				}
				void BinSearchWhileLoopX(int src[SIZEX], int Value)
				{
					int L = 0;
					int H = SIZEX - 1;
					cout << "value to search "<< Value << endl;
					while (L <= H)
					{
						
						int M = L + (H - L) / 2;

						cout << endl << "src[" << L << "] src[" << M << "] src[" << H << "]  = " << src[L] << "  " << src[M] << "  " << src[H] << endl;

						if (Value < src[M])
						{
							cout << "    Go Left L = " << L << " H = " << M - 1 << endl;
							H = M - 1;
						}
						else if (Value > src[M])
						{
							L = M + 1;
							cout << "    Go Right L = " << M + 1 << " H = " <<H << endl;
						}
						else
						{
							cout << "    Value found src[" << M << "] = " << src[M] << endl;
							break;
						}
					}
				}
	};
};