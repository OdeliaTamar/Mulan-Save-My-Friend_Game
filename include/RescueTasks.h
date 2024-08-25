#pragma once
#include"StaticObject.h"
#include"ColorItem.h"
#include"Utilities.h"
class RescueTasks :public StaticObject, public ColorItem
{
public:
	RescueTasks(sf::Vector2f position);
	virtual~RescueTasks() = default;
	int getColor() { return m_color; }
	void setColor(int color) { m_color = color; }

protected:

};
