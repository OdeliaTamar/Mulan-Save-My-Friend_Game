#pragma once
#include"Gift.h"
class Factory;
class LifeGift :public Gift
{
public:
	LifeGift(sf::Vector2f position);
	virtual~LifeGift() = default;

protected:
	static bool m_register;
};

