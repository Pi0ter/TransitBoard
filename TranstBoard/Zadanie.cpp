#include "Zadanie.h"
#include "Autobus.h"
#include "Kierowca.h"
#include "Trasa.h"

Zadanie *  Zadanie::noweZadanie(baseTrasa* trasa, baseKierowca* kierowca, baseAutobus* autobus)
{	
	if (kierowca->zajety || autobus->stan) {
		std::cout << std::endl << "Autobus lub kierowca jest zajety";
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
	std::cout << "Trasa od: "<<trasa->poczatek<<" do: "<< trasa->koniec<<"kierowca:  "<<kierowca->imie <<" " <<kierowca->nazwisko<<" rejestracja autobusu"<< autobus->rejestracja << std::endl;

	return this;
}


void Zadanie::sprawdzPostep()
{
	int scale = 30;
	std::cout <<trasa->poczatek<<" do "<<trasa->koniec <<" ("<<autobus->rejestracja<<") \t[";
	float stepSize = meta / scale;
	int x = floor(postep / stepSize);
	for (int i = 0; i < x; i++) {
		std::cout << "-";
		scale--;
	}
	for (int i = 0; i < scale; i++) {
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
		std::cout << " < Zakonczony kurs" << std::endl;
		autobus->stan = false;
		kierowca->zajety = false;
		koniec = true;

		//system("pause");
		//system("pause");
	}
	
}
