#include "pch.h"
#include "Graph.h"
#include <algorithm>
#include <iostream>


void Graph::DFS(int v)
{
	visited[v] = true;
	check++;

	for (auto it = list[v].begin(); it != list[v].end(); it++)
	{
		if (!visited[*it])
		{
			DFS(*it);
		}
	}
}

void Graph::resetVisited()
{
	for (int i = 0; i < vertex; i++)
	{
		visited[i] = false;
	}
}

Graph::Graph(int v)
{
	vertex = v;
}


Graph::~Graph()
{
}


void Graph::add(int a, int b)
{
	list[a].push_back(b);
	list[b].push_back(a);
}


int Graph::findBridges()
{

	for (int i = 0; i < vertex; i++)
	{
		for (auto it = list[i].begin(); it != list[i].end(); it++)
		{
			if (*it < i) continue;
			if (list[i].size() == 1 || list[*it].size() == 1) continue;
			visited[i] = visited[*it] = true;
			check = 2;

			for (int j = 0; j < vertex; j++)
			{
				if (!visited[j])
				{
					DFS(j);

					if (check != vertex)
					{
						bridges.push_back(std::make_pair(i, *it));
						break;
					}
				}
			}
			resetVisited();
		}
	}
	return 0;
}

/*void Graph::printBridges()
{
	for (auto it = bridges.begin(); it != bridges.end(); it++)
	{
		std::pair<int, int> p = *it;
		std::cout << p.first << " " << p.second << std::endl;
	}
}*/

std::vector<std::pair<int, int>>* Graph::returnBridges()
{
	return &bridges;
}
