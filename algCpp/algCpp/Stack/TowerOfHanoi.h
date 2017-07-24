#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

namespace  TowerOfHanoiNM
{

    ////@SH05 stack_015_Towers of Hanoi Concept_SH05
    ////@SH05 stack_017_Towers of Hanoi Implementation_SH05
    class TowerOfHanoi
    {
        public:
		void CallTowerOfHanoi()
        {
            stack<int> src;
            stack<int> dest;
            stack<int> buffer;
            src.push(33);
            src.push(23);
            src.push(13);
            src.push(3);

            

            TowerOfHanoiX(4, src, dest, buffer);

            cout << endl << "Dest stack" << endl;
            while(dest.size() > 0)
			{
				cout << dest.top() << endl;
				dest.pop();
			}
			/*
				Dest stack
							3
							13
							23
							33
			*/
        }
        
		int TowerOfHanoiX(int n, stack<int>& src, stack<int>& dest, stack<int>& buffer)
        {
            int result = 0;
            if (n <= 0)
                return 0;
            //Small P1->P3
            TowerOfHanoiX(n - 1, src, buffer, dest);

            int value = src.top();
			src.pop();
            dest.push(value);

            //Samm P3->P2
            TowerOfHanoiX(n - 1, buffer, dest, src);
            return result;
        }

    };
};
