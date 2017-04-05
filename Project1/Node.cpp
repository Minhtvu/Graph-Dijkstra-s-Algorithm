#include "Node.h"
#include "Edge.h"
#define MAX 999999999
Node::Node(string name)
{
	this->name = name;
	this->cost = MAX;
	this->priorNode = "";
}
void Node::addEdge(string target, int cost) {
	Edge new_edge(target, cost);
	this->adjacencies.push_back(new_edge);
}
string Node::get_name()
{
	return this->name;
}
vector<Edge> Node::get_adjacencies()
{
	return this->adjacencies;
}
int Node::get_cost() {
	return this->cost;
}
string Node::get_prior_node() {
	return this->priorNode;
}
void Node::set_prior_node(string node) {
	this->priorNode = node;
}
void Node::set_cost(int cost) {
	this-> cost = cost;
}