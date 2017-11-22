#pragma once
#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <unordered_map>
using namespace std;
namespace PlaceLettersApartNM //@RED20170617001
{
	/*
			Place same characters at X distance apart_20170617001
				Reorder the characters of a string so that same characters are distance d from each other.
							Input: { a, b, b }, distance = 2
							Output: { b, a, b }
		
				Rearrange the string so that repeating character are at constant distanxe from each other
				Ex: A repeats twice and C repeats 4 times. Problem says that repeating character should be 5 units apart.
				Then distance between one A to next A should be 5units; similarly distance between one C and next C should also be 5.
				Some other characters should take the the space existing between repeating characters.

				When re-arranging the characters follow this rule. Character repeats 3 times should come between the 
				characters that apppears 2 times.

				Solution is 
				create a map of character and their occurence count, and sort based so that most repeating character comes at the top.
				Once the map is ready, read the characters from the map and use it constructing output array..
				When reading from MAP, follow these rules
				-If the distance between the characters is 4, then read top 4 characters from MAP, and write them to output array.
				-When reading the next character start again from the top of the map.
				-decrement the count after reading a character
				-ignore the character if the count is zero


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