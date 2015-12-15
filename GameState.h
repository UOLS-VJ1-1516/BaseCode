#pragma once
#include <string>
#include <vector>

class GameState
{

	public:
		virtual void update() = 0;
		virtual void render() = 0;
		virtual bool onEnter() = 0;
		virtual bool onExit() = 0;
		virtual std::string getStateID() const = 0;

		typedef void(*Callback)();
		virtual void setCallbacks(const std::vector<Callback>& callbacks) {};
		std::vector< Callback > m_callbacks;

	protected:
		std::vector<std::string> m_textureIDList;

};