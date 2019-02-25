//#include <iostream>
#include <ncurses.h>
#include "mapa.hpp"
#include "worm.hpp" //origen del error.

#define ESC	27
#define ARRIBA	119 //38
#define ABAJO	115 //40
#define DER	100 //39
#define IZQ	97 //37


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
	int tecla;
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
			gusano.getUbicacion(&gus_y, &gus_x);
			switch(tecla)
			{
				case ARRIBA:	//arriva
					if(gus_y>0)
					--gus_y;
					break;
				case DER:	//izquierda
					++gus_x;
					break;
				case ABAJO:	//abajo
					++gus_y;
					break;
				case IZQ:	//derecha
					if(gus_x>0)
					--gus_x;
					break;
					
			}
			gusano.setUbicacion(gus_y, gus_x);
			mundo.setData(gus_y, gus_x, CUERPO);
			contador++;
			move(0,0);
			printw("Se cargo nueva ubiacion. %d",contador);
			move(1,1);
			printw("coord x:\t%d\tcoord y:\t%d",gus_x,gus_y);
			move(2,0);
			printw("tecla:\t%d",tecla);
		}
	}
	while(tecla!=ESC);
	
	endwin();
	
	return 0;
}