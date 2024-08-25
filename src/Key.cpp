#include "Key.h"
#include "Factory.h"

bool Key::m_register = Factory::registerObject("key",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<Key>(pos); });

Key::Key(sf::Vector2f position) :RescueTasks(position)
{
	if (position == RED_KEY)
	{
		m_color = 0;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Red_Key));
	}
	else if (position == BLUE_KEY)
	{
		m_color = 1;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Blue_Key));
	}
	else if (position == YELLOW_KEY)
	{
		m_color = 2;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Yellow_Key));
	}
	
}
