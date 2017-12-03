#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

namespace OccurenceCountInSortedArrayNM //@RED20170909019
{
    const int SIZEX = 9;
	
	class OccurenceCountInSortedArray
    {
        /*
		//@GN826 General_844_Find Occurence COunt Inside Array using DAC_GN826
			Find Occurence COunt Inside Array using DAC
				We are given a SORTED array and a NUMBER, we should find how times that number repeats.
				Strategy is, use two binary searches: once for finding the left border and again for finding the right border.
				Usually Binary search breaks once src[M] == Value. In this case we have do one more step.
				
				When seeking to know left-border look for 
					(src[M] == K) && src[M-1] != K) //K = 7
					
				Similarly to know the right-border look for 
					(src[M] == K) && src[M+1] != K) //K = 7
					
				After completing both the calls, subtract the one index from other. 
				This gives the number of occurence of M (7)

				Binary search method takes logN time.
				We could have solved using Linear scan and that would have taken O(N)
         */
	public:
		void callOccurenceCountInSortedArray()
        {
            int src[SIZEX] = { 1, 4, 5, 5, 5, 6, 7, 9, 10 };
            int K = 5;
			
			stringstream ss;
			cout << "src " << endl;
			for (int i = 0; i < SIZEX; i++)
			{
				cout << setw(4) << src[i];
				ss << setw(4) << i;
			}
			cout << endl;
			cout << ss.str() << endl;
			
            int L = binSearchForLeftEdgeOfV(src, K, 0, SIZEX - 1); //2
            int H = binSearchForRightEdgeOfV(src, K, 0, SIZEX - 1); //4
        }

		//Search for the index where "(src[M] == V) && (src[M-1] != V)"
		//Basically this finds the left-edge of V
		// aaaaVVVVbbbbb;
		//     *  
        int binSearchForLeftEdgeOfV(int src[SIZEX], int V, int L, int H)
        {
            int ret = -1;
            while(L <= H)
            {
                int M = (L + H)/ 2;

                //Note the 
                if ((src[M] == V) && ((src[M-1] != V) || (M == 0)))
                {	//found the left-edge of V
                    ret = M;
                    break;
                }
                else if(V > src[M])
                {
                    L = M + 1;
                }
                else //Default should be probing Left-side
                {
                    H = M - 1;
                }
            }
            return ret;
        }

		//Search for the index where "(src[M] == V) && (src[M + 1] != V)"
		//Basically this finds the right-edge of V
		// aaaaVVVVbbbbb;
		//        *
        int binSearchForRightEdgeOfV(int src[SIZEX], int V, int L, int H)
        {
            int ret = -1;
            while (L <= H)
            {
                int M = (L + H) / 2;
                if ((src[M] == V) && ((src[M + 1] > V) || (M == H)))
                {	//found the right-edge of V
                    ret = M;
                    break;
                }
                else if (V < src[M])
                {
                    L = M - 1;
                }
                else  //Default should be probing RIGHT-side
                {
                    H = M + 1;
                }
            }
            return ret;
        }
	};
};
