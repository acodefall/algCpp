#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace SetComparisonNM
{
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

	

	class compFunctorSet
	{
		public:
			bool operator()(City* p1, City* p2)
			{
				bool ret = false;
				if (p1->population < p2->population)
					ret = false;
				else
					ret = true;
				return ret;
			}
	};
	class testSetComparisonNM
	{
		public:

			void SetComparisonNM()
			{
				set<City*, compFunctorSet> mp;
				mp.insert(new City("ny", 100));
				mp.insert(new City("london", 5));
				mp.insert(new City("tokyo", 45));
				mp.insert(new City("bangalore", 15));

				//print values
				cout << "print Set \r\n";
				cout << "\r\n\r\n";
				for (set<City*>::iterator itr = mp.begin(); itr != mp.end(); itr++)
				{
					cout << "   " << (*itr)->name << "(" << (*itr)->population << ")" << "\r\n";
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