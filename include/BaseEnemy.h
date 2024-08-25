#pragma once
#include "MovingObject.h"
class Factory;
class BaseEnemy: public MovingObject
{
public:
	BaseEnemy(sf::Vector2f position);
	virtual ~BaseEnemy() = default;
	virtual bool getFaceRight() override { return m_faceRight; }
	void setFaceRight(bool face) { m_faceRight = face; }
protected:
};
