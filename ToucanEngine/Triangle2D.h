#pragma once
#include "Transform.h"
#include "Color.h"
#include "Vector2.h"
#include "Vector3.h"

class Triangle2D
{
private:
	float pointA = 0.1f;
	float pointB = 0.1f;
	float pointC = 0.005f;

public:
	Transform myTransform;
	Color myColor;

	//Sobrecargas de constructores
	Triangle2D();
	//Sobrecargas para modificar la posicion
	void SetPosition(Vector2 _pos);
	void SetPosition(float _x, float _y);
	//Sobrecargas para modificar la escala
	void SetScale(Vector2 _scale);
	void SetScale(float _x, float _y);
	//Sobrecargas para modificar el color
	void SetColor(Vector3 _color);
	void SetColor(float _x, float _y, float _z);
	//Define las posiciones de los puntos del triangulo
	void SetTrianglePoints(float _a, float _b, float _c);
	//Dibuja el Triangulo con los datos de su Transform(myTransform) y Color(myColor)
	void Draw();

};