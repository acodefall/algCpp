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

namespace PalidroneNM
{
    ////@GN08 General_029_Check whether string is palindrome_GN08
    class Palidrone
    {
		public:
		void callPalidrone()
        {
			string s("palidrone");
            callPalidrone(s);


        }
        void callPalidrone(string d)
        {
            bool palid = true;
            const char* a = d.c_str();
            for(int i = 0, j = (d.length() - 1); i < j; i++, j--)
            {
                if(a[i] != a[j])
                {
                    //No a palidrone
                    palid = false;
                    break;
                }
            }
        }
    };
};
