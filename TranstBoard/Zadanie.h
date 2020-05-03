#pragma once
#include "Kierowca.h"
#include "Trasa.h"
#include "Autobus.h"

class Obserwator;
#include "Obserwator.h"
#include <iostream>

class Zadanie
{
public:
	int meta;
	int postep;
	float krok;
	bool koniec;
	int scale = 30;

	Obserwator *mngr;
	baseTrasa* trasa;
	baseKierowca* kierowca;
	baseAutobus* autobus;

	Zadanie * noweZadanie(baseTrasa *  trasa, baseKierowca* kierowca, baseAutobus* autobus);
	//Zadanie * noweZadanie(baseTrasa *  trasa);
	void sprawdzPostep();
	void timerZadania();

	void notify();
	void attachMngr(Obserwator* mngr);
	void detachMngr(Obserwator* mngr);
	


};

