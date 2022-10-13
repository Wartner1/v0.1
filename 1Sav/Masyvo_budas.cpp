#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

class Stud
{
public:
	//Stud();
	string vardas;
	string pavarde;
	int nd_kiekis;
	int egz;
	double vidurkis;
	void ivedimas() {
		cout << "Iveskite varda" << endl;
		cin >> vardas;
		cout << "Iveskite pavarde" << endl;
		cin >> pavarde;
		cout << "Iveskite egzamino pazymi" << endl;
		cin >> egz;
		cout << "Iveskite pazymiu kieki" << endl;
		cin >> nd_kiekis;
	}
	void masyvas_ir_vidurkis() {
		int* paz_masyvas = new int[nd_kiekis];
		double suma = 0;
		for (int i = 0; i < nd_kiekis; i++)
		{
			cout << "Iveskite pazymi" << endl;
			cin >> paz_masyvas[i];
			suma += paz_masyvas[i];
		}
		vidurkis = suma / (double)nd_kiekis;
		delete[] paz_masyvas;
	}
	void isvedimas() {
		cout << left << setw(15) << "Pavardė" << "|" << left << setw(15) << "Vardas" << "|" << left << setw(15) << "Galutinis (Vid.)" << endl;
		cout <<"____________________________________________________" << endl;
		cout <<setw(15) << pavarde << "|" << left << setw(15) << vardas <<"|"<< left << setw(15) << 0.4*vidurkis+0.6*egz << endl;
	}
	double galutinis() {
		return 0;
	}
	Stud()
	{
		cout << endl;
	}
	~Stud() {
		cout << endl;
	}
};

int main()
{
	Stud objektas;
	objektas.ivedimas();
	objektas.masyvas_ir_vidurkis();
	objektas.isvedimas();
	return 0;
}
