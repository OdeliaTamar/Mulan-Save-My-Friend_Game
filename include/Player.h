#pragma once
#include "MovingObject.h"
#include "Subject.h"
#include "Bullet.h"
class Player :public MovingObject, public Subject
{
public:
	Player(sf::Vector2f position);
	virtual ~Player() = default;
	sf::Vector2f getPrevPosition() const { return m_prevPosition; }
	const sf::Vector2f& getBodyPosition() { return m_body.getPosition(); }
	void updatePrevPosition(sf::Vector2f position) { m_prevPosition = position; }
	void setPosition(sf::Vector2f pos) { m_body.setPosition(pos); }
	virtual void notifyObserversForLiveAndGuns()=0;
	virtual void updateLive(int num);
	virtual void updateGuns(int num) ;
	virtual int getLive() const { return m_live; };
	virtual int getGuns() const { return m_numOfGun; };
	virtual void restartData()=0;
	virtual void moveBullets(float deltaTime, const std::vector<BaseObject*>& snowVec)=0;
	virtual bool getFaceRight() override { return m_faceRight; }
	void setFaceRight(bool face) {  m_faceRight=face; }
	virtual std::vector < std::unique_ptr<Bullet>>& getBullets() = 0;
	void setBullet() { m_bullets.clear(); }
protected:

	sf::Vector2f m_prevPosition;
	int m_live;
	std::vector < std::unique_ptr<Bullet>> m_bullets;
	int m_numOfGun;

};