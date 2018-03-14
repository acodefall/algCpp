#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
namespace LongestCommonPalidroneNM //@RED20170531002
{
	/*
	Finding the Longest Palidrone in a string_20170531002
			Palidrone results in a mirror image so starting from index=1 check the whether the characters are same on either side '        
			of the cursor. Continue as long as characters are matching. For every matching aphabet, increment the paln count by 2.
			Break the comparison once the match stops. Do this check for index=1, 2, etc... Then select the palidrone who's length is max.
			
			At the beginning wrap each alphabet. Sentence should start with # and also end with #.
			
			Coming to implementation. Wrap the characters with #. Then start a ForLoop to start at index = 1.
			Then create two more indecies i-1 & i+1. Start a while loop for checking for mirror image around index-i.
			Inside while loop, compare i-1 and i+1. If they match and character is NOT #, then 
			increment the palincount by 2. Break the while loop  if alphabets faisl to match.
			
			Palin count uses # as marker. If the cursor is at non-hash then we are already past the marker so initialize the palincount = 1
			Otherwise palincount = 0.
			
			
			 We insert anchors because we want to a partition besides whom we can grow.
				 Ex: "abba" there is nothing to grow around but by inserting # between then, by making 
				 "ab#ba" we can grow on either side.
  
				 # a # b # b # a # p #  q  #  q  #  p  #  a  #  b  #
				 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
	
		Steps for Finding the Longest Palidrone in a string_20170531001
				a) Insert anchors (say #) in to src array. Anchors goes to beginning, end and between each character. 
				   Having anchor helps to walk across. Ex: In "aa" there is no achor element to diverge from.
				   by inserting #, we create a anchors. "#a#a#"

				b) After anchors are in place, start a ForLoop. i = 1 and goes until (< Len.)
				c) Each anchor-index could be meeting axis for palidrone so at every anchor-index we start fresh counter for counting palidrone.
				   Say palinCount = 0;
				d) Declare two indexes left and right for walking away from achor. 
				   left = i - 1;
				   right = i + 1;

				   //if anchor-index is pointing to 'non-anchor' character(#), then we know that there will be at least one palidrone,
				   //so set the count to 1.
				   if(src[anchor-index] != '#') 

				e) Then start a while loop to check for palidrone by diverging from anchor-index.
				   While Loop increments RightIndex and decrements LeftIndex. 
				   Loop goes on as long as "((LeftIndex >= 0) && (RightIndex < Len))"
				   Inside the whileLoop
							-if letters are not same/ MIRROR break the loop
								(src[left] != src[right]) 

							-if the letters are same, incr and decrement RightIndex and LeftIndex.
							 Increment the palinCount (by 2) only if the letter is not '#' 
							 Note we increement by 2 because we have anchors in between.
							 If the letter is '#' then we do not increment palin count.

				f) Once the While loop breaks we are out of palidone-sequence
				   And we have check how long it was, and it were the longer than compared to previous one, then update the MAXCounter.

		 
			
			
	*/
	class CallLongestCommonPalidrone
	{
		public:
			void callLongestCommonPalidrone()
			{
				const char* data = "abbapqqpab";
				char* dataWithAnchors = putAnchors(data, strlen(data)); //"q p a b"
				LongestCommonPalidroneX(dataWithAnchors, strlen(dataWithAnchors));


			}

			char* putAnchors(const char* data, int Len)
			{
				char* dataA = new char[(Len * 2) + 1];
			
				int j = 0;
				for (int i = 0; i < Len; i++)
				{
					dataA[j++] = '#';
					dataA[j++] = data[i];
				}
				dataA[j++] = '#';
				dataA[j++] = 0;
				return dataA;
			}

			void LongestCommonPalidroneX(char* dataA, int Len)
			{
				int left = 0;
				int right = 0;
				int peakPalinIndex = 0;
				int peakPalinWidth = 0;
				//i is the index of the achor. and we want one letter to be on either side, so set i = 1
				for (int i = 2; i < Len; i++)
				{
					//reset the palidrone count to 0.
					int palinCount = 0;

					//choose the indexes whos value we want to compare 
					left = i - 1;
					right = i + 1;

					//if anchor-index is pointing to 'non-anchor' character(#), then we know that there will be at least one palidrone,
					//so set the count to 1.
					if (dataA[i] != '#')
						palinCount = 1;


					//using [i] as anchor, extend on eiher side of [i], and check whether letters match.
					//If the character does match then increment the 'palidrone counter', provide the charter is not #
					while ((left >= 0) && (right < Len))
					{
						if (dataA[left] != dataA[right])
							break;
						else
						{
							if (dataA[left] != '#')
								palinCount += 2;
							left--;
							right++;
						}
					}

					if (palinCount > peakPalinWidth)
					{
						peakPalinWidth = palinCount;
						peakPalinIndex = i;
					}
					
				}

				cout << "palidrone \r\n";
				//print the final palidrone
				//Add one to peakPalinIndex because 'peakPalinIndex' will be pointing to ACHOR character
				int LenP = peakPalinIndex + peakPalinWidth;
				for (int k = peakPalinIndex + 1; (k < LenP) && (k < Len); )
				{
					cout << dataA[k] << " ";
					k = k + 2;
				}
			}
	};
	
};
/*
public static void findpalindrome() 
{
    int left, right, count;
    palinCount = new int[newlength];
    palinCount[0] = 1;
    palinCount[newlength - 1] = 1;
    for (int i = 1; i < newlength - 1; i++) 
	{
        count = 0;
        left = i - 1;
        right = i + 1;
        ;
        if (modifiedString[i] != pound)
            count++;
        while (left >= 0 && right < newlength) 
		{
            if (modifiedString[left] == modifiedString[right]) 
			{
                if (modifiedString[left] != pound)
                    count = count + 2;
                left--;
                right++;
            } 
			else
                break;
        }

        palinCount[i] = count;
        highestcount = count > highestcount ? count : highestcount;

    }

}
*/
