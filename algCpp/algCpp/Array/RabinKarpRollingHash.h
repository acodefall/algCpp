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

namespace RabinKarpRollingHashNM
{
    class RabinKarpRollingHash
    {
      
        /*
         	 
			 RollingHash RobinKarp_20170722004
					Rolling Hash is used for pattern matching, and it compares the hash instead of actual text. Hash for the text remains same but the Hash for the Text keeps on changing. Actually there will be window that Slides over the text, and it exposes WORD comparison and length of the WORD is same as lenght of pattern.

					We create a Hash for the WORD exposed by slide-window(say tHash) and also Pattern; and compare them, instead of comparing the actual character stored in text and pattern If the Hash matches, we found the pattern so we exit.
					If the hashes did not match, then we move the slide-window by one position to right.
					No slide-window looses a character at the front and GROWS a character at the TAIL. Now we recompute the tHash to reflect the change in WORD. We again compare two hashes (tHash against pHash). Continue this until Text.Len – Pattern.Len.

					Rolling hash is vulnerable to false +ve, so once pHash and tHash matches, we have to compare the actual characters also.
					Note hashes are just proxy for actual word.
					Rolling hash logic will touch every element of the text array. Its strength is, when it reshahes the text, it does not build the hash from scratch, instead it modifies the existing hash to account for the two character that got modified when we moved the slide-window over text
			 


			 Rolling Hash(RabinKarp)
					text :    'catsatrat' 
					pattern  'sat'
					Prime Number: 13 (should be higher than pat.Len)
					base: 10

					Flow:  
						Compute nitial hash:
							'c'   (tHash = 8)	's'   (pHash = 11)
							'ca'  (tHash = 8)	'sa'  (pHash = 12)
							'cat' (tHash = 1)	'sat' (pHash = 2)

							 pHash and tHash are PROXY for the WORD being compared.  We compare hashes as if they are actual words.

						(i .......Loops goes until Text.Len - Pat.Len)

						i = 0		                              Slide-window, hash = 1
							'catsatrat'                      
							'sat'                                                                             
							compare 'cat'(tHash = 1)  with 'sat'(pHash = 2)             
							Change the Text used for hashing from 'cat' to 'ats', rehash = tHash('3')
		

						i= 1
								 'catsatrat'                         Slide-window, hash = 3              
							 'sat'
							compare 'ats'(tHash = 3)  with 'sat'(pHash = 2)
							Change the Text used for hashing from 'ats' to 'tsa', rehash = tHash('3')
		
						i= 2                                                                                     Note the pHash(patter's hash stays same)
							'catsatrat'                        Slide-window, hash = 3
							   'sat'                                                                            
							compare 'tsa'(tHash = 3)  with 'sat'(pHash = 2)                  
							Change the Text used for hashing from 'tsa' to 'sat', rehash = tHash('2')

						i=3 
							'catsatrat'                       Slide-window, hash = 3
								'sat'
							compare 'cat'(tHash = 2)  with 'sat'(pHash = 2)
							pHash and tHash matched '2' '2'
									   Now compare the actual word also to make sure characters also match

            Pattern search using RollingHash (RabinKarp method)
	            -Function parameters are int[] pattern-text, int[] src-text, Prime number for modding and radix.
                -Compute the INITIAL hash for both pattern and the segment in Src that is used for comparison. Say first 5 letters of Src 
                         for(i = 0; to Pattern.Lengh)
		                Hash = ((radix * Hash) + character[i]) % Prime number
                 Final Hash will fit in a INT. 	 

                -Then move the pattern across src, and after every move compute new_hash from previous hash. 
	                for (int j = 0; j < txt.length() - pat.length(); j++)
		                Check whether Pattern-HAsh == Src-Hash; if so QUIT.
		                Other wise compute the new hash using rolling-hash method.
		                SrcHash = SrcHash - (src[i] * (int)Math.Pow(rdx, pat.length() - 1)); //Eliminate Left-end
                                        SrcHash = SrcHash * radix; //Add to Right-end
		                SrcHash = src[i + pat.length()] //Add to Right-end

		                SrcHash = SrcHash % Mod

		                if (tHash < 0)
		                {
			                tHash = tHash + md; //not same as ABS
		                }

         
         */
	public:
		void callRabinKarpRollingHash()
        {
            //
            string T = "catsatrat";
            string P = "sat";
            int mod = 13; //Should br > pattern-length
            int rdx = 10;
            RabinKarpChar(P, T,mod, rdx);

			T = "satcatrat";
			P = "sat";
			RabinKarpChar(P, T, mod, rdx);


           
        }

        void RabinKarpChar(string pat, string txt, int md, int rdx)
        {
			const char* P = pat.c_str();
			const char* T = txt.c_str();
            int pHash = 0;
            int tHash = 0;

			cout << "text and pattern " << "'" << txt.c_str() << "' pat '"  << pat.c_str() << "'" << endl;
           //Compute hash for both Pattern[0] and Src[0]
            //This will act as base for Src[1]
            //This will help Hash the first-set
            cout << endl << "Compute Initial hash: " << endl;
			for (int i = 0; i < pat.length(); i++)
            {
                pHash = ((rdx * pHash) + P[i]) % md;
                tHash = ((rdx * tHash) + T[i]) % md;
				
				cout << "	T[" << i << "] tHash '" << T[i] << "'  '" << tHash << "'  " << endl;
				cout << "	P[" << i << "] pHash '" << P[i] << "'  '" << pHash << "'  " << endl;
            }
            cout << endl;

            
		

            for (int j = 0; j < txt.length() - pat.length(); j++)
            {
				bool Match = true;
				string beingCompared;
				if (j >= pat.length())
					beingCompared = txt.substr(j- pat.length(), pat.length());
				else
					beingCompared = txt.substr(j, pat.length());

				//comparing cat(1)  with sat(1) using hash  pHash(2) and tHash(1)
				cout << "comparing '" << beingCompared << "'( tHash = " << tHash << ")  with '" << pat.c_str() << "'( pHash = " << pHash << ")" << endl;
				//cout << "pHash and tHash " << pHash << " " << tHash << endl; 
                if (pHash == tHash) //Hash matched
                {
					cout << "pHash and tHash matched '" << pHash << "' '" << tHash << "' " << endl; 
                    
					//verify the string matches using manual check. This is because Rollish hash method is not that robust.
					//you can make it better selecting "MOD > Pat.Len"
                    for (int k = 0; k < pat.length(); k++)
                    {
                        if (T[j + k] != P[k])
						{	
							Match = false;
							break;
						}
                    }
					if(Match)
						break;
                }

                //Delete 1st digit from PrevHash.
                //[4,8,9,0,2] is current hash, we need to delete 40000. This is why we do POW
                int valueToDelete = (T[j] * (int)pow(rdx, pat.length() - 1));
                //tHash = tHash - valueToDelete;

                //Add one more digit at the end. Since this is added at the end, we do not multiple.
                int valueToAdd = T[j + pat.length()];
               
				//cout << "remove 1st char at the front and add one at the end and rehash. '" << beingCompared << "' to '" << txt.substr(j+1, pat.length()) << "' and recompute(tHash)" << endl;
               // cout << "recompute(tHash) by replacing '" << valueToDelete << "' with '" << valueToAdd << "'" << endl;
                tHash -= valueToDelete; //Delete 1st digit
                tHash *= rdx;  //multipy by 10, because we just deleted the above
                tHash += valueToAdd; //Add the last digit

                //Mod the Hash 
                tHash = tHash % md;

                if (tHash < 0)
                {
                    tHash = tHash + md; //not same as ABS
                }
				cout << "Change the Text used for hashing from '" << beingCompared << "' to '" << txt.substr(j + 1, pat.length()) << "', and rehash = tHash('" << tHash << "')" <<endl;
				//cout << "new tHash '" << tHash  << "'" << endl;
            }
        }
        /*public void RabinKarpInt(int[] P, int[] T, int md, int rdx)
        {
            int pHash = 0;
            int tHash = 0;

            //Compute hash for both Pattern[0] and Src[0]
            //This will act as base for Src[1]
            //This will help Hash the first-set
            for (int i = 0; i < pat.length(); i++)
            {
                Console.Write("{0}", T[i]);
                pHash = ((rdx * pHash) + P[i]) % md;
                tHash = ((rdx * tHash) + T[i]) % md;
            }
            Console.Write("\r\n");

            //Check whether Pattern[0] and Src[0], if not true, then only 
            //compute the hash for subsequent sets.
            for (int j = 0; j < txt.length() - pat.length(); j++)
            {
                if (pHash == tHash) //Hash matched
                {
                    //verify the string match
                    for (int k = 0; k < pat.length(); k++)
                    {
                        if (T[j + k] == P[k])
                            Console.Write("{0}", P[k]);
                    }
                    Console.WriteLine("found at {0} \r\n", j);
                }

                //Delete 1st digit from PrevHash.
                //[4,8,9,0,2] is current hash, we need to delete 40000. This is why we do POW
                int valueToDelete = (T[j] * (int)Math.Pow(rdx, pat.length() - 1));
                //tHash = tHash - valueToDelete;

                //Add one more digit at the end. Since this is added at the end, we do not multiple.
                int valueToAdd = T[j + pat.length()];


                Console.Write("D: {0} A:{1}\r\n", valueToDelete, valueToAdd);
                tHash -= valueToDelete; //Delete 1st digit
                tHash *= rdx;  //multipy by 10, because we just deleted the above
                tHash += valueToAdd; //Add the last digit

                //Mod the Hash 
                tHash = tHash % md;


                if (tHash < 0)
                {
                    tHash = tHash + md; //not same as ABS
                }
            }
        }*/
    };
};
