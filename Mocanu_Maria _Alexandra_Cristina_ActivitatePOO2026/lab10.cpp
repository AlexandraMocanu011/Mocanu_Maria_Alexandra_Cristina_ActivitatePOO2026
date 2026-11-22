
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// ======================================================
// CERINTA 1 - DEFINIREA CLASEI SI A ATRIBUTELOR (1P)
// ======================================================

class Companie {
private:
    char* numeCompanie;
    const int idCompanie;
    float cifraAfaceri;

public:

    // ==================================================
    // CERINTA 2 - CONSTRUCTOR DEFAULT (2P - IMPREUNA)
    // ==================================================

    Companie() :idCompanie(0) {
        this->numeCompanie = new char[strlen("Necunoscuta") + 1];
        strcpy(this->numeCompanie, "Necunoscuta");

        this->cifraAfaceri = 0;
    }

    // ==================================================
    // CERINTA 2 - CONSTRUCTOR CU UN PARAMETRU
    // ==================================================

    Companie(const char* numeCompanie) :idCompanie(1) {

        if (numeCompanie != nullptr && strlen(numeCompanie) > 0) {
            this->numeCompanie = new char[strlen(numeCompanie) + 1];
            strcpy(this->numeCompanie, numeCompanie);
        }
        else {
            this->numeCompanie = new char[strlen("Necunoscuta") + 1];
            strcpy(this->numeCompanie, "Necunoscuta");
        }

        this->cifraAfaceri = 0;
    }

    // ==================================================
    // CERINTA 3 - GETTER PENTRU ATRIBUTUL CONSTANT (1P)
    // ==================================================

    int getIdCompanie() {
        return this->idCompanie;
    }

    // ==================================================
    // CERINTA 4 - SETTER PENTRU ATRIBUTUL DINAMIC (2P)
    // ==================================================

    void setNumeCompanie(const char* numeNou) {

        if (numeNou != nullptr && strlen(numeNou) > 0) {

            // Alocam mai intai memoria pentru noul nume
            char* copie = new char[strlen(numeNou) + 1];

            // Copiem caracterele
            strcpy(copie, numeNou);

            // Eliberam memoria veche
            delete[] this->numeCompanie;

            // Actualizam pointerul
            this->numeCompanie = copie;
        }

    }

    // ==================================================
    // CERINTA 5 - OPERATORUL DE ATRIBUIRE = (2P)
    // ==================================================

    Companie& operator=(const Companie& c) {

        // Verificam daca obiectul nu se atribuie lui insusi
        if (this != &c) {

            // Alocam memorie pentru noul nume
            char* copie = new char[strlen(c.numeCompanie) + 1];

            // Copiem continutul vectorului
            strcpy(copie, c.numeCompanie);

            // Eliberam memoria veche
            delete[] this->numeCompanie;

            // Actualizam pointerul
            this->numeCompanie = copie;

            // Copiem atributul obisnuit
            this->cifraAfaceri = c.cifraAfaceri;

            // idCompanie NU se modifica deoarece este const
        }

        return *this;
    }

    // ==================================================
    // CERINTA 6 - METODA DE AFISARE (1P)
    // ==================================================

    void afisare() {
        cout << endl << "--------------------------";
        cout << endl << "Id companie: " << this->idCompanie;
        cout << endl << "Nume companie: " << this->numeCompanie;
        cout << endl << "Cifra de afaceri: " << this->cifraAfaceri;
        cout << endl << "--------------------------";
    }

    // ==================================================
    // CERINTA SUPLIMENTARA - CONSTRUCTOR DE COPIERE
    // NECESAR PENTRU COPIEREA SIGURA A OBIECTELOR
    // ==================================================

    Companie(const Companie& c) :idCompanie(c.idCompanie) {

        this->numeCompanie = new char[strlen(c.numeCompanie) + 1];
        strcpy(this->numeCompanie, c.numeCompanie);

        this->cifraAfaceri = c.cifraAfaceri;
    }

    // ==================================================
    // CERINTA SUPLIMENTARA - DESTRUCTOR
    // PREVENIRE MEMORY LEAKS
    // ==================================================

    ~Companie() {
        delete[] this->numeCompanie;
        this->numeCompanie = nullptr;
    }
};


// ======================================================
// FUNCTIA MAIN - TESTAREA TUTUROR CERINTELOR
// ======================================================

int main() {

    // ==================================================
    // TEST 1 - CONSTRUCTOR DEFAULT
    // ==================================================

    Companie c1;

    cout << endl << "TEST CONSTRUCTOR DEFAULT";
    c1.afisare();


    // ==================================================
    // TEST 2 - CONSTRUCTOR CU UN PARAMETRU
    // ==================================================

    Companie c2("Microsoft");

    cout << endl << "TEST CONSTRUCTOR CU UN PARAMETRU";
    c2.afisare();


    // ==================================================
    // TEST 3 - GETTER ATRIBUT CONSTANT
    // ==================================================

    cout << endl << "TEST GETTER";
    cout << endl << "ID companie c2: " << c2.getIdCompanie();


    // ==================================================
    // TEST 4 - SETTER ATRIBUT DINAMIC
    // ==================================================

    cout << endl << "TEST SETTER";

    c2.setNumeCompanie("Google");

    c2.afisare();


    // ==================================================
    // TEST 5 - OPERATORUL =
    // ==================================================

    cout << endl << "TEST OPERATOR =";

    c1 = c2;

    c1.afisare();


    // ==================================================
    // TEST 6 - AUTOATRIBUIRE
    // ==================================================

    cout << endl << "TEST AUTOATRIBUIRE";

    c1 = c1;

    c1.afisare();


    // ==================================================
    // TEST 7 - CONSTRUCTOR DE COPIERE
    // ==================================================

    cout << endl << "TEST CONSTRUCTOR DE COPIERE";

    Companie c3(c2);

    c3.afisare();


    // ==================================================
    // TEST 8 - VERIFICARE COPIERE PROFUNDA
    // ==================================================

    cout << endl << "TEST DEEP COPY";

    c2.setNumeCompanie("Amazon");

    cout << endl << "Obiectul c2 modificat:";
    c2.afisare();

    cout << endl << "Obiectul c3 ramane nemodificat:";
    c3.afisare();


    // ==================================================
    // TEST 9 - OBIECT ALOCAT DINAMIC SI DESTRUCTOR
    // ==================================================

    cout << endl << "TEST OBIECT DINAMIC";

    Companie* c4 = new Companie("Oracle");

    c4->afisare();

    delete c4;
    c4 = nullptr;


    // Obiectele c1, c2 si c3 vor fi distruse automat
    // la finalul functiei main().

    return 0;
}
