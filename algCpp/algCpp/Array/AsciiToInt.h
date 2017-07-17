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

namespace AsciiToIntNM
{
	class Anagram1
	{
		public:
			void callAnagram1()
			{
				list<string> AngList;

				//Add Anagrams to ArrayList
				AngList.push_back("pans");
				AngList.push_back("reset");
				AngList.push_back("trees");
				AngList.push_back("naps");
				AngList.push_back("steer");
				AngList.push_back("span");


				cout << "Word list BEFORE sort " << endl;
				for (auto itr = AngList.begin(); itr != AngList.end(); itr++)
				{
					cout << (*itr).c_str() << endl;
				}

				sortByWord d;
				AngList.sort(d); //Sort will convert STRING in CHAR[] and then sort CHAR[]. Then convert CHAR[] to STRING. If the STRINGS are a same then it returns 1.

				cout << "Word list AFTER sort "<< endl;
				for (auto itr = AngList.begin(); itr != AngList.end(); itr++)
				{
					cout << (*itr).c_str() << endl;
				}

			}

		

	};
};