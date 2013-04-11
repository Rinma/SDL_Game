#include "Framework.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	//Framework initialisieren
	if(g_pFramework->init(800, 600, 16, true) == false) {
		return 0;
	}

	//Neue Instantz des Spiels
	CGame Game;

	//Spiel initialisieren
	CGame.Init();

	/* Spiel laufen lassen. Diese funktion läuft so lange,
	 * bis das Spiel geschlossen oder die Escape-Taste
	 * gedrückt wird
	 */
	Game.Run();

	//Spiel beenden
	Game.Quit();

	//Framework beenden
	g_pFramework->Quit();
	g_pFramework->Del();

	return 0;
}