#include "SmartEnemy.h"
#include "Factory.h"
#include "Reasources.h"

bool SmartEnemy::m_register = Factory::registerEnemy("smart",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseEnemy> { return std::make_unique<SmartEnemy>( pos); });


SmartEnemy::SmartEnemy(sf::Vector2f position):BaseEnemy(position),
			m_smartAnimation(Reasources::getInstance().getTexture(shanYoSpariteSheet), sf::Vector2u(3, 1), 0.01f)
{
	m_speed = SMART_ENEMY_SPEED;
	m_row = 0;
	m_faceRight = true;
	m_body.setSize(sf::Vector2f(SMART_ENEMY_SIZE));
	m_body.setPosition(position);
	m_body.setTexture(&Reasources::getInstance().getTexture(shanYoSpariteSheet));
	m_firstPosition = position;
}
//----------------------------------------------------------------------
void SmartEnemy::move(float deltaTime, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec)
{
	sf::Vector2f movement(0.0f, 0.0f);

	// Calculate the difference in positions between Mulan and the SmartEnemy
	sf::Vector2f diff = mulanPosition - m_body.getPosition();

	// Check if there is a wall
	bool isWallAhead = false;
	sf::FloatRect enemyBounds = m_body.getGlobalBounds();
	sf::Vector2f nextPosition = m_body.getPosition() + diff;
	for (const auto& snow : snowVec)
	{
		sf::FloatRect snowBounds = snow->getSprite().getGlobalBounds();
		if (enemyBounds.intersects(snowBounds))
		{
			isWallAhead = true;
			break;
		}
	}

	// Adjust movement based on the presence of a wall
	if (isWallAhead)
	{
		// Move away from the wall by a certain distance (by pixels)
		float moveAwayDistance = 200.0f;
		movement.x = (diff.x > 0.0f) ? -moveAwayDistance : moveAwayDistance;
		movement.y = (diff.y > 0.0f) ? -moveAwayDistance : moveAwayDistance;
		m_faceRight = (diff.x > 0.0f);
	}
	else
	{
		// Continue pursuing Mulan intelligently
		// Check if the horizontal distance is greater than a threshold
		if (std::abs(diff.x) > 20.0f)
		{
			movement.x = (diff.x > 0.0f) ? 0.10f : -0.10f; // Move left or right based on the difference in x-coordinates
			m_faceRight = (diff.x > 0.0f);
		}

		// Check if the vertical distance is greater than a threshold
		if (std::abs(diff.y) > 20.0f)
		{
			movement.y = (diff.y > 0.0f) ? 0.10f : -0.10f; // Move up or down based on the difference in y-coordinates
		}
	}

	m_row = 0;

	m_smartAnimation.updateMovesAnimation(m_row, deltaTime * 0.002f, m_faceRight);
	m_body.setTextureRect(m_smartAnimation.getUvRect());
	m_body.move(movement);

}
//-----------------------------------------
void SmartEnemy::draw()
{
	for (auto& b : m_bullets)
	{
		b->draw();
	}
	Reasources::getInstance().getWindow().draw(m_body);
}
//-----------------------------------------
void SmartEnemy::setToFirstPosition()
{
	m_body.setPosition(m_firstPosition);
}
