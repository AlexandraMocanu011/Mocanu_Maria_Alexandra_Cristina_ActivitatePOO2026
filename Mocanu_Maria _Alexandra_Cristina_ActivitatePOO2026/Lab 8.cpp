
#include <iostream>

using namespace std;

class Magazin {

private:
    const int idMagazin;
    int nrProduse;
    float* preturi;

public:

    // ==========================================
    // CERINTA 1 - CONSTRUCTOR DEFAULT
    // ==========================================

    Magazin() :idMagazin(0) {
        this->nrProduse = 0;
        this->preturi = nullptr;
    }

    // ==========================================
    // CERINTA 2 - CONSTRUCTOR CU PARAMETRI
    // ==========================================

    Magazin(int id, int nrProduse, const float* preturi)
        :idMagazin(id) {

        this->nrProduse = 0;
        this->preturi = nullptr;

        if (nrProduse > 0 && preturi != nullptr) {

            this->nrProduse = nrProduse;
            this->preturi = new float[nrProduse];

            for (int i = 0; i < nrProduse; i++) {
                this->preturi[i] = preturi[i];
            }
        }
    }

    // ==========================================
    // CERINTA 3 - GETTER PENTRU ATRIBUTUL CONSTANT
    // ==========================================

    int getIdMagazin() const {
        return this->idMagazin;
    }

    // ==========================================
    // CERINTA 4 - SETTER PENTRU VECTORUL DINAMIC
    // ==========================================

    void setPreturi(int nrNou, const float* preturiNoi) {

        if (nrNou > 0 && preturiNoi != nullptr) {

            float* copie = new float[nrNou];

            for (int i = 0; i < nrNou; i++) {
                copie[i] = preturiNoi[i];
            }

            delete[] this->preturi;

            this->preturi = copie;
            this->nrProduse = nrNou;
        }
    }

    // ==========================================
    // CERINTA 5 - OPERATORUL =
    // ==========================================

    Magazin& operator=(const Magazin& m) {

        if (this != &m) {

            float* copie = nullptr;

            if (m.preturi != nullptr && m.nrProduse > 0) {

                copie = new float[m.nrProduse];

                for (int i = 0; i < m.nrProduse; i++) {
                    copie[i] = m.preturi[i];
                }
            }

            delete[] this->preturi;

            this->preturi = copie;
            this->nrProduse = copie != nullptr ? m.nrProduse : 0;

            // idMagazin nu se modifica,
            // deoarece este const.
        }

        return *this;
    }

    // ==========================================
    // CERINTA 6 - METODA DE AFISARE
    // ==========================================

    void afisare() const {

        cout << endl << "-------------------------";
        cout << endl << "ID magazin: " << this->idMagazin;
        cout << endl << "Numar produse: " << this->nrProduse;

        cout << endl << "Preturi produse: ";

        if (this->preturi != nullptr) {

            for (int i = 0; i < this->nrProduse; i++) {
                cout << this->preturi[i] << " ";
            }
        }
        else {
            cout << "Nu exista produse";
        }

        cout << endl << "-------------------------";
    }

    // ==========================================
    // CONSTRUCTOR DE COPIERE
    // ==========================================

    Magazin(const Magazin& m) :idMagazin(m.idMagazin) {

        this->nrProduse = 0;
        this->preturi = nullptr;

        if (m.preturi != nullptr && m.nrProduse > 0) {

            this->nrProduse = m.nrProduse;
            this->preturi = new float[this->nrProduse];

            for (int i = 0; i < this->nrProduse; i++) {
                this->preturi[i] = m.preturi[i];
            }
        }
    }

    // ==========================================
    // DESTRUCTOR
    // ==========================================

    ~Magazin() {
        delete[] this->preturi;
        this->preturi = nullptr;
    }
};


// ==============================================
// FUNCTIA MAIN - TESTAREA CERINTELOR
// ==============================================

int main() {

    // TEST 1 - CONSTRUCTOR DEFAULT

    Magazin m1;
    m1.afisare();


    // TEST 2 - CONSTRUCTOR CU PARAMETRI

    float preturi1[] = { 100, 200, 300 };

    Magazin m2(1, 3, preturi1);
    m2.afisare();


    // TEST 3 - GETTER

    cout << endl << "ID magazin m2: "
        << m2.getIdMagazin();


    // TEST 4 - SETTER

    float preturi2[] = { 500, 600, 700, 800 };

    m2.setPreturi(4, preturi2);
    m2.afisare();


    // TEST 5 - CONSTRUCTOR DE COPIERE

    Magazin m3(m2);
    m3.afisare();


    // TEST 6 - OPERATORUL =

    m1 = m2;
    m1.afisare();


    // TEST 7 - AUTOATRIBUIRE

    m1 = m1;
    m1.afisare();


    // TEST 8 - VERIFICARE DEEP COPY

    float preturi3[] = { 10, 20 };

    m2.setPreturi(2, preturi3);

    cout << endl << "Magazin m2 modificat:";
    m2.afisare();

    cout << endl << "Magazin m3 nemodificat:";
    m3.afisare();


    // TEST 9 - DESTRUCTOR

    Magazin* m4 = new Magazin(4, 3, preturi1);

    m4->afisare();

    delete m4;
    m4 = nullptr;

    return 0;
}
