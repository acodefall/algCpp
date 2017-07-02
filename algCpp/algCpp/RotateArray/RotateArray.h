#pragma once
#include <iostream>
namespace RotateArrayNM
{
	//NotRead
	class RotateArrayX
	{
		public:
			/*
				RotateAntiClockwiseUsingShifting: 
				Here we vacate 0th element in to a temp variable, and then go through the array, and shift all the element, to left by one position.
				At the end of the shifting, the vacated-element will be put to last-position. Now we have shifted the elements by one position. 
				If we want to do shift by one more position repeathe whole process again.

				Steps:
					  There will be outer loop and inner loop.
					  Outer loop goes from 0 -> number of rotations
					  Inner loop goes by 1 -> length of array.
					  Outer loop vacates data[0] in to a Temp-Variable.
					  Then starts a inner loop.
					  Then inner assignes 
						   data[j-1] = data[j];
		   
					  Once the inner loop completes, outerloop moves 
						   data[j-1] = TempVariable.

					Note: In every loop, vacate same 0th element in to Temp variable

					Note: In Anti-clockwise case. 
							-Outerloop goes as long as the number of elements to be rotated.
							 Outerloop vacates the last element in to TempVariable 
							-Innerloop goes in revese direction. It shifts the elemnts to RIGHT by one position.
		   
		   
			*/
			//In this case we want
			void callRotateAntiClockwiseUsingShifting()
			{
				int data[5] = {100, 200, 300, 400, 500};
				int len = 5;
				int rotateBy = 2;
				for (int i = 0; i < rotateBy; i++)
				{
					int j = 1;
					int take = data[0];
					for (; j < len; j++)
					{
						data[j - 1] = data[j];
					}
					data[j - 1] = take;
				}

				for (int k = 0; k < len; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";

				/*
					100, 200, 300, 400, 500   //remove  100

					200, 300, 400, 500, 100   //remove 200

					300  400  500  100, 200,   (anti-clockwise)
				*/
			}

			/*
				RotateAntiClockwiseUsingJuggling:
				      AntiClockwise rotation by String-Reversal takes O(2N) and juggling method takes O(N) ++
					  In case of AntiClockwise rotation we know that 1st segment should go the far end of the array.
					  So we take the elements from 1st-segment(one at a time) and place it in its eventual index (at the far end of the array). 
					  This eventual-index will be inside the 2nd segment, and so we have to vacate one element from 2nd segment, to make space for the element from 1st segment.
					  We do this as follows:
  
					  -Pluck the 0th element of 1st segement and place it in a temp variable.  Then bring the 1st element of the 2nd-segment, to take up the vacant position in 1st segment.
					  -This creats a vacant slot in 2nd segment, so that the elements of 2nd segment can be moved to LEFT, by one position.
					   We shift only until the EVENTUAL index where the plucked-element is going sit. (This is very important).
					   Ex: 2nd segment may have 4 elements, and plucked element is going to sit at 3rd position, then we shift only 1st and 2nd element.
					   Then drop the plucked element element to vacant 3rd place. 
   
					   In the next round, we take [1] element from 1st segment will be taken out, and again the 1st element of 2nd segment will come to 2nd position of 1st segment.
					   Then we shift the elements of 2nd segments and then drop the plucked element in its eventual index.
					   Repeat this until we transport every element of 1st segment


						Note: After the 1st round, we will be shifting every element of 2nd segment to left. While doing that, we have to IGNORE the DROPPED elements, and also 
						elements that are right side of DROPPED elements, should JUMP over the DROOPED items. 
						So shifting logic is complex, and should seperate condition for 
						- index < (N-R) //Before dropped elements
						- index = (N-R) //Equal to beginning of dropped elements
						- index =  N - R + itemsShifted //Equal to dropped elements
						- index >  N - R + itemsShifted //After to dropped elements
						Note: Shifting operation always begins at the 1st element in 2nd block.
					
					
					(Initial)
						R = 2 N = 6
						100, 200, 300, 400, 500, 600
					                         X    
														
														Say X is the index where the 1st segment will eventually stay. This is N-R index. 
					(round 1)
						tmp = 100
							200, 300, 400, 500, 600  (pluck [0] in to temp variable)
						
						
						300,200,      400, 500, 600  (1st element of 2nd segment(300) takes the place of plucked-element. This creats a vacancy in 2nd segment.) 
										    X  	      Shift elements in 2nd block that are in between beginning of 2ndblock and [N-R]. That is [R+1] to [N-R]
										   [N-R]
											
						
						300,200, 400, 500,    , 600  (Shifting  made the [N-R]th position vacant so that we can drop plucked item)
						                    x
                                           [N-R]

						300,200, 400, 500, 100, 600  (Drop the plucked item)
													  
													 DO not move all of the 2nd block, just move only those elements that lie before the EVENTUAL position for plucked element.
													 In the 2nd block move only the elements that are  
											     	This creates an empty spot where we can drop the plucked [0] element that is sitting in temp variable)
						

														Say X is the index where the 1st segment will eventually stay. This is N-R index. 
					(round 1)
						tmp = 200
						300,   , 400, 500, 100, 600  (pluck [1] in to temp variable)
						
						
						300,400,    , 500, 100, 600  (Let the 1st element of 2nd segment(300) take the place of plucked-element. This creats a vacancy in 2nd segment.) 
										    X  	     
										  [N-R]

						300,400,500, 600,  100,     Shift elements in 2nd block that are in between beginning of 2ndblock and X.
						                    x       (Shifting  made the position X vacant so that we can drop plucked item)  

						300,200, 400, 500, 100, 200  (Drop the plucked item)
					
			*/
			

			void callRotateArrayClockWiseUsingJuggling()
			{
				int data[6] = { 100, 200, 300, 400, 500, 600 };
				int N = 6;
				int R = 2;

				int pluckededItem = 0;
				int itemsShifted = 0;
				int firstItem = true; //Means no element from 1st segment has been shifted to its eventual place.
				for (int i = 0; i < R; i++)
				{
					//1) pluck the item from 1st segment
					pluckededItem = data[i];
					
					//2)  Put the "1st element of 2nd segment" (that is [R]th item) take the place of plucked-element. This creats a vacancy in 2nd segment 
					data[i] = data[R];

			    	//3)Shift the items of 2nd segment within itself. 
					//2nd segment begins after the [R]. Shift the items staring from [R+1]
					int j = 0;
					j = R+1; //[R] start of 2nd segment, [R] has been shifted to front, so shift the content of 2nd segment to left by 1
				
					while (j < N)
					{
						//Items before [N-R] can be moved easily. 
						if (j < N - R)
						{
							data[j - 1] = data[j];
						}
						else if (j ==  N - R)
						{
							if (firstItem) //Move the 
							{
								data[j - 1] = data[j];
								firstItem = false;
								break;
							}
						} 
						else if ((j > N - R) && (j < N - R + itemsShifted))
						{   //[N-R].... will have  
							//skip
						}
						else if ((j == N - R + itemsShifted))
						{
							data[N - R - 1] = data[j]; //JUMP
						}
						else if ((j > N - R + itemsShifted))
						{
							data[j - 1] = data[j];
						}
						j++;


					}

					//4)  (Drop the plucked item)
					if (N - R + itemsShifted < N)
					{
						data[N - R + itemsShifted] = pluckededItem;
						itemsShifted++;
					}
				}

				for (int k = 0; k < N; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";
			}


			/*void callRotateArrayAntiClockwise()
			{
				int data[5] = { 100, 200, 300, 400, 500 };
				int len = 5;
				int rotateBy = 2;
				for (int i = 0; i < rotateBy; i++)
				{
					int j;
					int take = data[len-1];
					for (j = len - 2; j >= 0; j--)
					{
						data[j + 1] = data[j];
					}
					data[0] = take;
				}

				for (int k = 0; k < len; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";
			}*/


			void callRotateArray()
			{
				std::cout << "  \r\n Clockwise \r\n";
				callRotateAntiClockwiseUsingShifting();

				std::cout << "  \r\n AntiClockwise \r\n";
				//callRotateArrayAntiClockwise();

				std::cout << " \r\n callRotateArrayClockWiseEfficient \r\n";
				callRotateArrayClockWiseUsingJuggling();
			}

	};
};
