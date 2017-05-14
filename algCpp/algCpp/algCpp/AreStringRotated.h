#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>

using namespace std;
namespace StringRotatedNM
{
	class StringRotated
	{
		public:
			StringRotated()
			{
				cout << "in StringRotated";
			}
			void callStringRotated()
			{
				string x("mytest");
				string rx("testmy");

				string rxa = rx.append(rx);

				if (rxa.find(x) != -1)
				{
					cout << "rotated";
				}

			}
	};
};