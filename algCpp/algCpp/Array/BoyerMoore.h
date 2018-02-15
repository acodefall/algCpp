#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace BoyerMooreNM //@RED20170724012
{
	/*	Used for StrStr() implementation.
		

				oneXwothree
				    two
				
				oneXwothreetwo
				     two
					 
				seven
				   ten

	BoyerMoore for Pattern matching RED20170907003
		In Boyer Moore, we place the pattern under the src array and begin comparison from the END of the array.
		Advantage of this technique is if the last element of the patter itself is not matching, then no need to compare 
		other elements of the patter; we can simply right-shift the pattern by the amount equal to whole length of pattern.

		If the pattern matches partially, means say the last two character of the pattern are present in src[], then thinge get complicated. 
		In that case search for the missing character in PAttern. If it is not at all present, then we MOVE the pattern to RIGHT, by the amount equal to the full length of the pattern.
		Just past the missing character X
			 //i = 3, j = 2  (X == e) 'X' is the missing character
			 p t e X t w o t h r e e
			   o N e t w o
	               .

			NEXT-ACTION 
				//Move the pattern all the way, past the missing character X
				 p t e X t w o t h r e e
						 o N e t w o   
	   
		If the missing character is somewhere inside in the pattern, then MOVE the pattern so that missing characters coincide.
		Amount of movement is "PatternLen - indexOfMissingElement inside PatternArray"
			 //i = 3, j = 2  (N == e) 'N' is the missing character
			 p t e N t w o t h r e e
			   o N e t w o
			
			NEXT-ACTION 
				//Move the pattern so that 'N' coincides 
				 p t e N t w o t h r e e
					 o N e t w o   


	String search algorithms_GN172_RED20170907005
			There are 3 String search algorithms
			-BruteForce
			-Rabin-Karp
			-BoyerMoore

			BruteForce takes O(mn) time.
			Rabin-karp speeds are "Best case is O(m+n) and worst case is O(mn)"
			Boyer-Moore speeds are "Best case is O(n/m), and worst case is O(n)" Best case is when the first character to be compared fails; in such case comparison skips by the amount equivalent to length of pattern.
			Rabin-Karp can search for multiple patterns, and this feature is used in finding out Plagiarism.
			N = string Length
			M = pattern Length

	Bad character rule
			Boyer-moore alg uses ‘bad-character rule’ and ‘good-suffix rule’ for computing the shift count for “i”.
			Bad-char is the character that fails in match. Note  that bad-char is present at current-index but it may be at an other index in pattern. These possibilities affects how much “i” is going to be moved.

			–-If the bad-char is not found anywhere inside pattern, then 1st letter of pattern should move to RIGHT-OF bad-char index.
			(see step2)

			–-If the bad-char is present somewhere in pattern, then found-index of pattern should move to RIGHT-OF bad-char index.
			(see step1)
	BadChar Table or string.Find()
			Ideal implementation of Boyer-Moore uses BadIndex Table for computing the amount-shift in case of bad-char.
			In my implementation I do not use the Badchar table, instead I use string.find() for searching bad-char in pattern,
			and appropritely manually compute the shift.
			If I were to use BadIndex-table, table would have taken care of the both these operations.

   */
   
	
	const int MAXBAD = 256;
	class BoyerMoore
	{
		public:
			
			void callBoyerMoore()
			{
			
				//string src("Xwothrtwo");
				//string pat("two");
				//string src("pteNtwothree");
				//string pat("Ntwo");

				string src("WHICH FINALLY HALTS  AT THAT");
				string pat("AT THAT");

				cout << "S: " << src << endl;
				cout << "P: " << pat << endl;
				BoyerMooreX(src, pat);

			}

			/* 
			BadChar Table or string.Find()
				Ideal implementation of Boyer-Moore uses BadIndex Table for computing the amount-shift in case of bad-char.
				In my implementation I do not use the Badchar table, instead I use string.find() for searching bad-char in pattern,
				and appropritely manually compute the shift. 
				If I were to use BadIndex-table, table would have taken care of the both these operations. 
			*/
			void BoyerMooreX(string src, string pat)
			{
				int i = pat.length() - 1; //index for source
				int j = pat.length() - 1; //index for pattern
											//start comparing from the last letter of pattern 

				const char *s = src.c_str();
				const char *p = pat.c_str();
				int matchedChar = 0;
				while (i < src.length())
				{
					cout << endl << "s[" << i << "] = '" << s[i] << "'  p[" << j << "] = '" << p[j] << "'" << endl;
					//cout << "   src and pattern compared " << endl;
					cout << "   "<< src.substr(0, i+1) << endl;
					cout << "   "<< pat.substr(0, j+1) << endl;
					if (s[i] == p[j])
					{
						cout << "      '"<< s[i] << "' matched" << endl;
						if (j == 0)
						{
							cout <<"      "<< pat << " was found at '" << i << "'"<< endl;
							//we were able to match every letter of pattern against source so pattern exists.
							break;
						}
						j--;
						i--;
						matchedChar++;
					}
					else
					{

						/*
						Computing i;
							"No bad char" = i + pLen;
							"bad char" = i + pLen - matchCharsCnt;
							"bad char, found in Patrn" = i + pLen - matchCharsCnt - FndInx;
						*/
						int k = pat.find(s[i]);
						if (k == -1)
						{
							i += (pat.length() - matchedChar);
							if (matchedChar) //we have go past the matched index
								i = i + 1;
						}
						else
						{
							i += (pat.length() - matchedChar - k) - 1;
						}
						j = pat.length() - 1;
						matchedChar = 0;
					}
				}

			}
		

	};
};