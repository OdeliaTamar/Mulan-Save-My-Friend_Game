#pragma once
#include"StaticObject.h"
#include"ColorItem.h"
class Gate :public StaticObject, public ColorItem
{
public:
	Gate(sf::Vector2f position);
	virtual~Gate() = default;
	int getColor() { return m_color; }
	void setColor(int color) { m_color = color; }

protected:

};