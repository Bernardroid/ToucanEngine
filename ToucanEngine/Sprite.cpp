#include "Sprite.h"

void Sprite::Inicializar(int _n,int _f)
{
	n = _n;
	fps = _f;
	mode = GL_RGBA;
	textura = new GLuint[n];
	glGenTextures(n, textura);
}

void Sprite::CargarSprites(string paths[])
{
	width = new int[n];
	height = new int[n];
	imagen = new SDL_Surface *[n];
	for (int i = 0; i < n; i++)
	{		
		imagen[i] = IMG_Load(paths[i].c_str());
		
		glGenTextures(1, &textura[i]);
		glBindTexture(GL_TEXTURE_2D, textura[i]);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, mode, imagen[i]->w, imagen[i]->h, 0, mode, GL_UNSIGNED_BYTE, imagen[i]->pixels);
		width[i] = (imagen[i]->w)*0.1;
		height[i] = (imagen[i]->h)*0.1;

	}
}

void Sprite::DibujarAnimacion(int _x, int _y,float _delta)
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textura[(int)frameActual]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);	glVertex2f(-_x - (width[(int)frameActual] *0.5), -_y - (height[(int)frameActual] *0.5));
	glTexCoord2f(1, 1); glVertex2f(_x + ( width[(int)frameActual] *0.5), -_y - (height[(int)frameActual] *0.5));
	glTexCoord2f(1, 0); glVertex2f(_x + ( width[(int)frameActual] *0.5), _y + ( height[(int)frameActual] *0.5));
	glTexCoord2f(0, 0); glVertex2f(-_x - (width[(int)frameActual] *0.5), _y + ( height[(int)frameActual] *0.5));
	glEnd();
	glPopMatrix();

	///Actualizo el frameActual
	frameActual += fps * _delta;
	if (frameActual >= n - 1) ///Regresamos a repetir animacion
	{
		frameActual -= n - 1;
	}
}