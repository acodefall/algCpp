#pragma once
#include <iostream>
using namespace std;
namespace SmartPointerArcNM
{
	/*
		Smart pointer_RED20180209010
		   -Smart is not going allocate the object by calling NEW, instead the caller should allocate and pass it to 
			smart_ptr so that smart_ptr can manage life_time. smart_ptr assume that pointer passed was allocated using 
			NEW ( and not an object declared on STACK) and calls DELETE on the object when 
			smart_ptr goes out of scope. 
			
			-There are smart_pointers that maintain ref count and the ones that does not maintain refcount. 
			unique_ptr does not maintain refcount where as shared_ptr maintains refcount.


			-Class must be a template class.
	        -CTOR should accept the pointer of type T. This pointer is allocated by caller and is being passed to smart_ptr.
			
			-should not implement & operator because it does not want to leak the address of the object.

			-should not expose == and copyCTOR because smart_pointer is dedicated to only one pointer that was passed through CTOR.
			 It does not accept any object, passed afterwards.
	
			-Should expose *perator and ->operator.  
			 "->operator" returns actual pointer so that caller can invoke the methods. Note that caller can store this as pointer, nor he can pass this to 
			  DELETE. Caller can only use this POINTER for invoking methods on CLASS.

			"*operator" returns refernce to "*myptr" CLASS

			-DTOR should call DELETE on the pointer.

			-Optionally can implement Release(). This will behave just like DTOR
	*/


	template<typename T>
	class SmartPointerArcC
	{
		T* myptr;
		public: 
			SmartPointerArcC(T* p)
			{
				if (p == NULL)
				{
					myptr = 0;
				}
				else
				{
					myptr = p;
				}
			}
			
			

			T& operator*() const
			{
				return *myptr;
			}

			T* operator->() const
			{
				return myptr;
			}

			void Release()
			{
				if (myptr)
				{
					delete myptr;
					myptr = 0;
				}
			}

			~SmartPointerArcC()
			{
				if (myptr)
				{
					delete myptr;
					myptr = 0;
				}
				cout << "~SmartPointerArcC" << endl;
			}

	private:
			//SmartPointerArcC(const T& p) =
			//unique_ptr(const _Myt&) = delete;
			SmartPointerArcC(const T& p)
			{
			
			}

			T& operator=(const T& p)
			{
				return this;
			}

	};

	class Test
	{
		public:
			Test()
			{
			}
			void something()
			{
				cout << "some thing" << endl;
			}
	};

	class useSmartPointerArcC
	{
			public:	
				void create()
				{
					SmartPointerArcC<Test> p(new Test());

					p->something();
					(*p).something();

					//Caller can not call DELETE on the address returned by ->operator 
					//delete(p->);

				}
	};

};