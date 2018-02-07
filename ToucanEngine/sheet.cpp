#include "sheet.h"
#define _CRT_SECURE_NO_WARNINGS

void Sheet::Iniciar(string _path)
{
	inFile.open(_path);
	if (!inFile) {
		cout << "Unable to open file";
		return;
	}
	string temp;
	/*while (inFile >> temp) {
		contenido = contenido + temp;
	}*/
	while (!inFile.eof())
	{
		std::getline(inFile, temp);
	
	}
	//cout << temp << "\n";
	contenido = temp;
	cerrar();
	//cout << contenido << "\n";
}

void Sheet::cerrar()
{
	inFile.close();
}
void Sheet::Leer(string _pathxml, string _pathimage)
{
	Iniciar(_pathxml);
	numerodeImagenes = 0;
	CargarImagen(_pathimage.c_str());

	char * pch;
	char *array = &contenido[0];

	pch = strtok(array, ",");
	numerodeImagenes++;

	while (pch != NULL)
	{
		printf("%s-\n", pch);
		pch = strtok(NULL, ",");
		numerodeImagenes++;
	}
	x = new int[numerodeImagenes];
	y = new int[numerodeImagenes];
	w = new int[numerodeImagenes];
	h = new int[numerodeImagenes];
	int cont = 0;
	nombres = new string[numerodeImagenes];

	Iniciar(_pathxml);
	array = &contenido[0];
	pch = strtok(array, ", ");

	nombres[0] = pch;
	//pch = strtok(NULL, ", ");
	pch = strtok(NULL, ", ");
	x[cont] = atoi(pch);
	pch = strtok(NULL, ", ");
	y[cont] = atoi(pch);
	pch = strtok(NULL, ", ");
	w[cont] = atoi(pch);
	pch = strtok(NULL, ", ");
	h[cont] = atoi(pch);
	cont++;
	while (cont <= (numerodeImagenes - 3))
	{

		pch = strtok(NULL, ", ");
		nombres[cont] = pch;
		pch = strtok(NULL, ", ");
		x[cont] = atoi(pch);
		pch = strtok(NULL, ", ");
		y[cont] = atoi(pch);
		pch = strtok(NULL, ", ");
		w[cont] = atoi(pch);
		pch = strtok(NULL, ", ");
		h[cont] = atoi(pch);
		//cout << "nombre " << nombres[cont] << "\n";
		cont++;

	}
	numerodeImagenes -= 3;
}

void Sheet::CargarImagen(const char * _url)
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
	truWidth = imagen->w;
	truHeigh = imagen->h;



}
void Sheet::SetPos(Vector2 _pos)
{
	pos = _pos;
}
Vector2 Sheet::GetPos()
{
	return pos;
}


//Set Rotation
void Sheet::SetRotation(float _angle)
{
	angle = _angle;
}


//Set Scale
void Sheet::SetScale(float _x, float _y)
{
	scalex = _x;
	scaley = _y;
}
//Set Scale Overload
void Sheet::SetScale(Vector2 _xy)
{
	scalex = _xy.x;
	scaley = _xy.y;
}

void Sheet::DibujarImagen(int indice)
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 1);
	glScalef(scalex, scaley, 1);
	glRotatef(angle, 0, 0, rotz);
	glTranslatef(transx, transy, 0);
	glBegin(GL_QUADS);
	float myzerow = x[indice] / (float)truWidth;
	float myzeroh = y[indice] / (float)truHeigh;
	float myonew = (x[indice] + w[indice]) / (float)truWidth;
	float myoneh = (y[indice] + h[indice]) / (float)truHeigh;


	glTexCoord2f(myzerow, myoneh);	glVertex2f(pos.x - (w[indice] *0.05), pos.y - (h[indice] *0.05));

	glTexCoord2f(myonew, myoneh); glVertex2f(pos.x + (w[indice] *0.05), pos.y - (h[indice] *0.05));

	glTexCoord2f(myonew, myzeroh); glVertex2f(pos.x + (w[indice] *0.05), pos.y + (h[indice] *0.05));

	glTexCoord2f(myzerow, myzeroh); glVertex2f(pos.x - (w[indice] *0.05), pos.y + (h[indice] *0.05));
	glEnd();
	glPopMatrix();
}



.