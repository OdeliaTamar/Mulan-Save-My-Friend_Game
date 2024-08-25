#include "Reasources.h"


Reasources& Reasources::getInstance()
{
	static Reasources m_instance;
	return m_instance;
}

Reasources::Reasources()
{
	m_texture.resize(NUM_OF_PICTURES);

	m_texture[newGameButton].loadFromFile("NewGameButton.png");
	m_texture[helpButton].loadFromFile("HelpButton.png");
	m_texture[exitButton].loadFromFile("ExitButton.png");

	m_texture[background].loadFromFile("background.png");
	m_texture[mulan].loadFromFile("mulan1.png");
	m_texture[friendOfMulan].loadFromFile("shifu-helper.png");

	m_texture[mulanSpriteSheet].loadFromFile("mulanSpriteSheet.png");

	m_texture[mulanAndMushuSprite].loadFromFile("mulanAndMushuSprite.png");
	m_texture[shanYoSpariteSheet].loadFromFile("shanYoSpariteSheet.png");
	m_texture[shifuHelperSpriteSheet].loadFromFile("shifuHelperSpriteSheet.png");
	m_texture[Blue].loadFromFile("Blue.png");
	m_texture[Yellow].loadFromFile("Yellow.png");
	m_texture[Red].loadFromFile("Red.png");
	m_texture[heart].loadFromFile("Heart.png");
	m_texture[Red_medicine].loadFromFile("medicineR.png");
	m_texture[Blue_medicine].loadFromFile("medicineB.png");
	m_texture[Yellow_medicine].loadFromFile("medicineY.png");
	m_texture[Red_Plaster].loadFromFile("plasterR.png");
	m_texture[Blue_Plaster].loadFromFile("plasterB.png");
	m_texture[Yellow_Plaster].loadFromFile("plasterY.png");
	m_texture[Red_Key].loadFromFile("KeyR.png");
	m_texture[Blue_Key].loadFromFile("KeyB.png");
	m_texture[Yellow_Key].loadFromFile("KeyY.png");

	m_texture[bullet].loadFromFile("bullet.png");
	m_texture[gun].loadFromFile("gun.png");
	m_texture[redFree].loadFromFile("redFree.png");
	m_texture[yellowFree].loadFromFile("yellowFree.png");
	m_texture[blueFree].loadFromFile("blueFree.png");
	m_texture[cityGate].loadFromFile("city_gate.png");
	m_texture[kingGate].loadFromFile("king_gate.png");
	m_texture[gate].loadFromFile("gate.png");
	m_texture[snow].loadFromFile("snow.png");
	m_texture[gift].loadFromFile("gift.png");
	m_texture[win].loadFromFile("win.png");
	m_texture[gameOver].loadFromFile("gameOver.png");
	m_texture[king].loadFromFile("king.png");
	m_texture[saveMyFriends].loadFromFile("saveMyFriends.png");
	m_texture[help].loadFromFile("help1.png");


	m_text.resize(NUM_OF_TEXTS);
	m_text[live].setString("Live:");

	m_text[guns].setString("X ");
	
	m_buffer.resize(NUM_OF_SOUNDS);
	m_buffer[GameOver].loadFromFile("gameOver.wav");
	m_buffer[Win].loadFromFile("Win.wav");

	//load the background music
	m_music.openFromFile("background.wav");
	for (int i = 0, x = 10; i < NUM_OF_TEXTS; i++, x += 400)
	{
		m_font.loadFromFile("C:/Windows/Fonts/SNAP____.ttf");
		m_text[i].setFont(m_font);
		m_text[i].setCharacterSize(24); 
		m_text[i].setFillColor(sf::Color::Black);// set the color
		m_text[i].setPosition(x, 0);// the position of the text
	}
}
//-------------------------------------
sf::RenderWindow& Reasources::getWindow()
{
	return m_window;
}
//-------------------------------------
sf::RenderWindow& Reasources::getTaskWindow()
{
	return m_taskWindow;
}
//-------------------------------------
sf::RenderWindow& Reasources::getHelpWindow()
{
	return m_helpWindow;
}
//-------------------------------------
void Reasources::createWindow()
{
	m_window.create(sf::VideoMode(WINDOW_HEIGHT_SIZE, WINDOW_WIDTH_SIZE), "Mulan");
}
//-------------------------------------
 void Reasources::createTaskWindow()
{
	m_taskWindow.create(sf::VideoMode(800, 850), "Task");
}
 //-------------------------------------
void Reasources::createHelpWindow()
{
	m_helpWindow.create(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Help");
}
//-------------------------------------
sf::Texture& Reasources::getTexture(enum Pictures index)
{
	return m_texture[index];
}
//-------------------------------------
sf::Text& Reasources::getText(enum Texts index)
{
	return m_text[index];
}
//-------------------------------------
sf::Font& Reasources::getFont()
{
	return m_font;
}
//-------------------------------------
sf::SoundBuffer& Reasources::getSoundBuffer(enum SoundBuffer index)
{
	return m_buffer[index];
}
//-------------------------------------
sf::Music& Reasources::getMusic()
{
	return m_music;
}
