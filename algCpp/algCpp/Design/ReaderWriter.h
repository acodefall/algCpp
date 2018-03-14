#pragma once
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
using namespace std;
#include<iostream>
#include<algorithm>
#include<list>
#include <string>
namespace ReaderWriterNM
{
	/*
		Read-Preffered logic:
		Reader threads can all read togather at the same time, where as only one Writer thread should run at any time. 
		Logic for read-preffered model is that reader-thread will block the writer-thread whenever reading is going on.



		Reader thread blocks the writer-thread by acquiring the writermutex. 
		Reader thread maintains a counter of reader-threads; and acquires the  writermutex when readThreadCounter is 1.
		readThreadCounter gets incremented by every readerThread when it starts; and gets decremented when thread completes reading.
		Reader thread releases the writermutexmutex when readThreadCounter comes down to 0.




		
		
		In fact But when a single writer is working we can not have any other writer, nor we can have any reader.
		Count the number of Readers within a MUTEX. When count is more than one, acquire the LOCK on Writer also.
		So no writer is getting called.
		We have MUTEX for reder-count and disabling and enabling Writer. Both are controlled by Reader.

		//Every reader first increment the counter under the LOCK, then goes out of the lock and reads.
		//Now the LOCK if free, if another reader wants to come in to increment the counter.
		//After compleating of reading, readers will come decrement the counter under the LOCK.
		//If the counter is 1, then Reader will ACQUIRE the writeLock also; so now one is writing.
		//COnversly when then counter drops to 0, Reader will RELEASE the writeLock
		//So we need two lock: counterLock and writeLock


	*/
	
	class ReaderWriterC
	{

		mutex 				mtx;
		condition_variable 	cv;
		int   rdCountA;
		int   rdCountR;
		bool  writerFlag;

		public:
			
			//Reader-code is devided in to 3 parts because we have several readers,
			//if we give exclusive access to one reader then other reader has to wait. But the fact is 
			//all the readers can read parallely. 
			//For syncing purpose all we need is how many readers are reading.

			// https://stackoverflow.com/questions/5667793/how-does-a-read-write-mutex-lock-work
			/*ReaderWriterC()
			{
				rdCountA = 0;
				rdCountR = 0;
				writerFlag = false;
			}

			//In Reader writer algorithm, 
			//start reading only when you get the lock
			void BeginRead()
			{
				lock_guard<mutex> lck(mtx);
				//Wait until every WRITER STOPS (if any write is alive wait)
				while(writerFlag)
				{
					cv.wait(mtx);
				}
				rdCountA++;
			}
			
			void EndRead()
			{
				lock_guard<mutex> lck(mtx);
				rddCount--;
				if (rddCount == 0)
				{
					wrtMtx.unlock();
					cv.notify_all();
				}
			}

			void BeginWriter()
			{
				lock_guard<mutex> lck(mtx);
				//Wait until every READER STOPS (if any READER is alive, then wait)
				while(rddCount > 0)
					cv.wait(mtx); 
				writerFlag = true;
			}
			
			void EndWriter()
			{
				lock_guard<mutex> lck(mtx);
				writerFlag = false; //This indicates NO writer is active, so that READER can go ahead, if any READER is waiting.
				cv.notify_all();    //WAKES up any READER that had called Wait().
			}
			*/
	};

	class RdWr
	{
		/*public:
			void CreateThreads()
			{
				list<thread*> tlist;
				ReaderWriterC objReaderWriter;
				
				//create 5 read threads and 5 write threads
				for (int i = 0; i < 5; i++)
				{
					tlist.push_back(new thread(&RdWr::ReaderThread, this, &objReaderWriter, i));
				}

				for (int i = 0; i < 5; i++)
				{
					tlist.push_back(new thread(&RdWr::WriterThread, this, &objReaderWriter, i));
				}

				//wait on them 
				for (auto itr = tlist.begin(); itr != tlist.end(); itr++)
				{
					(*itr)->join();
				}
				cout << "End" << this_thread::get_id() << endl;
			}

			void ReaderThread(ReaderWriterC* p, int tm)
			{
				int rounds = 15;
				int i = 0;
				while (i < rounds)
				{
					p->BeginRead();
					p->ReadActualData();
					p->EndRead();

					i++;
					std::this_thread::sleep_for(chrono::microseconds(tm+6));
				}

				cout << "ReaderThread ()" << this_thread::get_id() << endl;
			}

			void WriterThread(ReaderWriterC* p, int tm)
			{
				int rounds = 15;
				int i = 0;
				while (i < rounds)
				{
					p->Writer();
					i++;
					std::this_thread::sleep_for(chrono::microseconds(tm + 10));
				}

				cout << "WriterThread ()" << this_thread::get_id() << endl;
			}*/

	};
};