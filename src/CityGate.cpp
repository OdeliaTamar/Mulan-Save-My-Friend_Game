#include"CityGate.h"
#include"Factory.h"

bool CityGate::m_register = Factory::registerObject("cityGate",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseObject> { return std::make_unique<CityGate>(pos); });

CityGate::CityGate(sf::Vector2f position):Gate(position)
{
	if (position == RED_CITY_GATE)
		m_color = 0;
	else if (position == BLUE_CITY_GATE)
		m_color = 1;
	else if (position == YELLOW_CITY_GATE)
		m_color = 2;

	m_sprite.setTexture(Reasources::getInstance().getTexture(cityGate));
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);


}
