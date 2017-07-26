#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include<algorithm>
#include<queue>
#include <string>
#include <sstream>
#include <random>
using namespace std;

namespace KnuthShuffleNM
{
	const int SIZEX = 6;
	class KnuthShuffle
	{
		
		public:
			void callKnuthShuffle()
			{
				int src[SIZEX] = {3, 6, 1, 89, 332, 8};
			
				stringstream ss;
				cout << "src before shuffle " << endl;
				for (int i = 0; i < SIZEX; i++)
				{
					cout << setw(4) << src[i];
					ss << setw(4) << i;
				}
				cout << endl;
				cout << ss.str() << endl;

				//swap src[i] with src[random(i, .... MAX)]
				//swap src[i+1] with src[random(i+1, .... MAX)]
				//swap src[i+2] with src[random(i+2, .... MAX)]
				//window used for picking random number keeps on reducing
				for (int i = 0; i < SIZEX; i++)
				{
					default_random_engine rdm;
					uniform_int_distribution<int> dist(i, SIZEX-1);
					
					int r = dist(rdm);
					cout << "random index '" << r << endl;
					swap(src[i], src[r]);
				}

				stringstream ss1;
				cout << "src after shuffle " << endl;
				for (int i = 0; i < SIZEX; i++)
				{
					cout << setw(4) << src[i];
					ss1 << setw(4) << i;
				}
				cout << endl;
				cout << ss1.str() << endl;

			}

	};
};