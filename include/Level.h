#pragma once
#include <SFML/Graphics.hpp>
#include "TaskManager.h"
#include "BaseEnemy.h"
#include "Player.h"
#include <memory>
#include <vector>
#include <iostream>
#include "Friend.h"
#include "Factory.h"
#include "Board.h"
#include "Reasources.h"
#include "Utilities.h"
#include "Player.h"
#include "SmartEnemy.h"
#include "StupidEnemy.h"
#include"InformationDisplay.h"
#include"TaskManager.h"
#include "CollisionHandling.h"
#include"KingGate.h"
#include"ColorItem.h"
class Mulan;
class Friend;
class Bullet;
class Level
{
public:
    Level(std::unique_ptr<Player>&);
    ~Level() = default;
    void movePlayers(float deltaTime);
    bool checkWin();
    bool checkGameOver();
    bool run();
    void draw();
    void handleColidtion();
    void updateBullet() { m_mulan->setBullet(); }
    sf::Vector2f getRandomPosition();
    void deleteEnemies();
    void openCityGate(const int& color) { m_taskManager.OpenCityMissionDone(color); }
    void missionDone(const int& color) { m_taskManager.missionDone(color); }    
    Board& getBoard() { return m_board; }
    void updateMission(const int& row, const int& col) { m_taskManager.updateMission(row, col); }
    void freeFriend();
    void restartLevel();
    void addEnemy(const std::string& name, sf::Vector2f pos);
    void addFriends(const std::string& name, sf::Vector2f pos);
    TaskManager& getTaskManager() { return m_taskManager; }
  
protected:
    Board m_board;
    sf::Sprite m_Background;
    TaskManager m_taskManager;
    std::unique_ptr<Player>& m_mulan;
    sf::Sprite m_miniMapSprite;
    sf::View m_miniMapView;
    InformationDisplay m_infoDisplay;
    sf::View m_infoView;
   std::vector<std::unique_ptr<Friend>> m_friendsVec;
   // std::vector<std::shared_ptr<Friend>> m_friendsVec;
    std::vector <std::unique_ptr<BaseEnemy>> m_enemies;
    void setView();
    void setInformationDisplay();
    void setMiniMap();
};

// STL-like algorithm to run over all pairs
template <typename FwdIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
    for (; begin != end; ++begin)
        for (auto second = begin + 1; second != end; ++second)
            fn(*begin, *second);
}