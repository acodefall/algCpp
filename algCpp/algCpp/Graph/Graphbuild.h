#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <algorithm>
#include <memory>
#include <deque>
#include <queue>
using namespace std;

/*
#include <iostream>
#include <queue>
using namespace std;

struct compare
{
bool operator()(const int& l, const int& r)
{
return l > r;
}
};

int main()
{
priority_queue<int,vector<int>, compare > pq;

pq.push(3);
pq.push(5);
pq.push(1);
pq.push(8);
while ( !pq.empty() )
{
cout << pq.top() << endl;
pq.pop();
}
cin.get();
}

*/

//This represents a Edge. Source of edge is the Node that is hosting THIS object;
//and Target Node is given by Edge::TargetNode
template<typename T> class Edge;

template<typename T>
class graphNode
{
	public:
		graphNode(T d)
		{
			data = d;
			visited = 0;
		}
		list<Edge<T>*> edgeList;
		T data; //vertex given inside circle
		int visited;

		void printAdjList()
		{
			cout << "\r\n";
			cout << "[" << data << "]  ";
			for (auto x = edgeList.begin(); x != edgeList.end(); x++)
			{
				cout << (*x)->TargetNode->data << "(" << (*x)->cost << ")   ->   ";
			}
		}

		bool operator == (const graphNode& u)
		{
			bool ret = false;
			if (this->data == u.data)
				ret = true;
			return ret;
		}
		~graphNode()
		{
			for (auto x = edgeList.begin(); x != edgeList.end(); x++)
			{
				if ((*x) != 0)
					delete ((*x));
			}	
		}
};

template<typename T>
class Edge
{
	public:
		Edge(graphNode<T>* N, int cst)
		{
			TargetNode = N;
			cost = cst;
		}
		graphNode<T>* TargetNode; //Source of the Edge is the node that is hosting current object.
		int cost;
};

template<typename T>
class GraphAirLine
{
	deque<graphNode<T>> q;


	public:
		list<graphNode<T>*> vertList;

		GraphAirLine()
		{

		}
		void AddVertex(T vrt)
		{
			graphNode<T>* frm = findByValue(vertList, vrt);

			if (frm == 0)
			{
				vertList.push_back(new graphNode<T>(vrt));
			}
		}

		void AddDirectedEdge(T from, T to, int cost)
		{
		
			graphNode<T>* frm = findByValue(vertList, from);
			graphNode<T>* trg = findByValue(vertList, to);
			Edge<T>* edj = new Edge<T>(trg, cost);
			frm->edgeList.push_back(edj);
		}

		graphNode<T>*	findByValue(list<graphNode<T>*> lst, T value)
		{
			//if (lst.size() > 0)
			{
				list<graphNode<T>*>::iterator frmI = lst.begin();

				for (; frmI != lst.end(); frmI++)
				{
					graphNode<T>* v = *frmI;
					if (v->data == value)
					{
						return v;
					}
				}
			}
			return 0;
		}

		~GraphAirLine()
		{
			for (auto x = vertList.begin(); x != vertList.end(); x++)
			{
				if ((*x) != 0)
				{
					//delete ((*x));
					delete ((*x));
				}
			}
		}
	
	
		void findShortestPath(string src)
		{


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
class testGraphAirLine
{
	public:
		void calltestGraphAirLine()
		{
			GraphAirLine<string>* grph = new GraphAirLine<string>();

			//Add Verticies
			grph->AddVertex("Atlanta");
			grph->AddVertex("Austin");
			grph->AddVertex("Chicago");
			grph->AddVertex("Dallas");
			grph->AddVertex("Denver");
			grph->AddVertex("Houston");
			grph->AddVertex("Washington");

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

			for (auto y = grph->vertList.begin(); y != grph->vertList.end(); y++)
			{
				(*y)->printAdjList();
			}
			delete (grph);
		}
};