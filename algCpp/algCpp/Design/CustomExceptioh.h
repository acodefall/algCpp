#pragma once
#include <iostream>
#include <string>
#include <exception>
namespace CustomExceptionNM
{
	/*
		custom exception
			Custom exception would be usefull to unify different types of execptions. Ex: Win32 API returns TRUE or FALSE,
			COM classes returns HRESULT. If we want to unify these as exception object, define custome exception class.

			Define a class that will be passed to throw function. This class should derive from std::exception.
			The ctor of should accept the string-param, to be used as exception-message.
			Function that wants to throw the custom exception should instantiate the custom-exception class, by passing msg to CTOR.
			Then pass the instance to throw() function.

			 
	*/
	using namespace std;
	class CustomException : public std::exception
	{
		string report;
		public:
			CustomException(const char* msg) : exception(msg)
			{
				report = msg;
			}

	};

	class Cex
	{
		public:
			void testCex()
			{
				testCexWin32();
				testCexCpp();
				testCexCOM();
			}

			void testCexWin32()
			{
				try
				{
					CustomException wx("Win32 error");
					throw(wx);
				}
				catch (CustomException ex)
				{
					cout << ex.what();
				}
			}

			void testCexCOM()
			{
				try
				{
					CustomException wx("COM error");
					throw(wx);
				}
				catch (CustomException ex)
				{
					cout << ex.what();
				}
			}

			void testCexCpp()
			{
				try
				{

					CustomException wx("123");
					throw(wx);
				}
				catch (CustomException ex)
				{
					cout << ex.what();
				}
			}

	};
};