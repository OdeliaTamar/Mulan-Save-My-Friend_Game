#pragma once
//#include <SFML/Graphics.hpp>

class ColorItem
{
public:
	ColorItem() = default;
	~ColorItem() = default ;
	int getColor() { return m_color; }
	void setColor(int color) { m_color = color; }

protected:
	int m_color;

};
