#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <sstream>
using namespace std;

namespace FindKthUniqueItemNM
{
	/*
		  Find the Kth non-repeating Character in a String_GN820
                String s={“sTress”} should return T
                -Use two auxillary arrays of size 256, called INDEX and OCCURANCE.
                 OCCURANCE[] role is, it helps to create Index[]. And Index[] will have index of the 
                 non-repeating characters.
 
                -Scan the src array and store occurance of character in OCCURANCE[]. Use Character as index.

                -INDEX[] will have been initialized to 256. When we encounter the character for the first time, store the
                 index-i in INDEX[]. Say when we encounter character 'T' at 5th position, we set
                 Index[T] to 5. Say we encounter 'T' yet again, then we reset the Index[T] = 256.

                -In the end, we sort the Index array. Array will have values that are not 256, and they will signify the index
                 where character is not repeating. If you want 2nd non repeating character, use the index stored in Index[1], 
                 to get the character from Src[].

				
					Src[0] = s is fresh
					Occurence[115] = 1  PlaceIndex[115] = 0

					Src[1] = o is fresh
					Occurence[111] = 1  PlaceIndex[111] = 1

					Src[2] = s is duplicate
					Occurence[115] = 2  PlaceIndex[115] = 2147483647

					Src[3] = o is duplicate
					Occurence[111] = 2  PlaceIndex[111] = 2147483647

					Src[4] = m is fresh
					Occurence[109] = 1  PlaceIndex[109] = 4

					Src[5] = e is fresh
					Occurence[101] = 1  PlaceIndex[101] = 5

					Src[6] = t is fresh
					Occurence[116] = 1  PlaceIndex[116] = 6

					Src[7] = e is duplicate
					Occurence[101] = 2  PlaceIndex[101] = 2147483647

					Src[8] = x is fresh
					Occurence[120] = 1  PlaceIndex[120] = 8

					Src[9] = t is duplicate
					Occurence[116] = 2  PlaceIndex[116] = 2147483647

					PlaceIndex Array (after sorting)
					PlaceIndex[0] = 4
					PlaceIndex[1] = 8
					PlaceIndex[2] = 2147483647
					PlaceIndex[3] = 2147483647
					PlaceIndex[4] = 2147483647
					PlaceIndex[5] = 2147483647
					PlaceIndex[6] = 2147483647
					PlaceIndex[7] = 2147483647
					PlaceIndex[8] = 2147483647
					PlaceIndex[9] = 2147483647

					K th(2) unique item is at 8 Item is x


   
	*/
	class FindKthUniqueItem
	{
		public:

				void callFindKthUniqueItem()
				{
					string src("sosometext"); 
					FindKthUniqueItemX(src,2);
				}
				void FindKthUniqueItemX(string srcIn, int K)
				{
					const char* Src = srcIn.c_str();
					int PlaceIndex[CHAR_MAX]; //This tracks the index of 
					int Occurence[CHAR_MAX]; //This tracks the index of  //maintains the occurence count for chars in srcIn
					
					//Init the crap
					for (int i = 0; i < CHAR_MAX; i++)
					{
						PlaceIndex[i] = INT_MAX;
					}
					for (int i = 0; i < CHAR_MAX; i++)
					{
						Occurence[i] = 0;
					}

					for (int i = 0; i < srcIn.length(); i++)
					{
						cout << endl << "Src[" << i << "] = " << Src[i];
						if (Occurence[Src[i]] > 0)
						{	//duplicate element
							cout << " is duplicate ";
							PlaceIndex[(Src[i])]= INT_MAX;
							
						}
						else
						{	//first time we are seeing Src[i], so record the real-index in PlaceIndex.
							cout << " is fresh ";
							PlaceIndex[Src[i]] = i;
						}
						Occurence[Src[i]]++;
						cout << endl << "Occurence[" << (int)Src[i] << "] = " << Occurence[(Src[i])];
						cout << "  PlaceIndex[" << (int)Src[i] << "] = " << PlaceIndex[(Src[i])] << endl;
						
					}

					//print occurance array
					/*stringstream ss;
					int last = 10;
					for (int h = 0; h < CHAR_MAX; h++)
					{
						ss << "[" << h << "] = " << Src[h] << " ";
						if (last == 10)
						{
							ss << endl;
							last = 0;
						}
						last++;
					}
					cout << endl << "occurance Array" << endl;
					cout << ss.str();

					//print PlaceIndex array
					ss.clear();
					last = 10;
					for (int h = 0; h < CHAR_MAX; h++)
					{
						ss << "[" << h << "] = " << PlaceIndex[h] << " ";
						if (last == 10)
						{
							ss << endl;
							last = 0;
						}
						last++;
					}
					cout << endl << "PlaceIndex Array" << endl;
					cout << ss.str();*/

					//sort the PlaceIndex
					sort(std::begin(PlaceIndex), std::end(PlaceIndex));

					//print fist 10 PlaceIndex array After sorting
					cout << endl << "PlaceIndex Array (after sorting)" << endl;
					for (int h = 0; h < 10; h++)
					{
						cout << "PlaceIndex[" << h << "] = " << PlaceIndex[h] << endl;
					}
					
					cout << endl;

					cout << "K th (" << K << ")unique item is at " << PlaceIndex[K-1] << " Item is " << Src[PlaceIndex[K - 1] ]<<endl;
				}
	};
};