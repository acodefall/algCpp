#pragma once
namespace MergeSortAndStoreInSameArrayNM
{
	/*
		         
            You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.

            Since we know that A has enough buffer at the end, we won't need to allocate additional
            space. Our logic should involve simply comparing elements of A and B and inserting
            them in order, until we've exhausted all elements in A and in B.
            The only issue with this is that if we insert an element into the front of A, then we'll
            have to shift the existing elements backwards to make room for it. It's better to insert
            elements into the back of the array, where there's empty space.
         
	*/
	class MergeSortAndStoreInSameArray
	{
		public:
			void CallMergeSortAndStoreInSameArray()
			{
				int src1[] = { 90,567,4577 }; //sorted alreday
				int src2[] = { 5, 9, 68, 234, 300, 0, 0, 0 }; //sorted alreday
				
				int src1Len = 3;
				int src2Len = 5;
				int src2TotalLen = 8;

				int outIndex = src2TotalLen - 1;
		
				int lastSrc1 = src1Len - 1;
				int lastSrc2 = src2Len - 1;
				while ((lastSrc1 >= 0) && (lastSrc2 >= 0))
				{
					if (src1[lastSrc1] > src2[lastSrc2])
					{
						src2[outIndex--] = src1[lastSrc1--];
					}
					else
					{
						src2[outIndex--] = src2[lastSrc2--];
					}
				}
				while (lastSrc1 >= 0)
				{
					src2[outIndex--] = src1[lastSrc1--];
				}

				while (lastSrc2 >= 0)
				{
					src2[outIndex--] = src2[lastSrc2--];
				}
			}


	};
};