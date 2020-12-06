#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>

using namespace std;
/*
* Polymorphism :
* - True	= Overriding (virtual)
* - Trivial	= Overloading (jumlah, letak, tipe argument)
*/

class Unggas {
protected:
	int aJumlahKaki;
	char aWarna[100];

public:
	/* Constructor */
	Unggas() {
		cout << "Constructor: Unggas" << endl;
	}
	
	/* Setter */
	void setJumlahKaki(int JumlahKaki) {
		this->aJumlahKaki = JumlahKaki;
	}

	void setWarna(const char w[100]) {
		strcpy(aWarna, w);
	}

	/* Getter */
	int getJumlahKaki() {
		return aJumlahKaki;
	}

	char* getWarna() {
		return aWarna;
	}

	/* Contoh Fungsi Untuk Polymorphism: True/Overloading */
	void Makan(int X) {
		cout << "Hewan makan sebanyak " << X << " piring" << endl;
	}

	void Makan(int X, const char Y[100]) {
		cout << "Hewan makan " << Y << " sebanyak " << X << " piring" << endl;
	}

	void Makan(const char Y[100], int X) {
		cout << "Hewan makan " << Y << "." << endl;
	}

	void Makan(const char X[100]) {
		cout << "Hewan makan " << X << "!" << endl;
	}

	/* Contoh Fungsi Untuk Polymorphism: True/Overriding */
	virtual void Berjalan() {
		cout << "Hewan Berjalan.." << endl;
	}

	/* Pure Virtual Function */
	virtual void Tidur() = 0;
};

class Ayam :public Unggas {
public:
	Ayam() {
		cout << "Constructor: Ayam" << endl;
	}

	void Tidur() {
		cout << "Ayam Tidur";
	}
};

class Burung :public Unggas {
public:
	Burung() {
		cout << "Constructor: Burung" << endl;
	}

	/* Contoh Fungsi Untuk Polymorphism: True/Overriding */
	void Berjalan() {
		cout << "Burung Berjalan.." << endl;
	}

	void Tidur() {
		cout << "Burung Tidur";
	}
};

class Bebek :public Unggas {
public:
	Bebek() {
		cout << "Constructor: Bebek" << endl;
	}

	void Tidur() {
		cout << "Bebek Tidur";
	}
};

int main() {
	/* Implementasi Polymorphism: Overloading/True */
	Ayam A1;

	A1.Makan(7);
	A1.Makan(3, "TIMUN");
	A1.Makan("SEMUT", 5);
	A1.Makan("OBAT");

	/* Implementasi Polymorphism: Overriding/Trivial */
	Unggas* Hewan = new Burung();

	Hewan->Berjalan();

	Hewan = new Ayam();
	Hewan->Tidur();
	
	_getch();
	return 0;
}