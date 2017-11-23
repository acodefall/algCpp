#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>

using namespace std;

namespace BreakLongWordToSubwordsNM
{
	/*
		Long word break problem_@RED20170816001
			Check whether the word "newspaper" has the subwords "spa, ape, new" in it. 
			We have to break the longword in to subwords using combinator technique, and check whether the subwords are present in the dictionary provided by caller.
			We can generate many subwords, this is because the subwords can have as low as single letter. But all subwords are not valid words. Only the words given in dictionary are valid words.

			Combinator technique used for generating subwords can be generatlized as follows. 
			Combinator will not make a combination by dropping a middle character.
			Ex: "Rat" There won't be combination called "Rt". But there will be "r a t  ra at rat"
		

			Say word is �iLike�. 
			Combinations[iLike] = �I� + Combinations[Like]
			Prefix �I� to every combination generated by �Like�. If �Like� has 6 combinations, prefix �I� to every one of them.

			Combinations[Like] = �L� + Combinations[ike]
			Combinations[ike] = �i� + Combinations[ke]  
			Combinations[ke] = �k� + Combinations[e]  
			Combinations[e] = �e� + No more to divide.

			Recursion(�Like�)
			{
				L + Recursion(�ike�)
					  {
					i + Recursion(�ke�)
						 {
						k + Recursion(�e�)
							{
							Retunn e
							 }
						 }
					  }		
			}

		hxxps://en.wikipedia.org/wiki/Composition_%28combinatorics%29

		This is how combination creation works.

		"ilike" can be split in 5 ways as shown below 
				a) i + like (extract i and subdivide the rest 'like')
						 l i k e ke ik e ike li k e ke lik e like
					i l i k e ke ik e ike li k e ke lik e like
		
				b) il + ike (extract il and subdivide the rest 'ike')
						 i k e ke ik e ike
					i l i k e ke ik e ike li k e ke lik e like il i k e ke ik e ike
		
				c)	ili + ke (extract ili and subdivide the rest 'ke')
						  k e ke
					i l i k e ke ik e ike li k e ke lik e like il i k e ke ik e ike ili k e ke

				d)	ilik + e (extract ilik and subdivide the rest 'e')
							e
					i l i k e ke ik e ike li k e ke lik e like il i k e ke ik e ike ili k e ke ilike

				e) ilike + "" (nothing sudivide)

		What is Overlapping problem?
			This is combinator problem. Combinations of 3 is =  Combinations of 2 +  Combinations of 1.
			Overlapping problem is the problem 

		
	*/
	class BreakLongWordToSubwords
	{
	public:
		void callBreakLongWordToSubwords()
		{
			int loopCount = 0;
			string src("newspaper");
			list<string> dictionary;
			dictionary.push_back("new");
			dictionary.push_back("spa");
			dictionary.push_back("paper");
			dictionary.push_back("per");
			dictionary.push_back("ape");
			dictionary.push_back("news");

			string parts = WordBreakUsingRecursion(src, &loopCount);
			cout << endl << "iterations(rec) " << loopCount << endl;
			for (auto itr = dictionary.begin(); itr != dictionary.end(); itr++)
			{
				if (parts.find((*itr).c_str()) != -1)
				{
					cout << (*itr).c_str() << " Y" << endl;
				}
				else
				{
					cout << (*itr).c_str() << " N" << endl;
				}
			}

			cout << endl;
			loopCount = 0;
			map<string, string> history; //MAP of Word/Cpmbinations
			parts = WordBreakUsingDP(src, history, &loopCount);
			cout << endl << "iterations(DP) " << loopCount << endl;
			for (auto itr = dictionary.begin(); itr != dictionary.end(); itr++)
			{
				if (parts.find((*itr).c_str()) != -1)
				{
					cout << (*itr).c_str() << " Y" << endl;
				}
				else
				{
					cout << (*itr).c_str() << " N" << endl;
				}
			}

			/*
				iterations(rec) 256
					new Y
					spa Y
					paper Y
					per Y
					ape Y
					news Y


				iterations(DP) 9
					new Y
					spa Y
					paper Y
					per Y
					ape Y
					news Y
							*/
		}

		//
		string WordBreakUsingRecursion(string remainingWord,int* loopCount)
		{
			string allCombs;
			string src = remainingWord;
			int len = src.length();
			(*loopCount)++;
			//src = iLike
			//firstPart will be {"i", "iL", "iLi", "iLik", "iLike"}
			for (int i = 0; i < len; i++)
			{
				//divide the src  as 1st and 2nd part. 2nd part will be passed to recursion.
				//"iLike" ==> firstPart "iL"
				string firstPart = src.substr(0, i + 1);
					
				//src='iLike', firstPart='iLi' then remaining='ke'
				remainingWord = src.substr(i + 1, len - (i + 1));
				
				
				string combinationsUsngRemWord;
				if (remainingWord.length())
				{
					combinationsUsngRemWord = WordBreakUsingRecursion(remainingWord, loopCount); //reduce the length by 'i'
				}

				//string allCombs = firstPart;
				allCombs += " ";
				allCombs += firstPart;
				allCombs += " ";
				allCombs += combinationsUsngRemWord;
				
				/*if (top)
				{
					cout << (src).c_str() << endl;
					cout << (firstPart).c_str() << endl;
					cout << (remaining).c_str() << endl;
					cout << (subwords).c_str() << endl;
					cout << (allParts).c_str() << endl;
				}*/
			}
			return allCombs;
		}

		//remaining: word who's combinations are to be found
		//history: map of "remaining-word" / "combinations"
		string WordBreakUsingDP(string remainingWord, map<string, string>& history, int* loopCount)
		{
			string allCombs;
			string src = remainingWord;
			int len = src.length();
			(*loopCount)++;
			//src = iLike
			//firstPart will be {"i", "iL", "iLi", "iLik", "iLike"}
			for (int i = 0; i < len; i++)
			{
				//divide the src  as 1st and 2nd part. 2nd part will be passed to recursion.
				//"iLike" ==> firstPart "iL"
				string firstPart = src.substr(0, i + 1);

				//src='iLike', firstPart='iLi' then remaining='ke'
				remainingWord = src.substr(i + 1, len - (i + 1));


				//find the combinations for remaining-word if only 
				//a) it is len > 0
				//b) it has not been already explored. If it is alreday explored it will be in MAP
				string combinationsUsngRemWord;
				if (remainingWord.length())
				{
					if (history.find(remainingWord) == history.end())
					{
						combinationsUsngRemWord = WordBreakUsingDP(remainingWord, history, loopCount); //reduce the length by 'i'

						//memorize the combinations for remaining-word  by storing t in MAP
						history.insert({ remainingWord,combinationsUsngRemWord });
					}
					else
					{
						//combinations are in MAP, fetch them
						combinationsUsngRemWord = history[remainingWord];
					}
				}
				//string allCombs = firstPart;
				allCombs += " ";
				allCombs += firstPart;
				allCombs += " ";
				allCombs += combinationsUsngRemWord;

				/*if (top)
				{
					cout << (src).c_str() << endl;
					cout << (firstPart).c_str() << endl;
					cout << (remaining).c_str() << endl;
					cout << (subwords).c_str() << endl;
					cout << (allParts).c_str() << endl;
				}*/
			}
			return allCombs;
		}
	};
};
