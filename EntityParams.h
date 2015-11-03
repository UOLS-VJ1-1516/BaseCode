#pragma once

class EntityParams
{
private:
	const char * id;
	int xPos, yPos;
	int width, height;
	int frame;
	int maxFrame, row;
	bool flipped;
public:
	EntityParams(const char * id, int xPos, int yPos, int width, int height, int maxFrame = 0, int row = 0);

	const char * GetId() { return id; }

	void SetXPos(int xPos) { this->xPos = xPos; }
	int GetXPos() { return xPos; }

	void SetYPos(int yPos) { this->yPos = yPos; }
	int GetYPos() { return yPos; }

	int GetWidth() { return width; }
	int GetHeight() { return height; }

	int GetFrame() { return frame; }
	void SetFrame(int frame) { this->frame = frame; }

	int GetMaxFrame() { return maxFrame; }
	int GetRow() { return row; }

	bool IsFlipped() { return flipped; }
	void Flip() { flipped = !flipped; }

	void AddFrame();
	void AddXPos(int);
};