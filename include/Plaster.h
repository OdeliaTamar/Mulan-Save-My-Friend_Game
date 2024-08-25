#pragma once
#include"RescueTasks.h"

class Factory;
class Plaster :public RescueTasks
{
public:
	Plaster(sf::Vector2f position);
	virtual~Plaster() = default;

protected:
	static bool m_register;

};






