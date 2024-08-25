#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Utilities.h"
enum Pictures
{
    newGameButton, helpButton, exitButton, background, mulan, friendOfMulan, mulanSpriteSheet,
    mulanAndMushuSprite, shanYoSpariteSheet, shifuHelperSpriteSheet, Blue, Yellow, Red, heart,
    Red_medicine, Blue_medicine, Yellow_medicine,
    Red_Plaster, Blue_Plaster, Yellow_Plaster,
    Red_Key, Blue_Key, Yellow_Key, bullet, gun, redFree, yellowFree, blueFree, cityGate, kingGate, gate, snow, gift,
    win,gameOver, king, saveMyFriends,help

};

enum Texts
{
    live,guns
};
enum SoundBuffer
{
    GameOver,
    Win
};
class Reasources
{
public:
    ~Reasources() = default;
    static Reasources& getInstance();
    sf::Texture& getTexture(enum Pictures index);
    sf::RenderWindow& getWindow();
    sf::RenderWindow& getTaskWindow();
    sf::RenderWindow& getHelpWindow();
    void createWindow();
    void createTaskWindow();
    void createHelpWindow();
    sf::Text& getText(enum Texts index);
    sf::Font& getFont();
     sf::SoundBuffer& getSoundBuffer(enum SoundBuffer index);
    sf::Music& getMusic();
private:
    Reasources();
    static Reasources m_instance;
    sf::RenderWindow m_window;
    sf::RenderWindow m_taskWindow;
    Reasources(const Reasources&) = default;//copy
    std::vector <sf::Texture> m_texture;
    std::vector <sf::Text> m_text;
    std::vector <sf::SoundBuffer> m_buffer;
    sf::RenderWindow m_helpWindow;
    sf::Font m_font;
    sf::Music m_music;
};