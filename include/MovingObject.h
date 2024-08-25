#pragma once
#include "BaseObject.h"
class Level;
class MovingObject:public BaseObject
{
public:
	MovingObject( sf::Vector2f position);
	virtual ~MovingObject() = default;
	virtual void move(float time, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec) = 0;
	void updatePrevPosition(sf::Vector2f position);
	virtual void draw() = 0;
	float getSpeed()const { return m_speed; }
	void setSpeed(float speed) { m_speed = speed; }
	virtual const sf::Vector2f& getPosition() { return m_sprite.getPosition(); }
	virtual const sf::Vector2f& getBodyPosition() { return m_body.getPosition(); }
	virtual bool getFaceRight() = 0;
	bool colideMovingWithMoving(MovingObject* obj);//m_body with m_sprite
	bool colideMoving(MovingObject* obj);//m_body with m_body
	bool colideMovingWithStatic(BaseObject* obj);//m_body with getSprite()


	
protected:
	sf::Vector2f m_direction;
	float m_speed = float(SPEED);
	sf::Vector2f m_prevPosition;
	sf::Vector2f m_firstPosition;

	sf::RectangleShape m_body;
	unsigned int m_row;
	bool m_faceRight;
};
