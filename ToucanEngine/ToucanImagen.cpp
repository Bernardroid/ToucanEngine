#include "ToucanImagen.h"
ToucanImagen::ToucanImagen()
{

}
void ToucanImagen::CargarImagen(const char * _url)
{
	imagen = IMG_Load(_url);
	mode = GL_RGB;
	if (imagen->format->BytesPerPixel == 4)
	{
		mode = GL_RGBA;
	}

	//Genra la textura y le pone los parametros
	glGenTextures(1, &textura);
	glBindTexture(GL_TEXTURE_2D, textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, mode, imagen->w, imagen->h, 0, mode, GL_UNSIGNED_BYTE, imagen->pixels);
	width = (imagen->w)*0.01;
	height = (imagen->h)*0.01;
	


}
void ToucanImagen::DibujarImagen(int _x, int _y)
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 1);	glVertex2f(-_x-(width*0.5), -_y-(height*0.5));
	glTexCoord2f(0, 1); glVertex2f(_x+(width*0.5), -_y- (height *0.5));
	glTexCoord2f(0, 0); glVertex2f(_x+ (width *0.5), _y+ (height *0.5));
	glTexCoord2f(1, 0); glVertex2f(-_x- (width *0.5), _y+ (height *0.5));
	glEnd();
	glPopMatrix();
}
