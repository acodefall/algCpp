#pragma once
#include <iostream>
using namespace std;
class BinSearchForLoop
{
	public:
		void callBinSearchForLoop()
		{
			int src[11] = { 1, 4, 6, 7, 8, 9, 10, 12, 45, 90, 888};
			BinSearchForLoopX(src, sizeof(src) / sizeof(int), 12);
		}

		void BinSearchForLoopX(int* src, int len, int V)
		{
			int L = 0;
			int H = len - 1;
			int M = 0;
			while (L <= H)
			{
				M = (H + L) / 2;

				if (V < src[M])
					H = M-1;
				else if (V > src[M])
					L = M+1;
				else
					break;
			}
	
			cout << V << " is at index" << M;
		}

};
