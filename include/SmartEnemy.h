#pragma once
#include <SFML/Graphics.hpp>
#include "BaseEnemy.h"
#include "Animation.h"
#include "Utilities.h"
#include "Bullet.h"
class Reasources;
class Factory;
class SmartEnemy:public BaseEnemy
{
public:
	SmartEnemy(sf::Vector2f position);
	virtual ~SmartEnemy() = default;
	virtual void move(float deltaTime,const sf::Vector2f& mulanPosition,
	const std::vector<BaseObject*>& snowVec) override;
	const sf::Vector2f& getBodyPosition() { return m_body.getPosition(); }
	virtual void draw() override;
	void setToFirstPosition();
	virtual const sf::Vector2f& getPosition() override { return m_body.getPosition(); }

protected:
	static bool m_register;
	Animation m_smartAnimation;
	unsigned int m_row;
	bool m_faceRight;
	std::vector < std::unique_ptr<Bullet>> m_bullets;
};
