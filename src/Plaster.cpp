#include"Plaster.h"
#include "Factory.h"

bool Plaster::m_register = Factory::registerObject("plaster",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<Plaster>(pos); });
Plaster::Plaster(sf::Vector2f position) :RescueTasks(position)
{

	if (position == RED_PLASTER)
	{
		m_color = 0;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Red_Plaster));
	}
	else if (position == BLUE_PLASTER)
	{
		m_color = 1;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Blue_Plaster));
	}
	else if (position == YELLOW_PLASTER)
	{
		m_color = 2;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Yellow_Plaster));
	}
}
