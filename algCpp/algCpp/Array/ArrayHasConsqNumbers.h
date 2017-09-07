#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;

class ArrayHasConsecutiveNumber
{

	//Procedure is
	//Logic is if the numbers are consecutive then the MAX-MIN should be equal to Array Len, provided there are no dupliacets. Our code should check that
	//a) Compute the MIN and MAX
	//b) Compare array length with MAX-MIN + 1
	//c) Verifiy there are no duplicates.
	//d) if all these conditions are met then we can say that array has consecutive numbers
	public:
		void callArrayHasConsecutiveNumber()
		{
			int data[6] = { 4,5,6,7,8,9 };
			ArrayHasConsecutiveNumberX(data, 6);
		}


		void ArrayHasConsecutiveNumberX(int* data, int len)
		{
			unordered_set<int> sh;

			//find max & min
			int Mx = data[0];
			int Mn = data[0];

			for (int i = 0; i < len; i++)
			{
				if (data[i] > Mx)
					Mx = data[i];
				if(data[i] < Mn)
					Mn = data[i];
			}


			if (len == (Mx - Mn + 1))
			{
				int i = 0;
				for (i = 0; i < len; i++)
				{
					if (sh.find(data[i]) == sh.end())
					{
						sh.insert(data[i]);
					}
					else
						break;
				}
			
				if (i < sh.size())
				{
					cout << "Not a Sequence";
				}
				else
					cout << "Sequence";
			}
			else
			{
				cout << "Not a SequenceX";
			}
		}
};