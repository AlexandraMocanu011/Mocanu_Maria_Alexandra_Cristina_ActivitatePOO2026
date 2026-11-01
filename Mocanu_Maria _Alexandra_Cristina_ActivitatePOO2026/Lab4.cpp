
#include <iostream>
#include <string>

using namespace std;

enum TipMagazin { ALIMENTAR = 1, VESTIMENTAR = 2 };

class Magazin {
private:
    const int id;
    string nume;
    TipMagazin tip;
    int nrProduse;
    float* preturi;

public:
    static int nrMagazine;

    Magazin() : id(++nrMagazine) {
        this->nume = "Magazin general";
        this->tip = ALIMENTAR;
        this->nrProduse = 0;
        this->preturi = nullptr;
    }

    Magazin(int id, string nume, TipMagazin tip,
        int nrProduse, float* preturi) : id(id) {

        nrMagazine++;
        this->nume = nume;
        this->tip = tip;
        this->nrProduse = nrProduse;
        this->preturi = nullptr;

        if (nrProduse > 0 && preturi != nullptr) {
            this->preturi = new float[nrProduse];

            for (int i = 0; i < nrProduse; i++) {
                this->preturi[i] = preturi[i];
            }
        }
        else {
            this->nrProduse = 0;
        }
    }

    Magazin(const Magazin& m) : id(++nrMagazine) {
        this->nume = m.nume;
        this->tip = m.tip;
        this->nrProduse = m.nrProduse;
        this->preturi = nullptr;

        if (m.preturi != nullptr) {
            this->preturi = new float[nrProduse];

            for (int i = 0; i < nrProduse; i++) {
                this->preturi[i] = m.preturi[i];
            }
        }
    }

    int getNrProduse() {
        return this->nrProduse;
    }

    void setNume(string numeNou) {
        if (numeNou.length() > 0) {
            this->nume = numeNou;
        }
    }

    void afisare() {
        cout << endl << "ID: " << this->id;
        cout << endl << "Nume: " << this->nume;
        cout << endl << "Tip: ";

        if (this->tip == ALIMENTAR)
            cout << "Alimentar";
        else
            cout << "Vestimentar";

        cout << endl << "Nr. produse: " << this->nrProduse;

        for (int i = 0; i < nrProduse; i++) {
            cout << endl << "Pret produs " << i + 1
                << ": " << preturi[i] << " lei";
        }

        cout << endl;
    }

    bool operator<(const Magazin& m) {
        return this->nrProduse < m.nrProduse;
    }

    ~Magazin() {
        delete[] this->preturi;
    }
};

int Magazin::nrMagazine = 0;

int main() {
    Magazin magazinGeneral;
    magazinGeneral.afisare();

    float preturi[] = { 25.5f, 49.9f, 70.0f };

    Magazin magazin1(10, "Fashion Store",
        VESTIMENTAR, 3, preturi);

    magazin1.afisare();

    Magazin magazin2(magazin1);
    magazin2.setNume("Fashion Outlet");
    magazin2.afisare();

    cout << endl << "Numar produse: "
        << magazin2.getNrProduse();

    if (magazinGeneral < magazin1) {
        cout << endl
            << "Magazinul general are mai putine produse.";
    }

    cout << endl << "Numar magazine create: "
        << Magazin::nrMagazine;

    return 0;
}
