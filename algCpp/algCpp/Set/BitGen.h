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

