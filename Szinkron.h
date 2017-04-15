#ifndef _SZINKRON_H
#define _SZINKRON_H

#include <iostream>
#include <fstream>
#include "Szamlalo.h"

using namespace std;

class Szinkron{
protected:
	int a;							//Jelsorozatok sz�ma
	char kezdoallapot;				//Kiindul�si �llapot a t�bl�zatban
	int* bemenet;					//Bemeneti jelek t�mbje
	char k;							//Beolvas�shoz sz�ks�ges v�ltoz�
	int b;							//Beolvas�shoz sz�ks�ges v�ltoz�
public:
	Szinkron(int par) :a(par){ bemenet = new int[a]; }	//Konstruktor
	~Szinkron(){ delete[]bemenet; }						//Destruktor
	void beolvasJelsorozat();							//Bemeeneti jelsorozat beolvas�sa
};


#endif