#pragma once
#include <string>
#include <vector>
#include <iostream>

struct baseKierowca
{
	std::string imie;
	std::string nazwisko;
	int wiek;
	bool zajety;

	baseKierowca(std::string imie, std::string nazwisko, int wiek, bool zajety = false) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->wiek = wiek;
		this->zajety = zajety;
	}

};

class Kierowca
{
public:
	std::vector<baseKierowca*> kierowcy;


	virtual void dodajKierowce();
	virtual void dodajKierowce(std::string imie, std::string nazwisko, int wiek);
	virtual void usunKierowce();
	virtual void wypiszKierowcow();
	
};

