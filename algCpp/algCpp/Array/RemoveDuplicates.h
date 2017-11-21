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
/*
	Iterating Two Sorted Array simultaneously_20170714004
	This logic is used at few places:
		-To find common element in two sorted arrays
		-To find Kth item in two sorted arrays.

		There will be two sorted arrays. Same while loop will be iterating both of them; means one loop may read a value from ar1 and next loop may read value from ary2. The order of reading MUST be asecnding. If ar1=5 and ar2=7 then read 5 from ar1 because the PATH must be ascending. Always keep this in mind,
			iteration should go from "from LOW-Number to Higher Number only".
		Coming to the coding, Use only one while loop for iterating both the arrays; but use different indexes.
		At the top of every while loop we have the option of reading from ar1 or ar2; but read the one that is lower. Reason is "path of iteration has to be Low to High".  check what is the next value in ar1 anf & ar2. 
		Say Ar1 = 8 Ary2 = 10, Read from Ar1 and increment Ar1

		It also possible both arrays have same value, in that case increment both the indexes 
			Ar1 = 15 Ary2 = 15, Read from Ar1 and increment Ar1 & Ar2

*/
namespace RemoveDuplicatesNM
{
	//@RED20170724006
	const int SIZEX = 12;
	//TBD write for STRING also
	class RemoveDuplicates
	{
		public:
			void callRemoveDuplicates()
			{
				

				int src[SIZEX] = {  56, 8, 4, 22, 5, 66, 4, 8, 56, 8, 34, 4 };
				UsingHashTable(src);  //56 8 4 22 5 66 34

				int src1[SIZEX] = { 56, 8, 4, 22, 5, 66, 4, 8, 56, 8, 34, 4 };
				UsingForLoop(src1);  //22 5 66 56 8 34 4

			}

		private:
			void UsingHashTable(int src[SIZEX])
			{
				unordered_set<int> set;
				int iSkipCount = 0;
				for (int i = 0; i < SIZEX; i++)
				{
					//Item is not in HashTable so it is not a duplicate
					//So insert the item to HashTable and also copy it.
					if (set.find(src[i]) == set.end())
					{
						set.insert({ src[i] });
						src[i - iSkipCount] = src[i];
					}
					else
					{	//Item is duplicate. Do not copy it, increment the duplicateCounter
						iSkipCount++;
					}
				}

				//fill the extra items with -1
				for (int i = SIZEX - iSkipCount; i < SIZEX; i++)
				{
					src[i] = -1;
				}

				//after expelling duplicates
				cout << "post cleanup data " << endl;
				for (int i = 0; i < SIZEX - iSkipCount; i++)
				{
					cout << src[i] << " ";
				}
				cout << endl;
			}
			//rattarugo
			//r
			// a
			void UsingForLoop(int src[SIZEX])
			{
				int iSkipCount = 0;
				for (int i = 0; i < SIZEX; i++)
				{
					bool found = false;
					//find the 1st duplicate occurence
					for (int j = i+1; j < SIZEX; j++)
					{
						if (src[i] == src[j])
						{
							found = true;
							break;
						}
					}

					if (found)
					{ 
						iSkipCount++;
					}
					else
					{
						src[i - iSkipCount] = src[i];
					}
				}

				//fill the extra items with -1
				for (int i = SIZEX - iSkipCount; i < SIZEX; i++)
				{
					src[i] = -1;
				}

				//after expelling duplicates
				cout << "post cleanup data " << endl;
				for (int i = 0; i < SIZEX - iSkipCount; i++)
				{
					cout << src[i] << " ";
				}
				cout << endl;
			}
	};
};