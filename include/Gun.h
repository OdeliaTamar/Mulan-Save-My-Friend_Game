#pragma once
#include"StaticWeapon.h"
class Factory;
class Gun :public StaticWeapon
{
public:
	Gun(sf::Vector2f position);
	virtual~Gun() = default;

protected:
	static bool m_register;

};

