#include"Board.h"
#include"Factory.h"
#include "Snow.h"
#include"Level.h"

Board::Board()
{
	createSnow();
}
//--------------------------------------------
void Board::addSnowPosition(sf::Vector2f pos)
{
	m_snowPosition.emplace_back(pos);
}
//-------------------------------------------
void Board::createSnow()
{
	for (int i = 0; i < m_snowPosition.size(); i++)
	{
		m_snowVec.emplace_back(std::move(Factory::createObject("Snow", m_snowPosition[i])));
	}
	fixSnowAngle();
}
//--------------------------------------------
void Board::drawSnow()
{
	for (int i = 0; i < m_snowVec.size(); i++)
	{
		Reasources::getInstance().getWindow().draw(m_snowVec[i]->getSprite());
	}
}
//--------------------------------------------
BaseObject* Board::getSnowVec(int index)
{
	if (index > m_snowVec.size())
		return nullptr;
	return m_snowVec[index].get();
}
//------------------------------------------
std::vector<BaseObject*> Board::getAllSnowVec()
{
	std::vector<BaseObject*> rawPointers;
	rawPointers.reserve(m_snowVec.size());

	for (const auto& snow : m_snowVec)
	{
		rawPointers.push_back(snow.get());
	}

	return rawPointers;
}
//--------------------------------------------
void Board::fixSnowAngle()
{
	for (int i = 102; i < m_snowVec.size(); i++)
	{
		m_snowVec[i]->getSprite().setRotation(90);
	}
}
//------------------------------------------------------
void Board::creatObject(Level& level)
{
	createEnemies(level);
	createFriends(level);
	createStatics(level);
}
//------------------------------------------------------------
BaseObject* Board::getObject(int index) const
{
	return(m_staticObject[index].get());
}
//----------------------------------------------------------------------------
void Board::connect(BaseObject* obj, Level& level)
{
	ColorItem* colorI = dynamic_cast<ColorItem*>(obj);
	if (colorI)
	{
		CityGate* cityGate = dynamic_cast<CityGate*>(obj);
		int color = colorI->getColor();

		if (cityGate)
		{
			level.getTaskManager().setOpenCityMission(color, obj);
			return;
		}
		JailGate* jailGate = dynamic_cast<JailGate*>(obj);
		if (jailGate)
		{
			level.getTaskManager().setMission(color, obj);
			return;
		}
		KingGate* kingGate = dynamic_cast<KingGate*>(obj);
		if (kingGate)
		{
			level.getTaskManager().setMission(color, obj);
			return;
		}
	}
}
//-----------------------------------------------------
void Board::drawStaticObject()
{
	for (auto& obj : m_staticObject)
	{
		Reasources::getInstance().getWindow().draw(obj->getSprite());
	}
}
//-------------------------------------------//delet the static object by condition
void Board::deleteStaticObject()
{
	std::erase_if(m_staticObject, [](const auto& item) { return item->isDead(); });
}
//-------------------------------------
void Board::restartStaticObject()
{
	if (m_staticObject.size() > 0)
		m_staticObject.clear();
}
//-------------------------------------
void Board::createEnemies(Level& level)
{
	for (int i = 0; i < m_enemyPosition.size(); i++)
	{
		if (i < NUM_OF_SMART_ENEMYS)
			level.addEnemy("smart", m_enemyPosition[i]);
		else if (i >= NUM_OF_SMART_ENEMYS && i < NUM_OF_ENEMYS)
			level.addEnemy("stupid", m_enemyPosition[i]);
	}
}
//-------------------------------------
void Board::createFriends(Level& level)
{
	for (int i = 0; i < m_friendPosition.size(); i++)
	{
		level.addFriends("friend", m_friendPosition[i]);
	}
}
//---------------------------------------------------------
void Board::createStatics(Level& level)
{
	for (int i = 0; i < m_staticObjectPosition.size() + NUM_OF_GUNS + NUM_OF_GIFTS; i++)
	{
		if (i < NUM_OF_MEDICATION)//need to add only 3 plasters and medication and keys
			m_staticObject.emplace_back(std::move(Factory::createObject("medication", m_staticObjectPosition[i])));
		else if (i >= NUM_OF_MEDICATION && i < NUM_OF_PLASTER)
			m_staticObject.emplace_back(std::move(Factory::createObject("plaster", m_staticObjectPosition[i])));
		else if (i >= NUM_OF_PLASTER && i < NUM_OF_KEYS)
			m_staticObject.emplace_back(std::move(Factory::createObject("key", m_staticObjectPosition[i])));
		else if (i >= NUM_OF_KEYS && i < NUM_OF_CITY_GATE)//need to add only 3 gates from each type
		{
			m_staticObject.emplace_back(std::move(Factory::createObject("cityGate", m_staticObjectPosition[i])));
			connect(m_staticObject[i].get(), level);
		}
		else if (i >= NUM_OF_CITY_GATE && i < NUM_OF_JAIL_GATE)
		{
			m_staticObject.emplace_back(std::move(Factory::createObject("jailGate", m_staticObjectPosition[i])));
			connect(m_staticObject[i].get(), level);
		}
		else if (i >= NUM_OF_JAIL_GATE && i < NUM_OF_KING_GATE)
		{
			m_staticObject.emplace_back(std::move(Factory::createObject("kingGate", m_staticObjectPosition[i])));
			connect(m_staticObject[i].get(), level);
		}
		else if (i >= NUM_OF_KING_GATE && i < MAX_GUNS)
			m_staticObject.emplace_back(std::move(Factory::createObject("gun", level.getRandomPosition())));
		else if (i >= MAX_GUNS && i < MAX_GIFT)
			m_staticObject.emplace_back(std::move(Factory::createObject("gift", level.getRandomPosition())));
		else
			throw std::out_of_range("GameObjectIndex item not found.");
	}
}
