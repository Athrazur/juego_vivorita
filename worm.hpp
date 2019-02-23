#ifndef WORM_HPP
#define WORM_HPP

//CLASE COORDENADA:
//---------------------------------------------------------------------------------------------------------------------------
class coor_xy{
private:
	int x;						//Coordenada x.
	int y;						//Coordenada y.
public:
	coor_xy(int cord_x=0, int cord_y=0);		//Constructor de objeto coordenada, establece coordenada en 0;0;.
	
	void setXY(int cord_x, int cord_y);		//Actualiza la coordenada.
	void getXY(int *X, int *Y);			//Devuelve datos de coordenada.
};
//---------------------------------------------------------------------------------------------------------------------------



//CLASE WORM (GUSANO/VIVORITA):
//---------------------------------------------------------------------------------------------------------------------------
class worm{
private:
	int largo;					//Largo del gusano.
	int direccion;					//Direccion del gusano.
	coor_xy posicion;				//Ubicacion del gusano.
public:
	worm();						//Constructor.
	void setUbicacion(int cord_x, int cord_y);	//Establece la ubicacion del gusano.
	void getUbicacion(int *cord_x, int *cord_y);	//Devuelve la ubicacion del gusano.
	void setDireccion(int i=0);			//Establece la direccion.
	int getDireccion();				//Devuelve la direccion.
	void alimentacion(int comida);			//Alimenta al gusano.
};
//---------------------------------------------------------------------------------------------------------------------------
#endif