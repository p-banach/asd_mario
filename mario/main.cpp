#include <iostream>
#include <string>
#include <climits>

using namespace std;

int ruch_podstawowy = 1;
int poczatkowa_skocznosc_zawodnika = 2;

int parametr_teleportacji;
int parametr_utrudnienia;

// tor ma pola od 1 do n,
// ale w programie numeruje je od 0 do n-1
int dlugosc_toru;
string tor;

// uzywany do zapisania minimalnego czasu, potrzebnego do dotarcia do danego pola
int *minimalny_czas_do_pola;

bool tor_pokonany = false;
int minimalny_czas_przejscia = INT_MAX;

int maksymalna_skocznosc_zawodnika = poczatkowa_skocznosc_zawodnika;

void wczytajDane() {
    string temp;
    cin >> dlugosc_toru;
    cin >> parametr_teleportacji;
    cin >> parametr_utrudnienia;

    getline(cin, temp); // do pominiecia pustego pola
    std::getline(cin, tor);
    minimalny_czas_do_pola = new int[dlugosc_toru];
    // domyslnie, czas dojscie do kazdego pola jest maksymalny
    // (pierwsze wejscie musi byc od niego mniejsze)
    for ( int i = 0; i < dlugosc_toru; i++ ) {
        minimalny_czas_do_pola[i] = INT_MAX;
    }
}

void wykonaj_ruch(int obecny_czas, int obecna_pozycja, int skocznosc_zawodnika, bool magiczne_pole_istnieje);

void wykonaj_ruchUtil(int obecny_czas, int obecna_pozycja, int skocznosc_zawodnika, bool magiczne_pole_istnieje) {

    // jezeli moge skoczyc do konca, to jest to scisle lepsza sytuacja od przechodzenia tam
    if ( obecna_pozycja + skocznosc_zawodnika == dlugosc_toru - 1 ) {
        wykonaj_ruch(obecny_czas, obecna_pozycja + skocznosc_zawodnika, skocznosc_zawodnika, magiczne_pole_istnieje);
        return;
    }
    wykonaj_ruch(obecny_czas, obecna_pozycja + skocznosc_zawodnika, skocznosc_zawodnika, magiczne_pole_istnieje);
    wykonaj_ruch(obecny_czas, obecna_pozycja + ruch_podstawowy, skocznosc_zawodnika, magiczne_pole_istnieje);
}

void wykonaj_ruch(int obecny_czas, int obecna_pozycja, int skocznosc_zawodnika, bool magiczne_pole_istnieje) {
    // nie wykonujemy ruchu, ktory wyrzuci nas poza tor
    if ( obecna_pozycja >= dlugosc_toru )
        return;

    // po wykonaniu ruchu, przede wszystkim zwiekszamy licznik ruchow o jeden
    obecny_czas++;

    if ( tor_pokonany && obecny_czas >= minimalny_czas_przejscia ) // nie ma powodu sprawdzac sciezke,
        return;                                                    // o ktorej wiemy ze jest gorsza

    bool teleport_w_lewo_pomoze = magiczne_pole_istnieje && skocznosc_zawodnika < dlugosc_toru;

    // jezeli juz kiedys bylismy w tym miejscu, i to w mniejszej ilosci ruchow, to nie ma potrzeby szukac dalej
    // (chyba ze w celu podniesienia skocznosci)
    if ( obecny_czas >= minimalny_czas_do_pola[obecna_pozycja] && !teleport_w_lewo_pomoze)
        return;

    // w przeciwnym wypadku nowy czas jest lepszy, wiec go zapisujemy
    minimalny_czas_do_pola[obecna_pozycja] = obecny_czas;

    // jezeli jestesmy na koncu toru, to porownujemy obecny czas z minimalnym
    if ( obecna_pozycja == dlugosc_toru - 1 ) {
        if ( obecny_czas < minimalny_czas_przejscia ) {
            minimalny_czas_przejscia = obecny_czas;
        }
        tor_pokonany = true;
        return; // przerywamy przejscie
    }

    switch (tor[obecna_pozycja]) {
        case '.': // zwykle pole, wykonujemy dalszy ruch
            wykonaj_ruchUtil(obecny_czas, obecna_pozycja, skocznosc_zawodnika, magiczne_pole_istnieje);
            break;
        case '*': // podwajamy skocznosc, i wykonujemy dalsze ruchy
            magiczne_pole_istnieje = true;
            skocznosc_zawodnika *= 2;
            if(skocznosc_zawodnika > maksymalna_skocznosc_zawodnika)
                maksymalna_skocznosc_zawodnika = skocznosc_zawodnika;
            wykonaj_ruchUtil(obecny_czas, obecna_pozycja, skocznosc_zawodnika, magiczne_pole_istnieje);
            break;
        case '#': // koniec gry
            return;
        case '>': // teleportacja w prawo, obnizamy obecny czas, bo teleportacja jest natychmiastowa
            // a zwiekszymy go przy wejsciu na kolejne pole
            wykonaj_ruch(--obecny_czas, obecna_pozycja + parametr_teleportacji, skocznosc_zawodnika, magiczne_pole_istnieje);
            break;
        case '<': // teleportacja w lewo,
            wykonaj_ruch(--obecny_czas, obecna_pozycja - parametr_teleportacji, skocznosc_zawodnika, magiczne_pole_istnieje);
            break;
        case 'U':
            obecny_czas += parametr_utrudnienia;
            wykonaj_ruchUtil(obecny_czas, obecna_pozycja, skocznosc_zawodnika, magiczne_pole_istnieje);
            break;
        default:
            wykonaj_ruchUtil(obecny_czas, obecna_pozycja, skocznosc_zawodnika, magiczne_pole_istnieje);
    }
}


void przejdzTor() {
    int obecny_czas = -1;
    int pozycja_na_torze = -1;
    int skocznosc_zawodnika = poczatkowa_skocznosc_zawodnika;
    bool magiczne_pole_istnieje = false;

    // pierwszy "ruch" to wejscie na tor
    wykonaj_ruch(obecny_czas, pozycja_na_torze + ruch_podstawowy, skocznosc_zawodnika, magiczne_pole_istnieje);
}

int main() {
    wczytajDane();
    przejdzTor();

    if ( tor_pokonany )
        cout << minimalny_czas_przejscia << endl;
    else
        cout << "-1" << endl;

    delete[] minimalny_czas_do_pola;
    return 0;
}
