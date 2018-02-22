#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
namespace FindMinValueInRotatedArrayNM
{
	/*
		Find MIN element in Rotated array_RED20180129009
			Rotated array must have junction where low-value and high-value meet.
			Say un-rotated array had 1 as min-value and 10 as max-value. When this array
			is rotated, 10 and 1 will sit next to each other.
			Our logic should look for junction where 10 & 1 meets, and then take the lowest value among them.
			When searching for junction, look for (s[M] > s[M + 1]). WHen this is met ,stop the search.
			Our code must push the cursor(M) to the CENTER of the array. Say (L < M), cursor is in left-side but junction is on the right,
			so go-right.
			Similarly if (M < H), cursor is in right-side but junction is on the left so go-left.


	*/
	const int MX = 7;
	class FindMinValueInRotatedArrayX
	{
		public:
			void callFindMinValueInRotatedArray()
			{
				int src[7] = { 4, 5, 6, 7, 1,2,3 };
				int c = find(src,0,6); //1
			}


			int find(int s[MX], int L, int H)
			{

				while (L <= H)
				{
					int M = (H - L + L) / 2;

					if (s[M] > s[M + 1])
					{
						return min(s[M], s[M+1]);
					}
					else if (s[L] > s[M] ) //4 [5] 3 2 1 7 9 -->  
					{
						L = M + 1;
					}
					else if (s[M] < s[H]) //4 5 3 2 1 [7] 9 --> 
					{
						H = M - 1;
					}
				}
			}
	};

};