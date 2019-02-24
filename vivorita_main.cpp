//#include <iostream>
#include <ncurses.h>
#include "mapa.hpp"
#include "worm.hpp" //origen del error.

#define ESC	27
#define ARRIBA	87 //38
#define ABAJO	83 //40
#define DER	65 //39
#define IZQ	68 //37


#define ANCHO 10
#define ALTO 10
#define CUERPO 178
#define VACIO 32

int main()
{
	mapa mundo(10,10);
	worm gusano;
	int gus_x=2;
	int gus_y=2;
	char tecla;
	int contador=0;
	
	mundo.erase();
	mundo.definir(ALTO, ANCHO);
	mundo.setFloor(VACIO);
	
	gusano.getUbicacion(&gus_x, &gus_y);
	//tierras_fertiles.setData(0,0,25);
	mundo.setData(gus_x, gus_y, CUERPO);
	
	initscr();
	//move(5,10);
	/*
	for(int i=0;i<ALTO;i++)
	{
		for(int j=0;j<ANCHO;j++)
		{
			std::cout << tierras_fertiles.getData(i,j);
			if(j==ANCHO-1)	std::cout << std::endl;
		}
	}
	*/
	//tierras_fertiles.mostrar();
	do
	{
		mundo.nc_mostrar(5,10);
		refresh();
		tecla=getch();
		if(tecla!=ESC)
		{
			if(tecla==ARRIBA || tecla==ABAJO || tecla==IZQ || tecla==DER)
				gusano.setDireccion(tecla);
			gusano.getUbicacion(&gus_x, &gus_y);
			switch(tecla)
			{
				case IZQ:
					--gus_x;
					break;
				case ARRIBA:
					++gus_y;
					break;
				case DER:
					++gus_x;
					break;
				case ABAJO:
					--gus_y;
					break;
					
			}
			gusano.setUbicacion(gus_x, gus_y);
			mundo.setData(gus_x, gus_y, CUERPO);
			contador++;
			move(0,0);
			printw("Se cargo nueva ubiacion. %d",contador);
		}
	}
	while(tecla!=ESC);
	
	endwin();
	
	return 0;
}