
#ifndef SNEK_WAZSFML_H
#define SNEK_WAZSFML_H


#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <algorithm>
#include <vector>
#include "plansza.h"
#include "waz.h"
using namespace std;

class Button
{
public:
    sf::RectangleShape body;
    sf::Text text;
    sf::Font font;

    Button(int x, int y, string txt);
    Button(int x, int y, string txt, float sizeX, float sizeY);
    void draw(sf::RenderWindow &window);
};

class Screen
{
public:
    bool active = false;
    sf::Text title;
    sf::Font font;

    Screen();
};

class MainScreen : public Screen
{
public:
    Button button1;
    Button button2;
    Button latwy;
    Button sredni;
    Button trudny;

    MainScreen();
    void drawScreen(sf::RenderWindow &window);
};

bool comp(int a, int b);

class GameScreen : public Screen
{
public:
    Waz waz;
    sf::Text punktyText;
    Jedzenie J;
    vector<Sciana> sciany;
    int punkty = 0;
    int poziom = 1;

    GameScreen();
    void drawScreen(sf::RenderWindow &window);
    void respawn();
};

class EndScreen : public Screen
{
public:
    sf::Text punktyText;
    vector<sf::Text> leaderboard;
    vector<int> val;

    EndScreen();
    void loadLeaderboard(int pkt);
    void saveLeaderboard();
    void drawScreen(sf::RenderWindow &window);
};



#endif //SNEK_WAZSFML_H
