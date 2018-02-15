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

namespace SyncQNM
{
	//SyncQ  
	//Make the Q object thread-safe. Deq() will return 0, if Q is empty.
	//For exiting the threads, WritterThread will insert  -1 to Q; in response to that ReaderThread will exit.

	//class SyncQArc;

	class SyncQArc
	{
		private:
			queue<int>	sQ;
			mutex		mtx;
			condition_variable cv; //cv should be operated within the code gaurded by MUTEX
								   //Before operating in CV, acquire the MUTEX
		public:
			SyncQArc()
			{
			}

			void EnQ(int& val)
			{
				unique_lock<mutex> ulck(mtx); //Block until the mutex is acquired
				sQ.push(val); //push in to Q
				cout << "EnQ = " << val << std::this_thread::get_id() << endl;
				//cv.notify_all(); //WakeUp the CV that is Waiting() in another thread. 
			}

			int DeQ()
			{
				int retval = 0;
				unique_lock<mutex> ulock(mtx); //Block until the mutex is acquired

				/*while (sQ.empty()) //If the Q is empty, yeild the MUTEX so that EnQ() can insert the item in to Q.
					cv.wait(ulock); //wait() will release the MUTEX and then blocks until notify_all() is called.
									//In perfect world, wait() returns only when notify_all() is called.
									//sometime wait() returns(wakesup) even if the notify_all() is not called. This is called as
									//'spurious' wakeups.
									//To counteract 'spurious' wakeups, do an additional check even after wait() returns.
									//Additional check could be anything, like boolean flag. In our case
									//In our case aiidtional check is 'Q should NOT be empty'. 
									//If Q is still empty, call the wait() again.

				*/
				if (sQ.empty())
					retval = 0;
				else
				{
					retval = sQ.front();
					sQ.pop();
				}
				cout << "DeQ = " << retval << std::this_thread::get_id() << endl;
				
				return retval;
			}
	};

	class callSyncQArc
	{
			SyncQArc*	synQ;
			public:
				callSyncQArc()
				{
					synQ = new SyncQArc();
				}
				~callSyncQArc()
				{
					delete synQ;
				}

				void createThreads() 
				{
					list<thread*> lst;

					//create read threads
					for (int i = 5; i >= 0; i--)
					{
						lst.push_back(
										new thread(&callSyncQArc::readThread, this,synQ)
									);
					}

					//create write threads
					for (int i = 4; i >= 0; i--)
					{
						lst.push_back(
										new thread(&callSyncQArc::writeThread, this, synQ, i)
									);
					}



					int jcnt = 0;
					for(auto itr= lst.begin(); itr != lst.end(); itr++)
					{
						(*itr)->join();
					}
				
					cout << " all the threads exited " << endl;
				


				}

				//This thread reads from Q
				void readThread(SyncQArc* sync)
				{
					int rounds = 10;
					while (rounds >= 0)
					{
						std::this_thread::sleep_for(chrono::seconds(3));
						if (sync->DeQ() == -1)
							break;
						cout << "[" << std::this_thread::get_id() << "]" << "read = " << sync->DeQ() << endl;
						rounds--;
					}

					cout << "exiting [" << std::this_thread::get_id() << "] readThread" << endl;
				}

				void writeThread(SyncQArc* sync, int seed)
				{
					default_random_engine rnd(seed);
					uniform_int_distribution<int> dist(10, 900);

					int rounds = 10;
					while (rounds >= 0)
					{
						std::this_thread::sleep_for(chrono::seconds(5));
						int val = dist(rnd);
						sync->EnQ(val);
						cout << "{" << std::this_thread::get_id() << "}" << "wrote = " << val << endl;
						rounds--;
					}
					//Write End of the work TOKEN
					int gEnd = -1;
					sync->EnQ(gEnd);
					sync->EnQ(gEnd);
					sync->EnQ(gEnd);
					sync->EnQ(gEnd);
					sync->EnQ(gEnd);
					sync->EnQ(gEnd);
					cout << "exiting [" << std::this_thread::get_id() << "] writeThread" << endl;
				}

	};
	
	
};
