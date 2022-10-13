#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <numeric>

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
		vector<int>nd;
		int paz = 0;
		double suma = 0;
		for (int i = 1; i <= nd_kiekis; i++)
		{
			cin >> paz;
			nd.push_back(paz);
		}
		suma = accumulate(nd.begin(), nd.end(), 0);
		vidurkis = suma / (double)nd_kiekis;

	}
	void isvedimas() {
		cout << left << setw(15) << "Pavardė" << "|" << left << setw(15) << "Vardas" << "|" << left << setw(15) << "Galutinis (Vid.)" << endl;
		cout << "____________________________________________________" << endl;
		cout << setw(15) << pavarde << "|" << left << setw(15) << vardas << "|" << left << setw(15) << 0.4 * vidurkis + 0.6 * egz << endl;
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
