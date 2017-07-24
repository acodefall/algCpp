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

namespace  SortUsingStackNM
{
    /*
     
     Sorting using STACK
		This algorithm takes 0(N2) time and 0(N) space.
		There will be two stacks: srcStack and sortedStack. 
		srcStack supplies the data to be sorted and also helps sorting by providing BUFFFER space during sorting.
		sortedStack will ONLY contain the sorted output, so before pushing any item in to sortedStack,
		check if placing the item at the top of the stack will disrupt sorted order.
		
		If it is going to disrupt the sorting order, then POP the items from sortedStack,
		till the appropriate SLOT becomes open(comes TOP). Then PUSH the newItem in to sortedStack.

		Ideally the item being inserted should be LESS than the current-TOP-item in SortedItem.
		Ex: If item = 8, and TOP item is 2, then we can not PUSH 8. 
            POP the items that are LESS than 8. Once we reach the item that is HIGHER than 8, then PUSH(8)
				
									
								     //PUSH(8) will break order in sortedStack
			
			                                                //POP the items from 'sorted' and push to 'src'   
	
																				   //Do PUSH(8)
		                                              7		                7	                       
			                                          5      				5
			8					    8	              2       				2
			6		2			6		2			  6						6		
			1		5			1		5			  1						1		
			3 		7			3 		7			  3 					3 		8
			5		9			5		9   		  5		9				5		9
			Src     Sorted		Src     Sorted		  Src	Sorted			Src	    Sorted
								

						
			

		Now we have PUSHED the item in to sortedStack without disrupting sorted order.
		The items that we POPPED from sortedStack(for making space) will be sitting in srcStack. 
		This is how srcStack acts as BUFFER stack. 
		In the next round of sorting, we will POP these TEMP items from srcStack, and 
		they will simply fall in to proper sorted place because when we transferred them to srcStack, they were already in sorted order. 
		
		
	
	
     */
    

	
	class SortUsingStack
    {
        public:
		
		void callSortUsingStack()
        {
			stack<int> srcStack;
			stack<int> sortedStack;
            
			
            srcStack.push(89);
            srcStack.push(789);
            srcStack.push(59);
            srcStack.push(3534);
            srcStack.push(2);
            
            SortUsingStackx(srcStack, sortedStack);
            cout << endl << "Sorted Items " << endl;
            while(sortedStack.size() > 0)
            {
                cout << sortedStack.top() << endl;
				sortedStack.pop();
            }

            /* output
					2
					59
					89
					789
					3534 
			*/
        }
		
		void SortUsingStackx(stack<int>& srcStack, stack<int>& sortedStack )
		{
			while (srcStack.size() > 0) 
			{
				int itemToSort = srcStack.top(); 
				srcStack.pop(); //POP the item, do not leave there
				
				//empty the items in sortedStack till the TOP is LARGER than itemToSort
				//if itemToSort = 10, LOOP until we reach 10 or ABOVE
				while ((sortedStack.size() > 0) && (sortedStack.top() < itemToSort))
				{
					srcStack.push(sortedStack.top()); //srcStack is acting as BUFFER
					sortedStack.pop();
				}
				sortedStack.push(itemToSort); //now the CORRECT slot is at the TOP, Push itemToSort
			}
			return;
		}
    };
};
