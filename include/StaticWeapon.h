#pragma once
#include"Gift.h"
class StaticWeapon: public Gift
{
public:
	StaticWeapon(sf::Vector2f position);
	virtual~StaticWeapon() = default;

protected:

};

