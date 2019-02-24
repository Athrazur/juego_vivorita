#ifndef MAPA_HPP
#define MAPA_HPP

class mapa{
private:
	char **matriz_mapa;				//Puntero para asignar memoria que representa el mapa.
	int x;
	int y;
	bool memoria;
public:
	mapa();
	mapa(int width, int height);			//Constructor del mapa.
	
	void definir(int height, int width);		//Define dimension del mapa.
	void erase();					//Borra y libera el mapa.
	
	bool setData(int i, int j, char data);		//Establece datos en el mapa.
	char getData(int i, int j);			//Devuelve datos en el mapa
	void setFloor(char simbol);			//Establece el simbolo del piso.
	void mostrar();					//Imprime en pantalla el mapa del mundo.
	void nc_mostrar(int nc_y, int nc_x);
	~mapa();
};

#endif