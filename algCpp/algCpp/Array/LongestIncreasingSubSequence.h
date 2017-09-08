
#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
namespace LongestIncreasingSubSequenceNM //@RED20170712001
{
	/*
		Compute the length of 'Longest Increasing SubSequence'_RED20170712001 
		Given an un sorted array, 'Increasing SubSequence' stores only those numbers that are in increasing order, 
		and those numbers does not have to be neighbours. Longest Increasing SubSequence is the length of such subset.
		Longest Increasing SubSequence can be generalized as length of the sub-array who's elements are increasing
		
		Longest Increasing SubSequence can be computed using DP, where the Solution array will hold the maximum length of 
		'Longest Increasing SubSequence' as of now. 
		
		To begin with Sol[0] will have 1, for building subseuent solution elements, add 1 to  pre-sol-element, if "curr-value > prev-value"; 
				if (src[cur] > src[prev])   //other wise, pre-sol-array will be replicated as current-sol-element even though the "curr-value < prev-value"; 
					sol[curr] = sol[prev] + 1; //This is because Sol[] is supposed to have MAX 'Longest Increasing SubSequence' as of now.
												//add to 1 to pre-sol-array and make current solution[] other wise, pre-sol-array will become current-sol-element
				else
					sol[curr] = sol[prev];
				
		Last value of Sol[] will give 'length of Longest Increasing SubSequence' 

		Compute the length of 'Longest Increasing SubSequence':
			src[SIZEX] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
			sol[SIZEX] = { 1,   2, 2,  3,  3,  4,  4,  5,  6 };
			length of Longest Increasing SubSequence = 6;

			Building solution[]
					{src[1] > src[0]}  22 > 10
						{Sol[1] = Sol[0] + 1} = 1 + 1 = 11
		
					{src[2] > src[1]}  9 > 22
						{Sol[2] = Sol[1]} =  Sol[2] = 2
		
					{src[3] > src[2]}  33 > 9
						{Sol[3] = Sol[2] + 1} = 2 + 1 = 10
		
					{src[4] > src[3]}  21 > 33
						{Sol[4] = Sol[3]} =  Sol[4] = 3
		
					{src[5] > src[4]}  50 > 21
						{Sol[5] = Sol[4] + 1} = 3 + 1 = 22
		
					{src[6] > src[5]}  41 > 50
						{Sol[6] = Sol[5]} =  Sol[6] = 4
		
					{src[7] > src[6]}  60 > 41
						{Sol[7] = Sol[6] + 1} = 4 + 1 = 42
		
					{src[8] > src[7]}  80 > 60
						{Sol[8] = Sol[7] + 1} = 5 + 1 = 61
		
			solution[] 1 2 2 3 3 4 4 5 6
	
	*/
	const int SIZEX = 9;
	class LongestIncreasingSubSequence
	{

	public:
		void callLongestIncreasingSubSequence()
		{

			int src[SIZEX] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };

			LongestIncreasingSubSequenceX(src);
		}


		void LongestIncreasingSubSequenceX(int src[SIZEX])
		{
			int Sol[SIZEX] = { 0 };

			Sol[0] = 1;

			for (int i = 1; i < SIZEX; i++)
			{
				cout << "{src[" << i << "] > src[" << i - 1 << "]} = " << src[i] << " > " << src[i - 1] << endl;
				if (src[i] > src[i - 1])
				{
					cout << "{Sol[" << i << "] = " << "Sol[" << i - 1 << "] + 1} = " << Sol[i - 1] << " + 1 = " << src[i - 1] + 1 << endl; ;
					Sol[i] = Sol[i - 1] + 1;
				}
				else
				{
					cout << "{Sol[" << i << "] = Sol[" << i - 1 << "]} = " << " Sol[" << i << "] = " << Sol[i - 1] << endl;
					Sol[i] = Sol[i - 1];
				}
			}

			cout << "solution[] ";
			for (int i = 0; i < SIZEX; i++)
			{
				cout << Sol[i] << " ";
			}
			cout << endl;

		}
	};
};