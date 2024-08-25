#include "TasksDisply.h"
#include "TasksDisply.h"
#include"TasksDisply.h"

TasksDisply::TasksDisply()
{
	spriteMatrix[0][0].setTexture(Reasources::getInstance().getTexture(Red_Key));
	spriteMatrix[0][1].setTexture(Reasources::getInstance().getTexture(Red_medicine));
	spriteMatrix[0][2].setTexture(Reasources::getInstance().getTexture(Red_Plaster));
	spriteMatrix[0][3].setTexture(Reasources::getInstance().getTexture(Red));

	spriteMatrix[1][0].setTexture(Reasources::getInstance().getTexture(Blue_Key));
	spriteMatrix[1][1].setTexture(Reasources::getInstance().getTexture(Blue_medicine));
	spriteMatrix[1][2].setTexture(Reasources::getInstance().getTexture(Blue_Plaster));
	spriteMatrix[1][3].setTexture(Reasources::getInstance().getTexture(Blue));

	spriteMatrix[2][0].setTexture(Reasources::getInstance().getTexture(Yellow_Key));
	spriteMatrix[2][1].setTexture(Reasources::getInstance().getTexture(Yellow_medicine));
	spriteMatrix[2][2].setTexture(Reasources::getInstance().getTexture(Yellow_Plaster));
	spriteMatrix[2][3].setTexture(Reasources::getInstance().getTexture(Yellow));
}
//---------------------------------------------------------
void TasksDisply::showMission()
{
	m_saveMyFriend.setTexture(Reasources::getInstance().getTexture(saveMyFriends));
	m_saveMyFriend.setScale(0.2f, 0.2f);
	m_saveMyFriend.setPosition(50, 40);
	m_king.setTexture(Reasources::getInstance().getTexture(king));
	m_king.setScale(0.7f, 0.7f);
	m_king.setPosition(350, 550);
	Reasources::getInstance().getTaskWindow().draw(m_king);
	Reasources::getInstance().getTaskWindow().draw(m_saveMyFriend);

	spriteMatrix[2][3].setScale(0.5f, 0.5f);
	spriteMatrix[1][3].setScale(0.5f, 0.5f);
	spriteMatrix[0][3].setScale(0.5f, 0.5f);
	const float spriteSize = 140.f; // Assuming each sprite is 50x50 pixels
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if ((j != 3 && i != 0) || (j != 3 && i != 1) || (j != 3 && i != 2))
				spriteMatrix[i][j].setScale(0.9f, 0.9f);
			else
				spriteMatrix[i][j].setOrigin(spriteSize / 2.f, spriteSize / 2.f);
			spriteMatrix[i][j].setPosition(j * spriteSize + 180, i * spriteSize + 150);
			Reasources::getInstance().getTaskWindow().draw(spriteMatrix[i][j]);
		}
	}
	Reasources::getInstance().getTaskWindow().display();
}
//-----------------------------------------------------------------
void TasksDisply::updateMission(const int& row, const int& col)
{
	spriteMatrix[row][col].setColor(sf::Color(51, 51, 51));

}
//--------------------------------------------
void TasksDisply::resetMissionDisplay()
{
	// Reset the state of the mission display
	for (int i = 0; i < NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOLS; j++) 
		{
			spriteMatrix[i][j].setColor(sf::Color::White);
		}
	}
}
