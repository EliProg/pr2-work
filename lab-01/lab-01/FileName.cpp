#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct adatok
{
	int szakitas = 0, lokes = 0, suly = 0, rajtszam = 0;
	string nev;
};

int main()
{
	int i = 0, letszam = 0, suly = 0, kevesebb = 0;
	fstream fajl("nevek.txt");
	srand((unsigned)time(NULL));
	

	adatok tmb[15];
	for (i = 0; i < 15 && !fajl.eof(); i++)
	{
		fajl >> tmb[i].szakitas;
		fajl >> tmb[i].lokes;
		getline(fajl, tmb[i].nev);
		tmb[i].rajtszam = rand() % 89 + 10;
			do {
				cout << "Adja meg a " << tmb[i].nev << " versenyzo sulyat (95-150): " << endl;
				cin >> tmb[i].suly;
				cin.ignore();
				if (tmb[i].suly < 95 || tmb[i].suly > 150)
				{
					cout << "Hibas adat, a sulynak 95 és 150 kg között kell lennie!";
				}
			} while (tmb[i].suly < 95 || tmb[i].suly > 150);


			letszam++;

	} 
	fajl.close();

	cout << "A versenyen " << letszam << " versenyzo indult." << endl;
	cout.setf(ios::right);

	for ( i = 0; i < letszam; i++)
	{
		cout << setw(20) << tmb[i].nev << "\t rajtszam: " << tmb[i].rajtszam
			<< "\t suly: " << tmb[i].suly << "\t szakitas: " << tmb[i].szakitas
			<< "\t lokes: " << tmb[i].lokes << "\t osszesitett: "
			<< (tmb[i].lokes + tmb[i].szakitas) << endl;
	}
}