#pragma once
#include<memory>
#include<vector>
#include"StaticObject.h"
#include <SFML/Graphics.hpp>
#include"Reasources.h"

class Level;
class Snow;
class Factory;
class Board
{
public:
    Board();
    ~Board() = default;
    void addSnowPosition(sf::Vector2f pos);
    void createSnow();
    void drawSnow();
    BaseObject* getSnowVec(int index);
    std::vector<BaseObject*> getAllSnowVec();
    int getSnowSize() { return int(m_snowVec.size()); }
    void fixSnowAngle();
    void addStaticObjectPosition(sf::Vector2f staticPosition) { m_staticObjectPosition.emplace_back(staticPosition); }
    void creatObject(Level& level);
    BaseObject* getObject(int index) const;
    void addEnemyPosition(sf::Vector2f enemyPos) { m_enemyPosition.emplace_back(enemyPos); }
    void addFriendPosition(sf::Vector2f friendPosition) { m_friendPosition.emplace_back(friendPosition); }
    void connect(BaseObject* obj, Level& level);
    int getSizeOfStaticObject() { return int(m_staticObject.size()); }
    void drawStaticObject();
    void deleteStaticObject();
    void restartStaticObject();
    void createEnemies(Level& level);
    void createFriends(Level& level);
    void createStatics(Level& level);

protected:
    sf::Sprite m_worldMap;
    std::vector <sf::Vector2f> m_snowPosition;
    std::vector<std::unique_ptr<BaseObject>> m_snowVec;
    sf::Vector2f startPoint = {};
    sf::Vector2f centerOfView = {};
    float zoomFactor = 1;
    bool miniMap = false;
    std::vector<std::unique_ptr<BaseObject>> m_staticObject;
    std::vector<sf::Vector2f> m_staticObjectPosition;
    std::vector<sf::Vector2f> m_enemyPosition;
    std::vector<sf::Vector2f> m_friendPosition;

};