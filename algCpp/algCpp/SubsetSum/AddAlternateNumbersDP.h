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

				for (int i = 0; i < 50; i++)
					saved[i] = -1;
				iterations = 1;
				AlternateSumWithoutDP(data1, 4, 0, saved, &iterations);

				for (int i = 0; i < 50; i++)
					saved[i] = -1;
				iterations = 1;
				AlternateSumUsingDP(data1, 4, 0, saved, &iterations);

				for (int i = 0; i < 50; i++)
					saved[i] = -1;
				iterations = 1;
				AlternateSumWithoutDP(data2, 5, 0, saved, &iterations);

				for (int i = 0; i < 50; i++)
					saved[i] = -1;
				iterations = 1;
				AlternateSumUsingDP(data2, 5, 0, saved, &iterations);

				int x = AddAlternateNumbersDPX(data1, 4); //13 (correct)
				int y = AddAlternateNumbersDPX(data2, 5); //15 (wrong - 14. should have been 15)
			}

			int AlternateSumWithoutDP(int* src,int Len, int s, int* saved, int* iterations)
			{
				int retvalue = 0;
				if (s < Len)
				{
					(*iterations)++;
					int baseValue = src[s];
					int m = 0;
					int i = s + 1;
					while (i < Len)
					{
						int x = AlternateSumWithoutDP(src, Len, i, saved, iterations);
						if((i - s) > 1)
							m = max(m, x);
						i++;
					}
					retvalue = saved[s] = baseValue + m;
				}
				return retvalue;
			}

			int AlternateSumUsingDP(int* src, int Len, int s, int* saved, int* iterations)
			{
				int retvalue = 0;
				if (s < Len)
				{
					(*iterations)++;
					int baseValue = src[s];
					int m = 0;
					int i = s + 1;
					while (i < Len)
					{
						int x = 0;
						if (saved[i] == -1)
							x = AlternateSumUsingDP(src, Len, i, saved, iterations);
						else
							x = saved[i];

						if ((i - s) > 1)
							m = max(m, x);
						i++;
					}
					retvalue = saved[s] = baseValue + m;
				}
				return retvalue;
			}

			/*
				So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7)
			*/
			int AddAlternateNumbersDPX(int* data, int len)
			{
				int back = data[0]; //holds cum sum at 0th
				int backback = data[1]; //holds cum sum at 1sth
				for (int i = 2; i < len; i++)
				{
					int maxSum = max(backback, back);
					int tmp = backback;
					backback = maxSum;
					back = tmp + data[i];
				}

				return max(back, backback);
			}


	};
};