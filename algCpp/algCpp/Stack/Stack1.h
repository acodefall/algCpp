#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>

using namespace std;




template<typename T>
class Stack1
{
	int index;
	T Data[_MAX_PATH];
	public:
		Stack1()
		{
			index = -1;
			for each (T var in Data)
			{

			}
		}

		int Push(T x)
		{
			if (index == _MAX_PATH)
				return -1;
			index++;
			Data[index] = x;
		}

		T Pop()
		{
			T ret;
			if (index == -1)
				return -1;
			ret = Data[index];
			index--;
			return ret;
		}


};


class StackTest
{
public:
	void TestStack()
	{
		Stack1<int> v1;
		v1.Push(1);
		v1.Push(12);
		cout << v1.Pop() << "\r\n";
		v1.Push(13);
		v1.Push(15);
		cout << v1.Pop() << "\r\n";
		cout << v1.Pop() << "\r\n";

	}

};