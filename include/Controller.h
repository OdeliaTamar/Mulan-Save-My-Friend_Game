#pragma once
#include <SFML/Graphics.hpp>
#include"Level.h"
#include"Menu.h"
#include"Reasources.h"
#include "Utilities.h"
class Mulan;
class Controller
{
public:
	Controller();
	~Controller() = default;
	void run();
	void startNewGame();
	void printGameOver();
	void printWin();
	void draw();

protected:
	std::unique_ptr<Player> m_mulan;
	Menu m_menu;
	sf::Sprite m_gameOverWinSprite;  //for the win and game over pictures
	sf::Sound m_gameOverWinSound;   //for the win and game over
};