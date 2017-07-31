#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace PowerSetNM //@RED20170530014   
{
	//See CombinationToWidth @RED20170729007
	//Read "Generate combinations using Recursion_20170729007"

	/*What is powerset_20170530014
		Powerset will contain all the combinations of source set.If the src - array has 3 - elements, powerset starts with empty set, then sets of one element, then sets of two elements and finally a set with all the 3 src - elements.This reflects the bit - sequences of width 3. Empty - set corresponds to the bit sequence 000, and set with all the 3 - elements corresponds to the bit sequence 111. If source - set has N elements, then powerset will have(2 ^ N) items.

		There are two other important qualities.
		- subsets do not support duplication.Means{ A, B } and {B, A} are not allowed.This is why there will be only one subset that has all of the original elements.
		Ex:  Src = { A,B, C }
		Subset will be{ A, B } //not {B, A}.
		Note that only one subset will have all of the subsets.Ex : {A, B, C}.

		- elements of subset will obey the order of elements as it is in src - array.
		For Src = { A, B, C }
		Subset will be{ A, B }, and {A, C} but not {B, A} or {C, A}.
		Some algorithm question make mention of this special quality.For example “Given a set of real number, generate subset or combinations that are in increasing order”


		Src = { A,B, C }
		PowerSet = {}, { A }, { B }, { C }, { A,B }, { A, C }, { B,C }, { A, B, C }
		//Print Subset of given number-set (PowerSet)

		Print All the Sub­sets of a Given Set (Power Set)
		S ={1,2,3}
		PS(S): {{?}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
	*/

	class PowerSet
	{
	public:
		void printPowerSetUsingBitGen(int src[], int srcLen, int bits[], int bitIndex)
		{
			if (bitIndex == srcLen)
			{

				//Print the bits also just for the sake of understanding
				for (int i = 0; i < bitIndex; i++)
				{
					if (bits[i])
					{
						cout << " 1 ";
					}
					else
						cout << " 0 ";

				}


				cout << "  ";

				//Print the powerset
				for (int i = 0; i < bitIndex; i++)
				{
					if (bits[i])
					{
						cout << src[i] << " ";
					}

				}





				cout << "\r\n";
				return;
			}

			bits[bitIndex] = 1;
			printPowerSetUsingBitGen(src, srcLen, bits, bitIndex + 1);

			bits[bitIndex] = 0;
			printPowerSetUsingBitGen(src, srcLen, bits, bitIndex + 1);
		}
	};

	class CallPowerSet
	{
	public:
		void callPowerSetX()
		{
			int src[4] = { 2, 4, 6, 8 };
			int bits[4] = { 0,0,0,0 };

			PowerSet o1PwerSet;
			o1PwerSet.printPowerSetUsingBitGen(src, 4, bits, 0);


			int src1[3] = { 1, 2, 3 };
			int bits1[3] = { 0,0,0 };

		
			o1PwerSet.printPowerSetUsingBitGen(src1, 3, bits1, 0);
			/*
				 1  1  1   1 2 3
				 1  1  0   1 2
				 1  0  1   1 3
				 1  0  0   1
				 0  1  1   2 3
				 0  1  0   2
				 0  0  1   3
				 0  0  0
			*/

		}
	};



};