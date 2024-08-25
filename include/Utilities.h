#pragma once
#include <SFML/Graphics.hpp>

enum Colors 
{
	red = 0,
	blue,
	yellow,
	kingColor,
};
enum TaskMissionDisply
{
	keyMission = 0,
	MedicationMission,
	PlasterMission,
	frinedMission
};

const float WINDOW_HEIGHT_SIZE = 1900.f;
const float WINDOW_WIDTH_SIZE = 950.f;
const float BACKGROUND_PIC_HEIGHT_SIZE = 8787.f;
const float BACKGROUND_PIC_WIDTH_SIZE = 4873.f;
const int NUM_OF_LEVELS = 1;
const int NUM_OF_PICTURES = 38;
const float BUTTON_Y_POSITION = 200.f;
const float MULAN_SPEED = 25.0f;
const float SMART_ENEMY_SPEED = 890.0f;
const int NUM_OF_TEXTS = 2;
const int HEART_Y_POSITION = 0;
const int NUM_OF_OBSERVERS = 1;
const int TOTAL_LIVE = 3;
const int TOTAL_GUNS = 4;
const int NUM_OF_MISSIONS= 4;
const int NUM_OF_ENEMYS = 14;
const int NUM_OF_SMART_ENEMYS = 6;
const int NUM_OF_FRIENDS = 3;
const int NUM_OF_OBJECTS = 20;
const int NUM_OF_GUNS = 20;
const int MAX_GUNS = 36;
const int MAX_GIFT = 46;
const int NUM_OF_GIFTS = 10;
const int NUM_OF_PLASTER = 6;
const int NUM_OF_MEDICATION = 3;
const int NUM_OF_KEYS = 9;
const int NUM_OF_CITY_GATE = 12;
const int NUM_OF_JAIL_GATE = 15;
const int NUM_OF_KING_GATE = 16;
const int NUM_OF_COLORS = 3;
const int DELAY_TIME = 5;
const int GAME_OVER_POSITION = 220;
const int WIN_POSITION = 250;
const int NUM_OF_SOUNDS = 2;
const int WINDOW_SIZE = 1000;

const int SPEED = 250;

const sf::Vector2f RED_MEDICATION = sf::Vector2f(2500.f, 1200.f);
const sf::Vector2f BLUE_MEDICATION = sf::Vector2f(1735.f, 3434.f);
const sf::Vector2f YELLOW_MEDICATION = sf::Vector2f(6753.f, 319.f);
const sf::Vector2f RED_PLASTER = sf::Vector2f(3755.f, 1231.f);
const sf::Vector2f BLUE_PLASTER = sf::Vector2f(351.f, 3600.f);
const sf::Vector2f YELLOW_PLASTER = sf::Vector2f(7894.f, 1124.f);
const sf::Vector2f RED_KEY = sf::Vector2f(1359.f, 344.f);
const sf::Vector2f BLUE_KEY = sf::Vector2f(4267.f, 3000.f);
const sf::Vector2f YELLOW_KEY = sf::Vector2f(2006.f, 2482.f);
const sf::Vector2f RED_CITY_GATE = sf::Vector2f(2380.f, 2300.f);
const sf::Vector2f BLUE_CITY_GATE = sf::Vector2f(2060.f, 4490.f);
const sf::Vector2f YELLOW_CITY_GATE = sf::Vector2f(6200.f, 1300.f);
const sf::Vector2f RED_JAIL_GATE = sf::Vector2f(3590.f, 1990.f);
const sf::Vector2f BLUE_JAIL_GATE = sf::Vector2f(1010.f, 3850.f);
const sf::Vector2f YELLOW_JAIL_GATE = sf::Vector2f(7475.f, 1050.f);

const sf::Vector2f RED_FRIEND = sf::Vector2f(3590.f, 2040.f);
const sf::Vector2f BLUE_FRIEND = sf::Vector2f(1010.f, 3896.f);
const sf::Vector2f YELLOW_FRIEND = sf::Vector2f(7490.f, 1100.f);
const sf::Vector2f KING_POS = sf::Vector2f(8090.f, 4300.f);
const sf::Vector2f MULAN_SIZE = sf::Vector2f(250.0f, 300.0f);
const sf::Vector2f SMART_ENEMY_SIZE = sf::Vector2f(200.0f, 250.0f);
