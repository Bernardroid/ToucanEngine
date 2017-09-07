#pragma once
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
};

extern RenderGL g_renderGL; //Singleton

