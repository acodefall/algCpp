#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>
#include "BuildLL.h"
using namespace std;
using namespace BuildLLNM;
namespace ReverseAlternativeKNodesNM //@RED20170705002
{
	
	/*
		
		/*
				Reverse Alternative K elements_@RED20170705002
					Reverse 1st K nodes, then leave the next K nodes untouched, and then Reverse the next K nodes.
					Reversal and Skipping is handled by same function, and they call each other recursively, until the while LL is processed. 
					Skipping and reversing is handled by Pre-recursion code. Once a segment is reversed, the node that is in contact with next segment will change; this is like swapping of HEAD and TAIL.
					Because of this, post-recursion code will have to re-connect the adjacent segments properly. For this to work, callee should return Post-reversal-HEAD for his segment, and then the caller should hookup the returned node to "Post-reversal-TAIL" of his segment.  Skipping operating will not swap HEAD and TAIL so it can use HEAD and TAIL that was passed to it, where Reversal code has to swap the HEAD and TAIL nodes.

						K = 3      h         t      h        t       h        t
						In:          10 15 20    25 30 35    40 45 50    55 60 65    70 75 80     85 90 95
						Out :      20 15 10    25 30 35    50 45 40    55 60 65    80 75 70     85 90 95

					Implementation
					Reverse code will Reverse K nodes.
					At the end of reversal, cursor would have gone past K nodes, and will be at 1st node of Next-K-Segment
					That is exactly the Node to be used for making SKIPPING-Recursion call, so use cur
					Recursion call will return the HEAD-Node, take that return value and connect it to 'post-reversal-Tail' of our segment, so use rt->Next

					We should also return 'post-reversal-Head' to our caller. 'post-reversal-Head' is nothing but the last node of K-segment, and it is held by prev. Return it to caller.

					Skip code will Skip K nodes.
					At the end of skipping, cursor would have gone past K nodes, and will be at 1st node of Next-K-Segment
					That is exactly the Node to be used for making REVERSING-Recursion call, so use cur
					Recursion call will return the HEAD-Node, we should connect it to 'post-reversal-Tail'.
					Tail is the last node of K-segment and it is held by prev. So assign the return value to prev->next
					We should also return 'post-reversal-Head' to our caller. 'post-reversal-Head' is nothing but the rt passed to us.
					Return rt to caller.

					fun(rt)
					{
						cur
						prev

						if(Rev)
						{
							while(K > 0)
								reverse
					
							rt->next = fun(cur);
					
							return prev;
						}
						else
						{
							while(K > 0)
								skip
							
							prev->next = fun(cur);
				
							return rt;
						}
					}



	
		K = 3
		In:    10 15 20    25 30 35    40 45 50    55 60 65    70 75 80     85 90 95
		Out:   20 15 10    25 30 35    50 45 40    55 60 65    80 75 70     85 90 95
	             reverse      skip       rev         skip        rev          skip
	*/
	class ReverseAlternativeKNodes
	{
		public:
			void callReverseAlternativeKNodes()
			{
				int K = 3;
				BuildLL sLL;
				sLL.AddValues();
				
				cout << "\r\n";
				cout << "Reverse K altarnative nodes of SLL. K: " << K << "\r\n";
				BuildLL::printLL(sLL.root);
				cout << "\r\n";

				NodeSLL* rev = reverseAltKNodes(sLL.root, K,1);
				cout << "\r\n";
				cout << "SLL after reversing alternative K nodes. K " << K << "\r\n";
				BuildLL::printLL(rev);
				cout << "\r\n";

			}

			
			/*
					K = 3      h      t    h      t    h     t
						In:    10 15 20    25 30 35    40 45 50    55 60 65    70 75 80     85 90 95
						Out :  20 15 10    25 30 35    50 45 40    55 60 65    80 75 70     85 90 95

			*/

			
			NodeSLL* reverseAltKNodes(NodeSLL* rt, int K, int rerverse)
			{
				int Ki = K;
				NodeSLL* cur = rt;
				NodeSLL* prev = NULL;
				 

				if (rt == NULL)
					return rt;

				if (rerverse == 1) //Reverse the K nodes. 
				{
					//At the end of reversal, cursor would have gone past K nodes, and will be at 1st node of Next-K-Segment
					//That is exactly the Node to be passed to SKIPPING-Recursion call, so use cur
					//Recursion will return the HEAD-Node, we should connect it to 'post-reversal-Tail', so use rt->Next
					//We should also return 'post-reversal-Head'. 'post-reversal-Head' is nothing but the last node of K-segment,
					//and it is held by prev. Return it to caller.
					//	
					//
					//

					while ((Ki > 0) && (cur)) //Since K is count, stay above 0. 
					{
						//backup the CONTENT of curr before altering its content (that is curr->next)
						NodeSLL* tmp = cur->next;
						cur->next = prev; //make curr->next point to backward, instead of forward
						prev = cur; //backup the curr node itself
						cur = tmp; //change the cursor to to Next 
						Ki--;  
					}

					//After revesal, cur will be at 1st node of Next-K-Segment. Use it for making next recursion call
					rt->next = reverseAltKNodes(cur,K, 0);
					//reverseAltKNodes() returns Post-reversal-HEAD, and we have to connect it to Post-reversal-TAIL(which is 1st node of K segment that we reversed). 
					//Value that we need is rt
					
					//RETURN Post-reversal-HEAD, that is last node of K-segment which got reversed. Value that we need is in 'prev'
					return prev; 
				}
				else
				{
					//Skip the K nodes
					//At the end of skipping, cursor would have gone past K nodes, and will be at 1st node of Next-K-Segment
					//That is exactly the Node to be passed to REVERSING-Recursion call, so use cur
					//Recursion will return the HEAD-Node, we should connect it to 'post-reversal-Tail'.
					//Tail the last node of K-segment and it is held by prev. So assign the return value to prev->next
					//We should also return 'post-reversal-Head'. 'post-reversal-Head' is nothing but the rt passed to us.
					//Return rt to caller.
					
					//To call the next recursion use the 'last Node of K segment'->Next
					//Return headNode that was passed to us. That is rt

					//skip k items
					while ((cur != NULL) && (Ki > 0))
					{
						prev = cur;
						cur = cur->next;
						Ki--;
					}

					//After skipping. cur will be pointing to beginning of next Kth segment.
					prev->next = reverseAltKNodes(cur, K, 1);

					return rt;
				}
			}

	
	};

};