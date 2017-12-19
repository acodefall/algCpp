#pragma once
#include <algorithm>
using namespace std;
namespace AddAlternateNumbersDPNM //@RED20170726006
{

	/*
		0  1  2  3  4  
		3  2  5  10 7
  
		  0 + 2 + 4 = 15
		  0 + 3     = 13
		  0 + 4     = 10            s[0] -> could be 15, 13, 10. We take higher one 15. s[0] = 15

		  1 + 3     = 12
		  1 + 4     = 9             s[1] -> could be either 9 or 12. We take higher one 12. s[1] = 12 

		  2 + 4     = 13            s[2]

		  3         = 10            s[3]

		  4			= 7             s[4]  
 
	
	*/
	//Q
	//Given an array all of whose elements are positive numbers, find the maximum sum of a sub - sequence with the constraint 
	//that no 2 numbers in the sequence should be adjacent in the array.
	//So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7)

	//WRONG
	//Answer does not match amzaon question. Flaw is this solution simply adds alterantive numbers.
	//We are supposed to add alternative elements. We maintain the even-sum in 'backback' amd odd sum in 'back'
	//In the beginning backback = d[0] and back = d[1].
	//When we go to ANY index, the value at current index will be added to backback and output will be placed at back.
	//And we also know backback and back has two types of sum, and going forward we want only one of them, so select the max of it and store in backback.
	//So backback is oldest and could have come from even-sum or odd-sum. This is the flaw.
	class AddAlternateNumbersDP
	{
		public:
			void callAddAlternateNumbersDP()
			{
				int data1[] = {3,2,7,10};
				int data2[] = { 3,2,5,10,7};
				int saved[50] = { -1 };
				int iterations = 1;

				AlternateSumWithoutDPY(data1, 4);
				AlternateSumWithoutDPY(data2, 5);
			}

			void AlternateSumWithoutDPY(int* src,int Len)
			{
				const int MAX = 50;
				int sol[MAX] = {0};
				
				sol[0] = src[0];
				sol[1] = max(sol[0], sol[1]);
				int i = 0;
				for(i = 2; i < Len; i++)
				{
					int x = src[i] + sol[i-2];
					
					//computing the value for Sol[i].
					//Decide whether we should take the value from past or just use the current value
					if( x > src[i])
						sol[i] = x;
					else
						sol[i] = src[i];
				}
				
				cout << "max value " << sol[i-1] << endl;
				
			}
	};
};