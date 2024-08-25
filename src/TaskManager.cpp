#include "TaskManager.h"

TaskManager::TaskManager()
{
	m_mission.resize(NUM_OF_MISSIONS);//there is 4 missions:to save 3 friends and free the king
	m_openCity.resize(NUM_OF_MISSIONS - 1);
}
//----------------------------------------------------------------
void TaskManager::OpenCityMissionDone(const int& color)
{
	m_openCity[color].second->updateDead();
}
//----------------------------------------------------------
void TaskManager::missionDone(const int& color)
{
	m_mission[color].first++;
	for (int i = 0; i < NUM_OF_COLORS; i++)
	{
		if (m_mission[i].first == NUM_OF_COLORS) {
			m_mission[i].second->updateDead();
			m_mission[i].first -= NUM_OF_COLORS;
			m_tasksDisplay.updateMission(color, frinedMission);
			m_openCity[color].first = true;//city free
			m_mission[kingColor].first++;
			if (m_mission[kingColor].first == 3)
				m_mission[kingColor].second->updateDead();
		}
	}
}
//----------------------------------------------------------------
void TaskManager::setOpenCityMission(const int& color, BaseObject* obj)
{
	int c = color;
	m_openCity[color].second = obj;
	m_openCity[color].first = false;
}
//-----------------------------------------------------
void TaskManager::setMission(const int& color, BaseObject* obj)
{
	m_mission[color].second = obj;
	m_mission[color].first = 0;
}
//------------------------------------------------------
bool TaskManager::freeFriend(const int& color)
{
		if (m_openCity[color].first)
			return true;
	return false;
}
//----------------------------------------
void TaskManager::restartMissions()
{
	for (auto& mission : m_mission) 
	{
		mission.first = 0;
	}

	for (auto& city : m_openCity) 
	{
		city.first = false;
	}

	m_tasksDisplay.resetMissionDisplay();
}
//---------------------------------------
void TaskManager::resetData()
{
	m_mission.clear();
	m_openCity.clear();
	m_mission.resize(NUM_OF_MISSIONS);
	m_openCity.resize(NUM_OF_MISSIONS - 1);
	m_tasksDisplay.resetMissionDisplay();
}