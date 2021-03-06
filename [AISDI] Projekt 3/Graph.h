#pragma once
#include <vector>
#define MX 10000

class Graph
{
	int vertex;
	std::vector <int> list[MX];
	bool visited[MX];
	std::vector <std::pair<int, int>> bridges;
	int check;

	void DFS(int);
	void resetVisited();
public:
	Graph(int);
	~Graph();
	void add(int, int);
	int findBridges();
	//void printBridges();

	std::vector <std::pair<int, int>>* returnBridges();
};

