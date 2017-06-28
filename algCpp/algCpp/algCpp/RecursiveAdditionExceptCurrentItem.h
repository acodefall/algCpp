#pragma once
#include <iostream>
using namespace std;

namespace RecursiveAdditionExceptCurrentItemNM
{
	/*
		Replace array elements with the product of other elements_20170530008
			Problem: We are given an array of numbers. We should transform the array in such a way that each element should be replaced with product of all other elements except current element.
					Ex: if array has 4 elements, replace the 1st element with the product of 2nd, 3rd and 4th.
							3   5   2    7
							70  42  105  30

		Solution to Replace array elements with the product of other elements
			Use recursion to solve this. 
			Conceptually divide the product as PreData, PostData and CurrentData.
			Say Array has 5 elements, and the recursion is at index = 2.
				{ 4, 3, 10, 5, 9}
				At index = 2, 
				PreData = [0]*[1] = 12 
				PostData = [3]*[4] = 45
				currentData = [2] = 10
				PreData comes as input parameter
				PostData is the return-value, returned by the recursion made to 'DEEPER levels'.
						
				func(PreData)
				{
					currentData = data[index];
					PostData = func(PreData * currentData); //When making recursion call do  "PreData * [2]", this is because next level should know about 'his pre level'
					data[index] = PreData * PostData        //Store output[2] as "PreData * PostData"
					return (PostData *currentData);         //When returning to Upper-Level (that is callee) include the currentData also because callee has to know about 'his post level'. 
				}

		Steps for Replacing array elements with the product of other elements_20170530010
			1) Recursion parameters are src[], Len, preData, index
								preData will have the product from 0 to currentIndex, excluding current index.
			2) check if (index < N)
			3) if so store
				src[index] in currData
				Then make recursion call by passing "preData * currentData", index+ 1.
				We multiple the preData with currentData because next-level of recursion should recieve the OUR-CURRENT-DATA in his preData.
							
				Once the recursion returns, we have will know the product of next deeper levels.
				Store the return value of recursion in 'postData'.
				Now we know PostProduct and PreProduct, multiply them and assign to src[index].
				We computed the product for currentIndex by multiplying all the elements except current-Element. 
							
				WHen it comes to returning,
				return "postData * currentData" to callee, because callee should recieve OUR-CURRENT-DATA in his postData.
			4) When (index is more than N) return 1

			5) WHen calling the recursion function, outer most layer should pass 1 for PreData.

            
	*/
	//@20170530008
	class RecursiveAdditionExceptCurrentItem
	{
		public:
				void callRecursiveAdditionExceptCurrentItem()
				{
					int data[4] = {3, 5, 2, 7}; //70  42  105  30

					cout << "\r\n";
					cout << "Before recursive summing \r\n";
					for(int x = 0; x < 4; x++)
						cout << data[x] << " ";
					cout << "\r\n";
					product(data, 4, 1, 0);

					cout << "after recursive summing \r\n";
					for (int x = 0; x < 4; x++)
						cout << data[x] << " ";
					cout << "\r\n";

				}


				int product(int* data, int N, int preData, int idx)
				{
					int retValue = 1;
					if (idx < N)
					{
						int currentData = data[idx];
						int postData = product(data, N, preData * currentData, idx + 1); //When making recursion call do  "PreData * currentData", this is because next level should know about 'his pre level'
						retValue = postData * currentData;

						data[idx] = postData * preData; //Store the product of 'PreData' and 'PostData', exclude the 'currentData'
					}

					return retValue; //When returning to Upper-Level (that is callee) include the currentData also because callee has to know about 'his post level'. 
				}
	};

};

/*
3   5   2    7
70  42  105  30
 fun(data[0], 0
 fun(int prevProd,int idx)
{
              int fpart = prevProd; //store the preprod;
             
              if(idx < N) (3)
              {
                             int retValue = fun( prevProd * data[idx], idx+1);
                             retValue = retValue * data[idx];
                            
                             data[index = retValue * fpart;
              }
             
              return retValue;
}
 
f(1, 0)
fpart = 1
                                           fun(1*3, 1)
                                           fpart = 3
                                                                                      fun(3*5, 2)
                                                                                      fpart = 15
                                                                                                    
                                                                                                                   fun(3*5*2, 3)
                                                                                                                   fpart = 30
                                                                                                                                  .
                                                                                                                                 fun(3*5*2*7, 4)
                                                                                                                                  fpart = max
                                                                                                                   data[3] = 30;
                                                                                                                   r(7)
                                                                                      data[2] = 15*7;
                                                                                      r(7*2)
                                                                                     
                                           data[1] = 3*7*2;
                                           r(7*2*5)
data[0] = 1 * 5*7*2;
r(7*2*5)                           
                                                                                                                   if(i == 0)
                                                                                                                                  return 1;
                                                                                                                   if(i == 3)
                                                                                                                                 data[3] = fpart;
                                                                                                                                 retvalue = data[i];
                                                                                                                   else
                                                                                                                                  data[i] = fpart * retvalue;
                                                                                                                                 retvalue = retvalue * data[i]
*/