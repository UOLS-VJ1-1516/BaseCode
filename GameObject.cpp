#include "GameObject.h"
#include "TextureManager.h"


void GameObject::clean() {
	TextureManager::Instance()->clearFromTextureMap(m_textureID);
}