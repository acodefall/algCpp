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
 
	
	
	Q
	Implement the max sub array problem with the condition that adjacent numbers should not be added.
	Means 4th element can be added 1st and 2nd elements but not 3rd.
		ex: So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7)

	Solution is similar to subsetsum problem. In case of subsetsum problem, we add src[i] to sol[i-1]. 
	This is because we assume sol[i-1] has the best value 
	until that point so we do not check the values earlier to [i-1]
	
	Similarly in this problem, add src[i] to sol[i-2], assume [i-2] has the best value.
	To understand the solution array creation, imagibe an array of 4 elements.
	Introduce first element and also add it to solution[0]
	Introduce 2nd element, and src[1] can not be added to src[0] because they are neighbors,
	but we take the max among them and store at sol[1].
	src[1] directly comes to sol[2].
		sol[0] = src[0]
		sol[1] = max(src[0], src[1]);
		
	Introduce the 3rd element, and this can be added to 1st element only. 
		sol[2] = max(sol[0] + src[2], src[2]);
	
	Introduce the 4th element, and this can be added to either 1st or 2nd element. 
	But we know sol[2] has the best value so we simply add to 
		sol[3] = max(sol[1] + src[3], src[3]);
	*/
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