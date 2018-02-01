#pragma once
#include "Vector2.h"
#include "ToucanImagen.h"
#include "LinkedList.h"
class RenderGL
{
	public:
		RenderGL();
		~RenderGL();
		Button butt1;
		Button butt2;
		LinkedList<Button> buttonList;
		ToucanImagen sprite;
		float clipAreaXLeft;
		float clipAreaYTop;
		float clipAreaXRightt;
		float clipAreaYBottom;
		int h;
		int w;
		//Funcion encarga de inicializar OpenGL
		//Regresa True si se inicio correctamente o false en caso cotrario
		void inicializar();
		//Se llama al momento de libarse
		void liberar();

		//Funcion que se actualiza cada frame
		void update();
		//Funcion encargado de dibujar
		void render();
};

extern RenderGL g_renderGL; //Singleton

