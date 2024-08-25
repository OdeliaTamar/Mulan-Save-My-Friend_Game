#include "MovingObject.h"
#include "Level.h"
#include"Bullet.h"

MovingObject::MovingObject(sf::Vector2f position) :BaseObject(position),m_faceRight(true),m_row(1)
{
}
//----------------------------------------------------------
void MovingObject::updatePrevPosition(sf::Vector2f position)
{
	m_prevPosition = position;
}
//----------------------------------------------------------
bool MovingObject::colideMovingWithMoving(MovingObject* obj)//m_body with m_sprite
{
	return m_body.getGlobalBounds().intersects(obj->m_sprite.getGlobalBounds());//check collision
}
//----------------------------------------------------------

bool MovingObject::colideMoving(MovingObject* obj)//m_body with m_body
{
	return m_body.getGlobalBounds().intersects(obj->m_body.getGlobalBounds());//check collision
}
//----------------------------------------------------------

bool MovingObject::colideMovingWithStatic(BaseObject* obj)//m_body with getSprite()
{
	return m_body.getGlobalBounds().intersects(obj->getSprite().getGlobalBounds());//check collision
}