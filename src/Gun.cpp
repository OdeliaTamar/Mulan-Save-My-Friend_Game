#include "Gun.h"
#include "Factory.h"
bool Gun::m_register = Factory::registerObject("gun",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<Gun>(pos); });

Gun::Gun(sf::Vector2f position) :StaticWeapon(position)
{
	m_sprite.setTexture(Reasources::getInstance().getTexture(gun));
}
