#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

double Atlag(int*, int);

void csere(int x, int* y);

void csere2(int x, int& y);

void Feltolt(int tmb[], int n);

void Kiir(int tmb[], int);

int Max(int tmb[], int);

int main()
{
	/*int jegy[10] = {1,2,3,23,34,56,23,45,21,23};
	int jegy2[10] = { 10,25,43,23,34,56,23,45,21,23 };
	cout << "\nSzamtani atlag: " << Atlag(jegy, 10) << endl;
	cout << "\nSzamtani atlag: " << Atlag(jegy2, 10) << endl;
	// Értékszerinti átadás.
	int szam1, szam2;
	cout << "Elso szam: ";
	cin >> szam1;
	cout << "Masodik szam: ";
	cin >> szam2;
	cout << "Csere elott: " << szam1 << ", " << szam2 << endl;
	csere2( szam1, szam2);
	cout << "Csere utan: " << szam1 << ", " << szam2 << endl;*/

	//Tömb feltöltése adatokkal

	srand((unsigned int)time(NULL));
	int db;
	do
	{
		cout << "Hany tanuloja van a csoportnak? ";
		cin >> db;
		if (db < 1 || db > 10)
		{
			cout << "Nem jo a szam! (1-10)" << endl;
		}
	} while (db < 1 || db > 10);
	int *jegy = new int[db];
	Feltolt(jegy, db);
	Kiir(jegy, db);
	cout << "\nA legjobb dolgozat erteke: " << Max(jegy, db) << endl;
	return 0;
}

double Atlag(int tmb, int db)
{
	double osszeg = 0;
	for (int i = 0; i < db; i++)
	{
		osszeg += tmb[i];
	}
	return osszeg / db;

}

void csere(int* x, int* y)
{
	cout << &x << ", " << &y << endl;
	int seged;
	seged = *x;
	*x = *y;
	*y = seged;
	cout << &x << ", " << &y << endl;
}

void csere2(int& x, int& y)
{
	int seged = x;
	x = y;
	y = seged;
}


void Feltolt(int tmb[], int n)
{
	for (int i = 0; i < n; i++)
	{
		tmb[i] = (rand() % 100) + 1;
	}
}

void Kiir(int tmb[], int n)
{
	cout << "\nA csoport jegyei: \n";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << tmb[i];
	}
	cout << endl;
}

int Max(int tmb[], int n)
{
	int max = tmb[0];
	for (int i = 1; i < n; i++)
	{
		if (max < tmb[i])
		{
			max = tmb[i];
		}
	}
	return max;
}