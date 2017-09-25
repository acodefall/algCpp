#pragma once
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;


/*
	
	Question:
			Implement a function to return top rated movies in the network of movies reachable from the current movie
				 eg:            A(Rating 1.2)
								/   \
							 B(2.4)  C(3.6)
							   \     /
								D(4.8)

			In the above example edges represent similarity and the number is rating. 
			getMovieRecommendations(A,2)
					should return C and D (order doesn't matter) 
			getMovieRecommendations(A,4) 
					should return A, B, C, D 
			getMovieRecommendations(A,1) 
				should return D. Note distance from A to D doesn't matter

	Implementation:
					Data is stored in Undirected graph. Iterate the Graph using BSF, and collect the data from Vertecies 
					load them to Priority_Queue(Max Heap). Then use the MaxHeap for serving user queries.

					Steps:
							Declare Movie class having Name and Rating
							Declare Edge class having pointer to 'destination Vertex of type Movie' and also weight. Hard code the weight to be 0.
							Declare Vertex class having instance-of-Movie and also list-of-Edge-instances.
							Declare a Graph class having map of movie-name and verteceis-instances.
									-Graph class will have a method that walks through Graph and loads data in PQ.

							Declare a Driver/Caller class that calls Graph class. 
									Driver class  creates Movie and Vertex instances, hands them over to Graph class.
												

*/

namespace GraphMovie
{
	class VertexMv;
	class Edge;
	class Mv
	{
		public:
			string name;
			float  rating;
			Mv(string n, float rt)
			{
				name = n;
				rating = rt;
			}
	};

	class Edge
	{
		public:
			int weight;
			VertexMv* dest;
			Edge()
			{
				dest = 0;
			}
			
	};

	class VertexMv
	{
			
		public:
			Mv* data;
			list<Edge*> edgeList;
			bool visited;
			VertexMv(Mv* d)
			{
				data = d;
				visited = false;
			}

			~VertexMv()
			{
				if (data)
				{
					delete data;
				}
				for (list<Edge*>::iterator itr = edgeList.begin(); itr != edgeList.end(); itr++)
				{
					if (*itr)
					{
						delete (*itr);
					}
				}
			}
	};

	class GraphMv
	{
		public:
			map<string, VertexMv*>  vertList;

			void AddVertex(string name, VertexMv* vt)
			{
				vertList.insert(pair<string, VertexMv*>(name, vt));
			}
			void AddUnDirectedEdge(string src, string dest)
			{
				Edge* ed = new Edge();
				ed->dest = vertList[dest];
				vertList[src]->edgeList.push_back(ed);

				Edge* ed2 = new Edge();
				ed2->dest = vertList[src];
				vertList[dest]->edgeList.push_back(ed2);
			}

			~GraphMv()
			{
				for (map<string, VertexMv*>::iterator itr = vertList.begin(); itr != vertList.end(); itr++)
				{
					if ((*itr).second)
						delete (*itr).second;
				}
			}
	};


	class compareRating
	{
		public:
			bool operator() (VertexMv* p1, VertexMv* p2)
			{
				return p1->data->rating < p2->data->rating;
			}
	};


	class testGraphMv
	{
		public:
			GraphMv grph;
			

			void testGraph()
			{
				float x = pow(2, 10);
			    cout << std::bitset<32>(pow(2, 10)) << "\r\n";

				cout << std::bitset<32>(pow(2, 2)) << "\r\n";
				cout << std::bitset<32>(pow(2, 15)) << "\r\n";

				cout << std::bitset<32>(pow(2, 26)) << "\r\n";

				int  y = 0x80000;

				//add vertecies
				grph.AddVertex("A", new VertexMv(new Mv("A",1.2)));
				grph.AddVertex("B", new VertexMv(new Mv("B", 2.4)));
				grph.AddVertex("C", new VertexMv(new Mv("C", 3.6)));
				grph.AddVertex("D", new VertexMv(new Mv("D", 4.8)));

				//add edges
				grph.AddUnDirectedEdge("A","C");
				grph.AddUnDirectedEdge("C", "D");
				grph.AddUnDirectedEdge("A", "B");
				grph.AddUnDirectedEdge("B", "D");

				//list<string> p1 = getMovieRecommendations("A", 1);
				//list<string> p2 = getMovieRecommendations("A", 2);
				list<string> p3 = getMovieRecommendations("A", 3);

				//printList(p1);
				//printList(p2);
				printList(p3);
				
				
			}

			void printList(list<string> px)
			{
				cout << "\r\n";
				for (list<string>::iterator itr = px.begin(); itr != px.end(); itr++)
				{
					cout << (*itr).c_str();
				}
			}
			typedef priority_queue<VertexMv*, vector<VertexMv*>, compareRating> pq;
			list<string> getMovieRecommendations(string start, int count)
			{
				list<string> names;
				pq lstBsf;
				makeBfsList(start, lstBsf);

				int k = 0;
				while ((k < count) && lstBsf.size() > 0)
				{
					names.push_back(lstBsf.top()->data->name);
					lstBsf.pop();
					k++;
				}
				return names;
			}
			
			void makeBfsList(string start, pq& lstBsf)
			{
				//grph.vertList
				deque<VertexMv*> q;
				q.push_back(grph.vertList[start]);

				while (q.size() > 0)
				{
					int size = q.size();
					int k = 0;
					while (k < size )
					{
						VertexMv* vt = q.front();
						q.pop_front();
						k++;
						if (vt->visited == false)
						{
							vt->visited = true;
							lstBsf.push(vt);
							for (list<Edge*>::iterator itr1 = vt->edgeList.begin(); itr1 != vt->edgeList.end(); itr1++)
							{
								if ((*itr1)->dest->visited == false)
								{ 
									q.push_back((*itr1)->dest);
								}
							}
						}
					}
				}
			}

	};
};
