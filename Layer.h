#pragma once
//este es un clase en el cual, define los methodos que tiene los layers

class Layer
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
protected:
	virtual ~Layer() {}
};
