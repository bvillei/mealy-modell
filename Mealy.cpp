#include "Mealy.h"

void Mealy::feltolt()			//y �s z t�mb felt�lt�se	
{
	y[0] = kezdoallapot;		//kezd��llapot be�r�sa
	switch (kezdoallapot) {		//kezd�poz�ci� meghat�roz�sa
	case 'A':					//ha A sorban van
		switch (bemenet[0]){	//�s a bemeneti jel �rt�ke
		case 0:					//00
			setPos(0);			//akkor a nulladik helyen vagyunk a t�bl�zatban
			break;				//ugrunk tov�bb
		case 1:					//01
			setPos(1);			//akkor az els� helyen vagyunk a t�bl�zatban
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
		throw runtime_error("Hibas a kezdeti allapot"); //ha nem megfelel� kezdeti �llapotot adtak meg akkor hib�t dob
	}
	z[0] = n[pos];				//z nulladik �s
	z[1] = n[pos];				//els� eleme a kezdeti kimeneti �rt�k lesz
	/*cout << y[0] << z[0] << endl;*/ //ki�rja a kezdeti �llapotot �s �rt�ket
}

void Mealy::lepegeto()		//ez a f�ggv�ny v�gigl�peget a t�bl�zaton(t�mb�n), �s felt�lti y �s z t�mb�t
{

	for (int i = 0, j = 2, k = 1; i < a - 1; ++i)
	{	//vizszintes l�p�s a t�bl�zatban
		if (bemenet[i] == 00 && bemenet[i + 1] == 01 || bemenet[i] == 01 && bemenet[i + 1] == 11 || bemenet[i] == 11 && bemenet[i + 1] == 10)							//v�zszintes
		{
			pos++;		//egyet jobbra
		}
		else if (bemenet[i] == 10 && bemenet[i + 1] == 11 || bemenet[i] == 11 && bemenet[i + 1] == 01 || bemenet[i] == 01 && bemenet[i + 1] == 00)
		{
			pos--;		//egyet balra
		}
		else if (bemenet[i] == 00 && bemenet[i + 1] == 10)
		{
			pos += 3;	//egyet balra(t�bl�zatb�l kimegy �s a m�sik v�g�n folytat�dik)
		}
		else if (bemenet[i] == 10 && bemenet[i + 1] == 00)
		{
			pos -= 3;	//egyet jobbra(t�bl�zatb�l kimegy �s a m�sik v�g�n folytat�dik)
		}
		else throw bad_exception("Funkcionalis hazardot tartalmaz");	//lekezeli ha funkcion�lis haz�rdot tartalmaz a h�l�zat
		y[k] = c[pos];								//y-ba adott �llapot �r�sa
		z[j] = n[pos];								//z-be adott kiemeneti �rt�k �r�sa
		pos = pos + ((y[k] - y[k - 1]) * 4);		//f�gg�leges l�p�s a t�bl�zatban
		z[j + 1] = n[pos];							//z-be adott �rt�k be�r�sa
		k++;										//k n�vel�se (y t�mb indexe)
		j = j + 2;									//j n�vel�se 2-vel, mivel minden �llapothoz 2 kimeneti �rt�k tartozik (z t�mb indexe)
	}
}

void Mealy::kepernyoreir() const			//eredm�ny ki�r� f�ggv�ny a k�perny�re
{			
	cout << ' ';							//igaz�t�s
	for (int i = 0; i < a; ++i)
		cout << y[i] << ' ' << ' ' << ' ';	//�llapotok ki�r�sa �s igaz�t�s
	cout << endl;
	for (int j = 0; j < 2 * a; ++j)
		cout << z[j] << ' ';				//kiemeneti �rt�kek ki�r�sa
	cout << endl;
}

void Mealy::fajlbair()const					//eredm�ny ki�r� f�ggv�ny a k�perny�re
{
	std::ofstream out("kimenet.txt");		//"kimenet.txt" nev� f�jl hoz l�tre �s abba fogja �rni az �llapotokat �s �rt�keket
	out << ' ';
	for (int i = 0; i < a; ++i)
		out << y[i] << ' ' << ' ' << ' ';
	out << endl;
	for (int j = 0; j < 2 * a; ++j)
		out << z[j] << ' ';
	out.close();							//f�jl bez�r�sa
}