#include "Interfejs.h"

Interfejs* Interfejs::instance = 0;
 
Interfejs* Interfejs::getInstance() {
	if (instance == 0) {
		instance = new Interfejs;
	}
	return instance;
}

Interfejs::Interfejs() {

}


void Interfejs::zapelnijZasoby()
{	
	ListaKierowcow->dodajKierowce("Jan", "Nowak", 13);
	ListaKierowcow->dodajKierowce("Janusz", "Tracz", 121);
	ListaKierowcow->dodajKierowce("Grzegorz", "Gracz", 131);

	ListaAutobusow->dodajAutobus("Solaris", "ABC", "KR12345", "Elektryczny", 32);
	ListaAutobusow->dodajAutobus("Mercedes", "ABC", "ABCDEFG", "Diesel", 31);
	ListaAutobusow->dodajAutobus("Jelcz", "ABC", "QWERTYU", "Diesel", 51);

	ListaTras->dodajTrase("Krakow", "Gdansk", 40);
	ListaTras->dodajTrase("Warszawa", "Lublin", 30);
	ListaTras->dodajTrase("Szczecin", "Wroclaw", 14);

	std::cout << std::endl << "Dodano przykladowe zasoby do poszczegolnych list zasobow [3]" << std::endl;
}

void Interfejs::zapelnijZadania()
{
	listaZadan.push_back((new Zadanie)->noweZadanie(ListaTras->trasy.at(0), ListaKierowcow->kierowcy.at(0), ListaAutobusow->autobusy.at(0)));
	listaZadan.push_back((new Zadanie)->noweZadanie(ListaTras->trasy.at(1), ListaKierowcow->kierowcy.at(1), ListaAutobusow->autobusy.at(1)));
	listaZadan.push_back((new Zadanie)->noweZadanie(ListaTras->trasy.at(2), ListaKierowcow->kierowcy.at(2), ListaAutobusow->autobusy.at(2)));

	for (auto x : listaZadan) {
		Obserwator* temp = new Obserwator;
		listaMngr.push_back(temp);
		temp->setObject(x);
		x->attachMngr(temp);
	}


	std::cout << std::endl << "Dodano przykladowe zadania do listy zadan"<<std::endl;
}

void Interfejs::dodajAutobus()
{
	ListaAutobusow->dodajAutobus();
}

void Interfejs::dodajKierowce()
{
	ListaKierowcow->dodajKierowce();
}

void Interfejs::dodajTrase()
{
	ListaTras->dodajTrase();
}

void Interfejs::dodajZadanie()
{
	int a, b, c;
	std::cout << std::endl << "Dodawanie zadania" << std::endl;

	wyswietlDostepneZasoby("kierowcy");
	std::cout << "Podaj numer kierowcy dla nowego zadania: ";
	std::cin >> a;

	wyswietlDostepneZasoby("autobusy");
	std::cout << "Podaj numer autobusu dla nowego zadania: ";
	std::cin >> b;

	wyswietlDostepneTrasy();
	std::cout << "Podaj numer trasy dla nowego zadania: ";
	std::cin >> c;

	listaZadan.push_back((new Zadanie)->noweZadanie(
		ListaTras->trasy.at(c),
		ListaKierowcow->kierowcy.at(a),
		ListaAutobusow->autobusy.at(b)
	));

	listaMngr.push_back(new Obserwator);
	listaMngr.at(listaMngr.size())->setObject(listaZadan.at(listaZadan.size()));
	listaZadan.at(listaZadan.size())->attachMngr(listaMngr.at(listaMngr.size()));



}

void Interfejs::wyswietlDostepneZasoby(std::string opcja)
{
	char x = opcja[0];
	switch (x)
	{
	case 'k':
		ListaKierowcow->wypiszKierowcow();
		break;
	case 'a':
		ListaAutobusow->wypiszAutobusy();
		break;
	default:
		std::cout << std::endl << "Podany zosta³ niepoprawny parametr";
		break;
	}
}

void Interfejs::wyswietlDostepneTrasy()
{
	ListaTras->wypiszTrasy();
}

void Interfejs::generujMenu()
{
	system("cls");
	std::cout << std::endl << "----------- MENU -----------" << std::endl;

	std::cout << " 1. \t  Uzupelnij dane o przykladowe dane (3 wiersze)" << std::endl;
	std::cout << " 2. \t  Uzupelnij liste zadan o przykladowe zadania (3 wiersze)" << std::endl;
	std::cout << " 3. \t  Dodaj nowy autobus" << std::endl;
	std::cout << " 4. \t  Dodaj nowego kierowce" << std::endl;
	std::cout << " 5. \t  Dodaj nowa trase" << std::endl;
	std::cout << " 6. \t  Dodaj nowe Zadanie" << std::endl;
	std::cout << " 7. \t  Wyswietl dostepne autobusy" << std::endl;
	std::cout << " 8. \t  Wyswietl dostepnych kierowcow" << std::endl;
	std::cout << " 9. \t  Uruchom zadania" << std::endl;
	std::cout << std::endl << ">";
	int opcja;
	std::cin >> opcja;
	opcjaMenu(opcja);






}

void Interfejs::opcjaMenu(int opcja)
{
	switch (opcja)
	{
	case 1:
		zapelnijZasoby();
		break;
	case 2:
		zapelnijZadania();
		break;
	case 3:
		dodajAutobus();
		break;
	case 4:
		dodajKierowce();
		break;
	case 5:
		dodajTrase();
		break;
	case 6:
		dodajZadanie();
		break;
	case 7:
		wyswietlDostepneZasoby("autobusy");
		break;
	case 8:
		wyswietlDostepneZasoby("kierowcy");
		break;
	case 9:
		uruchomZadania();
		break;
	default:
		std::cout << std::endl << "Cos poszlo nie tak";

		break;
	}
	system("pause");
	generujMenu();
}

void Interfejs::uruchomZadania()
{
	int* done;
	done = new int[(int)listaZadan.size()];
	int count;
	for (int i = 0; i < (int)listaZadan.size(); i++) {
		done[i] = 0;
	}


	system("pause");
	while (1)
	{
		count = (int)listaZadan.size();
		system("cls");

		for (int i = 0; i < (int)listaZadan.size(); i++) {
			std::cout << std::endl << "Zadanie nr " << i + 1 << ". ";
			listaZadan.at(i)->sprawdzPostep();
			listaZadan.at(i)->timerZadania();
			if (listaZadan.at(i)->koniec == true) {
				done[i] = 1;
			}
			
			
		}
		for (int i = 0; i < (int)listaZadan.size(); i++) {
			if (done[i] == 1) {
				count--;
			}
			
				
		}
		if (count == 0)
			break;

		//Sleep(500);
		system("pause");
	}

	generujMenu();
}
