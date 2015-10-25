#include "SDL.h"
#undef main
#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char* args[]) {
	Game joc;
	cout << "Prem ESC per tancar el programa." << endl;
	cout << "Prem F11 per canviar de pantalla completa a finestra." << endl;
	cout << "Si estas llegint aquest missatge, vol dir que tens el programa en mode finestra. Prem F11 per posar-lo a pantalla completa." << endl;
	if (!joc.Init("Videojocs I", 100, 100, 1280, 720, false)) {
		return 1;
	}
	while (joc.IsRunning()) {
		joc.EventHandler();
		joc.Update();
		joc.Render();
	}
	joc.Clear();
	return 0;
}
