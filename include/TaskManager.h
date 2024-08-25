#pragma once
#include <memory>
#include <vector>
#include "Friend.h"
#include "RescueTasks.h"
#include "JailGate.h"
#include "Utilities.h"
#include "BaseObject.h"
#include "CityGate.h"
#include"TasksDisply.h"
#include "Reasources.h"
#include "Utilities.h"

class TaskManager
{
public:
    TaskManager();
    ~TaskManager() = default;
    void setMission(const int& color, BaseObject* obj);
    void setOpenCityMission(const int& color, BaseObject* obj);
    void OpenCityMissionDone(const int& color);
    void missionDone(const int& color);
    void showMission() { m_tasksDisplay.showMission(); }
    void updateMission(const int& row, const int& col) { m_tasksDisplay.updateMission(row, col); }
    bool freeFriend(const int& color);
    void restartMissions();

    void resetData();
protected:
     std::vector<std::pair<int, BaseObject*>> m_mission;
    std::vector<std::pair<bool, BaseObject*>> m_openCity;

    TasksDisply m_tasksDisplay; 
};
