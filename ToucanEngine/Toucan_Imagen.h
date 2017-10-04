#pragma once
#include <string>
#include "SDL_image.h"
#include "SDL_opengl.h"

using std::string;

class Toucan_Imagen
{
public:
	//Constructores
	Toucan_Imagen();
	//Carga una imagen de la ubicacion dada 
	void CargarImagen(const char * _url);
	//Dibuja la imagen en su posicion dada
	void DibujarImagen(int _x,int _y);

	/*
	Agregar
	IMG_Init(IMG_INIT_JPG);
	IMG_Init(IMG_INIT_PNG);
	Despues de SDL_Init
	&
	Agregar
	IMG_Quit();
	antes de llamar SDL_Quit();
	*/

private:
	//Dejar vacio
	int width;
	int height;
	GLuint textura;
	SDL_Surface * Imagen;
	int Mode;

};