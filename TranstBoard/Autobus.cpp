
#include "Autobus.h"
#include <string.h>


void Autobus::dodajAutobus(){

	std::string marka;
	std::string model;
	std::string rejestracja;
	std::string naped;
	int pojemnosc;

	std::cout << std::endl << "Dodawanie autobusu: " << std::endl << std::endl;

	std::cout << std::endl << "Podaj marke autobusu ";
	std::cin >> marka;

	std::cout << std::endl << "Podaj model autobusu ";
	std::cin >> model;

	std::cout << std::endl << "Podaj rejestracja autobusu ";
	std::cin >> rejestracja;

	std::cout << std::endl << "Podaj naped autobusu ";
	std::cin >> naped;

	std::cout << std::endl << "Podaj pojemnosc autobusu ";
	std::cin >> pojemnosc;

	autobusy.push_back(new baseAutobus(marka, model, rejestracja, naped, pojemnosc));

}

void Autobus::dodajAutobus(std::string marka, std::string model, std::string rejestracja, std::string naped, int pojemnosc)
{
	autobusy.push_back(new baseAutobus(marka, model, rejestracja, naped, pojemnosc));
}


void Autobus::wypiszAutobusy() {
	std::cout << std::endl << "------ Lista autobusow ------" << std::endl;
	for (int i = 0; i < (int)autobusy.size(); i++)
	{
		std::cout << std::endl << i << ". Marka:" << autobusy.at(i)->marka 
			<< " \t Model: " << autobusy.at(i)->model << " \tNaped: " 
			<< autobusy.at(i)->naped << "\t pojemnosc: " 
			<< autobusy.at(i)->pojemnosc << "\t rejestracja: " 
			<< autobusy.at(i)->rejestracja<< "\t stan: "
			<< autobusy.at(i)->stan;
	}

}

void Autobus::usunAutobus() {
	int nr;
	std::cout << std::endl << "Podaj numer autobusu do usniecia " << std::endl;

	wypiszAutobusy();

	std::cout << std::endl << "Podaj numer autobusu do usniecia " << std::endl;
	std::cin >> nr;

	if (nr > (int)autobusy.size()) {
		std::cout << std::endl << "Cos poszlo nie tak, spróbuj jeszcze raz ";
		usunAutobus();
	}
	else 
	{

	autobusy.erase(autobusy.begin() + nr);
	}

		
}