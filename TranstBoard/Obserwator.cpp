#include "Obserwator.h"
#include <Windows.h>

void Obserwator::setObject(Zadanie * zad)
{
	this->zad = zad;
}

void Obserwator::unsetObject()
{
	delete this->zad;
}

void Obserwator::updateObeserver()
{
	stanZadania = "Ukonczone";
	std::cout << std::endl << "Zadanie zostalo wykonane, kierowca: " <<
		zad->kierowca->imie << " " << zad->kierowca->nazwisko <<
		" Rejestracja autobusu: " << zad->autobus->rejestracja;

}
