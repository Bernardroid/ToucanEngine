#include "Square2D.h"
#include "SDL_opengl.h"

//Sobrecarga de funciones para modificar posicion
void Square2D::SetPosition(Vector2 _pos)
{
	myTransform.position.x = _pos.x;
	myTransform.position.y = _pos.y;
	myTransform.position.z = 0;
}
void Square2D::SetPosition(float _x, float _y)
{
	myTransform.position.x = _x;
	myTransform.position.y = _y;
	myTransform.position.z = 0;
}

//Sobrecarga de funciones para modificar escala
void Square2D::SetScale(Vector2 _scale)
{
	myTransform.scale.x = _scale.x;
	myTransform.scale.y = _scale.y;
}
void Square2D::SetScale(float _x, float _y)
{
	myTransform.scale.x = _x;
	myTransform.scale.y = _y;
}

//Sobrecarga de funciones para modificar color
void Square2D::SetColor(Vector3 _color)
{
	myColor.r = _color.x;
	myColor.g = _color.y;
	myColor.b = _color.z;
}
void Square2D::SetColor(float _x, float _y, float _z)
{
	myColor.r = _x;
	myColor.g = _y;
	myColor.b = _z;
}

//Constructor Basico
Square2D::Square2D()
{
	myTransform.position.x = 0;
	myTransform.position.y = 0;
	myTransform.position.z = 0;
	myTransform.scale.x = 1;
	myTransform.scale.y = 1;
	myTransform.scale.z = 0;
}

//Funcion que imprime cuadrado con los datos de su Transform y Color
void Square2D::Draw()
{
	glPushMatrix();
		glColor4f(myColor.r, myColor.g, myColor.b, myColor.a);
		glBegin(GL_QUADS);
		glVertex2f(-(0.1f * myTransform.scale.x) + myTransform.position.x, -(0.1f * myTransform.scale.y) + myTransform.position.y);
		glVertex2f((0.1f * myTransform.scale.x) + myTransform.position.x, -(0.1f * myTransform.scale.y) + myTransform.position.y);
		glVertex2f((0.1f * myTransform.scale.x) + myTransform.position.x, (0.1f * myTransform.scale.y) + myTransform.position.y);
		glVertex2f(-(0.1f * myTransform.scale.x) + myTransform.position.x, (0.1f * myTransform.scale.y) + myTransform.position.y);
		glEnd();
	glPopMatrix();
}