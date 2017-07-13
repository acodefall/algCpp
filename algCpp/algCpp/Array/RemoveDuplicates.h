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
namespace RemoveDuplicatesNM
{
	const int SIZEX = 12;
	class RemoveDuplicates
	{
		public:
			void callRemoveDuplicates()
			{
				

				int src[SIZEX] = {  56, 8, 4, 22, 5, 66, 4, 8, 56, 8, 34, 4 };
				UsingHashTable(src);

				int src1[SIZEX] = { 56, 8, 4, 22, 5, 66, 4, 8, 56, 8, 34, 4 };
				UsingForLoop(src1);

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