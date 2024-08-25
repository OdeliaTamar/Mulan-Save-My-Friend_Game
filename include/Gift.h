#pragma once
#include"StaticObject.h"
class Gift:public StaticObject
{
public:
	Gift(sf::Vector2f position);
	virtual~Gift() = default;

protected:

};

