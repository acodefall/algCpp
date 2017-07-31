#pragma once
#include <iostream>
namespace MemcpyNM //@RED20170730001
{
	/*
		Implement Memcpy()
			Allocating function has to TEMPLATE function and req-size should be in-param and T* should be return value. 
			Caller will indicate TYPE of data to be allocated as template-type, and pass Size comes as in-param.
			Function should express the req-size in terms of SIZE_T because OS views memeory 
			in terms of SIZE_T. And this will avoid the need for padding.
	
			Allocate using CALLOC() and type-cast the void* in to T* and send it to caller.
	
			For expressing reqSize in terms of size_t do  
					"reqSize/sizeof(size_t)"
			
			Add one extra size_t to take care mod-value.
				size_t: 8
				reqSize:'13' 
					(13 / 8) = 1
					(13 % 8) = 5
				calloc(2, sizeof(size_t))

				void* ptrInt = AllocX<int>(13);
		
				template<typename T> T* AllocX(int num)
				{
					int NumAsSizeT = (num / sizeof(size_t)) + 1; //Add One so it will take care of MOD value.
					return (T*)calloc(sizeof(size_t), NumAsSizeT);
				}
		
		output:
				sizeof(size_t) : 8
				sizeof(T) : 1
				1num :'12' As Size_t: '1' Mod '4'
				Num As Size_t : '2'

				sizeof(size_t) : 8
				sizeof(T) : 4
				4num :'13' As Size_t: '1' Mod '5'
				Num As Size_t : '2'
	*/
	class Memcpy
	{
			public:
			void CallMemcpy()
			{
				//allocate CHAR
				//indicate TYPE(CHAR) of data to be allocated as template - type
				void* ptrChr = AllocX<char>(12);
				FreeX(ptrChr);

				//indicate TYPE(INT) of data to be allocated as template - type
				void* ptrInt = AllocX<int>(13);
				FreeX(ptrInt);
			}


			template<typename T> T* AllocX(int num)
			{
				cout << "sizeof(size_t) : " << sizeof(size_t) << endl;
				cout << "sizeof(T) : " << sizeof(T) << endl;
				
				//express reqSize in terms of size_t
				// OS views memeory 
				//in terms of SIZE_T.And this will avoid the need for padding.
				int NumAsSizeT = (num / sizeof(size_t)) + 1; //Add One so it will take care of MOD value.
				
				
				cout << sizeof(T) << "num :'" << num << "'" << " As Size_t: '" << (num/sizeof(size_t)) << "' Mod '" << (num % sizeof(size_t)) << "'" << endl;
				cout << "Num As Size_t : '" << NumAsSizeT << "'" << endl;
				
				//type-cast the pointer as SOUGHT type T.
				return (T*)calloc(sizeof(size_t), NumAsSizeT);
			}

			void FreeX(void* p)
			{
				if (p)
					free(p);
			}
	};
};
