#include "Transform.h"
#include "Vector2.h"
#pragma once
class Primitivas2D
{
private:

	Transform myTransform;
	//Color myColor;

public:

	virtual void Virtual() = 0;

	Primitivas2D();

	void SetPosition(Vector2 _pos);
	void SetPosition(float _x, float _y);

	//void SetColor(Color _color);
	//void SetColor(float _r, float _g, float _b);
};