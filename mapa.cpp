#include <iostream>
#include "ncurses.h"
#include "mapa.hpp"

//FUNCIONES DE OBJETO MAPA
//---------------------------------------------------------------------------------------------------------------------------
mapa::mapa()
{
	memoria=false;
}
mapa::mapa(int width, int height)			//Establece las dimenciones del mapa.
{
	x=width;
	y=height;
	matriz_mapa = new char*[height];
	for(int i=0; i<height; i++)
	{
		matriz_mapa[i]=new char[width];
	}
	memoria=true;
}

void mapa::definir(int height, int width)		//Establece o redefine las dimenciones del mapa.
{
	if(memoria)
	{
		for(int i = 0; i < height; i++)
		{
			delete[] matriz_mapa[i];
		}
		delete[] matriz_mapa;
		memoria=false;
	}
	else if(!memoria)
	{
		matriz_mapa = new char*[height];
		for(int i = 0; i<height; i++)
		{
			matriz_mapa[i] = new char[width];
		}
		memoria=true;
	}
}

void mapa::erase()					//Borra el mapa.
{
	if(memoria)
	{
		for(int i = 0; i<y; i++)
		{
			delete[]matriz_mapa[i];
		}
		delete[]matriz_mapa;
	}
	memoria=false;
	//matriz_mapa = '\0';
}

bool mapa::setData(int i, int j, char data)		//Establece datos en una coordenada en el mapa
{
	if(memoria && ((i >= 0 && i < x) && (j>=0 && j<y)))
	{
		matriz_mapa[i][j] = data;
		return true;
	}
	else	return false;
}

char mapa::getData(int i, int j)			//Devuelve datos de una coordenada del mapa.
{
	if(memoria) return matriz_mapa[i][j];
}

void mapa::setFloor(char simbol)			//Establece el dibujo del piso.
{
	if(memoria)
	{
		for(int j=0; j<y; j++)
		{
			for(int i=0; i<x; i++)
			{
				matriz_mapa[j][i]=simbol;
			}
		}
	}
}

void mapa::mostrar()					//Imprime en pantalla el mapa del mundo.
{
	if(memoria)
	{
		for(int i=0; i<y; i++)
		{
			for(int j=0; j<x; j++)
			{
				std::cout << matriz_mapa[i][j];
				if(j==x-1)	std::cout << std::endl;
			}
		}
	}
}

void mapa::nc_mostrar(int nc_y, int nc_x)
{
	if(memoria)
	{
		for(int i=0; i<y; i++)
		{
			for(int j=0; j<x; j++)
			{
				move(nc_y+i,nc_x+j);
				printw("%c",matriz_mapa[i][j]);
			}
		}
	}
}

mapa::~mapa()	//Destructor del mapa
{
	for(int i = 0; i<y; i++)
	{
		delete[]matriz_mapa[i];
	}
	delete[]matriz_mapa;
	memoria=false;
	//matriz_mapa = '\0';
}
//---------------------------------------------------------------------------------------------------------------------------
