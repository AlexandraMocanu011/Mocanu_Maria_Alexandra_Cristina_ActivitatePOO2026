
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

enum Specific { ROMANESC = 1, ITALIAN = 2 };

class Restaurant {
private:
    const int id;
    Specific specific;
    string nume;
    float incasari;
    int nrPreparate;
    float* preturi;

public:
    static int nrRestaurante;

    Restaurant() : id(++nrRestaurante) {
        this->nume = "Restaurant general";
        this->specific = ROMANESC;
        this->incasari = 0;
        this->nrPreparate = 0;
        this->preturi = nullptr;
    }

    Restaurant(int id, string nume, float incasari,
        int nrPreparate, const float* preturi, Specific specific) : id(id) {

        nrRestaurante++;
        this->nume = nume;
        this->incasari = incasari;
        this->specific = specific;
        this->nrPreparate = 0;
        this->preturi = nullptr;

        setPreturi(preturi, nrPreparate);
    }

    //constructor de copiere
    Restaurant(const Restaurant& copie) : id(++nrRestaurante) {
        this->nume = copie.nume;
        this->incasari = copie.incasari;
        this->specific = copie.specific;
        this->nrPreparate = 0;
        this->preturi = nullptr;

        setPreturi(copie.preturi, copie.nrPreparate);
    }

    //operator de atribuire
    Restaurant& operator=(const Restaurant& copie) {
        if (this != &copie) {
            setPreturi(copie.preturi, copie.nrPreparate);
            this->nume = copie.nume;
            this->incasari = copie.incasari;
            this->specific = copie.specific;
        }

        return *this;
    }

    //get si set pentru nrPreparate
    int getNrPreparate() const {
        return this->nrPreparate;
    }

    void setNrPreparate(int valoareNoua) {
        if (valoareNoua < 0) {
            throw exception();
        }

        float* vectorNou = nullptr;

        if (valoareNoua > 0) {
            vectorNou = new float[valoareNoua] {};

            int limita = this->nrPreparate;

            if (valoareNoua < limita) {
                limita = valoareNoua;
            }

            for (int i = 0; i < limita; i++) {
                vectorNou[i] = this->preturi[i];
            }
        }

        delete[] this->preturi;
        this->preturi = vectorNou;
        this->nrPreparate = valoareNoua;
    }

    //get si set pentru preturi
    float* getPreturi() const {
        if (this->nrPreparate == 0) {
            return nullptr;
        }

        float* vPreturi = new float[this->nrPreparate];

        for (int i = 0; i < this->nrPreparate; i++) {
            vPreturi[i] = this->preturi[i];
        }

        return vPreturi;
    }

    void setPreturi(const float* vPreturi, int dim) {
        if (dim < 0 || (dim > 0 && vPreturi == nullptr)) {
            throw exception();
        }

        float* vectorNou = nullptr;

        if (dim > 0) {
            vectorNou = new float[dim];

            for (int i = 0; i < dim; i++) {
                vectorNou[i] = vPreturi[i];
            }
        }

        delete[] this->preturi;
        this->preturi = vectorNou;
        this->nrPreparate = dim;
    }

    void afisare() const {
        cout << endl << "Id: " << this->id;
        cout << endl << "Nume: " << this->nume;
        cout << endl << "Incasari: " << this->incasari;
        cout << endl << "Specific: ";

        if (this->specific == ROMANESC) {
            cout << "Romanesc";
        }
        else {
            cout << "Italian";
        }

        cout << endl << "Nr. preparate: " << this->nrPreparate;

        if (this->nrPreparate > 0) {
            cout << endl << "Preturi: ";

            for (int i = 0; i < this->nrPreparate; i++) {
                cout << this->preturi[i] << " lei, ";
            }
        }

        cout << endl;
    }

    bool operator<(const Restaurant& r) const {
        return this->nrPreparate < r.nrPreparate;
    }

    ~Restaurant() {
        delete[] this->preturi;
    }

    //operator +=
    void operator+=(float suma) {
        this->incasari += suma;
    }

    //operator negatie
    bool operator!() const {
        return this->incasari == 0;
    }

    //operator functie
    float operator()(float suma) const {
        return this->incasari + suma;
    }

    //operator index
    float& operator[](int index) {
        if (index >= 0 && index < this->nrPreparate) {
            return this->preturi[index];
        }

        throw exception();
    }

    //operator afisare
    friend ostream& operator<<(ostream& out, const Restaurant& r) {
        out << endl << "Restaurant: " << r.nume;
        out << endl << "Id: " << r.id;
        out << endl << "Incasari: " << r.incasari;
        out << endl << "Specific: ";

        if (r.specific == ROMANESC) {
            out << "Romanesc";
        }
        else {
            out << "Italian";
        }

        out << endl << "Nr. preparate: " << r.nrPreparate;

        for (int i = 0; i < r.nrPreparate; i++) {
            out << endl << "Pret preparat " << i + 1
                << ": " << r.preturi[i] << " lei";
        }

        out << endl;
        return out;
    }

    //operator citire
    friend istream& operator>>(istream& in, Restaurant& r) {
        string numeNou;
        float incasariNoi;
        int tipNou;
        int nrNou;

        cout << endl << "Nume restaurant: ";
        in >> numeNou;

        cout << "Incasari: ";
        in >> incasariNoi;

        cout << "Specific (1-Romanesc, 2-Italian): ";
        in >> tipNou;

        cout << "Nr. preparate: ";
        in >> nrNou;

        if (!in || nrNou < 0 || (tipNou != 1 && tipNou != 2)) {
            in.setstate(ios::failbit);
            return in;
        }

        float* valori = nullptr;

        if (nrNou > 0) {
            valori = new float[nrNou];

            for (int i = 0; i < nrNou; i++) {
                cout << "Pret " << i + 1 << ": ";
                in >> valori[i];

                if (!in) {
                    delete[] valori;
                    return in;
                }
            }
        }

        try {
            r.setPreturi(valori, nrNou);
        }
        catch (...) {
            delete[] valori;
            throw;
        }

        delete[] valori;

        r.nume = numeNou;
        r.incasari = incasariNoi;
        r.specific = (Specific)tipNou;

        return in;
    }

    //postincrementare
    Restaurant operator++(int) {
        Restaurant copie = *this;
        this->incasari++;
        return copie;
    }

    //preincrementare
    Restaurant& operator++() {
        this->incasari++;
        return *this;
    }

    //cast explicit
    explicit operator int() const {
        return this->nrPreparate;
    }
};

int Restaurant::nrRestaurante = 0;

int main() {
    Restaurant restaurantGeneral;

    if (!restaurantGeneral) {
        cout << endl << "Nu exista incasari!";
    }
    else {
        cout << endl << "Exista incasari!";
    }

    cout << endl << restaurantGeneral(150);
    cout << restaurantGeneral;

    float preturi[] = { 35.5f, 48.0f, 62.5f };

    Restaurant* restaurantItalia = new Restaurant(
        8, "BellaItalia", 45000, 3, preturi, ITALIAN);

    (*restaurantItalia) += 200;

    if (restaurantGeneral < *restaurantItalia) {
        cout << endl << "Restaurantul general are mai putine preparate!";
    }

    (*restaurantItalia)[0] = 40;

    cout << endl << "Pret primul preparat: "
        << (*restaurantItalia)[0];

    cout << *restaurantItalia;

    //postincrementare
    Restaurant restaurant1 = restaurantGeneral++;
    cout << restaurant1;
    cout << restaurantGeneral;

    //preincrementare
    Restaurant restaurant2 = ++restaurantGeneral;
    cout << restaurant2;
    cout << restaurantGeneral;

    cout << endl << "Numar preparate: "
        << int(*restaurantItalia);

    //constructor copiere si operator =
    Restaurant restaurantCopie(*restaurantItalia);
    restaurantGeneral = restaurantCopie;
    restaurantGeneral.afisare();

    //testare get si set
    restaurantCopie.setNrPreparate(2);

    float preturiNoi[] = { 55.5f, 72.0f };
    restaurantCopie.setPreturi(preturiNoi, 2);

    float* v = restaurantCopie.getPreturi();

    for (int i = 0; i < restaurantCopie.getNrPreparate(); i++) {
        cout << endl << v[i] << " lei";
    }

    delete[] v;
    delete restaurantItalia;

    cout << endl << "Numar restaurante create: "
        << Restaurant::nrRestaurante;

    return 0;
}
