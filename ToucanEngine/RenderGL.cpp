#include "RenderGL.h"
#include "SDL_opengl.h"
#include "Square2D.h"
#include <GL\GLU.h>

RenderGL g_renderGL; //SIngleton

RenderGL::RenderGL()
{
}

void RenderGL::inicializar()
{
	GLenum error = GL_NO_ERROR;
	//Para obtener error: error = glGetError();

	//Inicializamos Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);
}

void RenderGL::liberar()
{
}

void RenderGL::update()
{
}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT);
	Square2D mySquare;
	Vector2 destination(0.5f,0);
	mySquare.DrawSquare();
	mySquare.MoveTo(destination);

}


