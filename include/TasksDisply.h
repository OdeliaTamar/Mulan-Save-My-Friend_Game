#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include"Reasources.h"

const int NUMROWS = 10; // Define the value of NUMROWS
const int NUMCOLS = 10; // Define the value of NUMCOLS

class TasksDisply
{
public:
    TasksDisply();
    ~TasksDisply() = default;
    void display() {}
    void updateDisplay() {}
    void showMission();
    void updateMission(const int& row, const int& col);

    void resetMissionDisplay();
protected:
    sf::Sprite m_friend;
    sf::Sprite m_task;
    sf::Sprite m_king;
    sf::Sprite m_saveMyFriend;
    std::vector<std::vector<sf::Sprite>> spriteMatrix{ NUMROWS, std::vector<sf::Sprite>(NUMCOLS) };
};
