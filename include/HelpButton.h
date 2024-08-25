#pragma once
#include"Button.h"
#include "Reasources.h"

class HelpButton :public Button
{
public:
	HelpButton(const enum Pictures& p, sf::Vector2f position);
	virtual ~HelpButton() = default;
	virtual void click(Controller& c) const override;
protected:
	sf::Sprite m_sprite;

};
