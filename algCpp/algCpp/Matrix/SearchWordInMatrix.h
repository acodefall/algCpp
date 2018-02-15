#pragma once
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace SearchWordInMatrixNM
{
	/*
		Searh for Word in character Matrix_RED20180209006
		
		Look for 1st letter of the word in current cell, if it is found then look for 2nd character in any of the
		immidiate neighbors. If any of recutsion call finds the 2nd letter, then it will make recursion call in to its neigbors, looking for 3rd character. 
		if the any of the 
		for tit succeeds, the Starting from a cell make recursive call in to neighboring cells until Cell of a matrix has characters and we have to search 			

	*/
	const int Mr = 4;
	const int Mc = 4;
	class SearchWordInMatrix
	{
		public:
			void SearchWordInMatrixX()
			{
				char src[Mr][Mc] =
				{
					{ 'A', 'B', 'C', 'E' },
					{ 'S', 'F', 'C', 'S' },
					{ 'A', 'D', 'E', 'E' }
				};

				vector<vector<char>> dict;
				dict.push_back(vector<char>{ 'A', 'B', 'C', 'C', 'E', 'D' });
				dict.push_back(vector<char>{ 'S', 'E', 'E'});
				dict.push_back(vector<char>{ 'A', 'B', 'C','B'});
				/*char src[Mr][Mc] =
				{
					{ 'o','a','a','n' },
					{ 'e','t','a','e' },
					{ 'i', 'h', 'k', 'r' },
					{ 'i','f','l','v' }
				};

				vector<vector<char>> dict;
				dict.push_back(vector<char>{ 'o','a','t','h' });
				dict.push_back(vector<char>{ 'e', 'a', 't'});*/

				for (auto itr = dict.begin(); itr != dict.end(); itr++)
				{
					SearchWords(src, (*itr));
				}
			}

			bool SearchWords(char src[Mr][Mc], vector<char> word)
			{
				bool retvalue = false;
				for (int i = 0; i < Mr; i++)
				{
					for (int j = 0; j < Mc; j++)
					{
						retvalue = searchForLetters(src, word,i,j,0);
						if (retvalue)
							break;
					}
					if (retvalue)
						break;
				}
				return retvalue;
			}

			bool searchForLetters(char src[Mr][Mc], vector<char> word, int r, int c, int wi)
			{
				if (wi == word.size())
					return false;

				if ((r < Mr) && (c < Mc))
				{
					//current letter matches
					if (word[wi] == src[r][c])
					{
						char cache = src[r][c];
						src[r][c] = '#'; //remove current word from list
						if (wi + 1 == word.size()) //This is the last letter of the word being searched do return TRUE
							return true;
						
						

						//Current letter matches but there are still words to check so make rec-call
						bool a = searchForLetters(src, word, r + 1, c, wi + 1);
						bool b = searchForLetters(src, word, r, c + 1, wi + 1);
						bool f = searchForLetters(src, word, r - 1, c, wi + 1);
						bool d = searchForLetters(src, word, r, c - 1, wi + 1);

						if (a || b || f || d)
						{
							//src[r][c] = cache; //remove current word from list
							return true;
						}
						src[r][c] = cache; //remove current word from list
					}
					
				}

				return false;
			}
	};
};