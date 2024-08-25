#include "BaseObject.h"

BaseObject::BaseObject(sf::Vector2f position)
{
	m_sprite.setPosition(position);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
}
//---------------------------------------------------------------------------
bool BaseObject::colideWith(BaseObject* obj)
{
	return m_sprite.getGlobalBounds().intersects(obj->m_sprite.getGlobalBounds());//check collision
}