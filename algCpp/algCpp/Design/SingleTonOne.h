#pragma once
#include<iostream>
#include<list>
#include<thread>
#include<memory>
using namespace std;

/*
	Singleton impl needs 3 things
		Say we want to have ONLY one instance of Resource R.
		Want to expose R through an another Singleton class called Sing. 
		Sing class will expose R to user. Use can not call new on Sing because it is singleton.
		Once the user gets R, he will not call Sing class for anything.
		R should be thread safe because multiple threads will be calling.
		Where as Sing does not have to be thread safe. Because Sing function will
        declare R as static and expose it to user through the getIns() function.
        Sing class will not expose any methods of R, other than creating it. 
		By declaring the R as STATIC, C++11 will asssure thread-safe creation of R.
		This is why Sing class does not need mutex or lock. 
		
		Sing class should have following
		a) Make the CTOR of Sing private so that user can no call NEW.
		b) Declare STATIC-PUBLIC function called getInst() to return the static instance of the R
		c) Declare the R as STATIC either as class member or declare inside the function GetInstance() function.
		 

*/
//unresolved external symbol "private: static class
//extern SingleTonOneX::getInstance inst;
class SingleTonOneX
{
	private:
			/*static SingleTonOneX* inst;*/
			SingleTonOneX()
			{
				//inst = nullptr;
				cout << "no one calls me " << this_thread::get_id() << " \r\n";
			}

			

	public:
		static SingleTonOneX& getInstance()
		{
			static SingleTonOneX instInst;
			/*if (inst == nullptr)
			{
				inst = new SingleTonOneX();
				cout << "getInstance() creates " << this_thread::get_id() << " \r\n";
			}	
			else
			{
				cout << "getInstance() uses " << this_thread::get_id() << " \r\n";
			}*/
			cout << "getInstance() uses " << this_thread::get_id() << " \r\n";
			return instInst;
		}
		void Method1()
		{

			cout << "Method1 " << this_thread::get_id() << " \r\n";
		}

		void Method2()
		{
			cout << "Method2 " << this_thread::get_id() << " \r\n";
		}
};


class testSingleTonOneX
{
	void work()
	{
		SingleTonOneX sngl = SingleTonOneX::getInstance();
		cout << "work() thread working. SingleTonOneX obtained \r\n";
		int reps = 3;
		while (reps > 0)
		{
			sngl.Method1();
			this_thread::sleep_for(std::chrono::milliseconds(3));
			sngl.Method2();
			this_thread::sleep_for(std::chrono::seconds(9));
			reps--;
		}
		cout << "work() threads Ends \r\n";
	}

	void work2()
	{
		SingleTonOneX sngl = SingleTonOneX::getInstance();
		cout << "work2() thread working \r\n";
		int reps = 4;
		while (reps > 0)
		{
			sngl.Method1();
			this_thread::sleep_for(std::chrono::milliseconds(3));
			sngl.Method2();
			this_thread::sleep_for(std::chrono::seconds(10));
			reps--;
		}

		cout << "work2() threads Ends \r\n";
	}

	list<thread*> lst;
	public:
		~testSingleTonOneX()
		{
			for (auto z = lst.begin(); z != lst.end(); z++)
			{
				delete *z;
			}
			lst.clear();
		}
		void callSingleTonOneX()
		{
			for (int i = 0; i < 10; i++)
			{
				if(i % 2 == 0)
					lst.push_back(new thread(&testSingleTonOneX::work, this));
				else
					lst.push_back(new thread(&testSingleTonOneX::work2, this));
			}
			cout << "callSingleTonOneX() threads created \r\n";

			Run();
		}

		void Run()
		{

			cout << "Run() is waiting \r\n";
			for (auto itr = lst.begin(); itr != lst.end(); itr++)
			{
				(*itr)->join();
			}
			cout << "Run() is returning \r\n";
		}
		
};