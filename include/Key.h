#pragma once
#include"RescueTasks.h"

class Factory;
class Key :public RescueTasks
{
public:
	Key(sf::Vector2f position);
	virtual~Key() = default;

protected:
	static bool m_register;
};