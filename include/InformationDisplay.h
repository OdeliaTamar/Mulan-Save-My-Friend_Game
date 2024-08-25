#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "Reasources.h"
#include "Observer.h"
class Mulan;
class Player;
class InformationDisplay :public Observer
{
public:
    InformationDisplay(std::unique_ptr<Player>& mulan);
    virtual ~InformationDisplay() = default;
    void display(sf::RenderTarget& target, const sf::View& view);
    virtual  void updateLive(int lives) override;
    virtual  void updateGuns(int guns) override;
protected:
    std::vector <sf::Text> m_text;
    sf::Sprite m_sprait;  //for the live (hearts)
    sf::Sprite m_gunSprait;
    int m_live;
    int m_numOfGun;
    /*int m_numOfKnife;*/

   // int m_level;
    //int& m_levelTime;
   // sf::Clock& m_levelClock;
};