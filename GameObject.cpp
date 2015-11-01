#include "GameObject.h"


char* m_texid;



	GameObject::GameObject() {  //Constructor

	}
	GameObject::~GameObject() {

	}
	bool GameObject::load(const LoadPar* lPar) {
		m_width = lPar->getwidth();
		m_height = lPar->getheight();
		m_x = lPar->getx();
		m_y = lPar->gety();
		m_texid = lPar->gettexid();
		m_currentFrame = lPar->getcurrentFrame();
		m_currentRow = lPar->getcurrentRow();
		m_sprits = lPar->getsprits();


	}
		
		
		
		bool GameObject::load(int x, int y, int width, int height, char* texid) {
		 m_x = x;
		 m_y = y;
		 m_width = width;
		 m_height = height;
		 m_texid = texid;
		 m_currentFrame = 0;
		 m_currentRow = 0;
		 m_sprits = 0;
		 m_flip = 0;


		 return true;
	}
		
	void GameObject::draw(SDL_Renderer* g_lRenderer) {
		TextureManager::Instance()->drawFrame(m_texid, m_x, m_y, m_width, m_height, m_currentRow,m_currentFrame,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);
		SDL_RenderPresent(g_lRenderer);

	}
	void GameObject::update() {
		m_currentFrame = ((SDL_GetTicks() / 100) % m_sprits);

	}
	void clean() {

	}
	
