#pragma once
#include "BaseEnemy.h"
#include "Animation.h"
#include "Utilities.h"
class Reasources;
class Factory;
class StupidEnemy :public BaseEnemy
{
public:
	StupidEnemy( sf::Vector2f position);
	virtual ~StupidEnemy() = default;
	virtual void move(float deltaTime, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec) override;
	void setToFirstPosition();
	virtual void draw() override { Reasources::getInstance().getWindow().draw(m_body); } 
	virtual const sf::Vector2f& getPosition() override { return m_body.getPosition(); }

protected:
	static bool m_register;
	Animation m_stupidAnimation;
	unsigned int m_row;
	bool m_faceRight;
};