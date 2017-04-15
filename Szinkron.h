#ifndef _SZINKRON_H
#define _SZINKRON_H

#include <iostream>
#include <fstream>
#include "Szamlalo.h"

using namespace std;

class Szinkron{
protected:
	int a;							//Jelsorozatok száma
	char kezdoallapot;				//Kiindulási állapot a táblázatban
	int* bemenet;					//Bemeneti jelek tömbje
	char k;							//Beolvasáshoz szükséges változó
	int b;							//Beolvasáshoz szükséges változó
public:
	Szinkron(int par) :a(par){ bemenet = new int[a]; }	//Konstruktor
	~Szinkron(){ delete[]bemenet; }						//Destruktor
	void beolvasJelsorozat();							//Bemeeneti jelsorozat beolvasása
};


#endif