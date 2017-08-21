#pragma onc

#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// 
/*
	Heap implementation_20170621001
					Heap rule says "ParentValue > childrenValues". Starting from Root, we have to make sure this rule is satisfied at every node.
					Function is called using ParentIndex and Value. 
					Using HeapRule compute the index of Lc and Rc, using ParentIndex
					Then compare the values of parent, Lc & Rc, and find the top one.
					If Top one is the Parent, then everything is fine. Exit the function.
					If the child has higher value, swap it with the Parent.
					Then check that the child-node (that we just modified) has higher value compared to its children(grand-children).
					If child is higher than any one of the grand childre, then swap the values, just like we did here.
					To do all this, make a recursion-call and pass the index of the child that was modified.
					
					Recursion goes from Root to bottom
*/
namespace HeapBaseNM //@RED20170621001
{
	class HeapBase;
	
	

	class HeapBase
	{
		vector<int> data;
		public:
				HeapBase(int size)
				{
					data.reserve(size);
				}
				void CallKthLargestItemUsingMergeSort()
				{
					int src[9] = { 3, 2, 16, 11, 27, 4, 15, 9, 8 };
					int srcLen = 9;
					int K = 4;
					//int ret = MergeSort(src, 0, srcLen - 1, K);
					//cout << "\r\n Kth value is " << ret << "\r\n";
				}

				void Remove()
				{
					if (data.size() > 0)
					{
						data[0] = data[data.size() - 1]; //overwrite the topitem with last item.

						//shrink the vector by 1
						//data.resize(data.size() - 1);
						data.pop_back();
						int sizex = data.size();
						//reconstruct the heap from top
						HeapDown(0);
					}
				
				}

				void Insert(int value)
				{
					//extend the vector by 1. Add the new item to bottom of vector and call HeapUp
					//data.resize(data.size() + 1);
					
					//copy the new value to the newly created slot at the bottom of the vector
					//data[data.size() - 1] = value;

					data.push_back(value);
					//calls HeapUp
					HeapUp(data.size() - 1);
				}

				int Top()
				{

					int retvalue = -1;

					if (data.size() > 0)
						retvalue = data[0];

					return retvalue;
				}

		private:
				void HeapUp(int idx)
				{
					int tempIdx = idx;
					int parentIdx = 0;
					while (tempIdx > 0)
					{
						parentIdx = (tempIdx - 1) / 2;
						if (data[parentIdx] < data[tempIdx])
						{
							swap(data[parentIdx], data[tempIdx]);
							tempIdx = parentIdx;
						}
						else
							break;
					}
				}
				void HeapDown(int parentIdx)
				{
					//Heap rule says "ParentValue > childrenValues". Starting from Root, we have to make sure this rule is satisfied at every node.
					//Function is called using ParentIndex and Value. 
					//Using HeapRule compute the index of Lc and Rc, using ParentIndex
					//Then compare the values of parent, Lc & Rc, and find the top one.
					//If Top one is the Parent, then everything is fine. Exit the function.
					//If the child has higher value, swap it with the Parent.
					//Then check that the child-node (that we just modified) has higher value compared to its children(grand-children).
					//If child is higher than any one of the grand childre, then swap the values, just like we did here.
					//To do all this, make a recursion-call and pass the index of the child that was modified.
					//
					//Recursion goes from Root to bottom

					int lChild = (2 * parentIdx) + 1;		//Using HeapRule compute the index of Lc and Rc
					int rChild = (2 * parentIdx) + 2;   //Using HeapRule compute the index of Lc and Rc
					int maxIdx = 0; //Assume left child has is max

											   //find the max among L & R, then compare that against 'currIdx'
						
					if (lChild < data.size() && (data[lChild] > data[parentIdx]))
					{
						maxIdx = lChild;
					}
					else
					{
						maxIdx = parentIdx;
					}


					if ((rChild < data.size()) && (data[rChild] > data[maxIdx]))
					{
						maxIdx = rChild;
					}

					if ((maxIdx < data.size()) && (parentIdx < data.size()) && (data[parentIdx] != data[maxIdx]))
					{
						int temp = data[parentIdx];
						data[parentIdx] = data[maxIdx]; //assign which ever HIGH to parentIndx
						data[maxIdx] = temp; //child will get the lower-value. 
												//This child is a parent from some children, if not we have to adjust that also, so call HeapDown again(on the child that we modified)
						HeapDown(maxIdx);
					}
					
				}


	};

	class UseHeap
	{
	public:
		void CallUseHeap()
		{
			HeapBase objHeapBase(50);
			stringstream ss;
			int src[] = { 2, 45, 3, 61, 29, 9, 4, 52, 272, 381, 1, 132 };
			for each (int a in src)
			{
				ss << a << " ";
				objHeapBase.Insert(a);
			}

			cout << "\r\n" << "Max heap size 50 \r\n";
			cout << ss.str();

			cout << "\r\n" << "Max heap Data \r\n";

			while (true)
			{
				int value = objHeapBase.Top();
				if (value == -1)
				{
					break;
				}
				objHeapBase.Remove();
				cout << value << " ";
			}

			cout << "\r\n";

		}
	};
};