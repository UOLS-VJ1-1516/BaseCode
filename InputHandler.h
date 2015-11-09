#pragma once
#include <map>
#include <stdint.h>
#include <iostream>

typedef uint32_t Uint32;

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	~InputHandler() {};
	void update(Uint32 key);
	void clean();
	// Métodos de acceso
	bool isKeyDown(Uint32 key);
	void updateKeyUp(Uint32 key);
	bool isKeyUp(Uint32 key);
	void InputHandler::removeKeyUp(Uint32 key);

private:

	static InputHandler* s_pInstance;
	InputHandler();
	std::map< Uint32, int > m_keystates;
};