#pragma once
#include"RescueTasks.h"

class Factory;
class Medication :public RescueTasks
{
public:
	Medication( sf::Vector2f position);
	virtual~Medication() = default;

protected:
	static bool m_register;

};



