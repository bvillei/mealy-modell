#ifndef _MEALY_H
#define _MEALY_H

#include "Tablazat.h"
#include "Szinkron.h"
#include <iostream>
using namespace std;

class Mealy :public Szinkron, public Tablazat{
	char *y;							//�llapotok t�mbje
	int *z;								//kimeneti �rt�kek t�mbje
	int pos;							//t�bl�zat beli poz�ci�
public:
	Mealy(int a) : Szinkron(a)			//konstruktor
	{
		y = new char[a];				//y dinamikus t�mb foglal�sa, bemeneti jelek sz�m�val egyenl� m�ret		
		z = new int[2*a];				//z dinamikus t�mb foglal�sa, bemeneti jelek sz�m�nak k�tszeres�vel egyenl� m�ret
	}
	~Mealy(){ delete[]y; delete[]z; }	//destruktor
	int getPos()const{ return pos; }	//get f�ggv�ny poz�ci� lek�rdez�s�hez
	void setPos(int x){ pos = x; }		//set f�ggv�ny poz�ci� be�ll�t�s�hoz
	void feltolt();						//kezdeti poz�ci� be�ll�t�sa �s kezdeti �llapot �s �rt�k be�r�sa a t�mb�kbe
	void lepegeto();					//v�gig l�pked a t�bl�zaton(t�mb�n) �s elt�rolja az �llapotokat �s �rt�keket a t�mb�kben
	void kepernyoreir() const;			//eredm�ny k�perny�re �r�sa
	void fajlbair() const;				//"kimenet.txt"-be ki�r�s
};

#endif