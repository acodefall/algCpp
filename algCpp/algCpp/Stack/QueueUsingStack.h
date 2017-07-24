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

namespace  QueueUsingStackNM
{
    /*
     //
     Implement Queue using Stack_SH02
		Working principle is this. 
		In both STACK and QUEUE, oldest item will be at the bottom and newest item will be at the top. This means when it comes to the order of the data in physical storage both STACK and QUEUE are same. But they differ in data extraction, QUEUE extracts the data from bottom(means oldest item) and STACK extracts the data that is at the top(means latest item). Now imagine we reverse the order of the data in physical storage, then the STACK returns the data just like QUEUE. We can either reverse the data after the fact or at the time of the pushing the data, we can put the latest data at the bottom and make sure that oldest data stays at the top. Now let us see how the latter approach can be implemented, that is pushing new data at the bottom.


		(Method1)
		In this method, at the time of inserting data in to STACK, we make sure that latest data goes to the bottom and oldest item stays at the top. 
		Assume STACK S1 is empty. Someone calls PUSH and data goes to S1. Someone calls the PUSH for second time. Now PUSH extracts S1’s contents and stores in them in an another STACK called S2. Now S1 is empty. Now PUSH stores the end-user provided data in S1. Then PUSH extract the data from S2 and puts back in to S1. Now the physical storage underneath S1 will have older data at the top and newest data at the bottom. Now onwards the data returned from POP() will the oldest data(just like Queue).  Last thing remaining is rename the POP() and PUSH in to Enqueue() and Dequeue(). 

		(Method2)
		In this method, we reverse the physical storage used by STACK after the fact. Reversing STACK is easy; pop data from one STACK and push them in to second STACK. Then read the data from second STACK. Order of Data will follow that of the QUEUE. Now let us see the actual implantation.

		Have a class called Queue. It will use two STACKS to implement Queue. The stacks are push-only-stack and pop-only-stack. push-only-stack stores data like any other STACK: oldest item will be at bottom and newest item will be at the top.
		pop-only-stack is created by popping the data out of push-only-stack. This means pop-only-stack is reverse of push-only-stack. pop-only-stack is used by Dequeue() method. Dequeue() method checks if pop-only-stack is empty, if so then it fill it with the data extracted from push-only-stack
		
     * 
     */
    

   
	/*
		By making the data go through TWO stacks will serialize the data as if it is coming from Q.
		Queue-class should have two stacks(pushOnly, popOnly). Store the incoming data in pustOnly stack.
		When user wants to fetch the data from stack, pop the data from pushOnly, and temporarily push it in to popOnly stack.
		Then extract the data from popOnly stack, and return to caller. 
		So the data sought by user passed to through two stacks and this serialized the data, as if it is coming from Q.
	*/
    class QueueUsingStack2
    {
        private:
				stack<int> pushOnly; //use only for storing
				stack<int> popOnly; //Data sought by user will be store here temporarily as passthrought.

        public:
				void Enqueue(int x)
				{
					pushOnly.push(x);
				}
				int Dequeue()
				{	//
					LoadToOutGoingStack();
					int ret = popOnly.top(); //Data given to User should comes from popOnly. This is where we reverse the order of data
					popOnly.pop();
					return ret;
				}

				bool IsEmpty()
				{
					LoadToOutGoingStack();
					return (popOnly.size() == 0) ? true : false;
				}

				void LoadToOutGoingStack()
				{
					if (popOnly.size() == 0)
					{
						while (pushOnly.size() > 0)
						{
							int ret = pushOnly.top();
							pushOnly.pop();

							popOnly.push(ret);
						}
					}
				}
    };

	class QueueUsingStackX
	{
		public:
			void callQueueUsingStack()
			{
				QueueUsingStack2 q2;
				q2.Enqueue(20);
				q2.Enqueue(200);
				q2.Enqueue(2000);

				cout << endl;
				cout << "Queue content " << endl;
				while (q2.IsEmpty() == false)
				{
					cout << q2.Dequeue() << endl;
				}
			}
	};
};
