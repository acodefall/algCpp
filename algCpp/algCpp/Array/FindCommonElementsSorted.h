#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

namespace FindCommonElementsSortedNM //@RED20170714004
{	
	/*@RED20170714004
		Find the common elements in two SORTED arrays_20170714004
			Common elements are also the elements where Arrays intersect so Solution is based on finding intersection of two sorted arrays.
			Start iterating both arrays using different indexes. 
			At every step compare the values. The array who's value is HIGH will wait for other array to catch up with it.
			If src1 may have 15 at 3 index and src2 may have 15 at 5th index. In this case src1 will wait at index-3 until the 
				src1[3] = 15
				src2[5] = 15
			while(Len of Src1 and Src2)	
				if (src1[i1] > src2[i2])
				{	//Src1 is high so it will wait until src2 catches up
					i2++;
				}
				else if (src2[i2] > src1[i1])
				{  //Src2 is high so it will wait until src1 catches up
					i1++;
				}
				else
				{
					//both src1 & src2 have same value, so both can proceed simultaneously
					i1++;
					i2++;
				}
			

		src1[]
			   2   3   5  15  20
			   0   1   2   3   4
		
		src2[]
			   5   7   9  11  14  15  20
			   0   1   2   3   4   5   6

		src1[0] = 2 src2[0] = 5
			src2 is high so wait until src1 catches up i1 = 1

		src1[1] = 3 src2[0] = 5
			src2 is high so wait until src1 catches up i1 = 2

		src1[2] = 5 src2[0] = 5
			src1 & src2 have same value, so both can proceed simultaneously. i1 = 3 i2 = 1

		src1[3] = 15 src2[1] = 7
			src1 is high so wait until src2 catches up i2 = 2

		src1[3] = 15 src2[2] = 9
			src1 is high so wait until src2 catches up i2 = 3

		src1[3] = 15 src2[3] = 11
			src1 is high so wait until src2 catches up i2 = 4

		src1[3] = 15 src2[4] = 14
			src1 is high so wait until src2 catches up i2 = 5

		src1[3] = 15 src2[5] = 15
			src1 & src2 have same value, so both can proceed simultaneously. i1 = 4 i2 = 6

		src1[4] = 20 src2[6] = 20
			src1 & src2 have same value, so both can proceed simultaneously. i1 = 5 i2 = 7

		common elements are
			5 15 20
	
	*/
	const int SIZEX1 = 5;
	const int SIZEX2 = 7;
	class FindCommonElementsSorted
	{
		public:
				void callFindCommonElementsSorted()
				{
					//Data has to Sorted for us to apply Binary search
					int src1[SIZEX1] = { 2, 3, 5, 15, 20};
					int src2[SIZEX2] = { 5, 7, 9, 11, 14, 15, 20};
					stringstream ss;
					cout << "src1 " << endl;
					for (int i = 0; i < SIZEX1; i++)
					{
						cout << setw(4) << src1[i];
						ss << setw(4) << i;
					}
					cout << endl;
					cout << ss.str() << endl;

					//STL again prooves how unfriendly the damn things.
					//Bible is more friendly than STL
					//ss.clear();
					stringstream ss2;
					cout << "src2 " << endl;
					for (int i = 0; i < SIZEX2; i++)
					{
						cout << setw(4) << src2[i];
						ss2 << setw(4) << i;
					}
					cout << endl;
					cout << ss2.str() << endl;

					FindCommonElementsSortedX(src1, src2);
				}
				void FindCommonElementsSortedX(int src1[SIZEX1], int src2[SIZEX2])
				{
					int i1 = 0;
					int i2 = 0;
					vector<int> commonItems;
					commonItems.reserve(max(SIZEX1, SIZEX2));
					while (i1 < SIZEX1 && i2 < SIZEX2)
					{
						cout << endl << "src1[" << i1 << "] = " << src1[i1] << " src2[" << i2 << "] = " << src2[i2] << endl;
						if (src1[i1] > src2[i2])
						{	//Src1 is high so it will wait until src2 catches up
							cout << "    src1 is high so wait until src2 catches up i2 = " << i2 + 1 << endl;
							i2++;
						}
						else if (src2[i2] > src1[i1])
						{  //Src2 is high so it will wait until src1 catches up
							cout << "    src2 is high so wait until src1 catches up i1 = " << i1 + 1 << endl;
							i1++;
						}
						else
						{
							//both src1 & src2 have same value, so both can proceed simultaneously
							cout << "    Both src1 & src2 have same value, so both can proceed simultaneously. i1 = " << i1 + 1 << " i2 = " << i2 + 1 << endl;
							
							commonItems.push_back(src1[i1]); //this item is same, add to commnElement list
							i1++;
							i2++;
						}
					}

					cout << endl << "common elements are " << endl;
					for (int i = 0; i < commonItems.size(); i++)
					{
						cout << commonItems[i] << " ";
					}
					cout << endl;
				}
	};
};