#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;
TextureManager::TextureManager() {};

//Método de carga de imágenes.
bool TextureManager::load(const char* fileName, const char* id, SDL_Renderer* pRenderer) {
	//Cargamos el fichero de la imagen BMP. La almacenamos en la surface.
	s_surface = SDL_LoadBMP(fileName);

	/*La imagen origen tiene de fondo un color rosa estridente, para dejar clara la parte que queremos trasparentar.
	Con la siguiente línea, pasamos la surface, un 1 (para afirmar que queremos trasparentar un color) y por último
	el color de formato del surface que queremos transparentar, en este caso el 255,0,255.*/
	SDL_SetColorKey(s_surface, 1, SDL_MapRGB(s_surface->format, 255, 0, 255));

	//Creamos la textura.
	s_texture = SDL_CreateTextureFromSurface(pRenderer, s_surface);

	//Almacenamos la textura en un map.
	m_textureMap[*id] = s_texture;

	return true;
};

void TextureManager::draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.x = 0;
	TextureManager::SrcR.y = 0;
	/*TextureManager::SrcR.w = m_textureSizes[*id][0];
	TextureManager::SrcR.h = m_textureSizes[*id][1];*/
	TextureManager::SrcR.w = width;
	TextureManager::SrcR.h = height;

	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

void TextureManager::drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	/*TextureManager::SrcR.x = currentFrame*m_textureSizes[*id][0];
	TextureManager::SrcR.y = currentRow*m_textureSizes[*id][1];
	TextureManager::SrcR.w = m_textureSizes[*id][0];
	TextureManager::SrcR.h = m_textureSizes[*id][1];*/ //Parte reservada para otra versión de programa, donde poder jugar con el tamaño final del sprite.
	
	//Recuadro de origen donde pasamos el frame y tamaño por el que nos vamos a desplazar en la imagen. Puntos de origen y tamaño del rectángulo.
	TextureManager::SrcR.x = currentFrame*width;
	TextureManager::SrcR.y = currentRow*height;
	TextureManager::SrcR.w = width;
	TextureManager::SrcR.h = height;

	//Recuadro destino donde vamos a pintarlo
	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;

	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);//Los tres últimos parametros son para girar o voltear el sprite, no los usamos.
};

//Método que nos permitirá almacenar el tamaño del sprite.
void TextureManager::setSizeFrames(const char* id, int w, int h) {
	m_textureSizes[*id][0] = w;
	m_textureSizes[*id][1] = h;
}

TextureManager::~TextureManager(){
	
};


