#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>

using namespace std;

class Stud
{
public:
    string vardas;
    string pavarde;
    int paz_kiekis;
    int egz;
    vector<int> paz_vektorius;
    double vidurkis;
    double mediana;
    void ivedimas() {
        cout << "Iveskite varda" << endl;
        cin >> vardas;
        cout << "Iveskite pavarde" << endl;
        cin >> pavarde;
        cout << "Ar norite kad egzamino pazymis butu sugeneruotas atsitiktinai? Taip - 't', Ne - 'n'" << endl;
        char egz_patikra;
        cin >> egz_patikra;
        if (egz_patikra == 'n')
        {
            cout << "Iveskite egzamino pazymi" << endl;
            cin >> egz;
        }
        else
        {
            srand((unsigned)time(NULL));
            egz = 1 + (rand() % 10);
            cout << endl;
            cout << "Sugeneruotas egzamino pazymis yra " << egz << endl;
            cout << endl;
        }
    }
    void masyvas_ir_vidurkis()
    {
        bool testi = 1;
        char patikra;
        char gen; // Patikra ar norima atsitiktinai generuoti skaiciu
        double suma = 0;
        int paz_kiekis = 0;
        int i = 0;
        int paz;
        while (testi != 0)
        {
            cout << "Ar norite ivesti pazymi? Taip - 't', Ne - 'n'" << endl;
            cin >> patikra;
            if (patikra == 'n')
            {
                testi = 0;
                break;
            }
            else if (patikra == 't')
            {
                paz_kiekis++;
            }
            cout << "Ar norite kad sis pazymis butu sugeneruotas atsitiktinai? Taip - 't', Ne - 'n'" << endl;
            cin >> gen;
            if (gen == 't')
            {
                srand((unsigned)time(NULL));
                paz_vektorius.push_back(1 + (rand() % 10));
                cout << endl;
                cout << "Skaicius sugeneruotas" << endl;
                cout << endl;
            }
            else
            {
                cout << "Iveskite pazymi" << endl;
                cin >> paz;
                paz_vektorius.push_back(paz);
            }
            suma = accumulate(paz_vektorius.begin(), paz_vektorius.end(), 0);
            i++;
        }
        if (paz_vektorius.size() != 0)
        {
            vidurkis = suma / (double)paz_vektorius.size();
            sort(paz_vektorius.begin(), paz_vektorius.end()); // Medianos skaiciavimas
            if (paz_vektorius.size() % 2 != 0)
            {
                mediana = (double)paz_vektorius[paz_vektorius.size() / 2];
            }
            mediana = (double)(paz_vektorius[(paz_vektorius.size() - 1) / 2] + paz_vektorius[paz_vektorius.size() / 2]) / 2.0;
        }
    }
    void isvedimas() {
        cout << endl;
        cout << left << setw(15) << "Pavardė" << "|" << left << setw(15) << "Vardas" << "|" << left << setw(20) << "Galutinis (Vid.)" << "|" << left << setw(20) << "Galutinis (Med.)" << endl;
        cout << "______________________________________________________________________" << endl;
        cout << setw(15) << pavarde << "|" << left << setw(15) << vardas << "|" << left << setw(20) << 0.4 * vidurkis + 0.6 * egz << "|" << left << setw(20) << 0.4 * mediana + 0.6 * egz << endl;
    }
    Stud()
    {
        cout << "";
    }
    ~Stud() {
        cout << "";
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
