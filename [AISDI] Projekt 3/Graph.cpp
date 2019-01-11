#include "pch.h"
#include "Graph.h"
#include <algorithm>
#include <iostream>


void Graph::DFS(int v)
{
	visited[v] = true;

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

Graph::Graph()
{
	vertex = 0;
}


Graph::~Graph()
{
}


void Graph::add(int a, int b)
{
	list[a].push_back(b);
	list[b].push_back(a);

	vertex = std::max(vertex, a + 1);
	vertex = std::max(vertex, b + 1);
}


int Graph::findBridges()
{
	int check;

	for (int i = 0; i < vertex; i++)
	{
		for (auto it = list[i].begin(); it != list[i].end(); it++)
		{
			if (*it < i) continue;

			visited[i] = visited[*it] = true;
			check = 0;

			for (int j = 0; j < vertex; j++)
			{
				if (!visited[j])
				{
					if (++check > 1)
					{
						bridges.push_back(std::make_pair(i, *it));
						break;
					}

					DFS(j);
				}

			}
			resetVisited();
		}
	}
	return 0;
}

void Graph::printBridges()
{
	for (auto it = bridges.begin(); it != bridges.end(); it++)
	{
		std::pair<int, int> p = *it;
		std::cout << p.first << " " << p.second << std::endl;
	}
}