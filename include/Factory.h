#pragma once
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include"Medication.h"
#include "BaseEnemy.h"
#include"Reasources.h"
#include"Plaster.h"
#include"Key.h"
#include "Friend.h"
#include"Board.h"

using std::istringstream;
using namespace std;
using std::ifstream;
class Level;

typedef std::map<std::string, std::unique_ptr<BaseObject>(*)(sf::Vector2f)> mymap;
typedef std::map<std::string, std::unique_ptr<BaseEnemy>(*)(sf::Vector2f)> enemyVec;
typedef std::map<std::string, std::unique_ptr<Friend>(*)(sf::Vector2f)> friendVec;

class Factory
{
public:
    Factory();
    static std::unique_ptr<BaseObject> createObject(const std::string& name, sf::Vector2f pos);
    static std::unique_ptr<BaseEnemy> createEnemy(const std::string& name, sf::Vector2f pos);
    static std::unique_ptr<Friend> createFriend(const std::string& name, sf::Vector2f pos);
    static bool registerObject(const std::string& name, std::unique_ptr<BaseObject>(*f)(sf::Vector2f));
    static bool registerEnemy(const std::string& name, std::unique_ptr<BaseEnemy>(*f)(sf::Vector2f));
    static bool registerFriend(const std::string& name, std::unique_ptr<Friend>(*f)(sf::Vector2f));
    static void readFromFile(Level& level, Board& board);

private:
    static mymap& getMap()
    {
        static mymap m_map;
        return m_map;
    }
    static enemyVec& getEnemyVec()
    {
        static enemyVec m_enemyVec;
        return m_enemyVec;
    }
    static friendVec& getFriendVec()
    {
        static friendVec m_friendVec;
        return m_friendVec;
    }


    static ifstream m_file;
    static std::string m_objectName;
    static float m_x, m_y;
    static std::vector<std::tuple<char, float, float>> m_friendData;

};