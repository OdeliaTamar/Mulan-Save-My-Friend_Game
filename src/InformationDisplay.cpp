#include "InformationDisplay.h"
#include "Mulan.h"
#include "Player.h"
InformationDisplay::InformationDisplay(std::unique_ptr<Player>& mulan) :m_live(mulan->getLive()),
m_numOfGun(mulan->getGuns())
{
	mulan->registerObserver(this);

	m_sprait.setTexture(Reasources::getInstance().getTexture(heart));//for the live

	m_text.resize(NUM_OF_TEXTS);//for the texts-titles
	for (int i = 0; i < NUM_OF_TEXTS; i++)
	{
		sf::Vector2f Pos = { Reasources::getInstance().getText(enum Texts(i)).getPosition().x + 90.f,
		Reasources::getInstance().getText(enum Texts(i)).getPosition().y };//position of the text

		m_text[i].setFont((Reasources::getInstance().getFont())); //set the font
		m_text[i].setCharacterSize(24); //size of the text
		m_text[i].setFillColor(sf::Color(0, 51, 153));
		m_text[i].setPosition(Pos);
	}

		m_gunSprait.setTexture(Reasources::getInstance().getTexture(gun));
		m_gunSprait.setPosition(250.f, 0.0f);
}
//---------------------------------------
void InformationDisplay::display(sf::RenderTarget& target, const sf::View& view)
{
    sf::FloatRect viewRect(view.getViewport());

    // Calculate the offset based on the view's center and size
    sf::Vector2f offset(viewRect.left * view.getSize().x, viewRect.top * view.getSize().y);

    // Set the view for drawing the information display
    target.setView(view);

    // Draw the texts of the titles
    for (int i = 0; i < NUM_OF_TEXTS; i++) {
        sf::Text& titleText = Reasources::getInstance().getText(enum Texts(i));
        titleText.setPosition(titleText.getPosition() + offset);
        target.draw(titleText);
    }

    // Draw the heart sprites for the lives
    for (int i = 0, x = Reasources::getInstance().getText(live).getPosition().x + 80.f; i < m_live; i++, x += 40.f) {
        m_sprait.setPosition(float(x) + offset.x, HEART_Y_POSITION + offset.y);
        target.draw(m_sprait);
    }

    // Set the texts for the number of guns
    m_text[guns].setString(std::to_string(m_numOfGun));

    // Draw the texts
    for (int i = 0; i < NUM_OF_TEXTS; i++) {
        sf::Text& text = m_text[i];
        text.setPosition(text.getPosition() + offset);
        target.draw(text);
    }

    // Draw the gun sprite
    m_gunSprait.setPosition(m_gunSprait.getPosition() + offset);
    target.draw(m_gunSprait);

}
//------------------------------------------------------
void InformationDisplay::updateLive(int lives)
{
	m_live = lives;
}
//------------------------------------------------------
void InformationDisplay::updateGuns(int guns)
{
	m_numOfGun = guns;
}
