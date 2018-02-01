#include "SDL.h"
#include "RenderGL.h"
#include <stdio.h>
#include <string>

//Dimensiones de la ventana
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 1000;

//Inicializa SDL, crea ventana y lo liga a openGL
bool init();
//Manejador de teclado con posicion del mouse
void handleKeys(unsigned char _key, int _x, int _y);
//Manejador de mouse
void handleMouse(SDL_Event* _evt, int _x, int _y);

//Liberar media y SDL
void close();

//Referencia a la ventana de windows
SDL_Window* gWindow = NULL;
//Referencia a OpenGl con SDL
SDL_GLContext gContext;

//------CORE ------------------------------------------------------------------------------------

//Teclado
void handleKeys(unsigned char _key, int _x, int _y)
{
	//Toggle quad
	if (_key == 'a')
	{
	}
}

//Mouse
void handleMouse(SDL_Event* _evt, int _x, int _y)
{
	//Click mouse izq
	if (_evt->button.button == SDL_BUTTON_LEFT)
	{
		//_x de 0 a 1500 izq a der
		//_y de 0 a 1000 arr a abajo
		//x -15 a 15
		//y -10 a 10
		//Cambia coordenadas de pantalla a coordenadas de camara Ortho
		float x = (((float)_x * 2) - 1500) / 100;
		float y = (((float)_y * 2) - 1000) / -100;
		//Checa los botones al hacerles click
		for (int i = 1; i <= g_renderGL.buttonList.Count(); i++)
		{
			if (x <= g_renderGL.buttonList.GetValue(i).buttonX + (g_renderGL.buttonList.GetValue(i).width*0.5) && x >= g_renderGL.buttonList.GetValue(i).buttonX - (g_renderGL.buttonList.GetValue(i).width*0.5) && y <= g_renderGL.buttonList.GetValue(i).buttonY + (g_renderGL.buttonList.GetValue(i).height*0.5) && y >= g_renderGL.buttonList.GetValue(i).buttonY - (g_renderGL.buttonList.GetValue(i).height*0.5))
			{
				g_renderGL.buttonList.GetValue(i).OnButtonClicked();
			}
		}
	}
}

//------ FIN CORE -------------------------------------------------------------------------------


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		IMG_Init(IMG_INIT_JPG);
		IMG_Init(IMG_INIT_PNG);
		//Indicamos que usaremos OPenGL
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

		//Creamos Ventana
		gWindow = SDL_CreateWindow("Toucan Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//SDL_GetRendererOutputSize(gWindow, &g_renderGL.w, &g_renderGL.h);
			g_renderGL.w= SDL_GetWindowSurface(gWindow)->w;
			g_renderGL.h = SDL_GetWindowSurface(gWindow)->h;
			//Creamos COntexto de OpenGL
			gContext = SDL_GL_CreateContext(gWindow);
			if (gContext == NULL)
			{
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Activamos VSync
				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}

				//Inicializamos OpenGL
				g_renderGL.inicializar();
			}
		}
	}
	
	return success;
}

void close()
{
	//Liberamos OpenGL
	g_renderGL.liberar();
	//Destruimos ventana
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//Cerramos SDL
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Error al inicializar!\n");
		system("pause");
	}
	else
	{
		//GameLoop
		bool GameLoop = false;

		//Manejador de evento
		SDL_Event e;

		//Se activa deteccion de teclado
		SDL_StartTextInput();

		//GameLoop
		while (!GameLoop)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT) //Salir
				{
					GameLoop = true;
				}
				else if (e.type == SDL_TEXTINPUT) //Evento de teclado
				{
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					handleKeys(e.text.text[0], x, y);
				}
				else if (e.type = SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEMOTION)
				{
					//obtenemos mouse
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					handleMouse(&e, x, y);
				}				
			}

			//Update
			g_renderGL.update();
			//Dibujamos
			g_renderGL.render();
			
			//Actualizamos pantalla
			SDL_GL_SwapWindow(gWindow);
		}

		//Desactivamos detectar teclado
		SDL_StopTextInput();
	}

	//Cerramos y desactivamos SDL
	close();

	return 0;
}