#pragma once
#include <iostream>
#include <algorithm>

namespace RotateArrayUsingReverseNM
{
	/*
	Array rotation using string rotation_20170530002
		Array rotation can be visualized as breaking a scale in to two parts; and then rotating each individual parts seperately.
		Rotation will bring left-most element and right-most elements to middle (right next each other).
		Some time we want them to swap sides, in addition to coming to center. 
		This depends on whether the rotation is clockwise or anti-clockwise. 

		Coming to coding, simulate broking of scale by breaking the src array in to two parts.
		Then rotate the two arrays within themselves using simple SWAPPING. This will bring Left-most and right-most element to center; right next to each other.

		If the problem insists that the elements have to swap their side aslo. then We have to one more array rotation. 
		Steps are as follows:
		-Before breaking the array in to two parts, rotate the whole array using SWAPPING.
		-Then break the array in to two parts, and then swap the two individual arrays within themselves using SWAPPING.
		-Now the end element will come to middle but they will be on opposite side.
		-This method took 3 rotations.


		AntiClockwise Rotation (lenN = 5, countR = 2)
		100, 200, 300, 400, 500 (in)
		500, 400, 300, 100, 200 (out)

		Clockwise Rotation (lenN = 5, countR = 2)
		100, 200, 300, 400, 500 (in)
		200, 100, 500, 400, 300 (out)
		Do not go by the name of rotation like Right or Left, instead look at the example. If the MIN and MAX change side, then it is Left rotation, otherwise it is Right totation.

	

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