#include <iostream>
#include <fstream>
#include <exception>

#ifndef _Tablazat_H
#define _Tablazat_H
#define N 16
#define File "teszt.txt"		//tesztfájl neve, itt kell átírni hogyha másik fájlal szeretnénk dolgozni

using namespace std;

class Tablazat{
protected:
	char c[N];					//táblázat állapotait tároló tömb
	int n[N];					//táblázat értékeit tartalmazó tömb
public:
	bool Moore_e()const;		//Moore mûködést tesztelõ függvény
	void beolvasTablazat();		//táblázat beolvasása
};

#endif