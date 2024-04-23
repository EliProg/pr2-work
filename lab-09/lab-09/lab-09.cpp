#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Eredmeny {
public: int helyezes;
public: int fo;
public: string kat;
public: string sport;


public: Eredmeny(int h, int f, string k, string s) {
	helyezes = h;
	fo = f;
	kat = k;
	sport = s;
}
	  Eredmeny() = default;
};


class Helsinki {
private: int db;
private: Eredmeny *tmb;
public: Helsinki() {
	tmb = new Eredmeny;
	ifstream be("helsinki.txt");
	int i = 0;
	while (!be.eof())
	{
		int h;
		int f;
		
		string k;
		string s;
		string temp;
		getline(be, temp, ';');
		h = stoi(temp);
		getline(be, temp, ';');
		f = stoi(temp);
		getline(be, k, ';');

		getline(be, s, ';');
	
		tmb[i] = Eredmeny(h, f, k, s);
		i++;
	}
}


public: Eredmeny getEredemeny(int i) {
	return tmb[i];
}
};


int main() {
	Helsinki helsinki;

	cout << helsinki.getEredemeny(0).helyezes << endl;
	return 0;
}