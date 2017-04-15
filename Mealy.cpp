#include "Mealy.h"

void Mealy::feltolt()			//y és z tömb feltöltése	
{
	y[0] = kezdoallapot;		//kezdõállapot beírása
	switch (kezdoallapot) {		//kezdõpozíció meghatározása
	case 'A':					//ha A sorban van
		switch (bemenet[0]){	//és a bemeneti jel értéke
		case 0:					//00
			setPos(0);			//akkor a nulladik helyen vagyunk a táblázatban
			break;				//ugrunk tovább
		case 1:					//01
			setPos(1);			//akkor az elsõ helyen vagyunk a táblázatban
			break;				//...
		case 11:
			setPos(2);
			break;
		case 10:
			setPos(3);
			break;
		}break;
	case 'B':					//ha B sorban van
		switch (bemenet[0]){	//...	
		case 0:
			setPos(4);
			break;
		case 1:
			setPos(5);
			break;
		case 11:
			setPos(6);
			break;
		case 10:
			setPos(7);
			break;
		}break;
	case 'C':					//ha C sorban van
		switch (bemenet[0]){	//...
		case 0:
			setPos(8);
			break;
		case 1:
			setPos(9);
			break;
		case 11:
			setPos(10);
			break;
		case 10:
			setPos(11);
			break;
		} break;
	case 'D':					//ha D sorban van
		switch (bemenet[0]){	//...
		case 0:
			setPos(12);
			break;
		case 1:
			setPos(13);
			break;
		case 11:
			setPos(14);
			break;
		case 10:
			setPos(15);
			break;
		}break;

	default:					
		throw runtime_error("Hibas a kezdeti allapot"); //ha nem megfelelõ kezdeti állapotot adtak meg akkor hibát dob
	}
	z[0] = n[pos];				//z nulladik és
	z[1] = n[pos];				//elsõ eleme a kezdeti kimeneti érték lesz
	/*cout << y[0] << z[0] << endl;*/ //kiírja a kezdeti állapotot és értéket
}

void Mealy::lepegeto()		//ez a függvény végiglépeget a táblázaton(tömbön), és feltölti y és z tömböt
{

	for (int i = 0, j = 2, k = 1; i < a - 1; ++i)
	{	//vizszintes lépés a táblázatban
		if (bemenet[i] == 00 && bemenet[i + 1] == 01 || bemenet[i] == 01 && bemenet[i + 1] == 11 || bemenet[i] == 11 && bemenet[i + 1] == 10)							//vízszintes
		{
			pos++;		//egyet jobbra
		}
		else if (bemenet[i] == 10 && bemenet[i + 1] == 11 || bemenet[i] == 11 && bemenet[i + 1] == 01 || bemenet[i] == 01 && bemenet[i + 1] == 00)
		{
			pos--;		//egyet balra
		}
		else if (bemenet[i] == 00 && bemenet[i + 1] == 10)
		{
			pos += 3;	//egyet balra(táblázatból kimegy és a másik végén folytatódik)
		}
		else if (bemenet[i] == 10 && bemenet[i + 1] == 00)
		{
			pos -= 3;	//egyet jobbra(táblázatból kimegy és a másik végén folytatódik)
		}
		else throw bad_exception("Funkcionalis hazardot tartalmaz");	//lekezeli ha funkcionális hazárdot tartalmaz a hálózat
		y[k] = c[pos];								//y-ba adott állapot írása
		z[j] = n[pos];								//z-be adott kiemeneti érték írása
		pos = pos + ((y[k] - y[k - 1]) * 4);		//függõleges lépés a táblázatban
		z[j + 1] = n[pos];							//z-be adott érték beírása
		k++;										//k növelése (y tömb indexe)
		j = j + 2;									//j növelése 2-vel, mivel minden állapothoz 2 kimeneti érték tartozik (z tömb indexe)
	}
}

void Mealy::kepernyoreir() const			//eredmény kiíró függvény a képernyõre
{			
	cout << ' ';							//igazítás
	for (int i = 0; i < a; ++i)
		cout << y[i] << ' ' << ' ' << ' ';	//állapotok kiírása és igazítás
	cout << endl;
	for (int j = 0; j < 2 * a; ++j)
		cout << z[j] << ' ';				//kiemeneti értékek kiírása
	cout << endl;
}

void Mealy::fajlbair()const					//eredmény kiíró függvény a képernyõre
{
	std::ofstream out("kimenet.txt");		//"kimenet.txt" nevû fájl hoz létre és abba fogja írni az állapotokat és értékeket
	out << ' ';
	for (int i = 0; i < a; ++i)
		out << y[i] << ' ' << ' ' << ' ';
	out << endl;
	for (int j = 0; j < 2 * a; ++j)
		out << z[j] << ' ';
	out.close();							//fájl bezárása
}