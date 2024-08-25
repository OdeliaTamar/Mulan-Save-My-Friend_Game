#pragma once
#include <SFML/Graphics.hpp>
#include "Reasources.h"
class Animation
{
public:
	Animation(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);
	~Animation()=default;
	void updateMovesAnimation(int row, float deltaTime, bool faceRight);
	const sf::IntRect& getUvRect() const { return m_uvRect; }
	const sf::Vector2u& getCurrentImage()const;
private:
	sf::Vector2u m_imageCount;
	sf::Vector2u m_currentImage;
	float m_totalTime;
	float m_switchTime;
	sf::IntRect m_uvRect;
};
