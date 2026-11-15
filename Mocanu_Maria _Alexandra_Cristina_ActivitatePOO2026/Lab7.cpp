
#include<iostream>
#include<string>
#include<exception>

using namespace std;

class ExceptieCustom : public exception {
public:
    ExceptieCustom(const char* mesaj) : exception(mesaj) {}
};

class Angajat {
private:
    const int cod;
    string nume;
    float salariu;

public:
    static const float SALARIU_MINIM;

    Angajat() :cod(0), nume("Angajat general"), salariu(4500) {
    }

    Angajat(int codA, string numeA, float salariuA)
        :cod(codA), nume(numeA), salariu(salariuA) {
        if (salariu < SALARIU_MINIM) {
            throw ExceptieCustom("Salariul este prea mic!");
        }
    }

    virtual void afisare() {
        cout << endl << "Cod: " << this->cod;
        cout << endl << "Nume: " << this->nume;
        cout << endl << "Salariu: " << this->salariu;
    }

    virtual ~Angajat() {
    }

    virtual float getProcentBonus() = 0;
};

const float Angajat::SALARIU_MINIM = 1000;

class AngajatBonus : public Angajat {
private:
    float procentBonus;

public:
    AngajatBonus() :Angajat(), procentBonus(5) {
    }

    AngajatBonus(int cod, string nume, float salariu,
        float procentBonus)
        :Angajat(cod, nume, salariu),
        procentBonus(procentBonus) {
    }

    void afisare() override {
        this->Angajat::afisare();
        cout << endl << "Procent bonus: "
            << this->procentBonus;
    }

    float getProcentBonus() override {
        return this->procentBonus;
    }
};

class SalariuInterface {
public:
    virtual float calculBonus(float salariu, float procent) = 0;
    virtual float calculSalariuTotal(float salariu, float bonus) = 0;
    virtual float calculImpozit(float salariu, float procent) = 0;
    virtual float calculSalariuNet(float salariu, float impozit) = 0;

    virtual ~SalariuInterface() {}
};

class SalariuOperation : public SalariuInterface {
public:
    float calculBonus(float salariu, float procent) override {
        return salariu * procent / 100;
    }

    float calculSalariuTotal(float salariu, float bonus) override {
        return salariu + bonus;
    }

    float calculImpozit(float salariu, float procent) override {
        return salariu * procent / 100;
    }

    float calculSalariuNet(float salariu, float impozit) override {
        if (impozit <= salariu) {
            return salariu - impozit;
        }
        else {
            throw ExceptieCustom("Impozitul depaseste salariul!");
        }
    }
};

int main() {

    //try {
    //    AngajatBonus angajat(1, "Maria", 500, 10);
    //}
    //catch (const ExceptieCustom& e) {
    //    cout << endl << e.what();
    //}

    //AngajatBonus angajat(1, "Maria", 5000, 10);
    //angajat.afisare();

    Angajat* vectorAngajati[3];

    vectorAngajati[0] = new AngajatBonus(1, "Andrei", 4500, 10);
    vectorAngajati[1] = new AngajatBonus(2, "Elena", 6000, 15);
    vectorAngajati[2] = new AngajatBonus(3, "Mihai", 7500, 20);

    for (int i = 0; i < 3; i++) {
        vectorAngajati[i]->afisare();
        delete vectorAngajati[i];
    }

    SalariuInterface* operation = new SalariuOperation();

    cout << endl << "Bonus: "
        << operation->calculBonus(5000, 10);

    cout << endl << "Salariu total: "
        << operation->calculSalariuTotal(5000, 500);

    cout << endl << "Impozit: "
        << operation->calculImpozit(5000, 10);

    cout << endl << "Salariu net: "
        << operation->calculSalariuNet(5000, 500);

    delete operation;

    return 0;
}
