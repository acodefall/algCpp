#pragma once
#include <set>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
namespace FindDistinctIslandNM
{


	/*
		Count number of Islands in a matrix_RED20180209004
			1 is considered LAND, and 0 is considered as WATER. To become an Island there should be at least two adjacent 
			cells with value 1. We have to find out the Islands, and filter out the island with duplicate shape.
			
			Logic is, Cursor starts from (0,0), and assumes (0,0) as the root for island and recursively 
			goes in to every neighboring cell, and checks if the value is 1. If the cell value is 1, we record cordinates in a SET.
			Recursion breaks once we encounter an cell that has been either 'processed-already'  OR 'cell-value-is-0'.

			Once recursion breaks, generate the hash for the shape of the island, by appending all coordinates 
			of the cells with value 1. So the hash is one long string with all the coordinates. Then Store the hash in a "ShapesSet"
			Now we have found out the island that starts from (0,0). 
			
			Repeat this process by using other cells as starting-cell. Then find out the shape; then compute the hash for
			that shape; and finally add the Hash to "ShapesSet".
			
			We are also interested in indentifying duplicate shapes. For example, an island with 2-cells should be 
			matched, irrespective of where it is located. This can be done by normalizing the cordinates of the cells that make up the island.
			Nomralization involves subtracting every cordinate from the co-rdinate of the starting-cell. So the normalized
			conrdinate for 2-celled island will be same where it is located in Matrix. In order to realize this
			recursion function should carry the cordinates of starting cell as input, and use it for subtracting current-cell's cordinates.

			
		Coming to implementation:
			Use two nested for-loops for iterating Matrix, and the call the recursive-function. 
			This recursive function call itself until cell value is 1. 
			If "current-cell is 1", and "current-cell has not been visited already", 
			then NOrmalize the coordinates of the cell, and add it to SET.
			Then make 4 recursion calls to all the four neighboring cells.


			Use recusrion for finding out the shape. Note down the coordinates of the cells whos value is 1.
			Say the cursor is as cell (x,y). First make sure that cell has not been processed. 
			If this is the first visit, check if the value is 1. If the value is 1, record the coordinates in a 
			SET. Then we have to explore the neighboring cells also so make recursion calls in to 4 neighboring cells. 
			Recursion breaks once we encounter an 'already-processed-cell'  OR 'cell-value-is-0'.
			Once recursion breaks, control comes to nested-for-loop. There iterate the SET containing cordonates,
			join them togather in to a long string. Add hash to ShapesSet. In the end ShapesSet will have 
			the list of UNIQUE islands.
		
		find out the isalnds. 
		
						11000
						11000
						00011
						00011
						 1



						11011
						10000
						00001
						11011
						3
	*/
	class cordinateCompare
	{
		public:
			bool operator()(pair<int, int> d1, pair<int, int> d2)
			{
				if ((d1.first == d2.first) && (d1.second == d2.second))
				{
					return true;
				}
				return false;
			}
	};
	/*
		Find the number of Distinct Islands in Matrix_RED20180208003
			Island should have atleast two 1s adjacent cells in any direction. Island ends when we encounter 0.
			is a cell with wil have more than one 

	*/
	int const Rx = 4;
	int const Cx = 5;
	class FindDistinctIsland
	{

		public:
			void callFindDistinctIsland()
			{
				/*int src[Rx][Cx] = 
				{
					{1,1,0,0,0},
					{1,1,0,0,0},
					{0,0,0,1,1},
					{0,0,0,1,1}
				};*/ //1 unique island
					
				

				int src[Rx][Cx] =
				{
					{ 1,1,0,1,1 },
					{ 1,0,0,0,0 },
					{ 0,0,0,0,1 },
					{ 1,1,0,1,1 }
				}; //3 unique island

				set<pair<int, int>> visited;
				set<string> shapes;

				for (int i = 0; i < Rx; i++)
				{
					for (int j = 0; j < Cx; j++)
					{
						set<pair<int, int>> shape;
						findIsland(src, i,j,i,j,visited,shape);
						NormalizeCords(shape, shapes);

					}
				}
				
			}

			void NormalizeCords( set<pair<int, int>>& shape, set<string>& shapes)
			{
				stringstream ss;
				//nomralize the shapes by converting them in to string
				for (auto itr = shape.begin(); itr != shape.end(); itr++)
				{
					ss << (*itr).first << (*itr).second;
				}

				shapes.insert({ ss.str() });
			}

			
			void findIsland(int d[Rx][Cx], int r, int c, int startX, int startY, 
				set<pair<int, int>>& visited, 
				set<pair<int,int> >& shape)
			{
				//check whether current cell is 1, if so it is LAND 

				//check if any of the neigbours are also LAND (that is 1)
				if (
						(r < Rx && c < Cx) && 
						(d[r][c] == 1) && 
						(visited.find({r,c}) == visited.end())
					)
				{
					visited.insert({ r,c });
					shape.insert({ r - startX, c - startY }); //This computes the ACTUAL 
					findIsland(d, (r + 1), c, startX, startY, visited, shape);
					findIsland(d, r, (c + 1), startX, startY, visited, shape);
					findIsland(d, (r - 1), c, startX, startY, visited, shape);
					findIsland(d, r, (c - 1), startX, startY, visited, shape);
				}
			}


	};
};