#ifndef _Szamlalo_H
#define _Szamlalo_H

#include <iostream>
#include"Tablazat.h"
using namespace std;

class Orajel
{
public:
	static double frekvencia;					//�rajel frekvencia
	void setFrek(){ cin >> frekvencia; }
	double getFrek()const{ return frekvencia; }
};

class Szamol							//"Szinkron.h" -ban haszn�lt 'a'-nak �rt�kad�s (dinamikus t�mb l�trehoz�s�hoz)
{	
private:
	int a;								//bemeneti jelek sz�ma
public:
	void setA()
	{
		int x = 0;						//'x' v�gs� �rt�k�vel lesz egyenl� 'a'
		char c;							//beolvas�shoz sz�ks�ges v�ltoz�
		int b;							//beolvas�shoz sz�ks�ges v�ltoz�
		ifstream file(File);			
		if (file.is_open())				//f�jl megnyit�sa
		{
			for (int i = 0; i < N; ++i)
			{
				file >> c >> b;			//�tl�pked�s a jelenleg nem sz�m�t� �rt�keken
			}
			file >> c;					//kezdeti �llapoton is
			while (!file.eof())			//f�jl v�g�ig olvas�s
			{
				file >> b;
				++x;					//ah�ny �rt�k j�n, annyi bemeneti v�ltoz�s van, ezt elt�roljuk 'x'-ben
			}
			file.close();				//f�jl bez�r�sa
		}
		a = x;							//'a' megkapja az �rt�k�t
	}
	int getA()const{ return a; }		//'a'-t lek�rdez� f�ggv�ny
};
#endif