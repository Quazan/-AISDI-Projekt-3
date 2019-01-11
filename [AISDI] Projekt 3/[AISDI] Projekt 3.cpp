

#include "pch.h"
#include <iostream>
#include "Graph.h"

int main()
{

	int v, e;
	int a, b;

	std::cout << "Podaj liczbe wierzcholkow w grafie." << std::endl;
    std::cin >> v;
	Graph graf = Graph(v);

	std::cout << "W kolejnych liniach podaj definicje krawedzi w grafie. Dwie liczby oddzielone spacja. Wcisnij ctrl+d aby zakonczyc wprowadzanie krawedzi." << std::endl;
	while (true)
	{
		std::cin >> a >> b;
		if (std::cin.eof()) break;
		graf.add(a, b);
	}
	
	graf.findBridges();

	std::vector <std::pair<int, int>> *bridge = graf.returnBridges();

	for (auto it = bridge->begin(); it != bridge->end(); it++)
	{
		auto p = *it;
		std::cout << p.first << " " << p.second << std::endl;
	}
}
