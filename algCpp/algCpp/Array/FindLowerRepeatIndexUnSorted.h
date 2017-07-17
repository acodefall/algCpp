#pragma once
#include <iostream>
#include <unordered_set>
using namespace std;

namespace FindLowerRepeatIndexUnSortedNM
{
	/*
		Find the lower-index of first repeating element in an array
			Array may have several numbers that repeats several times; and these repeating numbers will have lower-index and also higher-index.
			We will be asked to find out either the lower-repeat-index and also higher-repeat-index; number could be anything, all they need is repeating index. 
			
			To know the lower-repeat-index, interate the array from FAR-end, and use Hash Table to detect duplicate element; and record the index of duplicate elements.
			Once the iteration is complete, we will have lower-repeat-index. 
			To know the higher-repeat-index, interate the array from FRONT-end.

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