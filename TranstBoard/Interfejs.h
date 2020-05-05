#pragma once

#include "Kierowca.h"
#include "Trasa.h"
#include "Autobus.h"
#include "Zadanie.h"
#include <Windows.h>
#include <iostream>

class Interfejs
{
private:
	static Interfejs* instance;
	Interfejs();


public:
	static Interfejs* getInstance();

	std::vector<Obserwator*> listaMngr;
	std::vector<Zadanie*> listaZadan;

	Kierowca* ListaKierowcow = new Kierowca;
	Autobus* ListaAutobusow = new Autobus;
	Trasa* ListaTras = new Trasa;

	//dev tools
	void zapelnijZasoby();
	void zapelnijZadania();
	//dev tools


	void dodajAutobus();
	void dodajKierowce();
	void dodajTrase();
	void dodajZadanie();
	

	void wyswietlDostepneZasoby(std::string opcja); //kierowcy lub  autobusy
	void wyswietlDostepneTrasy();

	void generujMenu();

	void opcjaMenu(int opcja);

	void uruchomZadania();
};

