#ifndef _MEALY_H
#define _MEALY_H

#include "Tablazat.h"
#include "Szinkron.h"
#include <iostream>
using namespace std;

class Mealy :public Szinkron, public Tablazat{
	char *y;							//állapotok tömbje
	int *z;								//kimeneti értékek tömbje
	int pos;							//táblázat beli pozíció
public:
	Mealy(int a) : Szinkron(a)			//konstruktor
	{
		y = new char[a];				//y dinamikus tömb foglalása, bemeneti jelek számával egyenlõ méret		
		z = new int[2*a];				//z dinamikus tömb foglalása, bemeneti jelek számának kétszeresével egyenlõ méret
	}
	~Mealy(){ delete[]y; delete[]z; }	//destruktor
	int getPos()const{ return pos; }	//get függvény pozíció lekérdezéséhez
	void setPos(int x){ pos = x; }		//set függvény pozíció beállításához
	void feltolt();						//kezdeti pozíció beállítása és kezdeti állapot és érték beírása a tömbökbe
	void lepegeto();					//végig lépked a táblázaton(tömbön) és eltárolja az állapotokat és értékeket a tömbökben
	void kepernyoreir() const;			//eredmény képernyõre írása
	void fajlbair() const;				//"kimenet.txt"-be kiírás
};

#endif