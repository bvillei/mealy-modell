#include "Szinkron.h"

void Szinkron::beolvasJelsorozat()	//Bemeeneti jelsorozatot beovlasó függvény
{
	ifstream file(File);
	if (file.is_open())				//ha sikerült megnyitni a fájlt
	{
		for (int i = 0; i < N; ++i)	//végiglépked a kellõ részig
		{
			file >> k >> b;
		}
		file >> kezdoallapot;		//kezdõállapot beolvasása
		k = 0;
		while (!file.eof())			//bemeneti jel beolvasása fájlból fájl végéig
		{
			file >> bemenet[k];
			++k;
		}
		file.close();				 //fájl bezárása
	}
}