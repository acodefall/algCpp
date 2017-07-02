#pragma once
#include <map>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

/*
	PriorityQueue Limitations
		PriorityQueue is not editable. In the sense say we have PQ that holds City-object, and set priority is the Population of City.
		After loading the objects, if we can not change the POPULATION of one of the city and expect the PQ to get reordered automatically.
		One solution is replace PQ with Q and map.
		-Store pointer to City in both Q and Map. 
		-Map will have City-name as KEY. 
		When you want to edit the population of say Tokyo, use Map to get pointer-to-Tokyo, and modify it.
		Now call Sort-on-Q.

		Note that to the sort() function, you can provide appropriate the functor and get either AscendingQ or DescendingQ. 

		map<string, City*> Mp;
		deque<City*>		Q;

		City t1("tokyo", 100);
		City t2("london", 5);
	
		//add to map
		pq.Mp.insert(pair<string,City*>(t1.name,&t1));
		pq.Mp.insert(pair<string, City*>(t2.name, &t2));
		//

		//add to Dq
		pq.Q.push_back(&t1);
		pq.Q.push_back(&t2);

		///make Q the priority-Q by sorting
		compFunctor c1;
		sort(pq.Q.begin(), pq.Q.end(), c1);
		///

		////We need to modify Tokyo
		City* tq = pq.Mp["tokyo"];
		tq->population = 200;

		compFunctor c2; //we modified the population of Tokyo; so we need to set the
		sort(pq.Q.begin(), pq.Q.end(), c2);
		////

*/
namespace editablePQ
{
	/*
		output
				print Q (before sort)
								ny(100)
								london(5)
								tokyo(45)
								bangalore(15)


				print Q (after sort)
								ny(100)
								tokyo(45)
								bangalore(15)
								london(5)


				print Q (after edit)
								tokyo(200)
								ny(100)
								bangalore(15)
								london(5)
	*/
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
	class EditablePriorityQ
	{
		public:
			map<string, City*> Mp;
			deque<City*>		Q; 
	};

	class TestEditablePQ
	{
		public:
			void callEditablePQ()
			{
				EditablePriorityQ pq;

				City t1("ny", 100);
				City t2("london", 5);
				City t3("tokyo", 45);
				City t4("bangalore", 15);

				//add to map
				pq.Mp.insert(pair<string,City*>(t1.name,&t1));
				pq.Mp.insert(pair<string, City*>(t2.name, &t2));
				pq.Mp.insert(pair<string, City*>(t3.name, &t3));
				pq.Mp.insert(pair<string, City*>(t4.name, &t4));
				//

				//add to Dq
				pq.Q.push_back(&t1);
				pq.Q.push_back(&t2);
				pq.Q.push_back(&t3);
				pq.Q.push_back(&t4);
				/////

				//print values
				cout << "print Q (before sort) \r\n";
				cout << "\r\n\r\n";
				for (deque<City*>::iterator itr = pq.Q.begin(); itr != pq.Q.end(); itr++)
				{
					cout << "   " << (*itr)->name <<"(" << (*itr)->population <<")" << "\r\n";
				}

				///make Q the priority-Q by sorting
				compFunctor c1;
				sort(pq.Q.begin(), pq.Q.end(), c1);
				///

				//print values
				cout << "\r\n\r\n";
				cout << "print Q (after sort) \r\n";
				for (deque<City*>::iterator itr =  pq.Q.begin(); itr != pq.Q.end(); itr++)
				{
					cout << "   " << (*itr)->name << "(" << (*itr)->population << ")" << "\r\n";
				}

				////We need to modify Tokyo
				City* tq = pq.Mp["tokyo"];
				tq->population = 200;

				compFunctor c2; //we modified the population of Tokyo; so we need to set the 
				sort(pq.Q.begin(), pq.Q.end(), c2);
				////

				
				//print values
				cout << "\r\n\r\n";
				cout << "print Q (after edit) \r\n";
				for (deque<City*>::iterator itr = pq.Q.begin(); itr != pq.Q.end(); itr++)
				{
					cout << "   " << (*itr)->name << "(" << (*itr)->population << ")" << "\r\n";
				}
			}
	};
};
