
#include "Trasa.h"
#include <string.h>
#include <sstream>



void Trasa::dodajTrase() {
	std::string poczatek;
	std::string koniec;
	std::vector<std::string> przystanki;
	int odleglosc;

	std::cout << std::endl << "Dodawanie nowej trasy: " << std::endl << std::endl;

	std::cout << std::endl << "Podaj nazwe poczatkowego przystanku ";
	std::cin >> poczatek;
	

	std::cout << std::endl << "Podaj nazwe koncowego przystanku ";
	std::cin >> koniec;

	std::cout << std::endl << "Podaj dlugosc trasy ";
	std::cin >> odleglosc;

	/*std::cout << std::endl << "Podaj kolejne przystanki, oddzielajac je spacja " << std::endl;
	

	std::string buf,temp;

	getline(std::cin, buf);
	std::stringstream ss(buf);

	while (getline(ss,temp,' '))
	{
		przystanki.push_back(temp);
	}*/

	//while(getline(std::cin,buf,' ')){
	//	przystanki.push_back(buf);
	//}


	/*while (1)
	{
		std::cin >> buf;
		if (buf == "\n\t\n\t")
			break;
		else
		{
			przystanki.push_back(buf);
		}
		std::cout << std::endl<<"> ";
	}*/

	trasy.push_back(new baseTrasa(poczatek, koniec, odleglosc));
}

void Trasa::dodajTrase(std::string poczatek, std::string koniec, int odleglosc)
{
	trasy.push_back(new baseTrasa(poczatek, koniec, odleglosc));
}


void Trasa::wypiszTrasy() {

	std::cout << std::endl << "------ Lista tras ------" << std::endl;
	for (int i = 0; i < (int)trasy.size(); i++)
	{
		std::cout << std::endl << i << ". Poczatek:" << trasy.at(i)->poczatek
			<< " \t Koniec: " << trasy.at(i)->koniec
			<< " \t Dlugosc: " << trasy.at(i)->odleglosc;
		
		/*std::cout << std::endl << "--------- Przystanki w kolejnosci >>>" << std::endl;
		for (auto x : trasy.at(i)->przystanki) {
			std::cout <<"\t > "<< x<<std::endl;
		}
		*/
	}

}

void Trasa::usunTrase() {
	int nr;
	std::cout << std::endl << "Podaj numer trasy do usniecia" << std::endl;

	wypiszTrasy();

	std::cout << std::endl << "Podaj numer kierowcy do usniecia" << std::endl;
	std::cin >> nr;

	if (nr > (int)trasy.size()) {
		std::cout << std::endl << "Cos poszlo nie tak, spróbuj jeszcze raz ";
		usunTrase();
	}
	else
	{
		//trasy.at(nr)->przystanki.clear();
		trasy.erase(trasy.begin() + nr);
	}
}

