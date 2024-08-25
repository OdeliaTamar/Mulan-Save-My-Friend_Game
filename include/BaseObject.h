#pragma once
#include <SFML/Graphics.hpp>
#include"Reasources.h"
class BaseObject
{
public:
	BaseObject(sf::Vector2f position);
	virtual ~BaseObject() = default;
	sf::Sprite& getSprite() { return m_sprite; }
	void setSprite(sf::Texture& texture) { m_sprite.setTexture(texture); }
	bool colideWith(BaseObject* obj);

	bool isDead()const{ return m_dead; }
	void updateDead(){ m_dead = true; }
protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	bool m_dead = false;
};
