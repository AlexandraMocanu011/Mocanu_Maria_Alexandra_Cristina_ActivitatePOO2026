
#include <iostream>
#include <string>

using namespace std;

enum TipFlorarie { MAGAZIN = 1, ONLINE = 2 };

class Florarie {
private:
    const int id;
    TipFlorarie tip;
    string nume;
    int nrBuchete;
    float* preturi;

public:
    static int nrFlorarii;

    Florarie() : id(++nrFlorarii) {
        this->nume = "Florarie generala";
        this->tip = MAGAZIN;
        this->nrBuchete = 0;
        this->preturi = nullptr;
    }

    Florarie(int id, string nume, int nrBuchete,
        float* preturi, TipFlorarie tip) : id(id) {

        nrFlorarii++;
        this->nume = nume;
        this->tip = tip;
        this->nrBuchete = nrBuchete;

        if (preturi != nullptr && nrBuchete > 0) {
            this->preturi = new float[nrBuchete];

            for (int i = 0; i < nrBuchete; i++) {
                this->preturi[i] = preturi[i];
            }
        }
        else {
            this->nrBuchete = 0;
            this->preturi = nullptr;
        }
    }

    Florarie(const Florarie& copie) : id(++nrFlorarii) {
        this->nume = copie.nume;
        this->tip = copie.tip;
        this->nrBuchete = copie.nrBuchete;

        if (copie.preturi != nullptr) {
            this->preturi = new float[this->nrBuchete];

            for (int i = 0; i < this->nrBuchete; i++) {
                this->preturi[i] = copie.preturi[i];
            }
        }
        else {
            this->preturi = nullptr;
        }
    }

    void operator=(const Florarie& copie) {
        if (this != &copie) {
            float* preturiNoi = nullptr;

            if (copie.preturi != nullptr) {
                preturiNoi = new float[copie.nrBuchete];

                for (int i = 0; i < copie.nrBuchete; i++) {
                    preturiNoi[i] = copie.preturi[i];
                }
            }

            delete[] this->preturi;

            this->nume = copie.nume;
            this->tip = copie.tip;
            this->nrBuchete = copie.nrBuchete;
            this->preturi = preturiNoi;
        }
    }

    //get si set pentru nrBuchete
    int getNrBuchete() {
        return this->nrBuchete;
    }

    void setNrBuchete(int valoareNoua) {
        if (valoareNoua >= 0) {
            if (valoareNoua != this->nrBuchete) {
                float* preturiNoi = nullptr;

                if (valoareNoua > 0) {
                    preturiNoi = new float[valoareNoua] {};

                    int limita = this->nrBuchete;
                    if (valoareNoua < limita) {
                        limita = valoareNoua;
                    }

                    for (int i = 0; i < limita; i++) {
                        preturiNoi[i] = this->preturi[i];
                    }
                }

                delete[] this->preturi;
                this->preturi = preturiNoi;
                this->nrBuchete = valoareNoua;
            }
        }
        else {
            throw "Numar invalid de buchete!";
        }
    }

    //get si set pentru preturi
    float* getPreturi() {
        if (this->preturi == nullptr) {
            return nullptr;
        }

        float* vPreturi = new float[this->nrBuchete];

        for (int i = 0; i < this->nrBuchete; i++) {
            vPreturi[i] = this->preturi[i];
        }

        return vPreturi;
    }

    void setPreturi(float* vPreturi, int dim) {
        if (dim < 0 || (dim > 0 && vPreturi == nullptr)) {
            throw "Date invalide!";
        }

        float* preturiNoi = nullptr;

        if (dim > 0) {
            preturiNoi = new float[dim];

            for (int i = 0; i < dim; i++) {
                preturiNoi[i] = vPreturi[i];
            }
        }

        delete[] this->preturi;
        this->preturi = preturiNoi;
        this->nrBuchete = dim;
    }

    void afisare() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Nume: " << this->nume;
        cout << endl << "Tip florarie: ";

        if (this->tip == MAGAZIN) {
            cout << "MAGAZIN";
        }
        else {
            cout << "ONLINE";
        }

        cout << endl << "Nr. buchete: " << this->nrBuchete;

        if (this->nrBuchete > 0) {
            cout << endl << "Preturi: ";

            for (int i = 0; i < this->nrBuchete - 1; i++) {
                cout << this->preturi[i] << " lei, ";
            }

            cout << this->preturi[this->nrBuchete - 1]
                << " lei.";
        }

        cout << endl;
    }

    bool operator<(const Florarie& f) {
        return this->nrBuchete < f.nrBuchete;
    }

    ~Florarie() {
        cout << endl << "Destructor Florarie!";
        delete[] this->preturi;
    }
};

int Florarie::nrFlorarii = 0;

int main() {
    Florarie florarieGenerala;
    florarieGenerala.afisare();

    float preturi[] = { 35.5f, 48.0f, 62.5f };

    Florarie* florarieRoz =
        new Florarie(5, "Flori de Roz", 3, preturi, MAGAZIN);

    florarieRoz->afisare();

    Florarie* florarieNoua = new Florarie(*florarieRoz);
    florarieNoua->afisare();

    florarieGenerala = *florarieNoua;
    florarieGenerala.afisare();

    Florarie florarieX;

    florarieX = florarieGenerala;
    florarieX.afisare();

    try {
        florarieX.setNrBuchete(2);
    }
    catch (const char* mesaj) {
        cout << endl << mesaj;
    }
    catch (...) {
        cout << endl << "Eroare!";
    }

    cout << endl << "Noul numar de buchete: "
        << florarieX.getNrBuchete() << endl;

    float preturiNoi[] = { 75.5f, 90.0f };
    florarieX.setPreturi(preturiNoi, 2);

    float* vPreturi = florarieX.getPreturi();

    for (int i = 0; i < florarieX.getNrBuchete(); i++) {
        cout << vPreturi[i] << " lei, ";
    }

    if (florarieX < florarieGenerala) {
        cout << endl
            << "FlorarieX are mai putine buchete!";
    }
    else {
        cout << endl
            << "FlorarieX are cel putin la fel de multe buchete!";
    }

    delete[] vPreturi;

    delete florarieRoz;
    delete florarieNoua;

    cout << endl << "Numar florarii create: "
        << Florarie::nrFlorarii;

    return 0;
}
