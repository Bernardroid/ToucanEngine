#pragma once

#include "Toucan_Tween.h"

class RenderGL
{
	public:
		RenderGL();

		//Funcion encarga de inicializar OpenGL
		//Regresa True si se inicio correctamente o false en caso cotrario
		void inicializar();
		//Se llama al momento de libarse
		void liberar();
		//Funcion que se actualiza cada frame
		void update();
		//Funcion encargado de dibujar
		void render();
		unsigned int TexturaUno;
		ToucanImagen jiggly;

		
		int maxTime = 5;

		Vector2 posJig;

};

extern RenderGL g_renderGL; //Singleton

