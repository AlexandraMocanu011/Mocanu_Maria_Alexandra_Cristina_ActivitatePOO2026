//Pregatire test 


#include<iostream>
#include<string>
#include<exception>

using namespace std;

// ======================================================
// CERINTA 2 - DEFINIREA CLASEI STUDENT
// ======================================================

class Student {
private:
    const int id;
    string nume;
    int nota;
    int nrMaterii;
    string* materii;
    float medie;

public:
    // Atribut static - comun tuturor obiectelor
    static int nrStudenti;

    // ==================================================
    // CERINTA 3 - CONSTRUCTOR FARA PARAMETRI
    // ==================================================

    Student() :id(++nrStudenti) {
        this->nume = "Student necunoscut";
        this->nota = 1;
        this->nrMaterii = 0;
        this->materii = nullptr;
        this->medie = 1;
    }

    // ==================================================
    // CERINTA 3 - CONSTRUCTOR CU PARAMETRI
    // ==================================================

    Student(int id, string nume, int nota,
        int nrMaterii, string* materii, float medie)
        :id(id) {

        nrStudenti++;

        this->nume = nume;

        // Validare nota
        if (nota >= 1 && nota <= 10) {
            this->nota = nota;
        }
        else {
            this->nota = 1;
        }

        // Validare medie
        if (medie >= 1 && medie <= 10) {
            this->medie = medie;
        }
        else {
            this->medie = 1;
        }

        // Validare numar materii
        if (nrMaterii > 0 && materii != nullptr) {
            this->nrMaterii = nrMaterii;

            // Alocare dinamica
            this->materii = new string[this->nrMaterii];

            // Copiere element cu element
            for (int i = 0; i < this->nrMaterii; i++) {
                this->materii[i] = materii[i];
            }
        }
        else {
            this->nrMaterii = 0;
            this->materii = nullptr;
        }
    }

    // ==================================================
    // CERINTA 4 - METODA DE AFISARE
    // ==================================================

    void afisare() {
        cout << endl << "--------------------------";
        cout << endl << "Id: " << this->id;
        cout << endl << "Nume: " << this->nume;
        cout << endl << "Nota: " << this->nota;
        cout << endl << "Medie: " << this->medie;
        cout << endl << "Nr materii: " << this->nrMaterii;

        if (this->nrMaterii > 0 && this->materii != nullptr) {
            cout << endl << "Materii: ";

            for (int i = 0; i < this->nrMaterii; i++) {
                cout << this->materii[i];

                if (i < this->nrMaterii - 1) {
                    cout << ", ";
                }
            }
        }

        cout << endl << "--------------------------";
    }

    // ==================================================
    // CERINTA 5 - DESTRUCTOR
    // ==================================================

    ~Student() {
        cout << endl << "S-a apelat destructorul!";

        if (this->materii != nullptr) {
            delete[] this->materii;
            this->materii = nullptr;
        }
    }

    // ==================================================
    // CERINTA 6 - CONSTRUCTOR DE COPIERE
    // ==================================================

    Student(const Student& copie) :id(++nrStudenti) {

        this->nume = copie.nume;
        this->nota = copie.nota;
        this->nrMaterii = copie.nrMaterii;
        this->medie = copie.medie;

        // Deep copy pentru vectorul dinamic
        if (copie.materii != nullptr && this->nrMaterii > 0) {

            this->materii = new string[this->nrMaterii];

            for (int i = 0; i < this->nrMaterii; i++) {
                this->materii[i] = copie.materii[i];
            }
        }
        else {
            this->nrMaterii = 0;
            this->materii = nullptr;
        }
    }

    // ==================================================
    // CERINTA 7 - GETTERI SI SETTERI
    // ==================================================

    // Getter pentru nume
    string getNume() {
        return this->nume;
    }

    // Setter pentru nume
    void setNume(string numeNou) {
        if (numeNou.length() > 0) {
            this->nume = numeNou;
        }
    }

    // Getter pentru nota
    int getNota() {
        return this->nota;
    }

    // Setter pentru nota
    void setNota(int notaNoua) {
        if (notaNoua >= 1 && notaNoua <= 10) {
            this->nota = notaNoua;
        }
        else {
            throw exception("Nota invalida!");
        }
    }

    // Getter pentru medie
    float getMedie() {
        return this->medie;
    }

    // Setter pentru medie
    void setMedie(float medieNoua) {
        if (medieNoua >= 1 && medieNoua <= 10) {
            this->medie = medieNoua;
        }
        else {
            throw exception("Media invalida!");
        }
    }

    // ==================================================
    // CERINTA 8 - OPERATORUL DE ATRIBUIRE =
    // ==================================================

    Student& operator=(const Student& copie) {

        // Verificare autoatribuire
        if (this != &copie) {

            this->nume = copie.nume;
            this->nota = copie.nota;
            this->medie = copie.medie;

            // Eliberarea memoriei vechi
            if (this->materii != nullptr) {
                delete[] this->materii;
                this->materii = nullptr;
            }

            this->nrMaterii = copie.nrMaterii;

            // Deep copy
            if (copie.materii != nullptr && this->nrMaterii > 0) {

                this->materii = new string[this->nrMaterii];

                for (int i = 0; i < this->nrMaterii; i++) {
                    this->materii[i] = copie.materii[i];
                }
            }
            else {
                this->nrMaterii = 0;
                this->materii = nullptr;
            }

            // id NU se modifica deoarece este const
        }

        return *this;
    }
};

// ======================================================
// INITIALIZAREA ATRIBUTULUI STATIC
// ======================================================

int Student::nrStudenti = 0;


// ======================================================
// CERINTA 9 - TESTAREA IN MAIN()
// ======================================================

int main() {

    // ==================================================
    // 1. APEL CONSTRUCTOR FARA PARAMETRI
    // ==================================================

    Student studentGeneral;
    studentGeneral.afisare();


    // ==================================================
    // 2. APEL CONSTRUCTOR CU PARAMETRI
    // ==================================================

    string* materii = new string[3]{
        "POO", "Baze de date", "Matematica"
    };

    Student student1(10, "Alexandra", 9, 3, materii, 9.5);

    student1.afisare();

    // Constructorul a copiat vectorul.
    // Eliberam vectorul original din main.
    delete[] materii;


    // ==================================================
    // 3. APEL GETTERI
    // ==================================================

    cout << endl << "Nume: " << student1.getNume();
    cout << endl << "Nota: " << student1.getNota();
    cout << endl << "Medie: " << student1.getMedie();


    // ==================================================
    // 4. APEL SETTERI
    // ==================================================

    student1.setNume("Maria");
    student1.setNota(10);
    student1.setMedie(9.8f);

    student1.afisare();


    // ==================================================
    // 5. TESTAREA VALIDARILOR SI EXCEPTIILOR
    // ==================================================

    try {
        student1.setNota(15);
    }
    catch (const exception& e) {
        cout << endl << "Eroare: " << e.what();
    }

    try {
        student1.setMedie(12);
    }
    catch (const exception& e) {
        cout << endl << "Eroare: " << e.what();
    }


    // ==================================================
    // 6. APEL CONSTRUCTOR DE COPIERE
    // ==================================================

    Student student2(student1);

    student2.afisare();


    // ==================================================
    // 7. APEL OPERATOR DE ATRIBUIRE =
    // ==================================================

    Student student3;

    student3 = student1;

    student3.afisare();


    // ==================================================
    // 8. TESTAREA AUTOATRIBUIRII
    // ==================================================

    student3 = student3;

    student3.afisare();


    // ==================================================
    // 9. AFISAREA ATRIBUTULUI STATIC
    // ==================================================

    cout << endl << "Numar studenti creati: "
        << Student::nrStudenti;


    // ==================================================
    // 10. TESTAREA DESTRUCTORULUI
    // ==================================================

    Student* studentDinamic = new Student();

    studentDinamic->afisare();

    delete studentDinamic;

    // Obiectele locale sunt distruse automat
    // la iesirea din main().

    return 0;
}
