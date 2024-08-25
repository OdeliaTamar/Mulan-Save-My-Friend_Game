#include "ExitButton.h"

ExitButton::ExitButton(const enum Pictures& p, sf::Vector2f position) :Button(p, position)
{
}
//---------------------------------------
void ExitButton::click(Controller& c) const
{
	Reasources::getInstance().getWindow().close();
}