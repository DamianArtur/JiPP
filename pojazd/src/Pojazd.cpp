#include "Pojazd.h"

Pojazd::Pojazd(string nr_rej, string nazwa, int ilosc_miejsc, string marka, string typ, string zainstalowanaWersjaOprogramowania) {
    this->nr_rej = nr_rej;
    this->nazwa = nazwa;
    this->ilosc_miejsc = ilosc_miejsc;
    this->marka = marka;
    this->typ = typ;
    pasazerowie = new string[ilosc_miejsc];
    for(int i = 0; i < ilosc_miejsc; i++) {
        pasazerowie[i] = "puste";
    }
    this->zainstalowanaWersjaOprogramowania = zainstalowanaWersjaOprogramowania;
}

//konstruktor kopiujący
Pojazd::Pojazd(Pojazd &pojazd) {
    nr_rej = pojazd.nr_rej;
    nazwa = pojazd.nazwa;
    ilosc_miejsc = pojazd.ilosc_miejsc;
    pasazerowie = new string[ilosc_miejsc];
    for(int i = 0; i < ilosc_miejsc; i++) {
        pasazerowie[i] = pojazd.pasazerowie[i];
    }
    marka = pojazd.marka;
    typ = pojazd.typ;
    zainstalowanaWersjaOprogramowania = pojazd.zainstalowanaWersjaOprogramowania;
}

Pojazd::~Pojazd() {
    delete[] pasazerowie;
}

void Pojazd::print() {
    cout << "Numer referencyjny: " << nr_rej << endl;
    cout << "Nazwa: " << nazwa << endl;
    cout << "Ilosc miejsc: " << ilosc_miejsc << endl;
    cout << "Lista pasazerow: ";
    for(int i = 0; i < ilosc_miejsc; i++) {
        cout << pasazerowie[i] << " ";
    }
    cout << endl;
    cout << "Marka: " << marka << endl;
    cout << "Typ: " << typ << endl;
}

void Pojazd::zmien_pasazera(int nr_miejsca, string nowy_pasazer) {
    pasazerowie[nr_miejsca] = nowy_pasazer;
}

string Pojazd::getNr_rej() const {
    return nr_rej;
}

string Pojazd::getNazwa() const {
    return nazwa;
}

int Pojazd::getIloscMiejsc() const {
    return ilosc_miejsc;
}

string* Pojazd::getPasazerowie() const {
    return pasazerowie;
}

string Pojazd::getMarka() const {
    return marka;
}

string Pojazd::getTyp() const {
    return typ;
}

void Pojazd::setNr_rej(const int nr_rej) {
    this->nr_rej = nr_rej;
}

void Pojazd::setName(const string nazwa) {
    this->nazwa = nazwa;
}

void Pojazd::setIloscMiejsc(const int ilosc_miejsc) {
    this->ilosc_miejsc = ilosc_miejsc;
}

void Pojazd::setMarka(const string marka) {
    this->marka = marka;
}

void Pojazd::setTyp(const string typ) {
    this->typ = typ;
}

void Pojazd::wypiszWersje() {
    cout << "Zainstalowana wersja oprogramowania: " << zainstalowanaWersjaOprogramowania << endl;
}

void Pojazd::zaktualizujOprogramowanie() {
    zainstalowanaWersjaOprogramowania = najnowszaWersjaOprogramowania;
}

void Pojazd::opublikujNoweOprogramowanie(const string wersja) {
    najnowszaWersjaOprogramowania = wersja;
}

string Pojazd::najnowszaWersjaOprogramowania = "v2.3";