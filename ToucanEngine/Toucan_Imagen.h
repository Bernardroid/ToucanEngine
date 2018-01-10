#pragma once
#include <string>
#include "Vector2.h"
#include "SDL_image.h"
#include "SDL_opengl.h"
#include "tweeny\tweeny.h"


class ToucanImagen
{
public:
	
	//Constructores
	///<summary>Constructores</summary>
	ToucanImagen();
	//Carga una imagen de la ubicacion dada 
	///<summary>Carga una imagen de la ubicacion dada </summary>
	void CargarImagen(const char * _url);
	//Dibuja la imagen en su posicion dada
	///<summary>Dibuja la imagen en su posicion dada </summary>
	void DibujarImagen();

	//Get y Set de Posicion
	Vector2 GetPos();
	void SetPos(Vector2 _pos);
	
	//Rotacion
	float angle;
	float rotz=1;
	//Set Rotation
	void SetRotation(float _angle);
	
	//Set Scale
	void SetScale(float _x, float _y);
	void SetScale(Vector2 _xy);
	//Escala
	float scalex = 1;
	float scaley = 1;
	//Posicion
	Vector2 pos;
	float transx = 0;
	float transy = 0;

	
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