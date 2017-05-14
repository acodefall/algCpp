#pragma once
#include <iostream>
namespace RotateArrayUsingReverseNM
{
	//NotRead
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
				Clockwise Rotation
								10 20 30 40 50 60 70 (in)
								30 20 10 70 60 50 40 (out)
	 
				Steps:
						Reverse([0],[R-1], Rcount); -> "10 20 30" -> "30 20 10"
						Reverse([R],[N-1], N-R count); -> "40 50 60 70" -> "70 60 50 40"
			*/
			void callRotateArrayClockWise()
			{
				int data[5] = { 100, 200, 300, 400, 500 };
				int N = 5;
				int R = 2;

				reverse(data, 0, R-1, R);
				reverse(data, R, N-1, N-R);

				for (int k = 0; k < N; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";

			}

			/*
				AntiClockwise Rotation
					10 20 30 40 50 60 70 (in)
					40 50 60 70 10 20 30 (out)
	 
				Steps:
						Reverse([0],[R-1], Rcount); -> "10 20 30" -> "30 20 10"
						Reverse([R],[N-1], N-R count); -> "40 50 60 70" -> "70 60 50 40"
															30 20 10 70 60 50 40 
						Reverse([0],[N-1], N-R  count); ->  40 50 60 70 10 20 30
			*/
			void callRotateArrayAntiClockwise()
			{
				int data[5] = { 100, 200, 300, 400, 500 };
				int N = 5;
				int R = 2;

				reverse(data, 0, R - 1, R);
				reverse(data, R, N - 1, N - R);
				reverse(data, 0, N - 1, N - R);

				for (int k = 0; k < N; k++)
					std::cout << data[k] << " ";

				std::cout << " \r\n";
			}

			void reverse(int* data, int s, int e, int cnt)
			{
				int k = 0;
				while (( k < cnt) && (s < e))
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