#pragma once
#include "SDL_opengl.h"


class Button
{
public:
	///<sumary>Constructor</summary>
	Button();
	//Id Funcion
	int funcId = 0;
	//Coordenadas boton
	float buttonX = 0;
	float buttonY = 0;
	//Ancho largo boton
	float width = 1;
	float height = 1;
	
	///<summary>Accion Click</summary>
	void SetFuncId(int _id);
	///<summary>Accion Click</summary>
	void OnButtonClicked();
	///<summary>Dibuja Boton</summary>
	void DrawButton();
	///<summary>Acomoda el boton en ciertas coordenadas</summary>
	void SetButton(float x, float y, float w, float h);


};
