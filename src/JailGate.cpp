#include"JailGate.h"
#include "Factory.h"

bool JailGate::m_register = Factory::registerObject("jailGate",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<JailGate>(pos); });

JailGate::JailGate(sf::Vector2f position) :Gate(position)
{
	if (position == RED_JAIL_GATE)
		m_color = 0;
	else if (position == BLUE_JAIL_GATE)
		m_color = 1;
	else if (position == YELLOW_JAIL_GATE)
		m_color = 2;
	m_sprite.setTexture(Reasources::getInstance().getTexture(gate));
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
}
