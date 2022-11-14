#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

class Stud
{
public:
    string vardas;
    string pavarde;
    int paz_kiekis;
    int egz;
    int* paz_masyvas;
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
        paz_masyvas = new int[100];
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
                paz_masyvas[i] = 1 + (rand() % 10);
                cout << endl;
                cout << "Sugeneruotas atsitiktinis pazymis yra " << paz_masyvas[i] << endl;
                cout << endl;
            }
            else
            {
                cout << "Iveskite pazymi" << endl;
                cin >> paz_masyvas[i];
            }
            suma += paz_masyvas[i];
            i++;
        }
        if (paz_kiekis != 0)
        {
            vidurkis = suma / (double)paz_kiekis;
            sort(paz_masyvas, paz_masyvas + paz_kiekis); // Medianos skaiciavimas
            if (paz_kiekis % 2 != 0)
            {
                mediana = (double)paz_masyvas[paz_kiekis / 2];
            }
            mediana = (double)(paz_masyvas[(paz_kiekis - 1) / 2] + paz_masyvas[paz_kiekis / 2]) / 2.0;
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
        cout << endl;
    }
    ~Stud() {
        delete[] paz_masyvas;
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
