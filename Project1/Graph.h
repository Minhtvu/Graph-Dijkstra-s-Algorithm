#pragma once
#include "Edge.h"
#include "Node.h"
#include<queue>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
struct compare
{
	bool operator()(Node l, Node r)
	{
		return l.get_cost() > r.get_cost();
	}
};
class Graph {
private:
	vector<Node> graph;
public:
	Graph();
	void MakeEmpty();
	int checkVertexExist(string);
	bool AddVertex(string vertexname);
	bool AddEdge(string fromVertex, string toVertex, int cost);
	int GetWeight(string fromVertex, string toVertex);
	bool GetAdjacent(string fromVertex, queue<string>& vertexQue);
	vector<Node> getGraph();
	Node& getNode(string node);
	bool checkExplored(string node, queue<string>& explored);
	bool checkDiscovered(string node, priority_queue<Node, vector<Node>, compare>& explored);
	int Dijkstra(string startVertex, string endVertex, queue<string>& vertexQue);
	void printPath(string vertex, string start, string destination);
	void printAdjacent(vector<Edge> vertexQue);
};

