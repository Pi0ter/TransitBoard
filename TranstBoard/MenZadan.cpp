#include "MenZadan.h"

void MenZadan::setObject(Zadanie * zad)
{
	this->zad = zad;
}

void MenZadan::updateObeserver()
{
	stanZadania = "Ukonczone";
	std::cout << std::endl << "Zadanie zostalo wykonane, kierowca " <<
		zad->kierowca->imie << " " << zad->kierowca->nazwisko <<
		" Rejestracja autobusu: " << zad->autobus->rejestracja;




}
