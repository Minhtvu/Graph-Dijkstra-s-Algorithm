#include<iostream>
#include "Graph.h"
using namespace std;
int main()
{
	Graph graph;
	string option;
	while (true) {
		cout << "Welcome to Graph Test. You are already have an empty graph. Here are some options you can work with: " << endl;
		cout << "INIT: Reset the Graph" << endl;
		cout << "ADDV: Request a string, then add that string as a vertex " << endl;
		cout << "ADDE - Request the name of two vertices, then a weight between the vertices. Creates an edge based on this info." << endl;
		cout << "PRINT - Prints each vertex in the graph, along with all edges and weights associated with the vertex." << endl;
		cout << "TEST_GETWEIGHT - Getting weight between Austin-Dallas and Austin-Denver if exists, otherwise the weight is -1" << endl;
		cout << "TEST_GETADJACENT - Getting the adjacent list of Austin if exists" << endl;
		cout << "PATH - Request the name of two vertices. Return the path and the minimum cost if exists" << endl;
		cout << "TEST1 - Initializes the graph. Then insert the vertices and edges defined for the example on slide 5 in lecture 14 (Game Map and Graphs)." << endl;
		cout << "TEST2 (Bonus Points) - Initializes the graph. Then insert the vertices and edges defined for the example on slide 2 (Movealot) in lecture 14." << endl;
		cout << "QUIT - Quit the test program." << endl;
		cout << "Enter your chosen option: ";
		cin >> option;
		if (option == "INIT")
		{
			graph.MakeEmpty();
		}
		else if (option == "ADDV") {
			string vertex;
			cout << "Enter the name of the vertex: ";
			cin >> vertex;
			bool check = graph.AddVertex(vertex);
			if (check == false)
			{
				cout << "Error happens. Cannot add the same vertex!!!" << endl;
			}
			else {
				cout << "Successfully add " << vertex << " to the graph." << endl;
			}
		}
		else if (option == "ADDE") {
			string vertex1, vertex2;
			int cost;
			cout << "Enter the name of the first vertex: ";
			cin >> vertex1;
			cout << "Enter the name of the second vertex: ";
			cin >> vertex2;
			cout << "Enter the cost of the edge: ";
			cin >> cost;
			bool check = graph.AddEdge(vertex1, vertex2, cost);
			if (check == false)
			{
				cout << "Error happens. Source vertex might not exist or the edge has already been established!!!" << endl;
			}
			else {
				cout << "Successfully add edge from" << vertex1 << " to " << vertex2 << " with a cost of " << cost << " to the graph." << endl;
			}
		}
		else if (option == "PRINT") {
			vector<Node> result = graph.getGraph();
			for (unsigned int i = 0; i < result.size(); i++) {
				cout << result[i].get_name() << ";Adjacent: ";
				vector<Edge> check = result[i].get_adjacencies();
				for (unsigned int j = 0; j < check.size(); j++)
				{
					if (j == check.size() - 1)
						cout << check[j].get_target() << " (" << check[j].get_cost() << ")";
					else
						cout << check[j].get_target() << " (" << check[j].get_cost() << "),";
				}
				cout << endl;
			}
		}
		else if (option == "TEST1") {
			graph.MakeEmpty();
			graph.AddVertex("Austin");
			graph.AddEdge("Austin", "Dallas", 200);
			graph.AddEdge("Austin", "Houston", 160);
			graph.AddVertex("Dallas");
			graph.AddEdge("Dallas", "Austin", 200);
			graph.AddEdge("Dallas", "Chicago", 900);
			graph.AddEdge("Dallas", "Denver", 780);
			graph.AddVertex("Denver");
			graph.AddEdge("Denver", "Chicago", 1000);
			graph.AddEdge("Denver", "Atlanta", 1400);
			graph.AddVertex("Washington");
			graph.AddEdge("Washington", "Atlanta", 600);
			graph.AddEdge("Washington", "Dallas", 1300);
			graph.AddVertex("Chicago");
			graph.AddEdge("Chicago", "Denver", 1000);
			graph.AddVertex("Houston");
			graph.AddEdge("Houston", "Atlanta", 800);
			graph.AddVertex("Atlanta");
			graph.AddEdge("Atlanta", "Washington", 600);
			graph.AddEdge("Atlanta", "Houston", 800);
			vector<Node> result = graph.getGraph();
			for (unsigned int i = 0; i < result.size(); i++) {
				cout << result[i].get_name() << ";Adjacent: ";
				vector<Edge> check = result[i].get_adjacencies();
				for (unsigned int j = 0; j < check.size(); j++)
				{
					if (j == check.size() - 1)
						cout << check[j].get_target() << " (" << check[j].get_cost() << ")";
					else
						cout << check[j].get_target() << " (" << check[j].get_cost() << "),";
				}
				cout << endl;
			}
		}
		else if (option == "TEST2") {
			graph.MakeEmpty();
			graph.AddVertex("A1");
			graph.AddEdge("A1", "A2", 3);
			graph.AddEdge("A1", "B1", 2);
			graph.AddVertex("A2");
			graph.AddEdge("A2", "A1", 3);
			graph.AddEdge("A2", "B2", 3);
			graph.AddVertex("B1");
			graph.AddEdge("B1", "A1", 3);
			graph.AddEdge("B1", "B2", 3);
			graph.AddEdge("B1", "C1", 2);
			graph.AddVertex("B2");
			graph.AddEdge("B2", "A2", 3);
			graph.AddEdge("B2", "B1", 2);
			graph.AddEdge("B2", "C2", 3);
			graph.AddVertex("B5");
			graph.AddEdge("B5", "C5", 3);
			graph.AddEdge("B5", "B6", 3);
			graph.AddVertex("B6");
			graph.AddEdge("B6", "C6", 2);
			graph.AddEdge("B6", "B5", 3);
			graph.AddVertex("C1");
			graph.AddEdge("C1", "D1", 1);
			graph.AddEdge("C1", "B1", 2);
			graph.AddEdge("C1", "C2", 3);
			graph.AddVertex("C2");
			graph.AddEdge("C2", "C1", 2);
			graph.AddEdge("C2", "B2", 3);
			graph.AddEdge("C2", "C3", 3);
			graph.AddEdge("C2", "D2", 2);
			graph.AddVertex("C3");
			graph.AddEdge("C3", "C2", 3);
			graph.AddEdge("C3", "C4", 3);
			graph.AddEdge("C3", "D3", 2);
			graph.AddVertex("C4");
			graph.AddEdge("C4", "C3", 3);
			graph.AddEdge("C4", "C5", 3);
			graph.AddEdge("C4", "D4", 1);
			graph.AddVertex("C5");
			graph.AddEdge("C5", "C4", 3);
			graph.AddEdge("C5", "B5", 3);
			graph.AddEdge("C5", "C6", 2);
			graph.AddEdge("C5", "D5", 2);
			graph.AddVertex("C6");
			graph.AddEdge("C6", "B6", 2);
			graph.AddEdge("C6", "D6", 2);
			graph.AddEdge("C6", "C5", 3);
			graph.AddVertex("D1");
			graph.AddEdge("D1", "C1", 1);
			graph.AddEdge("D1", "E1", 4);
			graph.AddEdge("D1", "D2", 1);
			graph.AddVertex("D2");
			graph.AddEdge("D2", "D1", 1);
			graph.AddEdge("D2", "C2", 3);
			graph.AddEdge("D2", "E2", 2);
			graph.AddEdge("D2", "D3", 1);
			graph.AddVertex("D3");
			graph.AddEdge("D3", "D2", 1);
			graph.AddEdge("D3", "D4", 1);
			graph.AddEdge("D3", "C3", 3);
			graph.AddEdge("D3", "E3", 1);
			graph.AddVertex("D4");
			graph.AddEdge("D4", "D3", 1);
			graph.AddEdge("D4", "C4", 3);
			graph.AddEdge("D4", "D5", 1);
			graph.AddEdge("D4", "E4", 2);
			graph.AddVertex("D5");
			graph.AddEdge("D5", "D4", 1);
			graph.AddEdge("D5", "C5", 3);
			graph.AddEdge("D5", "D6", 1);
			graph.AddEdge("D5", "E5", 4);
			graph.AddVertex("D6");
			graph.AddEdge("D6", "C6", 2);
			graph.AddEdge("D6", "D6", 1);
			graph.AddEdge("D6", "E6", 2);
			graph.AddVertex("E1");
			graph.AddEdge("E1", "D1", 2);
			graph.AddEdge("E1", "E2", 2);
			graph.AddVertex("E2");
			graph.AddEdge("E2", "E1", 4);
			graph.AddEdge("E2", "D2", 2);
			graph.AddEdge("E2", "F2", 4);
			graph.AddEdge("E2", "E3", 2);
			graph.AddVertex("E3");
			graph.AddEdge("E3", "E2", 2);
			graph.AddEdge("E3", "D3", 1);
			graph.AddEdge("E3", "E4", 2);
			graph.AddEdge("E3", "F3", 1);
			graph.AddVertex("E4");
			graph.AddEdge("E4", "E3", 2);
			graph.AddEdge("E4", "D4", 2);
			graph.AddEdge("E4", "E5", 4);
			graph.AddEdge("E4", "F4", 2);
			graph.AddVertex("E5");
			graph.AddEdge("E5", "E4", 2);
			graph.AddEdge("E5", "D5", 2);
			graph.AddEdge("E5", "E6", 2);
			graph.AddEdge("E5", "F5", 2);
			graph.AddVertex("E6");
			graph.AddEdge("E6", "E5", 4);
			graph.AddEdge("E6", "D6", 2);
			graph.AddEdge("E6", "F6", 2);
			graph.AddVertex("F2");
			graph.AddEdge("F2", "E2", 2);
			graph.AddEdge("F2", "F3", 2);
			graph.AddVertex("F3");
			graph.AddEdge("F3", "F2", 4);
			graph.AddEdge("F3", "E3", 1);
			graph.AddEdge("F3", "F4", 2);
			graph.AddEdge("F3", "G3", 1);
			graph.AddVertex("F4");
			graph.AddEdge("F4", "F3", 2);
			graph.AddEdge("F4", "E4", 2);
			graph.AddEdge("F4", "F5", 2);
			graph.AddEdge("F4", "G4", 2);
			graph.AddVertex("F5");
			graph.AddEdge("F5", "F4", 2);
			graph.AddEdge("F5", "E5", 4);
			graph.AddEdge("F5", "F6", 2);
			graph.AddVertex("F6");
			graph.AddEdge("F6", "F5", 2);
			graph.AddEdge("F6", "E6", 2);
			graph.AddVertex("G1");
			graph.AddVertex("G3");
			graph.AddEdge("G3", "F3", 1);
			graph.AddEdge("G3", "H3", 1);
			graph.AddVertex("G4");
			graph.AddEdge("G4", "G3", 2);
			graph.AddEdge("G4", "F4", 2);
			graph.AddEdge("G4", "H4", 2);
			graph.AddVertex("H3");
			graph.AddEdge("H3", "G3", 1);
			graph.AddEdge("H3", "I3", 1);
			graph.AddEdge("H3", "H4", 2);
			graph.AddVertex("H4");
			graph.AddEdge("H4", "H3", 4);
			graph.AddEdge("H4", "G4", 2);
			graph.AddEdge("H4", "I4", 2);
			graph.AddVertex("H6");
			graph.AddEdge("H6", "I6", 2);
			graph.AddVertex("I2");
			graph.AddEdge("I2", "J2", 1);
			graph.AddEdge("I2", "I3", 4);
			graph.AddVertex("I3");
			graph.AddEdge("I3", "I2", 4);
			graph.AddEdge("I3", "H3", 1);
			graph.AddEdge("I3", "I4", 2);
			graph.AddEdge("I3", "J3", 1);
			graph.AddVertex("I4");
			graph.AddEdge("I4", "I3", 4);
			graph.AddEdge("I4", "H4", 2);
			graph.AddEdge("I4", "J4", 2);
			graph.AddVertex("I6");
			graph.AddEdge("I6", "H6", 2);
			graph.AddEdge("I6", "J6", 2);
			graph.AddVertex("J1");
			graph.AddEdge("J1", "J2", 1);
			graph.AddVertex("J2");
			graph.AddEdge("J2", "I2", 4);
			graph.AddEdge("J2", "J1", 1);
			graph.AddEdge("J2", "J3", 1);
			graph.AddVertex("J3");
			graph.AddEdge("J3", "I2", 1);
			graph.AddEdge("J3", "I3", 1);
			graph.AddEdge("J3", "J4", 2);
			graph.AddVertex("J4");
			graph.AddEdge("J4", "I3", 2);
			graph.AddEdge("J4", "I4", 2);
			graph.AddEdge("J4", "J5", 2);
			graph.AddVertex("J5");
			graph.AddEdge("J5", "J4", 2);
			graph.AddEdge("J5", "J6", 2);
			graph.AddVertex("J6");
			graph.AddEdge("J6", "J5", 2);
			graph.AddEdge("J6", "I6", 2);
			vector<Node> result = graph.getGraph();
			for (unsigned int i = 0; i < result.size(); i++) {
				cout << result[i].get_name() << ";Adjacent: ";
				vector<Edge> check = result[i].get_adjacencies();
				for (unsigned int j = 0; j < check.size(); j++)
				{
					if (j == check.size() - 1)
						cout << check[j].get_target() << " (" << check[j].get_cost() << ")";
					else
						cout << check[j].get_target() << " (" << check[j].get_cost() << "),";
				}
				cout << endl;
			}
		}
		else if (option == "PATH")
		{
			string vertex1, vertex2;
			int minimum_cost;
			queue<string> vertexQue;
			cout << "Enter the name of the first vertex: ";
			cin >> vertex1;
			cout << "Enter the name of the second vertex: ";
			cin >> vertex2;
			cout << "The path is: ";
			minimum_cost = graph.Dijkstra(vertex1, vertex2, vertexQue);
			if (minimum_cost != -1)
				cout << "The minimum cost between " + vertex1 + " and " + vertex2 + " is: " + to_string(minimum_cost) << endl;
			else
				cout << "There is no path between " + vertex1 + " and " + vertex2 << endl; 
		}
		else if (option == "QUIT") break;
		// The next two option assume TEST_1 graph has been loaded to be working properly
		else if (option == "TEST_GETWEIGHT")
		{
			cout << "Distance between Austin and Dallas is " << graph.GetWeight("Austin", "Dallas") << endl;
			cout << "Distance between Austin and Denver is " << graph.GetWeight("Austin", "Denver") << endl;
		}
		else if (option == "TEST_GETADJACENT")
		{
			queue<string> adjacencies;
			if (graph.GetAdjacent("Austin", adjacencies))
			{
				cout << "The adjacent list of Austin is:";
				string next;
				while (!adjacencies.empty())
				{
					cout << " ";
					next = adjacencies.front();
					adjacencies.pop();
					cout << next;
				}
				cout << endl;
			}
			else {
				cout << "Austin is not in the graph\n";
			}
		}
		else
			cout << "No option is found!!!";
		cout << "--------------------------------" << endl;
	}


}
