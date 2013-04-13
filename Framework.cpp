#include "Framework.h"

//init
//Aufgabe: Framework initialisieren
bool CFramework::Init(int ScreenWidth, int ScreenHeight, int ColorDepth, bool bFullscreen)
{
	//Alle Systeme der SDL initialisieren
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		Quit();

		return (false);
	}

	//Vollbild oder Fenstermodus einstellen
	if(bFullscreen == true) {
		m_pScreen = SDL_SetVideoMode(ScreenWidth, ScreenHeight, ColorDepth, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
	} else {
		m_pScreen = SDL_SetVideoMode(ScreenWidth, ScreenHeight, ColorDepth, SDL_HWSURFACE | SDL_DOUBLEBUF);
	}

	//Prüfen ob alles Funktioniert hat
	if(m_pScreen == NULL) {
		cout << "Videomodus konnte nicht gesetzt werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		Quit();

		return (false);
	}

	//Zeiger auf internes Array für tastaturstatus ermitteln
	m_pKeystate = SDL_GetKeyState(NULL);

	//Alles ging glatt, also true zurückliefern
	return (true);
} //Fin: Init