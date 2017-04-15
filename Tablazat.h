#include <iostream>
#include <fstream>
#include <exception>

#ifndef _Tablazat_H
#define _Tablazat_H
#define N 16
#define File "teszt.txt"		//tesztf�jl neve, itt kell �t�rni hogyha m�sik f�jlal szeretn�nk dolgozni

using namespace std;

class Tablazat{
protected:
	char c[N];					//t�bl�zat �llapotait t�rol� t�mb
	int n[N];					//t�bl�zat �rt�keit tartalmaz� t�mb
public:
	bool Moore_e()const;		//Moore m�k�d�st tesztel� f�ggv�ny
	void beolvasTablazat();		//t�bl�zat beolvas�sa
};

#endif