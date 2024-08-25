#include"KingGate.h"
#include "Factory.h"

bool KingGate::m_register = Factory::registerObject("kingGate",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<KingGate>(pos); });

KingGate::KingGate(sf::Vector2f position):Gate(position)
{
	m_color = 3;
	m_sprite.setTexture(Reasources::getInstance().getTexture(kingGate));
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);

}
