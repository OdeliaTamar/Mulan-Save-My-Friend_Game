#include"Snow.h"
#include "Factory.h"

bool Snow::m_register = Factory::registerObject("Snow",
    [](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<Snow>(pos); });

Snow::Snow(sf::Vector2f position) :StaticObject(position)
{
    m_sprite.setTexture(Reasources::getInstance().getTexture(snow));
}
