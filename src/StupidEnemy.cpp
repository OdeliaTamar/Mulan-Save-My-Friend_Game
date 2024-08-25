#include "StupidEnemy.h"
#include "Factory.h"
#include "Reasources.h"

bool StupidEnemy::m_register = Factory::registerEnemy("stupid",
	[](sf::Vector2f pos) -> std::unique_ptr<BaseEnemy> { return std::make_unique<StupidEnemy>(pos); });

StupidEnemy::StupidEnemy(sf::Vector2f position):BaseEnemy(position),
		m_stupidAnimation(Reasources::getInstance().getTexture(shifuHelperSpriteSheet), sf::Vector2u(4, 1), 0.01f)
{
	m_speed = 0.90f;
	m_row = 0;
	m_faceRight = true;
	m_body.setSize(sf::Vector2f(100.0f, 250.0f));
	m_body.setPosition(position);
	m_body.setTexture(&Reasources::getInstance().getTexture(shifuHelperSpriteSheet));//???
	m_firstPosition = position;
}
//-----------------------------------------
void StupidEnemy::move(float deltaTime, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec)
{
	sf::Vector2f movement(0.0f, 0.0f);
	float speed = m_speed * deltaTime;

	if (m_faceRight)
	{
		movement.x += speed; // Move right
	}
	else
	{
		movement.x -= speed; // Move left
	}

	m_row = 0;

	m_stupidAnimation.updateMovesAnimation(m_row, deltaTime * 0.002f, m_faceRight);
	m_body.setTextureRect(m_stupidAnimation.getUvRect());

	// Calculate the potential new position
	sf::Vector2f newPosition = m_body.getPosition() + movement;

	bool collidedWithWall = false;

	// Check collision with snows
	for (const auto& wall : snowVec)
	{
		if (m_body.getGlobalBounds().intersects(wall->getSprite().getGlobalBounds()))
		{
			collidedWithWall = true;

			// Reverse the face direction
			m_faceRight = !m_faceRight;
			break;
		}
	}

	// Update the movement and face direction based on the collision result
	if (!collidedWithWall)
	{
		m_body.move(movement);// Move the character to the new position
	}
	else
	{
		// Calculate the new movement based on the updated face direction
		movement.x = m_faceRight ? speed : -speed;
		m_body.move(movement);
	}
}
//-----------------------------------------
void StupidEnemy::setToFirstPosition()
{
	m_body.setPosition(m_firstPosition);
}
