#include "Animation.h"

Animation::Animation( sf::Texture& texture, sf::Vector2u imageCount, float switchTime):m_imageCount(imageCount)
					,m_switchTime(switchTime),m_totalTime(0.0f)
{
	m_currentImage.x = 0;

	m_uvRect.width = int(texture.getSize().x) / int(imageCount.x);
	m_uvRect.height = int(texture.getSize().y) / int(imageCount.y);
}
//------------------------------------------------------------------
//update the moves of the animation
void Animation::updateMovesAnimation(int row, float deltaTime, bool faceRight)
{
	m_currentImage.y = row;
	m_totalTime += deltaTime * 0.2f;

	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;

		if (m_currentImage.x >= m_imageCount.x)
		{
			m_currentImage.x = 0;
		}
	}

	m_uvRect.top = m_currentImage.y * m_uvRect.height;

	if (faceRight)
	{
		m_uvRect.left = m_currentImage.x * m_uvRect.width;
		m_uvRect.width = abs(m_uvRect.width);
	}
	else//if it turn left
	{
		// Calculate the left position by subtracting the width
		// of the frame from the right side
		m_uvRect.left = (m_currentImage.x ) * abs(m_uvRect.width) - m_uvRect.width;
		m_uvRect.width = -abs(m_uvRect.width);
	}
	
}
//-----------------------------------------------------
//get the current image
const sf::Vector2u&  Animation::getCurrentImage()const
{
	return m_currentImage;
}
