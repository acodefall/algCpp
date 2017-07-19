#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace FibForLoopNM
{
    class FibForLoop
    {
        public: 
			void calllFibForLoop()
			{
				const int fibLen = 7;
				int o[fibLen] = {0};

				o[0] = 0;
				o[1] = 1;
				cout << "Fib series of Len "<< fibLen << endl;
				for(int i = 2; i < fibLen; i++)
				{
					o[i] = o[i - 1] + o[i - 2];
					cout << o[i] << " ";
				}
				//Fib series of Len 7
				//	0 1 1 2 3 5 8
				cout << endl;
			}

	};
};
