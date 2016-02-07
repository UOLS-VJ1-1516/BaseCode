#pragma once
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
#include <string>
#include "Vector2D.h"

class LoaderParams
{
public:
	LoaderParams(int width, int height, std::string textureID, int currentRow, int sprits, int flip,int callBackID, Vector2D position, Vector2D velocity, Vector2D maxVelocity, Vector2D acceleration, Vector2D friction) {
		m_width = width;
		m_height = height;
		m_textureID = textureID;
		m_currentRow = currentRow;
		m_sprits = sprits;
		m_flip = flip;
		m_position = position;
		m_velocity = velocity;
		m_maxVelocity = maxVelocity;
		m_acceleration = acceleration;
		m_friction = friction;
		m_callbackID = callBackID;
	}

	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getCurrentRow() const { return m_currentRow; }
	int getSprits() const { return m_sprits; }
	int getFlip() const { return m_flip; }
	int getCallbackID() const { return m_callbackID; }
	Vector2D getPosition() const { return m_position; }
	Vector2D getVelocity() const { return m_velocity; }
	Vector2D getMaxVelocity() const { return m_maxVelocity; }
	Vector2D getAcceleration() const { return m_acceleration; }
	Vector2D getFriction() const { return m_friction; }
	std::string getTextureID() const { return m_textureID; }

private:
	
	int m_width;
	int m_height;
	int m_currentRow;
	int m_sprits;
	int m_flip;
	int m_callbackID;
	std::string m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_maxVelocity;
	Vector2D m_acceleration;
	Vector2D m_friction;
};
#endif LOADERPARAMS_H
