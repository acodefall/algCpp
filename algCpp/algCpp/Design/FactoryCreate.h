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

namespace FactoryCreateNM
{
	/*
		Factory create pattern_RED20180209008
		Factory create pattern: Factory create pattern provides a template for creating an object, given an object-name as input. 
		Factory class will have just one public-static method and takes object-name as input. It creates the concreate class
		that corresponds to object-name and return the pointer to caller. Pointer is type-casted to abstract base class at the time of 
		returning. Every class created by factory method should have same abstract base class. This is because return type 
		of the static-method is hard coded to be abstract base class. 
		Ex: Static function creates emails of type calender, Task, message and returns IMessage object.  
		So concreate class for calender, Task, message should derive from IMessage.  Static function will create corresponding 
		class and returns returns it to caller, as IMessage.
		
		If the Factory class wants to return different abstract object, then it should have another static function.
		
		Coming to implementation:
		a) Declare IMessage interface class, with PURE virtual functions and virtual dtor with empty body.
		b) Declare CCalender, CTask classes and let them derive from IMessage. And these concrete classes should declare their DTOR as virtual.
		c) Finally implement Factory class. It should have public-static function that accepts class-name as input and returns 
		   IMessage.
		d) Implementation of the fuction should have switch case for creating appropriate concreate class based on input.
		e) Function can return unique_ptr<Imessage>
	*/
	class IMailServer
	{
		public:
			virtual string Name() = 0;
			virtual ~IMailServer() {}
	};

	class Mail1 : public IMailServer
	{
		string name;
		public:
				Mail1()
				{
					name = "Mail1";
				}
				string Name()
				{
					return name;
				}

				virtual ~Mail1()
				{
					cout << "~Mail1" << endl;
				}
	};

	class Mail2 : public IMailServer
	{
		string name;
		public:
				Mail2()
				{
					name = "Mail2";
				}
				string Name()
				{
					return name;
				}

				virtual ~Mail2()
				{
					cout << "~Mail2" << endl;
				}
	};

	/*


		
			
		
	*/
	class MailSeverFactory
	{
		public:
			static unique_ptr<IMailServer> createMailServer(string s)
			{
				if (s == "Mail1")
				{
					return unique_ptr<IMailServer>(new Mail1());
				}
				else if (s == "Mail2")
				{
					return unique_ptr<IMailServer>(new Mail2());
				}
				else
				{
					return 0;
				}
			}
	};
	class useMailServer
	{
		public:
			void createMailServers()
			{
				unique_ptr<IMailServer> m1 =  MailSeverFactory::createMailServer((string)"Mail1");
				unique_ptr<IMailServer> m2 = MailSeverFactory::createMailServer((string)"Mail2");

				if (m1)
				{
					string s = m1->Name();
					cout << s << endl;
				
					m1 = 0;
				}

				if (m2)
				{
					string s = m2->Name();
					cout << s << endl;
					m2 = 0;
				}
			}
	};

};
