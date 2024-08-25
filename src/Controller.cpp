#include "Controller.h"
#include"Mulan.h"

Controller::Controller() :m_mulan(std::make_unique<Mulan>(sf::Vector2f(950, 475)))
, m_menu(*this)
{
	m_gameOverWinSprite.setTexture(Reasources::getInstance().getTexture(gameOver));
	m_gameOverWinSprite.setOrigin(m_gameOverWinSprite.getLocalBounds().width / 2, m_gameOverWinSprite.getLocalBounds().height / 2);
}
//-----------------------------------------------
void Controller::run()
{
	m_menu.show();
}
//-----------------------------------------------
void Controller::startNewGame()
{
	m_mulan->restartData();
	int levelNum = 1;

	//start the levels
	for (; levelNum <= NUM_OF_LEVELS; levelNum++)
	{
		Level level(m_mulan);
		if (!level.run()) //can continue to the next level
		{
			printGameOver();
			return;
		}
	}
	if (levelNum == NUM_OF_LEVELS + 1)
	{
		printWin();//show "you win"
		levelNum = 1;
	}
}
//-----------------------------------------------
void Controller::printGameOver()
{
	Reasources::getInstance().getMusic().stop();
	m_gameOverWinSound.setBuffer(Reasources::getInstance().getSoundBuffer(GameOver));
	m_gameOverWinSound.play();
	m_gameOverWinSprite.setTexture(Reasources::getInstance().getTexture(gameOver));
	Reasources::getInstance().getWindow().setView(Reasources::getInstance().getWindow().getDefaultView());
	m_gameOverWinSprite.setPosition(sf::Vector2f(Reasources::getInstance().getWindow().getSize().x / 2,
		Reasources::getInstance().getWindow().getSize().y / 2));
	draw();
}
//-----------------------------------------------
void Controller::printWin()
{
	Reasources::getInstance().getMusic().stop();
	m_gameOverWinSound.setBuffer(Reasources::getInstance().getSoundBuffer(Win));
	m_gameOverWinSound.play();
	m_gameOverWinSprite.setTexture(Reasources::getInstance().getTexture(win));
	Reasources::getInstance().getWindow().setView(Reasources::getInstance().getWindow().getDefaultView());
	m_gameOverWinSprite.setPosition(sf::Vector2f(Reasources::getInstance().getWindow().getSize().x / 2,
		Reasources::getInstance().getWindow().getSize().y / 2));
	draw();
}
//-----------------------------------------------
void Controller::draw()
{
	Reasources::getInstance().getWindow().clear(sf::Color::White);
	Reasources::getInstance().getWindow().draw(m_gameOverWinSprite);
	Reasources::getInstance().getWindow().display();
	sf::Time delayTime = sf::seconds(DELAY_TIME);
	sf::sleep(sf::Time(delayTime));
}

