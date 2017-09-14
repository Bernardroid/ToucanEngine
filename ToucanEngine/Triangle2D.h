#pragma once
#include "Vector2.h"
#include "Transform.h"

class Triangle2D
{
public:
	Transform myTransform;
	Triangle2D();
	Triangle2D(Vector2 _pos);
	Triangle2D(Vector2 _pos, float _size);

	void SetPosition(Vector2 _pos);


/*
	Triangle2D();
	Triangle2D(Vector2 _pos);
	Triangle2D(Vector2 _pos, float _size);*/
	/*void SetPosition(Vector2 _pos);
	void SetScale(Vector2 _scale);
	void MoveTo(Vector2 _destination);
	void DrawSquare();*/

};