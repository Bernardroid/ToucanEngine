#include "Square2D.h"
#include "SDL_opengl.h"

void Square2D::SetPosition(Vector2 _pos)
{
	myTransform.position.x = _pos.x;
	myTransform.position.y = _pos.y;
	myTransform.position.z = 0;
}

void Square2D::SetScale(Vector2 _scale)
{
	myTransform.scale.x = _scale.x;
	myTransform.scale.y = _scale.y;
}

void Square2D::MoveTo(Vector2 _destination)
{
	glPushMatrix();
	glTranslatef(_destination.x, _destination.y, 0);
	glPopMatrix();
}

Square2D::Square2D()
{
	myTransform.position.x = 0;
	myTransform.position.y = 0;
	myTransform.position.z = 0;
	myTransform.scale.x = 1;
	myTransform.scale.y = 1;
	myTransform.scale.z = 0;
}

Square2D::Square2D(Vector2 _pos)
{
	myTransform.position.x = _pos.x;
	myTransform.position.y = _pos.y;
	myTransform.position.z = 0;
	myTransform.scale.x = 1;
	myTransform.scale.y = 1;
	myTransform.scale.z = 0;
}

Square2D::Square2D(Vector2 _pos, float _scale)
{
	myTransform.position.x = _pos.x;
	myTransform.position.y = _pos.y;
	myTransform.position.z = 0;
	myTransform.scale.x = _scale;
	myTransform.scale.y = _scale;
	myTransform.scale.z = 0;

}
void Square2D::DrawSquare()
{
	glBegin(GL_QUADS);
	glVertex2f(-(0.1f * myTransform.scale.x) + myTransform.position.x, -(0.1f * myTransform.scale.y) + myTransform.position.y);
	glVertex2f((0.1f * myTransform.scale.x) + myTransform.position.x, -(0.1f * myTransform.scale.y) + myTransform.position.y);
	glVertex2f((0.1f * myTransform.scale.x) + myTransform.position.x, (0.1f * myTransform.scale.y) + myTransform.position.y);
	glVertex2f(-(0.1f * myTransform.scale.x) + myTransform.position.x, (0.1f * myTransform.scale.y) + myTransform.position.y);
	glEnd();

}