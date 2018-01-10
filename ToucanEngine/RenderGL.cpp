#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <stdio.h>
#include <iostream>

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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);

	//Variables


	jiggly.CargarImagen("jiggly.png");
	gluOrtho2D(-10, 10, -10, 10);
	

	//Inicializar

	DeclararTween(0, 5, 5);
	
	
	//Update
	jiggly.SetPos(posJig);

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
	InicioTiempo();
}

void RenderGL::render()
{
	//jiggly.angle = 45;
	//jiggly.scalex = 0.5f;

	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT);
	jiggly.SetRotation(90);
	jiggly.DibujarImagen();
	//MoverGlobal(&jiggly, Vector2(15, 0), 5);
	//Rotar(&jiggly, 90, 5);
	//Escalar(&jiggly, 3, 3, 5);


}
