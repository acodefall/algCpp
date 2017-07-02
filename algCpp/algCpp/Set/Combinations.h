#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
#include "Graphbuild.h"
using namespace std;

namespace CombinationsNM
{
	class Combination
	{
		public:

			/*
			output
			comb1UsingForLoop
			A A A
			A A B
			A A C
			A B B
			A B C
			A C C
			B B B
			B B C
			B C C
			C C C


			comb1UsingRecursion
			A A A
			A A B
			A A C
			A B B
			A B C
			A C C
			B B B
			B B C
			B C C
			C C C

			*/
			void useCombination()
			{
				char src[3] = { 'A', 'B', 'C'};
				cout << "CombinationUsingForLoop \r\n \r\n";
				CombinationUsingForLoop(src, 3);

				

				cout << "CombinationWithDuplicates2 \r\n \r\n";
				char src21[4] = { 'A', 'B', 'C', 'D' };
				int out21[4] = { 0 };
				CombinationWithDuplicates(src21, 0, 4, out21, 0, 4);

				cout << "CombinationWithoutDuplicates2 \r\n \r\n";
				char src22[4] = { 'A', 'B', 'C', 'D' };
				int out22[4] = { 0 };
				CombinationWithoutDuplicates(src22, 0, 4, out22, 0, 4);


				

			}

			

			void CombinationUsingForLoop(char src[], int outLen)
			{
				cout << "comb1UsingForLoop \r\n";
				for (int i = 0; i < outLen; i++)
				{
					for (int j = i; j < outLen; j++)
					{
						for (int k = j; k < outLen; k++)
						{
							cout << src[i] << " " << src[j] << " " << src[k] << " \r\n";
						}
					}
				}
			}

		void CombinationWithDuplicates(char src[], int srcIndex, int srcLen, int selection[], int outIndex, int K)
		{
			if (outIndex == K)
			{
				for (int a = 0; a < outIndex; a++)
				{
					cout << src[selection[a]] << " ";
				}
				cout << "\r\n";
				return;
			}
		

			for (int i = srcIndex; i < srcLen; i++)
			{
				selection[outIndex] = i;
				CombinationWithDuplicates(src, i, srcLen, selection, outIndex + 1, K);
			}
		}

		void CombinationWithoutDuplicates(char src[], int srcIndex, int srcLen, int selection[], int outIndex, int K)
		{
			if (outIndex == K)
			{
				for (int a = 0; a < outIndex; a++)
				{
					cout << src[selection[a]] << " ";
				}
				cout << "\r\n";
				return;
			}
			
			for (int i = srcIndex; i < srcLen; i++)
			{
				selection[outIndex] = i;
				CombinationWithoutDuplicates(src, i + 1, srcLen, selection, outIndex + 1, K);
			}
		}

		
	/*
			CombinationWithoutDuplicateUsingBitGen
						A B C D

			CombinationWithDuplicates
						A B C D

			CombinationWithoutDuplicates
						A A A A
						A A A B
						A A A C
						A A A D
						A A B B
						A A B C
						A A B D
						A A C C
						A A C D
						A A D D
						A B B B
						A B B C
						A B B D
						A B C C
						A B C D
						A B D D
						A C C C
						A C C D
						A C D D
						A D D D
						B B B B
						B B B C
						B B B D
						B B C C
						B B C D
						B B D D
						B C C C
						B C C D
						B C D D
						B D D D
						C C C C
						C C C D
						C C D D
						C D D D
						D D D D


		
		
		*/
	};
};

