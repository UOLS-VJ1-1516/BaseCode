#pragma once
#include "CollisionObject.h"
#include <vector>
#include "TileLayer.h"


CollisionObject::CollisionObject() {
	m_stopArriba = false;
	m_stopAbajo = false;
	m_stopDerecha = false;
	m_stopIzquierda = false;
	m_energyX = .0f;
	m_energyY = .0f;
	m_stopPositionArriba = Vector2D();
	m_stopPositionAbajo = Vector2D();
	m_stopPositionDerecha = Vector2D();
	m_stopPositionIzquierda = Vector2D();
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
}
void CollisionObject::clean()
{

}

bool CollisionObject::isCollisionWithTile()
{
	m_stopArriba = false;
	m_stopAbajo = false;
	m_stopDerecha = false;
	m_stopIzquierda = false;
	m_stopPositionArriba.setX(0); m_stopPositionArriba.setY(0);
	m_stopPositionAbajo.setX(0); m_stopPositionAbajo.setY(0);
	m_stopPositionDerecha.setX(0); m_stopPositionDerecha.setY(0);
	m_stopPositionIzquierda.setX(0); m_stopPositionIzquierda.setY(0);
	m_energyX = .0f;
	m_energyY = .0f;
	for (std::vector<TileLayer*>::const_iterator it = CollisionObject::m_pCollisionLayers->begin(); it != CollisionObject::m_pCollisionLayers->end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		int offSetTileIndexX, offSetTileIndexY, tileColumn, tileRow, tileid = 0;
		m_TileHeight = pTileLayer->getTileHeight();
		m_TileWith = pTileLayer->getTileWith();
		float vel_x = m_velocity.getX();
		float vel_y = m_velocity.getY();
		if (vel_x > 0) {
			if (vel_y < 0) {
				//Voy derecha-arriba
				buscarColisionesDerechaArriba(pTileLayer);
			}
			else if (vel_y > 0) {
				//Voy derecha-abajo
				buscarColisionesDerechaAbajo(pTileLayer);
			}
			else {
				buscarColisionesDerechaArriba(pTileLayer);
				buscarColisionesDerechaAbajo(pTileLayer);
			}
		}
		else if (vel_x < 0) {
			if (vel_y < 0) {
				//Voy izquierda-arriba
				buscarColisionesIzquierdaArriba(pTileLayer);
			}
			else if (vel_y > 0) {
				//Voy derecha-abajo
				buscarColisionesIzquierdaAbajo(pTileLayer);
			}
			else {
				buscarColisionesIzquierdaArriba(pTileLayer);
				buscarColisionesIzquierdaAbajo(pTileLayer);
			}
		}
		//else {
			buscarColisionesDerechaAbajo(pTileLayer);
			buscarColisionesIzquierdaAbajo(pTileLayer);		
	}

	return (m_stopAbajo || m_stopDerecha || m_stopIzquierda || m_stopArriba) ? true : false;
}


void CollisionObject::prohibidoIrHaciaArriba(int col, int fil) {
	m_stopPositionArriba.setX(0); //Este no se deberia usar
	m_stopPositionArriba.setY((fil + 1)*m_TileHeight);
	m_stopArriba = true;
}

void CollisionObject::prohibidoIrHaciaAbajo(int col, int fil) {
	m_stopPositionAbajo.setX(0); //Este no se deberia usar
	m_stopPositionAbajo.setY(fil*m_TileHeight - m_height);
	m_stopAbajo = true;
}

void CollisionObject::prohibidoIrHaciaDerecha(int col, int fil) {
	m_stopPositionDerecha.setX(col*m_TileWith - m_width + m_collisionMargin);
	m_stopPositionDerecha.setY(0); //Este no se deberia usar
	m_stopDerecha = true;
}

void CollisionObject::prohibidoIrHaciaIzquierda(int col, int fil) {
	m_stopPositionIzquierda.setX((col + 1)*m_TileWith);
	m_stopPositionIzquierda.setY(0); //Este no se deberia usar
	m_stopIzquierda = true;
}


void CollisionObject::recorrerFilaSuperior(TileLayer* pTileLayer, int fila, int columnaIzq, int columnaDer, int offSetTileIndexX, int offSetTileIndexY, bool izq) {
	if (fila + offSetTileIndexY < pTileLayer->getTileIDs().size()) {
		for (int i = 1; columnaIzq + i < columnaDer && (columnaIzq + i + offSetTileIndexX) < pTileLayer->getTileIDs()[0].size(); ++i) {
			if (pTileLayer->getTileIDs()[fila + offSetTileIndexY][columnaIzq + i + offSetTileIndexX] != 0) {
				prohibidoIrHaciaArriba(columnaIzq + i, fila);
			}
		}
		if (izq) {
			if ((columnaIzq + offSetTileIndexX) < pTileLayer->getTileIDs()[0].size() && pTileLayer->getTileIDs()[fila + offSetTileIndexY][columnaIzq + offSetTileIndexX] != 0) {
				prohibidoIrHaciaArriba(columnaIzq, fila);
			}
		}
		else {
			if ((columnaDer + offSetTileIndexX) < pTileLayer->getTileIDs()[0].size() && pTileLayer->getTileIDs()[fila + offSetTileIndexY][columnaDer + offSetTileIndexX] != 0) {
				prohibidoIrHaciaArriba(columnaDer, fila);
			}
		}
	}
}

void CollisionObject::recorrerFilaInferior(TileLayer* pTileLayer, int fila, int columnaIzq, int columnaDer, int offSetTileIndexX, int offSetTileIndexY, bool izq) {
	if (fila + offSetTileIndexY < pTileLayer->getTileIDs().size()) {
		for (int i = 1; columnaIzq + i < columnaDer && (columnaIzq + i + offSetTileIndexX) < pTileLayer->getTileIDs()[0].size(); ++i) {
			if (pTileLayer->getTileIDs()[fila + offSetTileIndexY][columnaIzq + i + offSetTileIndexX] != 0) {
				prohibidoIrHaciaAbajo(columnaIzq + i, fila);
			}
		}
		if (izq) {
			if ((columnaIzq + offSetTileIndexX) < pTileLayer->getTileIDs()[0].size() && pTileLayer->getTileIDs()[fila + offSetTileIndexY][columnaIzq + offSetTileIndexX] != 0) {
				prohibidoIrHaciaAbajo(columnaIzq, fila);
			}
		}
		else {
			if ((columnaDer + offSetTileIndexX) < pTileLayer->getTileIDs()[0].size() && pTileLayer->getTileIDs()[fila + offSetTileIndexY][columnaDer + offSetTileIndexX] != 0) {
				prohibidoIrHaciaAbajo(columnaDer, fila);
			}
		}
	}
}

void CollisionObject::recorrerColumnaDerecha(TileLayer* pTileLayer, int columna, int filaArriba, int filaAbajo, int offSetTileIndexX, int offSetTileIndexY, bool arriba) {
	if (columna + offSetTileIndexX < pTileLayer->getTileIDs()[0].size()) {
		for (int j = 1; filaArriba + j < filaAbajo && (filaArriba + j + offSetTileIndexY) < pTileLayer->getTileIDs().size(); ++j) {
			if (pTileLayer->getTileIDs()[filaArriba + j + offSetTileIndexY][columna + offSetTileIndexX] != 0) {
				prohibidoIrHaciaDerecha(columna, filaArriba + j);
			}
		}
		if (arriba) {
			if ((filaArriba + offSetTileIndexY) < pTileLayer->getTileIDs().size() && pTileLayer->getTileIDs()[filaArriba + offSetTileIndexY][columna + offSetTileIndexX] != 0) {
				prohibidoIrHaciaDerecha(columna, filaArriba);
			}
		}
		else {
			if ((filaAbajo + offSetTileIndexY) < pTileLayer->getTileIDs().size() && pTileLayer->getTileIDs()[filaAbajo + offSetTileIndexY][columna + offSetTileIndexX] != 0) {
				prohibidoIrHaciaDerecha(columna, filaAbajo);
			}
		}
	}
}

void CollisionObject::recorrerColumnaIzquierda(TileLayer* pTileLayer, int columna, int filaArriba, int filaAbajo, int offSetTileIndexX, int offSetTileIndexY, bool arriba) {
	if (columna + offSetTileIndexX < pTileLayer->getTileIDs()[0].size()) {
		for (int j = 1; filaArriba + j < filaAbajo && (filaArriba + j + offSetTileIndexY) < pTileLayer->getTileIDs().size(); ++j) {
			if (pTileLayer->getTileIDs()[filaArriba + j + offSetTileIndexY][columna + offSetTileIndexX] != 0) {
				prohibidoIrHaciaIzquierda(columna, filaArriba + j);
			}
		}
		if (arriba) {
			if ((filaArriba + offSetTileIndexY) < pTileLayer->getTileIDs().size() && pTileLayer->getTileIDs()[filaArriba + offSetTileIndexY][columna + offSetTileIndexX] != 0) {
				prohibidoIrHaciaIzquierda(columna, filaArriba);
			}
		}
		else {
			if ((filaAbajo + offSetTileIndexY) < pTileLayer->getTileIDs().size() && pTileLayer->getTileIDs()[filaAbajo + offSetTileIndexY][columna + offSetTileIndexX] != 0) {
				prohibidoIrHaciaIzquierda(columna, filaAbajo);
			}
		}
	}
}

void CollisionObject::buscarColisionesDerechaArriba(TileLayer* pTileLayer) {
	int offSetTileIndexX = pTileLayer->getPosition().getX() / pTileLayer->getTileWith();
	int offSetTileIndexY = pTileLayer->getPosition().getY() / pTileLayer->getTileHeight();

	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	float esquinaArribaIzquierdaBichoX = m_position.getX() + m_collisionMargin;
	float esquinaArribaDerechaBichoX = m_position.getX() + m_width - m_collisionMargin;
	float esquinaArribaDerechaBichoY = m_position.getY();
	float esquinaAbajoDerechaBichoY = m_position.getY() + m_height;

	int columnaTileChoqueArribaIzquierda = esquinaArribaIzquierdaBichoX / m_TileWith;
	int columnaTileChoqueArribaDerecha = esquinaArribaDerechaBichoX / m_TileWith;
	int filaTileChoqueArribaDerecha = esquinaArribaDerechaBichoY / m_TileHeight;
	int filaTileChoqueAbajoDerecha = esquinaAbajoDerechaBichoY / m_TileHeight;

	//saliente en pixeles
	float salienteX = absolute(esquinaArribaDerechaBichoX / m_TileWith - filaTileChoqueArribaDerecha)*m_TileWith;
	float salienteY = absolute(esquinaArribaDerechaBichoY / m_TileHeight - columnaTileChoqueArribaDerecha)*m_TileHeight;

	//Recorremos fila superior de tiles, en busca de choques (menos la esquina) si estamos almenos 1 dentro:
	if (salienteY > 1) {
		recorrerFilaSuperior(pTileLayer, filaTileChoqueArribaDerecha, columnaTileChoqueArribaIzquierda, columnaTileChoqueArribaDerecha, offSetTileIndexX, offSetTileIndexY, true);
	}
	if (salienteX > 1) {
		//Recorremos columna derecha de tiles, en busca de choques 
		recorrerColumnaDerecha(pTileLayer, columnaTileChoqueArribaDerecha, filaTileChoqueArribaDerecha, filaTileChoqueAbajoDerecha, offSetTileIndexX, offSetTileIndexY, false);
	}
	//Esquina
	if (salienteX + salienteY > 1 && filaTileChoqueArribaDerecha + offSetTileIndexY < pTileLayer->getTileIDs().size() && columnaTileChoqueArribaDerecha + offSetTileIndexX < pTileLayer->getTileIDs()[0].size()) {
		if (pTileLayer->getTileIDs()[filaTileChoqueArribaDerecha + offSetTileIndexY][columnaTileChoqueArribaDerecha + offSetTileIndexX] != 0) {
			m_energyX = salienteY*absolute(m_velocity.getX());
			m_energyY = salienteX*absolute(m_velocity.getY());
			if (m_energyX <= m_energyY) {
				if (salienteY > 1) {
					prohibidoIrHaciaDerecha(columnaTileChoqueArribaDerecha, filaTileChoqueArribaDerecha);
				}
				else if (salienteX > 1) {
					prohibidoIrHaciaArriba(columnaTileChoqueArribaDerecha, filaTileChoqueArribaDerecha);
				}
			}
			else {
				if (salienteX > 1) {
					prohibidoIrHaciaArriba(columnaTileChoqueArribaDerecha, filaTileChoqueArribaDerecha);
				}
				else if (salienteY > 1) {
					prohibidoIrHaciaDerecha(columnaTileChoqueArribaDerecha, filaTileChoqueArribaDerecha);
				}
			}
		}
	}


}


void CollisionObject::buscarColisionesDerechaAbajo(TileLayer* pTileLayer) {
	int offSetTileIndexX = pTileLayer->getPosition().getX() / pTileLayer->getTileWith();
	int offSetTileIndexY = pTileLayer->getPosition().getY() / pTileLayer->getTileHeight();

	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	float esquinaAbajoIzquierdaBichoX = m_position.getX() + m_collisionMargin;
	float esquinaAbajoDerechaBichoX = m_position.getX() + m_width - m_collisionMargin;
	float esquinaArribaDerechaBichoY = m_position.getY();
	float esquinaAbajoDerechaBichoY = m_position.getY() + m_height;

	int columnaTileChoqueAbajoIzquierda = esquinaAbajoIzquierdaBichoX / m_TileWith;
	int columnaTileChoqueAbajoDerecha = esquinaAbajoDerechaBichoX / m_TileWith;
	int filaTileChoqueArribaDerecha = esquinaArribaDerechaBichoY / m_TileHeight;
	int filaTileChoqueAbajoDerecha = esquinaAbajoDerechaBichoY / m_TileHeight;

	float salienteX = absolute(esquinaAbajoDerechaBichoX / m_TileWith - columnaTileChoqueAbajoDerecha)*m_TileWith;
	float salienteY = absolute(esquinaAbajoDerechaBichoY / m_TileHeight - filaTileChoqueAbajoDerecha)*m_TileHeight;

	//Recorremos fila inferior de tiles, en busca de choques (menos la esquina):
	if (salienteY > 1) {
		recorrerFilaInferior(pTileLayer, filaTileChoqueAbajoDerecha, columnaTileChoqueAbajoIzquierda, columnaTileChoqueAbajoDerecha, offSetTileIndexX, offSetTileIndexY, true);
	}

	//Esquina
	if (salienteX > 1) {
		//Recorremos columna derecha de tiles, en busca de choques 
		recorrerColumnaDerecha(pTileLayer, columnaTileChoqueAbajoDerecha, filaTileChoqueArribaDerecha, filaTileChoqueAbajoDerecha, offSetTileIndexX, offSetTileIndexY, true);
	}

	if (salienteX + salienteY > 1 && filaTileChoqueAbajoDerecha + offSetTileIndexY < pTileLayer->getTileIDs().size() && columnaTileChoqueAbajoDerecha + offSetTileIndexX < pTileLayer->getTileIDs()[0].size()) {
		if (pTileLayer->getTileIDs()[filaTileChoqueAbajoDerecha + offSetTileIndexY][columnaTileChoqueAbajoDerecha + offSetTileIndexX] != 0) {
			m_energyX = salienteY*absolute(m_velocity.getX());
			m_energyY = salienteX*absolute(m_velocity.getY());
			if (m_energyX <= m_energyY) {
				if (salienteY > 1) {
					prohibidoIrHaciaDerecha(columnaTileChoqueAbajoDerecha, filaTileChoqueAbajoDerecha);
				}
				else if (salienteX > 1) {
					prohibidoIrHaciaAbajo(columnaTileChoqueAbajoDerecha, filaTileChoqueAbajoDerecha);
				}
			}
			else {
				if (salienteX > 1) {
					prohibidoIrHaciaAbajo(columnaTileChoqueAbajoDerecha, filaTileChoqueAbajoDerecha);
				}
				else if (salienteY > 1) {
					prohibidoIrHaciaDerecha(columnaTileChoqueAbajoDerecha, filaTileChoqueAbajoDerecha);
				}
			}
		}
	}
}

void CollisionObject::buscarColisionesIzquierdaArriba(TileLayer* pTileLayer) {
	int offSetTileIndexX = pTileLayer->getPosition().getX() / pTileLayer->getTileWith();
	int offSetTileIndexY = pTileLayer->getPosition().getY() / pTileLayer->getTileHeight();

	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	float esquinaArribaIzquierdaBichoX = m_position.getX() + m_collisionMargin;
	float esquinaArribaDerechaBichoX = m_position.getX() + m_width - m_collisionMargin;
	float esquinaArribaIzquierdaBichoY = m_position.getY();
	float esquinaAbajoIzquierdaBichoY = m_position.getY() + m_height;

	int columnaTileChoqueArribaIzquierda = esquinaArribaIzquierdaBichoX / m_TileWith;
	int columnaTileChoqueArribaDerecha = esquinaArribaDerechaBichoX / m_TileWith;
	int filaTileChoqueArribaIzquierda = esquinaArribaIzquierdaBichoY / m_TileHeight;
	int filaTileChoqueAbajoIzquierda = esquinaAbajoIzquierdaBichoY / m_TileHeight;

	float salienteX = absolute(esquinaArribaIzquierdaBichoX / m_TileWith - columnaTileChoqueArribaIzquierda)*m_TileWith;
	float salienteY = absolute(esquinaArribaIzquierdaBichoY / m_TileHeight - filaTileChoqueArribaIzquierda)*m_TileHeight;

	if (salienteY > 1) {
		//Recorremos fila superior de tiles, en busca de choques (menos la esquina):
		recorrerFilaSuperior(pTileLayer, filaTileChoqueArribaIzquierda, columnaTileChoqueArribaIzquierda, columnaTileChoqueArribaDerecha, offSetTileIndexX, offSetTileIndexY, false);
	}

	if (salienteX > 1) {
		//Recorremos columna izquierda de tiles, en busca de choques 
		recorrerColumnaIzquierda(pTileLayer, columnaTileChoqueArribaIzquierda, filaTileChoqueArribaIzquierda, filaTileChoqueAbajoIzquierda, offSetTileIndexX, offSetTileIndexY, false);
	}

	//Esquina
	if (salienteX + salienteY > 1 && filaTileChoqueArribaIzquierda + offSetTileIndexY < pTileLayer->getTileIDs().size() && columnaTileChoqueArribaIzquierda + offSetTileIndexX < pTileLayer->getTileIDs()[0].size()) {
		if (pTileLayer->getTileIDs()[filaTileChoqueArribaIzquierda + offSetTileIndexY][columnaTileChoqueArribaIzquierda + offSetTileIndexX] != 0) {
			m_energyX = salienteY*absolute(m_velocity.getX());
			m_energyY = salienteX*absolute(m_velocity.getY());
			if (m_energyX <= m_energyY) {
				if (salienteY > 1) {
					prohibidoIrHaciaIzquierda(columnaTileChoqueArribaIzquierda, filaTileChoqueArribaIzquierda);
				}
				else if (salienteX > 1) {
					prohibidoIrHaciaArriba(columnaTileChoqueArribaIzquierda, filaTileChoqueArribaIzquierda);
				}
			}
			else {
				if (salienteX > 1) {
					prohibidoIrHaciaArriba(columnaTileChoqueArribaIzquierda, filaTileChoqueArribaIzquierda);
				}
				else if (salienteY > 1) {
					prohibidoIrHaciaIzquierda(columnaTileChoqueArribaIzquierda, filaTileChoqueArribaIzquierda);
				}
			}
		}
	}
}

void CollisionObject::buscarColisionesIzquierdaAbajo(TileLayer* pTileLayer) {
	int offSetTileIndexX = pTileLayer->getPosition().getX() / pTileLayer->getTileWith();
	int offSetTileIndexY = pTileLayer->getPosition().getY() / pTileLayer->getTileHeight();

	int m_TileWith = pTileLayer->getTileWith();
	int m_TileHeight = pTileLayer->getTileHeight();

	float esquinaAbajoIzquierdaBichoX = m_position.getX() + m_collisionMargin;
	float esquinaAbajoDerechaBichoX = m_position.getX() + m_width - m_collisionMargin;
	float esquinaArribaIzquierdaBichoY = m_position.getY();
	float esquinaAbajoIzquierdaBichoY = m_position.getY() + m_height;

	int columnaTileChoqueAbajoIzquierda = esquinaAbajoIzquierdaBichoX / m_TileWith;
	int columnaTileChoqueAbajoDerecha = esquinaAbajoDerechaBichoX / m_TileWith;
	int filaTileChoqueArribaIzquierda = esquinaArribaIzquierdaBichoY / m_TileHeight;
	int filaTileChoqueAbajoIzquierda = esquinaAbajoIzquierdaBichoY / m_TileHeight;

	float salienteX = absolute(esquinaAbajoIzquierdaBichoX / m_TileWith - columnaTileChoqueAbajoIzquierda)*m_TileWith;
	float salienteY = absolute(esquinaAbajoIzquierdaBichoY / m_TileHeight - filaTileChoqueAbajoIzquierda)*m_TileHeight;

	if (salienteY > 1) {
		//Recorremos fila inferior de tiles, en busca de choques (menos la esquina):
		recorrerFilaInferior(pTileLayer, filaTileChoqueAbajoIzquierda, columnaTileChoqueAbajoIzquierda, columnaTileChoqueAbajoDerecha, offSetTileIndexX, offSetTileIndexY, false);
	}

	if (salienteX > 1) {
		//Recorremos columna izquierda de tiles, en busca de choques 
		recorrerColumnaIzquierda(pTileLayer, columnaTileChoqueAbajoIzquierda, filaTileChoqueArribaIzquierda, filaTileChoqueAbajoIzquierda, offSetTileIndexX, offSetTileIndexY, true);
	}

	//Esquina
	if (salienteX + salienteY > 1 && filaTileChoqueAbajoIzquierda + offSetTileIndexY < pTileLayer->getTileIDs().size() && columnaTileChoqueAbajoIzquierda + offSetTileIndexX < pTileLayer->getTileIDs()[0].size()) {
		if (pTileLayer->getTileIDs()[filaTileChoqueAbajoIzquierda + offSetTileIndexY][columnaTileChoqueAbajoIzquierda + offSetTileIndexX] != 0) {
			m_energyX = salienteY*absolute(m_velocity.getX());
			m_energyY = salienteX*absolute(m_velocity.getY());
			if (m_energyX <= m_energyY) {
				if (salienteY > 1) {
					prohibidoIrHaciaIzquierda(columnaTileChoqueAbajoIzquierda, filaTileChoqueAbajoIzquierda);
				}
				else if (salienteX > 1) {
					prohibidoIrHaciaAbajo(columnaTileChoqueAbajoIzquierda, filaTileChoqueAbajoIzquierda);
				}
			}
			else {
				if (salienteX > 1) {
					prohibidoIrHaciaAbajo(columnaTileChoqueAbajoIzquierda, filaTileChoqueAbajoIzquierda);
				}
				else if (salienteY > 1) {
					prohibidoIrHaciaIzquierda(columnaTileChoqueAbajoIzquierda, filaTileChoqueAbajoIzquierda);
				}
			}
		}
	}
}

int CollisionObject::CollisionDirection(int tileColumn, int tileRow, float TileWith, float TileHeight)
{
	float leftwall = TileWith*tileColumn;
	float topwall = TileWith*tileRow;
	float collisiondistanceX = getWidth() - 2 * (m_collisionMargin - leftwall);
	float collisiondistanceY = getHeight() - 2 * (m_collisionMargin - topwall);
	if (absolute(collisiondistanceX) == 0 && absolute(collisiondistanceY) == 0) {
		return 0;
	}
	if (getVelocity().getX() > 0) { // voy a la derecha
		if (absolute(collisiondistanceX) / getVelocity().getX() > absolute(collisiondistanceY) / getVelocity().getY()) { //impacto a mi derecha (playeR)
			return 4;
		}
		else {
			if (getVelocity().getY() > 0) {
				return 1; //impacto superior.
			}
			else {
				return 3; //impacto inferior.
			}
		}
	}
	else {
		if (absolute(collisiondistanceX) / getVelocity().getX() > absolute(collisiondistanceY) / getVelocity().getY()) { //impacto a mi izquierda (playeR)
			return 2;
		}
		else {
			if (getVelocity().getY() > 0) {
				return 1; //impacto superior.
			}
			else {
				return 3; //impacto inferior.
			}
		}
	}
}

float CollisionObject::absolute(float a) {
	return a < 0 ? -a : a;
}