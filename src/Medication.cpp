#include "Medication.h"
#include "Factory.h"

bool Medication::m_register = Factory::registerObject("medication",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<Medication>(pos); });

Medication::Medication(sf::Vector2f position):RescueTasks(position)
{
	if (position == RED_MEDICATION)
	{
		m_color = 0;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Red_medicine));
	}
	else if (position == BLUE_MEDICATION)
	{
		m_color = 1;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Blue_medicine));
	}
	else if (position == YELLOW_MEDICATION)
	{
		m_color = 2;
		m_sprite.setTexture(Reasources::getInstance().getTexture(Yellow_medicine));
	}
}
