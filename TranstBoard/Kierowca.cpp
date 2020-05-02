
#include "Kierowca.h"
#include <string.h>

void Kierowca::dodajKierowce() {
	std::string imie;
	std::string nazwisko;
	int wiek;

	std::cout << std::endl << "Dodawanie kierowcy: " << std::endl << std::endl;

	std::cout << std::endl << "Podaj imie kierowcy ";
	std::cin >> imie;
	std::cout << std::endl << "Podaj nazwisko kierowcy ";
	std::cin >> nazwisko;

	std::cout << std::endl << "Podaj wiek kierowcy ";
	std::cin >> wiek;

	//baseKierowca* temp = new baseKierowca(imie, nazwisko, wiek);

	kierowcy.push_back(new baseKierowca(imie, nazwisko, wiek));
}

void Kierowca::dodajKierowce(std::string imie, std::string nazwisko, int wiek)
{
	kierowcy.push_back(new baseKierowca(imie, nazwisko, wiek));
}

void Kierowca::wypiszKierowcow() {
	std::cout << std::endl << "------ Lista kierowcow ------"<<std::endl;
	for(int i= 0; i<(int)kierowcy.size();i++)
	{
		std::cout << std::endl << i << ". " << kierowcy.at(i)->imie 
			<< " \t" << kierowcy.at(i)->nazwisko << " \tw: " 
			<< kierowcy.at(i)->wiek << "\t Status: " 
			<< kierowcy.at(i)->zajety;
	}

}

void Kierowca::usunKierowce() {
	int nr;
	std::cout << std::endl << "Podaj numer kierowcy do usniecia" << std::endl;

	wypiszKierowcow();

	std::cout << std::endl << "Podaj numer kierowcy do usniecia" << std::endl;
	std::cin >> nr;

	if (nr > (int)kierowcy.size()) {
		std::cout << std::endl << "Cos poszlo nie tak, spróbuj jeszcze raz ";
		usunKierowce();
	}
	else 
	{

	kierowcy.erase(kierowcy.begin() + nr);
	}

		
}