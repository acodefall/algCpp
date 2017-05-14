#pragma once
#include <iostream>
namespace RotateArrayNM
{
	//NotRead
	class RotateArrayX
	{
		public:
			/*
				Clockwise: 
				Here we vacate 0th element in to a temp variable, and then go through the array, and shift all the element, to left by one position.
				At the end of the shifting, vacated-element will be put to last-position. Now we have shifted the elements by one position. 
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
			void callRotateArrayClockWise()
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
			}

			/*
				Method2:
					In this method, take the 1st element from 0th position and place it at the exact position, at the end of the array.
					Then shift the middle items to left by one position. Then take the 1st element and place it at the exact position, at the end of the array.
					Then shift the middle items to left by one position. Do this until the plucked element count is same as that of 

					Detailed 
					Divide the array as 1st part(part to be rotated) and rest of the array
					Vacate the 0th element from its position and store it in a tempVariable.
					Then replace it with the 1st-element(immediately after 1st part).
					Now shift the elements of 2nd-block within 2nd-block. Do not shift all the elements of 
					2nd block. Stop shifting once you come across the positon where the 0th element is supposed to sit;
					Then place the 0th element at that position.

					Repeat the whole process again by plucking the second element from 1st block.
					This time extra care should be taken when shifting the elements within 2nd block.
					Do not shift the "dropped elements" because they are at their eventual position.
					but we may have to take the element from "dropped elements region" and place it before "dropped elements". 

					Note: Shifting operation always begins at the 1st element in 2nd block.
			*/
			void callRotateArrayClockWiseEfficient()
			{
				int data[5] = { 100, 200, 300, 400, 500 };
				int N = 5;
				int R = 2;

				int pluck = 0;
				for (int i = 0; i < R; i++)
				{
					int j = 0;
					pluck = data[i];
					data[i] = data[R];
					j = R;
					int offset = 0;
					while ((j < N) && (j <= N - R + i))
					{
						//Shift if possible
						if (offset > 0)
						{
							if (j < (N - R))
								data[j - 1] = data[j];
						}
						if (j == N - R + i)
						{
							int temp = data[j];
							data[j] = pluck;
							if (offset > 0)
							{
								data[N - R - 1] = temp;
							}
							break;
						}
						offset++;
						j++;
					}
				}

				for (int k = 0; k < N; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";
			}
			

			void callRotateArrayAntiClockwise()
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
			}


			void callRotateArray()
			{
				std::cout << "  \r\n Clockwise \r\n";
				callRotateArrayClockWise();

				std::cout << "  \r\n AntiClockwise \r\n";
				callRotateArrayAntiClockwise();

				std::cout << " \r\n callRotateArrayClockWiseEfficient \r\n";
				callRotateArrayClockWiseEfficient();
			}

	};
};
