#include "TileLayer.h"
#include "Tools.h"
#include "Loaders.h"
#include "Game.h"

TileLayer::TileLayer(int tileWidth, int tileHeight, std::vector<Tileset> tileSets)
{
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
	for (int row = 0; row < 20; row++) 
	{
		for (int tile = 0; tile < 20; tile++)
		{
			if (tile + firstX < 0 || tile + firstX >= tileIDs.size())
				continue;
			int current = tileIDs[row][tile + firstX];
			if (current == 0)
				continue;
			Tileset * ts = GetTileset(current);
			current--;
			Draw(ts->name, ts->margin, ts->spacing, (tile * ts->tileWidth) - lastX,
				(row * ts->tileHeight) - lastY, ts->tileWidth, ts->tileHeight, 
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

void TileLayer::Draw(string id, int margin, int spacing, int x, int y,
	int width, int height, int row, int frame)
{
	if (x + width < 0 || x - width > Tools::GetWidth() || y + height < 0 || y - height > Tools::GetHeight())
		return;
	SDL_Rect source, draw;
	
	source.x = margin + (spacing + width) * (frame - 1);
	source.y = margin + (spacing + height) * row;
	source.w = width;
	source.h = height;
	draw.w = width;
	draw.h = height;
	draw.x = x;
	draw.y = y;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[id];
	SDL_RenderCopy(TheGame->GetRenderer(), textura, &source, &draw);
}