#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include<string>

using namespace std;

/*  CLASA MASINA */

class Masina {
public:
	const int idMasina;
	static int nrMasini;

	char* marca;
	char* model;
	int anFabricatie;
	float pret;
	bool esteNoua;

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

	static float aplicaDiscount(float pretInitial, float procent) {
		return pretInitial * (1 - procent / 100.0f);
	}

	void afisareMasina() {
		cout << endl << this->idMasina << ". Masina ";
		if (this->marca != nullptr) {
			cout << this->marca;
		}
		else {
			cout << "Nespecificata";
		}

		cout << " " << (this->model != nullptr ? this->model : "N/A");
		cout << ", anul " << this->anFabricatie;
		cout << ", pret " << this->pret << " EUR";
		cout << ", " << (this->esteNoua ? "NOUA" : "SH");
		cout << ".";
	}
};

int Masina::nrMasini = 0;


/* CLASA MOTOCICLETA  */

enum TipMotocicleta { SPORT = 1, TOURING = 2, SCOOTER = 3 };

class Motocicleta {
public:
	const int idMotocicleta;
	static int nrMotociclete;

	char* marca;
	char* model;
	int nrKm;
	TipMotocicleta tip;

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

	static int kilometriMediu(int km1, int km2) {
		return (km1 + km2) / 2;
	}

	void afisareMotocicleta() {
		cout << endl << this->idMotocicleta << ". Motocicleta ";
		if (this->marca != nullptr) {
			cout << this->marca;
		}
		else {
			cout << "Nespecificata";
		}
		cout << " " << (this->model != nullptr ? this->model : "N/A");
		cout << " are " << this->nrKm << " km, tip ";

		if (this->tip == SPORT) cout << "SPORT";
		else if (this->tip == TOURING) cout << "TOURING";
		else cout << "SCOOTER";

		cout << ".";
	}
};

int Motocicleta::nrMotociclete = 0;


/* CLASA CLIENT */

class Client {
public:
	const int idClient;
	static int nrClienti;

	char* nume;
	int varsta;
	char* oras;
	bool esteFidel;

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

	static float procentClientiFideli(int nrFideli, int total) {
		if (total > 0) {
			return (float)nrFideli * 100 / total;
		}
		return 0;
	}

	void afisareClient() {
		cout << endl << this->idClient << ". Clientul ";
		if (this->nume != nullptr) {
			cout << this->nume;
		}
		else {
			cout << "Neidentificat";
		}
		cout << ", varsta " << this->varsta;
		cout << ", oras " << (this->oras != nullptr ? this->oras : "Necunoscut");
		cout << ", " << (this->esteFidel ? "FIDEL" : "nefidel");
		cout << ".";
	}
};

int Client::nrClienti = 0;


/* MAIN */

void main() {

	cout << "Proiect POO - Faza 1 (AMCM - domeniu Auto: Masini, Clienti si Motociclete)" << endl;


	// MASINI
	Masina m1;
	Masina m2("Dacia");
	Masina m3("Audi", "A4", 2019, 18500, false);

	m1.afisareMasina();
	m2.afisareMasina();
	m3.afisareMasina();

	cout << endl << "Pret m3 cu 10% discount: "
		<< Masina::aplicaDiscount(m3.pret, 10);

	// MOTOCICLETE
	Motocicleta moto1;
	Motocicleta moto2("Honda", "CBR");
	Motocicleta moto3("Yamaha", "MT-07", 12000, SPORT);

	moto1.afisareMotocicleta();
	moto2.afisareMotocicleta();
	moto3.afisareMotocicleta();

	cout << endl << "Kilometri medii (moto2 & moto3): "
		<< Motocicleta::kilometriMediu(moto2.nrKm, moto3.nrKm);

	// CLIENTI
	Client c1;
	Client c2("Alexandra");
	Client c3("Marius", 25, "Bucuresti", true);

	c1.afisareClient();
	c2.afisareClient();
	c3.afisareClient();

	cout << endl << "Procent clienti fideli (1 din 3): "
		<< Client::procentClientiFideli(1, Client::nrClienti) << "%";

	cout << endl << endl << "Sfarsit Faza 1." << endl;
}
