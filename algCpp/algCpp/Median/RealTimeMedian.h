#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
namespace RealTimeMedianNM
{
	/*
		Fetch Median from data stream_20170622001
			Following description will help visualize the solution.
			An ascending sequence of numbers can be partinioned at the middle in to two halves. Values in left-half will be decresing as we move away from partition,
			so we can use MaxHeap for representing left-half. Similarly, the values in the right-half will be increasing as we move away from partition, so we can represent the right partition using MinHeap.
			Heaps will maintain order when the items are added and removed.

			We want to compute the median for whole sequence, Right and Left.
			We have already divided the sequence in to halves and maintained them in MinHeap and MaxHeap.
			If the whole sequence length is ODD, then see which part (L or R) is odd. Say L part is odd, then Top of MaxHeap will give median.
			If R part is odd, then Top of MinHeap will give Median.
			If the whole sequence is EVEN, then average value of 'Top of MaxHeap' and 'Top of MinHeap'.

			When computing the Median, combine both halves in to one big array and compute Median. If any one of the Heap has ODD number of elements, then root of that Heap will be the Median. If both the Heaps are same in size, then the Median is Average of the root values.

			When a new data comes-in, we need a basis for deciding whether it should go to L-side or R-side,
			Compare the incoming element against the ROOT of either MinHeap or MaxHeap(but not the both).
			Say if we are comparing with MaxHeap (that is on left side)
				-If the data is less than root-of-MaxHeap, add to Left-side.
				-If the data is higher than root-of-MaxHeap, add to Right-side.
				We should make sure that Addition of new item will NOT make the count-difference MORE THAN 1. 
				To mainatain this rule, we may have to shift the element from one side to another side, BEFORE adding the item.
				Test the count before adding the item. 
				If the side to which we are adding is having more elements, then POP one one item and push to the side with 
				lower-count. This will make the element count equal, now add the new element to intended side.

				//Say we decided to add the new-item to Left-side, but left-side has more items. Adding to it make difference MORE THAN 1
				//So Pop() one item
				if(L.count > R.Count) 
					L.pop(); //This will balance the counts on both sides.
					R.push(); 
					L.push(); //Once the balance is achieved, add the new element
				else //both the sides have same number, no need to balance.
					L.push();

				

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
