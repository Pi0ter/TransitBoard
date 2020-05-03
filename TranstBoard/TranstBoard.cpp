// TranstBoard.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "Kierowca.h"
#include "Trasa.h"
#include "Autobus.h"
#include "Zadanie.h"
#include <Windows.h>




int main()
{
    std::vector<MenZadan*> listaMngr;
    std::vector<Zadanie*> listaZadan;

    Zadanie* pierwsze = new Zadanie;
    Zadanie* drugie = new Zadanie;
    listaZadan.push_back(pierwsze);
    listaZadan.push_back(drugie);

    Trasa* trasy = new Trasa();
    trasy->dodajTrase("Krakow", "Gdansk", 40);
    trasy->dodajTrase("Warszawa", "Gdansk", 30);
    trasy->dodajTrase("Szczecin", "Gdansk", 14);

    Autobus* autobusy = new Autobus();
    autobusy->dodajAutobus("Solaris", "ABC", "KR12345", "Elektryczny", 32);
    autobusy->dodajAutobus("Mercedes", "ABC", "ABCDEFG", "Diesel", 31);
    autobusy->dodajAutobus("Jelcz", "ABC", "QWERTYU", "Diesel", 51);

    Kierowca* kierowcy = new Kierowca();
    kierowcy->dodajKierowce("Jan", "Nowak", 13);
    kierowcy->dodajKierowce("Janusz", "Tracz", 121);
    kierowcy->dodajKierowce("Janusz", "Gracz", 131);

    listaZadan.at(0)->noweZadanie(trasy->trasy.at(0), kierowcy->kierowcy.at(0), autobusy->autobusy.at(0));
    listaZadan.at(1)->noweZadanie(trasy->trasy.at(1), kierowcy->kierowcy.at(1), autobusy->autobusy.at(1));
    listaZadan.push_back((new Zadanie)->noweZadanie(trasy->trasy.at(2), kierowcy->kierowcy.at(2), autobusy->autobusy.at(2)));

    /*MenZadan* mngr= new MenZadan;*/


    for (auto x : listaZadan) {
        MenZadan* temp = new MenZadan;
        listaMngr.push_back(temp);
        temp->setObject(x);
        x->attachMngr(temp);
    }



    system("pause");
    while (1)
    {
       
        system("cls");
        
        for (int i = 0; i < (int)listaZadan.size(); i++) {
            std::cout << std::endl << "Zadanie nr " << i+1 << ". ";
            listaZadan.at(i)->sprawdzPostep();
            listaZadan.at(i)->timerZadania();
        }


        Sleep(500);
    }








   /* Trasa* test = new Trasa();
    test->dodajTrase();
    test->wypiszTrasy();
    test->usunTrase();*/
    
    /*Kierowca * xd = new Kierowca();

    xd->dodajKierowce();
  



    xd->wypiszKierowcow();
    
    xd->usunKierowce();


    xd->wypiszKierowcow();*/

    
   

}






// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
