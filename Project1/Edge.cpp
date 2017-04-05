#include "Edge.h"
using namespace std;
Edge::Edge(string target, int cost)
{
	this->target = target;
	this->cost = cost;
}
int Edge::get_cost() {
	return cost;
}
string Edge::get_target() {
	return target;
}
