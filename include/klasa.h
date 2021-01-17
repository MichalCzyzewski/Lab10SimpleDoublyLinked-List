#include <iostream>
#include <string.h>
using namespace std;
class baza {

private:
    struct czlowiek {
        string imie;
        string nazwisko;
        string telefon;
        czlowiek *nastepny;
        czlowiek *poprzedni;
    };

    czlowiek *glowa, *ogon;
    int rozmiar;

public:
    czlowiek *pozycja=NULL;

    void nowaOsoba();
    void dodajOsobeOdKonca(string imie,string nazwisko,string telefon);
    void wyswietl();
    void kasuj(int nr);
    baza();
    baza(class baza *czlowiek);
    ~baza();

};
void menu();
