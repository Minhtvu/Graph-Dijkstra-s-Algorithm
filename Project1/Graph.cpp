#include "Graph.h"

Graph::Graph() {}
void Graph::MakeEmpty()
{
	graph.clear();
}
int Graph::checkVertexExist(string vertex)
{
	int source_index = -1;
	for (unsigned int i = 0; i < graph.size(); i++)
	{
		if (graph[i].get_name() == vertex)
		{
			source_index = i;
			break;
		}
	}
	return source_index;
}
bool Graph::AddVertex(string vertexname)
{
	for (unsigned int i = 0; i < graph.size(); i++)
	{
		if (graph[i].get_name() == vertexname)
		{
			return false;
		}
	}
	Node new_node(vertexname);
	graph.push_back(new_node);
	return true;
}
bool Graph::AddEdge(string fromVertex, string toVertex, int cost)
{
	int source_index = checkVertexExist(fromVertex);
	if (source_index == -1) return false;
	vector<Edge> check = graph[source_index].get_adjacencies();
	for (unsigned int j = 0; j < check.size(); j++)
	{
		if (check[j].get_target() == toVertex)
			return false;
	}
	graph[source_index].addEdge(toVertex, cost);
	return true;
}
int Graph::GetWeight(string fromVertex, string toVertex)
{
	int source_index = checkVertexExist(fromVertex);
	if (source_index == -1) return -1;
	vector<Edge> check = graph[source_index].get_adjacencies();
	for (unsigned int j = 0; j < check.size(); j++)
	{
		if (check[j].get_target() == toVertex)
			return check[j].get_cost();
	}
	return -1;
}

bool Graph::GetAdjacent(string fromVertex, queue<string>& vertexQue) {
	int source_index = checkVertexExist(fromVertex);
	if (source_index == -1) return false;
	while (!vertexQue.empty())
	{
		vertexQue.pop();
	}
	vector<Edge> check = graph[source_index].get_adjacencies();
	for (unsigned int j = 0; j < check.size(); j++)
	{
		vertexQue.push(check[j].get_target());
	}
	return true;
}
vector<Node> Graph::getGraph() {
	return this->graph;
}
Node& Graph::getNode(string node)
{
	for (unsigned int i = 0; i < graph.size(); i++)
	{
		if (node == graph[i].get_name())
			return graph[i];
	}
}
bool Graph::checkDiscovered(string node, priority_queue<Node, vector<Node>, compare>& explored)
{
	unsigned int size = explored.size();
	for (unsigned int i = 0; i < size; i++)
	{
		Node top = explored.top();
		string current = top.get_name();
		explored.pop();
		explored.push(top);
		if (current == node)
			return true;
	}
	return false;
}
bool Graph::checkExplored(string node, queue<string>& explored)
{
	unsigned int size = explored.size();
	for (unsigned int i = 0; i < size; i++)
	{
		string current = explored.front();
		explored.pop();
		explored.push(current);
		if (current == node)
			return true;
	}
	return false;
}
void Graph::printPath(string vertex, string start, string destination)
{
	if (vertex != start) {
		printPath(getNode(vertex).get_prior_node(), start, destination);
	}
	if (vertex != destination) {
		std::cout << vertex + " -> ";
	}
	else {
		std::cout << vertex << endl;
	}
}
void Graph::printAdjacent(vector<Edge> vertexQue) {
	cout << endl;
	for (unsigned int i = 0; i < vertexQue.size(); i++)
	{
		cout << vertexQue[i].get_target() << " ";
	}
	cout << endl;
}
int Graph::Dijkstra(string startVertex, string endVertex, queue<string>& vertexQue){
	int source_index = checkVertexExist(startVertex);
	if (source_index == -1) return -1;
	priority_queue<Node, vector<Node>, compare> discovered;
	queue<string> adjacent;
	string currentNode;
	getNode(startVertex).set_cost(0);
	discovered.push(getNode(startVertex));
	vertexQue.push(startVertex);
	while (!discovered.empty()) {
		Node top = discovered.top();
		currentNode = top.get_name();
		discovered.pop();
		if (currentNode == endVertex)
		{
			printPath(endVertex,startVertex, endVertex);
			return getNode(endVertex).get_cost();
		}
		vector<Edge> adjacent = getNode(currentNode).get_adjacencies();
		for (unsigned int i = 0; i < adjacent.size(); i++)
		{	
			string nextNode = adjacent[i].get_target();
			if (checkExplored(nextNode, vertexQue)) {
				continue;
			}
			if (checkDiscovered(nextNode, discovered)) {
				if (getNode(currentNode).get_cost() + adjacent[i].get_cost() < getNode(nextNode).get_cost()) {
					getNode(nextNode).set_prior_node(currentNode);
					getNode(nextNode).set_cost(getNode(currentNode).get_cost() + adjacent[i].get_cost());
				}
			}
			else {
				getNode(nextNode).set_prior_node(currentNode);
				getNode(nextNode).set_cost(getNode(currentNode).get_cost() + adjacent[i].get_cost());
				discovered.push(getNode(nextNode));
			}		
		}
		vertexQue.push(currentNode);
	}
	return -1;
}