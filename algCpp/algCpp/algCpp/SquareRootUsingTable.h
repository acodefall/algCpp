#pragma once
#include <iostream>
#include <math.h>
using namespace std;
namespace SquareRootUsingTableNM
{
	class SquareRootUsingTable
	{
		public:
				
			/*
				int sqrt
				1 = 0.4
				2 = 1.22
				3 = 1.8
				4 = 2

			*/
				void CallSquareRootUsingTable()
				{
					//To know the Fill table of length 2 ^ 8 with Sqrt for numbers going from 1 - > (2 ^ 16)
					int tableSize = pow(2, 8);
					int maxInput = pow(2, 16);
					float* map = new float[tableSize];
					for (int i = 1; i < maxInput; i++)
					{
						map[i-1] = sqrt((double)i);
					}

					int N = 59;
					SquareRootUsingTableX(N, map, maxInput);

					if (map)
						delete [] map;


				}

				float SquareRootUsingTableX(int N, float map[], int maxInput)
				{
					float retvalue;
					int start = 0;
					int end = maxInput; //start and end correspond to N(not the table size)

					while (start < end)
					{
						int mid = start + (end - start) / 2;
						int sqareTemp = mid * mid;

						//squart higher than N, means mid is also higher than N, so next-mid should be on the LEFT side
						if (sqareTemp > N)
						{
							end = mid - 1;
						}
						else if (sqareTemp < N)
						{
							start = mid - 1;
						}
						else
						{
							retvalue = map[mid];
						}

					}
					return retvalue;
				}
	};

};

