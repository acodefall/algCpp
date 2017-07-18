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

namespace BoyerMooreNM
{
	/*
		Q) Group the ANAGRAMs that are stored in a Array, so that they appear next to each other. 
            Basically RAT and TAR should appear next to each other.

		Strategy is to load the words to a LIST. Then provide a custom SORT-Predicate for LIST. 
		This predicate will sort the idividual characters of the string, and constructs a NEW string, and then compares these new strings.
		Ex: Predicate will turn p1=Rat p2=Art int to ART and ART, and then compares them using <
				OriginalWord /SortedWord
				trees  => eerst
				reset => eerst
				reset  => eerst
				pans => anps
				span  => anps
				steer => eerst
				steer  => eerst
				span => anps
				span  => anps
				naps => anps
				naps  => anps
				pans => anps
				naps  => anps
				reset => eerst
				reset  => eerst
				naps => anps
				span  => anps
				reset => eerst
				reset  => eerst
				span => anps
				steer  => eerst
				reset => eerst
				steer  => eerst
				trees => eerst


				oneXwothree
				    two
				
				oneXwothreetwo
				     two
					 
				seven
				   ten
				
   */
   //SORT-Predicate
	

	class BoyerMoore
	{
		public:
			void callBoyerMoore()
			{
			
				string src("Xwothrtwo");
				string pat("two");
				cout << "S: " << src << endl;
				cout << "P: " << pat << endl;
				BoyerMooreX(src, pat);

			}

			void BoyerMooreX(string src, string pat)
			{
				int i = pat.length() - 1; //index for source
				int j = pat.length() - 1; //index for pattern
											//start comparing from the last letter of pattern 

				const char *s = src.c_str();
				const char *p = pat.c_str();
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
					}
					else
					{
						//cout << "   " << "s[" << i << "] = '" << s[i] << "' is not matching" << endl;
						int k = pat.find(s[i]);
						if (k == -1)
						{
							//Here N is not at all existing in pattern, so move the pattern part N
								//teNtwothree
								//onetwo      //i = 2
								//   onetwo   //i = 8

							
							cout << "   " << "s[" << i << "] = '" << s[i] << "' is totally missing. Move patter beyond  '" << s[i] << "' to i = " << i + pat.length() << endl;
							i += pat.length();
							//cout << "   " << "src string used for comparison " << src.substr(0,i) << endl;
						}
						else
						{
							cout << "   " << "s[" << i << "] = '" << s[i] << "' is somewhere in pattern. i = '" << i << "'" << endl;

							 i = i + pat.length() - min(j, (int)src.length() - k +1);   //To shift the full length of TRG to right side(beyond [i]).
							                       //(j - x)
						}
						
						//when ever a character is missing
						//pattern index always starts from last psoition
						j = pat.length() - 1;
					}
				}

			}
		

	};
};