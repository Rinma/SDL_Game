#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>
#include "Singleton.h"
#include "Timer.h"

using namespace std;

#define g_pFramework CFramework::Get()

class CFramework : public TSingleton<CFramework>
{
	public bool Init(int ScreenWidth, int ScreenHeight, int ColorDepth, bool Fullscreen);
	void Quit();
	void Update();
	void Clear();
	void Flip();
	bool KeyDown(int Key_ID);
	SDL_Surface *GetScreen() {return m_pScreen;}

private:
	SDL_Surface *m_pScreen;		//Surface für den Screen
	Uint8		*m_pKeystate;	//Array für den aktuellen Tastaturstatus
}

#endif