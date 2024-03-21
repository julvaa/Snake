
#ifndef SNEK_PLANSZA_H
#define SNEK_PLANSZA_H



#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
class Jedzenie
{
public:
    sf::CircleShape body;

    Jedzenie();
    void respawn();
};

class Sciana : public sf::RectangleShape
{
public:
    Sciana();
};



#endif //SNEK_PLANSZA_H
