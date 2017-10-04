#pragma once
#include <string>
#include "SDL_image.h"
#include "SDL_opengl.h"

using std::string;

class ToucanImagen
{
public:
	///<summary>Constructores</summary>
	ToucanImagen();
	///<summary>Carga una imagen de la ubicacion dada </summary>
	void CargarImagen(const char * _url);
	///<summary>Dibuja la imagen en su posicion dada </summary>
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
	SDL_Surface * imagen;
	int mode;

};