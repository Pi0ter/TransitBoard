#include "Interfejs.h"

int main()
{
    Interfejs* intefejs = Interfejs::getInstance();

    intefejs->generujMenu();


}
/*
Użyte Wzorce:

Klasa   -   Wzorzec

Obserwer    <-  Observer

Interfejs   <-  Singleton
            <-  Mediator
            <-  Iterator

Zadanie     <- Builder


Instrukcja Uruchomienia:

Wymagania:
 - Visual Studio 2019 (Możliwe że działa na poprzednich)
 - Kompilator Cpp

Uruchomienie:

1. Kompilacja klas
2. Uruchomienie programu
*/

