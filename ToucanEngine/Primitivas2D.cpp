#include "Primitivas2D.h"
#include "SDL_opengl.h"

void Primitivas2D::SetPosition(Vector2 _pos)
{
	myTransform.position.x = _pos.x;
	myTransform.position.y = _pos.y;
	myTransform.position.z = 0;
}

void Primitivas2D::SetPosition(float _x, float _y)
{
	myTransform.position.x = _x;
	myTransform.position.y = _y;
	myTransform.position.z = 0;
}



Primitivas2D::Primitivas2D()
{
	myTransform.position.x = 0;
	myTransform.position.y = 0;
	myTransform.position.z = 0;
	myTransform.scale.x = 1;
	myTransform.scale.y = 1;
	myTransform.scale.z = 0;
}