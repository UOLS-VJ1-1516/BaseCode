#include "GameObject.h" 

GameObject::GameObject() {}

GameObject::~GameObject(){}

void GameObject::load(const LoaderParams* pParams) {
	
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_sprite = pParams->getSprits();
	m_currentRow = 0;
	m_currentFrame = 0;
	
}

void GameObject::update()
{ 	
	m_position += m_velocity; 
}
