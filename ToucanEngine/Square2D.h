#pragma once
#include "Vector2.h"
#include "Transform.h"
class Square2D
{
public:
	Transform myTransform;

	Square2D();
	Square2D(Vector2 _pos);
	Square2D(Vector2 _pos, float _size);
	void SetPosition(Vector2 _pos);
	void SetScale(Vector2 _scale);
	void MoveTo(Vector2 _destination);
	void DrawSquare();


};
