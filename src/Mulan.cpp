#include "Mulan.h"

Mulan::Mulan(sf::Vector2f position) :Player(position),
		m_mulanAnimation(Reasources::getInstance().getTexture(mulanSpriteSheet), sf::Vector2u(7, 2), 0.1f)
{
	m_firstPosition = position;
	m_prevPosition = position;
	m_live = TOTAL_LIVE;
	m_speed = MULAN_SPEED;
	m_numOfGun=TOTAL_GUNS;
	m_row = 0;
	m_faceRight = true;
	m_body.setSize(MULAN_SIZE);
	m_body.setPosition(position);
	m_body.setTexture(&Reasources::getInstance().getTexture(mulanSpriteSheet));
	
}
//-------------------------------------------
void Mulan::move(float deltaTime, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= m_speed * deltaTime;
		m_faceRight = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += m_speed * deltaTime;
		m_faceRight = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= m_speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += m_speed * deltaTime;
	}
	static bool bulletFired = false; // Declare the variable as static to retain its value between function calls

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !bulletFired && m_numOfGun > 0)
	{
		m_row = 1;
		sf::Vector2f bulletPosition = m_body.getPosition();
		if (!m_faceRight)
		{
			bulletPosition.x = m_body.getPosition().x + 10.f;
			bulletPosition.y = m_body.getPosition().y + 116.f;
		}
		else
		{
			bulletPosition.x = m_body.getPosition().x + 200.f;
			bulletPosition.y = m_body.getPosition().y + 118.f;
		}
		m_bullets.emplace_back(std::make_unique<Bullet>(bulletPosition));
		updateGuns(-1);
		bulletFired = true; // Set the flag to indicate that a bullet is fired
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_row = 0;
		bulletFired = false; // Reset the flag when the spacebar is released
	}

	m_mulanAnimation.updateMovesAnimation(m_row, deltaTime * 0.05f, m_faceRight);
	m_body.setTextureRect(m_mulanAnimation.getUvRect());
	m_body.move(movement);
}
//--------------------------------------------
void Mulan::draw()
{
	 for (auto& b:m_bullets)
	 { 
		 b->draw();
	 }
	 Reasources::getInstance().getWindow().draw(m_body);
}
//-------------------------------------------
void Mulan::notifyObserversForLiveAndGuns()
{
	for (auto& observer : m_observers)
	{
		observer->updateLive(m_live);
		observer->updateGuns(m_numOfGun);
	}
}
//-------------------------------------------
void Mulan::updateLive(int num)
{
	m_live += num;
	notifyObserversForLiveAndGuns();
}
//-------------------------------------------
void Mulan::updateGuns(int num)
{
	m_numOfGun += num;
	notifyObserversForLiveAndGuns();
}

//-------------------------------------------
int Mulan::getLive()const
{
	return m_live;
}
//-------------------------------------------
int Mulan::getGuns()const
{
	return m_numOfGun;
}
//-------------------------------------------
void Mulan::restartData()
{
	m_live = TOTAL_LIVE;
	m_numOfGun = TOTAL_GUNS;
}
//-------------------------------------------------
void Mulan::moveBullets(float deltaTime, const std::vector<BaseObject*>& snowVec)
{
	for (auto& b : m_bullets)
	{
		if (b->isNewBullet())//change the direction only if its new bullet
		{
			float bulletDirection = (m_faceRight) ? 1.0f : -1.0f;
			b->setDirection(bulletDirection);
			b->setNewBullet(false);
		}

		b->move(b->getDirection() * deltaTime,getBodyPosition(),snowVec);
	}
}
//-------------------------------------------------------------------
void Mulan::setToFirstPosition()
{
	m_body.setPosition(m_firstPosition);
}
//----------------------------------------------------------------------
