#pragma once
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <mutex>
#include <thread>
#include <list>
#include <random>

using namespace std;

namespace ObjectPoolArcNM
{
	class Arc
	{
		public:
			Arc()
			{

			}
		
		private:
			int value; 
	};


	/*
		Object pool pattern:
							Object pool should behave as singleton so everything should be declared as static.
							Private members will include 'static mutex' for syning get() and put() methods.
							There will two list objects called as Inlist and Outlist. Inlist carries the object available
							and Outlist carries the objects given-out.
							At anytime the cumulative sum of Inlist and Outlist should be equal to MAX OBJECTS.
							We do not create the objects in advance, instead get() will create brand new object if the
							cumulative sum Inlist and Outlist is less than MAX. 

							When adding to list, use list.push_back() so object goes to the bottom. 
							When retrieving the object pluck from top using list.front().
							After retrieving the object, inorder to delete it from list, call list.remove()

							Most importantly put() should reset the state of the object by calling Reset on the returned object pointer.

							Coming to implementation:
							1) declare static mutext, inList and outList
							2) declare static get(). Create lock_guard on MUTEX.
							   Check the cumulative sum of Inlist and Outlist, and if it is < MAX, create brand new object and push_back() in to inList
							   If the  cumulative sum more than MAX, get an item from inList and return to caller. Call inList.front()
							   and also inList.remove(), and then add to outList by calling push_back().

							   if inlist is empty return NULL.
							
							3) declare static put(). Reset the incoming object. Remove it from outList and add it to inlist.
							
							Note that we Remove() accepts VALUE to removed as input, not the index of the object to be removed.

							Note that we do not delete 'static mutex'. Instead it gets deleted when EXE unloads.
							Inside the list object store unique_ptr so when program unloads, DTOR of the object will get called.
	*/

	class ObjectPoolArc
	{
		static mutex lck;
		static list<Arc*> inList;
		static list<Arc*> outList;
		
		public:
		static Arc* getArc()
		{
			//there will be ONLY ONE mutex for getArc(). 
			//All the threads calling getArc() will get synched.
			Arc* ret = 0;
			lock_guard<mutex> glck(lck);
			if (outList.size() + inList.size() < 10)
			{
				ret = new Arc();
				//Add it to OUT-list;
				outList.push_back(ret);
			}
			else if(inList.size() > 0)
			{
				//get from inlist and add to outlist
				ret = inList.front();
				
				//remove from IN-list
				inList.remove(ret);
				outList.push_back(ret);
			}
			return ret;
		}

		static void putArc(Arc* val)
		{
			lock_guard<mutex> glck(lck);
			if (val)
			{
				//RESET the STATE of the object 
				//val->Reset();

				outList.remove(val);
				inList.push_back(val);
			}
		}
	};
	list<Arc*>	ObjectPoolArc::inList;
	list<Arc*>	ObjectPoolArc::outList;
	mutex		ObjectPoolArc::lck;
	class callObjectPoolArc
	{
		public:
			

			void createThread()
			{
				list<thread*> lstT;
				
				Arc* pObj = ObjectPoolArc::getArc();
				//create 
				for (int i = 0; i < 5; i++)
				{
					lstT.push_back(new thread(&callObjectPoolArc::fetchAndReturnObject, this));
				}
			
				
				for(auto itr = lstT.begin(); itr  != lstT.end(); itr++)
				{
					(*itr)->join();
				}

				cout << "all done" << endl;
			}

			void fetchAndReturnObject()
			{
				default_random_engine rnd(133);
				uniform_int_distribution<int> dist(10, 900);

				int rounds = 10;
				while (rounds >= 0)
				{
					//fetch the object
					
					Arc* pObj = 0;
					while (pObj == 0)
					{
						std::this_thread::sleep_for(chrono::seconds(2));
						pObj = ObjectPoolArc::getArc();
					}
					
					//hold the object for few seconds
					if (pObj)
					{
						std::this_thread::sleep_for(chrono::seconds(1));
						ObjectPoolArc::putArc(pObj);
					}
					rounds--;
				}
				
				cout << "exiting [" << std::this_thread::get_id() << "] fetchAndReturnObject" << endl;
			}

		
	};
};