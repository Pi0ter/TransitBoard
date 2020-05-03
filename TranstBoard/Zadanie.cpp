#include "Zadanie.h"
#include "Autobus.h"
#include "Kierowca.h"
#include "Trasa.h"

Zadanie *  Zadanie::noweZadanie(baseTrasa* trasa, baseKierowca* kierowca, baseAutobus* autobus)
{	
	if (kierowca->zajety || autobus->stan) {
		std::cout << std::endl << "Autobus lub kierowca jest zajety "<<std::endl;
		return nullptr;
	}
	koniec = false;
	


	this->trasa = trasa;
	this->kierowca = kierowca;
	this->autobus = autobus;
	meta = trasa->odleglosc;
	postep = 0;
	autobus->stan = true;
	kierowca->zajety = true;

	std::cout << std::endl << "Pomyslnie dodano zadanie: " << std::endl;
	std::cout << "Trasa z: "<<trasa->poczatek<<" do: "<< trasa->koniec<<" \tkierowca: \t"<<kierowca->imie <<" " <<kierowca->nazwisko<<" \t rejestracja autobusu \t"<< autobus->rejestracja << std::endl;

	return this;
}


void Zadanie::sprawdzPostep()
{
	std::cout <<trasa->poczatek<<" do "<<trasa->koniec <<" ("<<autobus->rejestracja<<") \t Odleglosc: "<<meta<< "\t[";
	float stepSize = (float)scale / (float)meta; 

	krok = (float)postep * (float)stepSize;


	int krokDruk = (int)krok;
	for (int i = 0; i < krokDruk; i++) {
		std::cout << "-";
	}
	int reszta = scale - krokDruk;

	for (int i = 0; i < reszta; i++) {
		std::cout << " ";
	}

	std::cout << "]";


}

void Zadanie::timerZadania()
{
	if (postep < meta) {
		postep++;
		//notify obserwer
	}
	else 
	{
		//sprawdzPostep();
		std::cout << " < Zakonczony kurs";
		autobus->stan = false;
		kierowca->zajety = false;
		koniec = true;

		//system("pause");
		//system("pause");
	}
	
}
