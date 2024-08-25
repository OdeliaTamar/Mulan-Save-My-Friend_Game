#pragma once
#include "MovingObject.h"

class MovingWeapon: public MovingObject
{
public:
	MovingWeapon(sf::Vector2f position);
	virtual ~MovingWeapon() = default;
	virtual bool getFaceRight() { return m_faceRight; }
protected:

};
