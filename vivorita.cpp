#include <iostream>
#include "obj_juego.hpp"
#define ALTO 10
#define ANCHO 10
#define RATON 111
#define CUERPO 178
#define VACIO 32
using namespace std;

// Crear reglas de vivorita:
//Falta crear reglas de pintado en pantalla, lectura de mapa, deteccion de obstaculos, deteccion de comida e ingesta.
//Mapa

int main(int argc, char *argv[])
{
	int gusano_x;
	int gusano_y;
	
	mapa azerot(ALTO,ANCHO);
	
	worm maggot;
	
	azerot.erase();
	azerot.definir(ALTO,ANCHO);
	azerot.setFloor(VACIO);				//Dibujando fondo en el mapa.
	
	maggot.getUbicacion(&gusano_x, &gusano_y);	//Obtencion de ubicacion de la vivorita.
	
	azerot.setData(gusano_x, gusano_y, CUERPO);	//Cargando gusano en el mapa.
	
	azerot.mostrar();				//Imprime, el mapa del juego, en pantalla.
	
	return 0;
}

