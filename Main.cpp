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

	catch (const out_of_range& e)		//Nem sikerült megnyitni a fájlt
	{
		cerr << e.what() << endl;
	}

	catch (const invalid_argument& e)	//Moore a hálózat és nem Mealy
	{
		cerr << e.what() << endl;
	}

	catch (const bad_exception& e)		//Funkcionális hazárdot tartalmaz a hálózat
	{
		cerr << e.what() << endl;
	}

	catch (const runtime_error& e)		//Hibás kezdeti állapot
	{
		cerr << e.what() << endl;
	}

	catch (...)							//További hibakezelés
	{
		cerr << "Varatlan hiba. Kerem, inditsa ujra a programot." << endl;
	}

	return 0;
}
