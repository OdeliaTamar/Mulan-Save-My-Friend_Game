#pragma once
#include "Player.h"
#include "Utilities.h"

class  Factory;
class Friend: public Player
{
public:
	Friend(sf::Vector2f position);
	virtual ~Friend()=default;
	virtual void move(float time, const sf::Vector2f& mulanPosition, const std::vector<BaseObject*>& snowVec) override{}
	virtual void draw() override{ Reasources::getInstance().getWindow().draw(m_sprite); }
	virtual const sf::Vector2f& getPosition() override { return m_body.getPosition(); }
	virtual void notifyObserversForLiveAndGuns()override {}
	virtual void restartData() override {}
	virtual void moveBullets(float deltaTime, const std::vector<BaseObject*>& snowVec) override{};
	virtual bool getFaceRight() override { return m_faceRight; }
	bool getFree() const { return m_free; }
	void setFree() { m_free =true; }
	char getColor() const { return m_color; }
	virtual std::vector < std::unique_ptr<Bullet>>& getBullets() override {	return  (m_bullets);}
	void setFPosition(sf::Vector2f pos) { m_sprite.setPosition(pos); }
	void setFaceSprite();
protected:
	static bool m_register;
	bool m_free=false; 
	char m_color;
};
