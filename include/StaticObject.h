#pragma once
#include "BaseObject.h"

class StaticObject :public BaseObject
{
public:
	StaticObject( sf::Vector2f position);
	virtual ~StaticObject() = default;

protected:

};
