#pragma once
#include<string>
#include<vector>
#include "Edge.h"
using namespace std;
class Node {
private:
	string name;
	string priorNode;
	vector<Edge> adjacencies;
public:
	int cost;
	Node(string name);
	void addEdge(string target, int cost);
	string get_name();
	vector<Edge> get_adjacencies();
	int get_cost();
	string get_prior_node();
	void set_prior_node(string);
	void set_cost(int);
};
