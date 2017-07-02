#pragma once
#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <unordered_map>
using namespace std;
namespace PlaceLettersApartNM
{
	/*
			Place same characters at X distance apart_20170617001
				Reorder the characters of a string so that same characters are distance d from each other.
							Input: { a, b, b }, distance = 2
							Output: { b, a, b }
		
				Our first thought is going to be to create a collection of repeating and non-repeating characters. Then take a character from repeating collection and place it in out-array; and then take few characters from non-repeating collection and place them in out-array as seperator.

				This strategy will fail if there characters that repeat twice, thrice and four times. Our solution should use both less-repeating characters(twice repeating) and non-repeating characters as space fillers. This means, non-reapting characters become space-fillers for twice-repeating characters; and twice-appearing characters will become space-fillers for thrice-repeating charcters. So the ideal solution should order the characters by their occurrence count, and read top-D letters(ingoring the letters with 0 count), and write them in to output array. Then go back to the list and read top-D letters again, and write them also in to output array. 2nd-read is the crucial step, and this is responsible for placing the repeating characters D-distance apart. Repeat this loop until the we have read all the characters. 

				If D = 3, read 1st, 2nd and 3rd and print them, and decrement occurence count for these characters; and write these to out-array. Now make a U-turn Now the index will be at 3, and take it back to index-0, and again pick top-3 characters and print them. Skip the characters who's count is 0. 	As program approches the end, there will be many characters with occurence count 0. Drawback of this algorithm is that we go through the whole array several times. We can optimize this by deleting the characters who’s count is 0. This should be done after successfully picking 3/D items. This will make the list shrink.
		
				Steps for Placing same characters at a distance X _20170617002
						a) Go through the src-array and build an unordred_map of character/occurrence count, and use the map to create instances of a structures that holds "character and its count".
						b) Then Load structure instances in to a List, and then sort the list so that most-occuring characters come at the top.
						c) Now start processing. 
						There will be three nested while loop, outer most loop goes until all the characters are read from list, it is just making sure that we have read every letter from List.
						Inner-while loop is responsible for reading D-letters from List, writing them to out-array, decrementing count in original list, and incrementing the counter ‘TotalCharsProcessed’. Inner-most-while loop is a helper used by 2nd while loop, for skipping the letters who’s count is 0, and this loop just goes on incrementing the List::iterator if the count is 0. 

						We use Iterator for reading from List, outer-mostLoop set the iterator to List.Begin() after reading every D-letters. And 2nd whileLoop reads from iterator, provided by 3rdWhile loop. Both 2nd and 3rd while loop advance iterator, 

						Function params are "list ", D/distance, and srcLen.
  
						  Set TotalCharsRead = 0. 
						  Start the Outer while-loop and it goes until (TotalCharsProcessed < srcLen)
						  Set the list-iterator to point to List.begin()
						  Start a 2nd-while loop, this goes until 
							((charCountSucessfullyPulled < D) && (itr != occurMap.end()))
							2nd-while loop starts 3rd-whileLoop to skip the items who’s count is 0.
							3rd-whileLoop goes until (itr != occurMap.end()), and advances itr if char-count is 0, otherwise breaks the loop.
							Once the 3rd-whileloop returns to 2nd-WhileLoop, 2nd-WhileLoop uses the itr to read the character; decrements the counter for the character; increments itr and also TotalCharsProcessed
							2nd-while loop exits after successfully picking D/3 characters from list. 
							Controls comes back to outermost loop. And it starts the 2ndWhileLoop again to read next D characters.


				   //geeksforgeeks
				   e=4   3  2    1    0
				   g=2   1  0    0    0
				   k=2   1  0    0    0
				   s=2           1    0
				   f             0    0
				   o             1    0
				   r             1    1
				   //egkegkesfesor


	*/
	//map<int, char>
	struct Letter
	{
		char c;
		int count;
	};
	struct compr
	{
		bool operator()(shared_ptr<Letter> p1, shared_ptr<Letter> p2)
		{
			bool bret = false;
			bret = (p1->count > p2->count) ? true : false;
			return bret;
		}
	};
	class PlaceLettersApart
	{
		public:
			void CallPlaceLettersApart()
			{
				int distance = 3;

				//SetLettersApart();
				const char* src("geeksforgeeks"); //egkegkesfesor
				list<shared_ptr<Letter>> occurMap;

				/*
					IN: geeksforgeeks
					OT: egsegsekoekfr
				*/
				cout << "\r\n";
				cout << "computeOccurance() \r\n" << src << "\r\n";
				computeOccurance(src, occurMap);
				for (auto itr = occurMap.begin(); itr != occurMap.end(); itr++)
				{
					cout << "\r\n";
					cout << (*itr).get()->c << "  " << (*itr).get()->count << " \r\n";

				}
				cout << "\r\n";
				//egkegkesfesor

				string out = PlaceLettersApartx(occurMap, distance, strlen(src));
				cout << "\r\n";
				cout << src << "\r\n";
				cout << out.c_str() << "\r\n";
				cout << "\r\n";

			}

			void computeOccurance(const char* src, list<shared_ptr<Letter>>& occurMap)
			{
				unordered_map<char, int> charOccurMapTemp;
				const char* p = src;
				while (*p != '\0')
				{
					if (charOccurMapTemp.find(*p) == charOccurMapTemp.end())
					{
						charOccurMapTemp.insert({ (char)*p, 1 });
					}
					else
					{
						charOccurMapTemp[*p]++;
					}
					p++;
				}


				for (auto itr = charOccurMapTemp.begin(); itr != charOccurMapTemp.end(); itr++)
				{
						shared_ptr<Letter> ltr = make_shared<Letter>();
						ltr.get()->c = (*itr).first;
						ltr.get()->count = (*itr).second;
						occurMap.push_back(ltr);
				}
				compr xcmp;
				occurMap.sort(xcmp);

			}
			/*
				e=4   3  2    1    0
				g=2   1  0    0    0
				k=2   1  0    0    0
				s=2           1    0 
				f             0    0 
				o             1    0
				r             1    1

				i = items taken out.

				i = 0 
				e g k
				i = 2

					i = 0
					e g k 
					i = 2
						i = 0 
								e s f
								i = 2

									 i = 0
									 e s o
									 i = 2
											i = 0    
											r
											i = 1

			*/

			/* 		
					
			*/
			string PlaceLettersApartx(list<shared_ptr<Letter>>& occurMap, int strideLength, int srcLen)
			{
				string out;
				
				
				int TotalCharsProcessed = 0;
				while (TotalCharsProcessed < srcLen)
				{
					int charCountSucessfullyPulled = 0;

					list<shared_ptr<Letter>>::iterator itr = occurMap.begin();
					while ((charCountSucessfullyPulled < strideLength) && (itr != occurMap.end()))
					{
						//use itr and get the next non-zero item
						while ((itr != occurMap.end()))
						{
							if ((*itr).get()->count == 0)
								itr++;
							else
								break;
						}
					
						//reduce the count for extracted item
						char c = (*itr).get()->c;
						(*itr).get()->count = (*itr).get()->count - 1;
						out += c;
						TotalCharsProcessed++;


						//get the letter from non-zero item and add it to string
						charCountSucessfullyPulled++;
						itr++;
					}
					
				}
				return out;
			}
	};
};