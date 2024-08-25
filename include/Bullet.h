#pragma once
#include "MovingWeapon.h"
class Bullet:public MovingWeapon
{
public:
	Bullet(sf::Vector2f position);
	virtual~Bullet()=default;
	virtual void move(float time, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec) override;
	virtual void draw() override { Reasources::getInstance().getWindow().draw(m_sprite); }
	void setDirection(float direction) { m_direction = direction; } // Setter for bullet's direction
	bool hasDirectionSet() const { return m_direction != 0.0f; } // Check if bullet's direction has been set
	float getDirection() const { return m_direction; } // Getter for bullet's direction
	bool isNewBullet() const { return m_newBullet; } // Check if the bullet is newly created
	void setNewBullet(bool isNew){ m_newBullet = isNew;} // Set the bullet as newly created or not
protected:
	float m_direction; 
	bool m_newBullet;
};
