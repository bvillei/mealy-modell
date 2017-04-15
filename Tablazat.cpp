#include "Tablazat.h"

bool Tablazat::Moore_e()const			//Moore mûködést tesztelõ függvény
{										//Ha minden sorban azonos kimeneti értékek vannak akkor Moore
	int b = 0;
	for (int i = 0; i < 4; ++i){
		int a = 0;
		for (int j = 0; j < 4; ++j)
			a += n[4 * i + j];
		if (a != 0 && a != 4)
			b++;
	}
	if (b == 0)
		return true;					//Moore a hálózat
	return false;						//Mealy a hálózat
}

void Tablazat::beolvasTablazat()		//Táblázat beolvasása a két tömbbe
{
	ifstream myfile(File);
	if (myfile.is_open())
	{
		for (int i = 0; i < N; ++i)
		{
			myfile >> c[i] >> n[i];
		}
		if (Moore_e()) throw invalid_argument("Moore a halozat");	//Moore a hálózat és nem Mealy, ekkor hibát dobunk
		myfile.close();												//Fájl bezárása
	}

	else{
		throw out_of_range("Nem lehet megnyitni a fajlt");			//Ha nem sikerült megnyitni a fájl, hibát dobunk
	}
}