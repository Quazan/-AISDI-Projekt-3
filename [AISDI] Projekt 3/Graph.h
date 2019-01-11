#pragma once
#include <vector>
#define MX 10000

class Graph
{
	int vertex;
	std::vector <int> list[MX];
	bool visited[MX];
	std::vector <std::pair<int, int>> bridges;

	void DFS(int);
	void resetVisited();
public:
	Graph();
	~Graph();
	void add(int, int);
	int findBridges();
	//void printBridges();

	std::vector <std::pair<int, int>>* returnBridges();
};

