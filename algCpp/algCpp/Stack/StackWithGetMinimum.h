#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

namespace  StackWithGetMinimumNM //@RED20170723019
    {
        /* 
		Stack with GetMinValue()_20170723019
            Implement a STACK that can return the LOWEST value as of now. Maintain two twin Stacks: main-stack and lowValue-stack. Stacks will grow & shrink togather, and their height will always be same. Difference is that Main-stack keeps the latest-arrival item at the TOPSlot, irrespective of whether the value is small or big. Where as lowValue-stack keeps only the smallest value at TOPSlot. lowValue-stack will ignore the new new-arrival if it's value is not smaller (when compared to the value that is already at the TOPSlot). Instead lower-stack will re-inserts the current Top-value oncemore. This results in duplication of data but keeps the height of the both stacks same.

			Let us take an example: 
				In the beginning both the stacks are empty. 
				First item comes, and we insert it to both stacks.
					8  8
						//GetMinValue() returns 8;  

				2nd item comes and it is a large value; we add this to main-stack in any case. lowValue-stack will ignore this because it is not smaller than existing TOP-value. lowValue-stack will reinsert the TOP-value once more. 
				    10  8 --> GetMinValue() returns this
					8   8
            

				Now the height of both the stacks are same. lowValue-stack has two items and their value is same, and value is 
				smallest among the two values that are kept in main-stack.
				In case, if the user queries for LOWEST value, we can return the TOP value taken from lowValue-stack,

				3rd item comes and it happens to be smallest also. We add the new-arrival to main-stack, and 
				also to lowValue-stack. In case, if the user queries for LOWEST value, we can return the TOP value of lowValue-stack.
        
					2   2 --> GetMinValue() returns this
					10  8
					8   8
    
				Implementation:
				-Push()
					Push to main-stack unconditionally.
					Push to lowValue-stack if it is only smaller compared to current TOPSLot value.
					therwise reinsert the current TOPSlot Value oncemore.

				-Pop()
					Pop an item from main-stack and return to caller
					Pop an item from lowValue-stack and THROW the value. This POP is done to keep the height of the STACK same.

				-GetMin()
					Pop an item from lowValue-stack and return to caller.
					Pop an item from main-stack and THROW the value. This POP is done to keep the height of the STACK same.

					main    Min
					10      0
					8       0
					0       0
					9       9
					89      89
					89      89

                    Implementing STACK.
                        Here the class will maintain two stacks: MinValue-stack and Main-stack. 
                        Same PUSH() and POP() function will operate on both the Stacks.
                        First ever item to be inserted will be pushed in to both the Stacks.
                        When inserting subsequent item, we compare the TOP item from MinValue-stack against the NEW-item,
                        which ever is the lower, will be PUSHED. If the TOP-item is lower, we PUSH it again, thus doubling it.
                        if the NEW-item is lower, then we PUSH the NEW-item.  
                        We always PUSH the NEW-item in to Main-stack.

                        Let this class have a function called getMin() and this PEEK in to MinValue-stack, and return that value.


                        Implementing QUEUE
                        Implement QUEUE using two STACKS(push-only-stack and pop-only-stack). Class will have a function called getMin().
                        getMin() will call getMin() on both push-only-stack and pop-only-stack, and return which ever is lower.
         */
        /*
         *        
			
         * 
         */
	


    //Maintain an two stack.
    //Insert in to 1st stack in  normal way. When inserting in to 2nd Stack make sure 
    class StackWithGetMinimum
    {
        private :
				stack<int> mainStack;
				stack<int> LowValueStack; //stores the lowest value as of now.
				
        public:
		void Push(int item)
        {
			//if the stack in empty push it to both mainStack and LowValueStack
            if (mainStack.size() == 0)
            {
                mainStack.push(item);
                LowValueStack.push(item);
            }

            int currLowValue = LowValueStack.top();

            LowValueStack.push(min(currLowValue, item));
            mainStack.push(item);
        }

        int Pop()
        {
            int ret = LowValueStack.top();
            LowValueStack.pop();
            return ret;
        }

        int getMin()
        {
            return LowValueStack.top();
        }

        int Count()
        {
            return mainStack.size();
        }

       
        void printLowStack()
        {
			cout << endl << "Low value stack " << endl;
            while (LowValueStack.size() > 0)
			{
				int ret = LowValueStack.top();
				LowValueStack.pop();
                cout << ret << endl;
			}

        }

        void printMainStack()
        {
			cout << endl << "mainStack " << endl;
            while (mainStack.size() > 0)
			{
				int ret = mainStack.top();
				mainStack.pop();
                cout << ret << endl;
			}
        }
    };
	
	class callStackWithGetMinimum
	{
        public: 
			void callStackWithGetMinimumX()
			{
				StackWithGetMinimum st;

				st.Push(89);
				st.Push(9);
				st.Push(0);
				st.Push(8);
				st.Push(10);

				st.printMainStack();
				st.printLowStack();
			}
    };
};
