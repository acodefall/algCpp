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
		String Rotated_RED20170907008
			Rotated string is same as original string except that it starts few positions after the original string.
			But they both span same length. 
			Apply this theory to alphabets series (a-z) going for 26 letters. Say original string starts at 'a' and ends at 'z'. 
			String Rotated by 2 positons, would start at 'c', goes over 'z' and ends at 'b'
			So rotated string makes a loop.

			So we can say that by joining original with original string we can create a composite string that loops, and this composite string
			MUST contain ROTATED strings shifted by any positions.

			Now coming to the problem:
			We have a rotated string and original string. And want to know whether the rotated string originates from orig string.
			Based on above theory rotated string must be part of composite string.
			So Append the org string to itself and create a composite string.
			Then search for rotated string inside composite string.
			If we ca find, then rotated string originates from org string.
			
			
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