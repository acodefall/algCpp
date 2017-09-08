#pragma once
#include <iostream>
#include <unordered_set>
using namespace std;

namespace FindLowerRepeatIndexUnSortedNM
{
	/*
		Find the lower-index of first repeating element in an array_RED20170907001
			Find the index of the DUPLICATE number that is towards FRONT of the array.
			Duplicate number will have one index towards FRONT and other towads ENDS; and we are supposed to find the index that is near the FRONT, not the TAIL.
			We can identify the DUPLICATE element using HASH_SET, but we want the index that is closest to FRONT. Strategy is iterate the array from TAIL to END. 
			All along the way memorize the number that repeats and also its index. Once we complete iteration we will have the index of duplicate number found closest to FRONT.
			Conversly to know the the index of the DUPLICATE number that is towards END, iterate the array from FRONT- To-TAIL
			
			Say array is {1, 12, 5, 12}
			[1] -> Lower-repeat-index
	        [3] -> Higher-repeat-index
   
	*/
	const int SIZEX = 11;
	class FindLowerRepeatIndexUnSorted
	{
		public:

				void callFindLowerRepeatIndexUnSorted()
				{
					int Src[SIZEX] = { 0, 12, 1, 1, 2, 2, 4, 4, 4, 5, 5 };
					LastRepeatingIndex(Src);
				}
				void LastRepeatingIndex(int Src[SIZEX])
				{
					int LastRepeatIndex = 0;
					unordered_set<int> sh;
					for (int i = SIZEX - 1; i >= 0; i--)
					{

						if (sh.find(Src[i]) != sh.end())
						{	//duplicate element
							LastRepeatIndex = i;
						}
						else
						{
							sh.insert({Src[i]});
						}
					}
					
					cout << "Lower-repeat-index " << LastRepeatIndex << " Value is " << Src[LastRepeatIndex] << endl;
				}

	};
};