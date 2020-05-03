#pragma once
#include <iostream>
#include <string.h>
class Zadanie;
//class MenZadan;
#include "Zadanie.h"

class MenZadan
{
public:
	std::string stanZadania = "pending";
	Zadanie* zad;


	void setObject(Zadanie* zad);
	void updateObeserver();
	







};

