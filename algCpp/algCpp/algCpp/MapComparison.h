#pragma once
#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace MapComparisonNM
{
	//illustrates the usage of comparaison operator with MAP
	class City
	{
	public:
		int population;
		string name;
		City(string nm, int pop)
		{
			population = pop;
			name = nm;
		}
	};

	class compFunctor
	{
		public:
			bool operator()(const string& p1, const string& p2)
			{
				bool ret = false;
				if (p1 == p2)
					ret = true;
				return ret;
			}
	};

	
	class testMapComparisonNM
	{
	public:
		void MapComparisonNM()
		{
			map<string, City*, compFunctor> mp;
			mp.insert(pair<string, City*>("ny", new City("ny", 100)));
			mp.insert(pair<string, City*>("london", new City("london", 5)));
			mp.insert(pair<string, City*>("tokyo", new City("tokyo", 45)));
			mp.insert(pair<string, City*>("bangalore", new City("bangalore", 15)));

			//print values
			cout << "print Map \r\n";
			cout << "\r\n\r\n";
			for (map<string, City*>::iterator itr = mp.begin(); itr != mp.end(); itr++)
			{
				cout << "   " << (*itr).second->name << "(" << (*itr).second->population << ")" << "\r\n";
			}

			/*
			london(5)
			bangalore(15)
			tokyo(45)
			ny(100)
			*/
		}

		
	};
};