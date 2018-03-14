#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <sstream>
using namespace std;

namespace FindMaxSubArryOfSizeKNM
{
	const int MAX = 9;
	class FindMaxSubArryOfSizeK
	{
		public:
			void callFindMaxSubArryOfSizeK()
			{
				int src[MAX] = {4, 2, 8, 3, 5, 9,12, 53, 1};
				int K = 2;
				FindMaxSubArryOfSizeK1(src, K);
			}

			void FindMaxSubArryOfSizeK1(int s[MAX], int K)
			{
				int sum = 0;
				int m = 0;
				for (int i = 0; i < MAX; i++)
				{
					if (i < K)
					{
						sum += s[i];
					}
					else
					{
						sum -= s[i - K];
						sum += s[i];
					}

					if (m < sum)
						m = sum;
				}

				cout << m << endl;
			}
	};
};