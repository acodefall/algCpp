#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

namespace BuddyMemoryManager
{
	class Allocator;

	/*
		Example for Buddy system:
		Assume Total memory is 128bytes. When MM starts, it allocates an array of 7 elements (because of 128 = 2 ^ 7).
		At the beginning largest available block is 128bytes long, so the starting address will be stored at FreeList[7]
		And 	FreeList[0 to 6] = -1
	
		0) Start
			FreeList[7] = 0x0 (128 bytes length)
			
		a) Then a Request for 18bytes comes. 18Bytes corresponds to 2^5 and but available memory is 2^7.
			So MM tries to create a block of size 2 ^ 5 out of 128bytes.
			 MM divides 128bytes block in to two 64byte blocks. And High-order buddy (of 64bytes) gets assigned to FreeList[6]; and low-order buddy undergoes further decomposition. 
				FreeList[7] = -1
				FreeList[6] =0x64;

	      (18Bytes < Low-order 64byte)
			64byte is still higher than 18bytes, so MM divides the Low-order buddy(of 64bytes) in to two buddies of 32bytes. 
			 High-order buddy(of 32 bytes) gets assigned to FreeList[5]; and low-order buddy is closest to the sought memory 
			 of size 18bytes. So it will be returned to caller.
				FreeList[7] = -1
				FreeList[6] = 0x64;
				FreeList[5] = 0x32;
				MM returns Low-order 32byte to caller.
				
		b) Then a Request for 14bytes comes. 14Bytes is 2 ^ 4. Smallest available free block is 2 ^ 5, so MM devides 32bytes block in to two. The High-order 16bytes gets assigned to FreeList[4]; and low-order 16byte will be sent to caller. 
			 			FreeList[7] = -1
						FreeList[6] = 0x64;
						FreeList[5] = -1;
						FreeList[4] = 0x16;
						MM returns Low-order 16byte to caller.
			
		c) Then a Request for 17bytes comes. 17Bytes needs 2^5 block. MM has free blocks of size 16bytes and 64bytes
			  16byte block is too small and 64byte block is one step large.
			 So MM devides 64byte block in to two 32byte blocks.
			 High-order 32bytes buddy gets assigned to FreeList[5]; and low-order buddy is returned to caller.
				
						FreeList[7] = -1
						FreeList[6] = -1;
						FreeList[5] = 0x32;
						FreeList[4] = 0x16;
	
		Final tally looks as follows.
				Allocated = 32(for 18) + 16(for 14) + 32(for 17) = 80bytes
				Free = 32 + 16 = 48bytes


		Steps: TBD
				a) Declare a class called Allocator, to have two methods CTOR and Alloc().
					CTOR's input parameter is MAX memory size, expressed as power-of-2
					Alloc()'s input paramater is memory size, expressed in terms of bytes.

					Class will also have two vector<void*>, one for freeList and allocList;

				b) Coming to CTOR. Say input to CTOR is powerOfN. This is also going to be the size length of freeList.
				   Then start a ForLoop that goes as long as  powerOfN, and inserts that many 0s to freeList.

				   Compute the totalMemory by doing 'pow(2,powerOfN)'
				   Call malloc(totalMemory), and assign the pointer to baseAddress-pointer.

					Then do 
						freeList[powerOfN] = baseAddress-pointer
					
					Then write 'write totalMemory to 'baseAddress-pointer'
						((int*)baseAddress)[0] = TotalMemory;

				c) Coming to Alloc()
				   Input param is bytesSought
				   Find the power of 2 equivalent of 'bytesSought', by left shifting '1' in a loop. 
				   Break the loop once "if (p >= bytesSought)" 
					
                   Now we have bytesSought in sought-bytes-in-power-of-two.
				
				   Now loop the FreeList, looking for valid pointer starting from the index 'sought-bytes-in-power-of-two'.
				   If nothing is found, then exit the function with NULL.
				   Else we found a free block. 
				   
				   Detach the adress from FreeList and assign to RetPtr, by doing 
					RetPtr = freeList[availMemIn2Power];
					
				   Then assign 0 to freeList[availMemIn2Power].
					freeList[availMemIn2Power] = 0
				   
				   Now compare 'availMemoryBlockIndex' with 'soughtMemory' in a while loop.
				   Eneter thr loop if availMemoryBlockIndex < soughtMemory, 
				   Inside the while loop, we divide the memory by 2, and also decrement availMemoryBlockIndex by one.
				   So loop continues until we trim the memory to close soughtMemory.

				   Read the size from header of 'RetPtr', and divide it by two.
				   Then do
						highOrderBuddy = RetPtr + halfSize;
						*highOrderBuddy = halfsize;
						*Retptr = halfsize.
				  Decrease

				   Read the size from header of RetPtr.


				   Use that as index in to FreeList[], and check if there it is has an valid address.
				   If so, use it we have found a matching free block.
				   If is not found, then check the higher elements of FreeList[]



	*/
	class Allocator
	{
		public:
			int		TotalMemory; //Includes both allocated and free
			void*	baseAddress; //starting address

			vector<void*> freeList; 
			vector<void*> allocList;
			Allocator(int powerOfN) //powerOfN = 7 .... 2 ^ 7 = 128 
			{
				baseAddress = 0;
				
				//initilize the 'freeList' with NULL
				for (int blocks = 0; blocks <= powerOfN; blocks++)
				{
					freeList.push_back(0);
				}

				TotalMemory = pow(2,powerOfN); //TotalFreeMemory = 128
				baseAddress = malloc(TotalMemory);

				//Initially only one block will be available and its size of is that of totalMemory.
				freeList[powerOfN] = baseAddress; //freeList[7] = baseMemory;
				((int*)baseAddress)[0] = TotalMemory;
			}
		
			void* Alloc(int bytesSought)
			{
				int RetIn2Power = 0; 
				int ReqIn2Power = 0;
				void *RetPtr = 0;
				int RetInBytes = 0;
				int availMemIn2Power = 0;
			
				//find the power of 2 equivalent of 'bytesSought'
				int p = 1;
				while(bytesSought > 0)
				{
					p <<= 1;
					ReqIn2Power++;
					if (p >= bytesSought)
						break;
				}
				
				

				//Scan the freeList for a block that is closest to 'BytesIn2Power'
				int notFound = 1;
				for (availMemIn2Power = ReqIn2Power; availMemIn2Power < freeList.size(); availMemIn2Power++)
				{
					if (freeList[availMemIn2Power] != 0)
					{
						notFound = 1;
						break;
					}
				}

				//k = 7
				if (notFound == 0)
				{	//No memory found return
					RetPtr = 0;
				}
				else
				{ 
					//free memory was found, try to compact the memory, if it is too large
					RetPtr = freeList[availMemIn2Power]; //take out from freeList[7];
					freeList[availMemIn2Power] = 0;
					RetIn2Power = availMemIn2Power;
					
					//free memory was found, try to compact the memory, if it is too large
					//Ex: k =7
					//ReqIn2Power = (2 ^ 5) but RetIn2Power = (2 ^ 7), so split the RetIn2Power.
					while (ReqIn2Power < RetIn2Power)
					{
						//RetPtr's header will have the size. Read the size from RetPtr, and divide it by 2.
						//We get 'high-order buddy' and 'low-order buddy'
						int halfMemory = ((int*)RetPtr)[0] / 2; 

						//RetPtr becomes low-order buddy 
						//(RetPtr + halfMemory) becomes high-order buddy  
						void* highOrderBuddy = ((unsigned char*)RetPtr + halfMemory);
						

						//write the size to header of 'low-order buddy' and 'high-order buddy'
						((int*)highOrderBuddy)[0] = halfMemory; //high-order
						((int*)RetPtr)[0] = halfMemory; //low-order
						
						//store the 'high-order buddy' in freeList.
						freeList[--availMemIn2Power] = highOrderBuddy; //add to freeList[6] Add the latter Half to FreeList; and return the 1st half to caller

						
						RetIn2Power = availMemIn2Power;
					}
					//add the allocated block to allocList
					allocList.push_back(RetPtr);
				}

				return RetPtr;
			}

			//to know the size of the memory read the size-header of every memory block.
			void printMemory()
			{
				cout << "bytes frees \r\n";
				for (vector<void*>::iterator itr = freeList.begin(); itr != freeList.end(); itr++)
				{
					if (*itr != 0)
					{
						cout << *((int*)(*itr)) << "\r\n";
					}

				}

				cout << "\r\nbytes allocated \r\n";
				for (vector<void*>::iterator itr = allocList.begin(); itr != allocList.end(); itr++)
				{
					if (*itr != 0)
					{
						cout << *((int*)(*itr)) << "\r\n";
					}

				}
			}
			
	
	};

	class callAllocator
	{

		public:
			void UseMemoryManager()
			{
				const int MaxMemory = 128;
				Allocator alc(7); //That is 2 ^ 7
				alc.Alloc(18);
				alc.Alloc(14);
				alc.Alloc(17);
				alc.printMemory();

			}
	};

};
