#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<cstring>
#include<string>

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
        else {
            marca = nullptr;
        }

        if (m.model != nullptr) {
            model = new char[strlen(m.model) + 1];
            strcpy(model, m.model);
        }
        else {
            model = nullptr;
        }

        anFabricatie = m.anFabricatie;
        pret = m.pret;
        esteNoua = m.esteNoua;
    }

    ~Masina() {
        if (marca != nullptr) {
            delete[] marca;
        }
        if (model != nullptr) {
            delete[] model;
        }
    }

    int getIdMasina() {
        return idMasina;
    }

    static int getNrMasini() {
        return nrMasini;
    }

    const char* getMarca() {
        return marca;
    }

    const char* getModel() {
        return model;
    }

    int getAnFabricatie() {
        return anFabricatie;
    }

    float getPret() {
        return pret;
    }

    bool getEsteNoua() {
        return esteNoua;
    }

    void setMarca(const char* marcaNoua) {
        if (marcaNoua != nullptr && strlen(marcaNoua) > 0) {
            if (marca != nullptr) {
                delete[] marca;
            }
            marca = new char[strlen(marcaNoua) + 1];
            strcpy(marca, marcaNoua);
        }
    }

    void setModel(const char* modelNou) {
        if (modelNou != nullptr && strlen(modelNou) > 0) {
            if (model != nullptr) {
                delete[] model;
            }
            model = new char[strlen(modelNou) + 1];
            strcpy(model, modelNou);
        }
    }

    void setAnFabricatie(int an) {
        if (an > 0) {
            anFabricatie = an;
        }
    }

    void setPret(float pretNou) {
        if (pretNou >= 0) {
            pret = pretNou;
        }
    }

    void setEsteNoua(bool esteNouaNoua) {
        esteNoua = esteNouaNoua;
    }

    static float aplicaDiscount(float pretInitial, float procent) {
        return pretInitial * (1 - procent / 100.0f);
    }

    void afisareMasina() {
        cout << endl << idMasina << ". Masina ";
        if (marca != nullptr) {
            cout << marca;
        }
        else {
            cout << "Nespecificata";
        }

        cout << " " << (model != nullptr ? model : "N/A");
        cout << ", anul " << anFabricatie;
        cout << ", pret " << pret << " EUR";
        cout << ", " << (esteNoua ? "NOUA" : "SH");
        cout << ".";
    }

    // operator = (de atribuire)
    void operator=(const Masina& m) {
        this->anFabricatie = m.anFabricatie;
        this->pret = m.pret;
        this->esteNoua = m.esteNoua;

        if (this->marca != nullptr) {
            delete[] this->marca;
            this->marca = nullptr;
        }
        if (m.marca != nullptr) {
            this->marca = new char[strlen(m.marca) + 1];
            strcpy(this->marca, m.marca);
        }
        else {
            this->marca = nullptr;
        }

        if (this->model != nullptr) {
            delete[] this->model;
            this->model = nullptr;
        }
        if (m.model != nullptr) {
            this->model = new char[strlen(m.model) + 1];
            strcpy(this->model, m.model);
        }
        else {
            this->model = nullptr;
        }
    }

    // comparatie dupa pret
    bool operator<(const Masina& m) {
        return this->pret < m.pret;
    }

    friend float valoareTotalaMasiniNoi(Masina* masini, int nr);
};

int Masina::nrMasini = 0;


/* CLASA MOTOCICLETA */

enum TipMotocicleta { SPORT = 1, TOURING = 2, SCOOTER = 3 };

class Motocicleta {
private:
    const int idMotocicleta;
    static int nrMotociclete;

    char* marca;
    char* model;
    int nrKm;
    TipMotocicleta tip;

public:
    Motocicleta() : idMotocicleta(++nrMotociclete) {
        marca = new char[strlen("Necunoscuta") + 1];
        strcpy(marca, "Necunoscuta");

        model = new char[strlen("N/A") + 1];
        strcpy(model, "N/A");

        nrKm = 0;
        tip = SPORT;
    }

    Motocicleta(const char* marca, const char* model) : idMotocicleta(++nrMotociclete) {
        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);

        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);

        nrKm = 0;
        tip = SPORT;
    }

    Motocicleta(const char* marca, const char* model, int nrKm, TipMotocicleta tip)
        : idMotocicleta(++nrMotociclete) {
        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);

        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);

        this->nrKm = nrKm;
        this->tip = tip;
    }

    Motocicleta(const Motocicleta& m) : idMotocicleta(++nrMotociclete) {
        if (m.marca != nullptr) {
            marca = new char[strlen(m.marca) + 1];
            strcpy(marca, m.marca);
        }
        else {
            marca = nullptr;
        }

        if (m.model != nullptr) {
            model = new char[strlen(m.model) + 1];
            strcpy(model, m.model);
        }
        else {
            model = nullptr;
        }

        nrKm = m.nrKm;
        tip = m.tip;
    }

    ~Motocicleta() {
        if (marca != nullptr) {
            delete[] marca;
        }
        if (model != nullptr) {
            delete[] model;
        }
    }

    int getIdMotocicleta() {
        return idMotocicleta;
    }

    static int getNrMotociclete() {
        return nrMotociclete;
    }

    const char* getMarca() {
        return marca;
    }

    const char* getModel() {
        return model;
    }

    int getNrKm() {
        return nrKm;
    }

    TipMotocicleta getTip() {
        return tip;
    }

    void setMarca(const char* marcaNoua) {
        if (marcaNoua != nullptr && strlen(marcaNoua) > 0) {
            if (marca != nullptr) {
                delete[] marca;
            }
            marca = new char[strlen(marcaNoua) + 1];
            strcpy(marca, marcaNoua);
        }
    }

    void setModel(const char* modelNou) {
        if (modelNou != nullptr && strlen(modelNou) > 0) {
            if (model != nullptr) {
                delete[] model;
            }
            model = new char[strlen(modelNou) + 1];
            strcpy(model, modelNou);
        }
    }

    void setNrKm(int km) {
        if (km >= 0) {
            nrKm = km;
        }
    }

    void setTip(TipMotocicleta tipNou) {
        tip = tipNou;
    }

    static int kilometriMediu(int km1, int km2) {
        return (km1 + km2) / 2;
    }

    void afisareMotocicleta() {
        cout << endl << idMotocicleta << ". Motocicleta ";
        if (marca != nullptr) {
            cout << marca;
        }
        else {
            cout << "Nespecificata";
        }
        cout << " " << (model != nullptr ? model : "N/A");
        cout << " are " << nrKm << " km, tip ";
        if (tip == SPORT) {
            cout << "SPORT";
        }
        else if (tip == TOURING) {
            cout << "TOURING";
        }
        else {
            cout << "SCOOTER";
        }
        cout << ".";
    }

    // operator = (de atribuire)
    void operator=(const Motocicleta& m) {
        this->nrKm = m.nrKm;
        this->tip = m.tip;

        if (this->marca != nullptr) {
            delete[] this->marca;
            this->marca = nullptr;
        }
        if (m.marca != nullptr) {
            this->marca = new char[strlen(m.marca) + 1];
            strcpy(this->marca, m.marca);
        }
        else {
            this->marca = nullptr;
        }

        if (this->model != nullptr) {
            delete[] this->model;
            this->model = nullptr;
        }
        if (m.model != nullptr) {
            this->model = new char[strlen(m.model) + 1];
            strcpy(this->model, m.model);
        }
        else {
            this->model = nullptr;
        }
    }

    // comparatie dupa nrKm
    bool operator<(const Motocicleta& m) {
        return this->nrKm < m.nrKm;
    }
};

int Motocicleta::nrMotociclete = 0;


/* CLASA CLIENT */

class Client {
private:
    const int idClient;
    static int nrClienti;

    char* nume;
    int varsta;
    char* oras;
    bool esteFidel;

public:
    Client() : idClient(++nrClienti) {
        nume = new char[strlen("Anonim") + 1];
        strcpy(nume, "Anonim");

        oras = new char[strlen("Necunoscut") + 1];
        strcpy(oras, "Necunoscut");

        varsta = 0;
        esteFidel = false;
    }

    Client(const char* nume) : idClient(++nrClienti) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        oras = new char[strlen("Necunoscut") + 1];
        strcpy(oras, "Necunoscut");

        varsta = 0;
        esteFidel = false;
    }

    Client(const char* nume, int varsta, const char* oras, bool esteFidel)
        : idClient(++nrClienti) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        this->oras = new char[strlen(oras) + 1];
        strcpy(this->oras, oras);

        this->varsta = varsta;
        this->esteFidel = esteFidel;
    }

    Client(const Client& c) : idClient(++nrClienti) {
        if (c.nume != nullptr) {
            nume = new char[strlen(c.nume) + 1];
            strcpy(nume, c.nume);
        }
        else {
            nume = nullptr;
        }

        if (c.oras != nullptr) {
            oras = new char[strlen(c.oras) + 1];
            strcpy(oras, c.oras);
        }
        else {
            oras = nullptr;
        }

        varsta = c.varsta;
        esteFidel = c.esteFidel;
    }

    ~Client() {
        if (nume != nullptr) {
            delete[] nume;
        }
        if (oras != nullptr) {
            delete[] oras;
        }
    }

    int getIdClient() {
        return idClient;
    }

    static int getNrClienti() {
        return nrClienti;
    }

    const char* getNume() {
        return nume;
    }

    int getVarsta() {
        return varsta;
    }

    const char* getOras() {
        return oras;
    }

    bool getEsteFidel() {
        return esteFidel;
    }

    void setNume(const char* numeNou) {
        if (numeNou != nullptr && strlen(numeNou) > 0) {
            if (nume != nullptr) {
                delete[] nume;
            }
            nume = new char[strlen(numeNou) + 1];
            strcpy(nume, numeNou);
        }
    }

    void setVarsta(int varstaNoua) {
        if (varstaNoua >= 0) {
            varsta = varstaNoua;
        }
    }

    void setOras(const char* orasNou) {
        if (orasNou != nullptr && strlen(orasNou) > 0) {
            if (oras != nullptr) {
                delete[] oras;
            }
            oras = new char[strlen(orasNou) + 1];
            strcpy(oras, orasNou);
        }
    }

    void setEsteFidel(bool esteFidelNou) {
        esteFidel = esteFidelNou;
    }

    static float procentClientiFideli(int nrFideli, int total) {
        if (total > 0) {
            return (float)nrFideli * 100 / total;
        }
        return 0;
    }

    void afisareClient() {
        cout << endl << idClient << ". Clientul ";
        if (nume != nullptr) {
            cout << nume;
        }
        else {
            cout << "Neidentificat";
        }
        cout << ", varsta " << varsta;
        cout << ", oras " << (oras != nullptr ? oras : "Necunoscut");
        cout << ", " << (esteFidel ? "FIDEL" : "nefidel");
        cout << ".";
    }

    // operator = (de atribuire)
    void operator=(const Client& c) {
        this->varsta = c.varsta;
        this->esteFidel = c.esteFidel;

        if (this->nume != nullptr) {
            delete[] this->nume;
            this->nume = nullptr;
        }
        if (c.nume != nullptr) {
            this->nume = new char[strlen(c.nume) + 1];
            strcpy(this->nume, c.nume);
        }
        else {
            this->nume = nullptr;
        }

        if (this->oras != nullptr) {
            delete[] this->oras;
            this->oras = nullptr;
        }
        if (c.oras != nullptr) {
            this->oras = new char[strlen(c.oras) + 1];
            strcpy(this->oras, c.oras);
        }
        else {
            this->oras = nullptr;
        }
    }

    // comparatie dupa varsta
    bool operator<(const Client& c) {
        return this->varsta < c.varsta;
    }

    friend int numarClientiFideliDinOras(Client* clienti, int nr, const char* orasCautat);
};

int Client::nrClienti = 0;


/* FUNCTII PRIETENE FAZA 2 */

float valoareTotalaMasiniNoi(Masina* masini, int nr) {
    float suma = 0;
    for (int i = 0; i < nr; i++) {
        if (masini[i].esteNoua) {
            suma += masini[i].pret;
        }
    }
    return suma;
}

int numarClientiFideliDinOras(Client* clienti, int nr, const char* orasCautat) {
    int contor = 0;
    for (int i = 0; i < nr; i++) {
        if (clienti[i].esteFidel &&
            clienti[i].oras != nullptr &&
            strcmp(clienti[i].oras, orasCautat) == 0) {
            contor++;
        }
    }
    return contor;
}


/* MAIN */

void main() {

    cout << "Proiect POO - Faza 3 - Commit 3 (operator= si operator<)" << endl;

    // MASINI
    Masina m1;
    Masina m2("Dacia");
    Masina m3("Audi", "A4", 2019, 18500, false);
    Masina m4(m3);

    m3.setEsteNoua(true);

    Masina m5;
    m5 = m3; // test operator= pentru Masina

    m1.afisareMasina();
    m2.afisareMasina();
    m3.afisareMasina();
    m4.afisareMasina();
    m5.afisareMasina();

    cout << endl << "Pret m3 cu 10% discount: "
        << Masina::aplicaDiscount(m3.getPret(), 10);

    cout << endl << "Numar masini create: " << Masina::getNrMasini();

    Masina vectorMasini[4] = { m1, m2, m3, m4 };
    cout << endl << "Valoare masini noi: "
        << valoareTotalaMasiniNoi(vectorMasini, 4);

    if (m2 < m3) {
        cout << endl << "Masina m2 este mai ieftina decat masina m3.";
    }
    else {
        cout << endl << "Masina m3 este mai ieftina sau egala ca pret cu masina m2.";
    }


    // MOTOCICLETE
    Motocicleta moto1;
    Motocicleta moto2("Honda", "CBR");
    Motocicleta moto3("Yamaha", "MT-07", 12000, SPORT);
    Motocicleta moto4(moto3);

    Motocicleta moto5;
    moto5 = moto3; // test operator= pentru Motocicleta

    moto1.afisareMotocicleta();
    moto2.afisareMotocicleta();
    moto3.afisareMotocicleta();
    moto4.afisareMotocicleta();
    moto5.afisareMotocicleta();

    cout << endl << "Kilometri medii (moto3 & moto4): "
        << Motocicleta::kilometriMediu(moto3.getNrKm(), moto4.getNrKm());
    cout << endl << "Numar motociclete create: " << Motocicleta::getNrMotociclete();

    if (moto1 < moto3) {
        cout << endl << "Motocicleta moto1 are mai putini kilometri decat moto3.";
    }
    else {
        cout << endl << "Motocicleta moto3 are mai putini sau egali kilometri fata de moto1.";
    }


    // CLIENTI
    Client c1;
    Client c2("Alexandra");
    Client c3("Marius", 25, "Bucuresti", true);
    Client c4(c3);

    c2.setOras("Cluj");
    c2.setVarsta(21);

    Client c5;
    c5 = c3; // test operator= pentru Client

    c1.afisareClient();
    c2.afisareClient();
    c3.afisareClient();
    c4.afisareClient();
    c5.afisareClient();

    cout << endl << "Numar clienti creati: "
        << Client::getNrClienti();

    cout << endl << "Procent clienti fideli (2 din 4): "
        << Client::procentClientiFideli(2, 4) << "%";

    Client vectorClienti[4] = { c1, c2, c3, c4 };

    cout << endl << "Clienti fideli din Bucuresti: "
        << numarClientiFideliDinOras(vectorClienti, 4, "Bucuresti");

    if (c2 < c3) {
        cout << endl << "Clientul c2 este mai tanar decat clientul c3.";
    }
    else {
        cout << endl << "Clientul c3 este mai tanar sau de aceeasi varsta cu clientul c2.";
    }

    cout << endl << endl << " Commit 3." << endl;
}
