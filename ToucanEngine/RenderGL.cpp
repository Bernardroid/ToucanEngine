#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include "Square2D.h"
#include "ToucanImagen.h"

RenderGL g_renderGL; //Singleton

RenderGL::RenderGL()
{
}
RenderGL::~RenderGL()
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
	
	sprite.CargarImagen("jiggly.png");
	
	float aspect =(float)w / (float)h;

	if (w >= h)
	{
		clipAreaXLeft=-10.0*aspect;
		clipAreaXRightt = 10.0*aspect;
		clipAreaYBottom = -10.0;
		clipAreaYTop = 10.0;
	}
	else
	{
		clipAreaXLeft = -10.0;
		clipAreaXRightt = 10.0;
		clipAreaYBottom = -10.0/aspect;
		clipAreaYTop = 10.0/aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRightt, clipAreaYBottom, clipAreaYTop);
	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	butt1.SetButton(12.5, -7.5, 5, 5);
	butt2.SetButton(-12.5, -7.5, 5,5);
	buttonList.Add(butt1);
	buttonList.Add(butt2);
}

void RenderGL::liberar()
{
	//delete this
}

void RenderGL::update()
{
	
}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT);
	//sprite.DibujarImagen(0,0);

	butt1.DrawButton();
	butt2.DrawButton();

}


