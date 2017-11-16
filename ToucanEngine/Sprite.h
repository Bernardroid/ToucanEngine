#pragma once
#include "SDL_image.h"
#include "SDL_opengl.h"
#include <string>

using std::string;

class Sprite
{
public:
	//ToucanImagen* Sprites;
	GLuint* textura;

	///<summary>Inicializas tu animacion con el numero de imagenes que usas y con la cantidad de frames que quieras</summary>
	void Inicializar(int _n,int _f);
	///<summary>Le mandas en donde estan hubicados los archivos en un arreglo de strings </summary>
	void CargarSprites(string paths[]);
	///<summary>Lo mandamos en el render, con la posicion x,y y el delta time</summary>
	void DibujarAnimacion(int _x, int _y,float _delta);

	/*
	Agregar
	IMG_Init(IMG_INIT_JPG);
	IMG_Init(IMG_INIT_PNG);
	Despues de SDL_Init
	&
	Agregar
	IMG_Quit();
	antes de llamar SDL_Quit();
	Agregar 
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	en el inicializar de RenderGl.cpp
	*/
	
private:
	//Dejar vacio
	int *width;
	int *height;
	SDL_Surface ** imagen;
	int mode;
	float frameActual = 0.0f;
	int fps;
	int n;

};