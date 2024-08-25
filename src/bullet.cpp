#include"Bullet.h"


Bullet::Bullet(sf::Vector2f position) :MovingWeapon(position)
{
	m_sprite.setTexture(Reasources::getInstance().getTexture(bullet));
	m_speed = 30;
	m_newBullet = true; // Set the bullet as newly created
	m_position = position;
	m_sprite.setPosition(m_position);
	m_direction =0;
}
//---------------------------------------------------------------------
void Bullet::move(float time, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.x += m_speed * time;
	m_sprite.move(movement.x,0);
}
