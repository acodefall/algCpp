#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>

using namespace std;
namespace StringRotatedNM
{
	/*
		String Rotated
			Difference between Rotated string and original string is that original string begins at 0th index and ends at last index; 
			where as rotated string begins at 2nd or 3rd index, and makes U-turn and then ends.
			Both will extend for same length. 
			So the solution is to append original string to itself so it makes circular loop.
			This circular looped string will have both original string and rotated string.

			For example: 
				Src   {1 2 3 4}   //starts at [0] and goes for4 counts
				Rotated {2 3 4 1} //starts at [1] and also  and goes for 4 counts. And this made a U-turn also

				LoopedSrc = {1 2 3 4   1 2 3 4} //This will have both original and rotated sequence
			                 .......
							   ........
							     ...........

			Steps:
					a) LoopedSrc = Src + Src
					b) Search for RotatedSrc in LoopedSrc
						"2 3 4 1" should be present in "1 2 3 4   1 2 3 4"
	*/
	class StringRotated
	{
		public:
			StringRotated()
			{
				cout << "in StringRotated";
			}
			void callStringRotated()
			{
				string src("mytest");
				string rotated("testmy");

				string loopedSrc = src.append(src); //creates circular loop of src

				//loopedSrc will have src, and also all versions of rotated strings
				if (loopedSrc.find(rotated) != -1)
				{
					cout << "rotated";
				}
			}
	};
};