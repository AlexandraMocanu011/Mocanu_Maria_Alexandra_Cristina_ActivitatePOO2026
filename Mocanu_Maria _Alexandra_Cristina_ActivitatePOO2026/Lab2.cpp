#include <iostream>
#include <string>

using namespace std;

class Librarie {
private:
    const int id;
    string denumire;
    int nrCarti;
    float* preturi;

public:
    static int nrLibrarii;

    Librarie() : id(++nrLibrarii) {
        this->denumire = "Librarie generala";
        this->nrCarti = 0;
        this->preturi = nullptr;
    }

    Librarie(int id, string denumire, int nrCarti, float* preturi)
        : id(id) {
        nrLibrarii++;
        this->denumire = denumire;
        this->nrCarti = nrCarti;

        this->preturi = new float[nrCarti];

        for (int i = 0; i < nrCarti; i++) {
            this->preturi[i] = preturi[i];
        }
    }

    void afisare() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr. carti: " << this->nrCarti;

        if (this->nrCarti > 0) {
            cout << " cu urmatoarele preturi: ";

            for (int i = 0; i < this->nrCarti - 1; i++) {
                cout << this->preturi[i] << " lei, ";
            }

            cout << this->preturi[this->nrCarti - 1] << " lei.";
        }

        cout << endl;
    }

    ~Librarie() {
        delete[] this->preturi;
    }
};

int Librarie::nrLibrarii = 0;

int main() {
    Librarie librarieGenerala;
    librarieGenerala.afisare();

    float* preturi = new float[3] { 45.5f, 30.0f, 65.9f };

    Librarie* librarieCarturesti =
        new Librarie(10, "Carturesti", 3, preturi);

    librarieCarturesti->afisare();

    delete librarieCarturesti;
    delete[] preturi;

    cout << endl << "Numar librarii: "
        << Librarie::nrLibrarii;

    return 0;
}