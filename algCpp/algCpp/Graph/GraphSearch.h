#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
#include "Graphbuild.h"
using namespace std;

namespace GraphSearch
{

	


	/*
		priority_queue  is not usable if you are planning to UPDATE the priority.
	*/

	class City
	{
		public:
			string name;
			City(string n)
			{
				name = n;
			}
	};
	template<typename T> class Vertex;

	

	template<typename T>
	class Edge
	{
		public:
			Vertex<T>* dest; //destination-vertex for Edge. 
							 //source-vertex for Edge is the vertex that is holding 'dest' pointer
			int cost;
			Edge()
			{
				dest = 0;
				cost = 0;
			}
	};

	template<typename T>
	class Vertex
	{
		public:
			T* data;
			int visited;
			list<Edge<T>*> adjList;
			Vertex()
			{
				visited = 0;
				data = 0;
			}

			~Vertex()
			{
				if (data)
				{
					delete data;
				}
				if (adjList.size() > 0)
				{
					for(auto z = adjList.begin(); z != adjList.end(); z++)
					{
						if (*z != 0)
						{
							delete (*z);
						}
					}
				}
			}

			
	};

	/*
		


	*/
	template<typename T>
	class Graph
	{
		public:
			map<string, Vertex<T>*> vertexList;

			void AddVertex(string name, T* src)
			{
				if (vertexList.find(name) == vertexList.end())
				{
					Vertex<T> *nNode = new Vertex<T>();
					nNode->data = src;
					vertexList.insert(pair<string,Vertex<T>*>(name,nNode));
				}
			}

			void AddDirectedEdge(string fromName, string toName, int cst)
			{
				Vertex<T> *nSrc = vertexList[fromName];
				Vertex<T> *nDest = vertexList[toName];

				//Create a Edge instance and add it to nSrc-Node
				Edge<T>* nEdg = new Edge<T>();
				nEdg->dest = nDest;
				nEdg->cost = cst;
				nSrc->adjList.push_back(nEdg);
			}

			

			bool DfsSearch(string startVertex, string valVertex)
			{
				bool bfound = false;
				stack<Vertex<T>*> st;

				Vertex<T>* t = vertexList[startVertex];
				st.push(t);

				while ( (st.size() > 0) && (bfound == false))
				{
					int size = st.size();
					while ((size > 0) && (bfound == false))
					{
						Vertex<T>* t1 = st.top();
						st.pop();

						if (t1->data->name == valVertex)
						{
							bfound = true;
							break;
						}

						if (t1->visited == 0)
						{
							t1->visited = 1;
							for (auto x = t1->adjList.begin(); x != t1->adjList.end(); x++)
							{
								Edge<T>* ed = (*x);
								if (ed->dest->visited == 0)
								{
									st.push_back(ed->dest);
								}
							}
						}
						size--;
					}
				}

				
				return bfound;
			}

			//Note this te
			bool BfsSearch(string startVertex, string valVertex)
			{
				bool bfound = false;
				deque<Vertex<T>*> q;

				Vertex<T>* t = vertexList[startVertex];
				q.push_back(t);

				while ((q.size() > 0) && (bfound == false))
				{
					int size = q.size();
					while ((size > 0) && (bfound == false))
					{
						Vertex<T>* t1 = q.back();
						q.pop_back(); //this will actually REMOVE the item from DEQ
						
						if (t1->data->name == valVertex)
						{
							bfound = true;
							break;
						}
						if (t1->visited == 0)
						{
							t1->visited = 1; //This is the only place where we set flag
							for(auto y = t1->adjList.begin(); y != t1->adjList.end(); y++)
							{
								Edge<T>* ed = (*y);
								if (ed->dest->visited == 0)
								{
									q.push_back(ed->dest);
								}
							}
						}
						
						size--;
					}
				}

			

				return bfound;
			}
			
			//startVertex - could be NY
			//destVertex  - could be Dubai
			int findShortestPath(string startVertex, string destVertex)
			{
				
				/*
					Say startVertex = NY
						distanceFromStartVert[Paris] = 10; //Distance between NY to Paris is 10
						distanceFromStartVert[Tokyo] = 20; //Distance between NY to Paris is 20
				*/
				map<string, int>				distanceFromStartVert; //This stores the distance between 'startVertex' and KEY. 
				map<string, string>				nearestVertexMap;
				deque<string>					allVertexQ;
				string							empty;
				//initialize the distanceFromSrc to -1
				//load every vertex to Q
				for (map<string,Vertex<T>*>::iterator g = vertexList.begin(); g != vertexList.end(); g++)
				{
					distanceFromStartVert.insert(std::pair<string, int>((*g).first, INT_MAX));
					nearestVertexMap.insert(std::pair<string, string>((*g).first, empty));
					allVertexQ.push_back((*g).first);
				}

				//Distance between 'startVertex' to 'startVertex' is 0
				distanceFromStartVert[startVertex] = 0;

				while (allVertexQ.size() > 0)
				{
					string baseVertexName = findNearestVertex(distanceFromStartVert, allVertexQ);
					Vertex<T>* lwst = vertexList[baseVertexName];

					if (lwst->adjList.size() > 0)
					{
						for (list<Edge<T>*>::iterator z = lwst->adjList.begin(); z != lwst->adjList.end(); z++)
						{
							/*



							*/
							Edge<T>* adjside = *z;
							string adjVertexName = adjside->dest->data->name;
							int newCost = adjside->cost + distanceFromStartVert[baseVertexName];
							if (newCost <  distanceFromStartVert[adjVertexName])
							{
								//Overwrite
								distanceFromStartVert[adjVertexName] = newCost;
								nearestVertexMap[adjVertexName] = baseVertexName;
								//prevVertex.push_back(baseVertexName);
							}
						}
					}
					

					//Remove from Q
					for (deque<string>::iterator itrDel = allVertexQ.begin(); itrDel != allVertexQ.end(); itrDel++)
					{
						if (*itrDel == baseVertexName)
						{
							allVertexQ.erase(itrDel);
							break;
						}
					}

					
				}

				//Construct the path
				stack<string> fullPath;
				while (destVertex.length() > 0)
				{
					fullPath.push(destVertex);
					destVertex = nearestVertexMap[destVertex];
				}

				cout << "\r\n";
				while (fullPath.size() > 0)
				{
					cout << fullPath.top() << " ";
					fullPath.pop();
				}
				return 0;
			}
			
			//Go through the 
			string findNearestVertex(map<string, int>& mapDistanceFromSrc, deque<string> vertList)
			{
				int trackMin = INT_MAX;
				string trackMinVertexName;

				for (deque<string>::iterator itrNearest = vertList.begin(); itrNearest != vertList.end(); itrNearest++)
				{
					//if(mapDistanceFromSrc[*itrNearest])
					if (trackMin > mapDistanceFromSrc[*itrNearest])
					{
						trackMin = mapDistanceFromSrc[*itrNearest];
						trackMinVertexName = *itrNearest;
					}
				}

				return trackMinVertexName;
			}
			
		
			void printGraph()
			{
				for(map<string, Vertex<T>*>::iterator z = vertexList.begin(); z != vertexList.end(); z++)
				{
					if ((*z).second != 0)
					{
						Vertex<T>* vt = (*z).second;
						cout << "\r\n" << "[" << vt->data->name << "] = ";

						for(list<Edge<T>*>::iterator y = vt->adjList.begin(); y != vt->adjList.end(); y++)
						{
							Edge<T>* ed = *y;
							if (ed->dest != 0)
							{
								Vertex<T>* vtd = ed->dest;
								cout << vtd->data->name << "(" <<  ed->cost << ") -> ";
							}
						}
					}
				}
			}
			~Graph()
			{
				if (vertexList.size() > 0)
				{
					for(map<string,Vertex<T>*>::iterator z = vertexList.begin(); z != vertexList.end(); z++)
					{
						if ((*z).second != 0)
						{
							delete ((*z).second);
						}
					}
				}
			}

	};

	/*
		Graph representation
					[Atlanta]		Washington(600)		->   Houston(800)
					[Austin]		Dallas(200)			->   Houston(160)
					[Chicago]		Denver(1000)
					[Dallas]		Denver(780)			->   Austin(200)
					[Denver]		Atlanta(1400)		->   Chicago(1000)
					[Houston]		Atlanta(800)
					[Washington]	Atlanta(600)		->   Dallas(1300)
	*/
	
	class callGraphSearch
	{
		public:
			Graph<City>* grph;
			callGraphSearch()
			{
				grph = 0;
			}

			void callGraphSearchX()
			{
				grph = new Graph<City>();
				buildGraph();

				grph->printGraph();

				//test BFS
				grph->BfsSearch("Austin", "Atlanta");

				grph->findShortestPath("Austin", "Atlanta");
				delete (grph);
			}



		private:
			void buildGraph()
			{
				//Add Verticies
				grph->AddVertex("Atlanta", new City("Atlanta"));
				grph->AddVertex("Austin", new City("Austin"));
				grph->AddVertex("Chicago", new City("Chicago"));
				grph->AddVertex("Dallas", new City("Dallas"));
				grph->AddVertex("Denver", new City("Denver"));
				grph->AddVertex("Houston", new City("Houston"));
				grph->AddVertex("Washington", new City("Washington"));

				string s1;
				string s2;
				s1 = "Atlanta";
				s2 = "Washington";
				grph->AddDirectedEdge(s1, s2, 600);

				s1 = "Atlanta";
				s2 = "Houston";
				grph->AddDirectedEdge(s1, s2, 800);

				s1 = "Austin";
				s2 = "Dallas";
				grph->AddDirectedEdge(s1, s2, 200);

				s1 = "Austin";
				s2 = "Houston";
				grph->AddDirectedEdge(s1, s2, 160);


				s1 = "Chicago";
				s2 = "Denver";
				grph->AddDirectedEdge(s1, s2, 1000);

				s1 = "Dallas";
				s2 = "Denver";
				grph->AddDirectedEdge(s1, s2, 780);

				s1 = "Dallas";
				s2 = "Austin";
				grph->AddDirectedEdge(s1, s2, 200);

				s1 = "Denver";
				s2 = "Atlanta";
				grph->AddDirectedEdge(s1, s2, 1400);

				s1 = "Denver";
				s2 = "Chicago";
				grph->AddDirectedEdge(s1, s2, 1000);


				s1 = "Houston";
				s2 = "Atlanta";
				grph->AddDirectedEdge(s1, s2, 800);

				s1 = "Washington";
				s2 = "Atlanta";
				grph->AddDirectedEdge(s1, s2, 600);

				s1 = "Washington";
				s2 = "Dallas";
				grph->AddDirectedEdge(s1, s2, 1300);


			}


	};

	
}