#include "Szinkron.h"

void Szinkron::beolvasJelsorozat()	//Bemeeneti jelsorozatot beovlas� f�ggv�ny
{
	ifstream file(File);
	if (file.is_open())				//ha siker�lt megnyitni a f�jlt
	{
		for (int i = 0; i < N; ++i)	//v�gigl�pked a kell� r�szig
		{
			file >> k >> b;
		}
		file >> kezdoallapot;		//kezd��llapot beolvas�sa
		k = 0;
		while (!file.eof())			//bemeneti jel beolvas�sa f�jlb�l f�jl v�g�ig
		{
			file >> bemenet[k];
			++k;
		}
		file.close();				 //f�jl bez�r�sa
	}
}