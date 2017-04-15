#include "Tablazat.h"

bool Tablazat::Moore_e()const			//Moore m�k�d�st tesztel� f�ggv�ny
{										//Ha minden sorban azonos kimeneti �rt�kek vannak akkor Moore
	int b = 0;
	for (int i = 0; i < 4; ++i){
		int a = 0;
		for (int j = 0; j < 4; ++j)
			a += n[4 * i + j];
		if (a != 0 && a != 4)
			b++;
	}
	if (b == 0)
		return true;					//Moore a h�l�zat
	return false;						//Mealy a h�l�zat
}

void Tablazat::beolvasTablazat()		//T�bl�zat beolvas�sa a k�t t�mbbe
{
	ifstream myfile(File);
	if (myfile.is_open())
	{
		for (int i = 0; i < N; ++i)
		{
			myfile >> c[i] >> n[i];
		}
		if (Moore_e()) throw invalid_argument("Moore a halozat");	//Moore a h�l�zat �s nem Mealy, ekkor hib�t dobunk
		myfile.close();												//F�jl bez�r�sa
	}

	else{
		throw out_of_range("Nem lehet megnyitni a fajlt");			//Ha nem siker�lt megnyitni a f�jl, hib�t dobunk
	}
}