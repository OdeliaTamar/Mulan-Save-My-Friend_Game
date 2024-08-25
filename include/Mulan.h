#pragma once
#include "Player.h"
#include "Animation.h"
#include "Subject.h"
#include"Bullet.h"

class Mulan:public Player
{
public:
	Mulan( sf::Vector2f position);
	virtual ~Mulan() = default;
	virtual void move(float deltaTime, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec) override;
	virtual void draw() override;
	virtual const sf::Vector2f& getPosition() override { return m_body.getPosition(); }
	void setPosition(sf::Vector2f pos) { m_body.setPosition(pos); }
	virtual void notifyObserversForLiveAndGuns()override;
	virtual void updateLive(int num)override;
	virtual void updateGuns(int num)override;
	virtual int getLive() const override;
	virtual int getGuns() const override;
	virtual void restartData()override;
	virtual void moveBullets(float deltaTime, const std::vector<BaseObject*>& snowVec) override;
	virtual std::vector < std::unique_ptr<Bullet>>& getBullets() override { return m_bullets; }
	void setToFirstPosition();


protected:
	Animation m_mulanAnimation;
	unsigned int m_row;
	bool m_faceRight;
	
};
