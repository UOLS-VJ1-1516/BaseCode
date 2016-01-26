#pragma once
#include "TextureManager.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "TileLayer.h"

class GameObject
{

	public:
		GameObject() {}
		virtual ~GameObject() {}
		virtual void load(const LoaderParams* pParams) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;
		void setCollisionLayers(std::vector<TileLayer*>* layers) { m_pCollisionLayers = layers; }

	protected:
		std::string m_textureID;
		std::string m_fileName;
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		int m_spriteNum;
		Vector2D m_position;
		Vector2D m_velocity;
		Vector2D m_maxVelocity; 
		Vector2D m_acceleration;
		Vector2D m_friction;
		Vector2D m_minVelocity;
		std::vector<TileLayer*>* m_pCollisionLayers;

};