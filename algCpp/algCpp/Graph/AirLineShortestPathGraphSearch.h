#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <limits>
#include "Graphbuild.h"
using namespace std;

namespace GraphSearch //RED20170908008
{

	

/*
	Matrix_459_Shortest Path between NY and Dubai_RED20170908008
		Strategy is to maintain a MAP of distance between NY and every other city in Graph.
		Call this MAP as Distance Map, where KEY is CITY and VALUE is 'distance from NY'
		For Example: If KEY is LONDON, then VALUE willll be the distance bwteen NY to LD.
		Initially MAP will have -1 for every city except for NY. NY's VALUE will be 0.
		This is because "distance from NY to NY is 0"
		
		Filling the Distance MAP
		Since the MAP has an entry for every vertex, we have to process every Vertex and update the corresponding 
		entry in MAP. So we to maintain the list of vertexes to be processed(call this remainingVextexList). 
		Initially remainingVextexList will have very vertex and it reduces gradually and becomes 0 in the end.
		Basically we loop through the remainingVextexList and fill DistanceMAP.
		
		Once we exit the loop, DistanceMAP will have shortest distance for 'NY to any place'
			DistanceMAP[Tokyo] gives shortest distance between 'NY -> Tokyo'
			DistanceMAP[Dubai] gives shortest distance between 'NY -> Dubai'

				//init DistanceMAP to -1 for every city except NY(NY = 0). NY = 0 because it is nearest to NY.
				 //init remainingVextexList with all vertex
				//Init PathMap with KEY(that is cityname and VALUE is "")

				CODE
				-----
						Loop( remainingVextexList)
							Scan remainingVextexList for Vertex that is NEAREST to NY(means VALUE is LOWEST in DistanceMap)
							Process such vertex(V) because we need SHORTEST path so Vertex should be NEAREST to NY.
							This is my ALG is called GREEDY

							Visit that vertex V
							(AdjList.....of V)
								Compute 'Distance between "adjList[] & NY" 
									newdist = 'dist of V from NY' + 'Weight of Edge from V & adjList[]'
									newdist = DistanceMap[V] + 'Weight of Edge from V & adjList'
			
								Write newdist to DistanceMap only if it is shorter						
									if(newdist  < DistanceMap[adjList[]] )	
										DistanceMap[adjList[]] = newdist;
										PathMap['Name of adjList[]']	= 'Name of V'		
						DistanceMAP is filled. 
						Distance MAP will be shortest distance between NY to any city.
						Actual Path will be in PathMap[]. Walk the PathMap[] in reverse direction from PathMap[Dubai] till VAUE is ""

			Computig Distance
				Say the route is "Ny - LD - Dubai", and we are processing LD vertex, and want to compute the distance between "Ny and Db'

				distance between 'Ny and Dubai' = 'distance between Ny & Ld' + 'distance between Ld & Dubai


				distance between 'NY to Dubai' is 'distance of  NY-LD" + 'distance of  LD-Dubai"
				distance between 'NY to Dubai' = 'distance of  NY-LD'  //This comes from MAP (KEY is LOD)
										+
   									 'distance of LD-Dubai'  //This is WEIGHT of edge connecting LD & Dubai.

	
	
			Finding shorter distance
				We have to do two TWEAKS for finding shortest distance.
				-First Tweak: We know that the next Vertex to be processed comes from remainingVextexList. To help us find shortest-path, apply an another condition when picking the vertex; condition is vertex should be closest to NY or source-city, this means vertex should have lowest VALUE in DistanceMAP.

				-Second Tweak: When updating the distance map, update the entry only if the new value is lower than existing value in MAP. Say [Dubai] = 800; and this is based on the route NY-LD-Db.  Later we discover a shorter route, 'Ny-Paris-Db' 500. Now we over write [Dubai] with 500.

				Let us take few example 'selecting next vertex to be processed':
				When the program starts, DistanceMAP has 0 for NY and -1 for every other city. DistanceMAP [NY] = 0 has lowest value so NY is closest to NY, so we process NY Vertex. 
						DistanceMAP [NY] = 0            remainingVextexList  {NY, LD, PR, DB}
						DistanceMAP [LD] = -1
						DistanceMAP [PR] = -1
						DistanceMAP [DB] = -1

				When processing NY, and we compute the distance for NY-LD and NY-PR, and these distances will be lower than the current value -1, so accordingly we update DistanceMAP. After processing NY, we remove NY from remainingVextexList. Next vertex to be processd will come from LD, PR and DB.  Among these Value of LD and PR is +ve value and DB is still -1.  We will pick the vertex with LOWEST value and that could be either PR or LD.
						DistanceMAP [NY] = 0   	remainingVextexList  {LD, PR, DB} //REMOVED NY, got processed
						DistanceMAP [LD] = x          
						DistanceMAP [PR] = y
						DistanceMAP [DB] = -1
				In this fashion, we ALWAYS process the vertex that has LOWEST value(or CLOSEST to NY), this is why 'shortest path algorithm' is called as GREEDY algorithm. 

			Summary 
				We achieves shortest path
				-by processing the Vertex that is NEAREST to NY
				-by updating DistanceMAP[] only if the NEW value is LOWER

			How do we know the actual shortest path
				DistanceMap[] gives the shortestDistance but not actual flight-path. Getting path needs one more map, where KEY is current-city and VALUE is previous-city. Call this as PathMap. To know the path walk the MAP in reverse direction.
				To know the path for NY-DB, 
					start from  PathMap[DB] = Paris; 	
							  PathMap[Paris] = NY; 	
											  PathMap[NY] = ""; //When VALUE stop the WALK.

				Update the  PathMap[] whenever we write somthing to DistanceMap[]. Ex: We are processing the adjacency list of Paris Vertex. Adj list has Dubai; and we compute the distance btw "Ny and Dubai" and decide to write this to DistanceMAP, that same time update PathMap[] also. Route is coming from PARIS to DUBAI. So update entry for DUBAI 
				PathMap[Dubai] = PARIS.



	

	*/

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
				map<string, int>				distanceFromStartVert;	//This stores the distance between 'startVertex'(say NY) and the city given by KEY. 
																		//Say startVertex = NY 
																		//	distanceFromStartVert[Paris] = 10; Distance between NY to Paris is 10
																		//	distanceFromStartVert[London] = 20; Distance between NY to London is 20
																		//VALUE gets updated if we find a shorter route.
																		//Say we found a shorter path between "Ny To Paris", the we write it to [Paris] = 5;

				deque<string>					remainingVertexQ; //Has the list of Vertexes to be proecessed. Initially this will have all the vertex.
																  //After processing a vertex, we remove it from this Q. Processing means going through the adj-list.
																  //Number of entries will keep on reducing and reduces to zero.
																  //So in the end we will have nothing in this Q.

				map<string, string>				PathMap;
			
															
				string							empty;
				//initialize the distanceFromSrc to -1
				//load every vertex to Q
				for (map<string,Vertex<T>*>::iterator g = vertexList.begin(); g != vertexList.end(); g++)
				{
					distanceFromStartVert.insert(std::pair<string, int>((*g).first, INT_MAX));
					PathMap.insert(std::pair<string, string>((*g).first, empty));
					remainingVertexQ.push_back((*g).first);
				}

				//Distance between 'startVertex' to 'startVertex' is 0
				distanceFromStartVert[startVertex] = 0;

				while (remainingVertexQ.size() > 0)
				{
					//If you want SHORTEST PATH, then pick the "Vertex that is nearest to NY"
					//Vertex NEAREST to NY will have LOWEST value in DistanceMAP, that is how we can find the it
					//Vertex should be a un-processed and also should be nearest to NY
					string baseVertexName = findNearestVertex(distanceFromStartVert, remainingVertexQ);
					//remainingVertexQ.pop_front();
					Vertex<T>* lwst = vertexList[baseVertexName];

					//Iterate the adjacency list of "nearest Vertex"
					if (lwst->adjList.size() > 0)
					{
						for (list<Edge<T>*>::iterator z = lwst->adjList.begin(); z != lwst->adjList.end(); z++)
						{
							Edge<T>* adjside = *z;
							string adjVertexName = adjside->dest->data->name;
							int newCost = adjside->cost + distanceFromStartVert[baseVertexName]; //add the distance 
							if (newCost <  distanceFromStartVert[adjVertexName])
							{
								//Overwrite
								distanceFromStartVert[adjVertexName] = newCost;
								PathMap[adjVertexName] = baseVertexName;
								//prevVertex.push_back(baseVertexName);
							}
						}
					}
					
					//baseVertexName got processed, adjacency list was totally explored so remove it from Q
					//Remove from Q
					for (deque<string>::iterator itrDel = remainingVertexQ.begin(); itrDel != remainingVertexQ.end(); itrDel++)
					{
						if (*itrDel == baseVertexName)
						{
							remainingVertexQ.erase(itrDel);
							break;
						}
					}
				}

				//Construct the path
				stack<string> fullPath;
				while (destVertex.length() > 0)
				{
					fullPath.push(destVertex);
					destVertex = PathMap[destVertex];
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
			
			/*//mapDistanceFromSrc has 'vertex-name' and thier 'distance-from-NY'
			//we have to go through the map and pickup the entry with lowest value
			string findNearestVertex(map<string, int>& mapDistanceFromSrc)
			{
				int trackMin = INT_MAX;
				string trackMinVertexName;

			
				for (map<string, int>::iterator itrNearest = mapDistanceFromSrc.begin(); itrNearest != mapDistanceFromSrc.end(); itrNearest++)
				{
					if (trackMin > (*itrNearest).second)
					{
						trackMin = (*itrNearest).second;
						trackMinVertexName = (*itrNearest).first;
					}
				}

				return trackMinVertexName;
			}*/
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

				/*
						[Atlanta] = Washington(600) -> Houston(800) ->
						[Austin] = Dallas(200) -> Houston(160) ->
						[Chicago] = Denver(1000) ->
						[Dallas] = Denver(780) -> Austin(200) ->
						[Denver] = Atlanta(1400) -> Chicago(1000) ->
						[Houston] = Atlanta(800) ->
						[Washington] = Atlanta(600) -> Dallas(1300) ->

					Actual PATH
						Austin Houston Atlanta
				
				
				*/
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