// Lab3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Polynominal.h"
#include <vector>
#include <sstream>

int main()
{
    vov elements = { {2,1},{1,2},{0,3} };
    vov elements2 = { {3,1},{1,2},{0,1} };
    vov elements3 = { {1,1},{0,1} };
    vov elements4 = { {1,1},{0,-1} };
    float num = 3.0;
    Polynominal poly(elements);
    Polynominal poly2(elements2);
    Polynominal poly3(elements3);
    Polynominal poly4(elements4);
    std::cout << "dupa" << std::endl;
    std::cout << poly.get_element(2) << std::endl;
    std::cout << poly << std::endl;
    std::cout << poly2 << std::endl;
    std::cout << poly2 + poly << std::endl;
    std::cout << poly2 - poly << std::endl;
    std::cout << poly+num << std::endl;
    std::cout << poly-num << std::endl;
    std::cout << poly*num << std::endl;
    std::cout << poly/num << std::endl;
    std::cout << poly << std::endl;
    poly -= 3;
    std::cout << "HERE " << poly << std::endl;
    std::cout << poly3 * poly4 << std::endl;
    num = poly3 << 1;
    std::cout << num << std::endl;
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
