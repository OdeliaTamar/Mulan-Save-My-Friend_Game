#include "Friend.h"
#include"Factory.h"
bool Friend::m_register = Factory::registerFriend("friend",
	[](sf::Vector2f pos) -> std::unique_ptr<Friend> { return std::make_unique<Friend>(pos); });

Friend::Friend(sf::Vector2f position) :Player(position)
{
	if (position == RED_FRIEND)
	{
		m_color = 0;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Red));
	}
	else if (position == YELLOW_FRIEND)
	{
		m_color = 2;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Yellow));
	}
	else if (position == BLUE_FRIEND)
	{
		m_color = 1;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Blue));
	}
	else if (position == KING_POS)
	{
		m_color = 3;
		m_sprite.setTexture(Reasources::getInstance().getTexture(king));
	}
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
	m_faceRight = true;
}

void Friend::setFaceSprite()
{
	if (m_faceRight)
		m_sprite.setScale(1.f, 1.f);
	else
		m_sprite.setScale(-1.f, 1.f);

	// Adjust the origin of the sprite based on its facing direction
	sf::FloatRect bounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, 0.f);
}