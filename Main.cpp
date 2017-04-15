#include <iostream>
#include <fstream>
#include <exception>

#include "Tablazat.h"
#include "Mealy.h"
#include "Szinkron.h"
#include "Szamlalo.h"

#define N 16

using namespace std;

int main()
{

	try
	{
		Szamol Szamlalos;
		Szamlalos.setA();
		Mealy m(Szamlalos.getA());
		m.beolvasTablazat();
		m.beolvasJelsorozat();
		m.feltolt();
		m.lepegeto();
		m.kepernyoreir();
		m.fajlbair();
	}

	catch (const out_of_range& e)		//Nem siker�lt megnyitni a f�jlt
	{
		cerr << e.what() << endl;
	}

	catch (const invalid_argument& e)	//Moore a h�l�zat �s nem Mealy
	{
		cerr << e.what() << endl;
	}

	catch (const bad_exception& e)		//Funkcion�lis haz�rdot tartalmaz a h�l�zat
	{
		cerr << e.what() << endl;
	}

	catch (const runtime_error& e)		//Hib�s kezdeti �llapot
	{
		cerr << e.what() << endl;
	}

	catch (...)							//Tov�bbi hibakezel�s
	{
		cerr << "Varatlan hiba. Kerem, inditsa ujra a programot." << endl;
	}

	return 0;
}
