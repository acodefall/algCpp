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

namespace OccurenceCountInSortedArrayNM
{
    const int SIZEX = 9;
	
	class OccurenceCountInSortedArray
    {
        /*
		//@GN826 General_844_Find Occurence COunt Inside Array using DAC_GN826
			Find Occurence COunt Inside Array using DAC
				We are given a SORTED array and a NUMBER, we should find how times that number repeats.
				Linear can solution takes O(N) and DAC method takes LogN time.
				Ex: In {1,2,7,7,7,25}, number '7' repeats thrice.
				We need to find the boundaries of 7. So we make two binary searches: 
				one for finding LEFT boundary of 7 and other for finding Right boundary.
				
				Left BinSearch STOPS if 
					(src[M] == K) && src[M-1] != K)
					
				Right BinSearch STOPS if  
					(src[M] == K) && src[M+1] != K)
					
				Now the number of repetations is difference between these mid values.
				
				So we need two customized versions of Binary search code. We need to make two important changes to base-version of BinarySearch code
				 -first IF condition should be looking for matching-value.
				 -Default ELSE should probe Left-side for LeftBoundaryBinarySearchCode().
							   should probe Right-side for RightBoundaryBinarySearchCode().
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
