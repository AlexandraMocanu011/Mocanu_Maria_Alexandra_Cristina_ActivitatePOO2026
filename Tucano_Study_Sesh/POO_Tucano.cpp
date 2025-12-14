#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class ContBancar {
private:
    char* titular;
    float* tranzactii;
    const int maxTranzactii;
    static int NrConturi;
    int n;
    float sold;

public:
    // constructor fara parametrii
    ContBancar() : maxTranzactii(100), sold(0.0f) {
        titular = nullptr;
        tranzactii = nullptr;
        NrConturi++;
        sold = 0.0f;
        n = 0;
    }

    // Constructor cu parametri
    ContBancar(const char* nume, const float* trx, int nrTrx, int maxTrx, float soldInitial, int dim)
        : maxTranzactii(maxTrx)
    {
        NrConturi++;

        titular = new char[strlen(nume) + 1];
        strcpy(titular, nume);

        tranzactii = new float[maxTranzactii];

        n = dim;
        if (n > maxTranzactii) n = maxTranzactii;
        if (n > nrTrx) n = nrTrx;

        for (int i = 0; i < n; i++) {
            tranzactii[i] = trx[i];
        }

        sold = soldInitial;
    }

    // Constructor de copiere
    ContBancar(const ContBancar& c) : maxTranzactii(c.maxTranzactii) {
        NrConturi++;

        titular = new char[strlen(c.titular) + 1];
        strcpy(titular, c.titular);

        tranzactii = new float[c.n];
        for (int i = 0; i < c.n; i++) {
            tranzactii[i] = c.tranzactii[i];
        }

        n = c.n;
        sold = c.sold;
    }
     //operator =
    ContBancar operator=(const ContBancar& c) {
        if (this == &c) return *this;
        delete[]titular;
        delete[] tranzactii;
        titular = new char[strlen(c.titular) + 1];
        strcpy(titular, c.titular);
        tranzactii = new float[c.n];
        for (int i = 0; i < c.n; i++) {
            tranzactii[i] = c.tranzactii[i];
        }
        n = c.n;
        sold = c.sold;
        return *this;
    }
    //getteri
    const char* getTitular() const {
        return titular;
    }
    const float* getTranzactii() const {
        return tranzactii;
    }
    const int getMaxTranzactii() const {
        return maxTranzactii;
   }
    static int getNrConturi() {
        return NrConturi;
    }
    float getSold() const {
        return sold;
     } 
    int getN() const {
        return n;
    }
    //setteri
    void setTitular(const char* nume) {
        delete[] titular;
        if (nume == nullptr) {
            titular = nullptr;
            return;
        }
        titular = new char[strlen(nume) + 1];
        strcpy(titular, nume);
    }
    void setTranzactii(const float* trx, int dim) {
        delete[] tranzactii;

        if (trx == nullptr || dim <= 0) {
            tranzactii = nullptr;
            n = 0;
            return;
        }

        n = dim;
        if (n > maxTranzactii) n = maxTranzactii;

        tranzactii = new float[n];
        for (int i = 0; i < n; i++) {
            tranzactii[i] = trx[i];
        }
    }
    void setSold(float s) {
        sold = s;

    }
    //destructor
     ~ContBancar() {
        delete[] titular;
        delete[] tranzactii;
    }
};

int ContBancar::NrConturi = 0;

int main() {
    return 0;
}
