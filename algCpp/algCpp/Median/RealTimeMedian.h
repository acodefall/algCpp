#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
namespace RealTimeMedianNM
{
	/*
		Fetch Median from data stream_20170622001
			In order to compute the median of real-time data, we have to arrange the data in following way.
			Imagine a sorted array as split in to two parts at the middle of the array.
			Values in left-half will be decresing as we move away from partition, so we can use MaxHeap for representing left-half. 
			Similarly, the values in the right-half will be increasing as we move away from partition, so we can represent the right partition using MinHeap.
			After this computing median is easy. If the size of both the heaps are same, then the median is average of top elements of 
			Min and Max Heap. If the size difference is 1, then the MEDIAN is top element of the HEAP whith higher count.
			Key thing is as new items comes in, it should be added to in such a way that, size difference at the max is 1.
			To achieve this equivibruim we may have to shift the element from one heap to other heap.
			Say the size difference is 1, and we want to add insert in to the higher-count side. Now pop the TOP element 
			from that higher-count side and push in to lower side, and the insert the NEW item to higher-count side.
			After addition the size difference stays at 1.

			Implementation
			-Need MinHeap, MaxHeap data members
			-Insert() and Median() function.
			-Insert function inserts new item. it should decide whether item goes in to Min & Max Heap.
			 This is how we could decide where to add. NewItem <= LeftTop, then add to left-heap. 
			 If NewItem >= RightTop, then add to Right-heap. 
			 Now before adding check the size, if the size is same, simply add. Otherwise shift the top element and then insert.
							if(L.count > R.Count) 
								L.pop(); //This will balance the counts on both sides.
								R.push(); 
								L.push(); //Once the balance is achieved, add the new element
							else //both the sides have same number, no need to balance.
								L.push();


			How do we find the median?
			Median computaion depends on size of Max and Min heap.
			If the size is same, median is average of top element of Min and Max Heap.
			Otherwise MEDIAN is top element of the HEAP whith higher count.


				

			Note: at any time values held by "top-of-maxHeap"  and "top-of-minHeap" should appear as continueos number.
			// 1 4 6 ---- 8 7 9 //WRONG
			// 1 4 6 ---- 7 8 9 //Correct
	*/

	class RealTimeMedian
	{

		struct comprLess
		{
		public:
			bool operator() (int p1, int p2)
			{
				if (p1 < p2)
					return false;
				else
					return true;
			}
		};

		struct comprMore
		{
		public:
			bool operator() (int p1, int p2)
			{
				if (p1 < p2)
					return true;
				else
					return false;
			}
		};

	public:
		comprLess cLess;
		comprMore cMore;
		priority_queue<int, vector<int>, comprLess> minheap{cLess};
		priority_queue<int, vector<int>, comprMore> maxheap{ cMore };

		int getMedian()
		{
			if (maxheap.size() == minheap.size())
			{ //sequence is EVEN so the median is average 
				return (maxheap.top() + minheap.top()) / 2;
			}
			else
			{
				//sequence is ODD so the median is TOP value of the which ever Heap that is HIGHT is quantity
				if (maxheap.size() > minheap.size())
					return maxheap.top();
				else if (minheap.size() > maxheap.size())
					return minheap.top();
			}
		}
		void InsertNewElement(int item)
		{
			//Sequence has no item. This is the first item add it to MaxHeap on LEFT side.
			if (maxheap.empty() && minheap.empty())
			{
				maxheap.push(item);
			}  //Compare ONLY against the MAXHeap that is on LEFT-side.
			else if (item <= maxheap.top())
			{ //add the item to left-side

				if (maxheap.size() > minheap.size())
				{
					//transferred the element from Left to Right
					//Maxheap on leftside is higher in capacity so transfer one item from MaxHeap to MinHeap
					int transfer = maxheap.top();
					maxheap.pop(); //remove the top item
					minheap.push(transfer);//transferred the element from Left to Right
				}

				//insert the new item in to maxHeap
				maxheap.push(item);
			}
			else
			{ //add the item to right-side

				if (minheap.size() > maxheap.size())
				{
					//transferred the element from Right to Left
					//Minheap on right side is higher in capacity so transfer one item from MinHeap to MaxHeap
					int transfer = minheap.top();
					minheap.pop(); //remove the top item
					maxheap.push(transfer);//transferred the element from Left to Right
				}

				//insert the new item in to minHeap
				minheap.push(item);
			}

			cout << endl << "item : " << item << endl;
			

		}

		void printheaps()
		{
			//print the values of heaps
			cout << endl << "Minheap content  (Right-side. Order of Printed data is correct)" << endl;
			while (minheap.empty() == false)
			{
				cout << minheap.top() << " ";
				minheap.pop();
			}

			cout << endl << "Maxheap content (Left-side. Order of Printed data is reverse)" << endl;
			while (maxheap.empty() == false)
			{
				cout << maxheap.top() << " ";
				maxheap.pop();
			}
			cout << endl;

		}
	};

	class CallRealTimeMedian
	{
	public:
		void CallCallRealTimeMedianX()
		{
			cout << endl << "CallRealTimeMedian" << endl;
			RealTimeMedian  objRealTimeMedian;
			objRealTimeMedian.InsertNewElement(16);
			objRealTimeMedian.InsertNewElement(32);
			objRealTimeMedian.InsertNewElement(2);
			objRealTimeMedian.InsertNewElement(12);

			objRealTimeMedian.InsertNewElement(6);
			objRealTimeMedian.InsertNewElement(320);
			objRealTimeMedian.InsertNewElement(76);
			objRealTimeMedian.InsertNewElement(3);
			objRealTimeMedian.InsertNewElement(56);

			//get the median
			int x = objRealTimeMedian.getMedian();
			cout << endl << "Median is " << x << endl;

			objRealTimeMedian.printheaps();
			
		}

		
	};
};
