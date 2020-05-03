#pragma once
#include "Kierowca.h"
#include "Trasa.h"
#include "Autobus.h"
#include "iostream"

class Zadanie
{
public:
	int meta;
	int postep;
	float krok;
	bool koniec;
	int scale = 30;

	baseTrasa* trasa;
	baseKierowca* kierowca;
	baseAutobus* autobus;

	Zadanie * noweZadanie(baseTrasa *  trasa, baseKierowca* kierowca, baseAutobus* autobus);
	//Zadanie * noweZadanie(baseTrasa *  trasa);
	void sprawdzPostep();
	void timerZadania();

};

