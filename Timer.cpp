#include "Timer.h"

//Konstruktor
CTimer::CTimer()
{
	//Initialisierung
	m_fCurTime = 0.0f;
	m_fLastTime = SDL_GetTicks() / 1000.0f;
	m_fElapsed = 0.0f;
}// Fin: Konstruktor

//Update
//Description: Timer updaten
void CTimer::Update()
{
	//Vergangene Zeit seit dem letzen Frame berechnen
	m_fCurTime = SDL_GetTicks() / 1000.0f;

	m_fElapsed = m_fCurTime - m_fLastTime;
	m_fLastTime = m_fCurTime;
} //Fin: Update