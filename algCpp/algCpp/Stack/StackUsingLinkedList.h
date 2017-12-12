#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

namespace  StackUsingLinkedListNM
{
    /* 
        Implement the Stack using Singly-LinkedList_LL06
			STACK returns latest data first; similarly LL stores the latest data at the TAIL.
			If we want STACK like output, we have to read the LL from TAIL to HEAD.
			So we have to build LL that is going from R-L, means Every newly built node should
			point to previous node that on the left-side. 
			In a way this looks like a reverse-LL, where Arrow goes R->L
			At any time TAIL node will be pointing to latest value. 
			When Push() constructs a band new node, it new node's NEXT-point will be
			pointed to TAIL node. Right after make NEW node TAIL node. 
			
			Coming POP(), it should return the value held inside TAIL because that is latest.
			We also have to expel the TAIL and do that by making TAIL point to left-node.
					TAIL = TAIL->PrevNode
			
			Key: 
			-TAIL will have the latest item.
            -PUSH will make NEW-NODE point to TAIL. This is why this is called as Reverse-Growing LL.  
			Traditionally, existing TAIL will point to New-Node.  
            -POP will return Tail, and make Tail = Tail.Next.

		Pushing values
			1  2  3  4  5  6  7  8  9

		Popping values
			9  8  7  6  5  4  3  2  1
	*/
    
	class NodeSLLForStack
	{
		public:
			int d;
			NodeSLLForStack* prev;
			NodeSLLForStack()
			{
				d = 0;
				prev = 0;
			}

			NodeSLLForStack(int x)
			{
				d = x;
				prev = 0;
			}
	};

    //Store the HEAD node in as class member.
    //
    class StackUsingLinkedListX
    {
		NodeSLLForStack* _Tail = NULL;
		NodeSLLForStack* _Head = NULL;
        int _size = 0;
    
		public:
			
		int size()
		{
			return _size;
		}
        void push(int d)
        {
			//build the NEW node	 
			NodeSLLForStack* newNode = new NodeSLLForStack();
			newNode->d = d;

			//is _Head is NULL, this is 1st node, make it the HEAD
			if (_Head == NULL)
			{
				_Head = newNode;
				_Tail = newNode;
			}
			else
			{	//there are already nodes in LL
				//NewNode's prev-ptr should to point to current TAIL
				newNode->prev = _Tail;

				//NewNode should become the TAIL
				_Tail = newNode;
			}
            _size++;
        }


        int pop()
        {
            int ret = 0;
			//_Tail is the latest node, and stack us LIFO, so return the value of TAIL to caller
			if (_Tail != NULL)
			{
				ret = _Tail->d;
				//TAIL cursor should retrive backwards by setting TAIL = TAIL->prev_node
				_Tail = _Tail->prev; //
				_size--;
			}
			
            return ret;
        }

    };
	
	class callStackUsingLinkedList
    {

		public:
		void callStackUsingLL()
        {
         
            StackUsingLinkedListX stk;
			cout << endl << "Pushing values  " << endl;
			for (int i = 1; i < 10; i++)
			{
				stk.push(i);
				cout << i << "  ";
			}
			cout << endl;

            
			cout << endl << "Popping values  " << endl;
			while (stk.size() > 0)
			{
				cout << stk.pop() << "  ";
			}
			cout << endl;
        }


    };
};
