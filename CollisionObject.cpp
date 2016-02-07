#pragma once
#include "CollisionObject.h"
#include <vector>
#include "TileLayer.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "GameOver.h"


CollisionObject::CollisionObject() {
	m_stopArriba = false;
	m_stopAbajo = false;
	m_stopDerecha = false;
	m_stopIzquierda = false;
	colisionmuerte = false;
	m_energyX = .0f;
	m_energyY = .0f;
	m_stopPositionArriba = Vector2D();
	m_stopPositionAbajo = Vector2D();
	m_stopPositionDerecha = Vector2D();
	m_stopPositionIzquierda = Vector2D();

	m_acceleration.setX(0);
	m_acceleration.setY(1);
}
CollisionObject::~CollisionObject() {

}
void CollisionObject::load(const LoaderParams* pParams) {

}
void CollisionObject::draw()
{

}
void CollisionObject::update()
{
	if (m_position.getX() < 0) {
		stopX(0);
		m_saltoAire = true;
	}
	if (m_position.getY() < 0) {
		stopY(0);
	}
	if (m_position.getY() > (Game::Instance()->getScreenHeight() - m_height)) {
		stopY(Game::Instance()->getScreenHeight() - m_height);
		m_estoyEnElSuelo = true;
		m_saltoBase = true;
		m_saltoAire = true;
	}

	m_velocity += m_acceleration;
	if (m_velocity.getY() > m_maxVelocity) {
		m_velocity.setY(m_maxVelocity);
	}
	m_friction = m_velocity*(-m_frictionCoeficient);
	if (m_estoyEnElSuelo) {
		m_velocity.setX(m_velocity.getX() + m_friction.getX());
	}


	if (m_velocity.getX() > 0) {
		if (isCollisionWithRightWall()) {
			m_position.setX(m_position.getX() - m_velocity.getX()*0.5);
			//m_position -= m_velocity*0.5;
			float paradaAnterior = m_stopPositionDerecha.getX();
			if (isCollisionWithRightWall()) {
				if (std::strcmp(m_textureID, "xic") == 0) {
					m_acceleration.setY(1);
					m_velocity.setX(-m_velocity.getX());
				}
				else {
					//printf("->HAY COLISION CON PARED DERECHA\n");
					stopX(m_stopPositionDerecha.getX());
				}
			}
			else {
				//printf("->HAY COLISION CON PARED DERECHA 2\n");
				stopX(paradaAnterior);
			}
		}
	}
	else if (m_velocity.getX() < 0) {
		if (isCollisionWithLeftWall()) {
			m_position.setX(m_position.getX() - m_velocity.getX()*0.5);
			//m_position -= m_velocity*0.5;
			float paradaAnterior = m_stopPositionIzquierda.getX();
			if (isCollisionWithLeftWall()) {
				//printf("->HAY COLISION CON PARED --> IZQUIERDA\n");
				if (std::strcmp(m_textureID, "xic") == 0) {
					m_acceleration.setY(1);
					m_velocity.setX(-m_velocity.getX());
				}
				else {
					stopX(m_stopPositionIzquierda.getX());
				}
			}
			else {
				//printf("->HAY COLISION CON PARED --> IZQUIERDA 2\n");
				stopX(paradaAnterior);
			}
		}
	}
	if (m_velocity.getY() > 0) {
		if (isCollisionWithFloor()) {
			m_position.setY(m_position.getY() - m_velocity.getY()*0.5);
			//m_position -= m_velocity*0.5;
			float paradaAnterior = m_stopPositionAbajo.getY();
			if (isCollisionWithFloor()) {
				if (std::strcmp(m_textureID, "xic") == 0) {
					m_acceleration.setY(-1);
					m_velocity.setY(-m_velocity.getY());
				}
				else {
					stopY(m_stopPositionAbajo.getY());
				}
				//printf("->HAY COLISION CON SUELO\n");
			}
			else {
				stopY(paradaAnterior);
				//printf("->HAY COLISION CON SUELO 2\n");
			}
			m_saltoBase = true;
			m_saltoAire = true;
			m_estoyEnElSuelo = true;
		}
		else {
			m_saltoBase = false;
			m_estoyEnElSuelo = false;
		}
	}
	else if (m_velocity.getY() < 0) {
		if (isCollisionWithCeil()) {
			m_position.setY(m_position.getY() - m_velocity.getY()*0.5);
			//m_position -= m_velocity*0.5;
			float paradaAnterior = m_stopPositionArriba.getY();
			if (isCollisionWithCeil()) {
				if (std::strcmp(m_textureID, "xic") == 0) {
					m_acceleration.setY(1);
					m_velocity.setY(-m_velocity.getY());
				}
				else {
					stopY(m_stopPositionArriba.getY());
				}
				//printf("->HAY COLISION CON TECHO\n");
			}
			else {
				stopY(paradaAnterior);
				//printf("->HAY COLISION CON TECHO 2\n");
			}
		}
	}
	m_position += m_velocity;
}

void CollisionObject::clean()
{

}

void CollisionObject::stopX(int positionX)
{
}

void CollisionObject::stopY(int positionY)
{
}

void CollisionObject::onCollision(GameObject * go)
{
	if (std::strcmp(go->getId(), "tim") == 0 || std::strcmp(go->getId(), "xic") == 0)
	{
		Game::Instance()->getGameStateMachine()->pushState(new GameOver());
	}
	else {
		Game::Instance()->getGameStateMachine()->pushState(new MenuState());
	}
}

bool CollisionObject::isCollisionWithFloor() {
	m_stopArriba = false;
	m_stopAbajo = false;
	m_stopDerecha = false;
	m_stopIzquierda = false;
	m_stopPositionArriba.setX(0);m_stopPositionArriba.setY(0);
	m_stopPositionAbajo.setX(0);m_stopPositionAbajo.setY(0);
	m_stopPositionDerecha.setX(0);m_stopPositionDerecha.setY(0);
	m_stopPositionIzquierda.setX(0);m_stopPositionIzquierda.setY(0);
	m_energyX = .0f;
	m_energyY = .0f;
	for (std::vector<TileLayer*>::const_iterator it = CollisionObject::m_pCollisionLayers->begin(); it != CollisionObject::m_pCollisionLayers->end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		buscarColisionesAbajo(pTileLayer);
	}
	return m_stopAbajo;
}

bool CollisionObject::isCollisionWithCeil() {
	m_stopArriba = false;
	m_stopAbajo = false;
	m_stopDerecha = false;
	m_stopIzquierda = false;
	m_stopPositionArriba.setX(0);m_stopPositionArriba.setY(0);
	m_stopPositionAbajo.setX(0);m_stopPositionAbajo.setY(0);
	m_stopPositionDerecha.setX(0);m_stopPositionDerecha.setY(0);
	m_stopPositionIzquierda.setX(0);m_stopPositionIzquierda.setY(0);
	m_energyX = .0f;
	m_energyY = .0f;
	for (std::vector<TileLayer*>::const_iterator it = CollisionObject::m_pCollisionLayers->begin(); it != CollisionObject::m_pCollisionLayers->end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		buscarColisionesArriba(pTileLayer);
	}
	return m_stopArriba;
}

bool CollisionObject::isCollisionWithRightWall() {
	m_stopArriba = false;
	m_stopAbajo = false;
	m_stopDerecha = false;
	m_stopIzquierda = false;
	m_stopPositionArriba.setX(0);m_stopPositionArriba.setY(0);
	m_stopPositionAbajo.setX(0);m_stopPositionAbajo.setY(0);
	m_stopPositionDerecha.setX(0);m_stopPositionDerecha.setY(0);
	m_stopPositionIzquierda.setX(0);m_stopPositionIzquierda.setY(0);
	m_energyX = .0f;
	m_energyY = .0f;
	for (std::vector<TileLayer*>::const_iterator it = CollisionObject::m_pCollisionLayers->begin(); it != CollisionObject::m_pCollisionLayers->end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		buscarColisionesDerecha(pTileLayer);
	}
	return m_stopDerecha;
}

bool CollisionObject::isCollisionWithLeftWall() {
	m_stopArriba = false;
	m_stopAbajo = false;
	m_stopDerecha = false;
	m_stopIzquierda = false;
	m_stopPositionArriba.setX(0);m_stopPositionArriba.setY(0);
	m_stopPositionAbajo.setX(0);m_stopPositionAbajo.setY(0);
	m_stopPositionDerecha.setX(0);m_stopPositionDerecha.setY(0);
	m_stopPositionIzquierda.setX(0);m_stopPositionIzquierda.setY(0);
	m_energyX = .0f;
	m_energyY = .0f;
	for (std::vector<TileLayer*>::const_iterator it = CollisionObject::m_pCollisionLayers->begin(); it != CollisionObject::m_pCollisionLayers->end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		buscarColisionesIzquierda(pTileLayer);
	}
	return m_stopIzquierda;
}

void CollisionObject::buscarColisionesArriba(TileLayer* pTileLayer) {
	int offSetTileIndexX = 0;
	int offSetTileIndexY = 0;
	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	int primeraCol = (m_position.getX() + m_collisionMargin) / m_TileWith;
	int ultimaCol = (m_position.getX() + m_width - m_collisionMargin) / m_TileWith;
	int filaTecho = m_position.getY() / m_TileHeight;

	if (pTileLayer->getTileIDs().size() > filaTecho + offSetTileIndexY) {
		for (int i = 0; primeraCol + i <= ultimaCol && (primeraCol + i + offSetTileIndexX) < pTileLayer->getTileIDs()[filaTecho + offSetTileIndexY].size(); ++i) {
			if (pTileLayer->getTileIDs()[filaTecho + offSetTileIndexY][primeraCol + i + offSetTileIndexX] != 0
				&& primeraCol + i < (m_position.getX() + m_width - m_collisionMargin) / m_TileWith
				&& (m_position.getX() + m_collisionMargin) / m_TileWith < primeraCol + i + 1) {
				if (pTileLayer->getTileIDs()[filaTecho + offSetTileIndexY][primeraCol + i + offSetTileIndexX] == 18 || pTileLayer->getTileIDs()[filaTecho + offSetTileIndexY][primeraCol + i + offSetTileIndexX] == 56) {
					colisionmuerte = true;
				}
				else {
					m_stopArriba = true;
					m_stopPositionArriba.setY((filaTecho + 1)*m_TileHeight);
				}
			}
		}
	}
}


void CollisionObject::buscarColisionesAbajo(TileLayer* pTileLayer) {
	int offSetTileIndexX = 0;
	int offSetTileIndexY = 0;
	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	int primeraCol = (m_position.getX() + m_collisionMargin) / m_TileWith;
	int ultimaCol = (m_position.getX() + m_width - m_collisionMargin) / m_TileWith;
	int filaSuelo = (m_position.getY() + m_height) / m_TileHeight;

	if (pTileLayer->getTileIDs().size() > filaSuelo + offSetTileIndexY) {
		for (int i = 0; primeraCol + i <= ultimaCol && (primeraCol + i + offSetTileIndexX) < pTileLayer->getTileIDs()[filaSuelo + offSetTileIndexY].size(); ++i) {
			if (pTileLayer->getTileIDs()[filaSuelo + offSetTileIndexY][primeraCol + i + offSetTileIndexX] != 0
				&& primeraCol + i < (m_position.getX() + m_width - m_collisionMargin) / m_TileWith
				&& (m_position.getX() + m_collisionMargin) / m_TileWith < primeraCol + i + 1) {
				if (pTileLayer->getTileIDs()[filaSuelo + offSetTileIndexY][primeraCol + i + offSetTileIndexX] == 18 || pTileLayer->getTileIDs()[filaSuelo + offSetTileIndexY][primeraCol + i + offSetTileIndexX] == 56) {
					colisionmuerte = true;
				}else {
					m_stopAbajo = true;
					m_stopPositionAbajo.setY(filaSuelo*m_TileHeight - m_height);
				}
			}
		}
	}
}

void CollisionObject::buscarColisionesDerecha(TileLayer* pTileLayer) {
	int offSetTileIndexX = 0;
	int offSetTileIndexY = 0;
	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	int primeraFila = m_position.getY() / m_TileHeight;
	int ultimaFila = (m_position.getY() + m_height) / m_TileHeight;
	int colDerecha = (m_position.getX() + m_width - m_collisionMargin) / m_TileWith;

	for (int j = 0; primeraFila + j < ultimaFila && (primeraFila + j + offSetTileIndexY) < pTileLayer->getTileIDs().size(); ++j) {
		if (colDerecha < pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY].size() && pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY][colDerecha + offSetTileIndexX] != 0) {
			if (pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY][colDerecha + offSetTileIndexX] == 18 || pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY][colDerecha + offSetTileIndexX] == 56) {
				colisionmuerte = true;
			}
			else {
				m_stopDerecha = true;
				m_stopPositionDerecha.setX(colDerecha*m_TileWith - m_width + m_collisionMargin);
			}
		}
	}
}

void CollisionObject::buscarColisionesIzquierda(TileLayer* pTileLayer) {
	int offSetTileIndexX = 0;
	int offSetTileIndexY = 0;
	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	int primeraFila = m_position.getY() / m_TileHeight;
	int ultimaFila = (m_position.getY() + m_height) / m_TileHeight;
	int colIzquierda = (m_position.getX() + m_collisionMargin) / m_TileWith;

	for (int j = 0; primeraFila + j < ultimaFila && (primeraFila + j + offSetTileIndexY) < pTileLayer->getTileIDs().size(); ++j) {
		if (colIzquierda < pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY].size()
			&& pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY][colIzquierda + offSetTileIndexX] != 0) {
			if (pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY][colIzquierda + offSetTileIndexX] == 18 || pTileLayer->getTileIDs()[primeraFila + j + offSetTileIndexY][colIzquierda + offSetTileIndexX] == 56) {
				colisionmuerte = true;
			}
			else {
				m_stopIzquierda = true;
				m_stopPositionIzquierda.setX((colIzquierda + 1)*m_TileWith - m_collisionMargin);
			}
		}
	}
}

float CollisionObject::absolute(float a) {
	return a < 0 ? -a : a;
}
