#include "Obserwator.h"

void Obserwator::setObject(Zadanie * zad)
{
	this->zad = zad;
}

void Obserwator::updateObeserver()
{
	stanZadania = "Ukonczone";
	std::cout << std::endl << "Zadanie zostalo wykonane, kierowca: " <<
		zad->kierowca->imie << " " << zad->kierowca->nazwisko <<
		" Rejestracja autobusu: " << zad->autobus->rejestracja;

}