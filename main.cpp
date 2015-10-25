#include "SDL.h"
#include "game.h"
#include "cstdlib" //libreria para random



int main(int argc, char* args[]) {

	//declaramos las variables que corresponden a los colores rgb rojo verde azul
	int a;
	int b;
	int c;
	 

	game game;
	

   
	//generamos la pantalla

	game.init("Videojuegos1",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//fuente:http://www.cplusplus.com/reference/cstdlib/rand/

	
	//hacemos que mientras el juego esta en marcha se vayan modificando los colores ya que se le ira asignando un valor random a las variables cada
	//vez que se carge una nueva ventana.

	while (game.isRunning()) {


	a = (rand() % 255) + 1;
	b = (rand() % 255) + 1;
    c = 30;

	game.update();
		game.render(a, b, c);
		
		SDL_Delay(200);
		
		
	}

	    game.clean();
		
		return 0;


	
}

