#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

/*
	PriorityQueue
			STL has Priority_Queue class. Caller can configure it as either MinHeap or MaxHeap by providing comparator operator to CTOR.
			PQ does not support Remove() or Erase(), and only way to remove the item is through Pop(); note that Pop() will remove only the Top item.
			So Only way to iterate is keep on calling Top() and Pop(). Top() will fetch the top-most element and Pop() will remove the Top-element and then automatically re-orders the heap.

			priority_queue<City*, vector<City*>, compFunctor> pq;
			pq.push(new City("ny", 100));
			pq.push(new City("london", 5));
		

			//print values
			while (pq.size() > 0)
			{
				City* itr = pq.top();
				cout << "   " << (itr)->name << "(" << (itr)->population << ")" << "\r\n";
				pq.pop();
			}
*/
namespace UsageOfPrioriQNm
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

	class TestUsageOfPriorotyQ
	{
		public:
			void callTestingUsageOfPriorityQ()
			{
				priority_queue<City*, vector<City*>, compFunctor> pq;
				pq.push(new City("ny", 100));
				pq.push(new City("london", 5));
				pq.push(new City("tokyo", 45));
				pq.push(new City("bangalore", 15));

				//print values
				cout << "print Q \r\n";
				cout << "\r\n\r\n";
				while (pq.size() > 0)
				{
					City* itr = pq.top();
					cout << "   " << (itr)->name << "(" << (itr)->population << ")" << "\r\n";
					pq.pop();
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