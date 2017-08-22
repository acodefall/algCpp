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
		Encode by replacing the multiple letters with their number of occurence.
		Ex: Replace "CC" using "2C"

	*/
	class EncodeReplaceMultipleWithNumber
	{
		public:
				void callEncodeReplaceMultipleWithNumber()
				{

				}

				void EncodeReplaceMultipleWithNumberX(string srcIn)
				{
					char* src = (char*)srcIn.c_str();
					int shiftCount = 1;
					int tokenCount = 1;
					int i = 0;
					char prev = src[0];

					//Loop through the src string starting from [0] to MAX
					//In each loop, compare  prev-char with current-char. If they match then there is a continuous seq of chars going on. 
					//Do not write them to output[]; just keep on counting them;
					//Once the sequence breaks, then write to output[].
					//Say if sequence has AA, then write 2A.
					//Basically Write to  output[] ONLY when prev-char and current-char are not matching.
					//When current-char and prev-char are equal, do not write to output[], instead just go on counting the sequence  
					while (i < srcIn.length())
					{
						cout << endl;
						//cout << " src[" << i "] = " << src[i] << endl;
						if (src[i] >= 'a' && src[i] <= 'z')
						{
							//compare with current-char and prev-char; they are same so  
							if (src[i] == prev)
							{
								tokenCount++; //Increement the tokenCount
								cout << "src[" << i << "] = " << src[i] << "is token. Skip if it is 1st in sequence. tokenCount : '" << tokenCount << "'" << endl;
								
								//increment the ShiftCount only when tokenCount is > 2. 
								//Increment for AAA but not AA. This is because AA & 2A take same 2 characters, so no shifting is needed.
								//If we had AAA/3A, then shifting will be 1. 
								if (tokenCount > 2)
								{
									cout << "non-First Token, SKIP char" << endl;
									shiftCount++;
									cout << "Incr tokenCount: " << tokenCount << endl;
									cout << "Incr shiftCount: " << shiftCount << endl;
								}
							}
							else
							{
								//cout << "src[" << i << "] = " << src[i] << " is Non-Token. SHIFT & COPY char" << endl;
								//cout << "Left-shift by '" << shiftCount << "' copy src[" << i << "] to src[" << i << " - " << shiftCount << "]" << endl;
								if (tokenCount > 1)
								{ //We are coming out of a sequence Write the count & character
									src[(i- shiftCount) - tokenCount] = (char)(tokenCount + '0');
									src[((i- shiftCount) - tokenCount) + 1] = src[i];
								}
								else
								{ //There was NO sequence, so simply write the character without any number
									src[(i - shiftCount)] = src[i];
								}
								//reset counters
								tokenCount = 1;
								cout << "Reset tokenCount " << tokenCount << endl;
								cout << "shiftCount stays same at '" << shiftCount << "' since we RETAINED char" << endl;
							}
							cout << "   Out array " << src << endl;
							
						}
						else
							src[i - shiftCount] = src[i];
						i++;
					}

					//This takes care of last one
					if (tokenCount > 1)
					{
						shiftCount += tokenCount - 1;
						src[i - shiftCount] = src[i];
					}

					//
					cout << "Compacted array " << srcIn.substr(0, i - shiftCount) << endl;
				}
	};
};
