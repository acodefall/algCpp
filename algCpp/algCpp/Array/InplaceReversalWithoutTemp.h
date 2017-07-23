#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>

using namespace std;

namespace InplaceReversalWithoutTempNM
{

	
    class InplaceReversalWithoutTemp
    {
        public:
				void callInplaceReversalWithoutTemp()
				{
					string s("reverse");
					Rev(s);
				}
				void Rev(string srcIn)
				{
					char* src = (char*)srcIn.c_str();
					cout << "Before " << src << endl;
					for(int i = 0, j = srcIn.length() - 1; i < j; i++, --j)
					{
						src[i] ^= src[j]; //load both in to one variable
						src[j] ^= src[i]; //i in to j(cancel out j and load i)
						src[i] ^= src[j]; //j in to i(cancel out i and leave j)
					}
					cout << "After " << src << endl;
				}
    };
};
