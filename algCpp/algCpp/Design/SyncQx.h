#pragma once

#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>
#include<thread>
#include<mutex>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

template <typename T>
class SyncDqX
{
	deque<T>	data;
	mutex		lock; //do not make the Mutex smart-pointer because we may use different smart-pointers

public:
	bool Empty()
	{
		lock_guard<mutex> lg(lock);
		return data->empty();
	}

	T front()
	{
		T ret;
		lock_guard<mutex> lg(lock);
		if (data.empty())
			ret = -1;
		else
		{
			ret = data.front();
			data.pop_front();
		}
		return ret;
	}

	T back()
	{
		T ret;
		lock_guard<mutex> lg(lock);
		if (data.empty())
			ret = -1;
		else
		{
			ret = data.back();
			data.pop_back();
		}

		return ret;
	}


	
	void push_back(T& x)
	{
		lock_guard<mutex> lg(lock);
		data.push_back(x);
	}

	void push_front(T& x)
	{
		lock_guard<mutex> lg(lock);
		data.push_front(x);
	}

};

class CallSyncDq
{
	SyncDqX<int> q;
	bool done = false;
	public:
		void Read()
		{
			while (done == false)
			{
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine

				int v = generator();

				try
				{
					cout << "id : " << this_thread::get_id() << "  " << q.front() << " \r\n";
					cout << "id : " << this_thread::get_id() << "  " << q.back() << " \r\n";
				}
				catch (...)
				{
					cout << "exception in Read \r\n";
				}
				//sleep
				this_thread::sleep_for(std::chrono::milliseconds(3000));
			}

			cout << "Read threads exiting \r\n";

		}
		void Add()
		{
			while (done == false)
			{
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine

				int v = generator();

				try
				{
					if (v % 2 == 0)
						q.push_back(v);
					else
						q.push_front(v);
					cout << "Added a value " << v << "\r\n";
				}
				catch (...)
				{
					cout << "exception in Add \r\n";
				}

				//sleep
				this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			cout << "Add threads exiting \r\n";
		}

		

		void callSyncDq()
		{
			vector<thread> vt;
			vt.reserve(12);
			for (int i = 0; i < 6; i++)
			{
				thread x(&CallSyncDq::Add, this);
				vt.push_back(move(x));
			}
			
			cout << "started Add threads \r\n";

			for (int i = 0; i < 6; i++)
			{
				thread x(&CallSyncDq::Read, this);
				vt.push_back(move(x));
			}

			cout << "started Read threads \r\n";

			for (auto k = vt.begin(); k != vt.end(); k++)
			{
				if ((*k).joinable())
					(*k).join();
				else
				{
					cout << "one thread not joinable \r\n";
				}
			}

			cout << "threads exiting \r\n";
		}

		public:
			void callSyncDqXSync()
			{
				
				try
				{
					Add();
					Add();
					Add();
					Add();
					Add();
					Add();
					Add();
					while (true)
					{
						cout << q.front() << " \r\n";
						
					}
				}
				catch (...)
				{
					cout << "Exception in callSyncDqX() \r\n";
					
				}

				cout << "exiting callSyncDqX() \r\n";
			}

			void callSyncDqX()
			{
				thread mn(&CallSyncDq::callSyncDq, this);
				try
				{
					this_thread::sleep_for(std::chrono::seconds(59));
					done = true;
					if (mn.joinable())
						mn.join();
				}
				catch (...)
				{
					cout << "Exception in callSyncDqX() \r\n";
					if (mn.joinable())
						mn.join();
				}

				cout << "exiting callSyncDqX() \r\n";
			}

		
};



/*
	v1 = rand() % 100;         // v1 in the range 0 to 99
	v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
	v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014



	// mersenne_twister_engine::seed example
	#include <iostream>
	#include <chrono>
	#include <random>

	int main ()
	{
		typedef std::chrono::high_resolution_clock myclock;
		myclock::time_point beginning = myclock::now();

		// obtain a seed from a user string:
		std::string str;
		std::cout << "Please, enter a seed: ";
		std::getline(std::cin,str);
		std::seed_seq seed1 (str.begin(),str.end());

		// obtain a seed from the timer
		myclock::duration d = myclock::now() - beginning;
		unsigned seed2 = d.count();

		std::mt19937 generator (seed1);   // mt19937 is a standard mersenne_twister_engine
		std::cout << "Your seed produced: " << generator() << std::endl;

		generator.seed (seed2);
		std::cout << "A time seed produced: " << generator() << std::endl;

		return 0;
	}


	



	// mersenne_twister_engine::min and max
	#include <iostream>
	#include <chrono>
	#include <random>

	int main ()
	{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator (seed);  // mt19937 is a standard mersenne_twister_engine

		std::cout << generator() << " is a random number between ";
		std::cout << generator.min() << " and " << generator.max();

		return 0;
	}


	//1-6
	mt19937::result_type seed = time(0);
	auto dice_rand = std::bind(std::uniform_int_distribution<int>(1,6),
	mt19937(seed));

	//0-1
	mt19937::result_type seed = time(0);
	auto real_rand = std::bind(std::uniform_real_distribution<double>(0,1),
	mt19937(seed));

*/
