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
namespace EncodeReplaceMultipleWithNumberNM //@RED20170823001
{
	/*
		Encode the string by replacing the repeating character with occurence-count
		Ex: Replace "CC" using "2C"
			Scan the array and detect how many times a character repeats. Use the Look forward strategy for detecting occurrence count. Look forward strategy uses a while loop; before entering the while loop, cache the current-character, and once inside the while loop, go on comparing the curr-character against cached character. If they matach, then increment the occurent count, and also advance the index, and also stay in the loop. Come out of the loop once curr-character is not sam as cached character.
			Once out of inner while loop, we know occurent count. It could be 1 or more. 1 means character is non-repeating, so ecoding is needed; otherwise we have to encode. Now copy the characters to appropriate position. 

			After copying is done we might have SHRUUNK the arrasy so we have to compute the "shift count .
			So "shift count = shift count + occurent count - leghtOfNumeralPrefix" //leghtOfNumeralPrefix could be multi-digit. 2A or 20A

			Coming to implementation, there will be outer-while loop and inner loop.	Both use different index variables; but inner while loop starts after the outer-loop’s index. If Outer while loop(I) is at 2, then inner while loop starts from index-3.
			Before getting in to inner-while loop, initialize the  'occurence count' = 1 because current-character cached  character has already appeared once.

			while(i < Len)
			{
				c = src[i];                                  
				i = j + 1;                                    
				occurCount = 1;                              
		
				while(j < Len) 
				{
					if(cachedChar = src[j]
					   occurCount++;
					 else
						break;
				}
														
				if(occurCount == 1) 
					src[(i - shiftCount)] = cache current character;
				else 
					itoA()
					Write COUNT & Alphabet That is 2A
					Array has shrunk because AAA became 3A, so adjust shiftCount  
					shiftCount = shiftCount + occurcount - (countlen + 1);
			}

			"u"
				-occurCount is 1
				-directly breaks;
				-No encoding, direct copy, no shiftCount modification


			"ss"
				occurCount is 2
				Make AAA in to 3A
				Adjust shiftCount


		Decode the string like "2A"
			Encoded string may have "2A" and this should be decoded as AA.
			Numeral prefix could be multidigit, so use forward looking strategy for capturing digits length.
			At every index, kick start a inner while loop for counting digit length.While loop tests whether the curr-char is Numeral and if so it increments the numeral-counter, and continues to test the next-character, and then to next-to-next-character. This goes on until the sequence of numerals breaks. Loop starts at the same index as outer while loop.
			Once we are out of the while loop, we will have the numeral-count, and this tells how many number of alphabets to
			be copied to out[]. Cursor will be pointing to the character after the Numeral.
    
			 -if the ‘numeral-count' is 0, there was no numeral prefix and character repeats only once. 
				 So copy the current character to out[] as it is.
				 Ex: For "ABC", 'number lengh' will be 0.

				-if the '‘numeral-count'' > 0, then character repeats several times and do Atoi() conversion.
				 Then copy the multiple instances of current character in to out[].
				  Ex: For "3ABC", 'number lengh' will be 3. AAABC
    
			Coming to implementation, there will be outer while loop and inner while loop, and  both will use diifferent indexes variables.  Inner while loop start at the same index as outer while loop. If outer loop at [5] and inner while loop will also start at [5] and goes until it finds a non-numeral.

			

	*/
	class EncodeReplaceMultipleWithNumber
	{
		public:
				void callEncodeReplaceMultipleWithNumber()
				{
					string src("ussfreeet"); ///u2sfr3et
					string encodedSrc = EncodeReplaceMultipleWithNumberX(src);

					cout << "src '"<< src <<"'" << endl;
					cout << "encoded '"<< encodedSrc << "'" << endl;
					string DecodedSrc = Decode(encodedSrc);
					cout << "Decoded '" << DecodedSrc << "'" << endl;
				}
				string Decode(string srcIn)
				{
					string outDecString;
					char* src = (char*)srcIn.c_str();
					int i = 0;

					
					while (i < srcIn.length())
					{
						int j = i; //Inner while loop start at the same index as outer while loop.
						int numberLen = 0;
						
						//While loop tests whether the curr-value is Numeral and if so increments the counter(numberLen), and continues to test next 
						//index, and to next-to-next-index. Loop goes from current index(same as outer while loop) and stops when 
						//curr - value becomes non - numeral(alphabet)..
						while (j < srcIn.length())
						{
							if (src[j] >= '0' && src[j] <= '9')
							{
								numberLen++;
							}
							else
							{
								break;
							}
							j++;
						}
						
						if (numberLen > 0)
						{//'number lengh' > 0, then number repeats several times and we have to do Atoi() conversion.
							//Then copy the multiple instances of current character in to out[].
							//	Ex: For "3ABC", 'number lengh' will be 3. AAABC

							//read the character that is after the number Eg: 2A
							char letter;
							if (j < srcIn.length())
								letter = src[j];
							
							//convert the 'number lengh' in to INT
							string temp = srcIn.substr(i, numberLen);
							int charLen = std::atoi(temp.c_str());
							
							//Copy the multiple instances of current character in to out[].
							while (charLen > 0)
							{
								outDecString += letter;
								charLen--;
							}

							//"2Abc"
							//advance the i. Now j will be pointing A
							i = j;
						}
						else
						{
							//'number lengh' is 0, then character is alphabet, it repeats only once.
							//	So copy the current character to out[] as it is.
							//	Ex: For "ABC", 'number lengh' will be 0.
							outDecString += src[i];
						}
						i++;
					}
					return outDecString;
				}
				string EncodeReplaceMultipleWithNumberX(string srcIn)
				{
					char* src = (char*)srcIn.c_str();
					int shiftCount = 0;
					
					int i = 0;
					

				
					while (i < srcIn.length())
					{
						cout << endl;
						char c = src[i];
						int j = i+1;
						int occurcount = 1; //character is already occuring once so make the count 1.
						while (j < srcIn.length())
						{
							if (c == src[j]) //char is repeating, incr the count and stay in loop
								occurcount++;
							else //char is not repeating, so exit
								break;
							j++;
						}
						if (occurcount == 1)
						{	//non-repeating character
							src[(i - shiftCount)] = c;
						}
						else //Repeating character
						{   //Write the count & character
							
							//Write the Count. 
							//Use itoa() because occurcount could be single digit(2) or multi digit(89)
							char num[5] = { 0 };
							itoa(occurcount, num, 10);// 
							int countlen = strlen(num);

							//Copy the counter
							for (int k = 0; k < countlen; k++)
							{
								src[(i - shiftCount) + k] = num[k];
							}

							//copy the Alhabet
							src[(i - shiftCount) + countlen] = c;
							
							//Array has shrunk because AAA became 3A, so adjust shiftCount  
							shiftCount = shiftCount + occurcount - (countlen + 1); //countlen "1 for 2A"; "2 for 45A";
							
							i += (occurcount - 1); //Use '-1' because occurcount is COUNT and i is INDEX
						}
						i++;
					}

					

					//
					string out = srcIn.substr(0, i - shiftCount);
					cout << "Compacted array " << out << endl;
					return out;
				}
	};
};
