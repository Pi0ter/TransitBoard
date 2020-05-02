#pragma once
#include <string>
#include <vector>
#include <iostream>



struct baseAutobus
{
	std::string marka;
	std::string model;
	std::string rejestracja;
	std::string naped;
	int pojemnosc;
	bool stan;

	baseAutobus(std::string marka, std::string model, std::string rejestracja, std::string naped, int pojemnosc, bool stan = false) {
		this->marka = marka;
		this->model = model;
		this->rejestracja = rejestracja;
		this->naped = naped;
		this->pojemnosc = pojemnosc;
		this->stan = stan;
	}

};
class Autobus
{

public:


	std::vector<baseAutobus*> autobusy;


	virtual	void dodajAutobus();
	virtual	void dodajAutobus(std::string marka, std::string model, std::string rejestracja, std::string naped, int pojemnosc);
	virtual	void usunAutobus();
	virtual	void wypiszAutobusy();









};

