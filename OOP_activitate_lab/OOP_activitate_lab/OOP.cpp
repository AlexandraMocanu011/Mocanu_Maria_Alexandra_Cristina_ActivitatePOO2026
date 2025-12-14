#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>

using namespace std;

/* CLASA MASINA */

class Masina {
private:
    const int idMasina;
    static int nrMasini;

    char* marca;
    char* model;
    int anFabricatie;
    float pret;
    bool esteNoua;

public:
    Masina() : idMasina(++nrMasini) {
        marca = new char[strlen("Necunoscuta") + 1];
        strcpy(marca, "Necunoscuta");

        model = new char[strlen("N/A") + 1];
        strcpy(model, "N/A");

        anFabricatie = 0;
        pret = 0;
        esteNoua = false;
    }

    Masina(const char* marca) : idMasina(++nrMasini) {
        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);

        model = new char[strlen("N/A") + 1];
        strcpy(model, "N/A");

        anFabricatie = 0;
        pret = 0;
        esteNoua = false;
    }

    Masina(const char* marca, const char* model, int anFabricatie, float pret, bool esteNoua)
        : idMasina(++nrMasini) {
        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);

        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);

        this->anFabricatie = anFabricatie;
        this->pret = pret;
        this->esteNoua = esteNoua;
    }

    Masina(const Masina& m) : idMasina(++nrMasini) {
        if (m.marca != nullptr) {
            marca = new char[strlen(m.marca) + 1];
            strcpy(marca, m.marca);
        }
        else marca = nullptr;

        if (m.model != nullptr) {
            model = new char[strlen(m.model) + 1];
            strcpy(model, m.model);
        }
        else model = nullptr;

        anFabricatie = m.anFabricatie;
        pret = m.pret;
        esteNoua = m.esteNoua;
    }

    ~Masina() {
        if (marca != nullptr) delete[] marca;
        if (model != nullptr) delete[] model;
    }

    float getPret() { return pret; }
    bool getEsteNoua() { return esteNoua; }

    void setMarca(const char* m) {
        if (m && strlen(m) > 0) {
            if (marca) delete[] marca;
            marca = new char[strlen(m) + 1];
            strcpy(marca, m);
        }
    }

    void setModel(const char* m) {
        if (m && strlen(m) > 0) {
            if (model) delete[] model;
            model = new char[strlen(m) + 1];
            strcpy(model, m);
        }
    }

    void setAnFabricatie(int a) { if (a > 0) anFabricatie = a; }
    void setPret(float p) { if (p >= 0) pret = p; }
    void setEsteNoua(bool e) { esteNoua = e; }

    void afisareMasina() {
        cout << endl << idMasina << ". Masina "
            << marca << " " << model
            << ", anul " << anFabricatie
            << ", pret " << pret << " EUR, "
            << (esteNoua ? "NOUA" : "SH") << ".";
    }

    bool operator!() {
        return !this->esteNoua;
    }

    friend int numarMasiniSH(Masina* masini, int nr);
};

int Masina::nrMasini = 0;

/* FUNCTII GLOBALE */

int numarMasiniSH(Masina* masini, int nr) {
    int contor = 0;
    for (int i = 0; i < nr; i++) {
        if (!masini[i]) { // folosim operator !
            contor++;
        }
    }
    return contor;
}

/* MAIN */

void main() {

    cout << "Faza 4 - vectori (prelucrare simpla)" << endl;

    int nrMasiniVector;
    cout << endl << "Numar masini in vector: ";
    cin >> nrMasiniVector;

    Masina* vectMasini = new Masina[nrMasiniVector];

    for (int i = 0; i < nrMasiniVector; i++) {
        char marca[50], model[50];
        int an;
        float pret;
        int esteNoua;

        cout << endl << "Masina " << i + 1 << " - marca: ";
        cin >> marca;
        cout << "Masina " << i + 1 << " - model: ";
        cin >> model;
        cout << "Masina " << i + 1 << " - an fabricatie: ";
        cin >> an;
        cout << "Masina " << i + 1 << " - pret: ";
        cin >> pret;
        cout << "Masina " << i + 1 << " - este noua? (1-DA / 0-NU): ";
        cin >> esteNoua;

        vectMasini[i].setMarca(marca);
        vectMasini[i].setModel(model);
        vectMasini[i].setAnFabricatie(an);
        vectMasini[i].setPret(pret);
        vectMasini[i].setEsteNoua(esteNoua == 1);
    }

    cout << endl << "Afisare vector masini:";
    for (int i = 0; i < nrMasiniVector; i++) {
        vectMasini[i].afisareMasina();
    }

    cout << endl << endl << "Numar masini SH din vector: "
        << numarMasiniSH(vectMasini, nrMasiniVector);

    delete[] vectMasini;

    cout << endl << endl << "Sfarsit commit." << endl;
}
