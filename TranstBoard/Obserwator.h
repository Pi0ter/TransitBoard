#pragma once
#include <iostream>
#include <string.h>
class Zadanie;
#include "Zadanie.h"

class Obserwator
{
public:
	std::string stanZadania = "pending";
	Zadanie* zad;


	void setObject(Zadanie* zad);
	void unsetObject();
	void updateObeserver();
	

};

