#include "Player.h"
Player::Player(sf::Vector2f position): MovingObject(position), m_live(TOTAL_LIVE), m_numOfGun(TOTAL_GUNS)
{
}
//------------------------------------------
void Player::updateLive(int num)
{
	m_live += num;
	notifyObserversForLiveAndGuns();
}
//-------------------------------------------
void Player::updateGuns(int num)
{
	m_numOfGun += num;
	notifyObserversForLiveAndGuns();
}
