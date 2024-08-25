#include "LifeGift.h"
#include "Factory.h"
bool LifeGift::m_register = Factory::registerObject("gift",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<LifeGift>(pos); });

LifeGift::LifeGift(sf::Vector2f position):Gift(position)
{
	m_sprite.setTexture(Reasources::getInstance().getTexture(gift));
}
