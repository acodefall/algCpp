#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;
namespace ReverseWithoutTempNM  //@RED20170725062
{
	/*
	
	*/
	class ReverseWithoutTemp
	{
		public:
			void callReverseWithoutTemp()
			{
				char* src = new char[8];

				strcpy(src, "reverse" );
				int f = 0;
				int r = strlen(src)-1;
			
				cout << src << endl;
				while (f < r)
				{
			
					src[f] = src[f] ^ src[r]; //store both values(src[f] & src[r]) at one place. 
											  //src[f] = "src[f] + src[r]"

					src[r] = src[f] ^ src[r]; //Expel "src[r]" from "src[f] + src[r]"

					src[f] = src[f] ^ src[r]; //Expel "src[f]" from "src[f] + src[r]"
					f++;
					r--;
				}
				cout << src << endl;

				delete[] src;
			}

	
	};
};