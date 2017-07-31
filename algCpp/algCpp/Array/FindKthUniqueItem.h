#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <sstream>
using namespace std;

namespace FindKthUniqueItemNM //@RED20170724004
{
	/*
		  Find the Kth non-repeating Character in a String_GN820
		  Find the Kth non-repeating Character in a String_20170724004
				String will have duplicate and non-duplicate characters. 
				Src = {pqqr}. R is the 2nd non-repeating character, and P is the 1st non-repeating character.
				We should return r, if the Question asks for 2nd non-repeating character.

				We have to know non-repeating characters and also their order of appearance in src[]. Maintain this info in an INDEXARRAY for every character. KEY is INT-of-CHARCTER and VALUE is index of that char.
				If ‘r’ appears at 4th place in src[], then store indexARRAY[‘r’] = 4;
				If a character is dupliate then VALUE will be -1. If a character is non-dupliate then VALUE will be the index(inside src[])
				indexARRAY[‘q’] = -1.

				VALUE for non-dupliate character will be the index where they appear in src[].
							indexARRAY [‘q’] = -1.
							indexARRAY [‘r’] = 4;
 
				Since the VALUE is the INDEX, by sorting the indexARRAY[], we can arrange the non-duplicate characters according to their solt in src[].Sorting will pushe dupliactes characters to bottom of indexARRAY[] (because their index is -1).
				//SORT 
						   indexARRAY[‘r’] = 4.  //1st non-duplicate character’s index
							indexARRAY[‘q’] = -1;

				To know whether a character is duplicate or not, we have to maintain it occurrence count. So basically we need two arrays: indexARRAY[] and Occurrence[]. For both arrays KEY is INT-of-CHARCTER. For Value for Occurrence[] is occurance count. Since characters are ASCII, use array of 256 length for both indexARRAY[] and Occurrence[].
					We can fill both arrays in same loop. 
						Iterate the src[].
							When we see 'a'
							Occurrence['a'] = 1 //Update Occurrence[] with count of 'a'.
							
							If(count > 1)	
								indexARRAY['a'] = -1; //if we encounter 'a' for the 2nd time, store -1
							else
								indexARRAY['a'] = curIndex; //if we encounter 'a' for the 1st time, store index
	
						Sort(indexARRAY); // After iterating the whole src[], sort the indexARRAY[]
					To know 2nd non-repeating character, use the 2nd item in indexARRAY[].



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
					int PlaceIndex[CHAR_MAX]; //KEY is character, VALUE is index of character in src[]
					int Occurence[CHAR_MAX]; //KEY is character, VALUE is occurence count of character
											 //Since the character is US-ASCII, use CHAR_MAX array
					
					//Init the crap
					for (int i = 0; i < CHAR_MAX; i++)
					{
						PlaceIndex[i] = INT_MAX;
					}
					for (int i = 0; i < CHAR_MAX; i++)
					{
						Occurence[i] = 0;
					}

					//Build both PlaceIndex[], Occurence[]
					for (int i = 0; i < srcIn.length(); i++)
					{
						//cout << endl << "Src[" << i << "] = " << Src[i];
						if (Occurence[Src[i]] > 0)
						{	//duplicate element
							cout << " is duplicate ";
							PlaceIndex[Src[i]]= INT_MAX; //KEY is Src[i]
							
						}
						else
						{	//first time we are seeing Src[i], so record the real-index in PlaceIndex.
							cout << " is fresh ";
							PlaceIndex[Src[i]] = i;
						}
						Occurence[Src[i]]++; //KEY is Src[i]
						//cout << endl << "Occurence[" << (int)Src[i] << "] = " << Occurence[(Src[i])];
						//cout << "  PlaceIndex[" << (int)Src[i] << "] = " << PlaceIndex[(Src[i])] << endl;
						
					}

					

					//sort the PlaceIndex.
					//Since the VALUE is INDEX in src[], by sorting the PlaceIndex[], we can arrange the non-duplicate 
					//characters according to their slot in src[].
					//sorting will push dupliactes characters to bottom of PlaceIndex[] (because their index is -1). 
					sort(std::begin(PlaceIndex), std::end(PlaceIndex));

					//print fist 10 PlaceIndex array After sorting
					cout << endl << "PlaceIndex Array (after sorting)" << endl;
					for (int h = 0; h < 10; h++)
					{
						cout << "PlaceIndex[" << h << "] = " << PlaceIndex[h] << endl;
					}
					
					cout << endl;

					//To know 2nd non-repeating character, fetch its index from  PlaceIndex[2]
					cout << "K th (" << K << ")unique item is at " << PlaceIndex[K-1] << " Item is " << Src[PlaceIndex[K - 1] ]<<endl;
				}
	};
};