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
namespace UniqueCharsNM
{
	/*

	*/
	
	class UniqueChars
	{
	public:
		void callUniqueChars()
		{
			char* src = new char[8];
			strcpy(src, "reverse");

			int hash[CHAR_MAX] = { 0 };

			int f = 0;
			int len = strlen(src);

			cout << src << endl;
			for (f = 0; f < len; f++)
			{
				if (hash[src[f]] > 0)
				{
					cout << "not unique";
				}
				else
					hash[src[f]]++;
			}
			delete[] src;
		}


	};
};