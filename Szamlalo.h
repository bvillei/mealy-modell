#ifndef _Szamlalo_H
#define _Szamlalo_H

#include <iostream>
#include"Tablazat.h"
using namespace std;

class Orajel
{
public:
	static double frekvencia;					//órajel frekvencia
	void setFrek(){ cin >> frekvencia; }
	double getFrek()const{ return frekvencia; }
};

class Szamol							//"Szinkron.h" -ban használt 'a'-nak értékadás (dinamikus tömb létrehozásához)
{	
private:
	int a;								//bemeneti jelek száma
public:
	void setA()
	{
		int x = 0;						//'x' végsõ értékével lesz egyenlõ 'a'
		char c;							//beolvasáshoz szükséges változó
		int b;							//beolvasáshoz szükséges változó
		ifstream file(File);			
		if (file.is_open())				//fájl megnyitása
		{
			for (int i = 0; i < N; ++i)
			{
				file >> c >> b;			//átlépkedés a jelenleg nem számító értékeken
			}
			file >> c;					//kezdeti állapoton is
			while (!file.eof())			//fájl végéig olvasás
			{
				file >> b;
				++x;					//ahány érték jön, annyi bemeneti változás van, ezt eltároljuk 'x'-ben
			}
			file.close();				//fájl bezárása
		}
		a = x;							//'a' megkapja az értékét
	}
	int getA()const{ return a; }		//'a'-t lekérdezõ függvény
};
#endif