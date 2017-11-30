#pragma once
#include <Windows.h>
//#include "SDL_opengl.h"
#include "Vector2.h"
#include "Toucan_Imagen.h"
#include "tweeny\tweeny.h"


	bool calcSpeed = false;
	bool calcRotvel = false;
	bool calcScalevel = false;

	unsigned int currentTime=0;
	int timerTween=0;
	int tweenDur=0;
	float speedx=0;
	float speedy=0;
	float rotvelz = 0;
	float scalevelx = 0;
	float scalevely = 0;

	tweeny::tween<int> tween;

	///Mover(Render)
	//Mover Objeto en tiempo determinado desde pos Actual
	void MoverLocal(Toucan_Imagen* _imagen, Vector2 _to, float time);
	void MoverGlobal(Toucan_Imagen* _imagen, Vector2 _to, float time);


	///Rotar(Render)
	//Rotar Objeto en tiempo determinado desde rot Actual
	void Rotar(Toucan_Imagen* _imagen, float _grados, float time);

	///Escalar(Render)
	//Escalar Objeto en tiempo determinado desde escala actual
	void Escalar(Toucan_Imagen* _imagen, float _scalex, float _scaley, float time);

	///Manejar Tiempo (Update)
	void InicioTiempo();
	///Declarar tween (Inicializar)
	//Declara Tween Para determianr el Tiempo del movimiento
	void DeclararTween(int _from, int _to, int _during);
	///
	void doMoverLocal(Toucan_Imagen* _imagen);
	void doMoverGlobal(Toucan_Imagen* _imagen);

	void doRotar(Toucan_Imagen* _imagen);
	void doEscalar(Toucan_Imagen* _imagen);
