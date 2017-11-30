#include "Toucan_Tween.h"


void doMoverLocal(Toucan_Imagen* _imagen)
{
	if (timerTween <= tweenDur)
	{
		_imagen->pos.x += speedx;
		_imagen->pos.y += speedy;
	}
}
void doMoverGlobal(Toucan_Imagen* _imagen)
{
	if (timerTween <= tweenDur)
	{
		_imagen->transx += speedx;
		_imagen->transy += speedy;
	}
}
void doRotar(Toucan_Imagen* _imagen)
{
	if (timerTween <= tweenDur)
	{
		_imagen->angle += rotvelz;
	}

}
void doEscalar(Toucan_Imagen* _imagen)
{
	if (timerTween <= tweenDur)
	{
		_imagen->scalex += scalevelx;
		_imagen->scaley += scalevely;
	}
}
void InicioTiempo()
{
	currentTime = SDL_GetTicks();
	currentTime /= 5000;
	timerTween += currentTime;
}
void DeclararTween(int _from, int _to, int _during)
{
	tween = tweeny::from(_from).to(_to).during(_during);
	tweenDur = tween.duration();
}
void MoverLocal(Toucan_Imagen * _imagen, Vector2 _to, float time)
{
	if (calcSpeed == false)
	{
		tweenDur = time;

		float from_x = _imagen->GetPos().x;
		float from_y = _imagen->GetPos().y;
		float to_x = _to.x;
		float to_y = _to.y;
		speedx = to_x - from_x;
		speedy = to_y - from_y;
		speedx *= time;
		speedy *= time;
		speedx /= 1250;
		speedy /= 1250;
		calcSpeed = true;
	}
	doMoverLocal(_imagen);
}
void MoverGlobal(Toucan_Imagen * _imagen, Vector2 _to, float time)
{
	if (calcSpeed == false)
	{
		tweenDur = time;

		float from_x = _imagen->GetPos().x;
		float from_y = _imagen->GetPos().y;
		float to_x = _to.x;
		float to_y = _to.y;
		speedx = to_x - from_x;
		speedy = to_y - from_y;
		speedx *= time;
		speedy *= time;
		speedx /= 1250;
		speedy /= 1250;
		calcSpeed = true;
	}
	doMoverGlobal(_imagen);
}
void Rotar(Toucan_Imagen* _imagen, float _grados, float time)
{
	if (calcRotvel == false)
	{
		tweenDur = time;
		float from_angle = _imagen->angle;
		float to_angle = _grados;
		rotvelz = to_angle - from_angle;
		rotvelz *= time;
		rotvelz /= 1250;


		calcRotvel = true;
	}
	doRotar(_imagen);
}
void Escalar(Toucan_Imagen* _imagen, float _scalex, float _scaley, float time)
{
	if (calcScalevel == false)
	{
		tweenDur = time;

		float from_x = _imagen->scalex;
		float from_y = _imagen->scaley;
		float to_x = _scalex;
		float to_y = _scaley;
		scalevelx = to_x - from_x;
		scalevely = to_y - from_y;
		scalevelx *= time;
		scalevely *= time;
		scalevelx /= 1250;
		scalevely /= 1250;
		calcScalevel = true;
	}
	doEscalar(_imagen);
}