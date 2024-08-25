#include "Level.h"
#include"Mulan.h"
#include"Friend.h"
#include"Bullet.h"
Level::Level(std::unique_ptr<Player>& mulan) :m_mulan(mulan), m_infoDisplay(m_mulan)
{
	// Load and set the background texture
	m_Background.setTexture(Reasources::getInstance().getTexture(background));
	m_miniMapSprite.setTexture(Reasources::getInstance().getTexture(background));

	// Adjust the size and position of the mini map sprite
	m_miniMapSprite.setScale(0.2f, 0.2f); // Adjust the scale as per your preference

	// Set up the view for the mini map
	m_miniMapView.setSize(sf::Vector2f(3500.f, 2550.f)); // Adjust the size of the mini map view as per your preference
	m_miniMapView.setViewport(sf::FloatRect(0.5f, 0.56f, 0.50f, 0.50f)); // Adjust the viewport for the mini map view

	m_infoView.setSize(sf::Vector2f(0.5f, 1500.f)); // Adjust the size of the mini map view as per your preference
	m_infoView.setViewport(sf::FloatRect(0.f, 0.f, 0.05f, 1500.f));

	// Set the center of the mini map view to the player's position
	m_miniMapView.setCenter(m_mulan->getPosition());
	m_miniMapView.setCenter(sf::Vector2f(0.f, 0.f));
	restartLevel();
	Factory::readFromFile(*this, m_board);
	m_board.createSnow();
	m_board.creatObject(*this);
}
//--------------------------------------------------------------------------
bool Level::run()
{
	Reasources::getInstance().getMusic().setLoop(true);//play music
	Reasources::getInstance().getMusic().play();
	float deltaTime = 0.0f;
	sf::Clock clock;

	Reasources::getInstance().createWindow();
	deltaTime = clock.restart().asSeconds();
	while (Reasources::getInstance().getWindow().isOpen())
	{
		sf::Vector2i releasePosition;

		for (auto event = sf::Event{}; Reasources::getInstance().getWindow().pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Reasources::getInstance().getWindow().close();
				break;
			case sf::Event::KeyPressed://if key T is pressed
				if (event.key.code == sf::Keyboard::T)
				{
					Reasources::getInstance().createTaskWindow();//window for the tasks
					while (Reasources::getInstance().getTaskWindow().isOpen())
					{
						for (auto event = sf::Event{}; Reasources::getInstance().getTaskWindow().pollEvent(event); )
						{
							switch (event.type)
							{
							case sf::Event::Closed:
								Reasources::getInstance().getTaskWindow().close();
								break;
							}
						}
						Reasources::getInstance().getTaskWindow().clear(sf::Color::White);
						m_taskManager.showMission();
					}
				}
				break;

			}
		}

		movePlayers(deltaTime);
		handleColidtion();

		freeFriend();
		if (checkWin())
			return true;
		
		if (checkGameOver())
			return false;

		Reasources::getInstance().getWindow().clear(sf::Color(230, 247, 255));
		draw();
		Reasources::getInstance().getWindow().display();
	}
	return true;
}
//---------------------------------------------------------
void Level::draw()
{
	setView();
	m_board.drawSnow();

	for (auto& amigo : m_friendsVec)
	{
		amigo->draw();
	}

	m_board.drawStaticObject();

	for (auto& enemy : m_enemies)
	{
		if (!enemy->isDead())
			enemy->draw();
	}
	m_mulan->draw();

	setInformationDisplay();

	setMiniMap();
}
//-------------------------------------------------------------------
void Level::handleColidtion()
{
	for (int j = 0; j < m_enemies.size(); j++)//the enemies colision
	{
		for (int i = 0; i < m_mulan->getBullets().size(); i++)//enemies with bullets
		{
			if (m_enemies[j]->colideMovingWithMoving(m_mulan->getBullets()[i].get()))
			{
				processCollision(*m_enemies[j].get(), *m_mulan->getBullets()[i].get(), *this);
			}
		}
		if (m_enemies[j]->colideMoving(m_mulan.get()))//enemies with Mulan
			processCollision(*m_enemies[j].get(), *m_mulan.get(), *this);

		for (int i = 0; i < m_board.getSnowSize(); i++)//enemies with snow
		{
			if (m_enemies[j]->colideMovingWithStatic(m_board.getSnowVec(i)))
			{
				processCollision(*m_enemies[j].get(), *m_board.getSnowVec(i), *this);
			}
		}
	}

	for (int i = 0; i < m_board.getSizeOfStaticObject(); i++)//enemies with statics
	{
		if (m_mulan->colideMovingWithStatic(m_board.getObject(i)))
		{
			processCollision(*m_mulan.get(), *m_board.getObject(i), *this);
		}
	}

	for (int i = 0; i < m_board.getSnowSize(); i++)//mulan with snow
	{
		if (m_mulan->colideMovingWithStatic(m_board.getSnowVec(i)))
		{
			processCollision(*m_mulan.get(), *m_board.getSnowVec(i), *this);
		}
	}
	m_board.deleteStaticObject();
	deleteEnemies();

}
//------------------------------------------------------
void Level::movePlayers(float deltaTime)
{

	m_mulan->updatePrevPosition((m_mulan->getBodyPosition()));//save the last position
	for (auto& enemy : m_enemies)
	{
		enemy->updatePrevPosition(enemy->getBodyPosition());
		enemy->move(deltaTime, m_mulan->getPosition(), m_board.getAllSnowVec());
	}
	m_mulan->move(deltaTime, m_mulan->getPosition(), m_board.getAllSnowVec());

	m_mulan->moveBullets(deltaTime, m_board.getAllSnowVec());
}
//--------------------------------------------------------
bool Level::checkWin()
{
	if (m_mulan->colideMovingWithStatic(m_friendsVec[3].get()))//king colision
	{
		processCollision(*m_mulan.get(), *m_friendsVec[3].get(), *this);
		return true;
	}
	return false;
}
//--------------------------------------------------------
bool  Level::checkGameOver()
{
	if (m_mulan->getLive() == 0)
	{
		return true;
	}
	return false;
}
//--------------------------------------------------------
sf::Vector2f Level::getRandomPosition()
{
	sf::Vector2f newPosition;
	// Generate random numbers for x and y within the specified ranges
	float x = float(std::rand() % 3951 + 50);
	float y = float(std::rand() % 6951 + 50);
	newPosition = sf::Vector2f(x, y);
	
	return newPosition;

}
//-------------------------------------------//delet the enemies by condition
void Level::deleteEnemies()
{
	std::erase_if(m_enemies, [](const auto& item) { return item->isDead(); });
}
//--------------------------------------------------------
void Level::freeFriend()
{
	for (int i = 0; i < m_friendsVec.size() - 1; i++)
	{
		if (m_taskManager.freeFriend(i) && i ==int(red))
		{
			m_friendsVec[i]->getSprite().setTexture(Reasources::getInstance().getTexture(redFree));
			m_friendsVec[i]->setFPosition(sf::Vector2f(m_mulan->getPosition().x + 50, m_mulan->getPosition().y));
		}
		else if (m_taskManager.freeFriend(i) && i == int(blue))
		{
			m_friendsVec[2]->getSprite().setTexture(Reasources::getInstance().getTexture(blueFree));
			m_friendsVec[2]->setFPosition(sf::Vector2f(m_mulan->getPosition().x , m_mulan->getPosition().y + 12.f));
		}
		else if (m_taskManager.freeFriend(i) && i == int(yellow))
		{
			m_friendsVec[1]->getSprite().setTexture(Reasources::getInstance().getTexture(yellowFree));
			m_friendsVec[1]->setFPosition(sf::Vector2f(m_mulan->getPosition().x - 50.f, m_mulan->getPosition().y));
		}
	}
}
//--------------------------------------------------------------------------
void Level::addEnemy(const std::string& name, sf::Vector2f pos)
{
	m_enemies.emplace_back(std::move(Factory::createEnemy(name, pos)));
}
//--------------------------------------------------------------------------
void Level::addFriends(const std::string& name, sf::Vector2f pos)
{
	m_friendsVec.emplace_back(std::move(Factory::createFriend(name, pos)));
}
//---------------------------------------------------------------
void Level::setView()
{
	sf::Vector2f windowSize(WINDOW_HEIGHT_SIZE, WINDOW_WIDTH_SIZE); // Size of the window
	sf::Vector2f backgroundSize(BACKGROUND_PIC_HEIGHT_SIZE, BACKGROUND_PIC_WIDTH_SIZE); // Size of the background image

	sf::Vector2f playerPosition = m_mulan->getPosition();
	sf::Vector2f playerOffset = playerPosition - windowSize / 2.f; // Offset of the player from the center of the window

	// Calculate the view center based on the player's position
	sf::Vector2f viewCenter = playerPosition;
	viewCenter.x = std::min(std::max(viewCenter.x, windowSize.x / 2.f), backgroundSize.x - windowSize.x / 2.f);
	viewCenter.y = std::min(std::max(viewCenter.y, windowSize.y / 2.f), backgroundSize.y - windowSize.y / 2.f);

	// Set the zoom level for the main view
	float zoomLevel = 1.2f;
	sf::Vector2f scaledWindowSize = windowSize * zoomLevel;

	// Calculate the view bounds based on the zoom level
	sf::FloatRect viewBounds(viewCenter - scaledWindowSize / 2.f, scaledWindowSize);

	// Adjust the view bounds to ensure it does not go beyond the background limits
	viewBounds.left = std::max(viewBounds.left, 0.f);
	viewBounds.top = std::max(viewBounds.top, 0.f);
	viewBounds.left = std::min(viewBounds.left, backgroundSize.x - viewBounds.width);
	viewBounds.top = std::min(viewBounds.top, backgroundSize.y - viewBounds.height);

	// Create the main view with the adjusted size and bounds
	sf::View mainView(viewBounds);
	Reasources::getInstance().getWindow().setView(mainView);

	// Draw the background
	Reasources::getInstance().getWindow().draw(m_Background);

}
//----------------------------------------------
void Level::setInformationDisplay()
{

	sf::View prevView = Reasources::getInstance().getWindow().getView();	// Save the current view
	sf::View infoView(sf::FloatRect(0.f, 0.f, 2000.f, 1500.f));	// Create a new view for the information display
	Reasources::getInstance().getWindow().setView(infoView);	// Set the view for the information display
	m_infoDisplay.display(Reasources::getInstance().getWindow(), infoView);// Draw the information display
	Reasources::getInstance().getWindow().setView(prevView);	// Restore the previous view

}
//------------------------------------
void Level::setMiniMap()
{
	sf::View previousView = Reasources::getInstance().getWindow().getView();	// Save the current view
	Reasources::getInstance().getWindow().setView(m_miniMapView);// Set the minimap view
	Reasources::getInstance().getWindow().draw(m_miniMapSprite);	// Draw the minimap background
	// Draw the player marker on the minimap
	sf::Vector2f playerPositionOnMiniMap = m_mulan->getPosition() * 0.2f; // Adjust the scaling factor as per your mini map size
	sf::CircleShape playerMarker(9.f);
	playerMarker.setFillColor(sf::Color::Red);
	playerMarker.setPosition(playerPositionOnMiniMap);
	Reasources::getInstance().getWindow().draw(playerMarker);// Draw the player marker on the minimap
	Reasources::getInstance().getWindow().setView(m_infoView);
	Reasources::getInstance().getWindow().setView(previousView);	// Restore the previous view
}
//---------------------------------
void Level::restartLevel()
{
	if (m_board.getSnowSize() > 0)
		m_board.getAllSnowVec().clear();
	if (m_enemies.size() > 0)
		m_enemies.clear();
	if (m_friendsVec.size() > 0)
		m_friendsVec.clear();
	m_board.restartStaticObject();

	// Call resetData() to restart the data
	m_taskManager.resetData();
}