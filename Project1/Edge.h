#pragma once
#include<string>
using namespace std;
class Edge {
private:
	int cost;
	string target;
public:
	Edge(string, int);
	int get_cost();
	string get_target();
};
