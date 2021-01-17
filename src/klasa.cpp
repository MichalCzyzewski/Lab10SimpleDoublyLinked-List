#include "klasa.h"

baza *lista=NULL;

void menu() {
    int i;
    lista=new baza();


    int point=0;
    do {
        cout << "\nMenu:\n";
        cout << "  1. Wprowadz osobe do listy\n";
        cout << "  2. Wyswietl Liste osob\n";
        cout << "  3. Usun osobe z listy\n";
        cout << "  4. Koniec\n";
        cout << "Wybieram pozycje nr : ";
        cin >> point;
        cout << endl;

        switch(point) {
        case 1:
            lista->nowaOsoba();
            break;
        case 2:
            lista->wyswietl();
            break;
        case 3:
            cout<<"Ktora pozycje z listy chcesz usunac (podaj nr) : ";
            cin>>i;
            lista->kasuj(i);
            break;
        case 4:
            lista->~baza();
            break;
        default:
            cout << "Podales nieprawidlowa opcje." << endl;
        }
    } while (point!=4);
};

void baza::nowaOsoba() {
    string i,n,t;

    cout<<"Podaj Imie : ";
    cin>>i;
    cout<<"Podaj Nazwisko : ";
    cin>>n;
    cout<<"Podaj Telefon : ";
    cin>>t;
    dodajOsobeOdKonca(i,n,t);
}

void baza::dodajOsobeOdKonca(string imie,string nazwisko,string telefon) {

    czlowiek *temp=new czlowiek{imie,nazwisko,telefon,NULL,NULL};
    if(rozmiar==0) {
        glowa=temp;
        ogon=temp;
        pozycja=temp;
        temp->nastepny=ogon;
    } else {
        pozycja=ogon;
        ogon->nastepny=temp;
        temp->poprzedni=ogon;
        ogon=temp;
    }
    cout<<"Dodano nowa pozycje :\n";
    cout<<"\t"<<temp->imie<<" "<<temp->nazwisko<<" "<<temp->telefon<<endl;
    rozmiar++;
}

void baza::wyswietl() {

    pozycja=glowa;
    for(int i = 0; i< rozmiar; i++) {
        cout<<"nr."<<i+1<<"\t";
        cout<<"\tImie: "<<pozycja->imie<<"\t";
        cout<<"\tNazw:"<<pozycja->nazwisko <<"\t";
        cout<<"\tTelefon:"<<pozycja->telefon<<"\n";
        pozycja=pozycja->nastepny;
    };
    if(rozmiar==0){
        cout<<"Lista jest pusta!!!. Dodaj osoby";
    }
    cout<<endl;
};

void baza::kasuj(int nr) {
    czlowiek *temp=glowa;
    for(int i=1; i<nr; i++) {
        temp=temp->nastepny;
    }
    if(nr==1) {
        glowa=glowa->nastepny;
        glowa->poprzedni=NULL;
    } else if(nr==rozmiar) {
        ogon=ogon->poprzedni;
        ogon->nastepny=NULL;
    } else {
        temp->poprzedni->nastepny=temp->nastepny;
        temp->nastepny->poprzedni=temp->poprzedni;
    }
    cout<<"Usuwam: "<<temp->imie<<" "<<temp->nazwisko<<" "<<temp->telefon<<endl;
    cout<<"\n";
    rozmiar--;
};

baza::baza() {
    glowa=NULL;
    ogon=NULL;
    rozmiar=0;
};

baza::~baza() {
    cout << "Lista zostala usunieta\n";
};
