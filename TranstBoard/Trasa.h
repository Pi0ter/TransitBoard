#pragma once
#include <string>
#include <vector>
#include <iostream>

struct baseTrasa
{
	std::string poczatek;
	std::string koniec;
	//std::vector<std::string> przystanki;
	int odleglosc;

	baseTrasa(std::string poczatek, std::string koniec, int odleglosc) {
		this->poczatek = poczatek;
		this->koniec = koniec;
		//this->przystanki = przystanki;
		this->odleglosc = odleglosc;
	}

};

class Trasa
{
public:
	std::vector<baseTrasa*> trasy;

	virtual void dodajTrase();
	virtual void dodajTrase(std::string poczatek, std::string koniec, int odleglosc);
	virtual void usunTrase();
	virtual void wypiszTrasy();




};

