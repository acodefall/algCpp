#pragma once

#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<deque>
#include<mutex>
#include<thread>
#include <chrono>
#include <random>
using namespace std;

#define SIZE 10


class ProdConsumer
{
	thread wrk[SIZE];
	deque<thread*> qst;
	list<thread*> lst;
	condition_variable evt;
	mutex lck;
	deque<int> data;
	public:
		int done;
		ProdConsumer()
		{
			done = false;
			
			for (int i = 0; i < SIZE; i++)
			{
				thread *x = new thread(&ProdConsumer::work, this, i);
				lst.push_front(x);
			}
			cout << " threads created \r\n";
		}

		~ProdConsumer()
		{
			evt.notify_all();
			int i = 0;
			for (auto k = lst.begin(); k != lst.end(); k++)
			{
				cout << " loop 1 "<< (*k)->get_id() << "\r\n";
				if ((*k)->joinable())
					(*k)->join();
				cout << " loop 2 " << (*k)->get_id() << "\r\n";
			}
			

			cout << " Dtor \r\n";
			for (auto k = lst.begin(); k != lst.end(); k++)
			{
				delete (*k);
			}
			cout << " Dtor finished \r\n";
		}

		void addWord(int x)
		{
			lock_guard<mutex> lk(lck);
			data.push_back(x);
			evt.notify_all();
			cout << " addWord()" << " " << x << "\r\n";
		}

		int getWork()
		{
			int ret = -1;
			unique_lock<mutex> lk(lck); //not locked yet
			try
			{
				evt.wait(lk, [this]() {return !data.empty(); }); //do not lock if empty() and wait on evt
				ret = data.back();
				cout << " getWork()" << " " << ret << "\r\n";
				data.pop_back();
				lk.unlock();
			}
			catch (...)
			{
				cout << " exception in getWork()" << "\r\n";
				if (lk.owns_lock())
					lk.unlock();
			}
			cout << " getWork() exiting" << "\r\n";
			return ret;
		}


		void work(int x)
		{
			try
			{

				while (true)
				{
					if (done == true)
						return;
					int x = getWork();
					if (x == -1)
						break; //last item
					cout << " work() exiting" << x << "\r\n";
					//sleep
					this_thread::sleep_for(chrono::milliseconds(100));

				}

				
			}
			catch (...)
			{
				cout << "exception in work() \r\n";
			}

			cout << " work() exiting" << "\r\n";
		}
};



class callProdConsume
{
	ProdConsumer x;
public:
	void callProd()
	{
		for (int i = 0; i < 8; i++)
		{
			x.addWord(i + 6);
			this_thread::sleep_for(chrono::milliseconds(1000));
		}

		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine

		this_thread::sleep_for(chrono::minutes(1));
		x.done = true;
		//insert several LAST ITEMS (=-1) in to Dq	
		for (int i = 0; i < 16; i++)
		{
			x.addWord(-1);
		}

		cout << " done set\r\n";

	}


};