#include "TileLayer.h"
#include "Tools.h"
#include "Loaders.h"
#include "Game.h"

TileLayer::TileLayer(int width, int height, int tileWidth, int tileHeight, std::vector<Tileset> tileSets)
{
	this->width = width;
	this->height = height;
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	this->tilesets = tileSets;
}

TileLayer::~TileLayer()
{
}

void TileLayer::Update(Player * player)
{
	position.X = player->position.X;
	position.Y = player->position.Y;
}

void TileLayer::Render()
{
	int firstX = position.X / tileWidth;
	int firstY = position.Y / tileHeight;
	int lastX = (int)position.X % tileWidth;
	int lastY = (int)position.Y % tileHeight;
	Vector2D scr(Tools::GetWidth(), Tools::GetHeight());
	for (int row = 0; row < width; row++) 
	{
		for (int tile = 0; tile < height; tile++)
		{
			if (tile + firstX < 0 || tile + firstX >= tileIDs.size())
				continue;
			int x1 = (row * tileWidth) - (position.X / tileWidth);
			int x2 = x1 + tileWidth;
			int y1 = (tile * tileHeight) - (position.Y / tileHeight);
			int y2 = y1 + tileHeight;

			if (((x1 < 0 && x2 < 0) || (x1 > Tools::GetWidth() && x2 > Tools::GetWidth())) && ((y1 < 0 && y2 < 0) || (y1 > Tools::GetHeight() && y2 > Tools::GetHeight())))
				continue;
			int current = tileIDs[row][tile + firstX];
			if (current == 1)
				continue;
			Tileset * ts = GetTileset(current);
			current--;
			/*Draw(ts->name, ts->margin, ts->spacing, (tile * ts->tileWidth) - lastX,
				(row * ts->tileHeight) - lastY, ts->tileWidth, ts->tileHeight, 
				(current - (ts->firstGridID - 1)) / ts->numColumns,
				(current - (ts->firstGridID - 1)) % ts->numColumns);*/
			Draw(ts->name, ts, (tile * ts->tileWidth) - lastX, (row * ts->tileHeight) - lastY, 
				(current - (ts->firstGridID - 1)) / ts->numColumns,
				(current - (ts->firstGridID - 1)) % ts->numColumns);
		}
	}
}

void TileLayer::SetTileIDs(const std::vector<std::vector<int>>& tileIDs)
{
	this->tileIDs = tileIDs;
}

Tileset * TileLayer::GetTileset(int ts)
{
	int f = 0;
	for (int i = 0; i < tilesets.size(); i++)
	{
		if (tilesets.at(i).firstGridID <= ts)
			f = i;
		else
			break;
	}
	return &tilesets.at(f);
}

void TileLayer::Draw(string id, Tileset * ts, int x, int y, int row, int frame)
{
	//source = IMATGE; draw = S
	SDL_Rect source, draw;
	
	source.x = ts->margin + (ts->spacing + ts->tileWidth) * (frame - 1);
	source.y = ts->margin + (ts->spacing + ts->tileHeight) * row;
	source.w = ts->tileWidth;
	source.h = ts->tileHeight;

	draw.w = tileWidth;
	draw.h = tileHeight;
	draw.x = x;
	draw.y = y;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[id];
	SDL_RenderCopy(TheGame->GetRenderer(), textura, &source, &draw);
}