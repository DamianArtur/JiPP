#ifndef POJAZD_H
#define POJAZD_H

#include <iostream>

using namespace std;

class Pojazd {

private:
    string nr_rej;
    string nazwa;
    int ilosc_miejsc;
    string* pasazerowie;
    string marka;
    string typ;
    static string najnowszaWersjaOprogramowania;
    string zainstalowanaWersjaOprogramowania;

public:

    Pojazd::Pojazd(string nr_rej, string nazwa, int ilosc_miejsc, string marka, string typ, string zainstalowanaWersjaOprogramowania);
    Pojazd(Pojazd &pojazd);
    Pojazd::~Pojazd();

    void print();
    void zmien_pasazera(int nr_miejsca, string pasazer);

    string Pojazd::getNr_rej() const;
    string Pojazd::getNazwa() const;
    int Pojazd::getIloscMiejsc() const;
    string* Pojazd::getPasazerowie() const;
    string Pojazd::getMarka() const;
    string Pojazd::getTyp() const;

    void Pojazd::setNr_rej(const int nr_rej);
    void Pojazd::setName(const string nazwa);
    void Pojazd::setIloscMiejsc(const int ilosc_miejsc);
    void Pojazd::setMarka(const string marka);
    void Pojazd::setTyp(const string typ);

    void Pojazd::wypiszWersje();

    void Pojazd::zaktualizujOprogramowanie();

    static void Pojazd::opublikujNoweOprogramowanie(string wersja);
};

#endif //POJAZD_H