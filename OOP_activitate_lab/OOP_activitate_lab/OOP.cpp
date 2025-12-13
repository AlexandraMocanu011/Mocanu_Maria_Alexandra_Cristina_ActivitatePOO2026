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

    // operator += (mareste pretul)
    void operator+=(float valoare) {
        this->pret += valoare;
    }

    // operator ! (true daca masina NU este noua)
    bool operator!() {
        return !this->esteNoua;
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

    // operator += (creste numarul de km)
    void operator+=(int km) {
        this->nrKm += km;
    }

    // operator ! (true daca are 0 km)
    bool operator!() {
        return this->nrKm == 0;
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

    // operator += (creste varsta)
    void operator+=(int ani) {
        this->varsta += ani;
    }

    // operator ! (true daca NU este fidel)
    bool operator!() {
        return !this->esteFidel;
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

    cout << "Proiect POO - Faza 3 - Commit 4 (operatori ! si +=)" << endl;

    // MASINI
    Masina m1;
    Masina m2("Dacia");
    Masina m3("Audi", "A4", 2019, 18500, false);
    Masina m4(m3);

    m3.setEsteNoua(true);

    Masina m5;
    m5 = m3; // operator= Masina

    m2 += 1000; // operator+= Masina

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

    if (!m1) {
        cout << endl << "Masina m1 NU este noua.";
    }
    else {
        cout << endl << "Masina m1 este noua.";
    }


    // MOTOCICLETE
    Motocicleta moto1;
    Motocicleta moto2("Honda", "CBR");
    Motocicleta moto3("Yamaha", "MT-07", 12000, SPORT);
    Motocicleta moto4(moto3);

    Motocicleta moto5;
    moto5 = moto3; // operator= Motocicleta

    moto2 += 500; // operator+= Motocicleta

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

    if (!moto1) {
        cout << endl << "Motocicleta moto1 are 0 km.";
    }
    else {
        cout << endl << "Motocicleta moto1 are cel putin 1 km.";
    }


    // CLIENTI
    Client c1;
    Client c2("Alexandra");
    Client c3("Marius", 25, "Bucuresti", true);
    Client c4(c3);

    c2.setOras("Cluj");
    c2.setVarsta(21);

    Client c5;
    c5 = c3; // operator= Client

    c1 += 5; // operator+= Client (creste varsta lui c1 cu 5 ani)

    c1.afisareClient();
    c2.afisareClient();
    c3.afisareClient();
    c4.afisareClient();
    c5.afisareClient();

    cout << endl << "Numar clienti creati: "
        << Client::getNrClienti();

    cout << endl << "Procent clienti fideli (2 din 5): "
        << Client::procentClientiFideli(2, 5) << "%";

    Client vectorClienti[4] = { c1, c2, c3, c4 };

    cout << endl << "Clienti fideli din Bucuresti: "
        << numarClientiFideliDinOras(vectorClienti, 4, "Bucuresti");

    if (c2 < c3) {
        cout << endl << "Clientul c2 este mai tanar decat clientul c3.";
    }
    else {
        cout << endl << "Clientul c3 este mai tanar sau de aceeasi varsta cu clientul c2.";
    }

    if (!c1) {
        cout << endl << "Clientul c1 NU este fidel.";
    }
    else {
        cout << endl << "Clientul c1 este fidel.";
    }

    cout << endl << endl << "Sfarsit Faza 3 - Commit 4." << endl;


    /* ================== FAZA 4 – VECTORI SI MATRICE (COMMIT 5) ================== */

    cout << endl << endl << "Faza 4 – vectori si matrice (Commit 5)" << endl;

    // ----------------- VECTOR MASINI -----------------

    int nrMasiniVector;
    cout << endl << "Numar masini in vector: ";
    cin >> nrMasiniVector;
    cin.ignore();

    if (nrMasiniVector <= 0) {
        cout << "Numar invalid!" << endl;
        return;
    }

    Masina* vectMasini = new Masina[nrMasiniVector];

    for (int i = 0; i < nrMasiniVector; i++) {

        char marca[100], model[100];
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

    cout << endl << "Vector masini (Faza 4):" << endl;
    for (int i = 0; i < nrMasiniVector; i++) {
        vectMasini[i].afisareMasina();
    }

    // ----------------- VECTOR MOTOCICLETE -----------------

    int nrMoto;
    cout << endl << endl << "Numar motociclete in vector: ";
    cin >> nrMoto;
    cin.ignore();

    if (nrMoto <= 0) {
        cout << "Numar invalid!" << endl;
        delete[] vectMasini;
        return;
    }

    Motocicleta* vectMoto = new Motocicleta[nrMoto];

    for (int i = 0; i < nrMoto; i++) {

        char marcaMoto[100], modelMoto[100];
        int km;
        int tip;

        cout << endl << "Moto " << i + 1 << " - marca: ";
        cin >> marcaMoto;

        cout << "Moto " << i + 1 << " - model: ";
        cin >> modelMoto;

        cout << "Moto " << i + 1 << " - km: ";
        cin >> km;

        cout << "Moto " << i + 1 << " - tip (1-SPORT, 2-TOURING, 3-SCOOTER): ";
        cin >> tip;

        vectMoto[i].setMarca(marcaMoto);
        vectMoto[i].setModel(modelMoto);
        vectMoto[i].setNrKm(km);
        vectMoto[i].setTip((TipMotocicleta)tip);
    }

    cout << endl << "Vector motociclete (Faza 4):" << endl;
    for (int i = 0; i < nrMoto; i++) {
        vectMoto[i].afisareMotocicleta();
    }

    delete[] vectMasini;
    delete[] vectMoto;

    cout << endl << endl << "Sfarsit Faza 4 - Commit 5." << endl;


    /* ================== FAZA 5 – MATRICE + PRELUCRARE (COMMIT 6) ================== */

    cout << endl << endl << "Faza 5 - matrice + prelucrare (Commit 6)" << endl;

    Masina matriceMasini[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            char marcaM[100], modelM[100];
            int an;
            float pret;
            int esteNoua;

            cout << endl << "Matrice masini [" << i << "][" << j << "] - marca: ";
            cin >> marcaM;

            cout << "Matrice masini [" << i << "][" << j << "] - model: ";
            cin >> modelM;

            cout << "Matrice masini [" << i << "][" << j << "] - an fabricatie: ";
            cin >> an;

            cout << "Matrice masini [" << i << "][" << j << "] - pret: ";
            cin >> pret;

            cout << "Matrice masini [" << i << "][" << j << "] - este noua? (1-DA / 0-NU): ";
            cin >> esteNoua;

            matriceMasini[i][j].setMarca(marcaM);
            matriceMasini[i][j].setModel(modelM);
            matriceMasini[i][j].setAnFabricatie(an);
            matriceMasini[i][j].setPret(pret);
            matriceMasini[i][j].setEsteNoua(esteNoua == 1);
        }
    }

    cout << endl << "Afisare matrice masini (Commit 6):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matriceMasini[i][j].afisareMasina();
        }
        cout << endl;
    }

    // Prelucrare 1: numar ensures
    int nrMasiniNoiMatrice = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (matriceMasini[i][j].getEsteNoua()) {
                nrMasiniNoiMatrice++;
            }
        }
    }
    cout << endl << "Numar masini noi in matrice: " << nrMasiniNoiMatrice;

    // Prelucrare 2: masina cu pret maxim
    int pozI = 0, pozJ = 0;
    float pretMax = matriceMasini[0][0].getPret();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (matriceMasini[i][j].getPret() > pretMax) {
                pretMax = matriceMasini[i][j].getPret();
                pozI = i;
                pozJ = j;
            }
        }
    }

    cout << endl << "Masina cu pret maxim este la pozitia [" << pozI << "][" << pozJ << "]:";
    matriceMasini[pozI][pozJ].afisareMasina();

    cout << endl << endl << "Sfarsit Faza 5 - Commit 6." << endl;
}
