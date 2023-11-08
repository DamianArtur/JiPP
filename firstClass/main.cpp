#include <iostream>
#include <cmath>

using namespace std;

class Prostopadloscian { //klasa Prostopadloscian
private:
    int a;
    int b;
    int h;
public:
    Prostopadloscian(int &fa, int &fb, int &fh); //konstruktor

    int pole() { //funkcja obliczajaca objetosc prostopadloscianu
        return a * h;
    }

    void setA(int a) {
        this->a = a;
    }
    void setB(int b) {
        this->b = b;
    }
    void setH(int h) {
        this->h = h;
    }
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
    int getH() {
        return h;
    }
};

class Kula { //klasa Kula
private:
    int r;
public:
    Kula(int &fr);

    double objetosc() { //funckcja obliczajaca objetosc kuli
        return 4/3. * pow(r, 3);
    }

    void setR(int r) {
        this->r = r;
    }
    int getR() {
        return r;
    }
};

class FunkcjaKwadratowa { //klasa FunkcjaKwadratowa
private:
    int a;
    int b;
    int c;
public:
    FunkcjaKwadratowa(int &fa, int &fb, int &fc);

    void wyswietl() { //funckja wyswietlajaca rownanie
        cout << "f(x) = " << a << " x^2 + " << b << " x + " << c << endl;
    }

    void setA(int a) {
        this->a = a;
    }
    void setB(int b) {
        this->b = b;
    }
    void setC(int c) {
        this->c = c;
    }
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
    int getC() {
        return c;
    }
};

class Student { //klasa Student
private:
    string imie;
    string nazwisko;
    int numer_albumu;
    int liczba_pytan;
    int poprawne_odpowiedzi;
public:
    Student(string &fimie, string &fnazwisko, int &fnumer_albumu, int &fliczba_pytan, int &fpoprawne_odpowiedzi);

    double procent_poprawnych() { //funkcja obliczajaca procent poprawnych odpowiedzi
        return poprawne_odpowiedzi * 100.0 / liczba_pytan;
    }

    void setImie(string imie) {
        this->imie = imie;
    }
    void setNazwisko(string nazwisko) {
        this->nazwisko = nazwisko;
    }
    void setNumer_albumu(int numer_albumu) {
        this->numer_albumu = numer_albumu;
    }
    void setLiczba_pytan(int liczba_pytan) {
        this->liczba_pytan = liczba_pytan;
    }
    void setPoprawne_odpowiedzi(int poprawne_odpowiedzi) {
        this->poprawne_odpowiedzi = poprawne_odpowiedzi;
    }
    string getImie() {
        return imie;
    }
    string getNazwisko() {
        return nazwisko;
    }
    int getNumer_albumu() {
        return numer_albumu;
    }
    int getLiczba_pytan() {
        return liczba_pytan;
    }
    int getPoprawne_odpowiedzi() {
        return poprawne_odpowiedzi;
    }
};

Prostopadloscian::Prostopadloscian(int &fa, int &fb, int &fh)
        :a ( fa )
        ,b ( fb )
        ,h ( fh ) {}

Kula::Kula(int &fr)
        :r ( fr ) {}

FunkcjaKwadratowa::FunkcjaKwadratowa(int &fa, int &fb, int &fc)
        :a ( fa )
        ,b ( fb )
        ,c ( fc ) {}

Student::Student(string &fimie, string &fnazwisko, int &fnumer_albumu, int &fliczba_pytan,
                 int &fpoprawne_odpowiedzi)
                 :imie ( fimie)
                 ,nazwisko ( fnazwisko )
                 ,numer_albumu ( fnumer_albumu )
                 ,liczba_pytan ( fliczba_pytan )
                 ,poprawne_odpowiedzi ( fpoprawne_odpowiedzi ) {}

int main() {
    int a, b, h;

    int r;

    int j, k, l;

    string imie, nazwisko;
    int numer_albumu;
    int liczba_pytan;
    int poprawne_odpowiedzi;

    //Zad1 ------------------------------------------------------------

    cout << "Podaj a, b, h w prostopadloscianie: ";
    cin >> a >> b >> h;
    Prostopadloscian prostopadloscian(a, b, h);
    cout << "Pole prostopadloscianu wynosi " << prostopadloscian.pole() << endl;

    //Zad2 ------------------------------------------------------------

    cout << "Podaj r kuli: ";
    cin >> r;
    Kula kula(r);
    cout << "Objetosc kuli wynosi " << kula.objetosc() << endl;

    //Zad3 ------------------------------------------------------------

    cout << "Wprowadz wspolczynniki funkcji kwadratowej a, b i c: ";
    cin >> j >> k >> l;
    FunkcjaKwadratowa funkcjaKwadratowa(j, k, l);
    funkcjaKwadratowa.wyswietl();

    //Zad4 ------------------------------------------------------------

    cout << "Wprowadz imie, nazwisko, nr albumu, liczbe pytan i liczbe poprawnych odpowiedzi" << endl;
    cin >> imie >> nazwisko >> numer_albumu >> liczba_pytan >> poprawne_odpowiedzi;
    Student student(imie, nazwisko, numer_albumu, liczba_pytan, poprawne_odpowiedzi);
    cout << "Mamy " << student.procent_poprawnych() << " % poprawnych odpowiedzi." << endl;
}