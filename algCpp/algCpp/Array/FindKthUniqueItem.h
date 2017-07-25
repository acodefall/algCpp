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
		  Find the Kth non-repeating Character in a String_@RED20170724004
                A word will have a series of characters that repeat, and also series of characters that do not repeat. 
				If the Question asks for 2nd non-repeating character, then return 2nd element from non-repeating series.
				non-repeating series is built using Array(say Index[]). Value of Index[] is the position of non-repeating character in src[].
				Index[] stores the index in to src[] provided the character is non-repeating. If the character repeats then value will be -1.
				By sorting the Index[], we can arrange non-repeating characters according to their position in src[].
				Sorting will bring non-repeating character (who's position is least) to TOP of Index[].
				and repeating characters will go to bottom of Index[] because their index is -1.
				To know 2nd non-repeating character, use the 2nd item in post-sorted-index[].

				To know whether a character repeats or not, we have to maintain occurence-count for each character, so we need occurence[].
				So basically we need two arrays: Index[] and occur[]. Length of these arrays is 256, and index is character itself, stored in src[]. (say 'a')
				We fill both arrays in same loop. 
				Iterate the src[].
				When we see 'a', 
					set occur['a'] = 1, 
					set Index['a'] = position of 'a' in src[]

					if we encounter 'a' for the second time, 
						set occur['a'] = 2,
						set Index['a'] = -1

				After iterating the whole src[], sort the Index[].
				To know 2nd non-repeating character, use the 2nd item in post-sorted-index[].

				Find the Kth non-repeating Character in a String
				 s s t r e s s     occur[] -> occurance of each character
				 0 1 2 3 4 5 6     Index[] -> position of non-repeating char as in src[]

				Construct occur[] and Index[]
								occur['e'] = 1	    Index['e'] = 4  //4 is position of 'e' in src[]						  				occur['r'] = 1      Index['r'] = 3  //3 is position of 'r' in src[]
								occur['s'] = 4      Index['s'] = -1 //-1 because it repeats
								occur['t'] = 1      Index['t'] = 2  //2 is position of 't' in src[]	
				
				Sort the Index[]  arranges non-repeating characters according to their position in src[].
								Index['t'] = 2   //2nd non-repeating character
								Index['r'] = 3
								Index['e'] = 4
								Index['s'] = -1


				

				
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