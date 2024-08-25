#pragma once
#include "Button.h"
class NewGameButton :public Button
{
public:
	NewGameButton(const enum Pictures& p, sf::Vector2f position);
	virtual ~NewGameButton() = default;
	virtual void click(Controller& c) const override;

protected:

};