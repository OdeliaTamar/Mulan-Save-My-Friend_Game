#include "Factory.h"
#include "Level.h"

ifstream Factory::m_file;
std::string Factory::m_objectName = "";
float m_x = 0, m_y = 0;
std::vector<std::tuple<char, float, float>> Factory::m_friendData = {};

//------------------------------------------------------------------------
Factory::Factory()
{
}
//------------------------------------------------------------------------
void Factory::readFromFile(Level& level, Board& board)
{
    std::string filePath = "text.txt";
    m_file.open(filePath);
    if (!m_file.is_open())
        exit(1);

    std::string line;
    while (std::getline(m_file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        m_objectName = line;
        // Process the object data based on its type
        if (m_objectName == "Enemy")
        {
            // Read the coordinates
            std::vector<sf::Vector2f> coordinates;
            std::string coordLine;
            while (std::getline(m_file, coordLine))
            {
                if (coordLine.empty() || coordLine[0] == '#')
                    break;

                std::istringstream iss(coordLine);
                float x, y;
                if (iss >> x >> y) {
                    board.addEnemyPosition(sf::Vector2f(x, y));
                }
            }
        }
        else if (m_objectName == "Snow")
        {
            float x, y;
            std::string dataLine;
            // Read the Snow object data
            while (std::getline(m_file, dataLine))
            {
                if (dataLine.empty() || dataLine[0] == '#')
                    break;

                std::istringstream iss(dataLine);
                if (iss >> x >> y /*>> width >> height*/)
                {
                    level.getBoard().addSnowPosition(sf::Vector2f(x, y));//coordinates.emplace_back(x, y);
                }
            }
        }
        else if (m_objectName == "Friend")
        {
            // Read the Fried object data
            std::string friendLine;
            while (std::getline(m_file, friendLine)) {
                if (friendLine.empty() || friendLine[0] == '#')
                    break;

                std::istringstream iss(friendLine);
                char color;
                float x, y;
                if (iss >> color >> x >> y)
                {
                    board.addFriendPosition(sf::Vector2f(x, y));
                }
            }
        }
        else if (m_objectName == "Medication")
        {
            // Read the Fried object data
            std::string MedicationLine;
            while (std::getline(m_file, MedicationLine)) {
                if (MedicationLine.empty() || MedicationLine[0] == '#')
                    break;

                std::istringstream iss(MedicationLine);
                char color;
                float x, y;
                if (iss >> color >> x >> y)
                {
                    board.addStaticObjectPosition(sf::Vector2f(x, y));
                }
            }
        }
        else if (m_objectName == "Plaster")
        {
            // Read the Fried object data
            std::string MedicationLine;
            while (std::getline(m_file, MedicationLine)) {
                if (MedicationLine.empty() || MedicationLine[0] == '#')
                    break;

                std::istringstream iss(MedicationLine);
                char color;
                float x, y;
                if (iss >> color >> x >> y)
                {
                    board.addStaticObjectPosition(sf::Vector2f(x, y));
                }
            }
        }
        else if (m_objectName == "Key")
        {
            // Read the Fried object data  
            std::string MedicationLine;
            while (std::getline(m_file, MedicationLine)) {
                if (MedicationLine.empty() || MedicationLine[0] == '#')
                    break;

                std::istringstream iss(MedicationLine);
                char color;
                float x, y;
                if (iss >> color >> x >> y)
                {
                    board.addStaticObjectPosition(sf::Vector2f(x, y));
                }
            }
        }
        else if (m_objectName == "CityGate")
        {
            // Read the Fried object data  
            std::string CityGateLine;
            while (std::getline(m_file, CityGateLine)) {
                if (CityGateLine.empty() || CityGateLine[0] == '#')
                    break;

                std::istringstream iss(CityGateLine);
                char color;
                float x, y;
                if (iss >> color >> x >> y)
                {
                    board.addStaticObjectPosition(sf::Vector2f(x, y));
                }
            }
        }
        else if (m_objectName == "JailGate")
        {
            // Read the Fried object data  
            std::string JailGateLine;
            while (std::getline(m_file, JailGateLine)) {
                if (JailGateLine.empty() || JailGateLine[0] == '#')
                    break;

                std::istringstream iss(JailGateLine);
                char color;
                float x, y;
                if (iss >> color >> x >> y)
                {
                    board.addStaticObjectPosition(sf::Vector2f(x, y));
                }
            }
        }
        else if (m_objectName == "KingGate")
        {
            // Read the Fried object data  
            std::string KingGateLine;
            while (std::getline(m_file, KingGateLine)) {
                if (KingGateLine.empty() || KingGateLine[0] == '#')
                    break;

                std::istringstream iss(KingGateLine);
                char color;
                float x, y;
                if (iss >> color >> x >> y)
                {
                    board.addStaticObjectPosition(sf::Vector2f(x, y));
                }
            }
        }
    }
    m_file.close();
}
//--------------------------------------------------------------------------------------------
std::unique_ptr<BaseObject> Factory::createObject(const std::string& name, sf::Vector2f pos)
{
    auto it = getMap().find(name);
    if (it == getMap().end())
        return nullptr;
    return (it->second)(pos);
}
//--------------------------------------------------------------------------------------------
std::unique_ptr<BaseEnemy> Factory::createEnemy(const std::string& name, sf::Vector2f pos)
{
    auto it = getEnemyVec().find(name);
    if (it == getEnemyVec().end())
        return nullptr;
    return (it->second)(pos);
}
//-------------------------------------------------------------------------------------
std::unique_ptr<Friend> Factory::createFriend(const std::string& name, sf::Vector2f pos)
{
    auto it = getFriendVec().find(name);
    if (it == getFriendVec().end())
        return nullptr;
    return (it->second)(pos);
}
//-------------------------------------------------------------------------------------
bool Factory::registerObject(const std::string& name, std::unique_ptr<BaseObject>(*f)(sf::Vector2f)) {
    getMap().emplace(name, f);
    return true;
}
//-----------------------------------------------------------------------------------
bool Factory::registerEnemy(const std::string& name, std::unique_ptr<BaseEnemy>(*f)(sf::Vector2f)) {
    getEnemyVec().emplace(name, f);
    return true;
}
//-----------------------------------------------------------------------------------
bool Factory::registerFriend(const std::string& name, std::unique_ptr<Friend>(*f)(sf::Vector2f)) {
    getFriendVec().emplace(name, f);
    return true;
}
//----------------------------------------------------------------
