
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

enum TipHotel { URBAN = 1, MONTAN = 2 };

class Hotel {
private:
    const int id;
    TipHotel tip;
    string denumire;
    float incasariTotale;
    int nrCamere;
    float* preturiCamere;

public:
    static int nrHoteluri;

    Hotel() : id(++nrHoteluri) {
        this->denumire = "Hotel general";
        this->incasariTotale = 0;
        this->tip = URBAN;
        this->nrCamere = 0;
        this->preturiCamere = nullptr;
    }

    Hotel(int id, string denumire, float incasariTotale,
        int nrCamere, const float* preturiCamere, TipHotel tip) : id(id) {

        nrHoteluri++;
        this->denumire = denumire;
        this->incasariTotale = incasariTotale;
        this->tip = tip;
        this->nrCamere = 0;
        this->preturiCamere = nullptr;

        setPreturi(preturiCamere, nrCamere);
    }

    //constructor de copiere
    Hotel(const Hotel& copie) : id(++nrHoteluri) {
        this->denumire = copie.denumire;
        this->incasariTotale = copie.incasariTotale;
        this->tip = copie.tip;
        this->nrCamere = 0;
        this->preturiCamere = nullptr;

        setPreturi(copie.preturiCamere, copie.nrCamere);
    }

    //operator de atribuire
    Hotel& operator=(const Hotel& copie) {
        if (this != &copie) {
            setPreturi(copie.preturiCamere, copie.nrCamere);
            this->denumire = copie.denumire;
            this->incasariTotale = copie.incasariTotale;
            this->tip = copie.tip;
        }
        return *this;
    }

    //get si set pentru nrCamere
    int getNrCamere() const {
        return this->nrCamere;
    }

    void setNrCamere(int valoareNoua) {
        if (valoareNoua < 0) {
            throw exception();
        }

        float* vectorNou = nullptr;

        if (valoareNoua > 0) {
            vectorNou = new float[valoareNoua] {};

            int limita = this->nrCamere;
            if (valoareNoua < limita)
                limita = valoareNoua;

            for (int i = 0; i < limita; i++) {
                vectorNou[i] = this->preturiCamere[i];
            }
        }

        delete[] this->preturiCamere;
        this->preturiCamere = vectorNou;
        this->nrCamere = valoareNoua;
    }

    //get si set pentru preturi
    float* getPreturi() const {
        if (this->nrCamere == 0)
            return nullptr;

        float* vPreturi = new float[this->nrCamere];

        for (int i = 0; i < this->nrCamere; i++) {
            vPreturi[i] = this->preturiCamere[i];
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

        delete[] this->preturiCamere;
        this->preturiCamere = vectorNou;
        this->nrCamere = dim;
    }

    void afisare() const {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Incasari totale: " << this->incasariTotale;
        cout << endl << "Tip hotel: ";

        if (this->tip == URBAN)
            cout << "URBAN";
        else
            cout << "MONTAN";

        cout << endl << "Nr. camere: " << this->nrCamere;

        if (this->nrCamere > 0) {
            cout << endl << "Preturi camere: ";

            for (int i = 0; i < this->nrCamere; i++) {
                cout << this->preturiCamere[i] << " lei ";
            }
        }
        cout << endl;
    }

    bool operator<(const Hotel& h) const {
        return this->nrCamere < h.nrCamere;
    }

    ~Hotel() {
        delete[] this->preturiCamere;
    }

    //operator +=
    void operator+=(float suma) {
        this->incasariTotale += suma;
    }

    //operator negatie
    bool operator!() const {
        return this->incasariTotale > 0;
    }

    //operator functie
    float operator()(float suma) const {
        return this->incasariTotale + suma;
    }

    //operator index
    float& operator[](int index) {
        if (index >= 0 && index < this->nrCamere) {
            return this->preturiCamere[index];
        }
        throw exception();
    }

    //operator afisare
    friend ostream& operator<<(ostream& out, const Hotel& h) {
        out << endl << "Hotel: " << h.denumire;
        out << endl << "Id: " << h.id;
        out << endl << "Incasari: " << h.incasariTotale;
        out << endl << "Tip: ";

        if (h.tip == URBAN)
            out << "URBAN";
        else
            out << "MONTAN";

        out << endl << "Nr. camere: " << h.nrCamere;

        for (int i = 0; i < h.nrCamere; i++) {
            out << endl << "Camera " << i + 1
                << ": " << h.preturiCamere[i] << " lei";
        }

        out << endl;
        return out;
    }

    //operator citire
    friend istream& operator>>(istream& in, Hotel& h) {
        float incasari;
        string nume;
        int tipNou;
        int nr;

        cout << endl << "Incasari totale: ";
        in >> incasari;

        cout << "Denumire: ";
        in >> nume;

        cout << "Tip (1-Urban, 2-Montan): ";
        in >> tipNou;

        cout << "Nr. camere: ";
        in >> nr;

        if (!in || (tipNou != 1 && tipNou != 2) || nr < 0) {
            in.setstate(ios::failbit);
            return in;
        }

        float* valori = nullptr;

        if (nr > 0) {
            valori = new float[nr];

            for (int i = 0; i < nr; i++) {
                cout << "Pret camera " << i + 1 << ": ";
                in >> valori[i];

                if (!in) {
                    delete[] valori;
                    return in;
                }
            }
        }

        try {
            h.setPreturi(valori, nr);
        }
        catch (...) {
            delete[] valori;
            throw;
        }

        delete[] valori;

        h.incasariTotale = incasari;
        h.denumire = nume;
        h.tip = (TipHotel)tipNou;

        return in;
    }

    //postincrementare
    Hotel operator++(int) {
        Hotel copie = *this;
        this->incasariTotale++;
        return copie;
    }

    //preincrementare
    Hotel& operator++() {
        this->incasariTotale++;
        return *this;
    }

    //cast explicit
    explicit operator int() const {
        return this->nrCamere;
    }
};

int Hotel::nrHoteluri = 0;

int main() {
    Hotel hotelGeneral;

    if (!hotelGeneral) {
        cout << endl << "Exista incasari!";
    }
    else {
        cout << endl << "Nu exista incasari!";
    }

    cout << endl << hotelGeneral(200);
    cout << hotelGeneral;

    float preturi[] = { 250, 320, 410 };

    Hotel* hotelCentral = new Hotel(
        5, "HotelCentral", 85000, 3, preturi, URBAN);

    (*hotelCentral) += 500;

    if (hotelGeneral < *hotelCentral) {
        cout << endl << "Hotelul general are mai putine camere!";
    }

    (*hotelCentral)[0] = 280;

    cout << endl << "Pret prima camera: "
        << (*hotelCentral)[0];

    cout << *hotelCentral;

    Hotel hotel1 = hotelGeneral++;
    cout << hotel1;
    cout << hotelGeneral;

    Hotel hotel2 = ++hotelGeneral;
    cout << hotel2;
    cout << hotelGeneral;

    cout << endl << "Numar camere: "
        << int(*hotelCentral);

    //testare constructor copiere si operator =
    Hotel hotelCopie(*hotelCentral);
    hotelGeneral = hotelCopie;
    hotelGeneral.afisare();

    //testare get si set
    hotelCopie.setNrCamere(2);
    float preturiNoi[] = { 350, 450 };
    hotelCopie.setPreturi(preturiNoi, 2);

    float* v = hotelCopie.getPreturi();

    for (int i = 0; i < hotelCopie.getNrCamere(); i++) {
        cout << endl << v[i] << " lei";
    }

    delete[] v;
    delete hotelCentral;

    cout << endl << "Numar hoteluri create: "
        << Hotel::nrHoteluri;

    return 0;
}
