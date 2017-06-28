#pragma once
#include <iostream>
#include <algorithm>

namespace RotateArrayUsingReverseNM
{
	/*
	Right and Left Rotations in general_20170530001
		View the Rotated array as two pieces of same scale. If scale’s range is 1 – 10; after the rotation 1 and 10 will come to the middle, and they will be next to each other.
		In Clockwise/Right rotation, 1 will stay on LEFT side and 10 will stay on RIGHT side.
		In AntiClockwise/Left rotation, 10 will be on left-side and 1 will be on right side, basically sides gets switched.

		AntiClockwise Rotation (lenN = 5, countR = 2)
		100, 200, 300, 400, 500 (in)
		500, 400, 300, 100, 200 (out)

		Clockwise Rotation (lenN = 5, countR = 2)
		100, 200, 300, 400, 500 (in)
		200, 100, 500, 400, 300 (out)
		Do not go by the name of rotation like Right or Left, instead look at the example. If the MIN and MAX change side, then it is Left rotation, otherwise it is Right totation.

	Strategies for rotating Arrays_20170530002
		There are 3 methods for rotating arrays:
		1) By string rotation. Break the original array in to two parts, at the index equal to rotation-count(R), and then rotate the individual arrays to get Clockwise/Right rotation. This takes O(N). Implement the rotation using in-place algorithm.

		In AntiClockwise/Left rotation needs one more extra step; first rotate the whole array, and then rotate each segments. Basically call the reverse() thrice. This takes O(2N) time.

		2) By shifting the elements of the array. This takes O(N*R)
		Left Shifting/Anticlockwise rotation
		Here we vacate 0th element in to a temp variable. This creates a vacant space, so we shift all the elements to left by one position. This creates a space at right-most end. We will put the element waiting in temp-variable in to vacant right-most position. Repeat this process as many times as the number elements to be rotated.

		3) By using Juggling. AntiClockwise rotation by String-Reversal takes O(2N) and juggling method takes O(N) ++


		Steps for LeftRotation using StringReverse_20170530004:
			Main function will call the reverse() function 3 times.
			reverse(0 index, MAX len); //Rotatates the full array,
			reverse(lenN - countR, countR); //Rotatates the last R bytes 
			reverse(0, lenN - countR); //Rotatates first N-R bytes

			Reverse() function accepts src-array, startIndex, count as parameters.
			Revese() does in-place reversal.This takes O(2N) time because we make two passes.

		Steps for RightRotation using StringReverse_20170530006:
			Main function will call the reverse function 2 times.
			reverse(0, countR - 1); //Rotatates first R bytes
			reverse(  countR, lenN - countR); //Rotatates the last N-R bytes 
						
			Reverse() function accepts src-array, startIndex, count as parameters.
			Revese does in-place reversal. This takes O(N) time because we makes only one pass.

	*/
	//@20170530001
	class RotateArrayUsingReverseX
	{
		public:
			void callRotateArrayUsingReverse()
			{
				std::cout << "  \r\n Clockwise \r\n";
				callRotateArrayClockWise();

				std::cout << "  \r\n AntiClockwise \r\n";
				callRotateArrayAntiClockwise();
			}

		private:
			/*
				Clockwise Rotation using Reverse (lenN = 5, countR = 2)
					100, 200, 300, 400, 500 (in)
					200, 100, 500, 400, 300 (out)
	 
				Steps for Clockwise Rotation  using Reverse:
							Main function will call the reverse function 2 times.
								reverse(0, countR - 1); //Rotatates first R bytes
								reverse(  countR, lenN - countR); //Rotatates the last N-R bytes 
						
								Reverse() function accepts src-array, startIndex, count as parameters.
								Revese does in-place reversal.

								This takes O(N) time because we makes only one pass.
			*/
			void callRotateArrayClockWise()
			{
				int data[5] = { 100, 200, 300, 400, 500 };
				int lenN = 5;
				int countR = 2;

				//Rotate the first 2 
				reverse(data, 0, countR);

				//Rotate last 3
				reverse(data, countR, countR);

				for (int k = 0; k < lenN; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";

			}

			/*  
			Clockwise and AntiClockwise Rotations  using Reverse in general
				(Anti is Left rotation and otherone is Right rotation)
				Clockwise and AntiClockwise Rotations can be viewed as follows.
				
				Clockwise Rotation
					Imagine scale of 1 - 10. Holding at 1 and 10, and fold it towards you. Folding will break the scale in to two parts.
					After breaking/folding 1 and 10 will be next to each other, at the center. 1 will continue to stay on left-side, like it was before 
					and 10 will stay on Right side as it was before. What I explained is Clockwise Rotation. 
				
				Anti-Clockwise Rotation
					In case of AntiClockwise rotation, first reverse the scale and then break/fold. 
					Now 1 and 10 will be right next to each other, at the center but 10 will be on left-side and 1 will be on right side. 

				Imagine the segments of broken scale as pieces of arrays.
				In case of ClockWise/Right rotation, rotate the two segments of length countR and (lenN-countR), by calling reverse() twice. This takes O(N) time. Reverse() uses inplace modification. 
				In case of AntiClockWise rotation, first rotate the whole array, and then rotate each segments, by calling reverse() thrice. This takes O(2N) time. Reverse() uses inplace modification. 
				
				AntiClockwise Rotation (lenN = 5, countR = 2)
					100, 200, 300, 400, 500 (in)
					500, 400, 300, 100, 200 (out)

				Clockwise Rotation (lenN = 5, countR = 2)
					100, 200, 300, 400, 500 (in)
					200, 100, 500, 400, 300 (out)
					
				Steps for AntiClockwise Rotation using Reverse:
								Main function will call the reverse() function 3 times.
								reverse(0 index, MAX len); //Rotatates the full array,
								reverse(lenN - countR, countR); //Rotatates the last R bytes 
								reverse(0, lenN - countR); //Rotatates first N-R bytes

								Reverse() function accepts src-array, startIndex, count as parameters.
								Revese*( does in-place reversal.

								This takes O(2N) time because we make two passes.
			*/
			void callRotateArrayAntiClockwise()
			{
				int data[5] = { 100, 200, 300, 400, 500 };
				int lenN = 5;
				int countR = 2;

				//Reverse the whole array
				reverse(data, 0, lenN); //

				//Reverse the last 2 elements (note: we rotate last two elements because we reversed the whole array first)  
				reverse(data, lenN - countR - 1 + 1, countR);
				
				//Reverse the first  3 elements
				reverse(data, 0, lenN - countR);
				

				for (int k = 0; k < lenN; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";
			}

			void reverse(int* data, int s, int cnt)
			{
				int k = 0;
				int e = s + cnt - 1;
				while ((k < cnt) && (s < e))
				{
					int t = data[s];
					data[s] = data[e];
					data[e] = t;
					k++;
					s++;
					e--;
				}
			}

		
	};
};