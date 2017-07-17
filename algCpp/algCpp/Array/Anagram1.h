#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include <sstream>

using namespace std;

namespace Anagram1NM
{
	/*
		Q) Group the ANAGRAMs that are stored in a Array, so that they appear next to each other. 
            Basically RAT and TAR should appear next to each other.

		Strategy is to load the words to a LIST. Then provide a custom SORT-Predicate for LIST. 
		This predicate will sort the idividual characters of the string, and constructs a NEW string, and then compares these new strings.
		Ex: Predicate will turn p1=Rat p2=Art int to ART and ART, and then compares them using <
				OriginalWord /SortedWord
				trees  => eerst
				reset => eerst
				reset  => eerst
				pans => anps
				span  => anps
				steer => eerst
				steer  => eerst
				span => anps
				span  => anps
				naps => anps
				naps  => anps
				pans => anps
				naps  => anps
				reset => eerst
				reset  => eerst
				naps => anps
				span  => anps
				reset => eerst
				reset  => eerst
				span => anps
				steer  => eerst
				reset => eerst
				steer  => eerst
				trees => eerst


   */
   //SORT-Predicate
	struct sortByWord
	{
		bool operator()(string p1, string p2)
		{
			stringstream ss;
			stringstream ss1;
			ss << p1.c_str() << "  => ";
			ss1 << p2.c_str() << " => ";
			
			//Sort the word and then compare
			//So p1=Rat p2=Art will become ART and ART after SORTING
			sort(std::begin(p1), std::end(p1));
			sort(std::begin(p2), std::end(p2));
			ss << p1.c_str() << " ";
			ss1 << p2.c_str() << " ";

			cout << ss.str() << endl;
			cout << ss1.str() << endl;

			//compare the SORTED words
			if (p1 < p2) //
			{
				return true;
			}
			return false;
		}
	};

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
					cout << "  " << (*itr).c_str() << endl;
				}

				sortByWord d;
				AngList.sort(d); //Sort will convert STRING in CHAR[] and then sort CHAR[]. Then convert CHAR[] to STRING. If the STRINGS are a same then it returns 1.

				cout << "Word list AFTER sort "<< endl;
				for (auto itr = AngList.begin(); itr != AngList.end(); itr++)
				{
					cout << "  " << (*itr).c_str() << endl;
				}

			}

		

	};
};