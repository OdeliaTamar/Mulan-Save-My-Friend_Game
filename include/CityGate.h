#pragma once
#include"Gate.h"
class Factory;

class CityGate :public Gate
{
public:
	CityGate(sf::Vector2f position);
	virtual~CityGate() = default;

protected:
	static bool m_register;
};