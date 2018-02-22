#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
#include "Graphbuild.h"
using namespace std;



/*
		Print plain bit generator 0 or 1 
			See CombinationToWidth @RED20170729007
	
			bitgenerator code uses recursion but it does not use for-loop like combination generator.
			combination generator makes the recursion call from inside the for-loop.
			Where as bitGen code makes TWO rec-calls from outside.

			Combination code uses the for-loop for plucking an item from src-array and places it combination-array.
			In case of bitGene code, we do not pluck the value from src-array, instead it is hard coded to either 0 and 1.
			We place 0 in comb-array and make rec-call.
			once that call rec-call returns we place 1 in comb-array and make an another rec-call.

			This can be coded using for-loop also, where src-array will have [0,1] and for-loop make one rec-call in every round.
			To understand this assume we had 4 values "0 1 2 3"; if we did not use for-loop,
			we would have made four rec calls(1st rec-call after placing 0 in comb-array; 
			2nd rec-call after placing 1 in comb-array; 3rd rec-call after placing 2 in comb-array;
			4th rec-call after placing 1 in comb-array;).
			
			//Bitgen code if there were many src-values 0123
			fun(si, r[],ri)
			{
				if(ri == LEN) //base condition
					return;
					
				r[si] = 0;
				func();
				
				r[si] = 1;
				func();
				
				r[si] = 2;
				func();
				
				r[si] = 3;
				func();
			}
			
			//Bitgen code using for-loop. This just looks like comb-code
			main()
			{
				s[2] = {0,1}
				funcX(s,0, r[4],0);
			}
			
			funX(s, si, r[],ri)
			{
				if(ri == LEN) //base condition
					return;
					
				for(i = si; i < 2; i++)
					r[si] = s[i];
					func(s, si+1, r, ri+1);
			}
			
					
			

*/
namespace BitGenNM
{
	class BitGen
	{
		public:
			void useBitGen()
			{
				int output1[3] = { 0 };
				int outIndex1 = 0;
				int outputWidth = 3;
				CombinationsAllBitGen(output1, outIndex1, outputWidth);
				/*
					1 1 1
					1 1 1
					1 1 0
					1 0 1
					1 0 0
					0 1 1
					0 1 0
					0 0 1
					0 0 0
				*/
			}
			
			void CombinationsAllBitGen(int* output, int outIndex, int outputWidth)
			{
				if ( outIndex == outputWidth)
				{
					for (int i = 0; i < outIndex; i++)
					{
						cout << output[i] << " ";
					}
					cout << endl;
					return;
				}
				
				
				//ENABLE the BIT.
				output[outIndex] = 1;
				CombinationsAllBitGen(output, outIndex + 1, outputWidth);
					
				//dis-ENABLE the BIT.
				output[outIndex] = 0;
				CombinationsAllBitGen( output, outIndex + 1, outputWidth);
			}
		
	};
};

