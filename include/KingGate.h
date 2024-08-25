#pragma once
#include"Gate.h"

class Factory;
class KingGate :public Gate
{
public:
	KingGate(sf::Vector2f position);
	virtual~KingGate() = default;

protected:
	static bool m_register;

}; 