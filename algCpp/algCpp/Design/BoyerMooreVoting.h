#pragma once
#include <iostream>
namespace BoyerMooreVotingNM //@RED20170526001
{
	//NotRead
	/*
	          BoyerMooreMejority algorithm_20170526001
					BoyerMoore alg finds the candidate that has more than 50% of vote. It supports negative voting also. Voting works as follows. 
					-Element gets a vote on first occurrence. If the next element is also same, then the element gets 2nd vote; if the next element is something else, then the element looses the vote and vote count comes to 0. So an element will come out as winner only if it appears consecutively. Because of negative voting, an element with 49% vote may loose all the votes in the last phase, and hit 0 when there is just one element is left to be counted. In the end, the last element will win with just 1 vote.

					This is an example for false positive. To avoid such false positive, after applying BoyerMoore alogorithm, we have to verify whether the winner indeed has more vote.
							So Mejority Alg has two steps
								-Find the mejority element using BoyerMoore alg
								-Then count the occurences of the 'choosen element', to make sure that it is more than 50%.

     
              http://stackoverflow.com/questions/3260653/algorithm-to-find-top-10-search-terms            
       Steps For BoyerMooreMejority algorithm_20170526002
       Declare 'currentTopElement' and 'occurenceCount'.  
          Set currentTopElement = src[0], and occurenceCount = 1;
          Then iterate the src-array.
          At each step, compare currentTopElement against currentElement.
			if (currentElement == currentTopElement)
				occurenceCount++;
			if (currentElement != currentTopElement)
				occurenceCount--; //This is negative voting 
				  If the 'occurence count' drops to zero, then unseat the currentElement, and make the currentElement as currentTopElement
									currentTopElement = currentElement
									occurenceCount = 1
				When the iteration ends, we will have something in currentTopElement.
				But that may not be the real winner, so go through the array for the seconde time, and count the occurences of currentTopElement. If occurence is more than 50%, then currentTopElement is indeed the mejority element.
					
			Ex: {5,5,5,7,8,9,10} //In the end 10 will win the vote by having just 1 vote. '5' had three votes but it lost all the 3
																										//because of 7, 8, 9

	*/
	class BoyerMooreVotingX
	{
		public:
			void callBoyerVoting()
			{
				//int data[8] = {5, 5, 5, 7, 8, 9, 10}; //failes  10

				int data[9] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 }; //passes 4

				int winner = BoyerMooreVote(data, 9);

				VerifyWinner(data, 9, winner);

			}

		private:
			int BoyerMooreVote(int* data, int len)
			{
				int selection = -1;
				int votes = 0;
				for (int i = 0; i < len; i++)
				{
					if (i == 0)
					{
						selection = data[i];
						votes = 1;
					}
					else
					{
						if (selection == data[i])
						{
							votes++;
						}
						else
						{
							votes--; //Negative voting
							if (votes == 0)
							{
								selection = data[i];
								votes = 1;
							}
						}
					}
				}

				return selection;
			}

			void VerifyWinner(int* data, int len, int winner)
			{
				int votes = 0;
				for (int i = 0; i < len; i++)
				{
					if (data[i] == winner)
					{
						votes++;
					}
				}

				if (votes >= len / 2)
					std::cout << winner << " is the winner. Votes : " << votes << std::endl;
			
			}

	};
};
