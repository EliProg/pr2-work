#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Teglalap {
	private: int mag, alap;

public: bool init(int a, int b)
{
	if (a > 0 && b > 0)
	{
		mag = a;
		alap = b;
		return true;
	}
	else
	{
		cout << "Hiba! Az alap es a magassag nem lehet negativ!" << endl;
		return false;
	}
}
	public: int ter()
	{
		return alap * mag;
	}
public: int ker() {
	return 2 * (alap + mag);
}

public: int getAlap() {
	return alap;
}
public: int getMag() {
	return mag;
}
};

int main() {

	int old1, old2;
	bool inited = false;
	Teglalap t1, t2;
	cout << "Adja meg a teglalap oldalait: " << endl;
	while (!inited)
	{
		cin >> old1;
		cin >> old2;
		inited = t2.init(old1, old2);
	}
	

	
	
	t1.init(5, 10);;
	

	cout << "Az elso teglalap terulete: " << t1.ter() << endl;
	cout << "A masodik teglalap terulete: " << t2.ter() << endl;
	cout << "Az elso teglalap magassaga: " << t1.getMag() << endl;
	return 0;
}