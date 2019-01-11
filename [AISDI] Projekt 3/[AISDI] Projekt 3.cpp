// [AISDI] Projekt 3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Graph.h"

int main()
{
	Graph graf;

	int v, e;
	int a, b;

	/*std::cin >> e;
	for (int i = 0; i < e; i++)
	{
		std::cin >> a >> b;
		graf.add(a, b);
	}*/
	std::cout << "Podaj liczbe wierzcholkow w grafie." << std::endl;
	//std::cin >> v;
	std::cout << "W kolejnych liniach podaj definicje krawedzi w grafie. Dwie liczby oddzielone spacja. Wcisnij ctrl+d aby zakonczyc wprowadzanie krawedzi." << std::endl;
	/*while (true)
	{
		std::cin >> a >> b;
		if (std::cin.eof()) break;
		graf.add(a, b);
	}*/

	for (int i = 0; i < 100; i++)
	{
		for (int j = i + 1; j < 100; j++)
		{
			graf.add(i, j);
		}
	}

	graf.findBridges();
	std::cout << "Bridges: " << std::endl;
	std::vector <std::pair<int, int>> *bridge = graf.returnBridges();

	if (bridge->begin() == bridge->end())
	{
		std::cout << "NONE" << std::endl;
	}

	for (auto it = bridge->begin(); it != bridge->end(); it++)
	{
		auto p = *it;
		std::cout << p.first << " " << p.second << std::endl;
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
