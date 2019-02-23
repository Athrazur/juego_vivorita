#include "worm.hpp"

//OBJETO COORDENADA					//OBJETO COORDENADA
//---------------------------------------------------------------------------------------------------------------------------
coor_xy::coor_xy(int cord_x, int cord_y)		//Constructor de objeto coordenada, establece coordenada en (0;0).
{
	x = cord_x;
	y = cord_y;
}
void coor_xy::setXY(int cord_x, int cord_y)		//Actualiza la coordenada.
{
	x = cord_x;
	y = cord_y;
}
void coor_xy::getXY(int *X, int *Y)			//Devuelve datos de coordenada.
{
	*X = x;
	*Y = y;
}
//---------------------------------------------------------------------------------------------------------------------------


//CLASE WORM(GUSANO/VIVORITA);
//---------------------------------------------------------------------------------------------------------------------------
worm::worm() 						//Constructor
{
	largo = 1;
	direccion = 0;
}
void worm::setUbicacion(int cord_x, int cord_y) 	//Establece la ubicacion del gusano.
{
	posicion.setXY(cord_x, cord_y);
}
void worm::getUbicacion(int *cord_x, int *cord_y) 	//Devuelve la ubicacion del gusano.
{
	posicion.getXY(cord_x, cord_y);
}
void worm::setDireccion(int i) 				//Establece la direccion.
{
	direccion=i;
}
int worm::getDireccion() 				//Deuelve la direccion.
{
	return direccion;
}
void worm::alimentacion(int comida) 			//Alimenta al gusano
{
	largo++;
}
//---------------------------------------------------------------------------------------------------------------------------