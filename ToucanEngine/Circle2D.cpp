#include "Circle2D.h"
#include "SDL_opengl.h"

//Sobrecarga de funciones para modificar posicion
void Circle2D::SetPosition(Vector2 _pos)
{
	myTransform.position.x = _pos.x;
	myTransform.position.y = _pos.y;
	myTransform.position.z = 0;
}
void Circle2D::SetPosition(float _x, float _y)
{
	myTransform.position.x = _x;
	myTransform.position.y = _y;
	myTransform.position.z = 0;
}

//Sobrecarga de funciones para modificar escala
void Circle2D::SetScale(Vector2 _scale)
{
	myTransform.scale.x = _scale.x;
	myTransform.scale.y = _scale.y;
}
void Circle2D::SetScale(float _x, float _y)
{
	myTransform.scale.x = _x;
	myTransform.scale.y = _y;
}

//Modifica el radio del circulo
void Circle2D::SetRadius(float _r)
{
	radius = _r;
}

//Sobrecarga de funciones para modificar color
void Circle2D::SetColor(Vector3 _color)
{
	myColor.r = _color.x;
	myColor.g = _color.y;
	myColor.b = _color.z;
}
void Circle2D::SetColor(float _x, float _y, float _z)
{
	myColor.r = _x;
	myColor.g = _y;
	myColor.b = _z;
}

//Constructor Basico
Circle2D::Circle2D()
{
	myTransform.position.x = 0;
	myTransform.position.y = 0;
	myTransform.position.z = 0;
	myTransform.scale.x = 1;
	myTransform.scale.y = 1;
	myTransform.scale.z = 0;
	radius = 0.1f;
}

//Funcion que imprime cuadrado con los datos de su Transform y Color
void Circle2D::Draw()
{
	glPushMatrix();
	glColor4f(myColor.r, myColor.g, myColor.b, myColor.a);
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(myTransform.position.x, myTransform.position.y);
	for (float i = 1; i < 360; i++)
	{
		pointX = myTransform.position.x + cos(i)*radius * myTransform.scale.x;
		pointY = myTransform.position.y + sin(i)*radius * myTransform.scale.y;
		glVertex2f(pointX, pointY);
	}
	
	glEnd();
	glPopMatrix();
}