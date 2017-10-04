#include "Toucan_Imagen.h"
Toucan_Imagen::Toucan_Imagen()
{

}
void Toucan_Imagen::CargarImagen(const char * _url)
{
	Imagen = IMG_Load(_url);
	Mode = GL_RGB;
	if (Imagen->format->BytesPerPixel == 4)
	{
		Mode = GL_RGBA;
	}

	//Genra la textura y le pone los parametros
	glGenTextures(1, &textura);
	glBindTexture(GL_TEXTURE_2D, textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, Mode, Imagen->w, Imagen->h, 0, Mode, GL_UNSIGNED_BYTE, Imagen->pixels);
	width = (Imagen->w)*0.01;
	height = (Imagen->h)*0.01;
	


}
void Toucan_Imagen::DibujarImagen(int _x, int _y)
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
