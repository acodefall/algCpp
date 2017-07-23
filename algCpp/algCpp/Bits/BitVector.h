#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <memory>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

namespace  BitVectorNM
{
	class BitVector
	{
	public:
		void callBitVector()
		{
			constructBitVector(63);
		}

		/* 
			MaxValue to be stored in BitVector. Length of the bitVector Array is (BitLenOfMaxValue/8).
			So we have to know the bit-width of MaxValue. We can know this left-shifting MaxValue
			
		*/
		void constructBitVector(int MaxValue)
		{
			//66 = 2 * 5   0010 0001

			int BitLenOfMaxValue = 0;
			int temp = MaxValue; 
			
			//compute the bit width of MaxValue by right shifting the MaxValue
			while (temp)
			{
				temp = temp >> 1;
				BitLenOfMaxValue++;
			}

			cout << "MaxValue to be stored in BitVector '" << MaxValue << "' BitLenOfMaxValue '" << BitLenOfMaxValue << "'" << endl;

			//Length of bitVector Array Len is (BitLenOfMaxValue/8)
			int bitVectorLen = pow(2, BitLenOfMaxValue - 3);

			cout << "BitVector array length in bytes'" << bitVectorLen << "'" << endl;
		
		
			//allocate memory for 
			shared_ptr<unsigned char>  bitVector(new unsigned char[bitVectorLen]);

			//init
			for (int i = 0; i < bitVectorLen; i++)
			{
				bitVector.get()[i] = (unsigned char)0;
			}

			//store Value in bit vector
			//get BitIndex and BitOffset and then enable particular bit
			int tempMax = MaxValue;
			while (tempMax)
			{
				int bitIndex = tempMax / 8;	//Ex:	For 12, 1
				int bitOffet = tempMax % 8;	//		For 12, 4
				
				bitVector.get()[bitIndex] = (bitVector.get()[bitIndex] | bitOffet); //Enable that bit

				tempMax--;
			}

			//print the bitvector array
			for (int i = 0; i < bitVectorLen; i++)
			{
				cout << std::bitset<8>(bitVector.get()[i]) << endl;
			}


			//read from bitvector
			for (int bitIndex = 0; bitIndex < bitVectorLen; bitIndex++)
			{
				unsigned char d = bitVector.get()[bitIndex];

				//each bit stoored in 'd' should be interpreted as DEC number
				//We know BitIndex(i), we have to find out BitOffset(which ever bit is enabled in 'd')
				//scan for the bits enabled in 'd'
				for (int bitOffset = 0; bitOffset < 8; bitOffset++)
				{
					if (d && (1 << bitOffset))
					{
						int decodedValue = (8 * bitIndex) + pow(2, bitOffset);
						cout << "bitIndex " << setw(4) << bitIndex << " bitOffset " << setw(4) << bitOffset << " Value " << setw(4) << decodedValue << endl;
					}
				}
			}


		}

	};
};