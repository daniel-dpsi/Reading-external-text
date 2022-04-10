#include <iostream>
#include <fstream>
using namespace std;

class avto {
public:
    string tip, barva;
    int letnik, kilometri;
}a[6];

void kilometri() {
    int stevec = 0;
    for (int i = 0; i < 6; i++) {
        if (a[i].kilometri > 100000) {
            stevec++;
        }
    }
    cout << endl;
    cout << stevec << " > 100000" << endl;
}

void avg() {
    int sestevek = 0, vsi = 6;
    for (int i = 0; i < 6; i++) {
        sestevek += a[i].letnik - 2000;
    }
    cout << "\nPovprecna starost je: " << sestevek / vsi << endl;
}

avto najnovejsi() {
    avto ime;
    int max = 0, pos;
    for (int i = 0; i < 6; i++) {
        if (a[i].letnik > max) {
            max = a[i].letnik;
            pos = i;
        }
    }
    for (int i = 0; i < 6; i++)
        if (a[i].letnik == max) {
            ime.tip = a[i].tip;
            ime.barva = a[i].barva;
            ime.letnik = a[i].letnik;
            ime.kilometri = a[i].kilometri;
        }
    return ime;
}

void fiati() {
    int stevec = 0;
    for (int i = 0; i < 6; i++) {
        if (a[i].tip == "FIAT" && a[i].letnik <= 2017) {
            stevec++;
        }
    }
    cout << "\nSt. FIAT-ov starejsih od 5: " << stevec << endl;
}

int main()
{
    ifstream txt("avtomobili.txt");
    for (int i = 0; i < 6; i++) {
        txt >> a[i].tip >> a[i].barva >> a[i].letnik >> a[i].kilometri;
        cout << a[i].tip << " " << a[i].barva << " " << a[i].letnik << " " << a[i].kilometri << endl;
    }
    kilometri();
    avg();
    fiati();
    avto name = najnovejsi();
    cout << name.tip << " " << name.barva << " " << name.letnik << " " << name.kilometri << endl;
}


