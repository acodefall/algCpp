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
namespace EncodeReplaceMultipleWithNumberNM
{
	/*
		Encode the string by replacing the repeating letters with their occurence-count followed by character itself.
		Ex: Replace "CC" using "2C"
		Get occurenace count using look forward strategy.  Look forward strategy compares the current value 
		against the next-value and next-value; and this continues as long as value is matching.
		This will give the repeat count of current-value. If the item is non-repeating then occurent count is 1.
		Once we have the occurent count, decided whether to encode or not. If we decide to encode, string may shrink, in that case increment
		the 'shiftCount' also. 
		Say occurent count is 1, then no encoding is needed, copy the curr-value to appropriate index.
		Say occurent count is 2 or more, then encode the character. (like AA 2A). Also compute the shift count.
		"shift count = shift count + occurent count - 2" //Two accounts for "2A"

		There will be outer-while loop and inner loop. Inner while loop is used for Forward lookup.
		Both use different index. If Outer while loop(I) is at 2, then inner while loop starts from index-3.
		Before getting in to inner-while loop, initialize the  'occurence count' = 1 because item is already existing once.
		Once we come out of this while loop, we will know the occurence count.
		USe iToA() function for converting 'occurent count' in to number. This is because occurent count could be 2 or 200
		while(i < Len)
		{
			i = j + 1;
			occurCount = 1;
			//Look forward loop
			while(j < Len)
			{
				occurCount++;
			}

			if(occurCount == 1) //Non-repeating character
			else
				//Repeating character
		}

	*/
	class EncodeReplaceMultipleWithNumber
	{
		public:
				void callEncodeReplaceMultipleWithNumber()
				{
					string src("ussfreeet"); ///u2sfr3et
					string encodedSrc = EncodeReplaceMultipleWithNumberX(src);
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
							for (int k = 0; k < countlen; k++)
							{
								src[(i - shiftCount) + k] = num[k];
							}
							src[(i - shiftCount) + countlen] = c;
							
							//adjust the shiftcount
							shiftCount = shiftCount + occurcount - (countlen + 1);//subtract the space taken by "2A"
							
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
