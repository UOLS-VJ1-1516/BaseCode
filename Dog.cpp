#include "Dog.h"
#include "TextureManager.h"
#include "game.h"

int spriteNum2;
int mov2 = 0;
int pos2 = 0;
int animacion2 = 1;
int cont2 = 0;

Dog::Dog()
{
}


Dog::~Dog()
{
}

void Dog::load(int x, int y, int width, int height, const char* textureID) {
	//texture manager
	TextureManager::Instance()->load("Dog.png", textureID, Game::Instance()->getRender());

}
void Dog::draw() {

	TextureManager::Instance()->drawFrame("imatge2", 500, 200, 64, 80, animacion2, spriteNum2, Game::Instance()->getRender(), SDL_FLIP_NONE);
	
	mov2 = mov2 + 1; //incrementamos la posición para que la imagen se mueva

	if (mov2 < 650) { //primera animació
		pos2 = mov2;
	}
	else {
		if (mov2 < 850) { //segona animació
			cont2++;
			animacion2 = 2;
			pos2 = mov2 - 425;
			SDL_Delay(10);
			if (cont2 == 4) {
				pos2 = pos2 - 1;
			}
			if (cont2 == 5) {
				pos2 = pos2 - 1;
			}
			if (cont2 == 6) {
				pos2 = pos2 - 1;
				cont2 = 0;
			}
		}
		else {
			if (mov2 < 1250) { // tercera animació
				animacion2 = 3;
				pos2 = 275;
			}
			else { //fi de la tercera animació, tornem a la primera
				animacion2 = 1;
				mov2 = 0;
			}
		}
	}
}
void Dog::update() {
	spriteNum2 = (int)((SDL_GetTicks() / 100) % 4);
}
void Dog::clean() {

}

