#include"StaticObject.h"


class Factory;
class Snow :public StaticObject
{
public:
	Snow(sf::Vector2f position);
	virtual~Snow() = default;

protected:
	static bool m_register;
};
