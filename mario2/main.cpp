#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <tuple>
#include <set>
#include <map>

using namespace std;

int ruch_podstawowy = 1;
int poczatkowa_skocznosc_zawodnika = 2;

int parametr_teleportacji;
int parametr_utrudnienia;

int dlugosc_toru;
string tor;

//docelowe pole, skocznosc, czas dotarcia
typedef tuple<int, int, long long> przejscie;

typedef set<long long> skoki_na_dane_pole;

// tablica, jedeb set odpowiada jednemu polu
// zaznacza czy postac byla juz na polu przy danym poziomie skocznosci
skoki_na_dane_pole skoki[100000];

long long czas_przejscia_do_pola[100000];

queue<przejscie> kolejka_pol;

void wczytajDane() {
    string temp;
    cin >> dlugosc_toru;
    cin >> parametr_teleportacji;
    cin >> parametr_utrudnienia;

    getline(cin, temp); // do pominiecia pustego pola
    std::getline(cin, tor);

    czas_przejscia_do_pola[0] = 0;
    for ( int i = 1; i < dlugosc_toru; i++ ) { // potencjalnie wejscie na dane pole jest niemozliwe
        czas_przejscia_do_pola[i] = INT_MAX;
    }
    czas_przejscia_do_pola[dlugosc_toru] = -1; // do debugowania
}

static inline void dodajPrzejscieDoKolejki(przejscie a, int dlugosc_ruchu, int czas_ruchu) {
    int skocznosc = get<1>(a);
    if(skocznosc > 100000){
        return;
    }
    get<0>(a) += dlugosc_ruchu;
    get<2>(a) += czas_ruchu;

    int numer_pola = get<0>(a);
    long long czas_dotarcia = get<2>(a);

    if(czas_przejscia_do_pola[numer_pola] > czas_dotarcia){
        czas_przejscia_do_pola[numer_pola] = czas_dotarcia;
    }

    // sprawdzam czy bylem juz na tym polu przy danej skocznosci
    auto wejscie_przy_danej_skocznosci = skoki[numer_pola].find(skocznosc);

    // jezeli nie bylem, to moge wejsc na nie jeszcze raz
    if(wejscie_przy_danej_skocznosci == skoki[numer_pola].end()){
        kolejka_pol.push(a);
        if(dlugosc_ruchu != 1){
            skoki[numer_pola].insert(skocznosc);
        }
    }
}

static inline void dodajPrzejsciaDoKolejki(przejscie a, int czas_przejscia) {
    int numer_pola = get<0>(a);
    int skocznosc = get<1>(a);

    if ( numer_pola + skocznosc < dlugosc_toru ) {
        dodajPrzejscieDoKolejki(a, skocznosc, czas_przejscia);
    }
    if ( numer_pola + ruch_podstawowy < dlugosc_toru ){
        dodajPrzejscieDoKolejki(a, ruch_podstawowy, czas_przejscia);
    }
}

void przejdzTor() {
    przejscie wejscie_na_tor = make_tuple( 0, poczatkowa_skocznosc_zawodnika, 0 );
    kolejka_pol.push(wejscie_na_tor);

    while (!kolejka_pol.empty()) {
        przejscie a = kolejka_pol.front();
        kolejka_pol.pop();

        int numer_pola = get<0>(a);
        int skocznosc = get<1>(a);
        long long czas_dotarcia = get<2>(a);

        switch (tor[numer_pola]) {
            case '.': // zwykle pole, wykonujemy dalszy ruch
                dodajPrzejsciaDoKolejki(a, 1);
                break;
            case '*': // podwajamy skocznosc, i wykonujemy dalsze ruchy
                dodajPrzejsciaDoKolejki(make_tuple(numer_pola, 2 * skocznosc, czas_dotarcia), 1);
                break;
            case '#': // koniec gry
                break;
            case '>':
                dodajPrzejscieDoKolejki(a, parametr_teleportacji, 0);
                break;
            case '<': // teleportacja w lewo,
                dodajPrzejscieDoKolejki(a, (-1) * parametr_teleportacji, 0);
                break;
            case 'U':
                dodajPrzejsciaDoKolejki(a, parametr_utrudnienia + 1);
                break;
            default:
                break;
        }
    }
}

int main() {
    wczytajDane();
    przejdzTor();

    if(czas_przejscia_do_pola[dlugosc_toru-1] != INT_MAX)
       cout <<czas_przejscia_do_pola[dlugosc_toru-1] << endl;
    else
        cout << "-1" << endl;

    return 0;
}